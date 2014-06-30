#include "BoardConnetServer.h"

namespace BoardConnet
{
    BoardConnectServer::BoardConnectServer()
    {
        init_complete = 0;
    }

    BoardConnectServer::~BoardConnectServer()
    {
    }

    inline int BoardConnectServer::getInitComplete() const
    {
        return init_complete;
    }

    inline void BoardConnectServer::setInitComplete(int initComplete)
    {
        init_complete = initComplete;
    }

    int BoardConnectServer::select_opration_mode(int argc, char *command[])
    {

    }
}
