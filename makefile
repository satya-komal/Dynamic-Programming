all:
	g++ prim.cpp -o prim.out
	g++ kruskal.cpp	-o kruskal.out
	g++ lcs.cpp -o lcs.out
	
clean:
	rm -f *.o prim.out
	rm -f *.o kruskal.out
	rm -f *.o lcs.out
