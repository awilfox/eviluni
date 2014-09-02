all: eviluni.cpython-34.so ccode.so

eviluni.cpython-34.so: eviluni.pyx ccode.pxd ccode.h
	CFLAGS="-g -ggdb -o0" LDFLAGS="-L." python setup.py build_ext --inplace

ccode.so: ccode.c
	clang -shared -fPIC -g -ggdb -O0 -o ccode.so ccode.c -licui18n

test:
	LD_LIBRARY_PATH=. python test.py

