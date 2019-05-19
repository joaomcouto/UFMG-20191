CC := gcc
SRCDIR := src
OBJDIR := build

MAIN := program/main.c


SRCEXT := c
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

CFLAGS := -g -Wall -O3 -std=c11
INC := -I include/

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

main: $(OBJECTS)
	$(CC) $(CFLAGS) $(INC) $(MAIN) $^ -o tp2 -lm

all: main

clean:
	$(RM) $(OBJDIR)/*.o
	$(RM) scripts/file/*.txt
	$(RM) -r scripts/results
	$(RM) graph.txt
	$(RM) time.txt

.PHONY: clean
