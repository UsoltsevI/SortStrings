all: StrQsort.o ReadStrings.o OnegMain.o
	g++ StrQsort.o ReadStrings.o OnegMain.o -o Q.exe

StrQsort.o: StrQsort.cpp
	g++ StrQsort.cpp -c

ReadStrings.o: ReadStrings.cpp
	g++ ReadStrings.cpp -c

OnegMain.o: OnegMain.cpp
	g++ OnegMain.cpp -c

clean:
	@echo "Clean project"
	rm -f StrQsort.o ReadStrings.o OnegMain.o
	@echo "Clean complited"
