
BIN := Download

SRC := \
	main.cpp \
	DownloadManager.cpp \
    Task.cpp

CFLAGS += -lpthread

$(BIN) : $(SRC)
	@g++ -g $^ -o $@ $(CFLAGS)

clean:
	@rm -r $(BIN)
