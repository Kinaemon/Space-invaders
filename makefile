COMPILER = g++

CXX_FLAGS = -std=c++20 -Wall -Wextra -Werror \
            -IGraphics -IGame -IInput -IObjects -IWorld

LIBS = -lncurses -pthread

SOURCES =   src/main.cpp \
            Graphics/Renderer.cpp \
            Game/Game.cpp \
            Input/Input.cpp \
            Objects/GameObject.cpp \
            World/World.cpp

HEADERS = $(wildcard Graphics/*.h Game/*.h Input/*.h Objects/*.h World/*.h)

TARGET = game

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(COMPILER) $(CXX_FLAGS) $(SOURCES) -o $(TARGET) $(LIBS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)