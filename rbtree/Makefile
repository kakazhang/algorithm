
INCDIRS 		:= include

SRCDIRS			:= src

INCLUDE			:= $(patsubst %, -I %, $(INCDIRS))

CFILES			:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))

CFILENDIR		:= $(notdir  $(CFILES))

COBJS			:= $(patsubst %, obj/%, $(CFILENDIR:.c=.o))
OBJS			:= $(COBJS)

VPATH			:= $(SRCDIRS)

TARGET          := topic_manager

.PHONY: clean

$(TARGET) : $(CFILES)
	gcc -g $(CFILES) -o $(TARGET) $(INCLUDE) -lpthread

clean:
	rm -rf $(TARGET)
