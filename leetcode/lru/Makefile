TARGET := LRU

SRCDIRS := $(shell pwd)

SRCFILES := $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.cpp))

FLAGS := -std=c++11

$(TARGET) : $(SRCFILES)
	g++ -g $(SRCFILES) -o $(TARGET) $(FLAGS)

clean:
	rm -rf $(TARGET)
