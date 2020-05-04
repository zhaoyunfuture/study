#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "my.pb.h"
#include "data.h"

using namespace std;


int my_read(int fd,char *buffer,int length){
    int bytes_left;
    int bytes_read;
    char *ptr; 
    ptr = buffer;
    bytes_left=length;
    while(bytes_left>0){ 
        bytes_read = read(fd, ptr,bytes_read);
        cout << "read bytes: " << bytes_read << endl;
        if(bytes_read<0) { 
            if(errno==EINTR)   
                bytes_read=0;   
            else    
                return(-1);  
        }else if(bytes_read==0) 
            break;   
        bytes_left-=bytes_read;  
        ptr+=bytes_read; 
    }
    return(length-bytes_left);
}

void addressinfo(const tutorial::AddressBook& address_book)
{
    cout <<"people size: " <<  address_book.people_size() << endl;
    for (int i = 0; i < address_book.people_size(); i++) {
        const tutorial::Person& person = address_book.people(i);
        cout << "people ID: " << person.id() << endl;
        cout << " Name: " << person.name() << endl;
        if (person.email() != "") {
            cout << " E-mail address: " << person.email() << endl;
        }
    }
}

int main()
{
	int server_sockfd = -1;
	int client_sockfd = -1;
	socklen_t client_len = 0;
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	//创建流套接字
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	//设置服务器接收的连接地址和监听的端口
	server_addr.sin_family = AF_INET;//指定网络套接字
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);//接受所有IP地址的连接
	server_addr.sin_port = htons(9736);//绑定到9736端口
	//绑定（命名）套接字
	bind(server_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
	//创建套接字队列，监听套接字
	listen(server_sockfd, 5);
	//忽略子进程停止或退出信号
	signal(SIGCHLD, SIG_IGN);
	
	while(1)
	{
		//char ch = '\0';
		client_len = sizeof(client_addr);
		printf("Server waiting\n");
		client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_addr, &client_len);

		if(fork() == 0)
		{
			//read(client_sockfd, &ch , 1);
            char buf[sizeof(data)];
            int readlen=0;
            //readlen = my_read(client_sockfd,buf,IPC_MAX_LEN);
            readlen = read(client_sockfd,buf,sizeof(data));
            cout << "readlen: " << readlen << endl;
#if 0
            data* d;
            d = (data*) buf;
             
            cout << "d.a: " << d->a << endl;
            cout << "d.b: " << d->b << endl;
            cout << "d.len: " << d->len << endl;
			cout << "d.c: " << d->c << endl;
#endif
            data* d = (data*) buf;
            cout << "d->len: " <<d->len << endl;

            tutorial::AddressBook address_book;
            if (!address_book.ParseFromArray(d->c,d->len)) {
                cerr << "Failed to parse address book." << endl;
                return -1;
            }
            addressinfo(address_book); 
            
            close(client_sockfd);
			exit(0);
		}
		else
		{
			//父进程中，关闭套接字
			close(client_sockfd);
		}
	}
    return 0;
}
