Socket Programming

This folder consists of two c++ programs
1.Server.cpp
2.Client.cpp
 
 Description:
 
 The client side program takes a string as input and sends it
 to the server.
 The server program reads the string and sends a message to
 the client .
 
 If the string sent by the client contains :
 a)Only time as a substring the server sends the current time only.
 
 b)Only date as a substring the server sends the current date only.
 
 c)Both date and time then the server sends both current date and time.
 
 d)If the string does not contain both of these words then the server 
  send the string "I don't understand"


Steps to run the codes:

 1)Open a terminal and run the following command:
 
 	g++ server.cpp
  
 2)Open another terminal and run
 
 	g++ client.cpp
  


