CC = g++
CFLAGS = -g -Wall -std=c++14

SRCDIR = src
BUILDDIR = build
TARGETDIR = bin

EXT = cpp

INC = -I include
SOURCES = $(wildcard $(SRCDIR)/*.$(EXT))
OBJECTS = $(patsubst $(SRCDIR)/%, $(BUILDDIR)/%, $(SOURCES:.$(EXT)=.o))

all: $(OBJECTS)
	@echo "===> Linking"
	@mkdir -p $(TARGETDIR)
	$(eval MAINOBJECTS = $(shell nm -A $(BUILDDIR)/* | grep 'T main\|T _main' | cut -d ':' -f1))
	@$(foreach MAIN, $(MAINOBJECTS), \
		$(eval TARGET = $(subst $(BUILDDIR), $(TARGETDIR), $(MAIN))) \
		$(eval LINK = $(filter-out $(MAINOBJECTS), $(OBJECTS))) \
		echo "$(CC) -o $(TARGET:.o=) $(MAIN) $(LINK)" ; \
		$(CC) -o $(TARGET:.o=) $(MAIN) $(LINK); \
	)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(EXT)
	@mkdir -p $(BUILDDIR)
	$(CC) -o $@ -c $< $(CFLAGS) $(INC)

clean:
	@echo "===> Cleaning"
	@$(RM) -r $(BUILDDIR) $(TARGETDIR)

.PHONY: clean
