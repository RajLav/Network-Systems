/*Name :- Raj Lavingia
PA-3
Proxy Server Immplementation
Credits :- Professor Sangtae Ha
*/
//Libraries Include
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include <sys/stat.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <signal.h>
#include <arpa/inet.h>
#include <netdb.h>
#include<time.h>
#include<netdb.h>
#include<errno.h>
#include <openssl/md5.h>
#include <sys/time.h>
#include <fcntl.h>
#include <string.h>
#include <netdb.h>
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
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/sendfile.h>
#include <setjmp.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <openssl/md5.h>

//Structure defined
struct stat status;
char buffer101[1000];
char buffer200[1000];
char *buffer300;

//Variables defined
int time_out = 0;
int increase = 0;
char *Day, *Month, *Year; //For time
char requesting[1000]; // GET or PUT
char request_type[1000]; //WWW
char request_type1[1000]; //HTTP
char version[1000];
char temp10[1000];
char buftosend[10000];
char Hour[100]; //For time
char Minute[100];
int loop;
char Seconds[100];
char Hour1[100];
char Minute1[100];
char Seconds1[100];
 time_t time1;
unsigned char push[16];
int increase1 = 0; //Counting
int increase2 = 0;
char time_created[1000];
char time_created1[1000];
int increase3 = 0;
int file;
int x;
FILE *ft1,*ft2,*ft3,*ft4,*ft5,*ft6,*ft7,*ft8; //File pointers used
int count = 0;
char original[200];
char post_data[1000];
char temp55[30];
char temp56[200];
char buffer[25000];
int f1_value=0;// char f6_value[BUFSIZE];
int f10_value=0;
int optval,optval2;
char filename[] = "Blocked.txt"; // Search for this name file in folder
struct stat attribute;
struct stat st = {0};
FILE* file2;
char str[1000];
char new_token[500];
int result = 0;
char *md5sum; //md5MD5sum check list
struct sockaddr_in addr_in,client_addr,server_addr;
struct hostent* host;
int sockfd,socket_fd;
FILE *fp;
char c_name[100];
char new_token2[500];
int right_now; //time of website loaded
int present; //time when website loaded for the first time
char filenamepath[1000];
struct sockaddr_in host_addr;
int client_len=sizeof(client_addr);
char *buffer100[1000];
////Define Bufsize
#define BUFSIZE 1339
#define BUFSIZE1 2000
#define BUFSIZE8 728350
#define BUFSIZE9 34180
#define BUFSIZE10 215231
#define BUFSIZE11 41

//Headers defined
char web[] =
    "HTTP/1.1 500 internal server error\r\n"
    "Content-Type: text/html; charset = UTF-8\r\n\r\n"
    "<!DOCTYPE html>\r\n"
    "<body><center><h1>ERROR 500:INTERNAL SERVER ERROR </h1><br>\r\n";

//Check for error message
void error(char* msg)
{
  printf("\nThere is error in the loop\n\r");
  exit(0);
}

//Reference :- http://codewiki.wikidot.com/c:system-calls:fstat
//Blocked websites .txt file checking

int block(char* hostname,char* hostIP)
{
  printf("\nOpen the file to check for blocked websites\n\r");
  file = open(filename,O_RDONLY);
  if(file < 0) //Check if file is empty
  {
    printf("\nFile can not be opened\n\r");
    return 0;
  }
  else
  {
    printf("\nentered the loop of blocked wibsites\n\r");
    if(fstat(file,&status) < 0) //Check if file can be read properly or not
    {
      printf("\nError in reading file stats\n\r");
      return -1;
    }
    else
    {
      //Once file read properly check for blocked websites
      printf("\nEntered loop of File read\n\r");
      x = (int)status.st_size; //for describing the size of file
      printf("size of file %d\n\r",x);
    }

    int d =read(file,buffer,x); //reading the file
    if((strstr(buffer,hostname)!=NULL)||(strstr(buffer,hostIP)!=NULL)) //check for hostname and hostip
    {
      printf("Hostname of blocked website and Host Ip of blocked websites are%s:%s", hostname,hostIP); //Display hostname and hostip of the blocked website
      close(file);
      return 1;
    }
    else
    {
      printf("\nentered the loop but found could not proceed\n\r");
      close(file);
      return 0;
    }
  }
}
//Reference:https://stackoverflow.com/questions/7627723/how-to-create-a-md5-hash-of-a-string-in-c
//Reference :https://stackoverflow.com/questions/7627723/how-to-create-a-md5-hash-of-a-string-in-c

char *md5sumgenerate(const char *str,int l)
{
  MD5_CTX c;
  char *out = (char*)malloc(33);
  MD5_Init(&c);
  while(l > 0)
  {
    printf("\nWhen l is greater than 0\n\r");
    if(l >512)
    {
      printf("\nWhen l is greater than 512 \n\r");
      MD5_Update(&c,str,512);
    }
    else
    {
      printf("\nWhen l is smaller than 512\n\r");
      MD5_Update(&c,str,l);
    }
    l -= 512;
    str += 512;
  }
  MD5_Final(push,&c);
  for(loop = 0;loop<16;loop++)
  {
    printf("\nEntered the for loop for MD5sum\n\r");
    snprintf(&(out[loop*2]),32,"%02x",(unsigned int)push[loop]);
  }
  return out;
}

//inside the cache time check between two requests

int in_cache(char* c_name)
{
  printf("\nIn the loop of when data in cache\n\r");
  if(stat("Cache Data",&st) == -1)
  {
    //Create a directory to store the cache
    printf("\n Creation of Directory\n\r");
    mkdir("Cache Data",0700);
  }

  sprintf(str,"Cache Data/%s",c_name);
  file2 = fopen(str,"r"); //open that directory
  if(file2 == NULL) //check if the directory is NULL
  {
    printf("\nFolder is not created \n\r");
    return 0;
  }
  else
  {
       printf("\nFolder is created successfully\n\r");
       stat(str,&attribute);
       sprintf(time_created,"%s",ctime(&attribute.st_mtime));
       time(&time1); //check for real time
       printf("\nData in time created is \n\r%s\n\r",time_created);
       sprintf(time_created1,"%s", ctime(&time1));
       char *token = strtok(time_created," ");
       while (token != NULL)
       {
        increase++;
        if(increase == 1)
        {
          printf("\nDay:%s\n\r", token);
        }
        if(increase == 2)
        {
          printf("\nMonth:%s\n\r", token);
        }
        if(increase == 3)
        {
          printf("\nYear:%s\n\r", token);
        }
        if(increase == 4)
        {
          printf("\nTime:%s\n\r", token);
          strcpy(new_token,token);
          printf("\nNew token string is:%s\n\r",new_token);
        }
        if(increase == 5)
        {
          printf("Final Year:%s\n\r", token);
        }
        token = strtok(NULL, " ");

    }

        char *token1 = strtok(new_token,":");
        while(token1 !=NULL)
        {
          increase1++;
          if(increase1 == 1)
          {
            printf("\nHour:%s\n\r",token1);
            strcpy(Hour,token1);
          }
          if(increase1==2)
          {
            printf("\nMinute:%s\n\r",token1);
            strcpy(Minute,token1);
          }
          if(increase1==3)
          {
            printf("\nSeconds:%s\n\r",token1);
            strcpy(Seconds,token1);
          }
          token1 = strtok(NULL,":");
        }


        char *token2 = strtok(time_created1," ");
        while (token2 != NULL)
     {
         increase3++;
         printf("\nCount:%d\n\r",increase);
         if(increase3 == 1)
         {
           printf("\nDay:%s\n\r", token2);
         }
         if(increase3 == 2)
         {
           printf("\nMonth:%s\n\r", token2);
         }
         if(increase3 == 3)
         {
           printf("\nYear:%s\n\r", token2);
         }
         if(increase3 == 4)
         {
           printf("\nTime:%s\n\r", token2);
           strcpy(new_token2,token2);
           printf("\nNew token string is:%s\n\r",new_token2);
         }
         if(increase3 == 5)
         {
           printf("\nFinal Year:%s\n\r", token2);
         }
         token2 = strtok(NULL, " ");

     }
        char *token5 = strtok(new_token2,":");
        while(token5!=NULL)
        {
          increase2++;
          if(increase2 == 1)
          {
            printf("\nHour:%s\n\r",token5);
            strcpy(Hour1,token5);
          }
          if(increase2==2)
          {
            printf("\nMinute:%s\n\r",token5);
            strcpy(Minute1,token5);
          }
          if(increase2==3)
          {
            printf("\nSeconds:%s\n\r",token5);
            strcpy(Seconds1,token5);
          }
          token5 = strtok(NULL,":");
        }
        //convert time into decimal unit number for both the times
        right_now = atoi(Hour)*3600 + atoi(Minute)*60 + atoi(Seconds);
        present=atoi(Hour1)*3600 + atoi(Minute1)*60 + atoi(Seconds1);
        printf("\nDifference of two times is %d\n\r", present - right_now);
      //check if the time is greater or smaller
       if (present - right_now > time_out)
       {
           printf("\ntime_out is over\n\r");
           return 0;
       }

       else
       {
         printf("\nTimeout is not over\n\r");
         fclose(file2);
         return 1;
       }
    }
}

//Reference:Taken from geekforgeeks
char *replaceWord(const char *s, const char *oldW,
                                 const char *newW)
{
    char *result1;
    int i, cnt = 0;
    int newWlen = strlen(newW);
    int oldWlen = strlen(oldW);

    // Counting the number of times old word
    // occur in the string
    for (i = 0; s[i] != '\0'; i++)
    {
        if (strstr(&s[i], oldW) == &s[i])
        {
            cnt++;

            // Jumping to index after the old word.
            i += oldWlen - 1;
        }
    }

    // Making new string of enough length
    result1 = (char *)malloc(i + cnt * (newWlen - oldWlen) + 1);

    i = 0;
    while (*s)
    {
        // compare the substring with the result
        if (strstr(s, oldW) == s)
        {
            strcpy(&result1[i], newW);
            i += newWlen;
            s += oldWlen;
        }
        else
            result1[i++] = *s++;
    }

    result1[i] = '\0';
    return result1;
}

int validIP(char *ip)
{
  struct sockaddr_in sa ;
  int result = inet_pton(AF_INET, ip, &sa.sin_addr);
  return result!=0;
}

int main(int argc,char* argv[])
{
char *result1 = NULL;
char temp99[1000];
int i1;
  char string4[1000]= "IP_cache.txt";
//check for total number of arguments
if(argc<3)
{
  printf("\nInvalid arguments \n\r");
  exit (1);
}
else
{
  //arguments in .c port no timeout
  printf("\nArguments are given in correct order\n\r");
}

time_out = atoi(argv[2]);
printf("\nWaiting for user to respond\n\r");
//sin family declaration
server_addr.sin_family=AF_INET;
server_addr.sin_port=htons(atoi(argv[1]));
server_addr.sin_addr.s_addr=INADDR_ANY;
sockfd=socket(AF_INET,SOCK_STREAM,0);
//if socket not opened
if(sockfd<0)
{
  printf("\nERROR opening socket\n\r");
  exit(1);
}
else
{
 printf("\nsocket openend\n\r");
}
if(bind(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr))<0)
{
   printf("\nERROR on binding\n\r");
   exit(1);
}
else
{
  printf("\nBinding done between server and client \n\r");
}
//maximum numbers of multiple requests
listen(sockfd,50);
//go to point
Raj:
socket_fd=accept(sockfd,(struct sockaddr*)&client_addr,&client_len);
if(socket_fd<0)
{
  printf("\nconnection is not established\n\r");
  exit (1);
}
else
{
  printf("\nConnection is established\n\r");
}
//start forking
if(!fork())
{

printf("\nEntered the child process\n\r");
int flag=0,socket_fd1,n,port=0,i,sockfd1;
char buffer[1000];char buffer3[1000];
char* temp9=NULL;
int ret = 0;
bzero((char*)buffer,500);
char request_type3[500];
char temp1000[1000];
//printf("\nBuffer value in the beginning is %s\n\r",buffer);
recv(socket_fd,buffer,500,0);
//printf("\nBuffer value in the Middle is %s\n\r",buffer);
sscanf(buffer,"%s %s %s",requesting,request_type,version);
printf("\nrequest_type is %s\n\r",request_type);
strcpy(temp1000,request_type);
strcpy(request_type3,request_type);
char request_type34[1000];
if(strncmp(request_type3,"http://",7)==0)
{
  printf("\nWhen http is present\n\r");
}
else
{
  printf("\nWhen http is not present\n\r");
  char Bad_Request[200] = "<html><body><H1>Error 400 Bad Request: Invalid method </H1></body></html>";
  send(socket_fd,Bad_Request,strlen(Bad_Request),0);
  exit(0);
}
//printf("\nBuffer data in the main loop is %s\n",buffer);
printf("\nData in requesting is %s\n\r",requesting);
printf("\nData in request_type is %s\n\r",request_type);
printf("\nData in version is %s\n\r",version);
strcpy(request_type1, request_type);
strcpy(request_type34,request_type1);
printf("\nrequest_type1 is %s\n\r",request_type1);
//port defined for general purpose browsing
temp9=strtok(request_type1,"//");
if(flag==0)
{
  port=80;
  temp9=strtok(NULL,"/");
}
else
{
  temp9=strtok(NULL,":");
}
printf("\ndata in temp9 is %s\n\r",temp9);
strcpy(temp99,temp9);
int r1 = validIP(temp9);
printf("is IP valid %d",r1);
if(r1 == 0)
{
  printf("\nNOT valid IP\n\r");

}
else
{

  ft2 = fopen("IP_cache.txt","r");
  fseek(ft2, 0, SEEK_END);
  int file_size56 = ftell(ft2);
  fseek(ft2,0,SEEK_SET);
  int num_bytes44 = file_size56;
  printf("\n******File size is**** %d\n\r",num_bytes44);
  fread(temp55,num_bytes44,1,ft2);
  fclose(ft2);
  printf("data in temp55 is %s\n\r",temp55);
  char * pch;
  pch = strstr (temp55,temp9);
  printf("\npch data is %s\n\r",pch);
  int ra1 = pch - temp55;
  printf("ra1 data is %d\n\r",ra1);
  ft2 = fopen("IP_cache.txt","r");
  fseek(ft2,15,SEEK_SET);
  fread(temp56,(num_bytes44-15),1,ft2);
  printf("temp56 data is %s\n\r",temp56);

  result1 = replaceWord(temp1000,temp99,temp56);
  strcpy(buffer200,result1);
  strtok(result1,"\n");
  buffer300 = strtok(buffer200,"\n");
  buffer300 = strtok(NULL,"\n");
  strcpy(buffer200,buffer300);
  strcat(result1,buffer200);
  printf("result1 final is %s\n\r",result1);

  //printf("\nresult1 is %s\n\r",result1);

}
  sprintf(request_type1,"%s",temp9);
//getting the IP of a web address for correction purpose
host=gethostbyname(request_type1);
//printf("request_type1 is %s\n\r",request_type1);
/*
if(host == NULL)
{
  printf("Entered in the null loop\n\r");
  char blocked[100] = "<html><body><H1>Error 404 File not found </H1></body></html>";
  send(socket_fd,blocked,strlen(blocked),0);
  goto Raj2;
}*/
//Check if the IP or website is in the black list option or not
  bzero((char*)&host_addr,sizeof(host_addr));
  host_addr.sin_port=htons(port);
  host_addr.sin_family=AF_INET;
  bcopy((char*)host->h_addr,(char*)&host_addr.sin_addr.s_addr,host->h_length);
  sockfd1=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
  socket_fd1=connect(sockfd1,(struct sockaddr*)&host_addr,sizeof(struct sockaddr));
  sprintf(buffer,"%s %s\n",inet_ntoa(host_addr.sin_addr),request_type);

  char *j = inet_ntoa(host_addr.sin_addr);
  printf("\nvalue of j is %s\n\r",j);//IP address to be put in the text file

  char buffer4[1000];
  strcpy(buffer4,j);

  printf("\nBuffer4 value is %s\n\r",buffer4);
  ret = block(request_type,inet_ntoa(host_addr.sin_addr));
  if(ret == 1) //if the blocked website is found from the blacklist function
  {
    printf("\nLoop of website blocked\n\r");
    char blocked[100] = "<html><body><H1>Error 403 Forbidden </H1></body></html>";
    send(socket_fd,blocked,strlen(blocked),0);
    exit(0);
  }

//Check for these conditions of GET HTTP and http://
if(((strncmp(requesting,"GET",3)==0))&&((strncmp(version,"HTTP/1.1",8)==0)||(strncmp(version,"HTTP/1.0",8)==0))&&(strncmp(request_type,"http://",7)==0))
{

strcpy(requesting,request_type);
printf("\nData in requesting after strcpy is %s\n\r",requesting);
strcpy(temp10,request_type);
printf("\nData in temp10 after strcpy is %s\n\r",temp10);
printf("replace data %s\n\r",temp99);
if(r1==1)
{
  printf("\nif r1 = 1 loop\n\r");
  md5sum = md5sumgenerate(result1,strlen(result1));
}
else
{
  printf("\nif r1 = 0 loop\n\r");
  md5sum = md5sumgenerate(temp10,strlen(temp10));
}
printf("\nmd5sum is %s\n",md5sum);
sprintf(c_name,"%s.html",md5sum);
printf("\nData in cache name is %s\n\r",c_name);
result = in_cache(c_name);
printf("\nresult data is %d\n\r",result);

if(result == 0)
{
  printf("\nEntered loop when result is 0\n\r");
  printf("\nNot in cache\n\r"); // when the data is not in cache and getting from the server
  sprintf(filenamepath,"Cache Data/%s",c_name);
  printf("\nfilenamepath is %s\n\r",filenamepath);
  fp = fopen(filenamepath,"w+");
  flag=0;
  temp9=strtok(request_type,"//");
  printf("\nValue of temp9 is %s for //\n\r",temp9);
  if(flag==0)
  {

  port=80;
  temp9=strtok(NULL,"/");
  printf("\nValue of temp9 is %s for / \n\r",temp9);
  }
  sprintf(request_type,"%s",temp9);
  printf("\nhost = %s\n\r",request_type);
  if(flag==1)
  {
  temp9=strtok(NULL,"/");
  printf("\nValue of temp9 is %s for / in flag=1 \n\r",temp9);
  port=atoi(temp9);
  }
  strcat(requesting,"^]");
  temp9=strtok(requesting,"//");
  printf("\nValue of temp9 is %s for // in flag 1\n\r",temp9);
  temp9=strtok(NULL,"/");
  printf("\nValue of temp9 is %s for / in flag 1\n\r",temp9);
  if(temp9!=NULL)
  temp9=strtok(NULL,"^]");
  printf("\npath: %s\nPort: %d\n",temp9,port);
  //Check if the IP or website is in the black list option or not
    bzero((char*)&host_addr,sizeof(host_addr));
    host_addr.sin_port=htons(port);
    host_addr.sin_family=AF_INET;
    bcopy((char*)host->h_addr,(char*)&host_addr.sin_addr.s_addr,host->h_length);
    sockfd1=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    socket_fd1=connect(sockfd1,(struct sockaddr*)&host_addr,sizeof(struct sockaddr));
    sprintf(buffer,"\nwebsite %s  i.p address is - %s\n",request_type,inet_ntoa(host_addr.sin_addr));
    ret = block(request_type,inet_ntoa(host_addr.sin_addr));
    if(ret == 1) //if the blocked website is found from the blacklist function
    {
      printf("\nLoop of website blocked\n\r");
      char blocked[100] = "<html><body><H1>Error 403 Forbidden </H1></body></html>";
      send(socket_fd,blocked,strlen(blocked),0);
      exit(0);
    }
    else
  {
  if(socket_fd1<0)
  error("Error in connecting to remote server");
  printf("\n%s\n\r",buffer);
  bzero((char*)buffer,sizeof(buffer));
  if(temp9!=NULL)
  {
    printf("\nSending it to host\n\r");
    sprintf(buffer,"GET /%s %s\r\nHost: %s\r\nConnection:\r\n\r\n",temp9,version,request_type);
  }
  else
  {
    printf("\nSending it to host\n\r");
    sprintf(buffer,"GET / %s\r\nHost: %s\r\nConnection:\r\n\r\n",version,request_type);
  }

  n=send(sockfd1,buffer,strlen(buffer),0);

  if(n<0)
  {
    printf("\nCannot write to socket\n\r");
  }
  else
  {
  do
  {
    printf("/n In the do loop\n\r");
    bzero((char*)buffer,500);
    n=recv(sockfd1,buffer,500,0);
    if(!(n<=0))
    {
      printf("\nUntill n is greater than 0\n");
      send(socket_fd,buffer,n,0);
      fwrite(buffer,1,n,fp);
    }
  }while(n>0);
  }
  fclose(fp);
  }
prefetch_func(filenamepath,sockfd1);
}
else
{
  printf("Entered in the loop when it takes from cache\n\r");

  flag=0;
  if(flag==1)
  {
  temp9=strtok(NULL,"/");
  printf("\nValue of temp9 is %s for / in flag=1 \n\r",temp9);
  port=atoi(temp9);
  }
    //parameters defined for contacting telnet
  strcat(requesting,"^]");
  temp9=strtok(requesting,"//");
  printf("\nValue of temp9 is %s for // in flag 1\n\r",temp9);
  temp9=strtok(NULL,"/");
  printf("\nValue of temp9 is %s for / in flag 1\n\r",temp9);
  if(temp9!=NULL)
  temp9=strtok(NULL,"^]");
  printf("\npath: %s\nPort: %d\n",temp9,port);

  {
  //if in cache then sent it again from the cache to save time
  char fname_path[1000];
  sprintf(fname_path,"Cache Data/%s",c_name);
  printf("present in cache\n");
  fp = fopen(fname_path,"r");
  do {
      n = fread(buftosend,1,10000,fp);
      send(socket_fd,buftosend,n,0);
      printf("Sent from the cache\n");
  }while(n > 0);
  fclose(fp);
}
}
}
else
{
  // Bad request because not in GET or not proper HTTP
  printf("\nWhen GET or http:// or HTTP given are wrong\n\r");
  char Bad_Request[200] = "<html><body><H1>Error 400 Bad Request: Invalid method </H1></body></html>";
  send(socket_fd,Bad_Request,strlen(Bad_Request),0);
}
close(sockfd1);
close(socket_fd);
close(sockfd);
_exit(0);
}
else
{
close(socket_fd);
goto Raj;
}
Raj2:
printf("reached the end\n");

return 0;

}
