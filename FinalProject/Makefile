TARGET = SchedulePlanner
SRC_FILES = main.cpp functions.cpp

CXX = g++
CFLAGS = -Wall -g -std=c++11
CXX_FLAGS = 
INC_PATH = /usr/local/include/
LIB_PATH = /usr/local/lib/
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

OBJECTS = $(SRC_FILES:.cpp=.o)

ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del
else
	DEL = rm
endif

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) ${CXX_FLAGS} -o $@ $^ -L${LIB_PATH} ${LIBS}

debug: CFLAGS += -DDEBUG
debug: clean $(TARGET)

%.o: %.cpp
	$(CXX) ${CXX_FLAGS} $(CFLAGS) -o $@ -c $< -I${INC_PATH} 
clean:
	$(DEL) $(TARGET) $(OBJECTS)