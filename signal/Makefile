
SRC := debugger.c

BIN := Debugger

$(BIN) : $(SRC)
	@gcc -g $^ -o $@ -rdynamic

clean:
	rm -r $(BIN)
