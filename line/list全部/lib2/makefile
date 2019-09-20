

lib%.a:%.o
	ar -cr $@ $<
lib%.so:%.c
	gcc -shared -fpic -o $@ $< 

install:libllist.so libllist.a
	mv $^ /usr/local/lib/
	cp llist.h /usr/local/include/








