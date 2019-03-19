#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() 
{
  int network_socket ;
  network_socket=socket(AF_INET, SOCK_STREAM, 0) ;
  
  struct sockaddr_in server_address ;
  server_address.sin_family=AF_INET ;
  server_address.sin_port=htons(9002) ;
  server_address.sin_addr.s_addr=inet_addr("192.168.31.134") ;
  
  int stat=connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
  if (stat== -1);
  {
    printf("error") ;
  }
  
  char server_response[256] ;
  recv(network_socket, &server_response, sizeof(server_response), 0) ;
  
  printf("The server sent the data : %s", server_response) ;
  
  close(network_socket) ;
  
  return 0 ;
}
