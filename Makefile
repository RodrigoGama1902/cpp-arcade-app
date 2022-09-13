all:
	g++ -Wall -std=c++17 -lmingw32 -I include -I src/graphics -I src/shapes -I src/utils -L lib src/utils/*.cpp src/graphics/*.cpp src/main.cpp -o build/main -lSDL2main -lSDL2
	copy bin\SDL2.dll build\SDL2.dll

