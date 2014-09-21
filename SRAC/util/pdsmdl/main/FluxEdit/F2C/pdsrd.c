/* pdsrd.f -- translated by f2c (version 20100827).
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
static integer c__9 = 9;
static integer c__3 = 3;

/* *********************************************************************** */
/* UTILITY PROGRAM TO READ CONTENTS OF PDS MEMBER                       * */
/* *********************************************************************** */
/* Subroutine */ int pdsrd_(char *filnam, real *work, integer *leng, integer *
	ierr, ftnlen filnam_len)
{
    /* System generated locals */
    integer i__1;
    olist o__1;
    cllist cl__1;

    /* Builtin functions */
    integer f_open(olist *), s_rsue(cilist *), do_uio(integer *, char *, 
	    ftnlen), e_rsue(void), f_clos(cllist *), s_wsle(cilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_wsle(void);

    /* Local variables */
    static integer i__, ios, iopds;

    /* Fortran I/O blocks */
    static cilist io___3 = { 1, 0, 1, 0, 0 };
    static cilist io___5 = { 0, 6, 0, 0, 0 };
    static cilist io___6 = { 0, 6, 0, 0, 0 };
    static cilist io___7 = { 0, 6, 0, 0, 0 };




/* -------------------------------INPUT----------------------------------- */
/*     FILNAM     : FULL PDS MEMBER NAME : /XXX/XXX/MACRO/CASEA010 */
/* -------------------------------OUTPUT---------------------------------- */
/*     WORK       : CONTENTS OF MEMBER */
/*     LENG       : LENGTH OF DATA IN MEMBER (EXCEPT LENG ITSELF) */
/*     IERR       : ERROR CODE =0 : NORMAL END */
/*                             =1 : OPEN ERROR */
/*                             =2 : CLOSE ERROR */
/*                             =3 : READ ERROR */
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
    ios = s_rsue(&io___3);
    if (ios != 0) {
	goto L100001;
    }
    ios = do_uio(&c__1, (char *)&(*leng), (ftnlen)sizeof(integer));
    if (ios != 0) {
	goto L100001;
    }
    i__1 = *leng;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ios = do_uio(&c__1, (char *)&work[i__], (ftnlen)sizeof(real));
	if (ios != 0) {
	    goto L100001;
	}
    }
    ios = e_rsue();
L100001:
    if (ios > 0) {
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
    s_wsle(&io___5);
    do_lio(&c__9, &c__1, " OPEN ERROR , IOSTAT=", (ftnlen)21);
    do_lio(&c__3, &c__1, (char *)&ios, (ftnlen)sizeof(integer));
    e_wsle();
    return 0;
L200:
    *ierr = 2;
    s_wsle(&io___6);
    do_lio(&c__9, &c__1, " CLOSE ERROR , IOSTAT=", (ftnlen)22);
    do_lio(&c__3, &c__1, (char *)&ios, (ftnlen)sizeof(integer));
    e_wsle();
    return 0;
L300:
    *ierr = 3;
    s_wsle(&io___7);
    do_lio(&c__9, &c__1, " READ ERROR , IOSTAT=", (ftnlen)21);
    do_lio(&c__3, &c__1, (char *)&ios, (ftnlen)sizeof(integer));
    e_wsle();
    return 0;
} /* pdsrd_ */

