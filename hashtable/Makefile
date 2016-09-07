
LIB := libhash.so

LIB_SRC := hash.c

BIN := Test
SRC := main.c

LOCAL_PATH := $(shell pwd)

all: $(LIB) $(BIN)

$(LIB) : $(LIB_SRC)
	@gcc -g $^ -fPIC -shared -o $@ -lpthread
	@cp $(LIB) /usr/lib

$(BIN): $(SRC)
	@gcc -g $^ -o $@ -L$(LOCAL_PATH)/$(LIB) -lhash -lpthread

clean:
	@rm -r $(LIB)

