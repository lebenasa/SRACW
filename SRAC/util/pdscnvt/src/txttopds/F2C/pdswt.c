/* pdswt.f -- translated by f2c (version 20100827).
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

/* *********************************************************************** */
/* UTILITY PROGRAM TO WRITE CONTENTS OF PDS MEMBER                      * */
/* *********************************************************************** */
/* Subroutine */ int pdswt_(char *filnam, real *work, integer *leng, integer *
	ierr, ftnlen filnam_len)
{
    /* System generated locals */
    integer i__1;
    olist o__1;
    cllist cl__1;

    /* Builtin functions */
    integer f_open(olist *), s_wsue(cilist *), do_uio(integer *, char *, 
	    ftnlen), e_wsue(void), f_clos(cllist *);

    /* Local variables */
    static integer i__, ios, iopds;

    /* Fortran I/O blocks */
    static cilist io___3 = { 1, 0, 0, 0, 0 };




/* -------------------------------INPUT----------------------------------- */
/*     FILNAM     : FULL PDS MEMBER NAME : /XXX/XXX/MACRO/CASEA010 */
/*     WORK       : CONTENTS OF MEMBER */
/*     LENG       : LENGTH OF DATA IN MEMBER (EXCEPT LENG ITSELF) */
/* -------------------------------OUTPUT---------------------------------- */
/*     IERR       : ERROR CODE =0 : NORMAL END */
/*                             =1 : OPEN ERROR */
/*                             =2 : CLOSE ERROR */
/*                             =3 : WRITE ERROR */
/* ----------------------------------------------------------------------- */

    /* Parameter adjustments */
    --work;

    /* Function Body */
    *ierr = 0;
    iopds = 49;

    o__1.oerr = 1;
    o__1.ounit = iopds;
    o__1.ofnmlen = 81;
    o__1.ofnm = filnam;
    o__1.orl = 0;
    o__1.osta = "UNKNOWN";
    o__1.oacc = "SEQUENTIAL";
    o__1.ofm = "UNFORMATTED";
    o__1.oblnk = 0;
    ios = f_open(&o__1);
    if (ios != 0) {
	goto L100;
    }
    io___3.ciunit = iopds;
    ios = s_wsue(&io___3);
    if (ios != 0) {
	goto L300;
    }
    ios = do_uio(&c__1, (char *)&(*leng), (ftnlen)sizeof(integer));
    if (ios != 0) {
	goto L300;
    }
    i__1 = *leng;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ios = do_uio(&c__1, (char *)&work[i__], (ftnlen)sizeof(real));
	if (ios != 0) {
	    goto L300;
	}
    }
    ios = e_wsue();
    if (ios != 0) {
	goto L300;
    }
    cl__1.cerr = 1;
    cl__1.cunit = iopds;
    cl__1.csta = "KEEP";
    ios = f_clos(&cl__1);
    if (ios != 0) {
	goto L200;
    }
    return 0;
L100:
    *ierr = 1;
/*     WRITE(6,*) ' OPEN ERROR , IOSTAT=',IOS */
    return 0;
L200:
    *ierr = 2;
/*     WRITE(6,*) ' CLOSE ERROR , IOSTAT=',IOS */
    return 0;
L300:
    *ierr = 3;
/*     WRITE(6,*) ' WRITE ERROR , IOSTAT=',IOS */
    return 0;
} /* pdswt_ */

