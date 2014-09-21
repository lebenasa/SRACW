/* MacroEdit.f -- translated by f2c (version 20100827).
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

/*  main program for pdsmdl */
/*  MacroEdit : Print out Macro Xs Table */

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
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void),
	     s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_stop(char *
	    , ftnlen);

    /* Local variables */
    static real en[108];
    static integer ng;
    static real wt[108], scat[16692]	/* was [107][156] */, xsec[1070]	
	    /* was [107][10] */;
    static integer iprn, iout;
    static real delay[4815]	/* was [15][107][3] */;
    static integer minsg, maxsg;
    extern /* Subroutine */ int macedt_(char *, integer *, integer *, char *, 
	    integer *, real *, integer *, integer *, real *, real *, ftnlen, 
	    ftnlen), engedt_(char *, integer *, integer *, char *, integer *, 
	    real *, real *, ftnlen, ftnlen);
    static char member[8], dirnam[72], memnam[8];
    extern /* Subroutine */ int uioset_(void);

    /* Fortran I/O blocks */
    static cilist io___1 = { 0, 5, 1, "(a72)", 0 };
    static cilist io___3 = { 0, 5, 1, "(a8)", 0 };


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
/* ---- loop on member */
L1000:
    i__1 = s_rsfe(&io___3);
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

/* ---- read number of enegy groups */
    s_copy(memnam, "CONTA000", (ftnlen)8, (ftnlen)8);
    *(unsigned char *)&memnam[4] = *(unsigned char *)&member[4];
    if (*(unsigned char *)&member[7] == '2') {
	*(unsigned char *)&memnam[7] = '2';
    }
    if (*(unsigned char *)&member[7] == '3') {
	*(unsigned char *)&memnam[7] = '2';
    }
    if (*(unsigned char *)&member[7] == '4') {
	*(unsigned char *)&memnam[7] = '2';
    }
    if (*(unsigned char *)&member[7] == 'Y') {
	*(unsigned char *)&memnam[7] = '2';
    }
    if (*(unsigned char *)&member[7] == 'M') {
	*(unsigned char *)&memnam[7] = '2';
    }
    iout = 99;
    iprn = 0;
    engedt_(dirnam, &iout, &iprn, memnam, &ng, wt, en, (ftnlen)72, (ftnlen)8);

/* ---- read macro xs and print out */
    s_copy(memnam, member, (ftnlen)8, (ftnlen)8);
    iout = 6;
    iprn = 1;
    macedt_(dirnam, &iout, &iprn, memnam, &ng, xsec, &minsg, &maxsg, scat, 
	    delay, (ftnlen)72, (ftnlen)8);
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

