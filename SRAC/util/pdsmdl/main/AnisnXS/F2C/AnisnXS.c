/* AnisnXS.f -- translated by f2c (version 20100827).
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
static integer c__3 = 3;
static integer c__50 = 50;

/* *********************************************************************** */
/* ANISNXS : MAIN PROGRAM TO FORM ANISN,MORSE,GMVP TYPE BINARY XS */
/*           LIBRARY FROM SRAC-PDS FILES */
/* *********************************************************************** */
/* ### COPYED FROM ENGEDT/MACEDT */
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
/* Main program */ int MAIN__(void)
{
    /* Format strings */
    static char fmt_6000[] = "(3x,1p5e13.5)";
    static char fmt_6110[] = "(1x,\002!!! WARNING: NEGATIVE \002,a,\002XS WA"
	    "S DETECTED IN GROUP\002,i3)";
    static char fmt_6120[] = "(1x,\002!!! WARNING: NEGATIVE \002,a,\002XS WA"
	    "S DETECTED : \002,\002FROM GROUP \002,i3,\002 TO GROUP \002,i3)";
    static char fmt_6130[] = "(1x,\002!!! WARNING: NEGATIVE SCATTERIG XS ("
	    "=\002,1pe12.5,\002) WAS SET TO ZERO.\002,/,\002     IT WAS ADDED"
	    " TO TOTAL(TRANSPORT) XS OF GROUP \002,i3)";
    static char fmt_6200[] = "(1x,\002IGG=\002,i3,2x,1p220e12.5:/(10x,1p220e"
	    "12.5:))";

    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    real r__1;
    static real equiv_0[1000000];

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfe(cilist *), e_wsfe(void), s_rsle(cilist *), e_rsle(void), 
	    s_cmp(char *, char *, ftnlen, ftnlen), s_wsue(cilist *), do_uio(
	    integer *, char *, ftnlen), e_wsue(void);

    /* Local variables */
    static integer i__, k, l, m, ig;
    static real en[108];
    static integer ng;
    static real wt[108];
    static integer igg, idm[50], irc;
    static real scm[1144900]	/* was [107][107][2][50] */;
    static integer nin, ldw, lgv, npl, iht, lup, lss;
    static real sum, xsm[32100]	/* was [107][3][2][50] */;
    static integer nds1, npl1, imac;
    static char etag[1];
    static integer leng, nbin, isgg;
    static real scat[16692]	/* was [107][156] */;
    static char ptag[1*6*2];
    static real xkai[5350]	/* was [107][50] */;
    static integer itbl, idum, nmat;
    static real xsec[1070]	/* was [107][10] */;
    static integer note, lsct, iprn, itmp, ipos, iout;
#define work (equiv_0)
    static integer nout1, nout2;
    static real delay[4815]	/* was [15][107][3] */;
    static integer msave;
    extern /* Subroutine */ int pdsin_(char *, char *, real *, integer *, 
	    integer *, integer *, ftnlen, ftnlen);
    static integer minsg, maxsg;
    static char title[48];
    static integer mcopt;
#define iwork ((integer *)equiv_0)
    static integer mxdws, mxups;
    extern /* Subroutine */ int macedt_(char *, integer *, integer *, char *, 
	    integer *, real *, integer *, integer *, real *, real *, ftnlen, 
	    ftnlen);
    static integer idebug;
    extern /* Subroutine */ int engedt_(char *, integer *, integer *, char *, 
	    integer *, real *, real *, ftnlen, ftnlen);
    static char member[8*50], dirnam[72], memnam[8];
    extern /* Subroutine */ int uioset_(void);

    /* Fortran I/O blocks */
    static cilist io___10 = { 0, 0, 0, 0, 0 };
    static cilist io___11 = { 0, 0, 0, 0, 0 };
    static cilist io___12 = { 0, 0, 0, 0, 0 };
    static cilist io___13 = { 0, 0, 0, 0, 0 };
    static cilist io___14 = { 0, 0, 0, 0, 0 };
    static cilist io___15 = { 0, 0, 0, 0, 0 };
    static cilist io___16 = { 0, 0, 0, 0, 0 };
    static cilist io___17 = { 0, 0, 0, 0, 0 };
    static cilist io___18 = { 0, 0, 0, 0, 0 };
    static cilist io___19 = { 0, 0, 0, 0, 0 };
    static cilist io___20 = { 0, 0, 0, 0, 0 };
    static cilist io___21 = { 0, 0, 0, 0, 0 };
    static cilist io___24 = { 0, 0, 1, "(A72)", 0 };
    static cilist io___31 = { 0, 0, 0, 0, 0 };
    static cilist io___35 = { 0, 0, 0, 0, 0 };
    static cilist io___36 = { 0, 0, 0, 0, 0 };
    static cilist io___37 = { 0, 0, 0, 0, 0 };
    static cilist io___38 = { 0, 0, 0, 0, 0 };
    static cilist io___39 = { 0, 0, 0, fmt_6000, 0 };
    static cilist io___41 = { 0, 0, 0, 0, 0 };
    static cilist io___42 = { 0, 0, 0, 0, 0 };
    static cilist io___47 = { 0, 0, 0, 0, 0 };
    static cilist io___48 = { 0, 0, 0, 0, 0 };
    static cilist io___49 = { 0, 0, 0, 0, 0 };
    static cilist io___50 = { 0, 0, 0, 0, 0 };
    static cilist io___51 = { 0, 0, 0, 0, 0 };
    static cilist io___52 = { 0, 0, 0, 0, 0 };
    static cilist io___55 = { 0, 0, 1, "(A8,I10)", 0 };
    static cilist io___57 = { 0, 0, 0, 0, 0 };
    static cilist io___64 = { 0, 0, 0, 0, 0 };
    static cilist io___70 = { 0, 0, 0, 0, 0 };
    static cilist io___71 = { 0, 0, 0, 0, 0 };
    static cilist io___72 = { 0, 0, 0, 0, 0 };
    static cilist io___78 = { 0, 0, 0, 0, 0 };
    static cilist io___79 = { 0, 0, 0, 0, 0 };
    static cilist io___80 = { 0, 0, 0, 0, 0 };
    static cilist io___81 = { 0, 0, 0, 0, 0 };
    static cilist io___82 = { 0, 0, 0, 0, 0 };
    static cilist io___83 = { 0, 0, 0, 0, 0 };
    static cilist io___84 = { 0, 0, 0, 0, 0 };
    static cilist io___85 = { 0, 0, 0, 0, 0 };
    static cilist io___86 = { 0, 0, 0, 0, 0 };
    static cilist io___87 = { 0, 0, 0, 0, 0 };
    static cilist io___88 = { 0, 0, 0, 0, 0 };
    static cilist io___89 = { 0, 0, 0, 0, 0 };
    static cilist io___95 = { 0, 0, 0, 0, 0 };
    static cilist io___96 = { 0, 0, 0, 0, 0 };
    static cilist io___97 = { 0, 0, 0, 0, 0 };
    static cilist io___98 = { 0, 0, 0, 0, 0 };
    static cilist io___100 = { 0, 0, 0, 0, 0 };
    static cilist io___101 = { 0, 0, 0, fmt_6000, 0 };
    static cilist io___102 = { 0, 0, 0, 0, 0 };
    static cilist io___104 = { 0, 0, 0, fmt_6110, 0 };
    static cilist io___105 = { 0, 0, 0, fmt_6110, 0 };
    static cilist io___106 = { 0, 0, 0, fmt_6110, 0 };
    static cilist io___110 = { 0, 0, 0, fmt_6120, 0 };
    static cilist io___111 = { 0, 0, 0, fmt_6130, 0 };
    static cilist io___114 = { 0, 0, 0, fmt_6200, 0 };
    static cilist io___116 = { 0, 0, 0, 0, 0 };
    static cilist io___117 = { 0, 0, 0, 0, 0 };
    static cilist io___118 = { 0, 0, 0, 0, 0 };
    static cilist io___119 = { 0, 0, 0, 0, 0 };
    static cilist io___120 = { 0, 0, 0, 0, 0 };
    static cilist io___121 = { 0, 0, 0, 0, 0 };


/*     ------------------------------------------------------------------ */
/* *********************************************************************** */
/*  XSM(g,1,L,m)  : absorption XS of m-th material (L-1 order) */
/*  XSM(g,2,L,m)  : production */
/*  XSM(g,3,L,m)  : total/transport */
/*  SCM(g,g',L,m) : scattering matrix (g->g') of m-th material */
/*  XKAI(g,m)     : fission spectrum */
/* ----------------------------------------------------------------------- */
/* *********************************************************************** */
/*     If you change I/O device number, */
/*     Change subroutine (uiount) at the last. */
    nin = 5;
    nout1 = 6;
    nout2 = 99;
    nbin = 1;
    iout = nout1;

    iprn = 1;
    note = 0;

    uioset_();
/* *********************************************************************** */
/* LOGO PRINT (99) */
/* *********************************************************************** */
    io___10.ciunit = nout1;
    s_wsle(&io___10);
    do_lio(&c__9, &c__1, " ********************************************", (
	    ftnlen)45);
    e_wsle();
    io___11.ciunit = nout1;
    s_wsle(&io___11);
    do_lio(&c__9, &c__1, " SRAC UTILITY TO CONVERT MACROSCOPIC XS DATA", (
	    ftnlen)44);
    e_wsle();
    io___12.ciunit = nout1;
    s_wsle(&io___12);
    do_lio(&c__9, &c__1, " OF PDS TO ANISN TYPE BINARY LIBRARY DATA", (ftnlen)
	    41);
    e_wsle();
    io___13.ciunit = nout1;
    s_wsle(&io___13);
    do_lio(&c__9, &c__1, " ********************************************", (
	    ftnlen)45);
    e_wsle();
    io___14.ciunit = nout2;
    s_wsle(&io___14);
    do_lio(&c__9, &c__1, " ********************************************", (
	    ftnlen)45);
    e_wsle();
    io___15.ciunit = nout2;
    s_wsle(&io___15);
    do_lio(&c__9, &c__1, " SRAC UTILITY TO CONVERT MACROSCOPIC XS DATA", (
	    ftnlen)44);
    e_wsle();
    io___16.ciunit = nout2;
    s_wsle(&io___16);
    do_lio(&c__9, &c__1, " OF PDS TO ANISN TYPE BINARY LIBRARY DATA", (ftnlen)
	    41);
    e_wsle();
    io___17.ciunit = nout2;
    s_wsle(&io___17);
    do_lio(&c__9, &c__1, " ********************************************", (
	    ftnlen)45);
    e_wsle();
    io___18.ciunit = nout2;
    s_wsle(&io___18);
    do_lio(&c__9, &c__1, " THE BINARY DATA IS AVAILABLE IN ANISN, TWOTRAN", (
	    ftnlen)47);
    do_lio(&c__9, &c__1, " GMVP, MORSE, ETC.", (ftnlen)18);
    e_wsle();
    io___19.ciunit = nout2;
    s_wsle(&io___19);
    do_lio(&c__9, &c__1, " NOTE: ANISN FORMAT DOSE NOT INCLUDE MATERIAL-", (
	    ftnlen)46);
    do_lio(&c__9, &c__1, " DEPENDENT FISSION SPECTRA.", (ftnlen)27);
    e_wsle();
    io___20.ciunit = nout2;
    s_wsle(&io___20);
    do_lio(&c__9, &c__1, " USE THE PRINTED FISSION SPECTRA IF NECESSARY.", (
	    ftnlen)46);
    e_wsle();
    io___21.ciunit = nout2;
    s_wsle(&io___21);
    e_wsle();

/* *********************************************************************** */
/* SET PL-TAG OF SRAC MEMBERS IN MACRO(1) OR MACROWRK(2) */
/* (SET INITIAL CHARACTER DATA) */
/* *********************************************************************** */
    s_copy(title, "                                                ", (ftnlen)
	    48, (ftnlen)48);
    *(unsigned char *)&ptag[0] = '0';
    *(unsigned char *)&ptag[1] = '1';
    *(unsigned char *)&ptag[2] = 'X';
    *(unsigned char *)&ptag[3] = 'X';
    *(unsigned char *)&ptag[4] = 'X';
    *(unsigned char *)&ptag[5] = 'X';

    *(unsigned char *)&ptag[6] = '4';
    *(unsigned char *)&ptag[7] = '3';
    *(unsigned char *)&ptag[8] = '5';
    *(unsigned char *)&ptag[9] = '6';
    *(unsigned char *)&ptag[10] = '7';
    *(unsigned char *)&ptag[11] = '8';
/* *********************************************************************** */
/* READ DIRECTORY NAME OF MACRO/MACROWRK */
/* Check MACRO or MACROWRK */
/* READ ENERGY GROUP STRUCTURE FROM CONTA00[0,2] */
/* *********************************************************************** */
/*     IMAC=1 : MACRO */
/*         =2 : MACROWRK */
    io___24.ciunit = nin;
    i__1 = s_rsfe(&io___24);
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, dirnam, (ftnlen)72);
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = e_rsfe();
    if (i__1 != 0) {
	goto L9999;
    }
    s_copy(memnam, "CONTA000", (ftnlen)8, (ftnlen)8);
    pdsin_(dirnam, memnam, work, &leng, &irc, &iout, (ftnlen)72, (ftnlen)8);
    if (irc == 0) {
	imac = 1;
	*(unsigned char *)etag = 'A';
	goto L100;
    }

    s_copy(memnam, "CONTA002", (ftnlen)8, (ftnlen)8);
    pdsin_(dirnam, memnam, work, &leng, &irc, &iout, (ftnlen)72, (ftnlen)8);
    if (irc == 0) {
	imac = 2;
	*(unsigned char *)etag = 'A';
	goto L100;
    }

    s_copy(memnam, "CONTF000", (ftnlen)8, (ftnlen)8);
    pdsin_(dirnam, memnam, work, &leng, &irc, &iout, (ftnlen)72, (ftnlen)8);
    if (irc == 0) {
	imac = 1;
	*(unsigned char *)etag = 'F';
	goto L100;
    }

    s_copy(memnam, "CONTF002", (ftnlen)8, (ftnlen)8);
    pdsin_(dirnam, memnam, work, &leng, &irc, &iout, (ftnlen)72, (ftnlen)8);
    if (irc == 0) {
	imac = 2;
	*(unsigned char *)etag = 'F';
	goto L100;
    }

    io___31.ciunit = nout1;
    s_wsle(&io___31);
    do_lio(&c__9, &c__1, " ERROR : PDSIN FAILED, IRC=", (ftnlen)27);
    do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
    e_wsle();
    s_stop("999", (ftnlen)3);
L100:
    engedt_(dirnam, &iout, &iprn, memnam, &ng, wt, en, (ftnlen)72, (ftnlen)8);
    io___35.ciunit = nout2;
    s_wsle(&io___35);
    do_lio(&c__9, &c__1, " NUMBER OF ENERGY GROUPS          = ", (ftnlen)36);
    do_lio(&c__3, &c__1, (char *)&ng, (ftnlen)sizeof(integer));
    e_wsle();
    io___36.ciunit = nout2;
    s_wsle(&io___36);
    e_wsle();
    io___37.ciunit = nout2;
    s_wsle(&io___37);
    do_lio(&c__9, &c__1, " << ENERGY BOUNDARY OF MACROSCOPIC XS >>", (ftnlen)
	    40);
    e_wsle();
    io___38.ciunit = nout2;
    s_wsle(&io___38);
    e_wsle();
    io___39.ciunit = nout2;
    s_wsfe(&io___39);
    i__1 = ng + 1;
    for (ig = 1; ig <= i__1; ++ig) {
	do_fio(&c__1, (char *)&en[ig - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
    io___41.ciunit = nout2;
    s_wsle(&io___41);
    e_wsle();

/* *********************************************************************** */
/* READ PL ORDER AND Monte Carlo Option */
/* MCOPT = 0 : accept negative XS (caused by transport correction) */
/*       = 1 : not accept negative scattering XS */
/*             SIGT = SIGT + ABS(SIGS) and SIGS=0 */
/* MSAVE = 0 : down-scattering size is forced to be NG-1 (suggested) */
/*       = 1 : down-scattering size is searched (additional input NDS1 */
/*             is necessary in GMVP (output library may be not available */
/*             in some codes (ex. MORSE) */
/* *********************************************************************** */
    io___42.ciunit = nin;
    s_rsle(&io___42);
    do_lio(&c__3, &c__1, (char *)&npl, (ftnlen)sizeof(integer));
    do_lio(&c__3, &c__1, (char *)&mcopt, (ftnlen)sizeof(integer));
    do_lio(&c__3, &c__1, (char *)&idebug, (ftnlen)sizeof(integer));
    do_lio(&c__3, &c__1, (char *)&msave, (ftnlen)sizeof(integer));
    e_rsle();
    io___47.ciunit = nout2;
    s_wsle(&io___47);
    do_lio(&c__9, &c__1, " INPUT PL ORDER (NPL)             = ", (ftnlen)36);
    do_lio(&c__3, &c__1, (char *)&npl, (ftnlen)sizeof(integer));
    e_wsle();
    io___48.ciunit = nout2;
    s_wsle(&io___48);
    do_lio(&c__9, &c__1, " OPTION FOR NEGATIVE XS           = ", (ftnlen)36);
    do_lio(&c__3, &c__1, (char *)&mcopt, (ftnlen)sizeof(integer));
    e_wsle();
    io___49.ciunit = nout2;
    s_wsle(&io___49);
    do_lio(&c__9, &c__1, " OPTION FOR DEBUG PRINT           = ", (ftnlen)36);
    do_lio(&c__3, &c__1, (char *)&idebug, (ftnlen)sizeof(integer));
    e_wsle();
    io___50.ciunit = nout2;
    s_wsle(&io___50);
    do_lio(&c__9, &c__1, " OPTION FOR MEMORY SAVVING        = ", (ftnlen)36);
    do_lio(&c__3, &c__1, (char *)&msave, (ftnlen)sizeof(integer));
    e_wsle();
    if (npl < 0) {
	io___51.ciunit = nout1;
	s_wsle(&io___51);
	do_lio(&c__9, &c__1, " ERROR: INPUT PL-OREDER(=", (ftnlen)25);
	do_lio(&c__3, &c__1, (char *)&npl, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ") IS INVALID", (ftnlen)12);
	e_wsle();
    }
    if (mcopt != 0) {
	mcopt = 1;
    }
    if (npl > 1) {
	io___52.ciunit = nout1;
	s_wsle(&io___52);
	do_lio(&c__9, &c__1, " ERROR: INPUT PL-OREDER IS GREATER THAN", (
		ftnlen)39);
	do_lio(&c__9, &c__1, " PROGRAM ARRAY SIZE (=", (ftnlen)22);
	do_lio(&c__3, &c__1, (char *)&c__1, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ")", (ftnlen)1);
	e_wsle();
	s_stop("777", (ftnlen)3);
    }
    if (npl == 0 && imac == 2) {
	*(unsigned char *)&ptag[6] = '2';
    }
    npl1 = npl + 1;

/* *********************************************************************** */
/* READ MEMBERS (MATERIALS) */
/* *********************************************************************** */
    nmat = 0;
L200:
    io___55.ciunit = nin;
    i__1 = s_rsfe(&io___55);
    if (i__1 != 0) {
	goto L210;
    }
    i__1 = do_fio(&c__1, memnam, (ftnlen)8);
    if (i__1 != 0) {
	goto L210;
    }
    i__1 = do_fio(&c__1, (char *)&idum, (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L210;
    }
    i__1 = e_rsfe();
    if (i__1 != 0) {
	goto L210;
    }
    if (s_cmp(memnam, "        ", (ftnlen)8, (ftnlen)8) == 0) {
	goto L210;
    }
    ++nmat;
    if (nmat > 50) {
	io___57.ciunit = nout1;
	s_wsle(&io___57);
	do_lio(&c__9, &c__1, " ERROR: NUMBER OF INPUT MEMBERS IS ", (ftnlen)
		35);
	do_lio(&c__9, &c__1, " GREATER THAN PROGRAM ARRAY SIZE (=", (ftnlen)
		35);
	do_lio(&c__3, &c__1, (char *)&c__50, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ")", (ftnlen)1);
	e_wsle();
	s_stop("777", (ftnlen)3);
    }
    s_copy(member + (nmat - 1 << 3), memnam, (ftnlen)8, (ftnlen)8);
    idm[nmat - 1] = idum;
    goto L200;
L210:

/* *********************************************************************** */
/* SEARCH MAX UP-SCATTERING AND MAX DOWN-SCATTERIG SIZES */
/* AMONG MEMBERS */
/* *********************************************************************** */
    mxups = 0;
    mxdws = 0;
    i__1 = nmat;
    for (m = 1; m <= i__1; ++m) {
	i__2 = npl1;
	for (l = 1; l <= i__2; ++l) {
	    s_copy(memnam, member + (m - 1 << 3), (ftnlen)8, (ftnlen)8);
	    *(unsigned char *)&memnam[4] = *(unsigned char *)etag;
	    *(unsigned char *)&memnam[7] = *(unsigned char *)&ptag[l + imac * 
		    6 - 7];
	    pdsin_(dirnam, memnam, work, &leng, &irc, &iout, (ftnlen)72, (
		    ftnlen)8);
	    if (irc != 0) {
		io___64.ciunit = nout1;
		s_wsle(&io___64);
		do_lio(&c__9, &c__1, " ERROR : PDSIN FAILED, IRC=", (ftnlen)
			27);
		do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
		e_wsle();
		s_stop("999", (ftnlen)3);
	    }
	    ipos = 0;
	    i__3 = ng;
	    for (ig = 1; ig <= i__3; ++ig) {
		lss = iwork[ipos];
		lgv = iwork[ipos + 1];
		lup = lss - 1;
		ldw = lgv - lss;
		mxups = max(lup,mxups);
		mxdws = max(ldw,mxdws);
		ipos = ipos + 10 + lgv;
/* L320: */
	    }
/* L310: */
	}
/* L300: */
    }
    if (msave == 0) {
	io___70.ciunit = nout2;
	s_wsle(&io___70);
	do_lio(&c__9, &c__1, " REAL MAX. SIZE OF DOWN-SCATTERING (", (ftnlen)
		36);
	do_lio(&c__3, &c__1, (char *)&mxdws, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ") WAS REPLACED BY ", (ftnlen)18);
	i__1 = ng - 1;
	do_lio(&c__3, &c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	e_wsle();
	mxdws = ng - 1;
    }
    io___71.ciunit = nout2;
    s_wsle(&io___71);
    do_lio(&c__9, &c__1, " MAX. SIZE OF UP-SCATTERING       = ", (ftnlen)36);
    do_lio(&c__3, &c__1, (char *)&mxups, (ftnlen)sizeof(integer));
    e_wsle();
    io___72.ciunit = nout2;
    s_wsle(&io___72);
    do_lio(&c__9, &c__1, " MAX. SIZE OF DOWN-SCATTERING     = ", (ftnlen)36);
    do_lio(&c__3, &c__1, (char *)&mxdws, (ftnlen)sizeof(integer));
    e_wsle();

/* *********************************************************************** */
/* READ MEMBER XS AND SET IT IN ANISN FORMAT */
/* *********************************************************************** */
/*     IHT : position of total cross section in a group XS data */
/*     ISGG: position of self-scattering in a group XS data */
/*     ITBL: length of a group XS data */
/*     LSCT: length of a scattering data in a group */
/*     LENG: record length of all group XS data */
/*     NDS1: size of down-scattering + 1(self-scattering) */

    iht = 3;
    isgg = iht + mxups + 1;
    itbl = isgg + mxdws;
    lsct = mxups + 1 + mxdws;
    leng = ng * itbl;
    nds1 = mxdws + 1;
    io___78.ciunit = nout2;
    s_wsle(&io___78);
    do_lio(&c__9, &c__1, " SIZE OF SCATTERING VECTOR        = ", (ftnlen)36);
    do_lio(&c__3, &c__1, (char *)&lsct, (ftnlen)sizeof(integer));
    e_wsle();
    io___79.ciunit = nout2;
    s_wsle(&io___79);
    do_lio(&c__9, &c__1, " IHT : POSITION OF TOTAL XS       = ", (ftnlen)36);
    do_lio(&c__3, &c__1, (char *)&iht, (ftnlen)sizeof(integer));
    e_wsle();
    io___80.ciunit = nout2;
    s_wsle(&io___80);
    do_lio(&c__9, &c__1, " ISGG: POSITION OF SELF-SCATTERNG = ", (ftnlen)36);
    do_lio(&c__3, &c__1, (char *)&isgg, (ftnlen)sizeof(integer));
    e_wsle();
    io___81.ciunit = nout2;
    s_wsle(&io___81);
    do_lio(&c__9, &c__1, " ITBL: LENGTH OF A GROUP XS DATA  = ", (ftnlen)36);
    do_lio(&c__3, &c__1, (char *)&itbl, (ftnlen)sizeof(integer));
    e_wsle();
    io___82.ciunit = nout2;
    s_wsle(&io___82);
    do_lio(&c__9, &c__1, " NDS1: LENGTH OF DOWN+SELF SCAT.  = ", (ftnlen)36);
    do_lio(&c__3, &c__1, (char *)&nds1, (ftnlen)sizeof(integer));
    e_wsle();

/* ----- MACEDT ARRANGEMENT ------------------------------ */
/*     XSEX(g,1): production */
/*     XSEX(g,2): fission */
/*     XSEX(g,3): capture defined as (absorption - fission) */
/*     XSEX(g,4): absorption */
/*     XSEX(g,5): fission spectrum */
/*     XSEX(g,6): diffusion coefficient (D1) */
/*     XSEX(g,7): diffusion coefficient (D2) */
/*     XSEX(g,8): total or transport */
/*     XSEX(g,9): velocity cross section */
/*     SCAT(g,g'): full size of scattering matrix (g=>g') */
/* ----- FOR ANISN FORMAT */
/*  XSM(g,1,L,m)  : absorption XS of m-th material (L-1 order) */
/*  XSM(g,2,L,m)  : production */
/*  XSM(g,3,L,m)  : total/transport */
/*  SCM(g,g',L,m) : scattering matrix (g->g') of m-th material */

/* ----- Sample when NG=9 -------------------------------------- */
/*      1   2  IHT,           [MXUPS]    ISGG    [MXDWS]  ITBL */
/* g=1  Ag, Pg, Tg,     0 .....3->1 2->1 1->1  0 0 0 ....... 0 */
/* g=2  Ag, Pg, Tg,     0 0 ...4->2 3->2 2->2  1->2  ....... 0 */
/* g=3  Ag, Pg, Tg,     0 0 0 0 ....4->3 3->3  2->3  1->3 .. 0 */
/*  :    :   :   :        :        :       :    :      :     : */
/*  :    :   :   :        :        :       :    :      :     : */
/* g=9  Ag, Pg, Tg,     0 0 0 0 ......0  9->9  8->9  7->9 .... */
/* ------------------------------------------------------------- */

    io___83.ciunit = nout2;
    s_wsle(&io___83);
    e_wsle();
    i__1 = nmat;
    for (m = 1; m <= i__1; ++m) {
	io___84.ciunit = nout2;
	s_wsle(&io___84);
	e_wsle();
	io___85.ciunit = nout2;
	s_wsle(&io___85);
	do_lio(&c__9, &c__1, " ******************************", (ftnlen)31);
	e_wsle();
	io___86.ciunit = nout2;
	s_wsle(&io___86);
	do_lio(&c__9, &c__1, "  INPUT MEMBER NAME = ", (ftnlen)22);
	do_lio(&c__9, &c__1, member + (m - 1 << 3), (ftnlen)8);
	e_wsle();
	io___87.ciunit = nout2;
	s_wsle(&io___87);
	do_lio(&c__9, &c__1, "  INPUT MATERIAL ID = ", (ftnlen)22);
	do_lio(&c__3, &c__1, (char *)&idm[m - 1], (ftnlen)sizeof(integer));
	e_wsle();
	io___88.ciunit = nout2;
	s_wsle(&io___88);
	do_lio(&c__9, &c__1, " ******************************", (ftnlen)31);
	e_wsle();
	io___89.ciunit = nout2;
	s_wsle(&io___89);
	e_wsle();
	i__2 = npl1;
	for (l = 1; l <= i__2; ++l) {
	    s_copy(memnam, member + (m - 1 << 3), (ftnlen)8, (ftnlen)8);
	    *(unsigned char *)&memnam[4] = *(unsigned char *)etag;
	    *(unsigned char *)&memnam[7] = *(unsigned char *)&ptag[l + imac * 
		    6 - 7];
	    macedt_(dirnam, &iout, &iprn, memnam, &ng, xsec, &minsg, &maxsg, 
		    scat, delay, (ftnlen)72, (ftnlen)8);

	    if (idebug == 1) {
		io___95.ciunit = nout2;
		s_wsle(&io___95);
		e_wsle();
		io___96.ciunit = nout2;
		s_wsle(&io___96);
		do_lio(&c__9, &c__1, " << MEMBER NAME OF THE PL(=", (ftnlen)
			27);
		i__3 = l - 1;
		do_lio(&c__3, &c__1, (char *)&i__3, (ftnlen)sizeof(integer));
		do_lio(&c__9, &c__1, ") COMPONENT : ", (ftnlen)14);
		do_lio(&c__9, &c__1, memnam, (ftnlen)8);
		do_lio(&c__9, &c__1, " >>", (ftnlen)3);
		e_wsle();
		io___97.ciunit = nout2;
		s_wsle(&io___97);
		e_wsle();
	    }
	    s_copy(title, memnam, (ftnlen)8, (ftnlen)8);
	    io___98.ciunit = nbin;
	    s_wsue(&io___98);
	    do_uio(&c__1, (char *)&ng, (ftnlen)sizeof(integer));
	    do_uio(&c__1, (char *)&itbl, (ftnlen)sizeof(integer));
	    i__3 = l - 1;
	    do_uio(&c__1, (char *)&i__3, (ftnlen)sizeof(integer));
	    do_uio(&c__1, (char *)&idm[m - 1], (ftnlen)sizeof(integer));
	    do_uio(&c__1, title, (ftnlen)48);
	    e_wsue();

	    if (l == 1) {
		i__3 = ng;
		for (ig = 1; ig <= i__3; ++ig) {
		    xkai[ig + m * 107 - 108] = xsec[ig + 427];
/* L400: */
		}
		io___100.ciunit = nout2;
		s_wsle(&io___100);
		do_lio(&c__9, &c__1, " << MATERIAL DEPENDENT FISSION SPECTRU"
			"M >>", (ftnlen)42);
		e_wsle();
		io___101.ciunit = nout2;
		s_wsfe(&io___101);
		i__3 = ng;
		for (ig = 1; ig <= i__3; ++ig) {
		    do_fio(&c__1, (char *)&xkai[ig + m * 107 - 108], (ftnlen)
			    sizeof(real));
		}
		e_wsfe();
		io___102.ciunit = nout2;
		s_wsle(&io___102);
		e_wsle();
	    }
/* *********************************************************************** */
	    i__3 = ng;
	    for (ig = 1; ig <= i__3; ++ig) {
		xsm[ig + ((l + (m << 1)) * 3 + 1) * 107 - 1071] = xsec[ig + 
			320];
		xsm[ig + ((l + (m << 1)) * 3 + 2) * 107 - 1071] = xsec[ig - 1]
			;
		xsm[ig + ((l + (m << 1)) * 3 + 3) * 107 - 1071] = xsec[ig + 
			748];
/* -----------Check Negative XS */
		if (l == 1) {
		    if (xsm[ig + ((l + (m << 1)) * 3 + 1) * 107 - 1071] < 0.f)
			     {
			io___104.ciunit = nout2;
			s_wsfe(&io___104);
			do_fio(&c__1, "ABSORPTION", (ftnlen)10);
			do_fio(&c__1, (char *)&ig, (ftnlen)sizeof(integer));
			e_wsfe();
			++note;
		    }
		    if (xsm[ig + ((l + (m << 1)) * 3 + 2) * 107 - 1071] < 0.f)
			     {
			io___105.ciunit = nout2;
			s_wsfe(&io___105);
			do_fio(&c__1, "PRODUCTION", (ftnlen)10);
			do_fio(&c__1, (char *)&ig, (ftnlen)sizeof(integer));
			e_wsfe();
			++note;
		    }
		    if (xsm[ig + ((l + (m << 1)) * 3 + 3) * 107 - 1071] < 0.f)
			     {
			io___106.ciunit = nout2;
			s_wsfe(&io___106);
			do_fio(&c__1, "TOTAL(TRA)", (ftnlen)10);
			do_fio(&c__1, (char *)&ig, (ftnlen)sizeof(integer));
			e_wsfe();
			++note;
		    }
		}
		sum = 0.f;
		i__4 = ng;
		for (igg = 1; igg <= i__4; ++igg) {
		    scm[ig + (igg + (l + (m << 1)) * 107) * 107 - 34455] = 
			    scat[ig + igg * 107 + 5135];
/* -----------Check Negative Scattering XS */
		    if (l == 1) {
			if (scm[ig + (igg + (l + (m << 1)) * 107) * 107 - 
				34455] < 0.f) {
			    io___110.ciunit = nout2;
			    s_wsfe(&io___110);
			    do_fio(&c__1, "SCATTERING", (ftnlen)10);
			    do_fio(&c__1, (char *)&ig, (ftnlen)sizeof(integer)
				    );
			    do_fio(&c__1, (char *)&igg, (ftnlen)sizeof(
				    integer));
			    e_wsfe();
			    ++note;
			    if (mcopt != 0) {
				sum += (r__1 = scm[ig + (igg + (l + (m << 1)) 
					* 107) * 107 - 34455], dabs(r__1));
				scm[ig + (igg + (l + (m << 1)) * 107) * 107 - 
					34455] = 0.f;
			    }
			}
		    }
/* L420: */
		}
		if (l == 1 && sum != 0.f) {
		    xsm[ig + ((l + (m << 1)) * 3 + 3) * 107 - 1071] += sum;
		    io___111.ciunit = nout2;
		    s_wsfe(&io___111);
		    do_fio(&c__1, (char *)&sum, (ftnlen)sizeof(real));
		    do_fio(&c__1, (char *)&ig, (ftnlen)sizeof(integer));
		    e_wsfe();
		    ++note;
		}
/* L410: */
	    }
/* --------- set one group XS data(one record) in WORK dimension */
/*         (Note : loop on sink group) */
	    ipos = 0;
	    i__3 = ng;
	    for (igg = 1; igg <= i__3; ++igg) {
		work[ipos] = xsm[igg + ((l + (m << 1)) * 3 + 1) * 107 - 1071];
		work[ipos + 1] = xsm[igg + ((l + (m << 1)) * 3 + 2) * 107 - 
			1071];
		work[ipos + 2] = xsm[igg + ((l + (m << 1)) * 3 + 3) * 107 - 
			1071];
		ipos += 3;

/* -----------SET SCATTERIG XS (LSCT=MXUPS+1+MXDWS) */
		i__4 = lsct;
		for (k = 1; k <= i__4; ++k) {
		    ig = igg + mxups + 1 - k;
		    if (ig <= ng && ig >= 1) {
			work[ipos + k - 1] = scm[ig + (igg + (l + (m << 1)) * 
				107) * 107 - 34455];
		    } else {
			work[ipos + k - 1] = 0.f;
		    }
/* L440: */
		}
		ipos += lsct;
		if (idebug == 1) {
		    itmp = ipos - (lsct + 3) + 1;
		    io___114.ciunit = nout2;
		    s_wsfe(&io___114);
		    do_fio(&c__1, (char *)&igg, (ftnlen)sizeof(integer));
		    i__4 = ipos;
		    for (i__ = itmp; i__ <= i__4; ++i__) {
			do_fio(&c__1, (char *)&work[i__ - 1], (ftnlen)sizeof(
				real));
		    }
		    e_wsfe();
		}
/* L430: */
	    }

	    io___116.ciunit = nbin;
	    s_wsue(&io___116);
	    i__3 = ipos;
	    for (i__ = 1; i__ <= i__3; ++i__) {
		do_uio(&c__1, (char *)&work[i__ - 1], (ftnlen)sizeof(real));
	    }
	    e_wsue();
/* L1100: */
	}
/* L1000: */
    }
    if (note != 0) {
	io___117.ciunit = nout2;
	s_wsle(&io___117);
	e_wsle();
	io___118.ciunit = nout2;
	s_wsle(&io___118);
	do_lio(&c__9, &c__1, " THERE ARE ", (ftnlen)11);
	do_lio(&c__3, &c__1, (char *)&note, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, " WARNING MESSAGES MARKED ", (ftnlen)25);
	do_lio(&c__9, &c__1, "BY (!!! WARNING:) ", (ftnlen)18);
	e_wsle();
	io___119.ciunit = nout2;
	s_wsle(&io___119);
	e_wsle();
    }
    io___120.ciunit = nout2;
    s_wsle(&io___120);
    e_wsle();
    io___121.ciunit = nout2;
    s_wsle(&io___121);
    do_lio(&c__9, &c__1, " ================ NORMAL END ===================", (
	    ftnlen)48);
    e_wsle();

/* *********************************************************************** */
L9999:
    s_stop("", (ftnlen)0);
    return 0;
} /* MAIN__ */

#undef iwork
#undef work


/* *********************************************************************** */

/*  uiount   : set unformated(0) or formated(1) */
/*             for each I/O device */

/* *********************************************************************** */

/* Subroutine */ int uiount_(integer *ioform)
{
    static integer i__;

    /* Parameter adjustments */
    --ioform;

    /* Function Body */
    for (i__ = 1; i__ <= 100; ++i__) {
	ioform[i__] = -1;
/* L100: */
    }
    ioform[1] = 0;
    ioform[5] = 1;
    ioform[6] = 1;
    ioform[99] = 1;
    return 0;
} /* uiount_ */

