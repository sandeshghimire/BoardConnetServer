#include <iostream>
#include <iomanip>
#include "BoardConnetServer.h"

using namespace std;
using namespace BoardConnet;

int main(int argc, char ** argv)
{
    BoardConnectServer * bcs = new BoardConnectServer;
    bcs->select_opration_mode(argc, argv);
    bcs->daemon_init();
    for (;;)
    {

        cout << "I am a 1s Task " << endl;
        sleep(1);
    }
    return 0;
}
