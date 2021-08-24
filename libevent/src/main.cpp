#include <string.h>
#include <string>
#include <iostream>

#include <errno.h>
#include <stdio.h>
#include <signal.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/listener.h>
#include <event2/util.h>
#include <event2/event.h>


using namespace std;

int main(int argc, char* argv[])
{
	cout << "rock libevent..." << endl;  

	struct event_base *base;
	base = event_base_new();
	if (!base) {
		cout << "Could not initialize libevent!" << endl;
		return 1;
	}

	event_base_free(base);

	cout << "done" << endl;

	return 0;
}




