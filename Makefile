exe: main.o libtree.a
	gcc -g main.c -o exe -L. libtree.a
libtree.a: tree.o
	ar rs libtree.a tree.o
tree.o: tree.c
	gcc -c tree.c -o tree.o
main.o: main.c
	gcc -c main.c -o main.o
clean:
	rm tree.o
	rm main.o
	rm libtree.a
	rm *.exe
