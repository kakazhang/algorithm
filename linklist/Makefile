
LPATH := $(shell pwd)

BIN := LinkList

SRC := main.c \
        list.c \

$(BIN) : $(SRC)
	@gcc -g $^ -o $@

clean:
	@rm -r $(BIN)
