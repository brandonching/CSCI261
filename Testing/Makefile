TARGET = Tester
SRC_FILES = main.cpp

CXX = g++
CFLAGS = -Wall -g
OBJECTS = $(SRC_FILES:.cpp=.o)

ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del
else
	DEL = rm
endif

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

debug: CFLAGS += -DDEBUG
debug: clean $(TARGET)

%.o: %.cpp
	$(CXX) $(CFLAGS) -o $@ -c $<
clean:
	$(DEL) $(TARGET) $(OBJECTS)