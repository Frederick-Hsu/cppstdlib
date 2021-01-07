# File name		: Makefile
# Description	: This script tells how to build the code files under class/ directory.
#
#

Project = class

CXXC = g++
CXXFLAGS = -Wall -std=c++17 -g -fpermissive -DDEBUG -Wextra
INCLUDES = 
LIBS = 

SRC_EXTENSIONS = .c .cpp .c++ .cc .cxx
HDR_EXTENSIONS = .h .hpp .h++ .hh .hxx

CUR_DIR = .
DIRS = $(shell find $(CUR_DIR) -maxdepth 5 -type d)
SOURCES = $(foreach dir, $(DIRS), $(wildcard $(addprefix $(dir)/*, $(SRC_EXTENSIONS))))
HEADERS = $(foreach dir, $(DIRS), $(wildcard $(addprefix $(dir)/*, $(HDR_EXTENSIONS))))
OBJECTS = $(addsuffix .o, $(basename $(SOURCES)))

.PHONY : all clean rebuild show

all : $(Project)

$(Project) : $(OBJECTS)
	$(CXXC) $(CXXFLAGS) $^ -o $@ $(INCLUDES) $(LIBS)

%.o : %.cpp %.hpp
	$(CXXC) $(CXXFLAGS) -c $< -o $@

%.o : %.c %.h
	$(CXXC) $(CXXFLAGS) -c $< -o $@

%.o : %.c++ %.h++
	$(CXXC) $(CXXFLAGS) -c $< -o $@

%.o : %.cc %.hh
	$(CXXC) $(CXXFLAGS) -c $< -o $@

%.o : %.cxx %.hxx
	$(CXXC) $(CXXFLAGS) -c $< -o $@

clean :
	@-rm -frv $(Project)
	@-rm -frv $(OBJECTS)
	@-rm -frv *.out

rebuild : clean all

show :
	@echo "Project = " $(Project)
	@echo "DIRS = " $(DIRS)
	@echo "SOURCES = " $(SOURCES)
	@echo "HEADERS = " $(HEADERS)
	@echo "OBJECTS = " $(OBJECTS)