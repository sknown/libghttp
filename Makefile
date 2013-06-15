
all:
	gcc -DGHTTP_MAJOR_VERSION=1 -DGHTTP_MINOR_VERSION=0 -DGHTTP_MICRO_VERSION=9 -DPACKAGE=\"libghttp\" -DVERSION=\"1.0.9\" -DSTDC_HEADERS=1 -I. -I. -g -O2 -c ghttp.c -o ghttp.o >/dev/null 2>&1
	gcc -DGHTTP_MAJOR_VERSION=1 -DGHTTP_MINOR_VERSION=0 -DGHTTP_MICRO_VERSION=9 -DPACKAGE=\"libghttp\" -DVERSION=\"1.0.9\" -DSTDC_HEADERS=1 -I. -I. -g -O2 -c http_date.c -o http_date.o >/dev/null 2>&1
	gcc -DGHTTP_MAJOR_VERSION=1 -DGHTTP_MINOR_VERSION=0 -DGHTTP_MICRO_VERSION=9 -DPACKAGE=\"libghttp\" -DVERSION=\"1.0.9\" -DSTDC_HEADERS=1 -I. -I. -g -O2 -c http_hdrs.c -o http_hdrs.o >/dev/null 2>&1
	gcc -DGHTTP_MAJOR_VERSION=1 -DGHTTP_MINOR_VERSION=0 -DGHTTP_MICRO_VERSION=9 -DPACKAGE=\"libghttp\" -DVERSION=\"1.0.9\" -DSTDC_HEADERS=1 -I. -I. -g -O2 -c http_req.c -o http_req.o >/dev/null 2>&1
	gcc -DGHTTP_MAJOR_VERSION=1 -DGHTTP_MINOR_VERSION=0 -DGHTTP_MICRO_VERSION=9 -DPACKAGE=\"libghttp\" -DVERSION=\"1.0.9\" -DSTDC_HEADERS=1 -I. -I. -g -O2 -c http_resp.c -o http_resp.o >/dev/null 2>&1
	gcc -DGHTTP_MAJOR_VERSION=1 -DGHTTP_MINOR_VERSION=0 -DGHTTP_MICRO_VERSION=9 -DPACKAGE=\"libghttp\" -DVERSION=\"1.0.9\" -DSTDC_HEADERS=1 -I. -I. -g -O2 -c http_trans.c -o http_trans.o >/dev/null 2>&1
	gcc -DGHTTP_MAJOR_VERSION=1 -DGHTTP_MINOR_VERSION=0 -DGHTTP_MICRO_VERSION=9 -DPACKAGE=\"libghttp\" -DVERSION=\"1.0.9\" -DSTDC_HEADERS=1 -I. -I. -g -O2 -c http_uri.c -o http_uri.o >/dev/null 2>&1
	gcc -DGHTTP_MAJOR_VERSION=1 -DGHTTP_MINOR_VERSION=0 -DGHTTP_MICRO_VERSION=9 -DPACKAGE=\"libghttp\" -DVERSION=\"1.0.9\" -DSTDC_HEADERS=1 -I. -I. -g -O2 -c http_base64.c -o http_base64.o >/dev/null 2>&1
	ar cru libghttp.a  ghttp.o http_date.o http_hdrs.o http_req.o http_resp.o http_trans.o http_uri.o http_base64.o
	ranlib libghttp.a

clean:
	rm *.o *.a
