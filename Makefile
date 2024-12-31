CC = g++
TARGET = prog
NUMBER = test.cpp
OPTION = -std=c++17 -o

$(TARGET) : $(NUMBER)
	$(CC) $(OPTION) $(TARGET) $(NUMBER)
	./$(TARGET)

bj : $(TARGET)
	./$(TARGET)

clean : 
	rm $(TARGET)