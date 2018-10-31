#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<time.h>
#include<unistd.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
using namespace std;
string getdatetime()
{
	  time_t rawtime;
	  struct tm * timeinfo;
	  char buffer[80];

	  time (&rawtime);
	  timeinfo = localtime(&rawtime);

	  strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
	  string str(buffer);
	  return str;

}
int getMessage(char data[100])
{		string time=getdatetime(); // Getting current date and time
		string str(data);
		transform(str.begin(), str.end(), str.begin(), ::tolower); //Converting the received message into lowercase
		bool found_time=false,found_date=false;
		if (str.find("date") != std::string::npos )					//Checking if the string contains "date" as a substring 
		{
    	found_date=true;
		}
		if (str.find("time") != std::string::npos) 					//Checking if the string contains "time" as a substring 
		{				

    	found_time=true;
		}
		int sz=0;
		if(found_time==true&&found_date==true)						//Storing appropriate message in data
		{
			for(int i=0;i<sizeof(time);++i)
			{
			data[i]=time[i];
			}
			sz=sizeof(time);

		}
		
		else if(found_date==true)
		{
			for(int i=0;i<10;++i)
			{
			data[i]=time[i];
			}
			sz=10;
		}
		
		else if(found_time==true){
			for(int i=10;i<sizeof(time);++i)
			{
			data[i-10]=time[i];
			}
			sz=sizeof(time)-10;
		}
		else{
			string ss="I don't understand";
			for(int i=0;i<20;++i)
			{
				data[i]=ss[i];
			}
			
			sz=20;

		}
		return sz;
}
int main()
{
	
	char data[1024];
	int cl=0,cc=0;
	struct sockaddr_in ServerIp;
	cl=socket(AF_INET, SOCK_STREAM,0);
	memset(&ServerIp,'0',sizeof(ServerIp));
	memset(data,'0',sizeof(data));
	ServerIp.sin_family=AF_INET;
	ServerIp.sin_addr.s_addr=htons(INADDR_ANY);
	ServerIp.sin_port=htons(4444);
	bind(cl,(struct sockaddr*)&ServerIp,sizeof(ServerIp));
	listen(cl,5);
	while(1)
	{
		cout<<"Server Ready"<<endl;
		cc=accept(cl,(struct sockaddr*)NULL,NULL);
		
		int num=read(cc,data,sizeof(data));			//Reading message sent by client
		cout<<"String sent by client is "<<data<<endl;
		int sz=getMessage(data);					//Analyzing the message and getting appropriate response
		write(cc,data,sz);							//Sending the response
		sleep(1);
	}

}
