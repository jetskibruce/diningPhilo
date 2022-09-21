IDIR =../inc
CC=g++
CFLAGS=-I$(IDIR) -std=c++17

ODIR=obj
LDIR =../lib

LIBS=-lm -lpthread

_DEPS = philosopher.h  
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o philosopher.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS) $(LIBS) 

.PHONY: clean

clean:
		rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
