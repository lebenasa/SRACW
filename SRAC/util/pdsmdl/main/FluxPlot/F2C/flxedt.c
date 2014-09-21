/* flxedt.f -- translated by f2c (version 20100827).
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
static integer c__300 = 300;

/* *********************************************************************** */
/*  PROGRAM TO EDIT FLUX FROM FLUX-PDS FILE                             * */
/*  VERSION : SRAC95 FOR UNIX                                           * */
/* *********************************************************************** */

/* Subroutine */ int flxedt_(char *dirnam, integer *iout, integer *iprn, char 
	*memnam, integer *ng, integer *nrr, real *flx1, real *volr, ftnlen 
	dirnam_len, ftnlen memnam_len)
{
    /* Format strings */
    static char fmt_7000[] = "(\002 \002,\002FLXEDT\002,114(\002=\002))";
    static char fmt_6000[] = "(\002 \002,\002REGION \002,10(4x,i4,4x):/(8x,1"
	    "0(4x,i4,4x)))";
    static char fmt_6010[] = "(\002 \002,6x,1p10e12.5:/(7x,1p10e12.5))";
    static char fmt_7010[] = "(\002 \002,114(\002=\002),\002FLXEDT\002)";
    static char fmt_6020[] = "(\002 \002,\002  G/R  \002,10(4x,i4,4x):/(8x,1"
	    "0(4x,i4,4x)))";
    static char fmt_6030[] = "(\002 \002,i4,2x,1p10e12.5:/(7x,1p10e12.5))";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);

    /* Local variables */
    static integer i__, j, k, ig, irc, leng;
    extern /* Subroutine */ int pdsin_(char *, char *, real *, integer *, 
	    integer *, integer *, ftnlen, ftnlen);
#define iwork ((integer *)&wkpds_1)
    static char member[8];

    /* Fortran I/O blocks */
    static cilist io___2 = { 0, 0, 0, 0, 0 };
    static cilist io___3 = { 0, 6, 0, 0, 0 };
    static cilist io___9 = { 0, 0, 0, 0, 0 };
    static cilist io___10 = { 0, 6, 0, 0, 0 };
    static cilist io___11 = { 0, 0, 0, 0, 0 };
    static cilist io___12 = { 0, 6, 0, 0, 0 };
    static cilist io___14 = { 0, 0, 0, 0, 0 };
    static cilist io___15 = { 0, 6, 0, 0, 0 };
    static cilist io___16 = { 0, 0, 0, 0, 0 };
    static cilist io___17 = { 0, 6, 0, 0, 0 };
    static cilist io___18 = { 0, 0, 0, 0, 0 };
    static cilist io___19 = { 0, 0, 0, fmt_7000, 0 };
    static cilist io___20 = { 0, 0, 0, 0, 0 };
    static cilist io___21 = { 0, 0, 0, 0, 0 };
    static cilist io___22 = { 0, 0, 0, 0, 0 };
    static cilist io___23 = { 0, 0, 0, 0, 0 };
    static cilist io___24 = { 0, 0, 0, 0, 0 };
    static cilist io___25 = { 0, 0, 0, 0, 0 };
    static cilist io___26 = { 0, 0, 0, fmt_6000, 0 };
    static cilist io___27 = { 0, 0, 0, 0, 0 };
    static cilist io___28 = { 0, 0, 0, fmt_6010, 0 };
    static cilist io___29 = { 0, 0, 0, 0, 0 };
    static cilist io___30 = { 0, 0, 0, 0, 0 };
    static cilist io___31 = { 0, 0, 0, fmt_7010, 0 };
    static cilist io___32 = { 0, 0, 0, 0, 0 };
    static cilist io___33 = { 0, 0, 0, 0, 0 };
    static cilist io___34 = { 0, 0, 0, fmt_7000, 0 };
    static cilist io___35 = { 0, 0, 0, 0, 0 };
    static cilist io___36 = { 0, 0, 0, 0, 0 };
    static cilist io___37 = { 0, 0, 0, 0, 0 };
    static cilist io___38 = { 0, 0, 0, 0, 0 };
    static cilist io___39 = { 0, 0, 0, 0, 0 };
    static cilist io___40 = { 0, 0, 0, 0, 0 };
    static cilist io___41 = { 0, 0, 0, fmt_6020, 0 };
    static cilist io___42 = { 0, 0, 0, 0, 0 };
    static cilist io___44 = { 0, 0, 0, fmt_6030, 0 };
    static cilist io___45 = { 0, 0, 0, 0, 0 };
    static cilist io___46 = { 0, 0, 0, 0, 0 };
    static cilist io___47 = { 0, 0, 0, fmt_7010, 0 };
    static cilist io___48 = { 0, 0, 0, 0, 0 };



/* =========================== FOR MAIN ================================== */
/* DEL  PARAMETER  (MAXNG=107, MAXNR=100) */
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
/* DEL  PARAMETER  (MAXWRK=11000) */
/* -------------------------------INPUT----------------------------------- */
/*     DIRNAM     : DIRECTORY NAME (A72) OF PDS : /XXX/XXX/FLUX01 */
/*     IOUT       : LOGICAL DEVICE FOR OUTPUT */
/*     IPRN       : =0(NO PRINT), =1(PRINT OUT IN DEVICE IOUT) */
/*     MEMNAM     : PDS MEMBER NAME TO EDIT(A8) */
/*     NG         : NUMBER OF ENERGY GROUPS CORRESPONDING TO INPUT */
/*                  FLUX MEMBER NAME */
/* -------------------------------OUTPUT---------------------------------- */
/*     NRR        : NUMBER OF R-REGIONS(IF MEMBER NAME CORRESPONDS TO */
/*                  X-REGION, NRR=1), IF MEMBER NAME = ____SVOL THEN */
/*                  NRR = NUMBER OF S-REGION */
/*     FLX1(G,I)  : NORMAL FLUX DATA (FLUX*DU*VOL) FOR GROUP-G, REGION-I */
/*                  IF MEMBER NAME CORRESPONDS TO X-REGION, FLX1(G,1) */
/*                  INDICATES THE X-REGION SPECTRUM */
/*     VOLR(I)    : VOLUME OF R-REGION WHEN E-TAG = 'F' OR 'T' OR 'A', */
/*                  VOLUME OF T-REGION WHEN E-TAG = 'S' */
/* ----------------------------------------------------------------------- */
/* **************************** */
/* SIZE CHECK & ZERO SETTING *------------------------------------------- */
/* **************************** */
    /* Parameter adjustments */
    --volr;
    flx1 -= 108;

    /* Function Body */
    if (*ng > 107) {
	io___2.ciunit = *iout;
	s_wsle(&io___2);
	do_lio(&c__9, &c__1, " ERROR(FLXEDT): NUMBER OF ENERGY GROUPS(=", (
		ftnlen)41);
	do_lio(&c__3, &c__1, (char *)&(*ng), (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ") IS GREATER THAN THE SET VALUE(=", (ftnlen)33);
	do_lio(&c__3, &c__1, (char *)&c__107, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ")", (ftnlen)1);
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___3);
	    do_lio(&c__9, &c__1, " ERROR(FLXEDT): NUMBER OF ENERGY GROUPS(=", 
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
    for (i__ = 1; i__ <= 200000; ++i__) {
	wkpds_1.work[i__ - 1] = 0.f;
/* L100: */
    }
/* ************************** */
/*     EDIT FLUX DATA      *-------------------------------------------- */
/* ************************** */
    if (s_cmp(memnam + 5, "VOL", (ftnlen)3, (ftnlen)3) == 0) {
	goto L300;
    }
    for (j = 1; j <= 300; ++j) {
	for (i__ = 1; i__ <= 107; ++i__) {
	    flx1[i__ + j * 107] = 0.f;
/* L200: */
	}
    }
    s_copy(member, memnam, (ftnlen)8, (ftnlen)8);
    pdsin_(dirnam, member, wkpds_1.work, &leng, &irc, iout, (ftnlen)72, (
	    ftnlen)8);
    if (irc != 0) {
	io___9.ciunit = *iout;
	s_wsle(&io___9);
	do_lio(&c__9, &c__1, " ERROR(FLXEDT): PDSIN ERROR, CODE=", (ftnlen)34)
		;
	do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___10);
	    do_lio(&c__9, &c__1, " ERROR(FLXEDT): PDSIN ERROR, CODE=", (
		    ftnlen)34);
	    do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	    e_wsle();
	}
	s_stop("", (ftnlen)0);
    }
    *nrr = leng / *ng;
    if (*nrr > 300) {
	io___11.ciunit = *iout;
	s_wsle(&io___11);
	do_lio(&c__9, &c__1, " ERROR(FLXEDT): NUMBER OF R-REGIONS(=", (ftnlen)
		37);
	do_lio(&c__3, &c__1, (char *)&(*nrr), (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ") IS GREATER THAN THE SET VALUE(=", (ftnlen)33);
	do_lio(&c__3, &c__1, (char *)&c__300, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ")", (ftnlen)1);
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___12);
	    do_lio(&c__9, &c__1, " ERROR(FLXEDT): NUMBER OF R-REGIONS(=", (
		    ftnlen)37);
	    do_lio(&c__3, &c__1, (char *)&(*nrr), (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, ") IS GREATER THAN THE SET VALUE(=", (ftnlen)
		    33);
	    do_lio(&c__3, &c__1, (char *)&c__300, (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, ")", (ftnlen)1);
	    e_wsle();
	}
	s_stop("", (ftnlen)0);
    }
    i__1 = *ng;
    for (k = 1; k <= i__1; ++k) {
	i__2 = *nrr;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    flx1[k + i__ * 107] = wkpds_1.work[(k - 1) * *nrr + i__ - 1];
/* L210: */
	}
    }
    goto L1000;
/* ************************** */
/*     REGION VOLUME       *-------------------------------------------- */
/* ************************** */
L300:
    for (j = 1; j <= 300; ++j) {
	volr[j] = 0.f;
/* L310: */
    }
    s_copy(member, memnam, (ftnlen)8, (ftnlen)8);
    pdsin_(dirnam, member, wkpds_1.work, &leng, &irc, iout, (ftnlen)72, (
	    ftnlen)8);
/* mod by okumura (in eigenvalue cal. caseAVOL should be read) */
    if (irc == 1) {
	*(unsigned char *)&member[4] = 'A';
	pdsin_(dirnam, member, wkpds_1.work, &leng, &irc, iout, (ftnlen)72, (
		ftnlen)8);
	if (irc != 0) {
	    io___14.ciunit = *iout;
	    s_wsle(&io___14);
	    do_lio(&c__9, &c__1, " ERROR(FLXEDT): PDSIN ERROR, CODE=", (
		    ftnlen)34);
	    do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	    e_wsle();
	    if (*iout != 6) {
		s_wsle(&io___15);
		do_lio(&c__9, &c__1, " ERROR(FLXEDT): PDSIN ERROR, CODE=", (
			ftnlen)34);
		do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
		e_wsle();
	    }
	    s_stop("", (ftnlen)0);
	}
    } else if (irc != 0) {
	io___16.ciunit = *iout;
	s_wsle(&io___16);
	do_lio(&c__9, &c__1, " ERROR(FLXEDT): PDSIN ERROR, CODE=", (ftnlen)34)
		;
	do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___17);
	    do_lio(&c__9, &c__1, " ERROR(FLXEDT): PDSIN ERROR, CODE=", (
		    ftnlen)34);
	    do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	    e_wsle();
	}
	s_stop("", (ftnlen)0);
    }
    *nrr = leng;
    i__2 = *nrr;
    for (i__ = 1; i__ <= i__2; ++i__) {
	volr[i__] = wkpds_1.work[i__ - 1];
/* L320: */
    }
/* ************************** */
/*     PRINT OUT           *-------------------------------------------- */
/* ************************** */
    if (*iprn == 0) {
	goto L9000;
    }
    io___18.ciunit = *iout;
    s_wsle(&io___18);
    e_wsle();
    io___19.ciunit = *iout;
    s_wsfe(&io___19);
    e_wsfe();
    io___20.ciunit = *iout;
    s_wsle(&io___20);
    e_wsle();
    io___21.ciunit = *iout;
    s_wsle(&io___21);
    do_lio(&c__9, &c__1, "    ***** REGION VOLUME : MEMBER NAME = ", (ftnlen)
	    40);
    do_lio(&c__9, &c__1, memnam, (ftnlen)8);
    do_lio(&c__9, &c__1, " *****", (ftnlen)6);
    e_wsle();
    io___22.ciunit = *iout;
    s_wsle(&io___22);
    e_wsle();
    io___23.ciunit = *iout;
    s_wsle(&io___23);
    do_lio(&c__9, &c__1, "    NG  = ", (ftnlen)10);
    do_lio(&c__3, &c__1, (char *)&(*ng), (ftnlen)sizeof(integer));
    e_wsle();
    io___24.ciunit = *iout;
    s_wsle(&io___24);
    do_lio(&c__9, &c__1, "    NRR = ", (ftnlen)10);
    do_lio(&c__3, &c__1, (char *)&(*nrr), (ftnlen)sizeof(integer));
    e_wsle();
    io___25.ciunit = *iout;
    s_wsle(&io___25);
    e_wsle();
    io___26.ciunit = *iout;
    s_wsfe(&io___26);
    i__2 = *nrr;
    for (i__ = 1; i__ <= i__2; ++i__) {
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
    }
    e_wsfe();
    io___27.ciunit = *iout;
    s_wsle(&io___27);
    e_wsle();
    io___28.ciunit = *iout;
    s_wsfe(&io___28);
    i__2 = *nrr;
    for (i__ = 1; i__ <= i__2; ++i__) {
	do_fio(&c__1, (char *)&volr[i__], (ftnlen)sizeof(real));
    }
    e_wsfe();
    io___29.ciunit = *iout;
    s_wsle(&io___29);
    e_wsle();
    io___30.ciunit = *iout;
    s_wsle(&io___30);
    e_wsle();
    io___31.ciunit = *iout;
    s_wsfe(&io___31);
    e_wsfe();
    io___32.ciunit = *iout;
    s_wsle(&io___32);
    e_wsle();
    goto L9000;
L1000:
    if (*iprn == 0) {
	goto L9000;
    }
    io___33.ciunit = *iout;
    s_wsle(&io___33);
    e_wsle();
    io___34.ciunit = *iout;
    s_wsfe(&io___34);
    e_wsfe();
    io___35.ciunit = *iout;
    s_wsle(&io___35);
    e_wsle();
    io___36.ciunit = *iout;
    s_wsle(&io___36);
    do_lio(&c__9, &c__1, "    ***** FLUX OF MEMBER NAME = ", (ftnlen)32);
    do_lio(&c__9, &c__1, memnam, (ftnlen)8);
    do_lio(&c__9, &c__1, " *****", (ftnlen)6);
    e_wsle();
    io___37.ciunit = *iout;
    s_wsle(&io___37);
    e_wsle();
    io___38.ciunit = *iout;
    s_wsle(&io___38);
    do_lio(&c__9, &c__1, "    NG  = ", (ftnlen)10);
    do_lio(&c__3, &c__1, (char *)&(*ng), (ftnlen)sizeof(integer));
    e_wsle();
    io___39.ciunit = *iout;
    s_wsle(&io___39);
    do_lio(&c__9, &c__1, "    NRR = ", (ftnlen)10);
    do_lio(&c__3, &c__1, (char *)&(*nrr), (ftnlen)sizeof(integer));
    e_wsle();
    io___40.ciunit = *iout;
    s_wsle(&io___40);
    e_wsle();
    io___41.ciunit = *iout;
    s_wsfe(&io___41);
    i__2 = *nrr;
    for (i__ = 1; i__ <= i__2; ++i__) {
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
    }
    e_wsfe();
    io___42.ciunit = *iout;
    s_wsle(&io___42);
    e_wsle();
    i__2 = *ng;
    for (ig = 1; ig <= i__2; ++ig) {
	io___44.ciunit = *iout;
	s_wsfe(&io___44);
	do_fio(&c__1, (char *)&ig, (ftnlen)sizeof(integer));
	i__1 = *nrr;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&flx1[ig + i__ * 107], (ftnlen)sizeof(real))
		    ;
	}
	e_wsfe();
/* L1010: */
    }
    io___45.ciunit = *iout;
    s_wsle(&io___45);
    e_wsle();
    io___46.ciunit = *iout;
    s_wsle(&io___46);
    e_wsle();
    io___47.ciunit = *iout;
    s_wsfe(&io___47);
    e_wsfe();
    io___48.ciunit = *iout;
    s_wsle(&io___48);
    e_wsle();

L9000:
    return 0;
} /* flxedt_ */

#undef iwork


