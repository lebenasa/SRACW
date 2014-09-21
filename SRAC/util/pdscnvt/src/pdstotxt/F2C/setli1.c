/* setli1.f -- translated by f2c (version 20100827).
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

/* Common Block Declarations */

struct {
    integer ntnuc1, ntnuc2, nzon2, nzon3;
} setdt_;

#define setdt_1 setdt_

/* Table of constant values */

static integer c__3 = 3;
static integer c__1 = 1;

/* ----------------------------------------------------------------------- */
/*     SETLI1 : SET DATA INCLUDING INTEGER OR FLOATING NUMBER OR */
/*              CHARACTER INTO A TEXT LINE(A72) */
/*              FOR THE MEMBER ----DN-T IN MACRO/MACROWRK */
/*              SAMPLE: */
/*               1.00000E+02-2.00000E-02 SRAC       -3.00000E-12 ....... */
/* ----------------------------------------------------------------------- */
/* Subroutine */ int setli1_(char *line, integer *ld, real *data, integer *
	kpos, ftnlen line_len)
{
    /* System generated locals */
    address a__1[3];
    integer i__1, i__2[3];
    icilist ici__1;
    static real equiv_0[6];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;

    /* Local variables */
    static integer i__, ie, is, iie, iis, lpos;
#define work (equiv_0)
    static integer icode;
#define cwork ((char *)equiv_0)
#define iwork ((integer *)equiv_0)
    extern /* Subroutine */ int numchk_(real *, integer *);

/*     KPOS : SEQUENTIAL POSITION OF PDS-DATA FOR THE TOP DATA IN A LINE */


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
	lpos = *kpos + i__ - 1;
	is = (i__ - 1) * 12 + 1;
	ie = is + 11;
/* ----- CASE(A4),STDNUC(A4) */
	iis = 11;
	iie = 12;
	if (lpos >= iis && lpos <= iie) {
/* Writing concatenation */
	    i__2[0] = 1, a__1[0] = " ";
	    i__2[1] = 4, a__1[1] = cwork + (i__ - 1 << 2);
	    i__2[2] = 7, a__1[2] = "       ";
	    s_cat(line + (is - 1), a__1, i__2, &c__3, ie - (is - 1));
	    goto L200;
	}
/* ----- NUCLID(NTNUC*A4) */
	if (setdt_1.ntnuc1 == 0) {
	    goto L210;
	}
	iis = 15;
	iie = iis + setdt_1.ntnuc1 - 1;
	if (lpos >= iis && lpos <= iie) {
/* Writing concatenation */
	    i__2[0] = 1, a__1[0] = " ";
	    i__2[1] = 4, a__1[1] = cwork + (i__ - 1 << 2);
	    i__2[2] = 7, a__1[2] = "       ";
	    s_cat(line + (is - 1), a__1, i__2, &c__3, ie - (is - 1));
	    goto L200;
	}
/* ---------------------- */
L210:
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
	    if (lpos == 2) {
		setdt_1.ntnuc1 = iwork[i__ - 1];
	    }
	}
L200:
	;
    }
    return 0;
} /* setli1_ */

#undef iwork
#undef cwork
#undef work


