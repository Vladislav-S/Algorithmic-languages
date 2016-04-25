CXXFLAGS=-I/usr/local/include/ -std=c++1y
LDFLAGS=-lc++ -lcrypto
HEADERS=Header.h
SOURCES=MyException.cpp	Region.cpp	main.cpp \
Person.cpp	Source.cpp	split.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=elections

all: $(SOURCES) $(EXECUTABLE)

clean: 
	rm *.o $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@