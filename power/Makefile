
LPATH := $(shell pwd)

BIN := Power

SRC := main.c \
        power.c \

$(BIN) : $(SRC)
	@gcc -g $^ -o $@

clean:
	@rm -r $(BIN)
