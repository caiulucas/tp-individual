CXX := g++
CXXFLAGS := -Wall -g

SRCDIR := src
BUILDDIR := build

TARGET := exe
SOURCES := $(wildcard $(SRCDIR)/*.cpp $(SRCDIR)/*/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@$(CXX) -o $@ $^ $(CXXFLAGS)
	@echo "Compilation successful. Executable: $(TARGET)"
	
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	@$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	@$(RM) -r $(BUILDDIR) $(TARGET)
	@echo "Cleanup complete"

run: $(TARGET)
	@./$(TARGET)