all:
	g++ -I include -L lib -o build/main src/main.cpp -lmingw32 -lSDL2main -lSDL2
	copy bin\SDL2.dll build\SDL2.dll

