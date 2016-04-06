dup2:dup2.c
	gcc -o $@ $^
.PHONY:clean
clean:
	rm -rf dup2 log
