# ========================================================================== #

# <-- Color Library --> #
ifneq ($(OS), Windows_NT)

# <-- Text Color --> #
	T_BLACK = "\\033[30m"
	T_RED = "\\033[31m"
	T_GREEN = "\\033[32m"
	T_YELLOW = "\\033[33m"
	T_BLUE = "\\033[34m"
	T_MAGENTA = "\\033[35m"
	T_CYAN = "\\033[36m2
	T_WHITE = "\\033[37m"

# <-- Text Style --> #
	BOLD = "\\033[1m"
	ITALIC = "\\033[2m"
	UNDERLINE = "\\033[3m"
	STRIKETHROUGH = "\\033[4m"

# <-- Background Color --> #
	B_RED = "\\033[31m"
	B_BLACK = "\\033[30m"
	B_GREEN = "\\033[32m"
	B_YELLOW = "\\033[33m"
	B_BLUE = "\\033[34m"
	B_MAGENTA = "\\033[35m"
	B_CYAN = "\\033[36m"
	B_WHITE = "\\033[37m"

# <-- Reset Everything --> #
	RESET = "\\033[0m"
endif
# ========================================================================== #

# <-- Program Name --> #
NAME = AcademicTracker

# <-- Program --> #
ifeq ($(OS), Windows_NT)
	PROGRAM = $(NAME).exe
else
	PROGRAM = $(NAME).out
endif

# <-- Compilation Command --> #
CC = g++

# <-- Remove Command -->#
ifeq ($(OS),Windows_NT)
	RM = -del
else
	RM = rm -f
endif

# <-- NULL --> #
ifeq ($(OS),Windows_NT)
	NULL = nul
else
	NULL = /dev/null
endif


# <-- Directories --> #
ifeq ($(OS), Windows_NT)
	SRC_DIR = src\\
	UTILS_DIR = utils\\
else
	SRC_DIR = src/
	UTILS_DIR = utils/
endif

# <-- Files --> #
SRC_FILES = main.cpp

UTILS_FILES = checker.cpp \
			grade.cpp \
			menu.cpp

# <-- Directories + Files --> #
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
UTILS = $(addprefix $(UTILS_DIR), $(UTILS_FILES))

# <-- Objects --> #
OBJ_SRC = $(SRC:.cpp=.o)
OBJ_UTILS = $(UTILS:.cpp=.o)

# ========================================================================== #

# <-- Main Target --> #
all: $(PROGRAM)

# <-- Program Creation --> #
$(PROGRAM): $(OBJ_SRC) $(OBJ_UTILS)
	@echo "$(B_GREEN)$(T_YELLOW)$(BOLD)Objects created successfully$(RESET)"
	$(CC) $(OBJ_SRC) $(OBJ_UTILS) -o $(PROGRAM)
	@echo "$(B_GREEN)$(T_YELLOW)$(BOLD)Program created successfully$(RESET)"

# <-- Objects Creation --> #
%.o: %.cpp
	$(CC) -c $< -o $@

# <-- Objects Destruction -->#
clean:
	$(RM) $(OBJ_SRC) $(OBJ_UTILS) 2> $(NULL)
	@echo "$(B_RED)$(T_YELLOW)$(BOLD)Source Object destroyed successfully$(RESET)"

# <- Program Destruction -> #
fclean: clean
	$(RM) $(PROGRAM) 2> $(NULL)
	@echo $(B_RED)$(T_YELLOW)$(BOLD)Program destroyed successfully$(RESET)

# <- Fclean Execution + All Execution -> #
re: fclean all

# <- Targets Declaration -> #
.PHONY = all clean fclean re

# ========================================================================== #