#include <stdio.h>
#include <stdlib.h>
#include "ghttp.h"

ghttp_request *init_request();

char *send_request11(ghttp_request *request, char *uri, int urilen, int mothod, char *path, int pathlen, char *body, int bodylen);

void destory_request(ghttp_request *request);

int send_request(char *uri, int urilen, int mothod, char *path, int pathlen, char *body, int bodylen, char *responsebuf, int *responselen);

