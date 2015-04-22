#include "http_request.h"

ghttp_request *init_request()
{
	ghttp_request *request = NULL;
	/* Allocate a new empty request object */
        request = ghttp_request_new();
	if (request == NULL)
	{
		return NULL;
	}
	return request;
}

char *send_request11(ghttp_request *request, char *uri, int urilen, int mothod, char *path, int pathlen, char *body, int bodylen)
{
	//if();
	return NULL;	
}

void destory_request(ghttp_request *request)
{
	if(request != NULL)
	{
		ghttp_request_destroy(request);
	}
	return ;
}

int send_request(char *uri, int urilen, int mothod, char *path, int pathlen, char *body, int bodylen, char *responsebuf, int *responselen)
{
	//char *uri = "http://www.solidot.org";
	/* This is the http request object */
	ghttp_request *request = NULL;
	ghttp_status status;
	char *buf = NULL, *allpath = NULL;
	int bytes_read = 0, ret = 0, allpathlen = urilen + pathlen;

	if(uri == NULL || urilen == 0 || path == NULL || pathlen == 0 || body == NULL || bodylen == 0)
	{
		ret = -1;
	}
	allpath = calloc(1, allpathlen + 1);
	snprintf(allpath, allpathlen, "%s%s", uri, path);
	/* Allocate a new empty request object */
	request = ghttp_request_new();
	/* Set the URI for the request object */
	if(ghttp_set_uri(request, allpath) == -1)
	{	
		ret = -1;
	}
	/* Set the type for the request object */
	if(ghttp_set_type(request, (ghttp_type)mothod) == -1)
	{
		ret = -1;
	}
	/* Prepare the connection */
	ghttp_prepare(request);
	/* Process the request */
	status = ghttp_process(request);
	if(status == ghttp_error)
	{
		ret = -1;
	}
	/* OK, done */
	printf("Status code -> %d\n", ghttp_status_code(request));
	/* Get the response for the request */
	buf = ghttp_get_body(request);
	responsebuf = buf;
	/* Get the response for the request*/
	bytes_read = ghttp_get_body_len(request);
	*responselen = bytes_read;
	printf("%s\n", buf);
	/* Destroy the request. This closes any file descriptors that may be open and will free any memory associated with the request. */
	return ret;
}

