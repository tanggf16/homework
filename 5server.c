#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *IP;
    int server_sockfd, client_sockfd;
    int server_len, client_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);


    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = 9734;
    server_len = sizeof(server_address);
    bind(server_sockfd, (struct sockaddr *)&server_address, server_len);


    listen(server_sockfd, 5);
    while(1) {
 	char ch[50];

        printf("server waiting\n");


        client_len = sizeof(client_address);
        client_sockfd = accept(server_sockfd, 
            (struct sockaddr *)&client_address, &client_len);


        read(client_sockfd, &ch, sizeof(ch));
	printf("接收到的客户端信息：%s\n",ch);
        write(client_sockfd, &ch, sizeof(ch));
        IP=inet_ntoa(client_address.sin_addr);
        write(client_sockfd,IP,strlen(IP));
        close(client_sockfd);
    }
}
