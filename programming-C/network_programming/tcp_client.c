#include <stdlib.h> 
#include <stdio.h> 
#include <errno.h> 
#include <string.h> 
#include <netdb.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 

#define portnumber 3333
#define gy 1234
int main(int argc, char *argv[]) 
{ 
	struct in_addr gy;	
	int sockfd; 
	char buffer[1024]; 
	struct sockaddr_in server_addr; 
	struct hostent *host; 

	//if(argc!=2) 
	//{ 
	//	fprintf(stderr,"Usage:%s hostname \a\n",argv[0]); 
	//	exit(1); 
	//} 

    /* 使用hostname查询host 名字 */
	//if((host=gethostbyname(argv[1]))==NULL) 
	//{ 
	//	fprintf(stderr,"Gethostname error\n"); 
	//	exit(1); 
	//} 

	/* 客户程序开始建立 sockfd描述符 */ 
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1) // AF_INET:Internet;SOCK_STREAM:TCP
	{ 
		fprintf(stderr,"Socket Error:%s\a\n",strerror(errno)); 
		exit(1); 
	} 

	/* 客户程序填充服务端的资料 */ 
	bzero(&server_addr,sizeof(server_addr)); // 初始化,置0
	server_addr.sin_family=AF_INET;          // IPV4
	server_addr.sin_port=htons(portnumber);  // (将本机器上的short数据转化为网络上的short数据)端口号
	inet_aton("192.168.3.104",&gy);
	server_addr.sin_addr=*(&gy); // IP地址
	
	/* 客户程序发起连接请求 */ 
	if(connect(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr))==-1) 
	{ 
		fprintf(stderr,"Connect Error:%s\a\n",strerror(errno)); 
		exit(1); 
	} 

	/* 连接成功了 */ 
	printf("Please input char:\n");
	
	/* 发送数据 */
	fgets(buffer,1024,stdin); 
	write(sockfd,buffer,strlen(buffer)); 
	/* 结束通讯 */ 
	close(sockfd); 
	exit(0); 
} 
