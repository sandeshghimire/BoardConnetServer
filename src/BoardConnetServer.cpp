#include "BoardConnetServer.h"

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

