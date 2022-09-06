IDIR = ./
CC=gcc
RM=rm -f
CFLAGS=-I$(IDIR) -g

SRCS= EpmsApp.c EpmsPwEncrypt.c EpmsFileProc.c EpmsUtils.c 

OBJS=$(subst .c,.o,$(SRCS))

all: epms

epms: $(OBJS)
	    $(CC) $(CFLAGS) -o epms $(OBJS)

depend: .depend

.depend: $(SRCS)
	    $(RM) ./.depend
	        $(CC) $(CFLAGS) -MM $^>>./.depend;

clean:
	    $(RM) $(OBJS)

distclean: clean
	    $(RM) *~ .depend

include .depend
