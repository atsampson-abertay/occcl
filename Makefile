CC=gcc
CFLAGS=-g -Wall -lOpenCL -I.
DEPS = 
OBJ = hellocl.o initial.o rot13.o sin.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellocl: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
clean:
	rm -f hellocl.o initial.o rot13.o sin.o hellocl
