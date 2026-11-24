COMPILER = g++
CXX_FLAGS = -Wall -Wextra -Werror -IGraphics -lncurses

test : src/main.cpp Graphics/Renderrer.cpp Graphics/Renderrer.h
	$(COMPILER) src/main.cpp Graphics/Renderrer.cpp $(CXX_FLAGS) -o game