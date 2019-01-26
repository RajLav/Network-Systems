This is Readme for my fourth Programming assignment for the Network Systems Course

For this assignment, I have 2 files. (Server and Client)
In order to compile the codes you can write ./client [conf file]
for server, you will have to run all the 4 servers at the same time.
./server [root folder] [port number] (For all 4 servers)

On client Side
 1) GET :- This function gets the file from all the 4 servers which are placed in the sub folders. It automatically combines these 4 files into 1
 file and makes 1 file which is complete. If by any chance the servers are down or the file is not complete then it will show an error message
 The method of traffic utilisation is also implemented where once the data is obtained it further stops the transfer so that it does not receive the data more than once

 2) PUT:- - This command uploads the file onto the DFS with the help of MD5 sum value of a file.

 3) LIST :- This command will list all the files stored on the DFS server and print it on the terminal. 

  This whole systems is made password protected with a username and password credentials asked at the beginning of the data transfer
  
On server side

On the server end it will always respond ton the client, in a particular case if the bad command is received then the server will handle it.

DFS folder will have folders named as DFS1 to DFS4

After the start of the server it will read .conf file so that it will know multiple users and their respective passwords. 

Encryption mechanism is implemented using XOR technique by giving encryption key on both the ends. If one of the end is unaware about the 
key then encryption can not be processed.
