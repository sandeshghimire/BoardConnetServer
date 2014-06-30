
#include <iostream>
#include <iomanip>

namespace BoardConnet
{

    class BoardConnectServer
    {
    public:
        BoardConnectServer();
        ~BoardConnectServer();

        int getInitComplete() const;
        void setInitComplete(int initComplete);
        int select_opration_mode(int argc, char **argv);

    private:
        int init_complete;
        int debug;
        int foreground;

    protected:

    };
}

