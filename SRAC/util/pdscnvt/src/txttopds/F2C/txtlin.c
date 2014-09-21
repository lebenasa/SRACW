/* txtlin.f -- translated by f2c (version 20100827).
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

/* ----------------------------------------------------------------------- */
/*     LENG = 18 */
/*     CALL TXTLIN(LENG,LINE) */
/*     WRITE(6,*) LINE */
/*     STOP */
/*     END */
/* ----------------------------------------------------------------------- */
/*     TXTLIN : SET LINE NUMBER OF PRINTED PDS DATA IN TEXT P-LIB */
/*              FORMAT FROM LENG */
/*             *PUT MU050000 N     14 */
/*              1.00000E+02 2.00000E-02-3.00000E-04......... */
/*              1.00000E+02 2.00000E-02-3.00000E-04......... */
/*             -1.00000E+02 2.00000E-02 */
/*              LENG=14 => LINES TO BE READ = 3 */
/* ----------------------------------------------------------------------- */
/* Subroutine */ int txtlin_(integer *leng, integer *line)
{
    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer iadd;

    /* Fortran I/O blocks */
    static cilist io___1 = { 0, 6, 0, 0, 0 };


    if (*leng <= 0) {
	s_wsle(&io___1);
	do_lio(&c__9, &c__1, " ERROR(TXTLIN):LENGTH OF MEMBER = 0", (ftnlen)
		35);
	e_wsle();
	s_stop("", (ftnlen)0);
    }
    *line = *leng / 6;
    if (*leng % 6 != 0) {
	iadd = 1;
    } else {
	iadd = 0;
    }
    *line += iadd;
    return 0;
} /* txtlin_ */

