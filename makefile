CXXFLAGS =		-O2 -Wall -fmessage-length=0

OBJS =			src/Main.c

INCLUDES =		

LIBS =			-lGLU -lGL -lglut -lXxf86vm

LIB_FOLDERS = 	

TARGET =		bin/Main.o

$(TARGET):	$(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(INCLUDES) $(LIBS) $(LIB_FOLDERS)

all:	$(TARGET)

clean:
	rm -rf $(TARGET)

run:
	./bin/Main.o