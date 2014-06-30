#include <iostream>
#include "BoardConnetServer.h"


using namespace std;
using namespace BoardConnet;

int main(int argc, char ** argv)
{
    BoardConnectServer * bcs = new BoardConnectServer;
    bcs->select_opration_mode(argc, argv);
	return 0;
}
