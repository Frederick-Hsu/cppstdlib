# File name		: Makefile
# Description	: This script tells how to build current project new_lang_feats
#

PROJECT = variadic_templates

CPPC = g++
CPPFLAGS = -Wall -pg -DDEBUG -std=c++17
INCLUDES = 
LIBS = 

SRC_EXTENSIONS = .cpp .cc .cxx
HDR_EXTENSIONS = .h .hpp .hh

CUR_DIR = .
DIRS = $(shell find -maxdepth 4 -type d)
SOURCES = $(foreach dir, $(DIRS), $(wildcard $(addprefix $(dir)/*, $(SRC_EXTENSIONS))))
HEADERS = $(foreach dir, $(DIRS), $(wildcard $(addprefix $(dir)/*, $(HDR_EXTENSIONS))))
OBJECTS = $(addsuffix .o, $(basename $(SOURCES)))

.PHONY : all clean rebuild show

all : $(PROJECT)

$(PROJECT) : $(OBJECTS)
	$(CPPC) $(CPPFLAGS) $^ -o $@ $(LIBS)

%.o : %.cpp
	$(CPPC) $(CPPFLAGS) -c $< -o $@

%.o : %.cc
	$(CPPC) $(CPPFLAGS) -c $< -o $@

%.o : %.cxx
	$(CPPC) $(CPPFLAGS) -c $< -o $@

clean :
	@-rm -frv $(OBJECTS)
	@-rm -frv $(PROJECT)
	@-rm -frv *.out

rebuild : clean all

show :
	@echo "DIRS = " $(DIRS)
	@echo "SOURCES = " $(SOURCES)
	@echo "HEADERS = " $(HEADERS)
	@echo "OBJECTS = " $(OBJECTS)