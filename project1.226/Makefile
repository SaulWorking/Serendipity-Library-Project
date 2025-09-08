# https://makefiletutorial.com/#why-do-makefiles-exist

#assign compiler
CXX := g++

#assign compiler flags
CXXFLAGS := -Wall -O2 -Iinclude

#assign source files directory
SRC_DIR := src
#assign output files directory
OUT_DIR := output

#assign target directory (../program/main)
TARGET := $(OUT_DIR)/main

#look at cpp files in source file directory

#find all files in source directory

#assign source files to src
SRCSF := $(wildcard $(SRC_DIR)/*.cpp)

#set basic target
all: $(TARGET)

#assign target's targets to rebuild if a source file changes or 
$(TARGET): $(SRCSF) | $(OUT_DIR)




# output main.cpp file in [program] directory using all [files] in source
#$@ is TARGET, name
#$^ is dependency files

# g++ -Wall -O2 -Iinclude -o program/main pfiles/bookinfo.cpp pfiles/cashier.cpp pfiles/invmenu.cpp pfiles/mainmenu.cpp pfiles/reports.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^


# clean up output directory
clean:
	rm -rf $(OUT_DIR)






