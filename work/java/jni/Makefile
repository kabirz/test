SRCJ := $(shell ls  *.java)
SRCCPP := $(SRCJ:.java=.cpp)
SRCC   := $(SRCJ:.java=.c)
TARGET := $(SRCJ:.java=)
OBJJ := $(SRCJ:.java=.class)
JNILIB := lib$(TARGET).so
CFLAGS+= -I $(JAVA_HOME)/include -I $(JAVA_HOME)/include/linux

all: $(OBJJ) $(JNILIB) 

clean:
	@rm $(OBJJ) $(TARGET).h $(JNILIB) -fr

%.class:%.java
	javac  $<

$(JNILIB):CFLAGS+=-fPIC -shared
#$(JNILIB):$(TARGET).cpp $(TARGET).h
#	g++ $(CFLAGS) -o $@ $<

$(JNILIB):$(TARGET).c $(TARGET).h
	gcc $(CFLAGS) -o $@ $<

%.h:%.java
	javah $(<:.java=)

