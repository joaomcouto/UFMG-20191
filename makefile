CC := gcc
SRCDIR := src
OBJDIR := build

MAIN := program/main.c
PRE := program/pre.c
ARRAY := program/array.c
TESTER := program/tester.c

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
	$(CC) $(CFLAGS) $(INC) $(PRE) $^ -o pre -lm
	$(CC) $(CFLAGS) $(INC) $(TESTER) $^ -o tester -lm
	$(CC) $(CFLAGS) $(INC) $(ARRAY) $^ -o array -lm

all: main

clean:
	$(RM) $(OBJDIR)/*.o
	$(RM) scripts/file/*.txt
	$(RM) -r scripts/results
	$(RM) graph.txt
	$(RM) time.txt

.PHONY: clean
