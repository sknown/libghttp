all:
	gcc  -g  -Wall -shared -fPIC -o request_send.so -I../lib/include/ -L../lib/ -lghttp http_request.c http_request.h

clean:
	rm  request_send.so
