## Makefile ##
all: sort

sort: main_p.o selection_sort.o insertion_sort.o merge_sort.o quick_sort.o heap_sort.o
	gcc -o sort main_p.o selection_sort.o insertion_sort.o merge_sort.o quick_sort.o heap_sort.o -lm

heap_sort.o: heap_sort.c
	gcc -c heap_sort.c

quick_sort.o: quick_sort.c
	gcc -c quick_sort.c

merge_sort.o: merge_sort.c
	gcc -c merge_sort.c

insertion_sort.o: insertion_sort.c
	gcc -c insertion_sort.c

selection_sort.o: selection_sort.c
	gcc -c selection_sort.c

main_p.o: main_p.c
	gcc -c main_p.c

clean: 
	rm -rf *.o

rmproper: clean
	rm -rf sort

run: sort
	./sort



