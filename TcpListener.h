#pragma once

#include <iostream>
#include <WS2tcpip.h>
#include <string>
#include <sstream>

#pragma comment (lib, "ws2_32.lib")


class TcpListener 
{

public:

	TcpListener(const char* ipAddress, int port) :
		m_ipAddress(ipAddress), m_port(port) { }

	// initialize the listener
	int init();

	//run the listener
	int run();




protected:

	//handler for client connections
	virtual void onClientConnected();

	//handler for client disconnections
	virtual void onClientDisconnected();

	//handler when a message is received from a client
	virtual void onMessageReceived(int clientSocket, const char* msg, int length);

	//send a message to the client
	void sendToClient(int clientSocket, const char* msg, int length);

	//broadcast a message to a client
	void broadcastToClients(int sendingClient, const char* msg, int length);

private:

	const char* m_ipAddress;    // IP Adress server will run on
	int			m_port;			// Port # for the web service
	int			m_socket;		// Internal FD for the listening socket
	fd_set      m_master;       // Master file descriptor set



	
};