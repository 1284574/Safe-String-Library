opt=-std=c2x

all: clean safestr

safestr: safestr.o
	cc $^ -o $@ ${opt}

safestr.o: safestr.c
	cc -c $^ -o $@

clean:
	rm -f *.o *.so