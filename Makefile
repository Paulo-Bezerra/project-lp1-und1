# Compila o codígo-fonte
all:
	mkdir -p build
	-cp build/*.o .
	g++ -c src/*.cpp
	cp -r *.o build/
	rm -r *.o
	g++ -o bin/progam build/*.o
	cp ./bin/progam .

run: all
	./progam

# Define a regra para limpar os arquivos gerados
clean:
	@rm -f build/* bin/* progam