CXX := g++
CXXFLAGS := -Wall -g

SRCDIR := src
BUILDDIR := build
BINDIR := bin
FUNCTIONAL_BUILDDIR := $(BUILDDIR)/tests/functional

TARGET := bin/exe
FUNCTIONAL_TEST_TARGET := bin/functional_test
SOURCES := $(wildcard $(SRCDIR)/*.cpp $(SRCDIR)/*/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))
FUNCTIONAL := ${wildcard tests/functional/*.cpp}
FUNCTIONAL_OBJECTS := $(patsubst tests/functional/%.cpp,$(FUNCTIONAL_BUILDDIR)/%.o,$(FUNCTIONAL))

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@$(CXX) -o $@ $^ $(CXXFLAGS)
	@echo "Compilation successful. Executable: $(TARGET)"
	
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	@$(CXX) -c $< -o $@ $(CXXFLAGS)

functional: $(FUNCTIONAL_TEST_TARGET)

$(FUNCTIONAL_TEST_TARGET): $(FUNCTIONAL_OBJECTS)
	@$(CXX) -o $@ $^ $(CXXFLAGS)
	@echo "Compilation successful. Executable: $(FUNCTIONAL_TEST_TARGET)"

$(FUNCTIONAL_BUILDDIR)/%.o: tests/functional/%.cpp
	@mkdir -p $(@D)
	@$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	@$(RM) -r $(BUILDDIR) $(TARGET)
	@echo "Cleanup complete"

run: $(TARGET)
	@./$(TARGET)