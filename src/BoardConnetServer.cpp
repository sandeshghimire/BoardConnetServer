#include "BoardConnetServer.h"
#include <string>

using namespace std;

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
                cout << "Runnin in debug mode " << endl;
                break;
            case 'f':
                bci.foreground = 1;
                cout << "Runnin in foreground mode " << endl;
                break;
            case 'n':
                bci.terminate;
                cout << "Terminating Daemon " << endl;
                break;
            default:
                cout << "Invalid option " << endl;
                break;
            }
        }
        else
        {
            // do nothing
        }
        return 0;

    }
    int BoardConnectServer::daemon_init()
    {
        if (1)

        return 0;
    }
}
