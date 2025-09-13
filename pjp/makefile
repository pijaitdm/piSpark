CXX = gcc
CXXFLAGS = -Wall -std=c11 -Ih

SRCDIR = c
INCDIR = h
OBJDIR = obj
LIBDIR = lib

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))

TARGET = PiSpark 

all: dirs debug $(TARGET)

debug:
	@echo "File sumber yang ditemukan: $(SOURCES)"
	@echo "File objek yang akan dibuat: $(OBJECTS)"

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "✅ Build sukses: $@"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CXX) $(CXXFLAGS) -c -o $@ $<

dirs:
	mkdir -p $(OBJDIR) $(LIBDIR)

clean:
	rm -rf $(OBJDIR) $(TARGET)

# =========================================================
# Menjalankan program
# =========================================================
run: all
	@echo "🚀 Menjalankan $(TARGET)..."
	@./$(TARGET)


