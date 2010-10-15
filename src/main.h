/*
 * Copyright (c) 1995 Danny Gasparovski.
 * 
 * Please read the file COPYRIGHT for the 
 * terms and conditions of the copyright.
 */

#define TRUE 1
#define FALSE 0

#include <sys/types.h>
#include <unistd.h>

#ifdef HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif

#define TOWRITEMAX 512
#define min(x,y) ((x) < (y) ? (x) : (y))

extern struct timeval tt;
extern int link_up;
extern int slirp_socket;
extern int slirp_socket_unit;
extern int slirp_socket_port;
extern u_int32_t slirp_socket_addr;
extern char *slirp_socket_passwd;
extern int ctty_closed;

/*
 * Get the difference in 2 times from updtim()
 * Allow for wraparound times, "just in case"
 * x is the greater of the 2 (current time) and y is
 * what it's being compared against.
 */
#define TIME_DIFF(x,y) (x)-(y) < 0 ? ~0-(y)+(x) : (x)-(y)

extern char *slirp_tty;
extern char *exec_shell;
extern u_int curtime;
extern fd_set readfds, writefds, xfds;
extern struct in_addr ctl_addr;
extern struct in_addr special_addr;
extern struct in_addr our_addr;
extern struct in_addr loopback_addr;
extern struct in_addr dns_addr, dns2_addr;
extern char *username;
extern char *socket_path;
extern int towrite_max;
extern int ppp_exit;
extern int so_options;
extern int tcp_keepintvl;

#define PROTO_SLIP 0x1
#ifdef USE_PPP
#define PROTO_PPP 0x2
#endif
