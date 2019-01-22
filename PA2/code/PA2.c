/*Name :- Raj Lavingia
Credits :- Professor Sangtae
Date :- 10/21/2018
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
#include <netdb.h>
#include <sys/stat.h>
#include <sys/sendfile.h>
#include <setjmp.h>


////Define Bufsize
#define BUFSIZE 1339
#define BUFSIZE1 2000
#define BUFSIZE8 728350
#define BUFSIZE9 34180
#define BUFSIZE10 215231
#define BUFSIZE11 41

int PIPELINE;

char web1[] =

"HTTP/1.1 200 OK\r\n"
"Content-Type: image/jpg\r\n\r\n";

char web2[] =

"HTTP/1.1 200 OK\r\n"
"Content-Type: image/gif\r\n\r\n";

char web3[] =

"HTTP/1.1 200 OK\r\n"
"Content-Type: text/plain\r\n\r\n";


char web4[] =

"HTTP/1.1 200 OK\r\n"
"Content-Type: text/css\r\n\r\n";

char web5[] =

"HTTP/1.1 200 OK\r\n"
"Content-Type: image/png\r\n\r\n";


char web6[] =

"HTTP/1.1 200 OK\r\n"
"Content-Type: javascript\r\n\r\n";

char web7[] =

"HTTP/1.1 200 OK\r\n"
"Content-Type: text/html\r\n\r\n";



  const char *get_filename_ext(const char *filename1)
  {
    const char *dot = strrchr(filename1, '.');
    if(!dot || dot == filename1) return "";
    return dot + 1;
  }

int main(int argc, char **argv)
{

  struct timeval time;
  int sockfd;   // Name of the socket
  int portno;  //Port Number Defination
  int newsocket; //Another socket created
  int p;int i1=0;
  int clientlen; /* byte size of client's address */
  socklen_t client_raj;
  int counter = 0;
  int count_value = 0;
  int timing_raj = 20;
  struct sockaddr_in serveraddr; /* server's addr */
  struct sockaddr_in clientaddr; /* client addr */
  struct dirent *in;
  struct hostent *hostp; /* client host info */
  int counter3;
  int counter2 = 0;
  char buf[BUFSIZE];
  char *buffer;
  char buf8[BUFSIZE8];
  char buf9[BUFSIZE9];
  char buf11[BUFSIZE11];
  char return_value[5000];
  char return_value1[2000];
  char decider[1000];
  char return_value22[2000];
  char return_value5[2000];
  char rajbuffer_sending[BUFSIZE]; //Buffer created for sending
  char rajbuffer_receiving[BUFSIZE]; //Buffer created for receiving
  char filename[BUFSIZE];
  char *hostaddrp; /* dotted decimal host addr string */
  char nameoffile[BUFSIZE];
  char send_buf[BUFSIZE];
  char command10[BUFSIZE];char command11[15];
  int f1_value=0;// char f6_value[BUFSIZE];
  int f10_value=0;
  int optval,optval2;
  int n,m,o;
  long int num_bytes = 0;
  long int file_size;
  int client_sock;
  FILE *ft1,*ft2,*ft3,*ft4,*ft5,*ft6,*ft7,*ft8;
  int count = 0;
  char original[200];
  char post_data[1000];

  printf("Enter 1 for pipeline, 0 for normal operation");
  scanf("%d", &PIPELINE);

  char web[] =
    "HTTP/1.1 500 internal server error\r\n"
    "Content-Type: text/html; charset = UTF-8\r\n\r\n"
    "<!DOCTYPE html>\r\n"
    "<body><center><h1>ERROR 500:INTERNAL SERVER ERROR </h1><br>\r\n";

  if (argc != 2) //There are 2 arguments , Ip address and port number
  {
    fprintf(stderr,"\nport number is not matched according to the requirement \n");
    exit(1); //To get out of the code
  }
  else
  {
   printf("\nArguments given are in correct number \n " );
  }
  portno = atoi(argv[1]); //Converts the string to integer, argv will contain the file name
  printf("\nWaiting for Client \n");
  sockfd = socket(AF_INET, SOCK_STREAM, 0); //Default for UDP is SOCK_DGRAM
  if (sockfd < 0)
  {
    printf("\nERROR opening socket\n");
    exit(1);
  }

  else
  {
   printf("\nsocket openend \n ");
  }
  optval = 1;
  setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval , sizeof(int));
  bzero((char *) &serveraddr, sizeof(serveraddr)); // clears whatever is in there before we make a fresh start
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = htonl(INADDR_ANY); //host to network long
  serveraddr.sin_port = htons((unsigned short)portno); //host to network short
  if (bind(sockfd, (struct sockaddr *) &serveraddr,
	   sizeof(serveraddr)) < 0)
    {
       printf("\nERROR on binding\n");
       exit(1);
    }
  else
    {
      printf("\nBinding done between server and client \n");
    }

  if(listen(sockfd , 7)<0)
  {
    exit(1);
  }
  else{printf("\nListening again \n");}

    while(1)
{
  client_sock = accept(sockfd,(struct sockaddr*)&clientaddr,&clientlen);

  if(client_sock < 0)
    {
      printf("\nconnection is not established \n");
      break;
    }

  else
    {

     printf("\nconnection is established \n");
     if(!fork())
    {
      char string5[200];
Raj:
      close(sockfd);
      char string4[150] = "/home/raj/Downloads/www/www";
      printf("\nraj\n");
      bzero(buf,BUFSIZE);
      read(client_sock,buf,sizeof(buf));
      strcpy(return_value1,buf);
      strcpy(return_value5,buf);
      strcpy(return_value22,buf);
      printf("return value 22 is %s",return_value22);
      int init_size = strlen(return_value1);
	    char delim[] = " ";
      char *ptr = strtok(return_value1, delim);
      printf("\nfirst value of the broken string is %s\n",return_value1);
      strcpy(decider,return_value1);
      printf("\nvalue of decider for either GET or POST is\n%s\n",decider);

      printf("\n\r\n\rcount: %d\n\r\n\r", count);
      if(!strncmp(decider,"GET",3))
    {
      printf("In the get loop\n");
      {
      if(PIPELINE==1)
      {
      printf("This loop is used for telnet command \n");
      while(ptr != NULL)
	     {
        ptr = strtok(NULL, delim);
        printf("\nFile name:%s\n",ptr);
        count++;
        if(count==1 || count == 6)
        {
          char *return_value3 = ptr;
          printf("in count 1:%s\n\r",return_value3);
          strcpy(return_value,get_filename_ext(return_value3));
          strcat(string4,return_value3);
        }
        else if(count == 2)
        {
          char *return_value4 = ptr;
          printf("in count 2:%s\n\r",return_value4);
          strcat(string5,return_value4);
          //count = 0;
        }

	     }
     }

     else if(PIPELINE == 0)
     {
       printf(" This loop is NOT used for telnet command \n");
       while(ptr != NULL)
 	     {
         ptr = strtok(NULL, delim);
         printf("\n\nFile name;%s\n", ptr);
         count++;
         if(count==1)
         {
           char *return_value3 = ptr;
           printf("in count 1:%s\n\r",return_value3);
           strcpy(return_value,get_filename_ext(return_value3));
           strcat(string4,return_value3);
         }
         else if(count == 2)
         {
           char *return_value4 = ptr;
           printf("in count 2:%s\n\r",return_value4);
           strcat(string5,return_value4);
         }

 	     }
     }
   } //if GET comes from the user loop end



       printf("\n%s\n\r",return_value);
       if(((!strncmp(return_value, "jpg",3)))||(!strncmp(return_value, "gif",3))||(!strncmp(return_value, "png",3))||(!strncmp(return_value, "css",3))||(!strncmp(return_value, "txt",3))||(!strncmp(return_value, "js",2))||(!strncmp(buf, "GET / HTTP/1.1",14)))
       {
         printf("extensions supported\n\n");

       printf("string 5 is %s",string5);


       if((!strncmp(string5,"HTTP/1.0",8))||(!strncmp(string5,"HTTP/1.1",8)))
       {
       printf("\nHTTP is either 1.1 or 1.0 \n");
      if(!strncmp(return_value, "jpg",3))
       {
       printf("For Image contents 2 of .jpg format\n");
       ft1=fopen(string4,"r");
       if(ft1 == NULL)
       {
         write(client_sock,web,sizeof(web)-1);
         printf(" File not found \n");
         goto Raj2;
        //break;
       }
       else
       {
         write(client_sock,web1,sizeof(web1)-1);
         fseek(ft1, 0, SEEK_END);
       	 file_size = ftell(ft1);
       	 fseek(ft1,0,SEEK_SET);
       	 num_bytes = file_size;
         printf("Number of bytes of file is %ld \n",num_bytes);
         char buf1[num_bytes];
         bzero(buf1,sizeof(buf1));
         int result = fread(buf1,1,num_bytes, ft1);
         write(client_sock,buf1,sizeof(buf1));
       }
         fclose(ft1);
     }


      if(!strncmp(return_value, "gif",3))
      {
       printf("For Image contents of .gif format\n");
       ft2=fopen(string4,"r");
       if(ft2 == NULL)
       {
         write(client_sock,web,sizeof(web)-1);
         printf(" File not found \n");
         goto Raj2;
         //break;
       }
         write(client_sock,web2,sizeof(web2)-1);
         fseek(ft2, 0, SEEK_END);
       	 file_size = ftell(ft2);
       	 fseek(ft2,0,SEEK_SET);
       	 num_bytes = file_size;
         printf("Number of bytes of file is %ld \n",num_bytes);
         char buf2[num_bytes];
         bzero(buf2,sizeof(buf2));
         int result1 =  fread(buf2,1,num_bytes,ft2);
         write(client_sock,buf2,sizeof(buf2));
         fclose(ft2);
      }

     if(!strncmp(return_value, "png",3))
    {
     printf("For Image contents of .jpg1 format\n");
     ft5=fopen(string4,"r");
      if(ft5 == NULL)
      {
        write(client_sock,web,sizeof(web)-1);
        printf(" File not found \n");
        goto Raj2;
      }
     write(client_sock,web5,sizeof(web5)-1);
     fseek(ft5, 0, SEEK_END);
     file_size = ftell(ft5);
     fseek(ft5,0,SEEK_SET);
     num_bytes = file_size;
     printf("Number of bytes of file is %ld \n",num_bytes);
     char buf5[num_bytes];
     bzero(buf5,sizeof(buf5));
     int result5 =  fread(buf5,1,num_bytes,ft5);
     write(client_sock,buf5,sizeof(buf5));
     fclose(ft5);
   }

       if(!strncmp(return_value, "txt",3))
      {
       printf("For Image contents of txt format\n");
       ft3=fopen(string4,"r");
       if(ft3 == NULL)
       {
         write(client_sock,web,sizeof(web)-1);
         printf("File not found \n");
         goto Raj2;
       }
       else
       {
         write(client_sock,web3,sizeof(web3)-1);
         fseek(ft3,0,SEEK_END);
       	 file_size = ftell(ft3);
       	 fseek(ft3,0,SEEK_SET);
       	  num_bytes = file_size;
         printf("Number of bytes of file is %ld \n",num_bytes);
         char buf3[num_bytes];
         bzero(buf3,sizeof(buf3));
         int result2 = fread(buf3,1,num_bytes,ft3);
         write(client_sock,buf3,sizeof(buf3));
         bzero(string4, sizeof(string4));
       }
         printf("exit 1 worked\n");
         fclose(ft3);

       }

       if(!strncmp(return_value, "css",3))
    {

     printf("For Image contents of css format\n");
     ft4=fopen(string4,"r");
     if(ft4 == NULL)
     {
       write(client_sock,web,sizeof(web)-1);
       printf(" File not found \n");
       goto Raj2;
     }
       write(client_sock,web4,sizeof(web4)-1);
       fseek(ft4, 0, SEEK_END);
       long int file_size2 = ftell(ft4);
       fseek(ft4,0,SEEK_SET);
       long int num_bytes2 = file_size2;
       char buf4[num_bytes2];
       printf("Number of bytes of file is %ld \n",num_bytes2);
       bzero(buf4,sizeof(buf4));
       long int result3 = fread(buf4,1,num_bytes2,ft4);
       printf("%ld",result3);
       write(client_sock,buf4,sizeof(buf4));
       fclose(ft4);
    }
    if(!strncmp(return_value, "js",2))
      {
       printf("For Image contents of js format\n");
       ft6=fopen(string4,"r");
       if(ft6 == NULL)
       {
         write(client_sock,web,sizeof(web)-1);
         printf(" File not found \n");
         goto Raj2;
       }
       write(client_sock,web6,sizeof(web6)-1);
       fseek(ft6, 0, SEEK_END);
       long int file_size6 = ftell(ft6);
       fseek(ft6,0,SEEK_SET);
       long int num_bytes6 = file_size6;
       char buf6[num_bytes6];
       printf("\nNumber of bytes of file is %ld \n",num_bytes6);
       bzero(buf6,sizeof(buf6));
       long int result6 = fread(buf6,1,num_bytes6,ft6);
       write(client_sock,buf6,sizeof(buf6));
       fclose(ft6);
     }

  if(!strncmp(buf, "GET / HTTP/1.1",14))
  {
   printf("\nFor Image contents of html format\n");
   ft7=fopen("/home/raj/Downloads/www/www/index.html","r");
   if(ft7 == NULL)
   {
     write(client_sock,web,sizeof(web)-1);
     printf("\nFile not found \n");
     goto Raj2;
   }
   else
   {
   write(client_sock,web7,sizeof(web7)-1);
   fseek(ft7, 0, SEEK_END);
   file_size = ftell(ft7);
   fseek(ft7,0,SEEK_SET);
   num_bytes = file_size;
   printf("\nNumber of bytes of file is %ld \n",num_bytes);
   char buf7[num_bytes];
   bzero(buf7,sizeof(buf7));
   fread(buf7,1,num_bytes, ft7);
   write(client_sock,buf7,sizeof(buf7));
 }
   fclose(ft7);
 }

 /*else
 {
   write(client_sock,web,sizeof(web)-1);
   printf("\nNone of the choices selected \n");
   //break;
    //exit(0);
 }
*/


} //if loop of http 1.1 or 1.0 finished

else //1.1 or 1.0 closing
  {
    printf("\nHTTP is not 1.1 or 1.0\n");
  }

} //extensions condition checking loop closed
else
{
   write(client_sock,web,sizeof(web)-1);
   //break;
}//if extensions are not correct then this loop will end finally

}// GET loop ended here

else if(!strncmp(decider,"POST",4))
{

{
  printf("\nIn the put section\n");
  if(PIPELINE==1)
  {
  printf("This loop is used for telnet command \n");
  while(ptr != NULL)
   {
    ptr = strtok(NULL, delim);
    printf("\nFile name:%s\n",ptr);
    count++;
    if(count==1 || count == 6)
    {
      char *return_value3 = ptr;
      printf("in count 1:%s\n\r",return_value3);
      strcpy(return_value,get_filename_ext(return_value3));
      strcat(string4,return_value3);
    }
    else if(count == 2)
    {
      char *return_value4 = ptr;
      printf("in count 2:%s\n\r",return_value4);
      strcat(string5,return_value4);
      //count = 0;
    }
   else if (count == 4)
    {
      char *return_value5 = ptr;
      printf("in count 4:%s\n\r",return_value5);
      const char ch = '\n';
      char *ret;

      ret = strrchr(return_value5,ch);
      printf("\nnew string is after strrchr %s\n",ret);
      strcpy(post_data,ret);
      printf("\ndata entered from user while posting is %s\n",post_data);


    }

   }
 }

 else if(PIPELINE == 0)
 {
   printf(" This loop is NOT used for telnet command \n");
   while(ptr != NULL)
   {
     ptr = strtok(NULL, delim);
     printf("\n\nFile name;%s\n", ptr);
     count++;
     if(count==1)
     {
       char *return_value3 = ptr;
       printf("in count 1:%s\n\r",return_value3);
       strcpy(return_value,get_filename_ext(return_value3));

       strcat(string4,return_value3);
     }
     else if(count == 2)
     {
       char *return_value4 = ptr;
       printf("in count 2:%s\n\r",return_value4);
       strcat(string5,return_value4);

     }

   }
 }
}
printf("Extension in the POST statement is %s\n",return_value);
char buffer_header[500];
sprintf(buffer_header,"HTTP/1.1 200 OK\r\nContent Type: %s\r\n<html><body><pre><h1>%s</h1></pre>\r\n","text/html",post_data);
printf("buffer_header is %s\n",buffer_header);

 printf("return_value5 is %s",return_value5);

 if((!strncmp(return_value,"txt",3))||(!strncmp(return_value,"css",3))||(!strncmp(return_value,"jpg",3))||(!strncmp(return_value,"png",3))||(!strncmp(return_value,"js",2))||(!strncmp(return_value,"gif",3)))
 {
  printf("\nFor Post statements\n");
  ft8=fopen(string4,"r");
  printf("string 4 is %s\n",string4);
  if(ft8 == NULL)
  {
    write(client_sock,web,sizeof(web)-1);
    printf("\nFile not found \n");
    goto Raj2;
    //break;
  }
  else
  {
  write(client_sock,buffer_header,sizeof(buffer_header)-1);
  printf("web8 is %s",buffer_header);
  fseek(ft8, 0, SEEK_END);
  file_size = ftell(ft8);
  fseek(ft8,0,SEEK_SET);
  num_bytes = file_size;
  printf("\nNumber of bytes of file is %ld \n",num_bytes);
  char buf8[num_bytes];
  bzero(buf8,num_bytes);
  fread(buf8,1,num_bytes,ft8);

  write(client_sock,buf8,sizeof(buf8));
  printf("buf8 is %s \n",buf8);
}
  fclose(ft8);
}
else if(!strncmp(buf, "POST / HTTP/1.1",15))
{
 printf(" POST HTML Format\n");
 printf("\nFor Image contents of html format\n");
 ft7=fopen("/home/raj/Downloads/www/www/index.html","r");
 if(ft7 == NULL)
 {
   write(client_sock,web,sizeof(web)-1);
   printf("\nFile not found \n");
   goto Raj2;
  // break;
 }
 else
 {
 write(client_sock,buffer_header,sizeof(buffer_header)-1);
 fseek(ft7, 0, SEEK_END);
 file_size = ftell(ft7);
 fseek(ft7,0,SEEK_SET);
 num_bytes = file_size;
 printf("\nNumber of bytes of file is %ld \n",num_bytes);
 char buf7[num_bytes];
 bzero(buf7,sizeof(buf7));
 fread(buf7,1,num_bytes, ft7);
 write(client_sock,buf7,sizeof(buf7));
}
 fclose(ft7);
}

}

    //break;
      //still in fork loop
Raj2:
      if(PIPELINE == 1)
      {
      printf("\nReturn value 22 at the end is  :%s\n",return_value22);
      buffer = strstr(buf,"Connection: Keepalive");
      printf("\nValue of buffer is before the pipelining %s\n",buffer);
      if(buffer != NULL)
      {
        time.tv_sec = 10;
        int pattern1 = setsockopt(client_sock, SOL_SOCKET, SO_RCVTIMEO, (const char *)&time, sizeof(struct timeval));
        printf("pattern1 : is %d\n",pattern1);
        printf("Entering pipelining \n");
        count_value++;
        printf("value of count_value in the piplelining is %d",count_value);
        goto Raj;
      }
      else
      {
        time.tv_sec = 0;
        int pattern2 = setsockopt(client_sock, SOL_SOCKET, SO_RCVTIMEO, (const char *)&time, sizeof(struct timeval));
        printf("pattern2 : is %d",pattern2);
      }
    }


  }//fork loop finished

    //parent process4
    else
    {
      printf("Lavingia \n");
      close(client_sock);
      //break;
    }
//parent and child finished
  }
  /*close(sockfd);
  close(client_sock);*/
}
 //close(client_sock);
//close(sockfd);
printf("Reached \n");
return 0;
}
