#include <iostream>
#include <iomanip>

class BoardConnectServer
{
public:
	BoardConnectServer();
	~BoardConnectServer();
	int getInitComplete() const;
	void setInitComplete(int initComplete);

private:
	int init_complete;

protected:

};

