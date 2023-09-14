CC=g++
CFLAGS=-Wall -g
LDFLAGS=
SOURCES=node.h linked_list.h song.cpp playlist.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Playlist

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o $(EXECUTABLE)
