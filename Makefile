CC = g++
TARGET = prog
NUMBER = 1268.cpp
OPTION = -std=c++17 -o

$(TARGET) : $(NUMBER)
	$(CC) $(OPTION) $(TARGET) $(NUMBER)
	./$(TARGET)

bj : $(TARGET)
	./$(TARGET)

cp :
	cp form $(NUMBER)

clean : 
	rm $(TARGET)