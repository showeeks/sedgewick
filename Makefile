
include_dirs = -I include/
CFLAGS = -g

target/graph-list.o: src/graph-list.c include/*
	gcc $(CFLAGS) -c $(include_dirs) src/graph-list.c -o $@

target/graph-matrix.o: src/graph-matrix.c include/*
	gcc $(CFLAGS) -c $(include_dirs) src/graph-matrix.c -o $@

# 构建 list
target/list: src/main.c target/graph-list.o
	gcc $(CFLAGS) $(include_dirs) src/main.c target/graph-list.o -o $@

# 构建 matrix
target/matrix: src/main.c target/graph-matrix.o
	gcc $(CFLAGS) $(include_dirs) src/main.c target/graph-matrix.o -o $@

clean:
	rm -rf target/*

all: target/list target/matrix

.PHONY: clean all