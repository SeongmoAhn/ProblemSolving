CC = g++
TARGET = prog
# PLATFORM: boj | mincoding
PLATFORM = mincoding
NUMBER = 9990.cpp
OPTION = -std=c++17 -o
SRC = $(PLATFORM)/$(NUMBER)

$(TARGET) : $(SRC)
	$(CC) $(OPTION) $(TARGET) $(SRC)
	./$(TARGET)

run : $(TARGET)
	./$(TARGET)

cp :
	cp form $(SRC)
	code $(SRC)

git :
	git add $(SRC)
	git commit -m "$(PLATFORM) $(NUMBER)"
	git push

clean : 
	rm $(TARGET)
