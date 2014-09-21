/* macedt.f -- translated by f2c (version 20100827).
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
/*  PROGRAM TO EDIT MACRO OR MACROWRK PDS FILE DATA                     * */
/*  VERSION : SRAC95 FOR UNIX                                           * */
/* *********************************************************************** */

/* Subroutine */ int macedt_(char *dirnam, integer *iout, integer *iprn, char 
	*memnam, integer *ng, real *xsec, integer *minsg, integer *maxsg, 
	real *scat, real *delay, ftnlen dirnam_len, ftnlen memnam_len)
{
    /* Format strings */
    static char fmt_7000[] = "(\002 \002,\002MACEDT\002,114(\002=\002))";
    static char fmt_6000[] = "(\002 \002,\002   G  \002,\002 PRODUCTION"
	    " \002,\002  FISSION   \002,\002  CAPTURE   \002,\002 ABSORPTION"
	    " \002,\002 FISS.SPCTR \002,\002 DIFFUSION1 \002,\002 DIFFUSION2"
	    " \002,\002   TOTAL    \002,\002 ACTIVATION \002)";
    static char fmt_6010[] = "(\002 \002,i4,2x,1p10e12.5,/,7x,1p10e12.5)";
    static char fmt_6020[] = "(\002 \002,\002  G/G' \002,10(4x,i4,4x),10(/,8"
	    "x,10(4x,i4,4x)))";
    static char fmt_6030[] = "(\002 \002,i4,2x,1p10e12.5,10(/,7x,1p10e12.5))";
    static char fmt_6040[] = "(\002 \002,\002  G/J  \002,10(4x,i4,4x),10(/,8"
	    "x,10(4x,i4,4x)))";
    static char fmt_7010[] = "(\002 \002,114(\002=\002),\002MACEDT\002)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);

    /* Local variables */
    static integer i__, j, n;
    static real x, d1, d2;
    static integer ic, ig, ir, igg, irc, lgv, lss, nfam, leng;
    static real absp;
    static char ptag[1];
    static real xact;
    static integer llgv[107];
    static real fiss, prod;
    static integer llss[107];
    static real totl;
    static integer igflg, ixflg;
    extern /* Subroutine */ int pdsin_(char *, char *, real *, integer *, 
	    integer *, integer *, ftnlen, ftnlen);
    static real wscat[11449]	/* was [107][107] */;
#define iwork ((integer *)&wkpds_1)
    static char member[8];
    static integer igstop, igstrt;

    /* Fortran I/O blocks */
    static cilist io___2 = { 0, 0, 0, 0, 0 };
    static cilist io___3 = { 0, 6, 0, 0, 0 };
    static cilist io___18 = { 0, 0, 0, 0, 0 };
    static cilist io___19 = { 0, 6, 0, 0, 0 };
    static cilist io___23 = { 0, 0, 0, 0, 0 };
    static cilist io___24 = { 0, 6, 0, 0, 0 };
    static cilist io___35 = { 0, 0, 0, 0, 0 };
    static cilist io___36 = { 0, 6, 0, 0, 0 };
    static cilist io___38 = { 0, 0, 0, 0, 0 };
    static cilist io___39 = { 0, 6, 0, 0, 0 };
    static cilist io___40 = { 0, 0, 0, 0, 0 };
    static cilist io___41 = { 0, 0, 0, fmt_7000, 0 };
    static cilist io___42 = { 0, 0, 0, 0, 0 };
    static cilist io___43 = { 0, 0, 0, 0, 0 };
    static cilist io___44 = { 0, 0, 0, 0, 0 };
    static cilist io___45 = { 0, 0, 0, 0, 0 };
    static cilist io___46 = { 0, 0, 0, 0, 0 };
    static cilist io___47 = { 0, 0, 0, 0, 0 };
    static cilist io___48 = { 0, 0, 0, 0, 0 };
    static cilist io___49 = { 0, 0, 0, 0, 0 };
    static cilist io___50 = { 0, 0, 0, 0, 0 };
    static cilist io___51 = { 0, 0, 0, fmt_6000, 0 };
    static cilist io___52 = { 0, 0, 0, fmt_6010, 0 };
    static cilist io___54 = { 0, 0, 0, 0, 0 };
    static cilist io___55 = { 0, 0, 0, 0, 0 };
    static cilist io___56 = { 0, 0, 0, 0, 0 };
    static cilist io___57 = { 0, 0, 0, 0, 0 };
    static cilist io___58 = { 0, 0, 0, fmt_6020, 0 };
    static cilist io___59 = { 0, 0, 0, fmt_6030, 0 };
    static cilist io___60 = { 0, 0, 0, 0, 0 };
    static cilist io___61 = { 0, 0, 0, 0, 0 };
    static cilist io___62 = { 0, 0, 0, 0, 0 };
    static cilist io___63 = { 0, 0, 0, 0, 0 };
    static cilist io___64 = { 0, 0, 0, 0, 0 };
    static cilist io___65 = { 0, 0, 0, fmt_6040, 0 };
    static cilist io___66 = { 0, 0, 0, fmt_6010, 0 };
    static cilist io___67 = { 0, 0, 0, 0, 0 };
    static cilist io___68 = { 0, 0, 0, 0, 0 };
    static cilist io___69 = { 0, 0, 0, 0, 0 };
    static cilist io___70 = { 0, 0, 0, 0, 0 };
    static cilist io___71 = { 0, 0, 0, fmt_6040, 0 };
    static cilist io___72 = { 0, 0, 0, fmt_6010, 0 };
    static cilist io___73 = { 0, 0, 0, 0, 0 };
    static cilist io___74 = { 0, 0, 0, 0, 0 };
    static cilist io___75 = { 0, 0, 0, 0, 0 };
    static cilist io___76 = { 0, 0, 0, 0, 0 };
    static cilist io___77 = { 0, 0, 0, fmt_6040, 0 };
    static cilist io___78 = { 0, 0, 0, fmt_6010, 0 };
    static cilist io___79 = { 0, 0, 0, 0, 0 };
    static cilist io___80 = { 0, 0, 0, 0, 0 };
    static cilist io___81 = { 0, 0, 0, fmt_7010, 0 };
    static cilist io___82 = { 0, 0, 0, 0, 0 };



/* ============================== FOR MAIN =============================== */
/* DEL  PARAMETER (MAXNG=107, MAXXS=10, MAXUP=48) */
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
/* DEL  PARAMETER  (MAXWRK=10000) */
/* ------------------------------ INPUT ---------------------------------- */
/*     DIRNAM     : DIRECTORY NAME (A72) OF PDS : /XXX/XXX/MACRO01 */
/*     IOUT       : LOGICAL DEVICE FOR OUTPUT */
/*     IPRN       : =0(NO PRINT), =1(PRINT OUT IN DEVICE IOUT) */
/*     MEMNAM     : PDS MEMBER NAME TO EDIT(A8) */
/*     NG         : NUMBER OF ENERGY GROUPS CORRESPONDING TO INPUT */
/*                  MACRO MEMBER NAME */
/* ------------------------------ OUTPUT --------------------------------- */
/*     XSEC(G,I)  : MACROSCOPIC XS OF XS-TYPE:I, ENERGY GROUP:G */
/*                  I=1 : PRODUCTION */
/*                  I=2 : FISSION */
/*                  I=3 : CAPTURE */
/*                  I=4 : ABSORPTION */
/*                  I=5 : FISSION SPECTRUM (X) */
/*                  I=6 : DIFFUSION COEFFICIENT (D1) */
/*                  I=7 : DIFFUSION COEFFICIENT (D2) */
/*                  I=8 : TOTAL (ABSORPTION + SCATTERING + N,2N) OR */
/*                        TRANSPORT XS (DEPEND ON MEMBER NAME) */
/*                  I=9 : ACTIVATION XS */
/*     MINSG      : MIN. GROUP OF UP-SCATTERING (ALLOW MINSG.LE.0) */
/*     MAXSG      : MAX. GROUP OF DOWN-SCATTERING (ALLOW MAXSG.GT.NG) */
/*     SCAT(G,G') : SCATTERING MATRIX (G => G') */
/*        PTAG=0,2,4 ; P0 SCATTERING MATRIX + 2*(N,2N MATRIX) */
/*        PTAG=1,3   : P1 SCATTERING MATRIX * 3.0 */
/*        PTAG=N,M   ; (N,2N) SCATTERING MATRIX */
/*                     XSEC(G,8) = ABS(G) + SUM-G'(SCAT(G,G')) */
/*                              - SUM-G'(SN2N(G,G')) */
/*   DELAY(J,G,I) : DELAYED NEUTRON DATA FOR FAMILY J, ENERGY G */
/*                  I=1 : DELAYED BETA(J)*DELAYED-NYU.SIGF(G) */
/*                  I=2 : DELAYED NEUTRON FISSION SPECTRUM */
/*                  I=3 : DELAYED BETA(J)*DELAYED-NYU.SIGF(G)/DECAY CNST */
/* ----------------------------------------------------------------------- */
    /* Parameter adjustments */
    delay -= 1621;
    scat -= -5135;
    xsec -= 108;

    /* Function Body */
    if (*ng > 107) {
	io___2.ciunit = *iout;
	s_wsle(&io___2);
	do_lio(&c__9, &c__1, " ERROR(MACEDT): NUMBER OF ENERGY GROUPS(=", (
		ftnlen)41);
	do_lio(&c__3, &c__1, (char *)&(*ng), (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ") IS GREATER THAN THE SET VALUE(=", (ftnlen)33);
	do_lio(&c__3, &c__1, (char *)&c__107, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ")", (ftnlen)1);
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___3);
	    do_lio(&c__9, &c__1, " ERROR(MACEDT): NUMBER OF ENERGY GROUPS(=", 
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
    igflg = 1;
    ixflg = 0;
    *(unsigned char *)ptag = *(unsigned char *)&memnam[7];
    if (*(unsigned char *)ptag == '0' || *(unsigned char *)ptag == '1') {
	igflg = 0;
    } else if (*(unsigned char *)ptag == 'Y') {
	ixflg = 1;
    } else if (*(unsigned char *)ptag == 'Z') {
	igflg = 0;
	ixflg = 1;
    } else if (*(unsigned char *)ptag == 'N') {
	igflg = 0;
    }
/* ************************** */
/*     ZERO SET            *--------------------------------------------- */
/* ************************** */
    for (i__ = 1; i__ <= 200000; ++i__) {
	wkpds_1.work[i__ - 1] = 0.f;
/* L100: */
    }
    for (ig = 1; ig <= 107; ++ig) {
	if (ixflg == 1) {
	    goto L115;
	}
	llss[ig - 1] = 0;
	llgv[ig - 1] = 0;
	for (n = 1; n <= 10; ++n) {
	    xsec[ig + n * 107] = 0.f;
/* L110: */
	}
	if (ixflg == 0) {
	    goto L125;
	}
L115:
	for (j = 1; j <= 15; ++j) {
	    delay[j + (ig + 107) * 15] = 0.f;
	    delay[j + (ig + 214) * 15] = 0.f;
	    delay[j + (ig + 321) * 15] = 0.f;
/* L120: */
	}
	if (ixflg == 1) {
	    goto L200;
	}
L125:
	for (igg = 1; igg <= 107; ++igg) {
	    wscat[ig + igg * 107 - 108] = 0.f;
/* L130: */
	}
	for (igg = -48; igg <= 107; ++igg) {
	    scat[ig + igg * 107] = 0.f;
/* L140: */
	}
L200:
	;
    }
/* ************************** */
/*   MACROSCOPIC XS EDIT   *--------------------------------------------- */
/* ************************** */
    if (ixflg != 0) {
	goto L400;
    }
    s_copy(member, memnam, (ftnlen)8, (ftnlen)8);
    pdsin_(dirnam, member, wkpds_1.work, &leng, &irc, iout, (ftnlen)72, (
	    ftnlen)8);
    if (irc != 0) {
	io___18.ciunit = *iout;
	s_wsle(&io___18);
	do_lio(&c__9, &c__1, " ERROR(MACEDT): PDSIN ERROR, CODE=", (ftnlen)34)
		;
	do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___19);
	    do_lio(&c__9, &c__1, " ERROR(MACEDT): PDSIN ERROR, CODE=", (
		    ftnlen)34);
	    do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	    e_wsle();
	}
	s_stop("", (ftnlen)0);
    }
    ic = 0;
    i__1 = *ng;
    for (ig = 1; ig <= i__1; ++ig) {
	for (n = 1; n <= 10; ++n) {
	    xsec[ig + n * 107] = wkpds_1.work[ic + n - 1];
/* L310: */
	}
	lss = iwork[ic];
	lgv = iwork[ic + 1];
	if (lgv == 0) {
	    io___23.ciunit = *iout;
	    s_wsle(&io___23);
	    do_lio(&c__9, &c__1, " CAUTION(MACEDT): LGV=0 FOR IG=", (ftnlen)
		    31);
	    do_lio(&c__3, &c__1, (char *)&ig, (ftnlen)sizeof(integer));
	    e_wsle();
	    if (*iout != 6) {
		s_wsle(&io___24);
		do_lio(&c__9, &c__1, " CAUTION(MACEDT): LGV=0 FOR IG=", (
			ftnlen)31);
		do_lio(&c__3, &c__1, (char *)&ig, (ftnlen)sizeof(integer));
		e_wsle();
	    }
	}
	if (lgv > 0) {
	    llss[ig - 1] = lss;
	    llgv[ig - 1] = lgv;
	    i__2 = lgv;
	    for (igg = 1; igg <= i__2; ++igg) {
		wscat[ig + igg * 107 - 108] = wkpds_1.work[ic + 10 + igg - 1];
/* L320: */
	    }
	}
	ic = ic + 10 + lgv;
/* L300: */
    }
    i__1 = *ng;
    for (ig = 1; ig <= i__1; ++ig) {
	xact = xsec[ig + 321];
	fiss = xsec[ig + 428];
	prod = xsec[ig + 535];
	totl = xsec[ig + 642];
	x = xsec[ig + 749];
	d1 = xsec[ig + 856];
	d2 = xsec[ig + 963];
	absp = xsec[ig + 1070];
	xsec[ig + 107] = prod;
	xsec[ig + 214] = fiss;
	xsec[ig + 321] = absp - fiss;
	xsec[ig + 428] = absp;
	xsec[ig + 535] = x;
	xsec[ig + 642] = d1;
	xsec[ig + 749] = d2;
	xsec[ig + 856] = totl;
	xsec[ig + 963] = xact;
/* L330: */
    }

/* ----- SCATTERING MATRIX ----------------------------------------------- */

    *minsg = 1;
    *maxsg = *ng;
    i__1 = *ng;
    for (ig = 1; ig <= i__1; ++ig) {
	igstrt = ig - llss[ig - 1] + 1;
	igstop = ig + llgv[ig - 1] - llss[ig - 1];
	if (igstrt < *minsg) {
	    *minsg = igstrt;
	}
	if (igstop > *maxsg) {
	    *maxsg = igstop;
	}
	i__2 = llgv[ig - 1];
	for (igg = 1; igg <= i__2; ++igg) {
	    scat[ig + (igstrt + igg - 1) * 107] = wscat[ig + igg * 107 - 108];
/* L350: */
	}
/* L340: */
    }
/* ************************** */
/*  DELAYED NEUTRON DATA   *--------------------------------------------- */
/* ************************** */
L400:
    if (ixflg != 1) {
	goto L1000;
    }
    s_copy(member, memnam, (ftnlen)8, (ftnlen)8);
    pdsin_(dirnam, member, wkpds_1.work, &leng, &irc, iout, (ftnlen)72, (
	    ftnlen)8);
    if (irc != 0) {
	io___35.ciunit = *iout;
	s_wsle(&io___35);
	do_lio(&c__9, &c__1, " ERROR(MACEDT): PDSIN ERROR, CODE=", (ftnlen)34)
		;
	do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___36);
	    do_lio(&c__9, &c__1, " ERROR(MACEDT): PDSIN ERROR, CODE=", (
		    ftnlen)34);
	    do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	    e_wsle();
	}
	s_stop("", (ftnlen)0);
    }
    nfam = leng / *ng / 3;
    if (nfam != 6 && nfam != 15) {
	io___38.ciunit = *iout;
	s_wsle(&io___38);
	do_lio(&c__9, &c__1, " ERROR(MACEDT): NUMBER OF DELAYED NEUTRON ", (
		ftnlen)42);
	do_lio(&c__9, &c__1, "FAMILY(=", (ftnlen)8);
	do_lio(&c__3, &c__1, (char *)&nfam, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ") IS INVALID", (ftnlen)12);
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___39);
	    do_lio(&c__9, &c__1, " ERROR(MACEDT): NUMBER OF DELAYED NEUTRON ",
		     (ftnlen)42);
	    do_lio(&c__9, &c__1, "FAMILY(=", (ftnlen)8);
	    do_lio(&c__3, &c__1, (char *)&nfam, (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, ") IS INVALID", (ftnlen)12);
	    e_wsle();
	}
	s_stop("", (ftnlen)0);
    }
    i__1 = *ng;
    for (ig = 1; ig <= i__1; ++ig) {
	i__2 = nfam;
	for (j = 1; j <= i__2; ++j) {
	    ic = (ig - 1) * nfam + j;
	    delay[j + (ig + 107) * 15] = wkpds_1.work[ic - 1];
	    delay[j + (ig + 214) * 15] = wkpds_1.work[*ng * nfam + ic - 1];
	    delay[j + (ig + 321) * 15] = wkpds_1.work[(*ng << 1) * nfam + ic 
		    - 1];
/* L410: */
	}
    }
/* ************************** */
/*      PRINT OUT          *--------------------------------------------- */
/* ************************** */
L1000:
    if (*iprn == 0) {
	goto L9000;
    }
    io___40.ciunit = *iout;
    s_wsle(&io___40);
    e_wsle();
    io___41.ciunit = *iout;
    s_wsfe(&io___41);
    e_wsfe();
    io___42.ciunit = *iout;
    s_wsle(&io___42);
    e_wsle();
    io___43.ciunit = *iout;
    s_wsle(&io___43);
    do_lio(&c__9, &c__1, "   ********** MEMBER NAME = ", (ftnlen)28);
    do_lio(&c__9, &c__1, memnam, (ftnlen)8);
    do_lio(&c__9, &c__1, " **********", (ftnlen)11);
    e_wsle();
    io___44.ciunit = *iout;
    s_wsle(&io___44);
    e_wsle();
    io___45.ciunit = *iout;
    s_wsle(&io___45);
    do_lio(&c__9, &c__1, "   NG    = ", (ftnlen)11);
    do_lio(&c__3, &c__1, (char *)&(*ng), (ftnlen)sizeof(integer));
    e_wsle();
    io___46.ciunit = *iout;
    s_wsle(&io___46);
    do_lio(&c__9, &c__1, "   MINSG = ", (ftnlen)11);
    do_lio(&c__3, &c__1, (char *)&(*minsg), (ftnlen)sizeof(integer));
    e_wsle();
    io___47.ciunit = *iout;
    s_wsle(&io___47);
    do_lio(&c__9, &c__1, "   MAXSG = ", (ftnlen)11);
    do_lio(&c__3, &c__1, (char *)&(*maxsg), (ftnlen)sizeof(integer));
    e_wsle();
    if (ixflg == 0) {
	io___48.ciunit = *iout;
	s_wsle(&io___48);
	e_wsle();
	io___49.ciunit = *iout;
	s_wsle(&io___49);
	do_lio(&c__9, &c__1, "   --- MACROSCPIC CROSS SECTION ---", (ftnlen)
		35);
	e_wsle();
	io___50.ciunit = *iout;
	s_wsle(&io___50);
	e_wsle();
	io___51.ciunit = *iout;
	s_wsfe(&io___51);
	e_wsfe();
	i__2 = *ng;
	for (ig = 1; ig <= i__2; ++ig) {
	    io___52.ciunit = *iout;
	    s_wsfe(&io___52);
	    do_fio(&c__1, (char *)&ig, (ftnlen)sizeof(integer));
	    for (ir = 1; ir <= 9; ++ir) {
		do_fio(&c__1, (char *)&xsec[ig + ir * 107], (ftnlen)sizeof(
			real));
	    }
	    e_wsfe();
/* L1010: */
	}
	io___54.ciunit = *iout;
	s_wsle(&io___54);
	e_wsle();
	io___55.ciunit = *iout;
	s_wsle(&io___55);
	e_wsle();
	io___56.ciunit = *iout;
	s_wsle(&io___56);
	do_lio(&c__9, &c__1, "   --- SCATTERING MATRIX(G=>G') ---", (ftnlen)
		35);
	e_wsle();
	io___57.ciunit = *iout;
	s_wsle(&io___57);
	e_wsle();
	io___58.ciunit = *iout;
	s_wsfe(&io___58);
	i__2 = *maxsg;
	for (i__ = *minsg; i__ <= i__2; ++i__) {
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	}
	e_wsfe();
	i__2 = *ng;
	for (ig = 1; ig <= i__2; ++ig) {
	    io___59.ciunit = *iout;
	    s_wsfe(&io___59);
	    do_fio(&c__1, (char *)&ig, (ftnlen)sizeof(integer));
	    i__1 = *maxsg;
	    for (igg = *minsg; igg <= i__1; ++igg) {
		do_fio(&c__1, (char *)&scat[ig + igg * 107], (ftnlen)sizeof(
			real));
	    }
	    e_wsfe();
/* L1020: */
	}
	io___60.ciunit = *iout;
	s_wsle(&io___60);
	e_wsle();
    } else {
	io___61.ciunit = *iout;
	s_wsle(&io___61);
	e_wsle();
	io___62.ciunit = *iout;
	s_wsle(&io___62);
	e_wsle();
	io___63.ciunit = *iout;
	s_wsle(&io___63);
	do_lio(&c__9, &c__1, "   --- DELAYED NEUTRON DATA (D-PRODUCTION) --- "
		, (ftnlen)47);
	e_wsle();
	io___64.ciunit = *iout;
	s_wsle(&io___64);
	e_wsle();
	io___65.ciunit = *iout;
	s_wsfe(&io___65);
	i__2 = nfam;
	for (j = 1; j <= i__2; ++j) {
	    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	}
	e_wsfe();
	i__2 = *ng;
	for (ig = 1; ig <= i__2; ++ig) {
	    io___66.ciunit = *iout;
	    s_wsfe(&io___66);
	    do_fio(&c__1, (char *)&ig, (ftnlen)sizeof(integer));
	    i__1 = nfam;
	    for (j = 1; j <= i__1; ++j) {
		do_fio(&c__1, (char *)&delay[j + (ig + 107) * 15], (ftnlen)
			sizeof(real));
	    }
	    e_wsfe();
/* L1030: */
	}
	io___67.ciunit = *iout;
	s_wsle(&io___67);
	e_wsle();
	io___68.ciunit = *iout;
	s_wsle(&io___68);
	e_wsle();
	io___69.ciunit = *iout;
	s_wsle(&io___69);
	do_lio(&c__9, &c__1, "   --- DELAYED NEUTRON DATA (D-FISS.SPECTR) --"
		"- ", (ftnlen)48);
	e_wsle();
	io___70.ciunit = *iout;
	s_wsle(&io___70);
	e_wsle();
	io___71.ciunit = *iout;
	s_wsfe(&io___71);
	i__2 = nfam;
	for (j = 1; j <= i__2; ++j) {
	    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	}
	e_wsfe();
	i__2 = *ng;
	for (ig = 1; ig <= i__2; ++ig) {
	    io___72.ciunit = *iout;
	    s_wsfe(&io___72);
	    do_fio(&c__1, (char *)&ig, (ftnlen)sizeof(integer));
	    i__1 = nfam;
	    for (j = 1; j <= i__1; ++j) {
		do_fio(&c__1, (char *)&delay[j + (ig + 214) * 15], (ftnlen)
			sizeof(real));
	    }
	    e_wsfe();
/* L1040: */
	}
	io___73.ciunit = *iout;
	s_wsle(&io___73);
	e_wsle();
	io___74.ciunit = *iout;
	s_wsle(&io___74);
	e_wsle();
	io___75.ciunit = *iout;
	s_wsle(&io___75);
	do_lio(&c__9, &c__1, "   --- DELAYED NEUTRON DATA (INV.DECAY CST) --"
		"- ", (ftnlen)48);
	e_wsle();
	io___76.ciunit = *iout;
	s_wsle(&io___76);
	e_wsle();
	io___77.ciunit = *iout;
	s_wsfe(&io___77);
	i__2 = nfam;
	for (j = 1; j <= i__2; ++j) {
	    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	}
	e_wsfe();
	i__2 = *ng;
	for (ig = 1; ig <= i__2; ++ig) {
	    io___78.ciunit = *iout;
	    s_wsfe(&io___78);
	    do_fio(&c__1, (char *)&ig, (ftnlen)sizeof(integer));
	    i__1 = nfam;
	    for (j = 1; j <= i__1; ++j) {
		do_fio(&c__1, (char *)&delay[j + (ig + 321) * 15], (ftnlen)
			sizeof(real));
	    }
	    e_wsfe();
/* L1050: */
	}
	io___79.ciunit = *iout;
	s_wsle(&io___79);
	e_wsle();
    }
    io___80.ciunit = *iout;
    s_wsle(&io___80);
    e_wsle();
    io___81.ciunit = *iout;
    s_wsfe(&io___81);
    e_wsfe();
    io___82.ciunit = *iout;
    s_wsle(&io___82);
    e_wsle();

L9000:
    return 0;
} /* macedt_ */

#undef iwork


