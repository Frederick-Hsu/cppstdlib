# File name		: Makefile
# Description	: This script builds the code files of project "rvalue_reference_move_semantics".
# Creator		: Frederique Hsu
# Creation date : Thur.	03 Dec. 2020	
# Copyright(C)	2020	All rights reserved.
#

Project = rvalue_reference_move_semantics

CC = g++
CFLAGS = -Wall -pg -std=c++17
INCLUDES = 
LIBS = 

SRC_EXTENSIONS = .cpp .cc .cxx .CC .c++
HDR_EXTENSIONS = .h .hpp .hh .HH .h++
ASM_EXTENSIONS = .s .asm

CUR_DIR = .
DIRS = $(shell find $(CUR_DIR) -maxdepth 5 -type d)
SOURCES = $(foreach dir, $(DIRS), $(wildcard $(addprefix $(dir)/*, $(SRC_EXTENSIONS))))
HEADERS = $(foreach dir, $(DIRS), $(wildcard $(addprefix $(dir)/*, $(HDR_EXTENSIONS))))
OBJECTS = $(addsuffix .o, $(basename $(SOURCES)))

.PHONY : all clean rebuild show

all : $(Project)

$(Project) : $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

%.o : %.cc
	$(CC) $(CFLAGS) -c $< -o $@

%.o : %.cxx
	$(CC) $(CFLAGS) -c $< -o $@

%.o : %.CC
	$(CC) $(CFLAGS) -c $< -o $@

%.o : %.c++
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@-rm -frv $(OBJECTS)
	@-rm -frv $(Project)
	@-rm -frv *.out

rebuild : clean all

show :
	@echo "Project = " $(Project)
	@echo "SOURCES = " $(SOURCES)
	@echo "HEADERS = " $(HEADERS)
	@echo "OBJECTS = " $(OBJECTS)