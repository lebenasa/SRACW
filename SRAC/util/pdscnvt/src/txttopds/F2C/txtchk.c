/* txtchk.f -- translated by f2c (version 20100827).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/*     CHARACTER*12 ADATA */
/*     ADATA = ' 1.00000E-04' */
/*     ADATA = ' 0.         ' */
/*     ADATA = '         12 ' */
/*     CALL TXTCHK(ADATA,ICODE) */
/*     WRITE(6,*) ICODE */
/*     STOP */
/*     END */
/* ----------------------------------------------------------------------- */
/*     TXTCHK : SUBROUTINE TO CHECK A TEXT DATA(A12) IS INTEGER OR NOT */
/*     ICODE = 0 : FLOATING NUMBER */
/*           = 1 : INTEGER NUMBER */
/* ----------------------------------------------------------------------- */
/* Subroutine */ int txtchk_(char *adata, integer *icode, ftnlen adata_len)
{
    static integer i__;

    for (i__ = 1; i__ <= 12; ++i__) {
	if (*(unsigned char *)&adata[i__ - 1] == '.') {
	    *icode = 0;
	    return 0;
	} else {
	    *icode = 1;
	}
/* L100: */
    }
    return 0;
} /* txtchk_ */

