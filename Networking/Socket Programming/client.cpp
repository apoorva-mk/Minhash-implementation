#include<iostream>
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <unistd.h> 
using namespace std;
int main() 
{ 
    struct sockaddr_in address; 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 

    char data[100];
    
    cout<<"Enter a string :"<<endl;
   
    cin.getline(data,100);
    
    char buffer[1024] = { 0 }; 
    if ((sock = socket(AF_INET, 
                    SOCK_STREAM, 0)) 
        < 0) { 
        cout<<"Error in creating socket!"<<endl;
        return -1; 
    } 

    memset(&serv_addr, '0', sizeof(serv_addr)); 
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(4444); 
    if (inet_pton(AF_INET, "127.0.0.1",&serv_addr.sin_addr) 
        <= 0) { 
        printf("\nAddress not supported \n"); 
        return -1; 
    } 

    if (connect(sock, (struct sockaddr*)&serv_addr, 
                sizeof(serv_addr)) 
        < 0) { 
        cout<<"Connection failed"<<endl;
        return -1; 
    } 

    

    send(sock,data, sizeof(data), 0); 

   
    valread = read(sock, data, 100); 

    printf("%s\n",data); 

    return 0; 
} 
