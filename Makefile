CC = g++
TARGET = prog
# PLATFORM: boj | mincoding | programmers
# PLATFORM = boj
PLATFORM = mincoding
# PLATFORM = programmers
NUMBER = 214.cpp
OPTION = -std=c++17 -o
SRC = $(PLATFORM)/$(NUMBER)
FORM = form.$(PLATFORM)

$(TARGET) : $(SRC)
	$(CC) $(OPTION) $(TARGET) $(SRC)
	./$(TARGET)

run : $(TARGET)
	./$(TARGET)

cp :
	cp $(FORM) $(SRC)
	code $(SRC)

git :
	git add $(SRC)
	git commit -m "$(PLATFORM) $(NUMBER)"
	git push

clean : 
	rm $(TARGET)
