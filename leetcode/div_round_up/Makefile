
TARGET 		:= DIV_ROUND_BITS

DIRS    	:= $(shell pwd)

SRCFILES 	:= $(foreach d, $(DIRS), $(wildcard $(d)/*.c))

$(TARGET)  : $(SRCFILES)
	g++ -g $(SRCFILES) -o $(TARGET)

clean:
	rm -rf $(TARGET)
