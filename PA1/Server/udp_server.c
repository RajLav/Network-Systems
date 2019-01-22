/*Name :- Raj lavingia
Credits :- Professor Sangtae
Date :- 09.23.2018
Objective :- Udp_Server
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
#include <ctype.h>
#include <dirent.h>

////Define Bufsize
#define BUFSIZE 1024

//Define Flags for acknowledgement
#define ACK_SUCCESS 1
#define ACK_FAIL		0

//Error checking function
unsigned char d[BUFSIZE];
void error(char *msg)
{
  perror(msg);
  exit(1);
}

//Structure payload for "put" command
typedef struct payload
{
	unsigned int seq_id;
	unsigned char data[BUFSIZE];
  unsigned int bytes;
} payload_t;

//Structure payload for "get" command
typedef struct payloadraj
{
	unsigned int seq_id1;
	unsigned char data1[BUFSIZE];
  unsigned int bytes1;
} payload_t1;

//Structure for acknowledgement of "put" command
typedef struct ack
{
	unsigned int seq_id;
	unsigned char ack_status;
} ack_t;

//Structure for acknowledgement of "get" command
typedef struct ack1
{
	unsigned int seq_id1;
	unsigned char ack_status1;
} ack_t1;

//Directory used for listing files
DIR *directory;

//Main Function
int main(int argc, char **argv)
{
  payload_t1 packet1;
  int sockfd;   // Name of the socket
  int portno;  //Port Number Defination
  int newsocket; //Another socket created
  int p;int i1=0;
  int clientlen; /* byte size of client's address */
  socklen_t client_raj;
  int counter = 0;
  int timing_raj = 20;
  struct sockaddr_in serveraddr; /* server's addr */
  struct sockaddr_in clientaddr; /* client addr */
  struct dirent *in;
  int counter4 = 1;
  struct hostent *hostp; /* client host info */
  int counter3;
  int counter2 = 0;
  unsigned int global_client_seq_id = 1;
  char buf[BUFSIZE]; /* message buf */
  char rajbuffer_sending[BUFSIZE]; //Buffer created for sending
  char rajbuffer_receiving[BUFSIZE]; //Buffer created for receiving
  char filename[BUFSIZE];
  char *hostaddrp; /* dotted decimal host addr string */
  char nameoffile[BUFSIZE];
  char send_buf[BUFSIZE];
  char command10[BUFSIZE];char command11[15];
  int f1_value=0;// char f6_value[BUFSIZE];
  int f10_value=0;
  int optval; /* flag value for setsockopt */
  int n,m,o; /* message byte size */
  long int num_bytes = 0;
  long int file_size;
  size_t result;
	ack_t1 rx_packet1;
  FILE *ft1; //File transfer
  // FILE *ft2;

  //Argument Check
  if (argc != 2) //There are 2 arguments , Ip address and port number
  {
    fprintf(stderr,"port number is not matched according to the requirement \n");
    exit(1); //To get out of the code
  }
  else
  {
   printf(" Arguments given are in correct number \n " );
  }

  //Port Number
  portno = atoi(argv[1]); //Converts the string to integer, argv will contain the file name

  //Initialisation from Server End
  printf("Welcome to socket programming\n");
  printf("Waiting for Client \n");

  //Creating a socket
  sockfd = socket(AF_INET, SOCK_DGRAM, 0); //Default for UDP is SOCK_DGRAM
  if (sockfd < 0)
  {
    error("ERROR opening socket");
  }

  else
  {
   printf("socket openend \n ");
  }


  optval = 1;
//  setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR,
	//     (const void *)&optval , sizeof(int));

  /*
   * build the server's Internet address
   */
  bzero((char *) &serveraddr, sizeof(serveraddr)); // clears whatever is in there before we make a fresh start
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = htonl(INADDR_ANY); //host to network long
  serveraddr.sin_port = htons((unsigned short)portno); //host to network short


  /*
   * bind: associate the parent socket with a port
   */
  if (bind(sockfd, (struct sockaddr *) &serveraddr,
	   sizeof(serveraddr)) < 0)
    {
       error("ERROR on binding");
    }
  else
    {
      printf("Binding done between server and client \n");
    }

    struct timeval timeval_structure = {timing_raj,0};
    setsockopt(sockfd,SOL_SOCKET,SO_RCVTIMEO, (char *)&timeval_structure,sizeof(timeval_structure));

  /*
   * main loop: wait for a datagram, then echo it
   */
  listen(sockfd , 5);
  clientlen = sizeof(clientaddr);

   while (1) {

     payload_t receive_packet;
     ack_t ack_packet;

    //RECEIVE FROM NUMBER 1
    bzero(buf, BUFSIZE); // Will delete all the data in the buffer and make it empty
    n = recvfrom(sockfd, (char *)buf, BUFSIZE, 0,
		 (struct sockaddr *) &clientaddr, &clientlen);

     //condition check for command received
     if (n < 0)
        {
          error("ERROR in recvfrom \n");
        }

    else
        {
          printf("Command is received \n ");
        }

   /*hostp = gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr,
				  sizeof(clientaddr.sin_addr.s_addr), AF_INET);
    if (hostp == NULL)
      error("ERROR on gethostbyaddr");
    hostaddrp = inet_ntoa(clientaddr.sin_addr);
    if (hostaddrp == NULL)
      error("ERROR on inet_ntoa\n");
    printf("server received datagram from %s (%s)\n",
	   hostp->h_name, hostaddrp);
    printf("server received %d/%d bytes: %s\n", strlen(buf), n, buf);*/


   buf[n] = '\0';
   //printf("Buffer client: %s\n ",buf);
   size_t result1;

	if((strcmp(buf, "put"))==0)
	{

	//int n2 = recvfrom(sockfd,&f1_value,sizeof(f1_value),0,(struct sockaddr *)&clientaddr,&clientlen);

	//printf(" value of f1 is %d \n ",f1_value);
  printf("going into put \n");
	ft1 = fopen("foo12","wb+");
  bzero(&receive_packet, sizeof(receive_packet));
  receive_packet.bytes = BUFSIZE;
	//int i = 0;
  while(receive_packet.bytes == BUFSIZE)
	{

    //	bzero(buf,BUFSIZE);
      recvfrom(sockfd,&receive_packet, sizeof(receive_packet), 0, (struct sockaddr *) &clientaddr,sizeof(clientaddr));
      printf("%u\tData = %u\tcounter4 is%d\n",receive_packet.seq_id, receive_packet.bytes,counter4);
      //recvfrom(sockfd,&counter3, sizeof(counter3), 0, (struct sockaddr *) &clientaddr,sizeof(clientaddr));
      //printf(" value of counter3 is %d:\n",counter3);

      //int final_result = 29053889%1024;
    //  printf("%d\n",final_result);
      //printf("",counter4);
      if(receive_packet.seq_id == counter4 )//|| receive_packet.bytes == (final_result))
      {
        //counter4++;
        bzero(&ack_packet, sizeof(ack_packet));
        ack_packet.seq_id = receive_packet.seq_id;
        printf("ack_packet seq id is %d\n",ack_packet.seq_id);
        ack_packet.ack_status = ACK_SUCCESS;
        printf("ack status is %d\n",ACK_SUCCESS);
      }

      else
      {
          printf("ACK_FAIL loop started\n");
            //bzero(&ack_packet, sizeof(ack_packet));
      //    ack_packet.seq_id = receive_packet.seq_id;
          ack_packet.ack_status = ACK_FAIL;
          printf("ack status is %d\n",ACK_FAIL);
          //counter4--;
      }
      sendto(sockfd, &ack_packet, sizeof(ack_packet), 0, (const struct sockaddr *)&clientaddr,sizeof(clientaddr));
      fwrite(receive_packet.data,1, receive_packet.bytes , ft1);
      printf("ack packet seq id is %d\n",ack_packet.seq_id);
      if(receive_packet.seq_id == ack_packet.seq_id)
      {
        counter4++;
      }
  }

	fclose(ft1);
  //counter4 =1;
	printf("done\n");
//	bzero(buf,sizeof(buf));
  }


	else if((strcmp(buf,"get"))==0)
	{
  bzero(command10,sizeof(command10));

	int n1 = recvfrom(sockfd,(char *)command10,sizeof(command10),0,(struct sockaddr *)&clientaddr,&clientlen);
	//printf("Value of n1 is %s \n ",command10);

	printf("getting file \n ");
	ft1 = fopen(command10, "r");
  fseek(ft1, 0, SEEK_END);
	file_size = ftell(ft1);
	fseek(ft1,0,SEEK_SET);
	num_bytes = file_size;
	//int f6_value = (file_size/BUFSIZE)+1;
	//printf(" f_value is %d \n ",f6_value);
	//int v6_value = sendto(sockfd,&f6_value,sizeof(f6_value),0,(const struct sockaddr *)&clientaddr,clientlen);
	//printf("v6 value is %d",v6_value);

	//printf("Number size = %ld.\n", num_bytes);
	while(num_bytes > 0)
	{
  bzero(&packet1, sizeof(packet1));
  result1 = fread(packet1.data1, 1, (num_bytes > BUFSIZE)? BUFSIZE:num_bytes, ft1);
	packet1.seq_id1 = global_client_seq_id++;
	printf("Seq id : %d\n",packet1.seq_id1);
	packet1.bytes1 = result1;
 	printf("Nack counter: %d\n",counter2);
  while(1)
  {
    printf("packet seq id is %d\n",packet1.seq_id1);
    sendto(sockfd, &packet1, sizeof(packet1), 0, (const struct sockaddr *)&clientaddr,sizeof(clientaddr));
    bzero(&rx_packet1, sizeof(rx_packet1));
    recvfrom(sockfd, &rx_packet1, sizeof(rx_packet1), 0,(struct sockaddr *) &serveraddr, sizeof(serveraddr));
    printf("rx_seq id is %d,packet_seq_id is %d\n",rx_packet1.seq_id1,packet1.seq_id1);

    //  bzero(send_buf,sizeof(send_buf));
	//result = fread(send_buf, 1, (num_bytes > BUFSIZE)? BUFSIZE:num_bytes, ft1);
	//printf("buf value is %s\n", buf);

  if((rx_packet1.seq_id1 == packet1.seq_id1) || (rx_packet1.ack_status1 == ACK_SUCCESS))
  {
    printf("success case\n");
    break;
  }
  else
  {
      printf("NACK is received from server end , loop again \n");
      counter2++;
    	printf("Nack counter: %d\n",counter2);
      if(rx_packet1.seq_id1 < packet1.seq_id1)
      rx_packet1.seq_id1++;
      if(counter2 == 100)
      {
        printf("File is not sent\n");
        	exit(1);
      }
      //printf("%d\n",counter2);
  }
}        //int nbytes = sendto(sockfd, send_buf,result, 0, (const struct sockaddr *)&clientaddr, clientlen);
//	 printf("Number of bytes sent: %d\n", nbytes);
	    num_bytes = num_bytes - result1;
  	  printf("%u\tNumber of bytes is : %ld\n\n",packet1.seq_id1, result1);
//	printf(" Number of bytes is : %ld ",num_bytes);

	}
      printf("File is sent successfully\n");
    //  global_client_seq_id = 2;
      printf(" sequence id is now %d\n",packet1.seq_id1);
	}

  ////Delete command for deleting files on the server
	else if((strcmp(buf, "delete"))==0)
	{
	   printf("deleting file \n ");
	   bzero(buf,BUFSIZE);
	   int b_value = recvfrom(sockfd, (char *)buf, BUFSIZE, 0,(struct sockaddr *) &clientaddr, &clientlen);
	   if(b_value == 0)
    	 {
    		printf("Error recieving file\n");
	     }
	    buf[b_value] = '\0';
	    strcpy(nameoffile,buf);
	    printf(" name of the file is %s:", nameoffile);

	//strcat(namefile,nameoffile);
	//printf(" name of the file is %s:", nameoffile);
	if((p = remove(nameoffile))==0)
	     {
         printf("delete success  \n ");
	     }
	else
	     {
	       printf("delete not success  \n" );
	     }
	}

  //List command for listing files on the server
  else if((strcmp(buf, "ls"))==0)
	{
	     bzero(buf,BUFSIZE);
	     printf("listing file \n ");
	       if((directory = opendir("./"))!=NULL)
	         {
	             while ((in = readdir(directory)) != NULL)
	              {
	                  counter++;
	                   printf(" value of count is %d \n\n",counter);

	               }
  int h1_value = sendto(sockfd,&counter,sizeof(counter),0,(const struct sockaddr *)&clientaddr,clientlen);
	printf(" value of h1 is %d\n \n",h1_value);
  counter =0;
	closedir(directory);
	}
	if((directory = opendir("./"))!=NULL)
	{
	while ((in = readdir(directory)) != NULL)
	 {
    	printf(" raj lavingia \n \n ");
    	printf("%s\n", in->d_name);
    	strcpy(buf,in->d_name);
    	printf("Value of buf is %s \n",buf);
    	int h = sendto(sockfd, (char *)buf, BUFSIZE, 0,(struct sockaddr *) &clientaddr, clientlen);
    	printf("value of h is %d : \n",h);
   }
  closedir(directory);
	}
	}

  //Exit command for socket closing
	else if((strcmp(buf, "exit"))==0)
	{
	   printf("exiting file \n ");
  	 close(sockfd);
  	 printf("socket closed : \n ");
  	 exit(1);
  }
	else
	  {
	    printf("Choose from the above choices \n ");
	  }
  }
}
