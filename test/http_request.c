#include <stdio.h>
#include <stdlib.h>
#include "ghttp.h"

//A simple example from doc/ghttp.html
int main()
{
	char *uri = "http://www.solidot.org";
	/* This is the http request object */
	ghttp_request *request = NULL;
	ghttp_status status;
	char *buf = NULL;
	int bytes_read = 0;
	
	/* Allocate a new empty request object */
	request = ghttp_request_new();
	/* Set the URI for the request object */
	if(ghttp_set_uri(request, uri) == -1)
		exit(-1);
	/* Set the type for the request object */
	if(ghttp_set_type(request, ghttp_type_get) == -1)
		exit(-1);
	/* Prepare the connection */
	ghttp_prepare(request);
	/* Process the request */
	status = ghttp_process(request);
	if(status == ghttp_error)
		exit(-1);
	/* OK, done */
	printf("Status code -> %d\n", ghttp_status_code(request));
	/* Get the response for the request */
	buf = ghttp_get_body(request);
	/* Get the response for the request*/
	bytes_read = ghttp_get_body_len(request);
	printf("%s\n", buf);
	/* Destroy the request. This closes any file descriptors that may be open and will free any memory associated with the request. */
	ghttp_request_destroy(request);
	return 0;
}

