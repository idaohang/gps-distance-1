CC = gcc
CFLAGS =-g -Wall

SRC = distance.c geofencelib.c
EXE= GEOFENCING_EXE


all : $(EXE)
$(EXE) : $(SRC)
	$(CC)   -o $@ $^
clean:
	$(RM) *\~
	$(RM) $(OBJS)
 #handle windows output.
	$(RM) $(EXE).exe
	$(RM) $(EXE)