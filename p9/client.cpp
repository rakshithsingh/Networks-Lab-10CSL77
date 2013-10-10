#include <iostream>
#include <arpa/inet.h>

using namespace std;

int main(int argc, char* argv[])
{
	if(argc!=2)
	{
		cout<<"Usage: "<<argv[0]<<" <ip-address>"<<endl;
		cout<<"No server IP specified as argument!\n";
		return 1;
	}
	
	char fname[50], buffer[1025];
	int sd;
	struct sockaddr_in address;

	address.sin_family = AF_INET;
	address.sin_port = htons(15000);
	inet_pton(AF_INET, argv[1], &address.sin_addr);

	sd = socket(AF_INET, SOCK_STREAM, 0);
	connect(sd, (struct sockaddr*)&address, sizeof(address));
	
	cout<<"Enter a filename: ";
	cin>>fname;
	
	cout<<"Sending request"<<endl;
	send(sd, fname, sizeof(fname), 0);
	
	cout<<"Recieved response:"<<endl;
	recv(sd, buffer, sizeof(buffer), 0);
	cout<<buffer;
	cout<<endl;
	
	return 0;
}
