CC = g++
LFLAGS = -std=c++11
CFLAGS = -c -Wall

EXECUTABLE_NAME = OSSim
SOURCES = main.cpp CPU.cpp IODevice.cpp SortedLinkedList.cpp OperatingSystem.cpp Memory.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): $(OBJECTS) 
	$(CC) -o $(EXECUTABLE_NAME) $(OBJECTS)

.cpp.o:
	$(CC) $(CFLAGS) $(LFLAGS) $< -o $@

clean:
	$(RM) *.o *~ $(EXECUTABLE_NAME)
