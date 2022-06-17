#	Copyright (c) 1990 UNIX System Laboratories, Inc.
#	Copyright (c) 1984, 1986, 1987, 1988, 1989, 1990 AT&T
#	  All Rights Reserved

#	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF
#	UNIX System Laboratories, Inc.
#	The copyright notice above does not evidence any
#	actual or intended publication of such source code.


#ident	"@(#)ucbtcopy:tcopy.mk	1.3.1.1"


#		PROPRIETARY NOTICE (Combined)
#
#This source code is unpublished proprietary information
#constituting, or derived under license from AT&T's UNIX(r) System V.
#In addition, portions of such source code were derived from Berkeley
#4.3 BSD under license from the Regents of the University of
#California.
#
#
#
#		Copyright Notice 
#
#Notice of copyright on this source code product does not indicate 
#publication.
#
#	(c) 1986,1987,1988,1989  Sun Microsystems, Inc
#	(c) 1983,1984,1985,1986,1987,1988,1989  AT&T.
#	          All rights reserved.

#     Makefile for tcopy

ROOT =

DIR = $(ROOT)/usr/ucb

INC = $(ROOT)/usr/include

INC1 = $(ROOT)/usr/ucbinclude

LDFLAGS = -s $(SHLIBS) 

CFLAGS = -O -I$(INC1) -I$(INC)

STRIP = strip

SIZE = size

#top#

MAKEFILE = tcopy.mk

MAINS = tcopy

OBJECTS =  tcopy.o

SOURCES = tcopy.c 

ALL:          $(MAINS)

$(MAINS):	tcopy.o
	$(CC) $(CFLAGS) -o tcopy tcopy.o $(LDFLAGS)
	
tcopy.o:		$(INC)/stdio.h \
		$(INC)/sys/file.h \
		$(INC)/sys/types.h \
		$(INC)/signal.h \
		$(INC)/sys/fcntl.h \
		$(INC1)/sys/mtio.h 


GLOBALINCS = $(INC)/stdio.h \
	$(INC)/sys/file.h \
	($INC)/sys/types.h \
	$(INC)/signal.h \
	$(INC)/sys/fcntl.h \
	$(INC1)/sys/mtio.h 

clean:
	rm -f $(OBJECTS)

clobber:
	rm -f $(OBJECTS) $(MAINS)

newmakefile:
	makefile -m -f $(MAKEFILE)  -s INC $(INC)
#bottom#

all :	ALL

install:	ALL
	install -f $(DIR) -m 555 -u bin -g bin tcopy 

size: ALL
	$(SIZE) $(MAINS)

strip: ALL
	$(STRIP) $(MAINS)

#     These targets are useful but optional

partslist:
	@echo $(MAKEFILE) $(SOURCES) $(LOCALINCS)  |  tr ' ' '\012'  |  sort

productdir:
	@echo $(DIR) | tr ' ' '\012' | sort

product:
	@echo $(MAINS)  |  tr ' ' '\012'  | \
	sed 's;^;$(DIR)/;'

srcaudit:
	@fileaudit $(MAKEFILE) $(LOCALINCS) $(SOURCES) -o $(OBJECTS) $(MAINS)