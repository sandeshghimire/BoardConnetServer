#ifndef BOARD_CONNECT_SERVER_H
#define BOARD_CONNECT_SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int init_board_connect_server(int argc, char**command);

typedef struct run_time
{
    int debug;
    int foreground;
    int daemon_exit;
}run_time;


#endif

