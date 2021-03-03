#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "headers/main.hpp"
#include "headers/socket.hpp"
#include "headers/stream.hpp"

int main( int argc, char* args[] ) {
    char * port = "4200";
    struct sockaddr_storage their_addr;
    socklen_t addr_size;
    struct addrinfo hints, *res;
    int sockfd, new_fd;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;  // use IPv4 or IPv6, whichever
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;     // fill in my IP for me

    getaddrinfo(NULL, port, &hints, &res);

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    bind(sockfd, res->ai_addr, res->ai_addrlen);
    listen(sockfd, 1);

    addr_size = sizeof their_addr;
    new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &addr_size);
};


// int main( int argc, char* args[] ) {
//     socklen_t addr_size = sizeof(struct sockaddr_in);

//     int fd = socket(AF_INET, SOCK_STREAM, 0);
//     struct sockaddr * server_addr = get_addr((char *) "127.0.0.1", 4200);
//     bind(fd, server_addr, addr_size);
//     listen(fd, 1);

//     int client = socket(AF_INET, SOCK_STREAM, 0);
//     struct sockaddr * client_addr = get_addr((char *) "127.0.0.1", 4200);
//     connect(fd, client_addr, addr_size);
    
//     printf("Accept\n");
//     accept(fd, client_addr, &addr_size);
// };
