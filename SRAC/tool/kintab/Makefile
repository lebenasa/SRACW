#
#  Makefile to produce load module for Bickley Function Table
#
SRAC_DIR = D:/SRACs/SRAC
#                                                                             
#  Note : If this is not executed by @PunchMe, set the full path name
#         of the SRAC code file in the following statement, and use it instead
#         of the above statement.
#                                                                             
#SRAC_DIR = $(HOME)/SRAC
#
#------------------------------------------------------------------------------
F77   = gfortran
OPT   = 
#
EXT   = $(SRAC_DIR)/src/extnl
LM    = kintab.out
OBJ   = kintab.o uioset.o uioint.o ugtenv.o

#------------------------------------------------------------------------------

$(LM):			$(OBJ)
			$(F77) -o $(LM) $(OPT) $(OBJ)

kintab.o:		kintab.f
			$(F77) -c $(OPT) kintab.f

uioset.o:		$(EXT)/uioset.f
			$(F77) -c $(OPT) $(EXT)/uioset.f

uioint.o:		$(EXT)/uioint.f
			$(F77) -c $(OPT) $(EXT)/uioint.f

ugtenv.o:		$(EXT)/ugtenv.f
			$(F77) -c $(OPT) $(EXT)/ugtenv.f
#------------------------------------------------------------------------------
