
all: test

selflua:
	gcc -shared -o libselflua.so selflua.c -llua -lluaT -lTH

test: selflua
	gcc -o test test.c -lselflua -L. -llua
