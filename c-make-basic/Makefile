# compiler and flags
CC      = clang
CFLAGS  = -Wall -Wextra -g
LDFLAGS =

# configurable output directory
OUTDIR = out

# source discovery
SOURCES = $(shell find . -name '*.c' | sort)
OBJECTS = $(patsubst %.c, $(OUTDIR)/%.o, $(SOURCES))

# executable name
EXECUTABLE = program_name


# default target
all: $(EXECUTABLE)

# link step
$(EXECUTABLE): $(OBJECTS)
	@echo "Linking $@..."
	@mkdir -p $(OUTDIR)
	@$(CC) $(LDFLAGS) $(OBJECTS) -o $(OUTDIR)/$@

# compile step
$(OUTDIR)/%.o: %.c
	@echo "Compiling $@..."
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# cleanup
clean:
	@echo "Cleaning..."
	@rm -rf $(OUTDIR)
