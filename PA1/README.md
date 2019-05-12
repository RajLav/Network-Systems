**#Subject : Network Systems  
#Term : Fall 18  
#Professor : Dr Sangtae  
#Assignment : 1  
#Author : Raj Lavingia**  

**UDP File Transfer Mechanism**

This assignment consists of 2 files
1) Client
2) Server

The assignment includes the concept of socket programming with 2 models (Client and Server)
It includes services like get the file , put the file, delete the file, list the file and exit the whole process.

**Testing**  
The whole process was made a reliable transfer of files which can be of any extension like .jpg, .pdf etc.

**For running the files**  
Server : Filename Port Number  
Client : Filename localhost ip  

This code is tested on native machine and also on remote server.

**Reliability**  
If packet loss happens in UDP transfer mechanism, then the lost packet is sent again till it is received on another end. 
If in a certain time , the packet is not reached on another end then the transfer stops and the program stops.

**Concepts Learned :**  

#Socket Programming  
#Reliable Packet Transfer Mechanism in UDP  
#send to and receive from mechanism used  


