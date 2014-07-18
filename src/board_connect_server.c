#include "board_connect_server.h"

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


static run_time rt;
static void select_operation_mode(int, char**);
static int daemon_init(void);


int init_board_connect_server(int argc, char**command)
{
    select_operation_mode(argc, command);
}


static void select_operation_mode(int argc, char**command)
{
    int option = 0;
    while ((option = getopt(argc, command, "dfn")) != -1)
    {
        if (option == 'd')
        {
            rt.debug = 1;
            printf("Debug Mode \n");
        }
        else if (option == 'f')
        {
            rt.foreground = 1;
            printf("Foreground Mode \n");
        }
        else if (option == 'n')
        {
            rt.daemon_exit = 1;
            printf("Terminate Daemon \n");
        }
        else
        {
            printf("Invalid command \n");
        }

        if ( !rt.debug && !rt.foreground)
        {
            if ( -1 == daemon_init())
            {
                syslog(LOG_DEBUG, "Unable to start daemon");
                exit(-1);
            }
        }
    }
}

static int daemon_init(void)
{
    pid_t pid;

    if ((pid = fork()) < 0)
        return -1;
    else if (pid != 0)
        exit(0);

    setsid();
    chdir("/");
    umask(0);
    return 0;
}


