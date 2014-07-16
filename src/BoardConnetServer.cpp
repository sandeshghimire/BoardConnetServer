#include "BoardConnetServer.h"
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

using namespace std;

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

namespace BoardConnet
{
    BoardConnectServer::BoardConnectServer()
    {
        bci.init_complete = 0;
        bci.debug = 0;
        bci.foreground = 0;
        bci.terminate = 0;
    }

    BoardConnectServer::~BoardConnectServer()
    {
    }

    inline int BoardConnectServer::getInitComplete() const
    {
        return bci.init_complete;
    }

    inline void BoardConnectServer::setInitComplete(int initComplete)
    {
        bci.init_complete = initComplete;
    }

    int BoardConnectServer::select_opration_mode(int argc, char **argv)
    {
        int option = 0;
        if (argc > 0)
        {
            option = getopt(argc, argv, "dfn");

            switch (option)
            {
            case 'd':
                bci.debug = 1;
                cout << "Running in debug mode " << endl;
                break;
            case 'f':
                bci.foreground = 1;
                cout << "Running in foreground mode " << endl;
                break;
            case 'n':
                bci.terminate;
                cout << "Terminating Daemon " << endl;
                break;
            default:
                cout << "Running in background mode " << endl;
                break;
            }
        }
        else
        {
            // do nothing
        }
        (void) daemon_init();
        return 0;
    }

    int BoardConnectServer::daemon_init()
    {
        pid_t pid;
        int rVlaue;

        if ((!bci.debug) && (!bci.foreground))
        {

            if (0 < (pid = fork()))
            {
                syslog(LOG_DEBUG, "Unable to start daemon");
                exit(-1);
            }
            else if (pid != 0)
            {
                exit(1);
            }
            else
            {
                (void) setsid();
                if (-1 == chdir("/"))
                {
                    syslog(LOG_DEBUG, "Unable to change dir ");
                }
                (void) umask(0);
            }
        }
        return 0;
    }
}
