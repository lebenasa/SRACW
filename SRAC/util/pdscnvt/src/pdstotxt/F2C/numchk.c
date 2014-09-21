/* numchk.f -- translated by f2c (version 20100827).
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
/*     NUMCHK : SUBROUTINE TO CHECK A BINARY DATA IS INTEGER OR NOT */
/*     ICODE = 0 : FLOATING NUMBER */
/*           = 1 : INTEGER NUMBER */
/* -----SAMPLE PROGRAM---------------------------------------------------- */

/*     DIMENSION WORK(10),IWORK(10) */
/*     EQUIVALENCE (WORK(1),IWORK(1)) */
/*     DO 100 I=1,10 */
/*       WORK(I) = FLOAT(I) */
/*       IF (I.EQ.10) IWORK(I) = 10 */
/*       CALL NUMCHK (WORK(I),ICODE) */
/*       IF(ICODE.EQ.1) THEN */
/*         WRITE(6,*) IWORK(I) */
/*       ELSE */
/*         WRITE(6,*) WORK(I) */
/*       ENDIF */
/* 100 CONTINUE */
/*     STOP */
/*     END */
/* ----------------------------------------------------------------------- */
/* Subroutine */ int numchk_(integer *ia, integer *icode)
{
    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    , s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static char aho[7];

    /* Fortran I/O blocks */
    static icilist io___2 = { 0, aho, 0, "(I7)", 7, 1 };



    s_wsfi(&io___2);
    do_fio(&c__1, (char *)&(*ia), (ftnlen)sizeof(integer));
    e_wsfi();
    if (s_cmp(aho, "*******", (ftnlen)7, (ftnlen)7) == 0) {
	*icode = 0;
    } else {
	*icode = 1;
    }
/*     WRITE(6,*) AHO */
    return 0;
} /* numchk_ */

