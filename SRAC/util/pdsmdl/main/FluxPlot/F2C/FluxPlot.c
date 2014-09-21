/* FluxPlot.f -- translated by f2c (version 20100827).
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
static integer c__2 = 2;
static integer c__3 = 3;

/* *********************************************************************** */

/*  main program for pdsmdl */
/*  FluxPlot : Read Fine Gruop Spectrum in each R-Region or X-Region and */
/*             Edit Table Data (Histgram Type) for any Plot-Applications */

/* *********************************************************************** */
/* ### COPYED FROM ENGEDT/FLXEDT */
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
    static char fmt_6000[] = "(1x,\002GROUP\002,\002 ENERGY-B.D. \002,\002  "
	    " SPECTRUM  \002)";
    static char fmt_6100[] = "(1x,i4,1x,1pe12.5,1x,1pe12.5)";

    /* System generated locals */
    address a__1[2];
    integer i__1, i__2[2], i__3;

    /* Builtin functions */
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void),
	     s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    double log(doublereal);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    integer s_wsfe(cilist *), e_wsfe(void);

    /* Local variables */
    static integer i__, k, ig;
    static real en[108];
    static integer ng;
    static real du[107];
    static integer ir;
    static real wt[108];
    static integer nrr;
    static real flx1[32100]	/* was [107][300] */;
    static integer iplt, iprn;
    static real volm[300];
    static integer iout;
    static real volr[300], volt;
    extern /* Subroutine */ int engedt_(char *, integer *, integer *, char *, 
	    integer *, real *, real *, ftnlen, ftnlen);
    static char member[8], dirnam[72], memnam[8];
    extern /* Subroutine */ int flxedt_(char *, integer *, integer *, char *, 
	    integer *, integer *, real *, real *, ftnlen, ftnlen), uioset_(
	    void);

    /* Fortran I/O blocks */
    static cilist io___1 = { 0, 5, 1, "(a72)", 0 };
    static cilist io___6 = { 0, 5, 1, "(a8)", 0 };
    static cilist io___9 = { 0, 6, 0, 0, 0 };
    static cilist io___22 = { 0, 0, 0, 0, 0 };
    static cilist io___23 = { 0, 0, 0, 0, 0 };
    static cilist io___24 = { 0, 0, 0, fmt_6000, 0 };
    static cilist io___26 = { 0, 0, 0, fmt_6100, 0 };
    static cilist io___27 = { 0, 0, 0, fmt_6100, 0 };


/*     ------------------------------------------------------------------ */
/* ----------------------------------------------------------------------- */
/* ----------------------------------------------------------------------- */
    uioset_();
/* ---- read directory name for FLUX file */
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
    iout = 99;
    iplt = 6;
    iprn = 1;

/* ==== loop on members */
L1000:
    i__1 = s_rsfe(&io___6);
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
    }
/* ---- read energy structur */
    if (*(unsigned char *)&member[7] == '2') {
	s_copy(memnam, "CONTA002", (ftnlen)8, (ftnlen)8);
    } else if (*(unsigned char *)&member[7] == '0') {
	s_copy(memnam, "CONTA000", (ftnlen)8, (ftnlen)8);
    } else {
	s_wsle(&io___9);
	do_lio(&c__9, &c__1, " THE LAST TAG OF INPUT MEMBER NAME IS INVALID ",
		 (ftnlen)46);
	e_wsle();
	s_stop("", (ftnlen)0);
    }
    *(unsigned char *)&memnam[4] = *(unsigned char *)&member[4];
/* ---- set lethergy */
    engedt_(dirnam, &iout, &iprn, memnam, &ng, wt, en, (ftnlen)72, (ftnlen)8);
    i__1 = ng;
    for (i__ = 1; i__ <= i__1; ++i__) {
	du[i__ - 1] = log(en[i__ - 1] / en[i__]);
/* L100: */
    }
/* ---- set region volume */
/*     X-REGION VOLUME IS DETERMINED AS TOTAL OF ALL R-REGION */
/* Writing concatenation */
    i__2[0] = 4, a__1[0] = member;
    i__2[1] = 4, a__1[1] = "FVOL";
    s_cat(memnam, a__1, i__2, &c__2, (ftnlen)8);
    flxedt_(dirnam, &iout, &iprn, memnam, &ng, &nrr, flx1, volr, (ftnlen)72, (
	    ftnlen)8);
    volt = 0.f;
    i__1 = nrr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	volm[i__ - 1] = volr[i__ - 1];
	volt += volm[i__ - 1];
/* L200: */
    }
    if (*(unsigned char *)&member[6] != '0') {
	volm[0] = volt;
    }
/* ---- read neutron spectrum */
    s_copy(memnam, member, (ftnlen)8, (ftnlen)8);
    flxedt_(dirnam, &iout, &iprn, memnam, &ng, &nrr, flx1, volr, (ftnlen)72, (
	    ftnlen)8);
    i__1 = nrr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__3 = ng;
	for (k = 1; k <= i__3; ++k) {
	    flx1[k + i__ * 107 - 108] = flx1[k + i__ * 107 - 108] / du[k - 1] 
		    / volm[i__ - 1];
/* L300: */
	}
    }
/* ********************************* */
/*  WRITE PLOT DATA FOR HISTGRAM  * */
/* ********************************* */
    i__3 = nrr;
    for (ir = 1; ir <= i__3; ++ir) {
	io___22.ciunit = iplt;
	s_wsle(&io___22);
	e_wsle();
	io___23.ciunit = iplt;
	s_wsle(&io___23);
	do_lio(&c__9, &c__1, " <<<< NEUTRON SPECTRUM(", (ftnlen)23);
	do_lio(&c__9, &c__1, member, (ftnlen)8);
	do_lio(&c__9, &c__1, ") REGION(", (ftnlen)9);
	do_lio(&c__3, &c__1, (char *)&ir, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ") >>>>", (ftnlen)6);
	e_wsle();
	io___24.ciunit = iplt;
	s_wsfe(&io___24);
	e_wsfe();
	i__1 = ng;
	for (ig = 1; ig <= i__1; ++ig) {
	    io___26.ciunit = iplt;
	    s_wsfe(&io___26);
	    do_fio(&c__1, (char *)&ig, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&en[ig - 1], (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&flx1[ig + ir * 107 - 108], (ftnlen)sizeof(
		    real));
	    e_wsfe();
	    io___27.ciunit = iplt;
	    s_wsfe(&io___27);
	    do_fio(&c__1, (char *)&ig, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&en[ig], (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&flx1[ig + ir * 107 - 108], (ftnlen)sizeof(
		    real));
	    e_wsfe();
/* L400: */
	}
/* L500: */
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

