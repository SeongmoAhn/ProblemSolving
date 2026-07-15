CC = g++
TARGET = prog
NUMBER = b.cpp
JNUMBER = b.java
OPTION = -std=c++17 -o

$(TARGET) : $(NUMBER)
	$(CC) $(OPTION) $(TARGET) $(NUMBER)
	./$(TARGET)

bj : $(TARGET)
	./$(TARGET)

java : $(JNUMBER)
	java $(JNUMBER)

cp :
	cp form $(NUMBER)
	code $(NUMBER)

git :
	git add $(NUMBER)
	git commit -m "baekjoon $(NUMBER)"
	git push

clean : 
	rm $(TARGET)
