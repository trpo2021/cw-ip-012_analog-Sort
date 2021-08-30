APP_NAME = analog_sort
LIB_NAME = lib_sort
TEST_NAME = $(APP_NAME)-test

CFLAGS = -W -Wall -Wextra -Werror
LFLAGS = -I src -MP -MMD
CC = gcc
TESTFLAGS = -g

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TEST_DIR = test

APP_PATH = $(BIN_DIR)/$(APP_NAME)
OBJ_PATH = $(OBJ_DIR)/$(SRC_DIR)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.c')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.c=$(OBJ_PATH)/%.o)

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.c')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.c=$(OBJ_PATH)/%.o)

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d) $(TEST_OBJECTS:.o=.d)

-include $(DEPS)

all: $(APP_PATH)

# make bin/sort
$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $(LFLAGS) $^ -o $@

# make lib
$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

# make obj-files for lib
$(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/%.o: $(SRC_DIR)/$(LIB_NAME)/%.c
	$(CC) $(CFLAGS) $(LFLAGS) -c $< -o $@

# make obj-files for app
$(OBJ_PATH)/$(APP_NAME)/%.o: $(SRC_DIR)/$(APP_NAME)/%.c
	$(CC) $(CFLAGS) $(LFLAGS) -c $< -o $@

.PHONY: clean

clean:
	$(RM) $(APP_PATH) $(LIB_PATH)
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;

#.clang-format:
#	wget -O $@ -c "https://csc-software-development.readthedocs.io/ru/2021/_static/.clang-format"

