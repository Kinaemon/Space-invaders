COMPILER = g++
CXX_FLAGS = -Wall -Wextra -Werror -IGraphics -lncurses

test : src/main.cpp Graphics/Renderer.cpp Graphics/Renderer.h
	$(COMPILER) src/main.cpp Graphics/Renderer.cpp $(CXX_FLAGS) -o game