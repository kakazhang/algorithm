
LPATH := $(shell pwd)

BIN := LinkList

SL_BIN := SL

SRC := main.c \
       list.c

SL_SRC := oneway_linklist.c


$(BIN) : $(SRC)
	@gcc -g $^ -o $@

$(SL_BIN) : $(SL_SRC)
	@gcc -g $^ -o $@

clean:
	@rm -r $(BIN) $(SL_BIN)
