#
# Modified 2024-0924 by ahd@kewm.com (Drew Derbyshire) make gneeric and to use
# /usr/local as destination.
#

CFLAGS= -O
SEPFLAG= -i
PROGRAM=xtitle
MAN=	${PROGRAM}.0
MANSRC=	${PROGRAM}.1
DESTDIR=/usr/local

all: ${PROGRAM} ${MAN}

${PROGRAM}: ${PROGRAM}.o 
	cc -i -o ${PROGRAM} ${PROGRAM}.o

${PROGRAM}.o: ${PROGRAM}.c 
	cc ${CFLAGS} -c ${PROGRAM}.c

${PROGRAM}.0: ${PROGRAM}.1
	# /usr/man/manroff ${MANSRC} > ${MAN}
	nroff -man -h ${MANSRC} > ${MAN}

install: all
	install -c -s ${PROGRAM} ${DESTDIR}/bin
	install -c -o bin -g bin -m 444 ${MAN} ${DESTDIR}/man/cat1

clean:
	rm -f ${PROGRAM}.o ${PROGRAM} ${MAN}

echo:
	echo MACHINE=${MACHINE}
