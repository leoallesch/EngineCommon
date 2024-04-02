CC := gcc

SRC_DIR := src
BUILD_DIR := build/debug

OBJ_NAME := target

SRC_FILES := $(shell find $(SRC_DIR) -name '*.c')
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))

INC_DIRS := $(shell find $(SRC_DIR) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CC_FLAGS := -std=c99 -Wall -O0 -g $(INC_FLAGS)

LINKER_FLAGS := -lSDL2_ttf -lSDL2_image -lm
SDL_FLAGS := `sdl2-config --cflags --libs`

all: $(BUILD_DIR)/$(OBJ_NAME)
	@echo "  "
	@echo Build Successful!
	@echo "  "


$(BUILD_DIR)/$(OBJ_NAME): $(OBJ_FILES)
	@echo "Linking $@"
	@$(CC) $^ -o $@ $(LINKER_FLAGS) $(SDL_FLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "Compiling $<"
	@$(CC) $(CC_FLAGS) -c $< -o $@

run: all
	@echo "Running $(OBJ_NAME)"
	@echo " "
	@./$(BUILD_DIR)/$(OBJ_NAME)

clean:
	@echo "Cleaning..."
	@rm -rf $(BUILD_DIR)
	@echo "Cleanup successful!"

.PHONY: all run clean