COMPILER=/usr/bin/gcc
INCLUDE= -I./include
OBJECTFILES= src/sasMain.o src/sasHelp.o src/sasThread.o src/sasDispatcher.o src/sasVid.o src/sasFuncDispatcher.o
TARGET=sastb
CP=cp
CFLAGS= -c -w -g
DBG_FLAGS = -g -D_SAS_DEBUG_
#DBG_FLAGS = 
RM=rm
#LINK= -L../lib -L../EXTERNAL/lib 
LIB= -lpthread 
$(TARGET): $(OBJECTFILES) 
	 $(SUPPRESS)echo "Linking \`$^' ..."; \
	$(COMPILER) -I $(INCLUDE) $(OBJECTFILES) $(LIB)   -o $@

%.o : %.c
	$(COMPILER) $(DEFINES) $(INCLUDE) $(DBG_FLAGS) $(CFLAGS) $< -o $@

clean: 
	$(RM) $(OBJECTFILES) $(TARGET)
