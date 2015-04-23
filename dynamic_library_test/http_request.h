#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include "ghttp.h"

#ifdef DEBUG_MSG
#define LOG_PRINTF(fmt, arg...) syslog(LOG_DEBUG, fmt, arg)
#else
#define LOG_PRINTF(fmt, arg...)
#endif

//ghttp_request *init_request();

//char *send_request11(ghttp_request *request, char *uri, int urilen, int mothod, char *path, int pathlen, char *body, int bodylen);

//mothod的值请参看Readme的枚举进行对应的整数值,uri和urilen必须有值且正确，若无path则path为NULL,若无body，body为NULL，responsebuf是想要接收的回应的空间，responselen是想要得到回应的长度
ghttp_request * send_request(char *uri, int urilen, int mothod, char *path, int pathlen, char *body, int bodylen, char *responsebuf, int *responselen);

//对send_request产生的ghttp_request的资源进行释放`
void destory_request(ghttp_request *request);

