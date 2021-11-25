all:
	make -C ./dictionary
	make -C ./priority_queue
.PHONY: clean 
clean:
	make clean -C ./dictionary
	make clean -C ./priority_queue