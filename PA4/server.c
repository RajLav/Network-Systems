/*Name :- Raj Lavingia
PA-4
Distributed File System
Credits :- Professor Sangtae Ha
*/
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


#define buffer_value 512
#define in_buffer_value 500
#define out_buffer_value 500
#define max1 4
#define BUFFER_SIZE1 512
#define buffer_in1 500
#define buffer_max1 500
#define timing_connection1 10
#define buffer_in_max1 512
#define buffer_out_temp1 512
#define maximum_value_buffer1 1024
int tempraj = 0;
int bytes_transfer = 0;
int total_child = 0;
int child;
int increase = 0;
int increase1 = 0;
int increase2 = 0;
int increase3 = 0;
int increase10 = 0;
char parsing_data[315];
char allow[3] = "yes";
char stop[2]= "no";
char sizeoffile[5];
char subdirectory[10];
char my_server_produced[5];
char cross_data_input[5];
int soc_file_pointer;
int portno;
int clientlength;
int temp99;
int newsockfd;
struct sockaddr_in server_address, client_address;
char dfs_subdirectory[500];
char dfsusernamefoldername[500];
char dfsusernamesubdirectoryfoldername[500];
char file[out_buffer_value];
char command[in_buffer_value];
char username[out_buffer_value];
char password[out_buffer_value];
//eroor function defined
void error(char* error_message)
{
	//inside the loop
	printf("\n\rError is there\n");
}
//authentication function
typedef enum result_pass
{
	SUCCESS = 0,
	FAILURE,
} result_pass_fail;
//checking username and password with the provided in the file
typedef struct authentication{
	char username[10];
   char password[10];
} cred_t;
//ip and port number matched a
typedef struct server{
    char ip[20];
    char port[6];
} server_t;

/*int number_of_lines(FILE *fp)
{
  fp = fopen("dfs.conf", "r");
  if (fp == NULL)
  {
    printf("\n\rinside null pointer\n");
    return 0;
  }
	printf("\n\rReached Here\n\r");
  char here[2];
  int no_lines = 0;
  while(fgets(here, 2, fp))
  {
		printf("\n\rInside the while loop\n");
    if (here[0] == '\n')
    {
			printf("\n\rhere is 0\n");
      no_lines++;
    }
  }
    fclose(fp);
    return no_lines;
}*/

int filecheck(const struct direct *entry)
{
	if(strcmp(entry->d_name, "..") == 0 || strcmp(entry->d_name, ".") == 0)
	{
		printf("\n\rreturn 0 will be done \n");
		return 0;
	}
	else
	{
		printf("\n\rReturn1 will be done\n\r");
		return 1;
	}
}
char here[2];
int no_lines = 0;
result_pass_fail data_submitting(cred_t authorize[10], char file[])
{
	FILE *fp1;
  FILE *fp = fopen(file,"r");
  if(fp==NULL)
  {
    printf("\n\rError is there\n");
  }
  else
  {
    printf("\n\rin the else loop\n");
    char* data_going_in;

{
		fp1 = fopen("dfs.conf", "r");
	  if (fp1 == NULL)
	  {
	    printf("\n\rinside null pointer\n");
	    return 0;
	  }
		printf("\n\rReached Here\n\r");

	  while(fgets(here, 2, fp1))
	  {
			printf("\n\rInside the while loop\n");
	    if (here[0] == '\n')
	    {
				printf("\n\rhere is 0\n");
	      no_lines++;
	    }
	  }
	    fclose(fp1);
}
		printf("\n\r no_lines is %d \n",no_lines);
    int lines = no_lines;
		printf("\n\r Number of lines are %d \n",lines);
    int it = 0;
    while(it < lines)
	{
		//inside the while loop
    while(fgets(parsing_data, sizeof(parsing_data), fp))
    {
			printf("\n\r inside the while loop\n");
      data_going_in = strtok(parsing_data, "\n");
			printf("\n\r data going in is 1%s\n",data_going_in);
			data_going_in = strtok(parsing_data, "\n ");
			printf("\n\r data going in is 2%s\n",data_going_in);
      strcpy(authorize[it].username, data_going_in);
			data_going_in = strtok(NULL, "\n ");
			printf("\n\r data going in is 3%s\n",data_going_in);
      strcpy(authorize[it].password, data_going_in);
      it++;
    }
	}
}
  fclose(fp);
  return 1;
}


//Main loop started
int main(int argc, char* argv[])
{
	char first_server[520];
	char second_server[520];
	cred_t authorized[10];
	cred_t received;
	bzero(file,sizeof(file));
	bzero(command,sizeof(command));
	bzero(username,sizeof(username));
	bzero(password,sizeof(password));
	//checking the argument
	if (argc<2)
	{
		printf("\n\rwhen arg is less than 2\n");
		fprintf(stderr, "ERROR: No Port Provided\n");
		exit(1);
	}

	soc_file_pointer = socket(AF_INET, SOCK_STREAM, 0);
	if (soc_file_pointer < 0)
	{
		//checking for the file pointer
		printf("\n\rwhen file descripter is less than 0\n");
		fprintf(stderr, "ERROR: Socket Creation Error\n");
	}

	bzero((char*) &server_address, sizeof(server_address));
	portno = atoi(argv[1]);

	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(portno);
	server_address.sin_addr.s_addr = INADDR_ANY;
	//check if binding is done properly
	if(bind(soc_file_pointer, (struct sockaddr*)&server_address, sizeof(server_address)) < 0)
	{
		printf("\n\r binding failed\n\r");
		fprintf(stderr, "\n\rERROR: Binding Error Occurred\n");
	}
	//maximum number of listeners
	listen(soc_file_pointer, 5);
	clientlength = sizeof(client_address);
  result_pass_fail ret = data_submitting(authorized, "dfs.conf");
	for (int it = 0; it< 4; it++)
	{
		//it should be less than 4 so total 4
		printf(" Username:%s\n", authorized[it].username);
   	printf(" Password:%s\n", authorized[it].password);
	}
  int it = 20;
	while(1)
	{
		printf("\n\r inside the while loop\n");
		newsockfd = accept(soc_file_pointer, (struct sockaddr *) &client_address, &clientlength);
		if(newsockfd < 0)
		{
			printf("\n\rError is there\n");
			exit(1);
		}
		else
		{
			//forking is done
			child = fork();
			if (child == 0)
			{
				//choild loop
				printf("\n\r when child is present\n");
				total_child++; //increment of child
				printf("Child is created %d\n", total_child);
				close(soc_file_pointer);
				int bytes_data_in = recv(newsockfd, &received, sizeof(cred_t), 0);
     		if (bytes_data_in < 0)
   			{
					//it should be greater than 0
					printf("\n\r Error is there\n");
   			}
      		for (it = 0; it < 4; it++)
				{
					//less than 4
					printf("\n\r for all the loops\n\r");
					if (strcmp(received.username, authorized[it].username) == 0)
					{
						printf("\n\rwhen Username Found\n");
						tempraj = 10;
						break;
					}
				}
				if (tempraj == 10)
				{
					//when value is set for 10 as a delay
					if (strcmp(received.password, authorized[it].password) == 0)
					{
						//check if password and username are corecr
						printf("When authentication occurs\n");
						bytes_transfer = send(newsockfd, allow, sizeof(allow), 0);
						if (bytes_transfer<0)
						{
							//check if the bytes is less than 0
							printf("\n\rError is there\n");
						}
						bytes_data_in = recv(newsockfd, command, sizeof(command), 0);
						if (bytes_data_in<0)
						{
							//check if the bytes is less than 0
							printf("\n\rError is there\n");
						}
						printf("%s\n", command);
						//for put function data from client to server
						if (strcmp(command, "put") == 0)
						{
							//inside the loop put
							bzero(first_server,sizeof(first_server));
							bzero(second_server,sizeof(second_server));
							bytes_data_in = recv(newsockfd, file, sizeof(command), 0);
							if (bytes_data_in<0)
							{
								//check for error
								printf("\n\rError is there\n");
							}
							printf("\n\rWhen the file is there%s\n", file);
							bytes_data_in = recv(newsockfd, subdirectory, sizeof(subdirectory), 0);
							if (bytes_data_in<=0)
							{
								//check//check if the bytes is less than 0
								printf("\n\rError is there\n");
							}
							printf("\n\r%s\n", subdirectory);
							bytes_data_in = recv(newsockfd, my_server_produced, sizeof(my_server_produced), 0);
							if (bytes_data_in<=0)
							{
								//check if the bytes is less than 0
								printf("\n\rError is there\n");
							}

							int server_space = atoi(my_server_produced);
							printf("in first part %d\n", server_space);

							if (server_space == 0)
							{
								//when server is 0
								printf("\n\rwhen serve is 0\n");
								strncpy(dfs_subdirectory, "DFS1", sizeof("DFS1"));
								printf("\n\r dfs_subdirectory is %s\n",dfs_subdirectory);
							}
							else if (server_space == 1)
							{
								printf("\n\rwhen serve is 1\n");
								strncpy(dfs_subdirectory, "DFS2", sizeof("DFS2"));
								printf("\n\r dfs_subdirectory is %s\n",dfs_subdirectory);
							}
							else if (server_space == 2)
							{
								printf("\n\rwhen serve is 2\n");
								strncpy(dfs_subdirectory, "DFS3", sizeof("DFS3"));
								printf("\n\r dfs_subdirectory is %s\n",dfs_subdirectory);
							}
							else if (server_space == 3)
							{
								printf("\n\rwhen serve is 3\n");
								strncpy(dfs_subdirectory, "DFS4", sizeof("DFS4"));
								printf("\n\r dfs_subdirectory is %s\n",dfs_subdirectory);
							}
							char directory_formation[150] = "mkdir -p ";
							strcat(directory_formation, dfs_subdirectory);
							printf("\n\r directory_formation is %s\n",directory_formation);
							system(directory_formation);
							bzero(directory_formation,sizeof(directory_formation));
							strcat(dfs_subdirectory, "/");
							printf("\n\r dfs_sub is %s\n",dfs_subdirectory);
							//printf("\n\rdfs_subdirectory is %s",dfs_subdirectory);
							strncpy(dfsusernamefoldername, dfs_subdirectory, sizeof(dfs_subdirectory));
							printf("\n\r dfs_subdirectory is %s\n",dfsusernamefoldername);
							strcat(dfsusernamefoldername, received.username);
							printf("\n\r dfs_subdirectory is %s\n",dfsusernamefoldername);
							strncpy(directory_formation, "mkdir -p ", sizeof("mkdir -p "));
							printf("\n\r dfs_subdirectory is %s\n",directory_formation);
							//printf("\n\rdirectory formation is %s\n\r",directory_formation);

							strcat(directory_formation, dfsusernamefoldername);
							printf("\n\r dfs_subdirectory is %s\n",directory_formation);
							system(directory_formation);
							bzero(directory_formation,sizeof(directory_formation));
							printf("\n\r dfs_subdirectory is %s\n",directory_formation);
							strncpy(dfsusernamesubdirectoryfoldername, dfsusernamefoldername, sizeof(dfsusernamefoldername));
							strcat(dfsusernamesubdirectoryfoldername, "/");
							printf("\n\r dfs_subdirectory is %s\n",dfsusernamefoldername);
							//printf("\n\rdfs %s\n",dfsusernamesubdirectoryfoldername);
							strcat(dfsusernamesubdirectoryfoldername, subdirectory);
							strncpy(directory_formation, "mkdir -p ", sizeof("mkdir -p "));
							strcat(directory_formation, dfsusernamesubdirectoryfoldername);
							system(directory_formation);
							printf("\n\rdirecory forming %s\n",directory_formation);
							bzero(directory_formation,sizeof(directory_formation));
							printf("subdirectory: %s\n", dfsusernamesubdirectoryfoldername);
							strncpy(first_server, dfsusernamesubdirectoryfoldername, sizeof(dfsusernamesubdirectoryfoldername));
							strncpy(second_server, dfsusernamesubdirectoryfoldername, sizeof(dfsusernamesubdirectoryfoldername));
							printf("\n\rsecondserver data is %s\n",second_server);


							bytes_data_in = recv(newsockfd, cross_data_input, sizeof(cross_data_input), 0);
							if (bytes_data_in<=0)
							{
								//check for bytes less than 0
							 	printf("\n\rError is there\n");
							}
							int sorted = atoi(cross_data_input);
							printf("Chunk Size Server is receiving: %d\n", sorted);
							char number[10];
							bytes_data_in = recv(newsockfd, number, sizeof(number), 0);
							if (bytes_data_in<=0)
							{
								//check for bytes less than 0
								printf("\n\rError is there\n");
							}
							int no = atoi(number);
							printf("\n\rreceived data %d\n", no);
							if(strlen(subdirectory))
							{
								strcat(first_server, "/");
								printf("\n\r first server is %s\n",first_server);
							}
							strcat(first_server, file);
							printf("\n\r%s\n", first_server);
							strcat(first_server, ".");
							printf("\n\r%s\n", first_server);
							strcat(first_server, number);
							printf("\n\r%s\n", first_server);
							char seg[sorted];
							bzero(seg,sizeof(seg));
							FILE* tempraj2  = fopen(first_server, "wb");
							if (tempraj2 == NULL)
         		 		{
									printf("\n\rError is there\n");
									continue;
          			}
							int temp2 = 0;
							int num = 0;
							while(temp2 < sorted)
							{
								printf("\n\r Inside the while loop\n");
								num = recv(newsockfd, seg, sorted, 0);
								if (num<0)
								{
									printf("\n\rError is there\n");
								}
								else
								{
									//file write is happening
									fwrite(seg, 1, num, tempraj2);
									temp2 += num;
								}
							}
						fclose(tempraj2);
						num = 0;
          	bzero(cross_data_input,sizeof(cross_data_input));
						bzero(number,sizeof(number));
						bzero(seg,sizeof(seg));
						bzero(my_server_produced,sizeof(my_server_produced));
						bytes_data_in = recv(newsockfd, my_server_produced, sizeof(my_server_produced), 0);
						if (bytes_data_in<=0)
						{
							printf("\n\rError is there\n");
						}
						server_space = atoi(my_server_produced);
						printf("in second part%d\n", server_space);
						bytes_data_in = recv(newsockfd, cross_data_input, sizeof(cross_data_input), 0);
						if (bytes_data_in<=0)
						{
							printf("\n\rError is there\n");
						}
						sorted = atoi(cross_data_input);
						printf("data sorted %d\n", sorted);
						bytes_data_in = recv(newsockfd, number, sizeof(number), 0);
						if (bytes_data_in<=0)
						{
							printf("\n\rError is there\n");
						}
						no = atoi(number);
						printf("abcd%d\n", no);
						if(strlen(subdirectory))
						{
							printf("\n\rsubdirector is entered\n\r");
							strcat(second_server, "/");
						}
						strcat(second_server, file);
						printf("\n\r Second Server is %s\n",second_server);
						strcat(second_server, ".");
						printf("\n\r Second Server is %s\n",second_server);
						strcat(second_server, number);
						printf("\n\r Second Server is %s\n",second_server);
						char seg2[sorted];
						bzero(seg2,sizeof(seg2));
						tempraj2=fopen(second_server, "wb");
						if (tempraj2 == NULL)
         	 		{
								printf("\n\rError is there\n");
								continue;
         	 		}
						temp2 = 0; //made it 0 here
						while(temp2 < sorted)
						{
							printf("\n\rwhen its smaller than sorted\n");
							num = recv(newsockfd, seg2, sorted, 0);
							if (num<0)
							{
								printf("\n\r when num is smaller than 0\n");
							}
							else
							{
								printf("\n\rin the else loop\n\r");
								fwrite(seg2, 1, num, tempraj2);
								temp2 += num;
							}
						}
						fclose(tempraj2);
						bzero(cross_data_input,sizeof(cross_data_input));
						bzero(number,sizeof(number));
						sorted = 0;
						bzero(my_server_produced,sizeof(my_server_produced));
						bzero(dfsusernamesubdirectoryfoldername,sizeof(dfsusernamesubdirectoryfoldername));
						bzero(file,sizeof(file));
						bzero(command,sizeof(command));
						bzero(subdirectory,sizeof(subdirectory));
						bzero(received.username,sizeof(received.username));
						bzero(received.password,sizeof(received.password));
						bzero(first_server,sizeof(first_server));
						bzero(second_server,sizeof(second_server));

					}
					//get function started
					else if (strcmp(command, "get") == 0)
					{
						printf("In get \n");
						bytes_data_in = recv(newsockfd, file, sizeof(command), 0);
						if (bytes_data_in<0)
						{
							printf("\n\rError is there\n");
						}
						printf("sending %s \n", file);
						bytes_data_in = recv(newsockfd, subdirectory, sizeof(subdirectory), 0);
						if (bytes_data_in<=0)
						{
							printf("\n\rError is there\n");
						}
						char filepartone[300];
						char size[5];
						char temp3[5];
						char r[5];
						bytes_data_in = recv(newsockfd, my_server_produced, sizeof(my_server_produced), 0);
						if (bytes_data_in<=0)
						{
							//check for errors
							printf("\n\rError is there\n");
						}
						int server_space = atoi(my_server_produced);
						printf("Sending first part of data%d\n", server_space);
						int foundflag = 0;
						for (int ext = 1; ext<5; ext++)
						{

							bzero(filepartone,sizeof(filepartone));
							if (server_space == 0)
							{
								printf("\n\rserver is 0\n\r");
								strncat(filepartone,"DFS1/",sizeof("DFS1/"));
								printf("\n\rDFS1 is %s\n",filepartone);
							}
							else if (server_space == 1)
							{
								printf("\n\rServer is 1\n");
								strncat(filepartone, "DFS2/" , sizeof("DFS2/"));
								printf("\n\rDFS2 is %s\n",filepartone);
							}
							else if (server_space == 2)
							{
								printf("\n\rServer is2\n");
								strncat(filepartone, "DFS3/" , sizeof("DFS3/"));
								printf("\n\rDFS2 is %s\n",filepartone);
							}
							else if (server_space == 3)
							{
								printf("\n\rServer is 3\n");
								strncat(filepartone, "DFS4/" , sizeof("DFS4/"));
								printf("\n\rDFS4 is %s\n",filepartone);
							}
							strncat(filepartone, received.username, strlen(received.username));
							printf("\n\rfile part 1 data is %s\n",filepartone);
							strncat(filepartone, "/", sizeof("/"));
							printf("\n\rfile part 1 data is %s\n",filepartone);
							strncat(filepartone, subdirectory, strlen(subdirectory));
							printf("\n\rfile part 1 data is %s\n",filepartone);
							if(strlen(subdirectory))
							{
								printf("\n\rstren length is entered directory\n");
								strcat(filepartone, "/");
							}
							else
							{
								printf("\n\r part 1 \n");
								strcat(filepartone, "");
								printf("\n\rfirst par is %s\n",filepartone);
							}

							strncat(filepartone, file, strlen(file));
							printf("\n\rfile part 1 data is %s\n",filepartone);
							strncat(filepartone, "." , sizeof("."));
							printf("\n\rfile part 1 data is %s\n",filepartone);
							bzero(temp3,sizeof(temp3));
							sprintf(temp3, "%d", ext);
							strncat(filepartone, temp3, sizeof(temp3));
							printf("%s\n", filepartone);
							FILE *fp = fopen(filepartone, "rb");
							if (fp == NULL)
							{
								printf("\n\rError is there\n");
							}
							else
							{
								printf("\n\r Valid file\n\r");
								foundflag++;
								fseek(fp, 0, SEEK_END);
								int file_pointer_raj = ftell(fp);
								printf("Length of File: %d\n" , file_pointer_raj);
								rewind(fp);
								printf("Sending Chunk Number: %s\n", temp3);
								bytes_transfer = send(newsockfd, temp3, sizeof(temp3), 0);
								if (bytes_transfer < 0)
								{
									printf("\n\rError is there\n");
								}
								bzero(r,sizeof(r));
								int bytes_data_in = recv(newsockfd, r, sizeof(r), 0);
								if (strncmp(allow, r, 3) == 0)
								{
									printf("\n\rString compare is done\n\r");
									bzero(r,sizeof(r));
									sprintf(size, "%d", file_pointer_raj);
									bytes_transfer = send(newsockfd, size, sizeof(size), 0);
									if (bytes_transfer < 0)
									{
										printf("\n\rError is there\n");
									}
									printf("Sending part%s\n", size);
									char packet[file_pointer_raj];
									bzero(packet,sizeof(packet));
									fread(packet,file_pointer_raj,1,fp);
									bytes_transfer=send(newsockfd,packet,file_pointer_raj,MSG_NOSIGNAL);
									if (bytes_transfer < 0)
									{
										printf("\n\rError is there\n");
									}
									printf("\n\rNo of bytes of packet actually sent: %d\n",bytes_transfer);
									bzero(packet,sizeof(packet));
									fclose(fp);
								}
								bzero(r,sizeof(r));
							}
							if( foundflag == 2)
							{
								printf("\n\r Entered the loop when foundflas is 2\n\r");
								break;
							}
							bzero(temp3,sizeof(temp3));
							bzero(filepartone,sizeof(filepartone));
							bzero(size,sizeof(size));
							}
							/*
							bzero(my_server_produced,sizeof(my_server_produced));
							bzero(dfsusernamesubdirectoryfoldername,sizeof(dfsusernamesubdirectoryfoldername));
							bzero(file,sizeof(file));
							bzero(command,sizeof(command));
							bzero(subdirectory,sizeof(subdirectory));
							bzero(received.username,sizeof(received.username));
							bzero(received.password,sizeof(received.password));
							bzero(first_server,sizeof(first_server));
							bzero(second_server,sizeof(second_server));*/
						}

//List function started
						else if (strcmp(command, "list") == 0)
						{
							//in the loop
							printf("\n\rInside the list\n");
							char serverno[5];
							bzero(serverno,sizeof(serverno));
							int bytes_data_in = recv(newsockfd, serverno, sizeof(serverno), 0);
							if (bytes_data_in<=0)
							{
								//bytes is less than 0
								printf("\n\rwhen bytes are less than 0 error occurs\n\r");
							}
							int server_space = atoi(serverno);
							printf("Server %d\n", server_space);
							bytes_data_in = recv(newsockfd, subdirectory, sizeof(subdirectory), 0);
							if (bytes_data_in<0)
							{
								//bytes is less than 0
								printf("\n\rError is there\n");
							}
							printf("in the director%s \n", subdirectory);
							char filepartone[300];
							bzero(filepartone,sizeof(filepartone));
							switch(server_space)
							{
								case 0:
								strncat(filepartone, "DFS1/" , sizeof("DFS1/"));
								printf("\n\rfile part 1 is %s",filepartone);
								break;
								case 1:
								strncat(filepartone, "DFS2/" , sizeof("DFS2/"));
								printf("\n\rfile part 2 is %s",filepartone);
								break;
								case 2:
								strncat(filepartone, "DFS3/" , sizeof("DFS3/"));
								printf("\n\rfile part 3 is %s",filepartone);
								break;
								case 3:
								strncat(filepartone, "DFS4/" , sizeof("DFS4/"));
								printf("\n\rfile part 4 is %s",filepartone);
								break;
							}
							strncat(filepartone, received.username, strlen(received.username));
							printf("\n\rfile part 1 is %s",filepartone);
							strncat(filepartone, "/", sizeof("/"));
							printf("\n\rfile part 1 is %s",filepartone);
							strncat(filepartone, subdirectory, strlen(subdirectory));
							printf("\n\rfile part 1 is %s",filepartone);
							if (strlen(subdirectory))
							{
								printf("\n\rfile part 1 is %s",filepartone);
								strncat(filepartone, "/", sizeof("/"));
								printf("\n\rfile part 1 is %s",filepartone);
							}
							printf("path gping in%s\n", filepartone);
							int count = 0;
							int i =0;
							struct direct **file_structure;
							char written_read[500];
							bzero(written_read,sizeof(written_read));
							count = scandir(filepartone, &file_structure, filecheck, alphasort);
							printf("files %d\n", count);
							if (count <= 0)
							{
								printf("\n\rNo files \n");
								bytes_transfer = send(newsockfd, "nos", sizeof("nos"), 0);
								printf("no bytes transfered %d\n", bytes_transfer);
					   		if (bytes_transfer<0)
								{
									//bytes should be less than 0
									printf("\n\rError is there\n");
								}
								close(newsockfd);
								printf("\n\rnumber of child present %d\n", total_child);
								exit(1);
						}
							else
							{
								printf("counting counting %d\n", count);
								bytes_transfer = send(newsockfd, allow, 3, 0);
								printf("bytes are transfered for acknowledgement: %d\n", bytes_transfer);
					   		if (bytes_transfer<0)
								{
									printf("\n\rError is there\n");
								}
							}
							//slepts for 1 secS
							sleep(1);
							for (int i = 1; i<=count; i++)
							{
								//for loop strated
								printf("Looking at file: %s\n", file_structure[i-1]->d_name);
								sprintf(written_read + strlen(written_read), "%s\n", file_structure[i-1] -> d_name);
							}
							sprintf(written_read + strlen(written_read), "\n");
							int file_pointer_raj = strlen(written_read);
							char filelength[5] ;
							bzero(filelength,sizeof(filelength));
							sprintf(filelength, "%d", file_pointer_raj);
							bytes_transfer = send(newsockfd, filelength, sizeof(filelength), 0);
							printf("Length of file to send: %s in bytes %d\n", filelength, bytes_transfer);
					   	if (bytes_transfer<0)
							{
								//checl  for bytes transfered
								printf("\n\rError is there\n");
							}
							sleep(1);
							bytes_transfer = send(newsockfd, written_read, strlen(written_read), 0);
					   	if (bytes_transfer<0)
							{
								//check for bytes transfdered
								printf("\n\rError is there\n");
							}


						}
//exit loop
						else if (strcmp(command, "exit") == 0)
						{
							printf("\nin the exit loop\n");
							temp99 = close(newsockfd);
							if (temp99>0)
							{
								printf("return Value is greater than 0\n");
							}
							printf("exiting hte loop%d\n", total_child);
							exit(1);
						}

					}
					else
					{
						printf("\n\rError is there (authentication)\n");
						if(send(newsockfd, &stop, sizeof(stop), 0) <0)
						{
							printf("\n\rError is there\n");
						}
						continue;
					}
				}
				else
				{
				if(send(newsockfd, &stop, sizeof(stop), 0) <0)
					{
						printf("\n\rError is there\n");
					}
					continue;
				}
 				close(newsockfd);
				printf("\n\r%d\n", total_child);
				exit(1);
			}
			else
			{
				printf("Final loop entered\n");
				close(newsockfd);
			}

		}

	}
	return 0;
}
