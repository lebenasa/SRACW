/* setdat.f -- translated by f2c (version 20100827).
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
/*     CHARACTER LINE*72, MEMBER*8 */
/*     LINE = ' 1.00000E+02-2.00000E-02        125 -3.00000E-12' */
/*     LD = 4 */
/*     CALL SETDAT(LINE,LD,WORK) */
/*     WRITE(6,*) (WORK(I),I=1,LD) */
/*     WRITE(6,*) (IWORK(I),I=1,LD) */
/*     STOP */
/*     END */
/* ----------------------------------------------------------------------- */
/*     SETDAT : SET DATA FROM TEXT LINE(A72) INCLUDING INTEGER OR */
/*              FLOATING NUMBER */
/*              SAMPLE: */
/*               1.00000E+02-2.00000E-02        125 -3.00000E-12 ....... */
/* ----------------------------------------------------------------------- */
/* Subroutine */ int setdat_(char *line, integer *ld, real *data, ftnlen 
	line_len)
{
    /* System generated locals */
    integer i__1;
    icilist ici__1;
    static real equiv_0[6];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(void)
	    ;

    /* Local variables */
    static integer i__, ie, is;
#define work (equiv_0)
    static char adata[12*6];
    static integer icode;
#define iwork ((integer *)equiv_0)
    extern /* Subroutine */ int cnvint_(char *, integer *, ftnlen), txtchk_(
	    char *, integer *, ftnlen);



    /* Parameter adjustments */
    --data;

    /* Function Body */
    i__1 = *ld;
    for (i__ = 1; i__ <= i__1; ++i__) {
	is = (i__ - 1) * 12 + 1;
	ie = is + 11;
	s_copy(adata + (i__ - 1) * 12, line + (is - 1), (ftnlen)12, ie - (is 
		- 1));
	txtchk_(adata + (i__ - 1) * 12, &icode, (ftnlen)12);
	if (icode == 0) {
	    ici__1.icierr = 0;
	    ici__1.iciend = 0;
	    ici__1.icirnum = 1;
	    ici__1.icirlen = 12;
	    ici__1.iciunit = adata + (i__ - 1) * 12;
	    ici__1.icifmt = "(1PE12.5)";
	    s_rsfi(&ici__1);
	    do_fio(&c__1, (char *)&work[i__ - 1], (ftnlen)sizeof(real));
	    e_rsfi();
/*         WRITE(6,*) I,WORK(I) */
	} else {
	    cnvint_(adata + (i__ - 1) * 12, &iwork[i__ - 1], (ftnlen)12);
	}
/* L100: */
    }
    i__1 = *ld;
    for (i__ = 1; i__ <= i__1; ++i__) {
	data[i__] = work[i__ - 1];
/* L200: */
    }
    return 0;
} /* setdat_ */

#undef iwork
#undef work


