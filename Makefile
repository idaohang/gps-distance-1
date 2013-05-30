CC = gcc
CFLAGS =-g -Wall

SRC = geofence_example.c geofencelib.c
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