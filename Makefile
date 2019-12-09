
include_dirs = -I include/
CFLAGS = -g

target/graph-list.o: src/GRAPHLIST/graph.c include/*
	gcc $(CFLAGS) -c $(include_dirs) src/GRAPHLIST/graph.c -o $@

target/graph-matrix.o: src/GRAPHMATRIX/graph.c include/*
	gcc $(CFLAGS) -c $(include_dirs) src/GRAPHMATRIX/matrix.c -o $@

target/uf.o: src/UF/uf.c include/*
	gcc $(CFLAGS) -c $(include_dirs) src/UF/uf.c -o $@

target/stack.o: src/STACK/stack.c include/*
	gcc $(CFLAGS) -c $(include_dirs) src/STACK/stack.c -o $@

target/test.o: src/TEST/test.c include/*
	gcc $(CFLAGS) -c $(include_dirs) src/TEST/test.c -o $@

# 构建 list
target/list: src/GRAPHLIST/main.c target/graph-list.o target/test.o include/*
	gcc $(CFLAGS) $(include_dirs) src/GRAPHLIST/main.c target/test.o target/graph-list.o -o $@

# 构建 matrix
target/matrix: src/GRAPHMATRIX/main.c target/graph-matrix.o target/test.o include/*
	gcc $(CFLAGS) $(include_dirs) src/GRAPHMATRIX/main.c target/test.o target/graph-matrix.o -o $@

target/stack: src/STACK/main.c target/stack.o target/test.o include/*
	gcc $(CFLAGS) $(include_dirs) src/STACK/main.c target/test.o target/stack.o -o $@

# 构建
target/uf: src/UF/main.c target/uf.o target/test.o
	gcc $(CFLAGS) $(include_dirs) src/UF/main.c target/test.o target/uf.o -o $@
	
clean:
	rm -rf target/*

all: target/list target/matrix

.PHONY: clean all