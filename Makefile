.PHONY: default release debug install uninstall clean

CC       ?= gcc
PREFIX   ?= /usr/local

SRCDIR   = src
OBJDIR   = build/obj
BINDIR   = build/bin

SRC      = $(shell find $(SRCDIR) -name '*.c')
OBJ      = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))

VERSION  = $(shell cat .VERSION)

CFLAGS  += -Wall -Wextra -I./include -DFSIZE_VERSION=\"$(VERSION)\"

TARGET   = $(BINDIR)/fsize-release-$(VERSION)

default: release

release: CFLAGS += -O2
release: $(TARGET)

debug: CFLAGS += -g
debug: $(BINDIR)/fsize-debug

$(TARGET): $(OBJ) | $(BINDIR)
	$(CC) $(OBJ) $(LDLIBS) -o $@

$(BINDIR)/fsize-debug: $(OBJ) | $(BINDIR)
	$(CC) $(OBJ) $(LDLIBS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BINDIR):
	@mkdir -p $@

install: release
	install -Dm755 $(TARGET) $(DESTDIR)$(PREFIX)/bin/fsize

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/fsize

clean:
	rm -rf build
