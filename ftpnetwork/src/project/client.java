package project;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class client {

	public static void main(String[] args) {
			InetAddress ip;
			try 
			{
				ip = InetAddress.getByName("localhost");
				Socket client = new Socket(ip,2000);	 
				DataInputStream in = new DataInputStream(client.getInputStream());
				DataOutputStream out = new DataOutputStream(client.getOutputStream());	
				
				Scanner scanner = new Scanner(System.in);	
				String read ;
			
				while(true)
				{
					String replay = in.readUTF();//connect
					System.out.println(replay);
					
					replay = in.readUTF();//please send your username
					System.out.println(replay);
					
					read = scanner.nextLine();//username//
					out.writeUTF(read);
					
					replay = in.readUTF();//please send your username - wrong user name
					System.out.println(replay);
					
					//checking the username
					if(replay.equalsIgnoreCase("wrong user name")) 
					{
						System.out.println("connection is closed");
						break; 
					}
					
					read = scanner.nextLine();//password//
					out.writeUTF(read);
					
					replay = in.readUTF();//login successfully - wrong password
					System.out.println(replay);
					
					if(replay.equalsIgnoreCase("wrong password")) 
					{
						System.out.println("connection is closed");
						break; 
					}
					
					while(true)
					{
						replay = in.readUTF();//please enter the command (show my directories \to see your directories\ )
						System.out.println(replay);
						
						read = scanner.nextLine();//show my directories//
						out.writeUTF(read);
						
						replay = in.readUTF();//"Please enter correct command (show my directories \\to see your directories\\ ) "  -- "The available dirs ( "+Dirs[i*3]+" , "+Dirs[(i*3)+2]+" , "+Dirs[(i*3)+4]+" )"
						System.out.println(replay);
						
						while(replay.equalsIgnoreCase("Please enter correct command (show my directories or close ) ")) 
						{
							read = scanner.nextLine();
							out.writeUTF(read);
							
							replay = in.readUTF();
							System.out.println(replay);
						}
						if(replay.equalsIgnoreCase("connection is trermenated"))
							break;

						replay = in.readUTF();//Enter the command
						System.out.println(replay);
						
						read = scanner.nextLine();//show first_director//
						out.writeUTF(read);
						
						replay = in.readUTF();//"the available files ( "+list[0]+" , "+list[1]+" , "+list[2]+" )" -- "Please enter correct command like ('show moves')"
						System.out.println(replay);
						
						while(replay.equalsIgnoreCase("Please enter correct command like ('show moves')"))
						{
							read = scanner.nextLine();
							out.writeUTF(read);
							
							replay = in.readUTF();
							System.out.println(replay);
						}
						
						replay = in.readUTF();//Enter the name of file
						System.out.println(replay);
						
						read = scanner.nextLine();//filename//
						out.writeUTF(read);
						
						replay = in.readUTF();//"you will recive '"+reader+"'" -- "Please enter correct name of file like ('joker.txt')"
						System.out.println(replay);
						
						
						//if the entered file name is wrong or not found
						while(replay.equalsIgnoreCase("Please enter correct name of file like ('joker.txt')"))
						{
							read = scanner.nextLine();
							out.writeUTF(read);
							
							replay = in.readUTF();
							System.out.println(replay);
						}
						
						System.out.println("Enter the name of file you want to save in it: ");
						String reader = scanner.nextLine();//new name for the file to be received
						
						System.out.println("Enter the path of the file: ");//the path where the file 
						String path = scanner.nextLine();
						
						boolean c=false;
						while(true)
						{
							File f = new File(path);
							c=f.exists();
							if(c==true)
								break;
							System.out.println("Please enter correct path  ");
							path = scanner.nextLine();
						}
						
						//create a new socket to recieve the file into 
						Socket file = new Socket(ip,1000);
						DataInputStream IN = new DataInputStream(file.getInputStream());//from server
						DataOutputStream OUT = new DataOutputStream(file.getOutputStream());// to server	
						
						replay = IN.readUTF();//
						BufferedOutputStream send = new BufferedOutputStream(new FileOutputStream(new File(path+"\\"+reader+"."+replay)));//to file
						
						byte[] b = new byte[50002] ;
						int v=IN.readInt();//the number of packets the client will recieve
						int x=0;
						for(int i=0;i<v+1;i++) {
							x=IN.read(b);//reads the packet from the server
							OUT.writeUTF("sending data successfully");
			    			send.write(b, 0, x );//write the packet to the file
						}
						send.close();
						//
		    			replay = IN.readUTF();
						System.out.println(replay);  
						
						read = scanner.nextLine();
						OUT.writeUTF(read);
						
						replay = IN.readUTF();
						System.out.println(replay);
						
						while(replay.equalsIgnoreCase("Please enter the command 'close'"))
						{
							read = scanner.nextLine();
							OUT.writeUTF(read);
							
							replay = IN.readUTF();
							System.out.println(replay);
						}
						
						file.close();
						
					}
				}
				
			} catch (UnknownHostException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	       
	}
}
