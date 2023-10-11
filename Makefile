# Compila o codígo-fonte
all:
	@-mkdir -p build
	@-mkdir -p bin
	@-if [ -e build/main.o ]; then\
      cp build/*.o .;\
	  fi
	g++ -c src/*.cpp
	@-mv *.o build/
	g++ -o bin/progam build/*.o
	cp ./bin/progam .

run: all
	./progam

# Define a regra para limpar os arquivos gerados
clean:
	@-rm -Rf build bin progam
