ifeq ($(OS), Windows_NT)
	CLEANUP = pwsh -Command Remove-Item *.o
else
	CLEANUP = rm -f *.o
endif

compile:
	g++ -I include -c src/*.cpp -std=c++17
	g++ *.o -o build/neith -std=c++17
	$(CLEANUP)