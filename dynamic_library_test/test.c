#include <stdio.h>
#include <string.h>
#include "http_request.h"

int main()
{
	char *uri = "http://www.solidot.org";
	char response[80*1024] = {0};
	int responselen = 80*1024;
	ghttp_request *testreq = send_request(uri, strlen(uri), 0, NULL, 0, NULL, 0, response, &responselen);
	int lenn = strlen(uri);
	printf("response is %s len is %d lenn is %d\n", response, responselen, lenn);
	destory_request(testreq);
	return 0;
}
