CC = g++
TARGET = prog
NUMBER = 20365.cpp
OPTION = -std=c++17 -o

$(TARGET) : $(NUMBER)
	$(CC) $(OPTION) $(TARGET) $(NUMBER)
	./$(TARGET)

bj : $(TARGET)
	./$(TARGET)

cp :
	cp form $(NUMBER)
	code $(NUMBER)

git :
	git add $(NUMBER)
	git commit -m "baekjoon $(NUMBER)"
	git push

clean : 
	rm $(TARGET)
