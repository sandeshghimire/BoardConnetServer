#include "BoardConnetServer.h"

BoardConnectServer::BoardConnectServer()
{
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

