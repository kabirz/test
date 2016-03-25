#PHONY +=FORCE
FORCE:
#.PHONY: $(PHONY)

%:%.o FORCE
	gcc -o $@ $<
%.o:%.c FORCE
	gcc -c $<

