#pragma once
#include "TcpListener.h"

class MultiClientChat : public TcpListener
{
public:

	MultiClientChat(const char* ipAddress, int port) :
		TcpListener(ipAddress, port) {

	}

protected:
	//handler for client connections
	virtual void onClientConnected(int clientSocket);

	//handler for client disconnections
	virtual void onClientDisconnected(int clientSocket);

	//handler when a message is received from a client
	virtual void onMessageReceived(int clientSocket, const char* msg, int length);
};
