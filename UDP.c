#include<stdio.h> //printf
#include<string.h> //memset
#include<stdlib.h> //exit(0);
#include<arpa/inet.h>
#include<sys/socket.h>
 
#define SERVER "127.0.0.1" //参照你提供的PDF中的IPv4地址
#define BUFLEN 512  //Max length of buffer
#define PORT 2000   //参照你提供的PDF中的端口数

struct frame
{
        unsigned Time;
        float Ang_X;
        //之后把所有相关的参数全部加进来，简而言之复制黏贴
};
 
//自定义的function，当目标创建失败的时候退出程序，比如socket，比如sendto等
void die(char *s)
{
    perror(s);
    exit(1);
}
 
int main(void)
{
    struct sockaddr_in si_other; //这个struct的dependency是#include <netinet/in.h> 相关信息网上可以查到
    struct frame *f; //创建frame的instance
    f->Ang_X = 0.0001; //设定参数，其实也可以在struct frame定义里就设定好
    //设定所有必要的参数
    
    int s, i, slen=sizeof(si_other);
    char buf[BUFLEN];
    char message[BUFLEN];
 
    if ( (s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) //这个socket（）function的dependency是#include<sys/socket.h> 相关信息网上可以查到
    {
        die("socket");
    }
 
    memset((char *) &si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(PORT);
     
    if (inet_aton(SERVER , &si_other.sin_addr) == 0) 
    {
        fprintf(stderr, "inet_aton() failed\n");
        exit(1);
    }
 
    while(1)
    {
        
         
        //send the message
        if (sendto(s, *f, strlen(*f) , 0 , (struct sockaddr *) &si_other, slen)==-1) //sendto()这个function的manual网上也能查到
        {
            die("sendto()");
        }
         
        //receive a reply and print it
        //clear the buffer by filling null, it might have previously received data
        memset(buf,'\0', BUFLEN);
        //try to receive some data, this is a blocking call
        if (recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen) == -1)
        {
            die("recvfrom()");
        }
         
        puts(buf);
    }
 
    close(s);
    return 0;
}