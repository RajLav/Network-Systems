**#Subject : Network Systems   
#Term : Fall 18  
#Professor : Dr Sangtae  
#Author : Raj Lavingia  
#Assignment : 3**    

**Run this file**  
./webproxy2

**Features Included :**  

Multithreading - In this , multiple clients can access the server at the same time. It is implemented with the help of forking method

Caching- If the data of the website exists in the folder of cache then the data will be recovered from that instead of getting it from the server.

Page cache - It checks if a page exists in the proxy before retrieving a page from a remote server. If there is a valid cached copy of the page, that is returned to the
client instead of creating a new server connection. Local file is created to store retrieved page based MD5sum of the url. New folder is created for 
every new host.

Hostname’ IP address cache - If same hostname is requested again, my proxy server skips the DNS query to reduce DNS query time. 

Blocked websites are written in the blocked websites txt file. 


There are 4 conditions which are handled in the code:
1. 400 Bad Request: Wrong method
2. 400 Bad Request: Wrong version
3. 404 Not Found: URL not found
4. ERROR 403 Forbidden :  Blocked Website

