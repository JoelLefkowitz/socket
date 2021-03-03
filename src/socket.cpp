#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "headers/socket.hpp"


struct sockaddr * get_addr(char *host, int port) {
    struct sockaddr_in addr_in;
    addr_in.sin_family = AF_INET;  
    addr_in.sin_addr.s_addr = inet_addr(host); 
    addr_in.sin_port = htons(port);
    struct sockaddr * addr = (struct sockaddr *) &addr_in;
    return addr;
};


void print_addr(struct sockaddr* addr) {
    struct sockaddr_in *addr_in = (struct sockaddr_in *) addr;
    char ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(addr_in->sin_addr), ip, INET_ADDRSTRLEN);
    int port = ntohs(addr_in->sin_port);
    printf("%s:%d\n", ip, port);
};