
include_dirs = -I include/
CFLAGS = -g

target/graph-list.o: src/GRAPHLIST/graph.c include/*
	gcc $(CFLAGS) -c $(include_dirs) src/GRAPHLIST/graph.c -o $@

target/graph-matrix.o: src/GRAPHMATRIX/graph.c include/*
	gcc $(CFLAGS) -c $(include_dirs) src/GRAPHMATRIX/matrix.c -o $@

target/uf.o: src/UF/uf.c include/*
	gcc $(CFLAGS) -c $(include_dirs) src/UF/uf.c -o $@

target/test.o: src/TEST/test.c include/*
	gcc $(CFLAGS) -c $(include_dirs) src/TEST/test.c -o $@

# 构建 list
target/list: src/GRAPHLIST/main.c target/graph-list.o target/test.o
	gcc $(CFLAGS) $(include_dirs) src/GRAPHLIST/main.c target/test.o target/graph-list.o -o $@

# 构建 matrix
target/matrix: src/GRAPHMATRIX/main.c target/graph-matrix.o target/test.o
	gcc $(CFLAGS) $(include_dirs) src/GRAPHMATRIX/main.c target/test.o target/graph-matrix.o -o $@

# 构建
target/uf: src/UF/main.c target/uf.o target/test.o
	gcc $(CFLAGS) $(include_dirs) src/UF/main.c target/test.o target/uf.o -o $@
	
clean:
	rm -rf target/*

all: target/list target/matrix

.PHONY: clean all