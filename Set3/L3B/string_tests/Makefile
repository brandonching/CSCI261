TARGET = L3B
SRC_FILES = main.cpp test_suite.cpp string_functions.cpp

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

.cpp.o:
	$(CXX) $(CFLAGS) -o $@ -c $<

clean:
	$(DEL) $(TARGET) $(OBJECTS)

# DEPENDENCIES
test_suite.o: test_suite.cpp test_suite.h string_functions.cpp string_functions.h
string_functions.o: string_functions.cpp string_functions.h
main.o: main.cpp test_suite.h