
OUT=out/
INCLUDE_DIR=src/include/

CC=gcc

SRC_DIR=src/
CFLAGS=-Wall
SRC=$(SRC_DIR)main.c $(SRC_DIR)rfid_reader.c  $(SRC_DIR)lib/utils.c $(SRC_DIR)lib/config.c 



$(OUT):
	@mkdir $@
clean:
	@rm -rf $(OUT)

all: $(OUT)rfidutil

$(OUT)rfidutil: $(SRC) $(OUT)
	$(CC) -I$(INCLUDE_DIR) $(SRC) -DDEBUG $(CFLAGS) -o $@


