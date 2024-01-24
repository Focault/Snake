CXX = g++
CC = $(CXX)

CPPFLAGS = -I $(INC_DIR) -I $(INL_DIR)
CPPFLAGS += -MMD -MP
# CPPFLAGS += -DDEBUG
# c language
CFLAGS = -g3

# c++ language
CXXFLAGS = -std=c++17
CXXFLAGS+= -Wall -pedantic
CXXFLAGS+= -Wextra
CXXFLAGS+= -Werror
CXXFLAGS+= -g3

LDFLAGS =
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

SRC_DIR= ./
INC_DIR= ../inc/
INL_DIR= ../inc/inl/

TARGET = Snake
# ! Fill only this:
OBJS = $(SRC_DIR)Snake.o $(SRC_DIR)snake_game.o $(SRC_DIR)snake_window.o $(SRC_DIR)snake_game_logic.o

all: $(TARGET)

$(TARGET): $(OBJS)

check: all
	./$(TARGET)

vala: all
	valgrind --leak-check=yes --track-origins=yes -s ./$(TARGET)

DEPENDS= $(OBJS:%.o=%.d)

clean:
	@$(RM) $(TARGET) $(OBJS) $(DEPENDS) .gdb_history

.PHONY: all check clean DEPENDS

-include $(DEPENDS)