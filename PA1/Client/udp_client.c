/*Name :- Raj lavingia
Credits :- Professor Sangtae
Date :- 09.23.2018
Objective :- UDp_Client
*/

//Include Libraries
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <signal.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <memory.h>

//Define Bufsize
#define BUFSIZE 1024

//Define Flags for acknowledgement
#define ACK_SUCCESS 1
#define ACK_FAIL		0

//Error checking function
void error(char *msg)
	{
	  perror(msg);
  	  exit(1);
	}

typedef struct payload
{
	unsigned int seq_id;
	unsigned char data[BUFSIZE];
	unsigned int bytes;
} payload_t;


typedef struct ack
{
	unsigned int seq_id;
	unsigned char ack_status;
} ack_t;

typedef struct payload1
{
	unsigned int seq_id1;
	unsigned char data1[BUFSIZE];
	unsigned int bytes1;
} payload_t1;


typedef struct ack1
{
	unsigned int seq_id1;
	unsigned char ack_status1;
} ack_t1;

//Sequence id defined globally
unsigned int global_client_seq_id = 1;

//Main function starts
int main(int argc, char **argv)
{

    char d_ls[BUFSIZE];
    int counter3 = 0;
    int sockfd, portno, n;
    int serverlen;
    int counter2 = 0;
    int counter4 =1;
    int clientlen;
    socklen_t client_raj;
    long unsigned int f7_value=0;
    long unsigned int f77_value=0;
    struct sockaddr_in clientaddr;
    struct sockaddr_in serveraddr;
    struct sockaddr_in addr;
    struct hostent *server;
    char d[BUFSIZE];
    char *hostname;
    char buf[BUFSIZE];
    char rajbuffer_sending[BUFSIZE]; //Buffer created for sending
    char rajbuffer_receiving[BUFSIZE]; //Buffer created for receiving
    char file_name[BUFSIZE];
    char command2[15];
    char command3[15];
    char command10[15];
    char command11[BUFSIZE];
    char buffer_get_command[BUFSIZE];
    char recieve_buf[BUFSIZE];
    FILE *ft1,*ft2;

    /* check command line arguments */
    if (argc != 3)
    {
       fprintf(stderr,"port number is not matched according to the requirement \n");
       exit(1);
    }
    else
    {
     printf(" Arguments given are in correct number \n " );
    }

    hostname = argv[1];
    portno = atoi(argv[2]);

    /* socket: create the socket */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
      {
        error("ERROR opening socket");
      }
    else
      {
	printf(" Socket created successfully \n ");
      }

    /* gethostbyname: get the server's DNS entry */
    server = gethostbyname(hostname);
    if (server == NULL)
    {
        fprintf(stderr,"ERROR, no such host as %s\n", hostname);
        exit(1);
    }

    /* build the server's Internet address */
    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,  (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(portno);

    if(connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0)
	{
         error("Connection is not established \n ");
	}
    else
	{
	 printf("Connection is created successfully \n ");
	}
	int timing_raj = 4;
	struct timeval timeval_structure = {timing_raj,0};
  	setsockopt(sockfd,SOL_SOCKET,SO_RCVTIMEO, (char *)&timeval_structure,sizeof(timeval_structure));
	while(1)
	{
         payload_t packet;
        ack_t rx_packet;
	payload_t1 receive_packet1;
	ack_t1 ack_packet1;
	long int file_size;
	int m;
	long int num_bytes = 0;
	size_t result;

	//printf("There are 5 choices :- \n1)get%s \n2)put%s \n3)delete%s \n4)ls%s \n5)exit%s \n",FILE_NAME,FILE_NAME,FILE_NAME,FILE_NAME,FILE_NAME);
	  printf("There are 5 choices :- \n1)get \n2)put \n3)delete \n4)ls \n5)exit\n");
  	  bzero(command2,sizeof(command2));
	  gets(command2);

	//SENDTO NUMBER 1
	 n = sendto(sockfd, command2, strlen(command2), 0, (const struct sockaddr *)&serveraddr,sizeof(serveraddr));

	if((strcmp(command2, "put"))==0)
	{

	printf("going into put \n");
	printf("Enter the file name : \n");
	bzero(command11,sizeof(command11));
	gets(command11);
	printf("User entered file name : %s \n",command11);
	ft1 = fopen(command11, "r");
	fseek(ft1, 0, SEEK_END);
	file_size = ftell(ft1);
	fseek(ft1,0,SEEK_SET);
	num_bytes = file_size;
	//int f_value = (file_size/BUFSIZE)+1;
	//printf(" f_value is %d \n",f_value);
	//int v_value = sendto(sockfd,&f_value, sizeof(f_value), 0, (const struct sockaddr *)&serveraddr,sizeof(serveraddr));


	while(num_bytes > 0)
	{
	bzero(&packet, sizeof(packet));
	result = fread(packet.data, 1, (num_bytes > BUFSIZE)? BUFSIZE:num_bytes, ft1);
	packet.seq_id = global_client_seq_id++;
	printf("Seq id : %d\n", packet.seq_id);
	packet.bytes = result;
	printf("Nack counter: %d\n",counter2);
	/*if(counter2 == 2)
	{
		printf("rx_seq id is %d,packet_seq_id is %d\n",rx_packet.seq_id,packet.seq_id );
		exit(1);
	}*/

//  counter3++;
		while(1)
		{
			printf("packet seq id is %d\n",packet.seq_id);
			sendto(sockfd, &packet, sizeof(packet), 0, (const struct sockaddr *)&serveraddr,sizeof(serveraddr));

//				sendto(sockfd, &counter3, sizeof(counter3), 0, (const struct sockaddr *)&serveraddr,sizeof(serveraddr));
	//			printf("counter 3 value is: %d \n",counter3);
			//  serverlen = sizeof(serveraddr);
			bzero(&rx_packet, sizeof(rx_packet));
			recvfrom(sockfd, &rx_packet, sizeof(rx_packet), 0,(struct sockaddr *) &serveraddr, sizeof(serveraddr));
			printf("rx_seq id is %d,packet_seq_id is %d\n",rx_packet.seq_id,packet.seq_id );

			if((rx_packet.seq_id == packet.seq_id) || (rx_packet.ack_status == ACK_SUCCESS))
			{
				printf("success case\n");
				break;
			}

			else
				{
					printf("NACK is received from server end , loop again \n");
			 		counter2++;
			   	printf("Nack counter: %d\n",counter2);
					if(rx_packet.seq_id < packet.seq_id)
						rx_packet.seq_id++;
						if(counter2 == 100)
						{
							printf(" File could not be sent \n");
							exit(1);
						}
				}

		}
//		sendto(sockfd, &rx_packet, sizeof(rx_packet), 0, (const struct sockaddr *)&serveraddr,sizeof(serveraddr));
  	num_bytes = num_bytes - result;
	  printf("%u\tNumber of bytes is : %ld\n\n",packet.seq_id, result);
	//fwrite (packet.data, sizeof(unsigned char), result, stdout);
	}
		printf("File is sent successfully\n");
  //global_client_seq_id = 2;
		printf(" sequence id is now %d\n",packet.seq_id);
	}


	else if((strcmp(command2, "get"))==0)
	{

	printf(" Enter the file name : \n ");
  bzero(command11,sizeof(command11));
	gets(command11);
	printf(" User entered file name : %s \n",command11);
  sendto(sockfd,command11,strlen(command11), 0, (const struct sockaddr *)&serveraddr,  sizeof(serveraddr));
	//printf(" Value of e_value is : %d \n",e_value);
  //int v7_value = recvfrom(sockfd,&f7_value,sizeof(f7_value),0,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
	//printf("value of v7 is : %ld \n ",f7_value);
	ft1 = fopen("foo12","wb+");


	//printf(" outside the loop %d \n \n ",i1);
//	for(int i1=0;i1<f7_value;i1++)
	//{
	//while(i1 < 3)
	bzero(&receive_packet1, sizeof(receive_packet1));
	receive_packet1.bytes1 = BUFSIZE;
	while(receive_packet1.bytes1 == BUFSIZE)
	{
		recvfrom(sockfd,&receive_packet1, sizeof(receive_packet1), 0, (struct sockaddr *) &serveraddr, sizeof(serveraddr));
		printf("\n%u\tData = %u\tcounter4 is%d\n",receive_packet1.seq_id1, receive_packet1.bytes1,counter4);
	//int i1 = 0;
	//	printf(" In the loop : \n \n" );
	//bzero(recieve_buf,sizeof(recieve_buf));
	//printf(" Value of receive_buf is %s \n",recieve_buf);
  if(receive_packet1.seq_id1 == counter4 )
	{
		//printf("In the loop 2\n");
		//counter4++;
		bzero(&ack_packet1, sizeof(ack_packet1));
		ack_packet1.seq_id1 = receive_packet1.seq_id1;
		printf("ack_packet seq id is %d\n",ack_packet1.seq_id1);
		ack_packet1.ack_status1 = ACK_SUCCESS;
		printf("ack status is %d\n",ACK_SUCCESS);
	}
	//printf("\n\nEntered the while loop\n\n");
	else
	{
			printf("ACK_FAIL loop started\n");
				//bzero(&ack_packet, sizeof(ack_packet));
		//  ack_packet.seq_id = receive_packet.seq_id;
			ack_packet1.ack_status1 = ACK_FAIL;
			printf("ack status is %d\n",ACK_FAIL);

				//counter4--;
	}
	sendto(sockfd, &ack_packet1, sizeof(ack_packet1), 0, (const struct sockaddr *)&serveraddr,sizeof(serveraddr));
  fwrite(receive_packet1.data1,1, receive_packet1.bytes1 , ft1);
	printf("ack packet seq id is %d\n",ack_packet1.seq_id1);
	if(receive_packet1.seq_id1 == ack_packet1.seq_id1)
	 {
		 counter4++;
	 }
       // recieve_buf[b1_value] = '\0';
	//printf(" value of i is : %d ",i1);
	}
	fclose(ft1);
	printf("done\n");
	}

 //Delete command for deleting files on the server
	else if((strcmp(command2, "delete"))==0)
	{
		printf(" going into delete \n ");
		printf("Enter File name:");
		bzero(d, sizeof(d));
		//bzero(buf,512);
		gets(command3);
		printf("File name is : %s \n ",command3);
		int nbytes = sendto(sockfd, command3, strlen(command3), 0, (const struct sockaddr *)&serveraddr,  sizeof(serveraddr));

		printf("n bytes is %d ",nbytes);
	}

  //List command for listing files on the server
	else if((strcmp(command2, "ls"))==0)
	{
		printf(" going into list \n ");
		bzero(d_ls, sizeof(d_ls));
		//printf("value of d is : %d",d);
		int k=0;

		int f11_value = recvfrom(sockfd,&f77_value,sizeof(f77_value),0,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
		printf("value of f77_value is : %ld \n ",f77_value);

		for(int k=0;k<f77_value;k++)
	{

		int b_value = recvfrom(sockfd, (char *)d_ls, sizeof(d_ls), 0,(struct sockaddr *) &clientaddr, &clientlen);
		printf("%s \n",d_ls);
	}
	}

	//Exit command for socket closing
	else if((strcmp(command2, "exit"))==0)
	{
		printf(" going into exit \n ");
		close(sockfd);
		printf("socket closed : \n ");
		exit(1);
}
	else
	{
		printf("Choose from the above choices : \n");
	}

}
}
