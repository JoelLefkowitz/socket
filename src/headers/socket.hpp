#ifndef SOCKET_H
#define SOCKET_H

struct sockaddr * get_addr(char *host, int port);
void print_addr(struct sockaddr* addr);

#endif