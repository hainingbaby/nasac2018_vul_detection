CC=gcc
CPP=g++
DEBUG=-g
CFLAGS=-c -lpthread
LFLAGS=-lpthread
AR=ar

INCLUDES=-I ./testcasesupport

MAIN=main_linux.cpp
MAIN_OBJECT=$(MAIN:.cpp=.o)

C_SUPPORT_PATH=./testcasesupport/
C_SUPPORT_FILES=$(C_SUPPORT_PATH)io.c
C_SUPPORT_OBJECTS=io.o

# only grab the .c files without "w32" or "wchar_t" in the name
C_SOURCES=$(wildcard testset*.c)
C_OBJECTS=$(C_SOURCES:.c=.o)

# only grab the .cpp files without "w32" or "wchar_t" in the name
CPP_SOURCES=$(wildcard testset*.cpp)
CPP_OBJECTS=$(CPP_SOURCES:.cpp=.o)

#OBJECTS=$(MAIN_OBJECT) $(C_OBJECTS) $(CPP_OBJECTS) $(C_SUPPORT_OBJECTS)
OBJECTS=$(C_OBJECTS) $(CPP_OBJECTS) $(C_SUPPORT_OBJECTS)
# TARGET is the only line in this file specific to the CWE
TARGET=testset1.a

all: $(TARGET)

$(TARGET) : $(OBJECTS)
	$(AR) -r $@ $^

$(C_OBJECTS) : $(C_SOURCES)
	$(CC) $(CFLAGS) $(INCLUDES) $(@:.o=.c) -o $@

$(CPP_OBJECTS) : $(CPP_SOURCES)
	$(CPP) $(CFLAGS) $(INCLUDES) $(@:.o=.cpp) -o $@

$(C_SUPPORT_OBJECTS) : $(C_SUPPORT_FILES)
	$(CC) $(CFLAGS) $(INCLUDES) $(C_SUPPORT_PATH)$(@:.o=.c) -o $@

#$(MAIN_OBJECT) : $(MAIN)
#	$(CC) $(CFLAGS) $(INCLUDES) $(MAIN) -o $@

clean:
	rm -rf *.o $(TARGET)
