CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = main

HEADERS = $(wildcard *.h)

$(TARGET): main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: run clean