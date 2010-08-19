# $Id: Makefile,v 1.17 2009/10/23 16:49:08 mark Exp $
include ${FSLCONFDIR}/default.mk

PROJNAME = meshUtils

LD_LIBRARY_PATH=${FSLDIR}/lib

USRINCFLAGS = -I${INC_NEWMAT} -I${INC_ZLIB} -I${INC_PROB} -I${INC_BOOST} 
USRLDFLAGS =  -L${LIB_PROB} -L${LIB_NEWMAT} -L${LIB_ZLIB}

ifneq ($(strip $(VTKDIR_INC)),)
	USRINCFLAGS+=-I${VTKDIR_INC}
endif

ifneq ($(strip $(VTKDIR_LIB)),)
        USRLDFLAGS+=-L${VTKDIR_LIB}
endif

LIBS+=-lwarpfns -lbasisfield -lfslvtkio -lMVdisc

ifneq ($(strip $(VTKDIR_LIB)),)
        LIBS+=-lfslvtkconv 
endif

LIBS+=-lfirst_lib -lmeshclass -lnewimage -lmiscmaths -lprob -lfslio -lniftiio -lznz -lutils -lnewmat  -lz

SWOBJS=meshUtils.o
RMUOBJS=meshUtils.o run_mesh_utils.o
XFILES=run_mesh_utils

all: meshUtils.a ${XFILES}

meshUtils.a: ${SWOBJS} 
	${AR} -r libmeshUtils.a  ${SWOBJS}
	@${MAKE} libinstall

run_mesh_utils: ${RMUOBJS}
	${CXX} ${CXXFLAGS} ${LDFLAGS} -o $@ ${RMUOBJS} ${LIBS}


