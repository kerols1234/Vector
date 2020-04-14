package project;
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;



public class server {

	public static void main(String[] args) 
	{
		try
		{
			ServerSocket server1 = new ServerSocket(2000);
			ServerSocket server2 = new ServerSocket(1000);
			System.out.println("server wait for client");
			//////load usernames and passwords
			Scanner scan = new Scanner(new File("C:\\Users\\kerols\\Desktop\\project net\\username.txt"));
			String [] username = new String[8] ;//4 usernames + 4 passwords
			for (int i = 0 ; scan.hasNext() ; i++)
			{ 
				username[i]=scan.nextLine();
			}
			//////directories
			scan = new Scanner(new File("C:\\Users\\kerols\\Desktop\\project net\\dirs.txt"));
			String [] Dirs = new String[24] ;//3 directories for each user
			for (int j = 0 ; scan.hasNext() ; j++)
			{ 
				Dirs[j]=scan.nextLine();
			}
			scan.close();
			
			while(true) 
			{
				Socket c1 = server1.accept();
				ClientConnection clientcon = new ClientConnection(c1 ,server2 ,username,Dirs);
				clientcon.start();	
			}
		} 
		catch (Exception e) 
		{
			System.out.println("you have a problem I/O OF SERVER socket");
		}
	}//end of main
	
	static class ClientConnection  extends Thread
	{
		Socket c1,c2 ;//c1 for sending prompts to the user + c2 for sending the file
		ServerSocket s1;
		String[] username = new String[8];
		String[] Dirs = new String[24];
		
		//constructor
		public ClientConnection (Socket client1 ,ServerSocket s2 ,String[] user ,String[] dirs) 
		{
			
			c1 = client1;
			s1 = s2;
			for(int i=0;i<8;i++) 
			{
				this.username[i] = user[i] ;
			}
			for(int i=0;i<24;i++) 
			{
				this.Dirs[i] = dirs[i] ;
			}
		}
		@Override
		public void run()
		{
			try 
			{
				    DataInputStream in = new DataInputStream(c1.getInputStream());
				    DataOutputStream out = new DataOutputStream(c1.getOutputStream());
				   	String reader;//read from the user
				   	String  find ="";//path of the file
					int x = 1 , i ;
					out.writeUTF("connect");
					out.writeUTF("Please send your username");
					reader = in.readUTF();
					
					//validation of username
					for(i = 0 ; i<8 ; i=i+2)
					{
						if(reader.equalsIgnoreCase(username[i]))
						{
							x = 0;
							break;
						}
					}
					if(x == 1)
					{
						out.writeUTF("wrong user name");
						return;
					}
					x = 1;//reset x to test password
					out.writeUTF("Please send your password");
					reader = in.readUTF();
					
					//validation of password
					if(!(reader.equalsIgnoreCase(username[i+1])))
					{
						out.writeUTF("wrong password");
						return;
					}
					out.writeUTF("Login Successfully ");
					
					while(true)
					{
						out.writeUTF("please enter the command (show my directories or close ) ");
						reader = in.readUTF();				
						while(true) 
						{
							if(reader.equalsIgnoreCase("show my directories")||reader.equalsIgnoreCase("close"))
							{
								break;
							}
							out.writeUTF("Please enter correct command (show my directories or close ) ");
							reader = in.readUTF();//REMOVE THIS SENTENCE
						}
						if(reader.equalsIgnoreCase("close")) 
						{
							out.writeUTF("connection is trermenated");
							break;
						}
						out.writeUTF("The available dirs ( "+Dirs[i*3]+" , "+Dirs[(i*3)+2]+" , "+Dirs[(i*3)+4]+" )");
						out.writeUTF("Enter the command");
						reader = in.readUTF();
						while(true) 
						{
							for(int j=0 ; j<5 ; j=j+2) 
							{
								//check if the user entered a valid director
								if(reader.equalsIgnoreCase("show "+Dirs[(i*3)+j])) 
								{
									find = Dirs[(i*3)+j+1] ;
									x = 0 ;
									break ;
								}
							}
							if(x == 0) 
							{
								x = 1;
								break;
							}
							out.writeUTF("Please enter correct command like ('show moves')");
							reader = in.readUTF();
						}
						File file = new File(find);
						String[] list = file.list();
						out.writeUTF("the available files ( "+list[0]+" , "+list[1]+" , "+list[2]+" )");
						out.writeUTF("Enter the name of file");
						reader = in.readUTF();//entering the name of the file
						while(true) 
						{
							for(int j=0 ; j<3 ; j++) 
							{
								if(reader.equalsIgnoreCase(list[j])) 
								{
									x = 0 ;
									break ;
								}
							}
							if(x == 0) 
							{
								x = 1;
								break;
							}
							out.writeUTF("Please enter correct name of file like ('joker.txt')");
							reader = in.readUTF();
						}
						out.writeUTF("you will recive '"+reader+"'");
						
						//send file
						find = find + "\\" + reader;
						String extend = "" ;
						File file1 = new File(find); 
					    FileInputStream read1 = new FileInputStream(file1);
					    byte b[]= new byte[(int)file1.length()] ;
					    read1.read(b, 0, b.length);
					    read1.close();
					    //read the extension of the file
					    for(int j = find.length()-1 ; j>=0 ; j--) 
					    {
					    	if(find.charAt(j)=='.') 
					    	{
					    		break ;
					    	}
					    	extend= find.charAt(j)+ extend ;
					    }
					    
						c2 = s1.accept();
					    BufferedOutputStream OUT = new BufferedOutputStream(c2.getOutputStream());//send the bytes
					    DataOutputStream out1 = new DataOutputStream(c2.getOutputStream());//send prompts
					    DataInputStream IN = new DataInputStream(c2.getInputStream()); //Receive data
					   	out1.writeUTF(extend);
					   	//
					   	int z=50000;//size of the packet
					   	out1.writeInt(b.length/50000);
					    for(int j=0; j<b.length; j=j+50000)
					    {
					    	if(j+50000>=b.length) 
					    	{
					    	    z=b.length-j;//the size of the last packet
					    	}
					    	OUT.write(b, j, z);//b = file in bytes, j = index of the start, z = number of bytes to be sent
					    	OUT.flush();
					    	reader = IN.readUTF();
					    }
					   	out1.writeUTF("Enter the command 'close'");
						reader = IN.readUTF();//read from client
						while(!(reader.equalsIgnoreCase("close"))) 
						{
							out1.writeUTF("Please enter the command 'close'");
							reader = IN.readUTF();
						}
						out1.writeUTF("Connection is terminated in port 1000");
						c2.close();
					}
					   
			}
			catch (IOException e) {
				System.out.println("you have a problem I/O OF CLIENT socket");
			}

		}	
	}
	
}
