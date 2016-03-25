all:myelf.o
	gcc -o $@ $<

%.o:%.c FORCE
	gcc -c $<

clean:
	rm -fr *.o myelf all

FORCE:
