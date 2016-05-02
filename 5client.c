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
    int sockfd;
    int len,endlen;
    struct sockaddr_in address;
    int result;
    char ch[50];
    char IP[50];
    char rec[50];
    scanf("%s",&ch);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);


    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = 9734;
    len = sizeof(address);


    result = connect(sockfd, (struct sockaddr *)&address, len);

    if(result == -1) {
        perror("oops: client2");
        exit(1);
    }


    write(sockfd, &ch, sizeof(ch));
    read(sockfd, &rec, sizeof(rec));
    endlen=read(sockfd,&IP,sizeof(IP));
    IP[endlen]='\0';
    printf("客户端IP地址:%s\n",IP);
    printf("从服务器接收到的字符串：%s\n",rec);
    close(sockfd);
    exit(0);
}
