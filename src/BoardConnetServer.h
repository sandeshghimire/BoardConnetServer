#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <iomanip>

namespace BoardConnet
{
    typedef struct BoardConnetInit
    {
        int init_complete;
        int debug;
        int foreground;
        int terminate;

    } board_connect_init;

    class BoardConnectServer
    {
    public:
        BoardConnectServer();
        ~BoardConnectServer();

        int getInitComplete() const;
        void setInitComplete(int initComplete);
        int select_opration_mode(int argc, char **argv);
        int daemon_init();

    private:
        board_connect_init bci;

    protected:

    };
}

