/* engedt.f -- translated by f2c (version 20100827).
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
    real work[200000];
} wkpds_;

#define wkpds_1 wkpds_

/* Table of constant values */

static integer c__9 = 9;
static integer c__1 = 1;
static integer c__3 = 3;
static integer c__107 = 107;

/* *********************************************************************** */
/*  PROGRAM TO OUTPUT ENERGY GROUP STRUCTURE FROM MEMBER CONT_00_       * */
/*  IN FLUX OR MACROWRK OR MACRO OR MICREF FILE                         * */
/*  VERSION : SRAC95 FOR UNIX                                           * */
/* *********************************************************************** */

/* Subroutine */ int engedt_(char *dirnam, integer *iout, integer *iprn, char 
	*memnam, integer *ng, real *wt, real *en, ftnlen dirnam_len, ftnlen 
	memnam_len)
{
    /* Format strings */
    static char fmt_7000[] = "(\002 \002,\002ENGEDT\002,114(\002=\002))";
    static char fmt_6000[] = "(\002 \002,\002  G \002,2x,\002ASYMPTOTIC FL"
	    "X\002,2x,\002ENERGY LIMIT(EV)\002)";
    static char fmt_6100[] = "(\002 \002,i4,3x,1pe12.5,3x,1pe12.5)";
    static char fmt_7010[] = "(\002 \002,114(\002=\002),\002ENGEDT\002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);

    /* Local variables */
    static integer i__, ig, irc, leng;
    extern /* Subroutine */ int pdsin_(char *, char *, real *, integer *, 
	    integer *, integer *, ftnlen, ftnlen);
#define iwork ((integer *)&wkpds_1)
    static char member[8];

    /* Fortran I/O blocks */
    static cilist io___6 = { 0, 0, 0, 0, 0 };
    static cilist io___7 = { 0, 6, 0, 0, 0 };
    static cilist io___8 = { 0, 0, 0, 0, 0 };
    static cilist io___9 = { 0, 6, 0, 0, 0 };
    static cilist io___10 = { 0, 0, 0, 0, 0 };
    static cilist io___11 = { 0, 0, 0, fmt_7000, 0 };
    static cilist io___12 = { 0, 0, 0, 0, 0 };
    static cilist io___13 = { 0, 0, 0, 0, 0 };
    static cilist io___14 = { 0, 0, 0, 0, 0 };
    static cilist io___15 = { 0, 0, 0, fmt_6000, 0 };
    static cilist io___16 = { 0, 0, 0, 0, 0 };
    static cilist io___18 = { 0, 0, 0, fmt_6100, 0 };
    static cilist io___19 = { 0, 0, 0, 0, 0 };
    static cilist io___20 = { 0, 0, 0, 0, 0 };
    static cilist io___21 = { 0, 0, 0, fmt_7010, 0 };
    static cilist io___22 = { 0, 0, 0, 0, 0 };



/* =========================== FOR MAIN ================================== */
/* DEL  PARAMETER  (MAXNG=107) */
/*     PARAMETER DEFINISION FOR PDSMDL */

/*     ------------------------------------------------------------------ */
/*     PARAMETER MEANING                                  RECOMMENDED */
/*     NAME      MEANING                                  DEFAULT VALUE */
/*     ------------------------------------------------------------------ */
/*     MAXNG     MAXIMUM FINE ENERGY GROUPS                      107 */
/*     MAXNGC    MAXIMUM CONDENSED ENERGY GROUPS                  20 */
/*     MAXSTP    MAXIMUM BURNUP STEPS                             35 */
/*     MAXNUC    MAXIMUM BURNABLE NUCLIDES IN CHAIN              110 */
/*     MAXZN     MAXIMUM BURNABLE ZONES                           50 */
/*     MAXNR     MAXIMUM R-REGIONS                               300 */
/*     MAXXS     MAXIMUM XS-TYPES                                 10 */
/*     MAXUP     MAXIMUM UP-SCATTERING GROUPS                     48 */
/*     MAXWRK    MAXIMUM LENGTH OF A PDS MEMBER               200000 */
/*     ------------------------------------------------------------------ */
/*     ------------------------------------------------------------------ */
/* ======================================================================= */
/* DEL  PARAMETER  (MAXWRK=250) */
/* -------------------------------INPUT----------------------------------- */
/*     DIRNAM     : DIRECTORY NAME (A72) OF PDS : /XXX/XXX/FLUX01 */
/*     IOUT       : LOGICAL DEVICE FOR OUTPUT */
/*     IPRN       : =0(NO PRINT), =1(PRINT OUT IN DEVICE IOUT) */
/*     MEMNAM     : PDS MEMBER NAME TO EDIT(A8) */
/* -------------------------------OUTPUT---------------------------------- */
/*     NG         : NUMBER OF ENERGY GROUPS CORRESPONDING TO INPUT */
/*                  MEMBER NAME FOR ENENRGY STRUCTURE (CONTE00P). */
/*     WT(G)      : INTEGRATED ASYMPTOTIC NEUTRON SPECTRUM (G=1,NG) */
/*                  WT(GC)=SUM(WT(GF)) */
/*     EN(G)      : ENERGY BOUNDARIES STARTING FROM THE HIGHEST ENERGY */
/*                  GROUP (G=1,NG+1) */
/* ----------------------------------------------------------------------- */
/* ************************** */
/*      ZERO SETTING       *--------------------------------------------- */
/* ************************** */
    /* Parameter adjustments */
    --en;
    --wt;

    /* Function Body */
    for (i__ = 1; i__ <= 200000; ++i__) {
	wkpds_1.work[i__ - 1] = 0.f;
/* L100: */
    }
    for (i__ = 1; i__ <= 108; ++i__) {
	en[i__] = 0.f;
	wt[i__] = 0.f;
/* L110: */
    }
/* ************************** */
/* ENERGY GROUP STRUCTURE  *-------------------------------------------- */
/* ************************** */
    s_copy(member, memnam, (ftnlen)8, (ftnlen)8);
    pdsin_(dirnam, member, wkpds_1.work, &leng, &irc, iout, (ftnlen)72, (
	    ftnlen)8);
    if (irc != 0) {
	io___6.ciunit = *iout;
	s_wsle(&io___6);
	do_lio(&c__9, &c__1, " ERROR(ENGEDT): PDSIN ERROR, CODE=", (ftnlen)34)
		;
	do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___7);
	    do_lio(&c__9, &c__1, " ERROR(ENGEDT): PDSIN ERROR, CODE=", (
		    ftnlen)34);
	    do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	    e_wsle();
	}
	s_stop("", (ftnlen)0);
    }
    *ng = iwork[0];
    if (*ng > 107) {
	io___8.ciunit = *iout;
	s_wsle(&io___8);
	do_lio(&c__9, &c__1, " ERROR(ENGEDT): NUMBER OF ENERGY GROUPS(=", (
		ftnlen)41);
	do_lio(&c__3, &c__1, (char *)&(*ng), (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ") IS GREATER THAN THE SET VALUE(=", (ftnlen)33);
	do_lio(&c__3, &c__1, (char *)&c__107, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ")", (ftnlen)1);
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___9);
	    do_lio(&c__9, &c__1, " ERROR(ENGEDT): NUMBER OF ENERGY GROUPS(=", 
		    (ftnlen)41);
	    do_lio(&c__3, &c__1, (char *)&(*ng), (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, ") IS GREATER THAN THE SET VALUE(=", (ftnlen)
		    33);
	    do_lio(&c__3, &c__1, (char *)&c__107, (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, ")", (ftnlen)1);
	    e_wsle();
	}
	s_stop("", (ftnlen)0);
    }
    i__1 = *ng;
    for (i__ = 1; i__ <= i__1; ++i__) {
	wt[i__] = wkpds_1.work[i__];
/* L200: */
    }
    i__1 = *ng + 1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	en[i__] = wkpds_1.work[*ng + 1 + i__ - 1];
/* L210: */
    }
/* ************************** */
/*     PRINT OUT           *-------------------------------------------- */
/* ************************** */
    if (*iprn == 0) {
	goto L9000;
    }
    io___10.ciunit = *iout;
    s_wsle(&io___10);
    e_wsle();
    io___11.ciunit = *iout;
    s_wsfe(&io___11);
    e_wsfe();
    io___12.ciunit = *iout;
    s_wsle(&io___12);
    e_wsle();
    io___13.ciunit = *iout;
    s_wsle(&io___13);
    do_lio(&c__9, &c__1, " NUMBER OF ENERGY GROUPS (MEMBER:", (ftnlen)33);
    do_lio(&c__9, &c__1, memnam, (ftnlen)8);
    do_lio(&c__9, &c__1, ")= ", (ftnlen)3);
    do_lio(&c__3, &c__1, (char *)&(*ng), (ftnlen)sizeof(integer));
    e_wsle();
    io___14.ciunit = *iout;
    s_wsle(&io___14);
    e_wsle();
    io___15.ciunit = *iout;
    s_wsfe(&io___15);
    e_wsfe();
    io___16.ciunit = *iout;
    s_wsle(&io___16);
    e_wsle();
    i__1 = *ng + 1;
    for (ig = 1; ig <= i__1; ++ig) {
	io___18.ciunit = *iout;
	s_wsfe(&io___18);
	do_fio(&c__1, (char *)&ig, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&wt[ig], (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&en[ig], (ftnlen)sizeof(real));
	e_wsfe();
/* L1000: */
    }
    io___19.ciunit = *iout;
    s_wsle(&io___19);
    e_wsle();
    io___20.ciunit = *iout;
    s_wsle(&io___20);
    e_wsle();
    io___21.ciunit = *iout;
    s_wsfe(&io___21);
    e_wsfe();
    io___22.ciunit = *iout;
    s_wsle(&io___22);
    e_wsle();

L9000:
    return 0;
} /* engedt_ */

#undef iwork


