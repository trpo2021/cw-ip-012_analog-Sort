APP_NAME = analog_sort
LIB_NAME = lib_sort

CFLAGS = -W -Wall -Wextra -Werror
LFLAGS = -I src -MP -MMD

CC = gcc


BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src

APP_PATH = $(BIN_DIR)/$(APP_NAME)
OBJ_PATH = $(OBJ_DIR)/$(ARC_DIR)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a



clean:
	$(RM) $(APP_PATH) $(LIB_PATH)
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;

#.clang-format:
#	wget -O $@ -c "https://csc-software-development.readthedocs.io/ru/2021/_static/.clang-format"

