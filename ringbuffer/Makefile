SRC := ringbuffer.c main.c

BIN := TESTRingBuffer

LIBS := -lpthread

$(BIN):$(SRC)
	gcc -g $(SRC) -o $(BIN) $(LIBS)

clean:
	rm -rf $(BIN)
