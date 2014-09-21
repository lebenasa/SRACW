/* cnvint.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__9 = 9;
static integer c__1 = 1;

/*     CHARACTER*12 ADATA */
/*     ADATA = '     125    ' */
/*     ADATA = '125         ' */
/*     ADATA = '         125' */
/*     ADATA = '            ' */
/*     CALL CNVINT(ADATA,IDATA) */
/*     WRITE(6,*) IDATA */
/*     STOP */
/*     END */
/* ----------------------------------------------------------------------- */
/*     CNVINT : SUBROUTINE TO CONVERT TEXT DATA(A12) INTO INTEGER DATA */
/*              EX : '   1234     ' => 1234 */
/* ----------------------------------------------------------------------- */
/* Subroutine */ int cnvint_(char *adata, integer *idata, ftnlen adata_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(void)
	    ;

    /* Local variables */
    static integer i__, ie, le, is, ls, ldata;
    static char atemp[12];

    /* Fortran I/O blocks */
    static cilist io___5 = { 0, 6, 0, 0, 0 };
    static icilist io___9 = { 0, atemp, 0, "(I12)", 12, 1 };



    s_copy(atemp, "            ", (ftnlen)12, (ftnlen)12);
    is = 0;
    ie = 0;
    for (i__ = 1; i__ <= 12; ++i__) {
	if (*(unsigned char *)&adata[i__ - 1] != ' ' && is == 0) {
	    is = i__;
	    ie = 0;
	    if (i__ == 12) {
		ie = is;
	    }
	    goto L100;
	}
	if (*(unsigned char *)&adata[i__ - 1] == ' ' && ie == 0 && is != 0) {
	    ie = i__ - 1;
	    goto L100;
	}
	if (*(unsigned char *)&adata[i__ - 1] != ' ' && i__ == 12) {
	    ie = 12;
	    goto L100;
	}
	if (i__ == 12 && is == 0) {
	    s_wsle(&io___5);
	    do_lio(&c__9, &c__1, " ERROR(CNVINT) : DATA MAY BE EMPTY :", (
		    ftnlen)36);
	    do_lio(&c__9, &c__1, adata, (ftnlen)12);
	    e_wsle();
	    s_stop("", (ftnlen)0);
	}
L100:
	;
    }
    ldata = ie - is + 1;
    ls = 12 - ldata + 1;
    le = 12;
    s_copy(atemp + (ls - 1), adata + (is - 1), le - (ls - 1), ie - (is - 1));
    s_rsfi(&io___9);
    do_fio(&c__1, (char *)&(*idata), (ftnlen)sizeof(integer));
    e_rsfi();
    return 0;
} /* cnvint_ */

