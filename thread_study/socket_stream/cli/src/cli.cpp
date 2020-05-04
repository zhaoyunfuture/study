#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string.h>

#include "data.h"
#include "my.pb.h"
using namespace std;


int my_write(int fd,char *buffer,int length){
    int bytes_left;
    int written_bytes;
    char *ptr;
    ptr=buffer;
    bytes_left=length;

    cout <<"fd: " << fd << endl;
    cout << "len: " << length << endl;
    while(bytes_left>0){
        written_bytes = write(fd, ptr,bytes_left);  
        cout << "write byte: " << written_bytes << endl; 
        if(written_bytes<=0){
            if(errno==EINTR)  
                written_bytes=0;
            else     
                return(-1);  
        }  
        bytes_left-=written_bytes;  
        ptr+=written_bytes; 
    }return(0);
}


int main(int agrc, char *argv[])
{
	int sockfd = -1;
	int len = 0;
	struct sockaddr_in address;
	int result;
#if 0
    if(agrc > 1)
		ch = argv[1][0];
#endif
	//创建流套接字
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	//设置要连接的服务器的信息
	address.sin_family = AF_INET;//使用网络套接字
	address.sin_addr.s_addr = inet_addr("127.0.0.1");//服务器地址
	address.sin_port = htons(9736);//服务器所监听的端口
	len = sizeof(address);
	//连接到服务器
	result = connect(sockfd, (struct sockaddr*)&address, len);

	if(result == -1)
	{
		perror("ops:client\n");
		exit(1);
	}
#if 0
    char cc[]="test";
    char buf[IPC_MAX_LEN];
    memset(buf,0,IPC_MAX_LEN);
    data d;
    d.a = 1;
    d.b = 2;
    d.len = sizeof(cc);
    cout << "d.c len: " << sizeof(d.c) << endl;
    memset(d.c,0,sizeof(d.c));
    memcpy(d.c,cc,sizeof(cc));
    printf("d.c: %s\n", d.c);
    cout << "d.len: " << d.len << endl;
    cout << "d.size: " << sizeof(d) << endl;
    memcpy(buf,&d,sizeof(d));
#endif
    int id=10;
    string email("zyqq.com");
    string name("jacob");
    data d;
    cout << "sizeof d: " << sizeof(d) << endl;
    memset(&d,0,sizeof(d));

    tutorial::AddressBook address_book;
    cout << "sizeof ad: " << sizeof(tutorial::AddressBook) << endl;
    cout << "ByteSizeLong: " << address_book.ByteSizeLong() << endl;
    tutorial::Person* person = address_book.add_people();
    person->set_id(id);
    *person->mutable_name() = name; 
    person->set_email(email);
    cout << "sizeof ad: " << sizeof(tutorial::AddressBook) << endl;
    cout << "ByteSizeLong: " << address_book.ByteSizeLong() << endl;
    int reallen = address_book.ByteSizeLong();
    
    d.len = reallen;

    if (!address_book.SerializeToArray(d.c,reallen)) {
        cerr << "Failed to write address book." << endl;
        return -1;
    }

    tutorial::AddressBook address_book1;
    if (!address_book1.ParseFromArray(d.c,reallen)) {
        cerr << "Failed to parse address book." << endl;
        return -1;
    }
    cout <<"people size: " <<  address_book1.people_size() << endl;

    my_write(sockfd,(char*)(&d),sizeof(d));
	close(sockfd);

	exit(0);
}
