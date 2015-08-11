#include <string.h>
#include "http_request.h"

ghttp_request *init_request()
{
	ghttp_request *request = NULL;
	 #ifdef DEBUG_MSG
        openlog("http_request", LOG_PID, LOG_USER);
    	#endif
	/* Allocate a new empty request object */
        request = ghttp_request_new();
	if (request == NULL)
	{
		LOG_PRINTF("Error: Func: %s Acclocate new empty request is NULL\n", __func__);
		return NULL;
	}
	LOG_PRINTF("Info: Func: %s Acclocate new empty request is ok. \n", __func__);
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
	LOG_PRINTF("Info: Func: %s Destroy request is ok. \n", __func__);
	#ifdef DEBUG_MSG
    	closelog();
    	#endif
	return ;
}

ghttp_request *send_request(char *uri, int urilen, int mothod, char *path, int pathlen, char *body, int bodylen, char *responsebuf, int *responselen)
{
	//char *uri = "http://www.solidot.org";
	/* This is the http request object */
	ghttp_request *request = NULL;
	ghttp_status status;
	char *buf = NULL, *allpath = NULL;
	int bytes_read = 0, ret = 0, allpathlen = urilen + pathlen;

	if(uri == NULL || urilen == 0 )
	{
		ret = -1;
		LOG_PRINTF("Error: Func: %sAcclocate new empty request is NULL\n", __func__);
		return request;
	}
	allpath = calloc(1, allpathlen + 1);
	snprintf(allpath, allpathlen+1, "%s%s", uri, path);
	LOG_PRINTF("Info: Func: %s allpath is %s allpath len is %d uri is %s. \n", __func__, allpath, pathlen, uri);
	/* Allocate a new empty request object */
	request = ghttp_request_new();
	if (request == NULL)
	{
		ret = -1;
		LOG_PRINTF("Error: Func: %s new request return error.\n", __func__);
		return request;
	}
	else
	{
		LOG_PRINTF("Info: Func: %s Acclocate new empty request is ok. \n", __func__);
	}
	/* Set the URI for the request object */
	if(ghttp_set_uri(request, allpath) == -1)
	{	
		ret = -1;
		LOG_PRINTF("Error: Func: %s set uri return error.\n", __func__);
		return request;
	}
	LOG_PRINTF("Info: Func: %s set uri  is ok. \n", __func__);
	/* Set the type for the request object */
	if(ghttp_set_type(request, (ghttp_type)mothod) == -1)
	{
		ret = -1;
		LOG_PRINTF("Error: Func: %s set type return error.\n", __func__);
		return request;
	}
	LOG_PRINTF("Info: Func: %s set type is ok. \n", __func__);
	if(body != NULL && bodylen != 0)
	{
		LOG_PRINTF("Info: Func: %s set body is %s \n", __func__, body);
		ret = ghttp_set_body(request,body, bodylen);
		if (ret == -1)
		{
			LOG_PRINTF("Error: Func: %s set body return error.\n", __func__);
			return request;
		}
		else
		{
			LOG_PRINTF("Info: Func: %s set body is ok. \n", __func__);
		}
	}
	else
	{
		LOG_PRINTF("Info: Func: %s not set body.\n", __func__);
	}
	/* Prepare the connection */
	ghttp_prepare(request);
	/* Process the request */
	status = ghttp_process(request);
	if(status == ghttp_error)
	{
		ret = -1;
		LOG_PRINTF("Error: Func: %s ghttp_process return error.\n", __func__);
		return request;
	}
	/* OK, done */
	LOG_PRINTF("Info: Func: %s Status code -> %d\n", __func__, ghttp_status_code(request));
	/* Get the response for the request */
	buf = ghttp_get_body(request);
	bytes_read = ghttp_get_body_len(request);
	if(buf != NULL && bytes_read >= 0 )
	{
		memcpy(responsebuf, buf, *responselen);
	}
	/* Get the response for the request*/
	*responselen = bytes_read;
	LOG_PRINTF("Info: Func: %s get_body len is %d response is: %s \n", __func__, bytes_read, buf);
	//printf("%s\n", buf);
	return request;
}

ghttp_request *send_request_async(char *uri, int urilen, int mothod, char *path, int pathlen, char *body, int bodylen, char *responsebuf, int *responselen)
{
	//char *uri = "http://www.solidot.org";
	/* This is the http request object */
	ghttp_request *request = NULL;
	ghttp_status status;
	char *buf = NULL, *allpath = NULL;
	int bytes_read = 0, ret = 0, allpathlen = urilen + pathlen, get_response_len = 0;

	if(uri == NULL || urilen == 0 )
	{
		ret = -1;
		LOG_PRINTF("Error: Func: %sAcclocate new empty request is NULL\n", __func__);
		return request;
	}
	allpath = calloc(1, allpathlen + 1);
	snprintf(allpath, allpathlen+1, "%s%s", uri, path);
	LOG_PRINTF("Info: Func: %s allpath is %s allpath len is %d uri is %s. \n", __func__, allpath, pathlen, uri);
	/* Allocate a new empty request object */
	request = ghttp_request_new();
	if (request == NULL)
	{
		ret = -1;
		LOG_PRINTF("Error: Func: %s new request return error.\n", __func__);
		return request;
	}
	else
	{
		LOG_PRINTF("Info: Func: %s Acclocate new empty request is ok. \n", __func__);
	}
	/* Set the URI for the request object */
	if(ghttp_set_uri(request, allpath) == -1)
	{	
		ret = -1;
		LOG_PRINTF("Error: Func: %s set uri return error.\n", __func__);
		return request;
	}
	LOG_PRINTF("Info: Func: %s set uri  is ok. \n", __func__);
	/* Set the type for the request object */
	if(ghttp_set_type(request, (ghttp_type)mothod) == -1)
	{
		ret = -1;
		LOG_PRINTF("Error: Func: %s set type return error.\n", __func__);
		return request;
	}
	LOG_PRINTF("Info: Func: %s set type is ok. \n", __func__);
	if(body != NULL && bodylen != 0)
	{
		LOG_PRINTF("Info: Func: %s set body is %s \n", __func__, body);
		ret = ghttp_set_body(request,body, bodylen);
		if (ret == -1)
		{
			LOG_PRINTF("Error: Func: %s set body return error.\n", __func__);
			return request;
		}
		else
		{
			LOG_PRINTF("Info: Func: %s set body is ok. \n", __func__);
		}
	}
	else
	{
		LOG_PRINTF("Info: Func: %s not set body.\n", __func__);
	}
	/* Set async request */
   	ghttp_set_sync(request, ghttp_async);
	/* Prepare the connection */
	ghttp_prepare(request);
	while(1)
	{
		/* Process the request */
		status = ghttp_process(request);
		if(status == ghttp_error)
		{
			ret = -1;
			LOG_PRINTF("Error: Func: %s ghttp_process return error.\n", __func__);
			break;
		}
		/* OK, done */
		LOG_PRINTF("Info: Func: %s Status code -> %d\n", __func__, ghttp_status_code(request));
		/* Get the response for the request */
		buf = ghttp_get_body(request);
		/* Get the response for the request*/
		bytes_read = ghttp_get_body_len(request);
		get_response_len += bytes_read;
		if(get_response_len >= *responselen)
		{
			LOG_PRINTF("Info: Func: %s get_response_len is gt responselen ---break!!\n", __func__);
			break;
		}
		else
		{
			memcpy(responsebuf, buf, bytes_read);
			responsebuf = responsebuf + bytes_read;
		}
		*responselen = bytes_read;
		LOG_PRINTF("Info: Func: %s get_body len is %d response is: %s \n", __func__, bytes_read, buf);
		if (status == ghttp_done)
		{
			break;
		}
	}
	//printf("%s\n", buf);
	return request;
}

