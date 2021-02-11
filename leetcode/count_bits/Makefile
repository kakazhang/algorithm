
TARGET 		:= CountBits

DIRS    	:= $(shell pwd)

SRCFILES 	:= $(foreach d, $(DIRS), $(wildcard $(d)/*.cpp))

CPPFLAGS	:= std=c++11

$(TARGET)  : $(SRCFILES)
	g++ -g $(SRCFILES) -o $(TARGET)

clean:
	rm -rf $(TARGET)
