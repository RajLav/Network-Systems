/*Name :- Raj Lavingia
PA-4
Distributed File System
Credits :- Professor Sangtae Ha
*/

//Libraries included
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include <sys/stat.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>
#include<errno.h>
#include <openssl/md5.h>
#include <sys/time.h>
#include <time.h>
#include <fcntl.h>
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
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/sendfile.h>
#include <setjmp.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/time.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <sys/time.h>
#include <pthread.h>
#include <semaphore.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
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
#include <openssl/md5.h>
#include <sys/stat.h>
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<netdb.h>
#include<fcntl.h>
#include <sys/dir.h>

//Macros defined
#define max 4
#define BUFFER_SIZE 512
#define buffer_in 500
#define buffer_max 500
#define timing_connection 10
#define buffer_in_max 512
#define buffer_out_temp 512
#define maximum_value_buffer 1024

//Variables declared
char *Day, *Month, *Year; //For time
char version[1000];
char temp10[1000];
char buftosend[10000];
char Hour[100]; //For time
char Minute[100];
char Seconds[100];
char Hour1[100];
char Minute1[100];
char Seconds1[100];
char* temp4;
unsigned char push[16];
char time_created[1000];
char time_created1[1000];
char bytes_out_received[buffer_in];
char dfs_in[5];
char data_server[5];
//int x;
int size_data;
FILE *ft3,*ft4,*ft5,*ft6,*ft7,*ft8; //File pointers used

char temp[buffer_in];
char tempin[buffer_in];
char* temp1;
char* temp2;
char* temp33;
char* temp44;
char* temp7;
char* temp8;
char* comapare;
char* comapare2;
char* comapare3;
char* comapare4;
char* port_number1;
char* port_number2;
char* port_number3;
char* port_number4;
char value_determined[150];
char value_determined2[150];
char value_determined3[150];
char value_determined4[150];
char value_determined5[150];
char value_determined6[150];
char data_in[10];
int servernumber;
int setsize = 0;
int lastsize = 0;
int increase = 0;
int increase1 = 0;
int increase2 = 0;
int increase3 = 0;
int increase10 = 0;
int sock_file[max];
int port_number;
int size_of_file_pieces;
int total_file_size;
int first_apart;
int _apart_sizetwo;
int last_apart_sizesize;
int clientlength;
int temperory;
char md5_in_temp[100];
char bytes_out_received[buffer_in];
char command[buffer_in];
char file[buffer_max];
char inusername[buffer_max];
char inpassword[buffer_max];
char allow[15] = "yes";
char stop[20]= "no";
char conffile[200];
char cli[500]={};
char filestored[30][300] = {};
char store_file_buffer[4][400] = {};
char store_data[500]={};
char first_file_apart[1000000];
char second_apart[1000000];
char third_apart[1000000];
char fourth_apart[1000000];
int newsockfd;
int distributiontable[4][4] = {{12,23,34,41}, {41,12,23,34}, {34,41,12,23}, {23,34,41,12}};//file distribution table
char filesize[10];
char folder_in_folder[10];
char userfolder_in_folder[10];
//Eroor condition function
int sending_bytes;
int servers_in_place[4] = {0};
uint8_t data_to_file[4] = {0};
uint8_t listof_apart_sizes[4] = {0};
char newfile[100] = "duplicate";

void error(char* message_user)
{
    printf("\n\r Error is occured\n");
}
//Authentication Function created
typedef enum result_pass
{
    SUCCESS = 0, //If success it will return 0
    FAILURE, //Else it will return 1
} result_pass_fail; //Function

//Structure defined
typedef struct server{
    char ip[20]; //IP and Port number defined
    char port[6];
} server_t;

//Authentication Function described
typedef struct authentication{
    char username[10]; //Username and password for authentication
   char password[10];
} cred_t;

//parse a data in function
result_pass_fail parseCommand(char parsing[buffer_in], char filename[buffer_in], char within_directory_formation[buffer_in])
{
    int temp2 = 0;
    char* pointing = parsing;
    pointing = strtok(parsing, " \n"); //Strtok of a big string done here
    printf("\n\rValue stored in pointing buffer is %s\n",pointing);
    while (pointing != NULL)
    {
        //while loop started
        if (temp2 == 0)
        {
            //Inside the loop when temp 2 is 0
            printf("\n\rWhen temp2 is 0\n");
            strncpy(temp, pointing , strlen(pointing));
            printf("\n\rAfter copying data is %s",temp);
        }
        else if (temp2 == 1)
        {

            //temp2 is 1
            printf("\n\rWhen temp2 is 1\n");
            strncpy(filename, pointing, strlen(pointing));
            printf("\n\rAfter copying data2 is %s",filename);
        }
        else
        {

            printf("\n\rWhen temp2 is nothing\n");
            strncpy(within_directory_formation, pointing, strlen(pointing));
            printf("\n\rAfter copying data is %s",within_directory_formation);
        }
        temp2++;
        pointing = strtok(NULL, " ,-\n"); //strtok used again for concatenate
    }
    return SUCCESS; //returning 1 or 0 depending on the situatuoin
}

result_pass_fail parseConfFile(cred_t* cred, server_t* connection_server, char file[])
{
     FILE *fp = fopen(file,"r");
     if(fp==NULL)
      {
           //File pointer described here if null file cannot be opened
           printf("\n\rfile is not present\n");
      }
      else
      {
          //File opened successfuly
        printf("\n\rFile is present\n");
        char data_surrendered_in[500];
        while(fgets(data_surrendered_in, sizeof(data_surrendered_in), fp))
        {
          //while loop is started
          temp4 = strtok(data_surrendered_in, "\n");
          printf("\n\rtemp4 value is %s\n",temp4);
          if (strncmp(temp4, "#server one", 11) == 0)
          {
                //String is matched
                printf("\n\rEntered the loop of server one\n");
                fgets(value_determined, sizeof(value_determined), fp);//pointer is directed here
                printf("\n\rvalue determined: %s\n",value_determined);
                temp1 = strtok(value_determined, "\n\t");
                temp1 = strtok(value_determined, "\n\t ");
                temp1 = strtok(NULL, "\n\t "); //Final temp1 value is got here
                printf("\n\rtemp1 value is %s\n",temp1);
                comapare = strtok(NULL, "\n\t: ");
                printf("\n\rcompare value is %s\n",comapare);
                port_number1 = strtok(NULL, "");
                printf("\n\rport_number1 is %s\n",port_number1);
                strcpy(connection_server->ip,comapare);
                strcpy(connection_server->port, port_number1);
                //printf("\n\rconnection_server is %s\n",connection_server);
                connection_server++;
            }
          if (strncmp(temp4, "#server two", 11) == 0)
          {
                //When it matches to 2
                fgets(value_determined2, sizeof(value_determined2), fp);
                printf("\n\rEntered the loop of server one\n");
                printf("\n\rvalue determined2: %s\n",value_determined2);
                temp2 = strtok(value_determined2, "\n\t");
                temp2 = strtok(value_determined2, "\n\t ");
                temp2 = strtok(NULL, "\n\t ");
                printf("\n\rtemp2 value is %s\n",temp2);
                comapare2 = strtok(NULL, "\n\t: ");
                printf("\n\rcomapre2 value is %s\n",comapare2);
                port_number2 = strtok(NULL, "");
                printf("\n\rport_number2 value is %s\n",port_number2);
                strcpy(connection_server->ip,comapare2);
                strcpy(connection_server->port, port_number1);
                //printf("\n\rconnection_server value is %s\n",connection_server);
                connection_server++;
          }
          if (strncmp(temp4, "#server three", 13) == 0)
          {
                //When in server 3 matched
                printf("\n\rEntered the loop of server three\n");
                fgets(value_determined3, sizeof(value_determined3), fp);
                printf("\n\rvalue determined3: %s\n",value_determined3);
                temp33 = strtok(value_determined3, "\n\t");
                temp33 = strtok(value_determined3, "\n\t ");
                temp33 = strtok(NULL, "\n\t ");
                printf("\n\rtemp33: %s\n",temp33);
                comapare3 = strtok(NULL, "\n\t: ");
                printf("\n\rcomapre3: %s\n",comapare3);
                port_number3 = strtok(NULL, "");
                printf("\n\rport_number3 is %s\n",port_number3);
                strcpy(connection_server->ip,comapare3);
                strcpy(connection_server->port, port_number3);
                //printf("\n\rconnection_server is %s\n",connection_server);
                connection_server++;
          }
          if (strncmp(temp4, "#server four", 12) == 0)
          {
                printf("\n\rEntered the loop of server four\n");
                fgets(value_determined4, sizeof(value_determined4), fp);
                printf("\n\rvalue determined4: %s\n",value_determined4);
                temp44 = strtok(value_determined4, "\n\t");
                temp44 = strtok(value_determined4, "\n\t ");
                temp44 = strtok(NULL, "\n\t ");
                printf("\n\rtemp44 is %s\n",temp44);
                comapare4 = strtok(NULL, "\n\t: ");
                printf("\n\rcompare4 is %s\n",comapare4);
                port_number4 = strtok(NULL, "");
                printf("\n\rport_number3 is %s\n",port_number4);
                strcpy(connection_server->ip,comapare4);
                strcpy(connection_server->port, port_number4);
                //printf("\n\rconnection_server is %s\n",connection_server);
                connection_server++;
          }
          if (strncmp(temp4, "#username", 9) == 0)
          {
                //check for correct user name from the file give
                fgets(value_determined5, sizeof(value_determined5), fp);
                printf("\n\rvalue_determined5: %s\n",value_determined5);
                printf("\n\rTemp7 is %s\n",temp7);
                temp7 = strtok(value_determined5, "\n");
                printf("\n\rTemp7 is %s\n",temp7);
                temp7 = strtok(value_determined5, ":");
                printf("\n\rTemp7 is %s\n",temp7);
                temp7 = strtok(NULL, ": ");
                printf("\n\rTemp7 is %s\n",temp7);
                strcpy(cred->username,temp7);
                //printf("\n\rconnection_server is %s\n",connection_server);
              }
          if (strncmp(temp4, "#password", 9) == 0)
          {
                //Functioon for checking password from user and matching
                fgets(value_determined6, sizeof(value_determined6), fp);
                printf("\n\rvalue determined6 is %s\n",value_determined6);
                printf("\n\rTemp8 is %s\n",temp8);
                temp8 = strtok(value_determined6, "\n");
                printf("\n\rTemp8 is %s\n",temp8);
                temp8 = strtok(value_determined6, ":");
                printf("\n\rTemp8 is %s\n",temp8);
                temp8 = strtok(NULL, ": ");
                printf("\n\rTemp8 is %s\n",temp8);
                printf("\n\rtemp8 is %s\n",temp8);
                strcpy(cred->password,temp8);
                //printf("\n\rconnection_server is %s\n",connection_server);
            }
        }
  }
  fclose(fp);
}

result_pass_fail sendToDFS(int servernumber, char* partfile, int size, int _apart_sizenumber)
{

    bzero(dfs_in,sizeof(dfs_in));
    bzero(bytes_out_received,sizeof(bytes_out_received));
    sprintf(data_server, "%d", servernumber);
    printf("Sending to Server Number: %s\n", data_server);
    int bytes_in_server = send(sock_file[servernumber], data_server, sizeof(data_server), MSG_NOSIGNAL);
    if (bytes_in_server < 0)
    {
        //bytes in the server
        printf("\n\r Error is there\n");
    }
    sprintf(dfs_in, "%d", size);
//    printf("\n\rdfs_in is %s\n",dfs_in);
//    printf("\n\r bytes in server %s\n",bytes_in_server);
    bytes_in_server = send(sock_file[servernumber], dfs_in, sizeof(dfs_in), MSG_NOSIGNAL);
    if (bytes_in_server <= 0)
    {
        printf("\n\r Error is there\n");
    }

    sprintf(data_in, "%d", _apart_sizenumber);
    printf("data_in is%s\n", data_in);
    bytes_in_server = send(sock_file[servernumber], data_in, sizeof(data_in), MSG_NOSIGNAL);
    printf("\n\rno of bytes sent is %d\n",bytes_in_server);
    if (bytes_in_server < 0)
    {
        printf("\n\r Error is there\n");
    }
    char arr[size];
    bzero(arr,sizeof(arr));
    for (size_data = 0;size_data<size;size_data++)
    {
        printf("\n\r size of data for loop\n");
        arr[size_data] = partfile[size_data];
    }
    bytes_in_server = send(sock_file[servernumber], arr, size, MSG_NOSIGNAL);
    printf("no of bytes sent for file = %d\n", bytes_in_server);
    if (bytes_in_server < 0)
    {
        printf("\n\r Error is there\n");
    }
    bzero(bytes_out_received,sizeof(bytes_out_received));
    return SUCCESS;
}

int main(int argc, char* argv[])
{
    int k = 0;


    volatile int zero_server_working = 0;
    struct timeval time;

    printf("\n\rinside the main loop\n");
    /*
    bzero((char*)&server_addr,sizeof(server_addr));
bzero((char*)&client_addr, sizeof(client_addr));

server_addr.sin_family=AF_INET;
server_addr.sin_port=htons(atoi(argv[1]));
server_addr.sin_addr.s_addr=INADDR_ANY;


sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
if(sockfd<0)
error("Problem in initializing socket");

if(bind(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr))<0)
error("Error on binding");

listen(sockfd,50);
int client_len=sizeof(client_addr);

accepting:

newsockfd=accept(sockfd,(struct sockaddr*)&client_addr,&client_len);

if(newsockfd<0)
error("Problem in accepting connection");

pid=fork();
if(pid==0)*/
    if(argc < 2)
    {
        printf("\n\rif arg is less than 2\n");
				fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(0);
    }

    bzero(command,sizeof(command));
    bzero(bytes_out_received,sizeof(bytes_out_received));
    bzero(file,sizeof(file));
    bzero(inusername,sizeof(inusername));
    bzero(inpassword,sizeof(inpassword));
    bzero(md5_in_temp,sizeof(md5_in_temp));
    server_t connection_server[max];
    cred_t authenticate;
    if (argc == 2)
    {
        strncpy(conffile, "dfc.conf", sizeof("dfc.conf"));
        result_pass_fail ret = parseConfFile(&authenticate, connection_server, conffile);
    }
    else
    {
       printf("\n\rEntered in the else loop\n");
       result_pass_fail ret = parseConfFile(&authenticate, connection_server, argv[2]);
    }

    struct sockaddr_in server_address[max], client_address;
    struct hostent *server;

    while(1)
    {
        printf("\n\rEnter Username for authentication: \n");
        fgets(inusername, buffer_max, stdin);
        printf("\n\rEnter Password for authentication: \n");
        fgets(inpassword, buffer_max, stdin);
        if (strncmp(inusername, authenticate.username, strlen(authenticate.username)) == 0 && strncmp(inpassword, authenticate.password, strlen(authenticate.password)) == 0)
        {
          printf("\n\rPassword authentication done\n");
          printf("\n\rBelow options are there \nget [filename] [directory] \nput [filename] [directory] \nlist [directory] \nexit\n");
          bzero(command,sizeof(command));
          bzero(file,sizeof(file));
          bzero(folder_in_folder,sizeof(folder_in_folder));
          fgets(command, buffer_in, stdin);
          char* ptr_to_command = command;
          char* ptr_to_commands;
          int ret = parseCommand(ptr_to_command, file, folder_in_folder);
          // printf("Name of file is %s\n", file);
          //  printf("\n\r%s\n", folder_in_folder);
          strncpy(userfolder_in_folder, folder_in_folder, sizeof(folder_in_folder));
          //printf("User Sub Directory: %s\n", userfolder_in_folder);
          if (strncmp(command, "put", strlen("put")) != 0 && strncmp(command, "get", strlen("get")) != 0 && strncmp(command, "list", strlen("list")) != 0  && strncmp(command, "exit", strlen("exit")) != 0)
            {
              printf("\n\rError is there\n");
              continue;
            }
            //for loop for socket
            for (int i = 0; i< max; i++)
            {
              printf("\n\rEntered in the for loop\n");
              port_number = atoi(connection_server[i].port);
              if ((sock_file[i] = socket(AF_INET, SOCK_STREAM, 0)) == -1)
                {
                  printf("\n\rError is there\n");
                }
                server_address[i].sin_family = AF_INET;
                server = gethostbyname(argv[1]);
                if (server == NULL)
                {
                    //when server is not connected properly
                    printf("\n\r When there is no host present\n");
                    fprintf(stderr, "ERROR: No such host found\n");
                }

                bcopy((char*)server->h_addr, (char*)&server_address[i].sin_addr, server->h_length);
                server_address[i].sin_port = htons(port_number);
                if (connect(sock_file[i], (struct sockaddr *)&server_address[i], sizeof(server_address[i]))<0)
                {
                    printf("\n\rError is there\n");
                    servers_in_place[i] = 1;
                    zero_server_working++;
                }
                clientlength = sizeof(struct sockaddr_in);
                time.tv_sec = 10;
                time.tv_usec = 0;
                if(setsockopt(sock_file[i], SOL_SOCKET, SO_RCVTIMEO, (char *) &time, sizeof(time)) < 0)
                {
                  //setting socket time duration
                  printf("\n\rError is there\n");
                }
           }
              printf("No of Failed Server Connections: %d\n", zero_server_working);
              int acknowledgements = 0;
              for(int u = 0; u<max; u++)
              {
                if(servers_in_place[u] == 1)
                {
                    printf("There is no active servers: %d\n", u);
                    continue;
                }
               sending_bytes = send(sock_file[u], &authenticate, sizeof(authenticate), MSG_NOSIGNAL);
               if (sending_bytes < 0)
                  {
                    //sending bytes when smaller than 0
                    printf("\n\rError is there \n");
                  }
                int bytes_in = recv(sock_file[u], bytes_out_received, sizeof(bytes_out_received), 0);
                printf("%s\n", bytes_out_received);
                if (strncmp("no", bytes_out_received, 2) == 0)
                {
                    //no when strncmp is done correct
                    printf("\n\rError is there\n");
                    bzero(command,sizeof(command));
                }
                else if(strncmp("yes", bytes_out_received, 3) == 0)
                {
                    //yes when strncmp is compared
                    printf("\n\rPasswords and username are matched\n");
                    acknowledgements += 1;
                }
            }
                  if (acknowledgements == 4)
                {
                  //when ack is 4 for all the servers
                  printf("\n\r When all 4 servers are there\n");
                }
                  if (strcmp("put", command) == 0)
                {
                  FILE *fp;
                  fp = fopen(file,"rb"); //readidng file is here
                  if (fp == NULL)
                  {
                    //null pointer is there
                    printf("\n\rError is there\n");
                    continue;
                  }
                  else if (fp != NULL)
                  {
                    //when file pointer is not null
                    strcpy(folder_in_folder, ".");
                    char md5_saving[] = "md5sum";
                    sprintf(md5_saving, "md5sum %s >md5sumsave.txt", file);
                    printf("\n\rmd5sum saving %s\n", md5_saving);
                    system(md5_saving);
                    FILE *fptr = fopen("md5sumsave.txt", "r");
                    for( int  u = 0; u< max; u++)
                    {
                      if(servers_in_place[u] == 1)
                        //maximum value
                        {
                            printf("\n\r In the active server list\n");
                            continue;
                        }
                        sending_bytes = send(sock_file[u], command, sizeof(command), MSG_NOSIGNAL);
                        if (sending_bytes < 0)
                          {
                            printf("\n\rEnterd data is having errors\n");
                          }
                        if (fptr == NULL)
                        {
                            //file poinyer is NULL
                            printf("\n\r Error is there\n");
                            continue;
                        }
                        else
                        {
                            //sending bytes is data when data is send
                            sending_bytes = send(sock_file[u], file, sizeof(file), MSG_NOSIGNAL);
                            if (sending_bytes < 0)
                              {
                                printf("\n\r Error is there\n");
                              }
                            //snd data on the other endd
                            sending_bytes = send(sock_file[u], userfolder_in_folder, sizeof(userfolder_in_folder), MSG_NOSIGNAL);
                            if (sending_bytes < 0)
                              {
                                printf("\n\r Error is there\n");
                              }
                        }
                    }
                    bzero(userfolder_in_folder,sizeof(userfolder_in_folder));
                    fclose(fptr);
                    fptr=fopen("md5sumsave.txt", "r"); //reading the file
                    fgets(md5_in_temp, sizeof(md5_in_temp), fptr);
                    char md5sum[32], md5last, md5;
                    strncpy(md5sum, md5_in_temp, 32);
                    printf("\n\rmd5sum data is %s\n",md5sum);
                    md5last = md5sum[31];
                    printf("Last byte of md5sum is %c\n", md5last);
                    if(md5last == '0'|| md5last == '1'|| md5last == '2'|| md5last == '3'|| md5last == '4'|| md5last == '5'|| md5last == '6'|| md5last == '7'|| md5last == '8'|| md5last == '9' )
                    {
                      printf("\n\r When md5sum is in one of the numbers\n");
                      servernumber = atoi(&md5last);
                    }
                    else
                    {
                      printf("\n\rIn the else loop\n");
                      sprintf(&md5, "%x", md5last);
                      servernumber = atoi(&md5) - 51; //ascii conversion
                    }
                    servernumber %= 4;
                    fclose(fptr);
                    if ( (fp = fopen(file, "rb")) == NULL)
                    {
                        printf("Error is there\n");
                    }
                    else
                    {
                      printf("\n\rFile size determined loop\n");
                      int file_size1;
                      int num_bytes1;
                      fseek(fp, 0, SEEK_END);
                      file_size1 = ftell(fp);
                      fseek(fp,0,SEEK_SET);
                      num_bytes1 = file_size1;
                      printf("Number of bytes of file is %d \n",num_bytes1);
                      total_file_size = num_bytes1;
                      printf("Number of bytes of file is %d \n",total_file_size);
                      fclose(fp);
                      size_of_file_pieces = (total_file_size/4);
                      printf("Number of bytes of file is %d \n",total_file_size);
                      last_apart_sizesize = (total_file_size - (3*size_of_file_pieces));
                      printf("Number of bytes of file is %d \n",last_apart_sizesize);
                  }
                    char _apart_size[size_of_file_pieces];
                    char final_apart_size[last_apart_sizesize];
                    char first_file_apart[size_of_file_pieces];
                    char second_apart[size_of_file_pieces];
                    char third_apart[size_of_file_pieces];
                    char fourth_apart[last_apart_sizesize];
                    bzero(_apart_size,sizeof(_apart_size));
                    bzero(final_apart_size,sizeof(final_apart_size));
                    bzero(first_file_apart,sizeof(first_file_apart));
                    bzero(second_apart,sizeof(second_apart));
                    bzero(third_apart,sizeof(third_apart));
                    bzero(fourth_apart,sizeof(fourth_apart));
                    printf("file cracked %d\n", size_of_file_pieces);
                    printf("file cracked again last = %d\n", last_apart_sizesize);
                    if((fp = fopen(file, "rb")) != NULL)
                    {
                        //file is opened
                        for(int server = 0; server < max; server++)
                        {
                            printf("\n\rserver connection\n");
                            if(servers_in_place[server] == 1)
                            {
                                printf("\n\rBefore continuein \n");
                                continue;
                            }
                            first_apart = distributiontable[servernumber][server]/10;
                            //printf("\n\rFirst Apart %s\n",first_apart);
                            if(first_apart == 1)
                            {
                                fseek(fp, 0, SEEK_SET); //file rreached end
                                bzero(first_file_apart,sizeof(first_file_apart));
                                fread(first_file_apart, size_of_file_pieces, 1, fp);
                                rewind(fp); //file back to starting point
                                k = 0;
                                for (int o = 0; o<size_of_file_pieces; o++)
                                {
                                    //size of file pieces
                                    _apart_size[o] = first_file_apart[o] ^ authenticate.password[k];
                                    if ( k == (strlen(authenticate.password) - 1) )
                                    {
                                      printf("\n\rIf k is 0 and authentication is success \n\r");
                                      k = 0;
                                    }
                                    else
                                    {
                                      printf("\n\r Else k s value is incremetned\n");
                                      k++;
                                    }
                                }
                                result_pass_fail ret = sendToDFS(server, _apart_size, size_of_file_pieces, first_apart);
                                bzero(_apart_size,sizeof(_apart_size));
                                bzero(first_file_apart,sizeof(first_file_apart));
                            }
                            else if(first_apart == 2)
                            {
                                fseek(fp, size_of_file_pieces, SEEK_SET);
                                bzero(second_apart,sizeof(second_apart));
                                fread(second_apart, size_of_file_pieces, 1, fp);
                                rewind(fp);
                                k = 0;
                                for (int o = 0; o<size_of_file_pieces; o++)
                                {
                                    //strength length
                                    _apart_size[o] = second_apart[o] ^ authenticate.password[k];
                                    if ( k == (strlen(authenticate.password) - 1) )
                                    {
                                      printf("\n\rIf k is 0 and authentication is success \n\r");
                                      k = 0;
                                    }
                                    else
                                    {
                                      printf("\n\r Else k s value is incremetned\n");
                                      k++;
                                    }
                                }
                                result_pass_fail ret = sendToDFS(server, _apart_size, size_of_file_pieces, first_apart);
                                bzero(_apart_size,sizeof(_apart_size));
                                bzero(second_apart,sizeof(second_apart));
                            }
                            else if(first_apart == 3)
                            {
                                fseek(fp,2*size_of_file_pieces,SEEK_SET); //file reached end
                                bzero(third_apart,sizeof(third_apart));
                                fread(third_apart, size_of_file_pieces, 1, fp);
                                rewind(fp); //file reached starting popoint
                                k = 0;
                                for (int o = 0; o<size_of_file_pieces; o++)
                                {
                                  //password authentication
                                  _apart_size[o] = third_apart[o] ^ authenticate.password[k];
                                  if ( k == (strlen(authenticate.password) - 1) )
                                    {
                                      printf("\n\rIf k is 0 and authentication is success \n\r");
                                      k = 0;
                                    }
                                    else
                                    {
                                      printf("\n\r Else k s value is incremetned\n");
                                      k++;
                                    }
                                }
                                result_pass_fail ret = sendToDFS(server, _apart_size, size_of_file_pieces, first_apart);
                                bzero(_apart_size,sizeof(_apart_size));
                                bzero(third_apart,sizeof(third_apart));

                            }
                            else if(first_apart == 4)
                            {
                                fseek(fp, 3*size_of_file_pieces, SEEK_SET);
                                //printf("\n\r file pointer value %s\n",fp);
                                bzero(fourth_apart,sizeof(fourth_apart));
                                fread(fourth_apart,last_apart_sizesize, 1, fp);
                                rewind(fp); //back to starting point
                                k = 0;
                                bzero(final_apart_size,sizeof(final_apart_size));
                                for (int o = 0; o<last_apart_sizesize; o++)
                                {
                                    final_apart_size[o] = (fourth_apart[o] ^ authenticate.password[k]);
                                    if (k == (strlen(authenticate.password) - 1) )
                                    {
                                      printf("\n\rIf k is 0 and authentication is success \n\r");
                                      k = 0;
                                    }
                                    else
                                    {
                                      printf("\n\r Else k s value is incremetned\n");
                                      k++;
                                    }
                                }
                                result_pass_fail ret = sendToDFS(server, final_apart_size, last_apart_sizesize, first_apart);
                                bzero(final_apart_size,sizeof(final_apart_size));
                                bzero(fourth_apart,sizeof(fourth_apart));
                            }

                            _apart_sizetwo = distributiontable[servernumber][server]%10;

                            if(_apart_sizetwo == 1)
                            {
                                fseek(fp, 0, SEEK_SET);
                                bzero(first_file_apart,sizeof(first_file_apart));
                                fread(first_file_apart, size_of_file_pieces, 1, fp);
                                rewind(fp);
                                k = 0;
                                for (int o = 0; o<size_of_file_pieces; o++)
                                {
                                    _apart_size[o] = first_file_apart[o] ^ authenticate.password[k];
                                    if ( k == (strlen(authenticate.password) - 1) )
                                    {
                                      printf("\n\rIf k is 0 and authentication is success \n\r");
                                      k = 0;
                                    }
                                    else
                                    {
                                      printf("\n\r Else k s value is incremetned\n");
                                      k++;
                                    }
                                }
                                result_pass_fail ret = sendToDFS(server, _apart_size, size_of_file_pieces, _apart_sizetwo);
                                bzero(_apart_size,sizeof(_apart_size));
                                bzero(first_file_apart,sizeof(first_file_apart));
                            }
                            else if(_apart_sizetwo == 2)
                            {
                                fseek(fp, size_of_file_pieces, SEEK_SET);
                                bzero(second_apart,sizeof(second_apart));
                                fread(second_apart, size_of_file_pieces, 1, fp);
                                rewind(fp);
                                k = 0;
                                for (int o = 0; o<size_of_file_pieces; o++)
                                {
                                    _apart_size[o] = second_apart[o] ^ authenticate.password[k];
                                    if ( k == (strlen(authenticate.password) - 1) )
                                    {
                                        printf("\n\rIf k is 0 and authentication is success \n\r");
                                        k = 0;
                                    }
                                    else
                                    {
                                        printf("\n\r Else k s value is incremetned\n");
                                        k++;
                                    }
                                }
                                result_pass_fail ret = sendToDFS(server, _apart_size, size_of_file_pieces, _apart_sizetwo);
                                bzero(_apart_size,sizeof(_apart_size));
                                bzero(second_apart,sizeof(second_apart));
                            }
                            else if(_apart_sizetwo == 3)
                            {
                                fseek(fp, 2*size_of_file_pieces, SEEK_SET);
                                bzero(third_apart,sizeof(third_apart));
                                fread(third_apart, size_of_file_pieces, 1, fp);
                                k = 0;
                                for (int o = 0; o<size_of_file_pieces; o++)
                                {
                                  _apart_size[o] = third_apart[o] ^ authenticate.password[k];
                                  if ( k == (strlen(authenticate.password) - 1) )
                                    {
                                      printf("\n\rIf k is 0 and authentication is success \n\r");
                                      k = 0;
                                    }
                                    else
                                    {
                                      printf("\n\r Else k s value is incremetned\n");
                                      k++;
                                    }
                                }
                                result_pass_fail ret = sendToDFS(server, _apart_size, size_of_file_pieces, _apart_sizetwo);
                                bzero(_apart_size,sizeof(_apart_size));
                                bzero(third_apart,sizeof(third_apart));
                            }
                            else if(_apart_sizetwo == 4)
                            {
                                fseek(fp, 3*size_of_file_pieces, SEEK_SET);
                                bzero(fourth_apart,sizeof(fourth_apart));
                                fread(fourth_apart, last_apart_sizesize, 1, fp);
                                rewind(fp);
                                k = 0;
                                bzero(final_apart_size,sizeof(final_apart_size));
                                for (int o = 0; o<last_apart_sizesize; o++)
                                {
                                  final_apart_size[o] = (fourth_apart[o] ^ authenticate.password[k]);
                                  if ( k == (strlen(authenticate.password) - 1) )
                                    {
                                      printf("\n\rIf k is 0 and authentication is success \n\r");
                                      k = 0;
                                    }
                                    else
                                    {
                                      printf("\n\r Else k s value is incremetned\n");
                                        k++;
                                    }
                                }
                                result_pass_fail ret = sendToDFS(server, final_apart_size, last_apart_sizesize, _apart_sizetwo);
                                bzero(final_apart_size,sizeof(final_apart_size));
                                bzero(fourth_apart,sizeof(fourth_apart));
                            }
                            bzero(_apart_size,sizeof(_apart_size));
                            bzero(final_apart_size,sizeof(final_apart_size));
                        }
                        fclose(fp);
                        bzero(file,sizeof(file));
                    }
                    else
                    {
                        printf("Error is there\n");
                        continue;
                    }

                }
            }


            else if (strcmp("get", command) == 0)
             {
							 	printf("\n\rInside the get loop\n\r");
                strncat(newfile, file, strlen(file));
                bzero(second_apart,sizeof(second_apart));
								bzero(first_file_apart,sizeof(first_file_apart));
								bzero(fourth_apart,sizeof(fourth_apart));
								bzero(third_apart,sizeof(third_apart));
				        for( int  u = 0; u< max; u++)
                {
										printf("\n\rInside the maxfor loop\n");
                    if(servers_in_place[u] == 1)
                      {
												printf("\n\rServers are in place\n\r");
                        continue;
                      }
                    sending_bytes = send(sock_file[u], command, sizeof(command), MSG_NOSIGNAL);
                    if (sending_bytes < 0)
                      {
                      	printf("\n\r Error is there\n");
                      }
                    sending_bytes = send(sock_file[u],file,sizeof(file), 0);
                    if (sending_bytes < 0)
                      {
											  printf("\n\r Error is there\n");
					            }
                    sending_bytes = send(sock_file[u], userfolder_in_folder, sizeof(userfolder_in_folder), MSG_NOSIGNAL);
                    if (sending_bytes < 0)
                      {
                        printf("\n\rError is there\n");
                      }
                    char data_server[5];
                    sprintf(data_server, "%d", u);
										printf("%s\n", data_server);
                    int bytes_in_server = send(sock_file[u], data_server, sizeof(data_server), MSG_NOSIGNAL);
                    if (bytes_in_server < 0)
                    {
                      printf("\n\rError is there\n");
                    }
                    int loops = 0;
                    char _apart_sizenumber[5];
                    char _apart_sizesize[5];
                    while(loops < 2)
                    {
											printf("\n\rif the loop is less than 2\n");
                      bzero(_apart_sizenumber,sizeof(_apart_sizenumber));
                      int bytes_in = recv(sock_file[u], _apart_sizenumber, sizeof(_apart_sizenumber), 0);
                      int _apart_sizenu = atoi(_apart_sizenumber);
                      if (_apart_sizenu > 0 && listof_apart_sizes[_apart_sizenu-1] ==  0)
                        {
                          bytes_in_server = send(sock_file[u], allow, 3, 0);
                          if(bytes_in_server<0)
                            {
                            	printf("\n\rError is there\n");
                            }
                        }
                        else if(_apart_sizenu == 0 || (_apart_sizenu>0 && listof_apart_sizes[_apart_sizenu-1] !=  0))
                        {
                          bytes_in_server = send(sock_file[u], stop, 2, 0);
                          if (bytes_in_server<0)
                          {
														printf("\n\rError is there\n");
                          }
                          loops++;
                          break;
                        }
                        if(_apart_sizenu == 1)
                        {
													printf("\n\rif apart size is 1\n");
                          if(listof_apart_sizes[_apart_sizenu-1]<2)
                            {
															printf("\n\r list of apart sizes\n");
                              listof_apart_sizes[_apart_sizenu-1]++;
                            }
                        }
                        else if(_apart_sizenu == 2)
                        {
													printf("\n\rIf the apart size is equal to 2\n");
                          if(listof_apart_sizes[_apart_sizenu-1]<2)
                            {
															printf("\n\r if the list of size is smaller than 2\n");
                              listof_apart_sizes[_apart_sizenu-1]++;
                            }
                        }
                        else if(_apart_sizenu == 3)
                        {
													printf("\n\rapart size is equal to 3\n");
                          if(listof_apart_sizes[_apart_sizenu-1]<2)
                          {
														printf("\n\rapart lsize is less than 2\n\r");
                            listof_apart_sizes[_apart_sizenu-1]++;
                          }
                        }
                        else if(_apart_sizenu == 4)
											  {
														printf("\n\rapart size is 4\n");
                            if(listof_apart_sizes[_apart_sizenu-1]<2)
                            {
																printf("\n\r apart size is less than 2\n");
                                listof_apart_sizes[_apart_sizenu-1]++;
                            }
                        }

                        uint8_t write_apart_size = 0;
                        int k = 0;
                        if (_apart_sizenu > 0 && listof_apart_sizes[_apart_sizenu-1] == 1)
                        {
                            bzero(_apart_sizesize,sizeof(_apart_sizesize));
                            bytes_in = recv(sock_file[u], _apart_sizesize, sizeof(_apart_sizesize), 0);
                            int _apart_sizesi = atoi(_apart_sizesize);
                            char data_received[_apart_sizesi];
                            bzero(data_received,_apart_sizesi);
                            bytes_in = recv(sock_file[u], data_received, _apart_sizesi, 0);
                            if (_apart_sizenu == 1)
                            {
															printf("\n\r when size is 1 of file\n\r");
                              if (_apart_sizenu > 0 && data_to_file[_apart_sizenu-1] == 0)
                                {
                                  printf("\n\rFirst part copied from the data\n");
                                  setsize = _apart_sizesi;
                                  k = 0;
                                  for (int o = 0; o < _apart_sizesi; o++)
                                  {
																		printf("\n\rinside the for loop\n");
                                    first_file_apart[o] = data_received[o] ^ authenticate.password[k];
                                    if ( k == (strlen(authenticate.password) - 1) )
                                    {
																			printf("\n\rwhen k is 0\n");
                                      k = 0;
                                    }
                                    else
                                    {
																			printf("\n\rincrement k value\n");
                                      k++;
                                    }
                                    }
                                     bzero(data_received,sizeof(data_received));
                                     data_to_file[_apart_sizenu-1] = 1;
                                 }
                            }
                            if (_apart_sizenu == 2)
                            {
																printf("\n\rapart size is 2 loop\n");
                                if(_apart_sizenu>0 && data_to_file[_apart_sizenu-1] == 0)
                                {
                                    printf("in second part wiringt file\n");
                                    k = 0;
                                    for (int o = 0; o < _apart_sizesi; o++)
                                    {
																		  printf("\n\raoart size is less than max loop\n\r");
                                      second_apart[o] = data_received[o] ^ authenticate.password[k];
                                      if ( k == (strlen(authenticate.password) - 1) )
                                      {
																				printf("\n\r when k is 0\n");
                                        k = 0;
                                      }
                                        else
                                        {
																					printf("\n\r when k increments\n\r");
                                          k++;
                                        }
                                    }
                                    bzero(data_received,sizeof(data_received));
                                    data_to_file[_apart_sizenu-1] = 1;
                                  }
                            }
                            if (_apart_sizenu == 3)
                            {
															printf("\n\r apart file is 3 mentioned\n");
                              if (_apart_sizenu > 0 && data_to_file[_apart_sizenu-1] == 0)
                                {
                                  printf("in third part wiringt file\n");
                                  k = 0;
                                  for (int o = 0; o < _apart_sizesi; o++)
                                  {
                                    third_apart[o] = data_received[o] ^ authenticate.password[k];
                                    if ( k == (strlen(authenticate.password) - 1) )
                                    {
																			printf("\n\r when k is 0\n");
                                      k = 0;
                                    }
                                    else
                                      {
																				printf("\n\r when k increments\n\r");
                                        k++;
                                        }
                                    }
                                    data_to_file[_apart_sizenu-1] = 1;
                                    bzero(data_received,sizeof(data_received));
                                }
                            }
                            if (_apart_sizenu == 4)
                            {
																printf("\n\r when size of file is 4\n");
                                if(_apart_sizenu>0 && data_to_file[_apart_sizenu-1] == 0)
                                {
                                    printf("in fourth part wiringt file\n");
                                    lastsize = _apart_sizesi;
                                    k = 0;
                                    for (int o = 0; o < lastsize; o++)
                                    {
																				printf("\n\r in loop till last size is determined\n\r");
                                        fourth_apart[o] = data_received[o] ^ authenticate.password[k];
                                        if ( k == (strlen(authenticate.password) - 1) )
                                        {
																						printf("\n\r when k is 0\n\r");
                                            k = 0;
                                        }
                                        else
                                        {
																						printf("\n\r when k increments\n");
                                            k++;
                                        }
                                    }

                                    bzero(data_received,sizeof(data_received));
                                    data_to_file[_apart_sizenu-1] = 1;
                                }
                            }
                            bzero(data_received,sizeof(data_received));
                        }

                        bzero(_apart_sizenumber, sizeof(_apart_sizenumber));
                        bzero(_apart_sizesize, sizeof(_apart_sizesize));

                        loops++;
                    }
                }
                int zerocount = 0;
                int onecount = 0;
                for(int i = 0; i<4; i++)
                {
										printf("\n\rapart size less than 4\n\r");
                    if(listof_apart_sizes[i] == 0)
                    {
												printf("\n\r zero counting adding\n");
                        zerocount++;
                    }
                    else if (listof_apart_sizes[i] == 1 && data_to_file[i] == 1)
                    {
												printf("\n\raparting addition\n");
                        onecount++;
                    }
                    printf("_apart_size N0: %d Count:%d\n", (i+1), listof_apart_sizes[i]);
                }
                if(zerocount == 4)
                {
                  printf("\n\r error is there\n\r");
                }
                if(onecount == 4)
                {
                    FILE* fp = fopen(newfile, "wb+");
                    fwrite(first_file_apart, 1, setsize, fp);
                    fwrite(second_apart, 1, setsize, fp);
                    fwrite(third_apart, 1, setsize, fp);
                    fwrite(fourth_apart, 1, lastsize, fp);
                    fclose(fp);
                    printf("File Complete\n");
                }
                else
                {
                    printf("\n\rFile Incomplete.\n");
                }
                bzero(file,sizeof(file));
								printf("\n\rfile is made zero %s",file);
                bzero(first_file_apart,sizeof(first_file_apart));
								printf("\n\rfirst file apart is made zero %s",first_file_apart);
                bzero(second_apart,sizeof(second_apart));
								printf("\n\rsecond file apart %s",second_apart);
                bzero(third_apart,sizeof(third_apart));
								printf("\n\rthird file apart is made zero %s",third_apart);
                bzero(fourth_apart,sizeof(fourth_apart));
								printf("\n\rfourth file apart is made zero %s",fourth_apart);
						}

            else if (strcmp(command, "list") == 0)
            {
                FILE *fp = fopen("tempfilelist.txt", "w");
                printf("\n\rlist\n");
                printf("\n\r%s\n", file);
                for( int  u = 0; u< max; u++)
                {
										printf("\n\rwhen max value is less\n");
									  if(servers_in_place[u] == 1)
                    {
												printf("\n\rbefore continuing\n");
                        continue;
                    }
                    sending_bytes = send(sock_file[u], command, sizeof(command), MSG_NOSIGNAL);
                    if (sending_bytes < 0)
                      {
                        printf("\n\rError is there\n");
                      }
                    char data_server[5];
                    bzero(data_server,sizeof(data_server));
                    sprintf(data_server, "%d", u);
                    printf("data server%s\n", data_server);
                    int bytes_in_server = send(sock_file[u], data_server, sizeof(data_server), MSG_NOSIGNAL);
                    if (bytes_in_server < 0)
                    {
                       printf("\n\rError is there\n");
                    }
                    sending_bytes = send(sock_file[u], file, sizeof(file), MSG_NOSIGNAL);
                    if (sending_bytes < 0)
                      {
                        printf("\n\rError is there\n");
                      }
                    char rec[3];
                    bzero(rec,sizeof(rec));
                    int bytes_in = recv(sock_file[u], rec, 3, 0);
                    if (strncmp("no", rec, 2) == 0)
                    {
                        printf("\n\rError wrong directory\n");
                        continue;
                    }

                    else if(strncmp("yes", rec, 3) == 0)
                    {
                        printf("\n\rGetting into the file\n");
                        char filesize[5];
                        bzero(filesize,sizeof(filesize));
                        bytes_in = recv(sock_file[u], filesize, sizeof(filesize), 0);
                        int size = atoi(filesize);
                        printf("file size received %d in total bytes %d\n", size, bytes_in);
                        int recbytes = 0;
                        int temp2 = 0;
                        int remainingbytes = size;
                        while(remainingbytes)
                        {
														printf("\n\rwhen remainig bytes are sent\n");
                            bzero(store_data,sizeof(store_data));
                            recbytes = recv(sock_file[u], store_data, 1, 0);
                            remainingbytes -= recbytes;
                            store_file_buffer[u][temp2] = store_data[0];
                            temp2++;
                        }
                        printf("File received\n");
                        fwrite(store_file_buffer[u], 1, strlen(store_file_buffer[u]), fp);
                    }

                }

                char endfile[] = "\n..zzz.zzz.z";
                fwrite(endfile,1,sizeof(endfile), fp);
                fclose(fp);
                bzero(store_data,sizeof(store_data));
                strcpy(cli, "sort tempfilelist.txt | uniq > finalfilelist.txt");
                system(cli);
                bzero(cli,sizeof(cli));
              //  strcpy(cli, "rm tempfilelist");
              //  system(cli);
                fp = fopen("finalfilelist.txt", "r"); //file is opened
                char onefile[200];
                bzero(onefile,sizeof(onefile));
                int a = 0;
                int b = 0;
                int loops = 0;
                printf("List of files in directory %s:\n", file);
                while(!feof(fp))
                {
										printf("\n\rfeof while loop entered\n");
                    loops++; //When loop is incremented
                    char section[200];
                    bzero(store_data,sizeof(store_data));
                    bzero(section,sizeof(section));
                    bzero(onefile,sizeof(onefile));
                    fgets(store_data,sizeof(store_data), fp);
                    strcpy(section, store_data);
                    printf("\n\r section data is %s \n",section);
                    if (strlen(section) > 2 )
                    {
                        printf("\n\r raj lavingia\n");
                        char storetoken[50];
                        char *temptoken = strtok((char*)&section[1], ".");
                        strcpy(storetoken, section);
                      //  printf("\n\r store token is  %s\n",storetoken);
                        temptoken = strtok(NULL, ".");
                        //printf("\n\r temp token is %s\n",temptoken);
                        if ((strncmp(temptoken, "1", 1) != 0) && (strncmp(temptoken, "2", 1) != 0) && (strncmp(temptoken, "3", 1) != 0) && (strncmp(temptoken, "4", 1) != 0) )
                        {
														printf("\n\rTem token\n");
                            strcat(storetoken, ".");
                            strcat(storetoken, temptoken);
                        }
                        sprintf(onefile, "%s", storetoken);
                      	if ( b == 0)
                        {
														printf("\n\r when b is 0\n");
                            bzero(store_file_buffer[b],sizeof(store_file_buffer[b]));
                            strncpy(store_file_buffer[b], onefile, strlen(onefile));
                            b++;
														printf("\n\rnow b is incremented\n");
                        }
                        else if(strncmp(onefile, store_file_buffer[b-1], strlen(onefile)) == 0)
                        {
                            a++;
                            if ( a== 3)
                            {
																printf("\n\r when a is 3 loop\n");
                                printf("\n%s: Complete loop \n", store_file_buffer[b-1]);
                                a = 0;
																printf("\n\ra is 0 back\n");
                            }
                        }
                        else
                        {
                            if(a!=0)
                            {
																printf("\n\rwhen a is not equal to 0\n");
                                printf("\n%s: Not complete\n", store_file_buffer[b-1]);
                            }
                            bzero(store_file_buffer[b],sizeof(store_file_buffer[b]));
                            strncpy(store_file_buffer[b], onefile, strlen(onefile));
                            b++;
														printf("\n\r b is incremented\n");
                            a = 0;
                        }
                    }
                }
                fclose(fp);
                bzero(cli,sizeof(cli));
              //  strcpy(cli, "rm finalfilelist");
            //    system(cli);
            }
            else if (strcmp(command, "exit") == 0)
            {
                //in the exit loop
							  for( int  u = 0; u< max; u++)
                {
                    // before less than max
										printf("\n\rmax value increased\n");
									  if(servers_in_place[u] == 1)
                    {
												printf("\n\r servers which are prpper\n\r");
                        continue;
                    }
                  	sending_bytes = send(sock_file[u], command, sizeof(command), MSG_NOSIGNAL);
                    if (sending_bytes < 0)
                      {
                        printf("\n\rError is there\n");
                      }
                    printf("connection to Server is closed: %d\n",u+1);
                    close(sock_file[u]);
                    if (temperory>0)
                    {
                      printf("Closed Client Socket\n");
                    }
                }
                exit(1);
            }

        }
        else
        {
            printf("\n\rError is there.\n");
             continue;
        }
    }
    return 0;
}
