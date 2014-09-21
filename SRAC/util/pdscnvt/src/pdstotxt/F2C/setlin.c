/* setlin.f -- translated by f2c (version 20100827).
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
/*     DIMENSION WORK(6),IWORK(1) */
/*     EQUIVALENCE (WORK(1),IWORK(1)) */
/*     CHARACTER LINE*72 */
/*     WORK(1)  =  1.00000E+02 */
/*     WORK(2)  = -2.00000E-02 */
/*     IWORK(3) = 125 -3.00000E-12 */
/*     WORK(4)  = -3.00000E-12 */
/*     IWORK(5) = 1 */
/*     WORK(6) = -4.125E-1 */
/*     LD = 3 */
/*     CALL SETLIN(LINE,LD,WORK) */
/*     WRITE(6,*) LINE */
/*     STOP */
/*     END */
/* ----------------------------------------------------------------------- */
/*     SETLIN : SET DATA INCLUDING INTEGER OR FLOATING NUMBER */
/*              IN TEXT LINE(A72) */
/*              SAMPLE: */
/*               1.00000E+02-2.00000E-02        125 -3.00000E-12 ....... */
/* ----------------------------------------------------------------------- */
/* Subroutine */ int setlin_(char *line, integer *ld, real *data, ftnlen 
	line_len)
{
    /* System generated locals */
    integer i__1;
    icilist ici__1;
    static real equiv_0[6];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;

    /* Local variables */
    static integer i__, ie, is;
#define work (equiv_0)
    static integer icode;
#define iwork ((integer *)equiv_0)
    extern /* Subroutine */ int numchk_(real *, integer *);



    /* Parameter adjustments */
    --data;

    /* Function Body */
    s_copy(line, " ", (ftnlen)72, (ftnlen)1);
    i__1 = *ld;
    for (i__ = 1; i__ <= i__1; ++i__) {
	work[i__ - 1] = data[i__];
/* L100: */
    }

    i__1 = *ld;
    for (i__ = 1; i__ <= i__1; ++i__) {
	is = (i__ - 1) * 12 + 1;
	ie = is + 11;
	numchk_(&data[i__], &icode);
	if (icode == 0) {
	    ici__1.icierr = 0;
	    ici__1.icirnum = 1;
	    ici__1.icirlen = ie - (is - 1);
	    ici__1.iciunit = line + (is - 1);
	    ici__1.icifmt = "(1PE12.5)";
	    s_wsfi(&ici__1);
	    do_fio(&c__1, (char *)&work[i__ - 1], (ftnlen)sizeof(real));
	    e_wsfi();
	} else {
	    ici__1.icierr = 0;
	    ici__1.icirnum = 1;
	    ici__1.icirlen = ie - (is - 1);
	    ici__1.iciunit = line + (is - 1);
	    ici__1.icifmt = "(4X,I7,1X)";
	    s_wsfi(&ici__1);
	    do_fio(&c__1, (char *)&iwork[i__ - 1], (ftnlen)sizeof(integer));
	    e_wsfi();
	}
/* L200: */
    }
    return 0;
} /* setlin_ */

#undef iwork
#undef work


