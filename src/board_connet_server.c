#include <stdio.h>
#include <string>
#include <syslog.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/un.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/wait.h>   /* For WEXITSTATUS */
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <pthread.h>
#include <syslog.h>
#include <sched.h>
#include <mqueue.h>
#include "board_connet_server.h"

#define LOG_EMERGENCY   0
#define LOG_ALERT   1
#define LOG_CRITICAL    2
#define LOG_ERROR   3
#define LOG_WARNING 4
#define LOG_NOTICE  5
#define LOG_INFO 6
#define LOG_DEBUG 7

const char * bcs_socket1 = "/tmp/.bcs_sock1";
const char * bcs_socket2 = "/tmp/.bcs_sock2";

