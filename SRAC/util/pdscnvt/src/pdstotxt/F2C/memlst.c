/* memlst.f -- translated by f2c (version 20100827).
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

static integer c__1 = 1;

/* ----------------------------------------------------------------------- */
/*     PARAMETER (MAXME=3000) */
/*     DIMENSION MEMNAM(MAXME) */
/*     CHARACTER MEMNAM*8 */
/*     IOMLS = 11 */
/*     CALL MEMLST(IOMLS,NMEM,MEMNAM) */
/*     WRITE(6,*) 'NMEM= ',NMEM */
/*     DO 10 I=1,NMEM */
/*       WRITE(6,*) MEMNAM(I) */
/*  10 CONTINUE */
/*     STOP */
/*     END */
/* ----------------------------------------------------------------------- */
/*     MEMLST : READ LIST OF MEMBER NAME FROM SPECIAL MEMBER(LIST) */
/*     FORMAT IS DEPEND ON UNIX SYSTEM BUT DIVIDED BY SOME BLANKS. */
/*     CU050000   CU08000   CPU00000   CPU10000  CPU20000 */
/*     CPU90000   CAM1000 */
/* ----------------------------------------------------------------------- */
/* Subroutine */ int memlst_(integer *iomls, integer *nmem, char *memnam, 
	ftnlen memnam_len)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, ie, is;
    static char line[255];
    static integer lmem, isrc, ipos, lline;

    /* Fortran I/O blocks */
    static cilist io___4 = { 0, 0, 1, "(A255)", 0 };




    /* Parameter adjustments */
    memnam -= 8;

    /* Function Body */
    lline = 255;
    ipos = 0;
    *nmem = 0;
L1000:
    isrc = 0;
    io___4.ciunit = *iomls;
    i__1 = s_rsfe(&io___4);
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, line, (ftnlen)255);
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = e_rsfe();
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = lline;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* -- FIND NEW MEMBER NOW */
	if (isrc == 0 && *(unsigned char *)&line[i__ - 1] != ' ') {
	    lmem = 1;
	    isrc = 1;
/* -- ALREADY FOUND */
	} else if (isrc != 0 && *(unsigned char *)&line[i__ - 1] != ' ') {
	    ++lmem;
	}
/* -- END OF MEMBER */
	if (isrc != 0 && *(unsigned char *)&line[i__ - 1] == ' ') {
	    ++(*nmem);
	    is = i__ - lmem;
	    ie = i__ - 1;
	    s_copy(memnam + (*nmem << 3), line + (is - 1), (ftnlen)8, ie - (
		    is - 1));
	    isrc = 0;
	}
/* L100: */
    }
    goto L1000;

L9999:
    return 0;
} /* memlst_ */

