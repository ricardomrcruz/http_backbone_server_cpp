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
	void onClientConnected();

	//handler for client disconnections
	void onClientDisconnected();

	void sendToClient(int clientSocket, const char* msg, int length)

private:

	const char* m_ipAddress;    // IP Adress server will run on
	int			m_port;			// Port # for the web service
	int			m_socket;		// Internal FD for the listening socket
	fd_set      m_master;       // Master file descriptor set



	
};