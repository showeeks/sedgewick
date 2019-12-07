
target/main.o: src/main.c
	gcc -g src/main.c -o target/main.o

run: target/main.o
	target/main.o

clean:
	rm -rf target/*

.PHONY: run