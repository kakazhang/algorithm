SRC := ringbuffer.c main.c

BIN := TESTRingBuffer

LIBS := -lpthread -lrt

CFLAGS := -DUSE_SHM

$(BIN):$(SRC)
	gcc -g $(SRC) -o $(BIN) $(LIBS) $(CFLAGS)

clean:
	rm -rf $(BIN)
