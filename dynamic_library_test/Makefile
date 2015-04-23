all:
	gcc  -g  -Wall -shared -fPIC -o librequestsend.so -I../lib/include/ -L../lib/ -lghttp http_request.c http_request.h

with-debug:
	gcc  -g  -Wall -DDEBUG_MSG -shared -fPIC -o librequestsend.so -I../lib/include/ -L../lib/ -lghttp http_request.c http_request.h

clean:
	rm  *.so
