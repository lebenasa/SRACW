/* BnupEdit.f -- translated by f2c (version 20100827).
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

/* *********************************************************************** */

/*  main program for pdsmdl */
/*  BnupEdit : Print out Burnup Calculational Results */
/*             Contents of Member ????BNUP/????DN?T */
/*             Print out in the 99th Device */

/* *********************************************************************** */
/* ### COPYED FROM ENGEDT/BNPEDT/DNTEDT */
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
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsle(cilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_wsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static real en[108];
    static integer ng;
    static real wt[108];
    static integer ngc, ngt;
    static real u235f[35], ydi0[1750]	/* was [35][50] */;
    static char case__[4];
    static real days[35];
    static integer ierr, iprn;
    static real rlht[1750]	/* was [35][50] */, ydxe[1750]	/* was [35][
	    50] */, ydpm[1750]	/* was [35][50] */, ydsm[1750]	/* was [35][
	    50] */;
    static char mtnm[4*50];
    static integer iout, nzon;
    static real volx;
    static integer mtyp[50];
    static real sigi0[35000]	/* was [20][35][50] */, u235fx[35], ydi0x[35],
	     akeff[35], akinf[35], cfert[700]	/* was [20][35] */;
    static integer nleng;
    static real afiss[700]	/* was [20][35] */, crins[35], crint[35], 
	    sigxe[35000]	/* was [20][35][50] */, hminv[1750]	/* 
	    was [35][50] */, sigsm[35000]	/* was [20][35][50] */, sigpm[
	    35000]	/* was [20][35][50] */, densx[5250]	/* was [35][
	    150] */;
    static char title[72];
    extern /* Subroutine */ int pdsnm_(char *, char *, char *, integer *, 
	    integer *, ftnlen, ftnlen, ftnlen);
    static integer ntnuc;
    extern /* Subroutine */ int pdssr_(char *, integer *, ftnlen);
    static integer iexst;
    static real rlhtx[35], ydxex[35], expst[35], ydsmx[35], ydpmx[35], expsx[
	    35], powrx[35];
    static integer mtypx;
    static real sigi0x[700]	/* was [20][35] */;
    static char filnam[81], member[8];
    extern /* Subroutine */ int engedt_(char *, integer *, integer *, char *, 
	    integer *, real *, real *, ftnlen, ftnlen);
    static char dirnam[72], memnam[8];
    extern /* Subroutine */ int bnpedt_(char *, integer *, integer *, char *, 
	    integer *, integer *, integer *, integer *, char *, char *, char *
	    , char *, integer *, real *, real *, real *, real *, real *, real 
	    *, real *, real *, real *, real *, real *, real *, real *, real *,
	     real *, real *, real *, real *, char *, real *, real *, real *, 
	    real *, real *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen);
    static char nuclid[4*150];
    extern /* Subroutine */ int dntedt_(char *, integer *, integer *, char *, 
	    integer *, integer *, integer *, integer *, char *, char *, 
	    integer *, real *, real *, real *, real *, real *, real *, real *,
	     real *, real *, real *, char *, real *, real *, real *, real *, 
	    real *, real *, real *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen);
    static char stdnuc[4];
    static real flxnrm[35], densty[262500]	/* was [35][150][50] */, 
	    powerl[35], hminvx[35], sigxex[700]	/* was [20][35] */, sigsmx[
	    700]	/* was [20][35] */, voldpz[50], sigpmx[700]	/* 
	    was [20][35] */;
    extern /* Subroutine */ int uioset_(void);
    static real expszn[1750]	/* was [35][50] */;
    static integer nowstp;
    static real powrzn[1750]	/* was [35][50] */;

    /* Fortran I/O blocks */
    static cilist io___1 = { 0, 5, 1, "(a72)", 0 };
    static cilist io___14 = { 0, 5, 1, "(a8)", 0 };
    static cilist io___67 = { 0, 6, 0, 0, 0 };


/*     ------------------------------------------------------------------ */

/* *********************************************************************** */

    uioset_();
/* ---- read directory name for MACRO/MACROWRK */
    i__1 = s_rsfe(&io___1);
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

/* ---- read number of condensed enegy groups */
    s_copy(memnam, "CONTA000", (ftnlen)8, (ftnlen)8);
    pdsnm_(dirnam, member, filnam, &nleng, &ierr, (ftnlen)72, (ftnlen)8, (
	    ftnlen)81);
    pdssr_(filnam, &iexst, (ftnlen)81);
    if (iexst == 1) {
	s_copy(memnam, "CONTF000", (ftnlen)8, (ftnlen)8);
    }
    iout = 99;
    iprn = 0;
    engedt_(dirnam, &iout, &iprn, memnam, &ng, wt, en, (ftnlen)72, (ftnlen)8);

/* ---- loop on member */

    iout = 6;
    iprn = 1;
L1000:
    i__1 = s_rsfe(&io___14);
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, member, (ftnlen)8);
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = e_rsfe();
    if (i__1 != 0) {
	goto L9999;
    }
    if (s_cmp(member, "        ", (ftnlen)8, (ftnlen)8) == 0) {
	goto L9999;
    } else if (s_cmp(member + 4, "BNUP", (ftnlen)4, (ftnlen)4) == 0) {
	s_copy(memnam, member, (ftnlen)8, (ftnlen)8);
	bnpedt_(dirnam, &iout, &iprn, memnam, &ng, &nowstp, &ntnuc, &nzon, 
		case__, stdnuc, title, mtnm, mtyp, voldpz, days, expst, u235f,
		 akeff, akinf, crins, crint, powerl, flxnrm, powrzn, expszn, 
		hminv, rlht, ydxe, ydi0, ydsm, ydpm, nuclid, densty, sigxe, 
		sigi0, sigsm, sigpm, (ftnlen)72, (ftnlen)8, (ftnlen)4, (
		ftnlen)4, (ftnlen)72, (ftnlen)4, (ftnlen)4);
    } else if (s_cmp(member + 4, "DN", (ftnlen)2, (ftnlen)2) == 0 && *(
	    unsigned char *)&member[7] == 'T') {
	s_copy(memnam, member, (ftnlen)8, (ftnlen)8);
	dntedt_(dirnam, &iout, &iprn, memnam, &nowstp, &ntnuc, &ngc, &ngt, 
		case__, stdnuc, &mtypx, &volx, powrx, expsx, u235fx, hminvx, 
		rlhtx, ydxex, ydi0x, ydsmx, ydpmx, nuclid, densx, afiss, 
		cfert, sigxex, sigi0x, sigsmx, sigpmx, (ftnlen)72, (ftnlen)8, 
		(ftnlen)4, (ftnlen)4, (ftnlen)4);
    } else {
	s_wsle(&io___67);
	do_lio(&c__9, &c__1, " ERROR(MAIN) : MEMBER NAME(", (ftnlen)27);
	do_lio(&c__9, &c__1, member, (ftnlen)8);
	do_lio(&c__9, &c__1, ") IS INVALID", (ftnlen)12);
	e_wsle();
    }

    goto L1000;
L9999:
    s_stop("", (ftnlen)0);
    return 0;
} /* MAIN__ */

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
    ioform[5] = 1;
    ioform[6] = 1;
    ioform[99] = 1;
    return 0;
} /* uiount_ */

