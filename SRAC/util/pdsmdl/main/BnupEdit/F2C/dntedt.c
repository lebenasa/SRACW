/* dntedt.f -- translated by f2c (version 20100827).
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
static integer c__20 = 20;
static integer c__35 = 35;
static integer c__150 = 150;

/* *********************************************************************** */
/*  PROGRAM TO EDIT MEMBER 'CASE'//DN?T IN MACRO OR MACROWRK FILE       * */
/*  VERSION : SRAC95 FOR UNIX                                           * */
/* *********************************************************************** */

/* Subroutine */ int dntedt_(char *dirnam, integer *iout, integer *iprn, char 
	*memnam, integer *nowstp, integer *ntnuc, integer *ngc, integer *ngt, 
	char *case__, char *stdnuc, integer *mtypx, real *volx, real *powrx, 
	real *expsx, real *u235fx, real *hminvx, real *rlhtx, real *ydxex, 
	real *ydi0x, real *ydsmx, real *ydpmx, char *nuclid, real *densx, 
	real *afiss, real *cfert, real *sigxex, real *sigi0x, real *sigsmx, 
	real *sigpmx, ftnlen dirnam_len, ftnlen memnam_len, ftnlen case_len, 
	ftnlen stdnuc_len, ftnlen nuclid_len)
{
    /* Format strings */
    static char fmt_7000[] = "(\002 \002,\002DNTEDT\002,114(\002=\002))";
    static char fmt_6000[] = "(/\002 BNUP-STEP  \002,10(5x,i2,5x):/(12x,10(5"
	    "x,i2,5x)))";
    static char fmt_6010[] = "(\002 ABS./CC    \002,1p10e12.5:/(12x,1p10e12."
	    "5))";
    static char fmt_6020[] = "(\002 MWD/TON    \002,1p10e12.5:/(12x,1p10e12."
	    "5))";
    static char fmt_6030[] = "(1x,a3,\002-%\002,6x,1p10e12.5:/(12x,1p10e12.5"
	    "))";
    static char fmt_6040[] = "(\002 POW(MW/CC) \002,1p10e12.5:/(12x,1p10e12."
	    "5))";
    static char fmt_6050[] = "(\002 HM-TON/CC  \002,1p10e12.5:/(12x,1p10e12."
	    "5))";
    static char fmt_6060[] = "(\002 J-ENG/FIS. \002,1p10e12.5:/(12x,1p10e12."
	    "5))";
    static char fmt_6070[] = "(\002 XE-135 YD. \002,1p10e12.5:/(12x,1p10e12."
	    "5))";
    static char fmt_6080[] = "(\002 I -135 YD. \002,1p10e12.5:/(12x,1p10e12."
	    "5))";
    static char fmt_6090[] = "(\002 SM-149 YD. \002,1p10e12.5:/(12x,1p10e12."
	    "5))";
    static char fmt_6100[] = "(\002 PM-149 YD. \002,1p10e12.5:/(12x,1p10e12."
	    "5))";
    static char fmt_6200[] = "(1x,3(\002-\002),2x,4(\002-\002),1x,11(1x,10"
	    "(\002-\002)))";
    static char fmt_6210[] = "(1x,i3,2x,a4,1x,1p11e11.4:/(11x,1p11e11.4))";
    static char fmt_6300[] = "(1x,\002STEP:\002,i3,2x,1p10e11.4:/(11x,1p10e1"
	    "1.4))";
    static char fmt_7010[] = "(\002 \002,114(\002=\002),\002DNTEDT\002)";

    /* System generated locals */
    integer i__1, i__2, i__3;
    icilist ici__1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsle(cilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_wsle(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_stop(char *
	    , ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    , s_wsfe(cilist *), e_wsfe(void);

    /* Local variables */
    static integer i__, j, k, ig, irc, leng, ipos, nstg;
    extern /* Subroutine */ int pdsin_(char *, char *, real *, integer *, 
	    integer *, integer *, ftnlen, ftnlen);
#define iwork ((integer *)&wkpds_1)
    static char member[8];

    /* Fortran I/O blocks */
    static cilist io___3 = { 0, 0, 0, 0, 0 };
    static cilist io___4 = { 0, 6, 0, 0, 0 };
    static cilist io___8 = { 0, 0, 0, 0, 0 };
    static cilist io___9 = { 0, 6, 0, 0, 0 };
    static cilist io___11 = { 0, 0, 0, 0, 0 };
    static cilist io___12 = { 0, 6, 0, 0, 0 };
    static cilist io___13 = { 0, 0, 0, 0, 0 };
    static cilist io___14 = { 0, 6, 0, 0, 0 };
    static cilist io___15 = { 0, 0, 0, 0, 0 };
    static cilist io___16 = { 0, 6, 0, 0, 0 };
    static cilist io___20 = { 0, 0, 0, 0, 0 };
    static cilist io___21 = { 0, 6, 0, 0, 0 };
    static cilist io___22 = { 0, 0, 0, 0, 0 };
    static cilist io___23 = { 0, 0, 0, fmt_7000, 0 };
    static cilist io___24 = { 0, 0, 0, 0, 0 };
    static cilist io___25 = { 0, 0, 0, 0, 0 };
    static cilist io___26 = { 0, 0, 0, 0, 0 };
    static cilist io___27 = { 0, 0, 0, "(1X,A,A)", 0 };
    static cilist io___28 = { 0, 0, 0, "(1X,A,I3)", 0 };
    static cilist io___29 = { 0, 0, 0, "(1X,A,I3)", 0 };
    static cilist io___30 = { 0, 0, 0, "(1X,A,I3)", 0 };
    static cilist io___31 = { 0, 0, 0, "(1X,A,I3)", 0 };
    static cilist io___32 = { 0, 0, 0, "(1X,A,I3)", 0 };
    static cilist io___33 = { 0, 0, 0, "(1X,A,1P10E12.5)", 0 };
    static cilist io___34 = { 0, 0, 0, fmt_6000, 0 };
    static cilist io___35 = { 0, 0, 0, fmt_6010, 0 };
    static cilist io___36 = { 0, 0, 0, fmt_6020, 0 };
    static cilist io___37 = { 0, 0, 0, fmt_6030, 0 };
    static cilist io___38 = { 0, 0, 0, fmt_6040, 0 };
    static cilist io___39 = { 0, 0, 0, fmt_6050, 0 };
    static cilist io___40 = { 0, 0, 0, fmt_6060, 0 };
    static cilist io___41 = { 0, 0, 0, fmt_6070, 0 };
    static cilist io___42 = { 0, 0, 0, fmt_6080, 0 };
    static cilist io___43 = { 0, 0, 0, fmt_6090, 0 };
    static cilist io___44 = { 0, 0, 0, fmt_6100, 0 };
    static cilist io___45 = { 0, 0, 0, 0, 0 };
    static cilist io___46 = { 0, 0, 0, "(/A)", 0 };
    static cilist io___47 = { 0, 0, 0, fmt_6000, 0 };
    static cilist io___48 = { 0, 0, 0, fmt_6200, 0 };
    static cilist io___49 = { 0, 0, 0, fmt_6210, 0 };
    static cilist io___50 = { 0, 0, 0, "(/A)", 0 };
    static cilist io___51 = { 0, 0, 0, fmt_6300, 0 };
    static cilist io___53 = { 0, 0, 0, "(/A)", 0 };
    static cilist io___54 = { 0, 0, 0, fmt_6300, 0 };
    static cilist io___55 = { 0, 0, 0, "(/A)", 0 };
    static cilist io___56 = { 0, 0, 0, fmt_6300, 0 };
    static cilist io___57 = { 0, 0, 0, "(/A)", 0 };
    static cilist io___58 = { 0, 0, 0, fmt_6300, 0 };
    static cilist io___59 = { 0, 0, 0, "(/A)", 0 };
    static cilist io___60 = { 0, 0, 0, fmt_6300, 0 };
    static cilist io___61 = { 0, 0, 0, "(/A)", 0 };
    static cilist io___62 = { 0, 0, 0, fmt_6300, 0 };
    static cilist io___63 = { 0, 0, 0, 0, 0 };
    static cilist io___64 = { 0, 0, 0, 0, 0 };
    static cilist io___65 = { 0, 0, 0, fmt_7010, 0 };
    static cilist io___66 = { 0, 0, 0, 0, 0 };



/* =========================== FOR MAIN ================================== */
/* DEL  PARAMETER (MAXNGC=20, MAXSTP=35, MAXNUC=110) */
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
/* DEL  PARAMETER    (MAXWRK=10000) */
/* -------------------------------INPUT----------------------------------- */
/*   DIRNAM       : DIRECTORY NAME (A72) OF PDS : /XXX/XXX/MACRO01 */
/*   IOUT         : LOGICAL DEVICE FOR OUTPUT */
/*   IPRN         : =0(NO PRINT), =1(PRINT OUT IN DEVICE IOUT) */
/*   MEMNAM       : PDS MEMBER NAME TO EDIT(A8): ____ND?T */
/*                  ?=X-REGION TAG (1,2,3,....9,A,B,....Z) */
/* -------------------------------OUTPUT---------------------------------- */
/*   *** ALL DATA BELOW IS HOMOGENIZED VALUE IN X-REGION *** */
/*   NOWSTP       : NUMBER OF BURNUP STEPS INCLUDING THE INITIAL STEP */
/*                  NOWSTP = 1 + NEP(INPUT IN BURNUP) */
/*   NTNUC        : TOTAL NUMBER OF DEPLETING NUCLIDES */
/*   NGC          : NUMBER OF CONDENSED ENERGY GROUPS */
/*   NGT          : NUMBER OF CONDENSED THERMAL ENERGY GROUPS */
/*   CASE         : CASE IDENTIFICATION (A4) */
/*   STDNUC       : STANDARD NUCLIDE NAME (A4) TO INDICATE FRACTIONAL */
/*                  BURNED DENSITY (%), DEFALT:XU05 */
/*   MTYPX        : MATERIAL TYPE (=0:NOT BURNABLE, =1:FISSILE & BURNABLE */
/*                  =2:NOT FISSILE BUT BURNABLE) */
/*   VOLX         : VOLUME OF X-REGION (CM3) */
/*   NUCLID(K)    : K-TH DEPLETING NUCLIDE NAME (A4) */
/*                  EX. XU05,XPU9 */
/*   POWRX(J)     : POWER DENSITY (W/CM3) BY STEP(J) */
/*   EXPSX(J)     : ACCUMULATED BURNUP (MWD/T) BY STEP(J) */
/*                  IF MTYPX=2 THEN ACCUMULATED ABSORPTION RATE (ABS/CM3) */
/*   U235FX(J)    : FRACTIONAL BURNED DENSITY OF STDNUC (%) */
/*   HMINVX(J)    : HEAVY METAL INVENTRY DENSITY (TON/CM3) */
/*   RLHTX(J)     : RELEASED ENERGY/FISSION (J/FISS) BY STEP(J) */
/*   YDXEX(J)     : FISSION YIELD OF XE-135 BY STEP(J) */
/*   YDI0X(J)     : FISSION YIELD OF I-135 BY STEP(J) */
/*   YDSMX(J)     : FISSION YIELD OF SM-149 BY STEP(J) */
/*   YDPMX(J)     : FISSION YIELD OF PM-149 BY STEP(J) */
/*   DENSX(J,K)   : DENSITY OF NUCLIDE(K) BY STEP(J) */
/*   AFISS(G,J)   : FISSILE ABSORPTION MACRO (/CM) IN GROUP(G) BY STEP(J) */
/*   CFERT(G,J)   : FERTILE CAPTURE MACRO (/CM) IN GROUP(G) BY STEP(J) */
/*   SIGXEX(G,J)  : MICRO ABSORPTION XS OF XE-135 IN GROUP(G) BY STEP(J) */
/*   SIGI0X(G,J)  : MICRO ABSORPTION XS OF I-135 IN GROUP(G) BY STEP(J) */
/*   SIGSMX(G,J)  : MICRO ABSORPTION XS OF SM-149 IN GROUP(G) BY STEP(J) */
/*   SIGPMX(G,J)  : MICRO ABSORPTION XS OF PM-149 IN GROUP(G) BY STEP(J) */
/* ----------------------------------------------------------------------- */
/* ************* */
/*  ZERO SET  *--------------------------------------------------------- */
/* ************* */
    /* Parameter adjustments */
    sigpmx -= 21;
    sigsmx -= 21;
    sigi0x -= 21;
    sigxex -= 21;
    cfert -= 21;
    afiss -= 21;
    densx -= 36;
    nuclid -= 4;
    --ydpmx;
    --ydsmx;
    --ydi0x;
    --ydxex;
    --rlhtx;
    --hminvx;
    --u235fx;
    --expsx;
    --powrx;

    /* Function Body */
    for (i__ = 1; i__ <= 200000; ++i__) {
	wkpds_1.work[i__ - 1] = 0.f;
/* L10: */
    }

    if (s_cmp(memnam + 4, "DN", (ftnlen)2, (ftnlen)2) != 0 || *(unsigned char 
	    *)&memnam[7] != 'T') {
	io___3.ciunit = *iout;
	s_wsle(&io___3);
	do_lio(&c__9, &c__1, " CAUTION(DNTEDT): THE LAST 4 CHARACTER IS NOT", 
		(ftnlen)45);
	do_lio(&c__9, &c__1, " DN?T , MEMBER NAME = ", (ftnlen)22);
	do_lio(&c__9, &c__1, memnam, (ftnlen)8);
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___4);
	    do_lio(&c__9, &c__1, " CAUTION(DNTEDT): THE LAST 4 CHARACTER IS "
		    "NOT", (ftnlen)45);
	    do_lio(&c__9, &c__1, " DN?T , MEMBER NAME = ", (ftnlen)22);
	    do_lio(&c__9, &c__1, memnam, (ftnlen)8);
	    e_wsle();
	}
    }
/* ************************** */
/*  ----DN?T DATA EDIT     *--------------------------------------------- */
/* ************************** */
    s_copy(member, memnam, (ftnlen)8, (ftnlen)8);
    pdsin_(dirnam, member, wkpds_1.work, &leng, &irc, iout, (ftnlen)72, (
	    ftnlen)8);
    if (irc != 0) {
	io___8.ciunit = *iout;
	s_wsle(&io___8);
	do_lio(&c__9, &c__1, " ERROR(DNTEDT): PDSIN ERROR, CODE=", (ftnlen)34)
		;
	do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___9);
	    do_lio(&c__9, &c__1, " ERROR(DNTEDT): PDSIN ERROR, CODE=", (
		    ftnlen)34);
	    do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	    e_wsle();
	}
	s_stop("", (ftnlen)0);
    }
/* ------ 1:NOWSTP, 2:NTNUC, 3:NGC, 4:NGT, 5-10:IDUMY,ZONE ------- */
    *nowstp = iwork[0];
    *ntnuc = iwork[1];
    *ngc = iwork[2];
    *ngt = iwork[3];
    ipos = 10;

    if (*ngc > 20) {
	io___11.ciunit = *iout;
	s_wsle(&io___11);
	do_lio(&c__9, &c__1, " ERROR(DNTEDT): NUMBER OF ENERGY GROUPS(=", (
		ftnlen)41);
	do_lio(&c__3, &c__1, (char *)&(*ngc), (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ") IS GREATER THAN THE SET VALUE(=", (ftnlen)33);
	do_lio(&c__3, &c__1, (char *)&c__20, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ")", (ftnlen)1);
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___12);
	    do_lio(&c__9, &c__1, " ERROR(DNTEDT): NUMBER OF ENERGY GROUPS(=", 
		    (ftnlen)41);
	    do_lio(&c__3, &c__1, (char *)&(*ngc), (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, ") IS GREATER THAN THE SET VALUE(=", (ftnlen)
		    33);
	    do_lio(&c__3, &c__1, (char *)&c__20, (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, ")", (ftnlen)1);
	    e_wsle();
	}
	s_stop("", (ftnlen)0);
    }
    if (*nowstp > 35) {
	io___13.ciunit = *iout;
	s_wsle(&io___13);
	do_lio(&c__9, &c__1, " ERROR(DNTEDT): NUMBER OF BURNUP STEP(=", (
		ftnlen)39);
	do_lio(&c__3, &c__1, (char *)&(*nowstp), (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ") IS GREATER THAN THE SET VALUE(=", (ftnlen)33);
	do_lio(&c__3, &c__1, (char *)&c__35, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ")", (ftnlen)1);
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___14);
	    do_lio(&c__9, &c__1, " ERROR(DNTEDT): NUMBER OF BURNUP STEP(=", (
		    ftnlen)39);
	    do_lio(&c__3, &c__1, (char *)&(*nowstp), (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, ") IS GREATER THAN THE SET VALUE(=", (ftnlen)
		    33);
	    do_lio(&c__3, &c__1, (char *)&c__35, (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, ")", (ftnlen)1);
	    e_wsle();
	}
	s_stop("", (ftnlen)0);
    }
    if (*ntnuc > 150) {
	io___15.ciunit = *iout;
	s_wsle(&io___15);
	do_lio(&c__9, &c__1, " ERROR(DNTEDT): NUMBER OF DEP. NUCLIDES(=", (
		ftnlen)41);
	do_lio(&c__3, &c__1, (char *)&(*ntnuc), (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ") IS GREATER THAN THE SET VALUE(=", (ftnlen)33);
	do_lio(&c__3, &c__1, (char *)&c__150, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ")", (ftnlen)1);
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___16);
	    do_lio(&c__9, &c__1, " ERROR(DNTEDT): NUMBER OF DEP. NUCLIDES(=", 
		    (ftnlen)41);
	    do_lio(&c__3, &c__1, (char *)&(*ntnuc), (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, ") IS GREATER THAN THE SET VALUE(=", (ftnlen)
		    33);
	    do_lio(&c__3, &c__1, (char *)&c__150, (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, ")", (ftnlen)1);
	    e_wsle();
	}
	s_stop("", (ftnlen)0);
    }
/* ------ 11:CASE, 12:STDNUC, 13:MTYPX, 14:VOLX ------- */
    ici__1.icierr = 0;
    ici__1.icirnum = 1;
    ici__1.icirlen = 4;
    ici__1.iciunit = case__;
    ici__1.icifmt = "(A4)";
    s_wsfi(&ici__1);
    do_fio(&c__1, (char *)&iwork[ipos], (ftnlen)sizeof(integer));
    e_wsfi();
    ici__1.icierr = 0;
    ici__1.icirnum = 1;
    ici__1.icirlen = 4;
    ici__1.iciunit = stdnuc;
    ici__1.icifmt = "(A4)";
    s_wsfi(&ici__1);
    do_fio(&c__1, (char *)&iwork[ipos + 1], (ftnlen)sizeof(integer));
    e_wsfi();
    *mtypx = iwork[ipos + 2];
    *volx = wkpds_1.work[ipos + 3];
    ipos += 4;
/* ------ 15:NUCLID ----------------------------------- */
    i__1 = *ntnuc;
    for (k = 1; k <= i__1; ++k) {
	++ipos;
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = 4;
	ici__1.iciunit = nuclid + (k << 2);
	ici__1.icifmt = "(A4)";
	s_wsfi(&ici__1);
	do_fio(&c__1, (char *)&iwork[ipos - 1], (ftnlen)sizeof(integer));
	e_wsfi();
/* L100: */
    }
/* ------ 16:POWRX, 17:EXPSX, 18:U235FX, 19:HMINVX, 20:RLHTX */
/*       21:YDXEX, 22:YDI0X, 23:YDSMX, 24:YDPMX -------------------- */
    i__1 = *nowstp;
    for (j = 1; j <= i__1; ++j) {
	powrx[j] = wkpds_1.work[ipos + j - 1];
	expsx[j] = wkpds_1.work[ipos + *nowstp + j - 1];
	u235fx[j] = wkpds_1.work[ipos + (*nowstp << 1) + j - 1];
	hminvx[j] = wkpds_1.work[ipos + *nowstp * 3 + j - 1];
	rlhtx[j] = wkpds_1.work[ipos + (*nowstp << 2) + j - 1];
	ydxex[j] = wkpds_1.work[ipos + *nowstp * 5 + j - 1];
	ydi0x[j] = wkpds_1.work[ipos + *nowstp * 6 + j - 1];
	ydsmx[j] = wkpds_1.work[ipos + *nowstp * 7 + j - 1];
	ydpmx[j] = wkpds_1.work[ipos + (*nowstp << 3) + j - 1];
/* L110: */
    }
    ipos += *nowstp * 9;
/* ------ 25:DENSX ------------------------------- */
    i__1 = *ntnuc;
    for (k = 1; k <= i__1; ++k) {
	i__2 = *nowstp;
	for (j = 1; j <= i__2; ++j) {
	    ++ipos;
	    densx[j + k * 35] = wkpds_1.work[ipos - 1];
/* L120: */
	}
    }
/* ------ 26:AFISS, 27:CFERT, 28:SIGXEX, 29:SIGI0X, 30:SIGSMX, 31:SOGPMX */
    nstg = *nowstp * *ngc;
    i__2 = *nowstp;
    for (j = 1; j <= i__2; ++j) {
	i__1 = *ngc;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    afiss[i__ + j * 20] = wkpds_1.work[ipos + *ngc * (j - 1) + i__ - 
		    1];
	    cfert[i__ + j * 20] = wkpds_1.work[ipos + nstg + *ngc * (j - 1) + 
		    i__ - 1];
	    sigxex[i__ + j * 20] = wkpds_1.work[ipos + (nstg << 1) + *ngc * (
		    j - 1) + i__ - 1];
	    sigi0x[i__ + j * 20] = wkpds_1.work[ipos + nstg * 3 + *ngc * (j - 
		    1) + i__ - 1];
	    sigsmx[i__ + j * 20] = wkpds_1.work[ipos + (nstg << 2) + *ngc * (
		    j - 1) + i__ - 1];
	    sigpmx[i__ + j * 20] = wkpds_1.work[ipos + nstg * 5 + *ngc * (j - 
		    1) + i__ - 1];
/* L130: */
	}
    }
    ipos += nstg * 6;
/* ------ DATA LENGTH CHECK ---------------------- */
    if (ipos != leng) {
	io___20.ciunit = *iout;
	s_wsle(&io___20);
	do_lio(&c__9, &c__1, " CAUTION(DNTEDT): DATA LENGTH IN PDS FILE(=", (
		ftnlen)43);
	do_lio(&c__3, &c__1, (char *)&leng, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ") IS MISMATCHED WITH EDIT LENGTH(=", (ftnlen)34)
		;
	do_lio(&c__3, &c__1, (char *)&ipos, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ")", (ftnlen)1);
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___21);
	    do_lio(&c__9, &c__1, " CAUTION(DNTEDT): DATA LENGTH IN PDS FILE(="
		    , (ftnlen)43);
	    do_lio(&c__3, &c__1, (char *)&leng, (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, ") IS MISMATCHED WITH EDIT LENGTH(=", (
		    ftnlen)34);
	    do_lio(&c__3, &c__1, (char *)&ipos, (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, ")", (ftnlen)1);
	    e_wsle();
	}
    }
/* ************************** */
/*     PRINT OUT           *-------------------------------------------- */
/* ************************** */
    if (*iprn == 0) {
	goto L9000;
    }
    io___22.ciunit = *iout;
    s_wsle(&io___22);
    e_wsle();
    io___23.ciunit = *iout;
    s_wsfe(&io___23);
    e_wsfe();
    io___24.ciunit = *iout;
    s_wsle(&io___24);
    e_wsle();
    io___25.ciunit = *iout;
    s_wsle(&io___25);
    do_lio(&c__9, &c__1, "    ***** HOMOGENEOUS BURNUP DATA : MEMBER NAME = ",
	     (ftnlen)50);
    do_lio(&c__9, &c__1, memnam, (ftnlen)8);
    do_lio(&c__9, &c__1, " *****", (ftnlen)6);
    e_wsle();
    io___26.ciunit = *iout;
    s_wsle(&io___26);
    e_wsle();
    io___27.ciunit = *iout;
    s_wsfe(&io___27);
    do_fio(&c__1, "CASE    = ", (ftnlen)10);
    do_fio(&c__1, case__, (ftnlen)4);
    e_wsfe();
    io___28.ciunit = *iout;
    s_wsfe(&io___28);
    do_fio(&c__1, "MTYPX   =", (ftnlen)9);
    do_fio(&c__1, (char *)&(*mtypx), (ftnlen)sizeof(integer));
    e_wsfe();
    io___29.ciunit = *iout;
    s_wsfe(&io___29);
    do_fio(&c__1, "NOWSTP  =", (ftnlen)9);
    do_fio(&c__1, (char *)&(*nowstp), (ftnlen)sizeof(integer));
    e_wsfe();
    io___30.ciunit = *iout;
    s_wsfe(&io___30);
    do_fio(&c__1, "NTNUC   =", (ftnlen)9);
    do_fio(&c__1, (char *)&(*ntnuc), (ftnlen)sizeof(integer));
    e_wsfe();
    io___31.ciunit = *iout;
    s_wsfe(&io___31);
    do_fio(&c__1, "NGC     =", (ftnlen)9);
    do_fio(&c__1, (char *)&(*ngc), (ftnlen)sizeof(integer));
    e_wsfe();
    io___32.ciunit = *iout;
    s_wsfe(&io___32);
    do_fio(&c__1, "NGT     =", (ftnlen)9);
    do_fio(&c__1, (char *)&(*ngt), (ftnlen)sizeof(integer));
    e_wsfe();
    io___33.ciunit = *iout;
    s_wsfe(&io___33);
    do_fio(&c__1, "VOLX(CC)=", (ftnlen)9);
    do_fio(&c__1, (char *)&(*volx), (ftnlen)sizeof(real));
    e_wsfe();

    io___34.ciunit = *iout;
    s_wsfe(&io___34);
    i__1 = *nowstp - 1;
    for (j = 0; j <= i__1; ++j) {
	do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
    }
    e_wsfe();
    if (*mtypx == 2) {
	io___35.ciunit = *iout;
	s_wsfe(&io___35);
	i__1 = *nowstp;
	for (j = 1; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&expsx[j], (ftnlen)sizeof(real));
	}
	e_wsfe();
    } else {
	io___36.ciunit = *iout;
	s_wsfe(&io___36);
	i__1 = *nowstp;
	for (j = 1; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&expsx[j], (ftnlen)sizeof(real));
	}
	e_wsfe();
    }
    io___37.ciunit = *iout;
    s_wsfe(&io___37);
    do_fio(&c__1, stdnuc + 1, (ftnlen)3);
    i__1 = *nowstp;
    for (j = 1; j <= i__1; ++j) {
	do_fio(&c__1, (char *)&u235fx[j], (ftnlen)sizeof(real));
    }
    e_wsfe();
    io___38.ciunit = *iout;
    s_wsfe(&io___38);
    i__1 = *nowstp;
    for (j = 1; j <= i__1; ++j) {
	do_fio(&c__1, (char *)&powrx[j], (ftnlen)sizeof(real));
    }
    e_wsfe();
    io___39.ciunit = *iout;
    s_wsfe(&io___39);
    i__1 = *nowstp;
    for (j = 1; j <= i__1; ++j) {
	do_fio(&c__1, (char *)&hminvx[j], (ftnlen)sizeof(real));
    }
    e_wsfe();
    io___40.ciunit = *iout;
    s_wsfe(&io___40);
    i__1 = *nowstp;
    for (j = 1; j <= i__1; ++j) {
	do_fio(&c__1, (char *)&rlhtx[j], (ftnlen)sizeof(real));
    }
    e_wsfe();
    io___41.ciunit = *iout;
    s_wsfe(&io___41);
    i__1 = *nowstp;
    for (j = 1; j <= i__1; ++j) {
	do_fio(&c__1, (char *)&ydxex[j], (ftnlen)sizeof(real));
    }
    e_wsfe();
    io___42.ciunit = *iout;
    s_wsfe(&io___42);
    i__1 = *nowstp;
    for (j = 1; j <= i__1; ++j) {
	do_fio(&c__1, (char *)&ydi0x[j], (ftnlen)sizeof(real));
    }
    e_wsfe();
    io___43.ciunit = *iout;
    s_wsfe(&io___43);
    i__1 = *nowstp;
    for (j = 1; j <= i__1; ++j) {
	do_fio(&c__1, (char *)&ydsmx[j], (ftnlen)sizeof(real));
    }
    e_wsfe();
    io___44.ciunit = *iout;
    s_wsfe(&io___44);
    i__1 = *nowstp;
    for (j = 1; j <= i__1; ++j) {
	do_fio(&c__1, (char *)&ydpmx[j], (ftnlen)sizeof(real));
    }
    e_wsfe();
    io___45.ciunit = *iout;
    s_wsle(&io___45);
    e_wsle();

    io___46.ciunit = *iout;
    s_wsfe(&io___46);
    do_fio(&c__1, " * NUMBER DENSITY (*E24 N/CC)", (ftnlen)29);
    e_wsfe();
    io___47.ciunit = *iout;
    s_wsfe(&io___47);
    i__1 = *nowstp - 1;
    for (j = 0; j <= i__1; ++j) {
	do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
    }
    e_wsfe();
    io___48.ciunit = *iout;
    s_wsfe(&io___48);
    e_wsfe();
    i__1 = *ntnuc;
    for (k = 1; k <= i__1; ++k) {
	io___49.ciunit = *iout;
	s_wsfe(&io___49);
	do_fio(&c__1, (char *)&k, (ftnlen)sizeof(integer));
	do_fio(&c__1, nuclid + (k << 2), (ftnlen)4);
	i__2 = *nowstp;
	for (j = 1; j <= i__2; ++j) {
	    do_fio(&c__1, (char *)&densx[j + k * 35], (ftnlen)sizeof(real));
	}
	e_wsfe();
/* L1000: */
    }

    io___50.ciunit = *iout;
    s_wsfe(&io___50);
    do_fio(&c__1, " * MACRO FISSILE ABSORPTION XS BY GROUP", (ftnlen)39);
    e_wsfe();
    i__1 = *nowstp;
    for (j = 1; j <= i__1; ++j) {
	io___51.ciunit = *iout;
	s_wsfe(&io___51);
	i__2 = j - 1;
	do_fio(&c__1, (char *)&i__2, (ftnlen)sizeof(integer));
	i__3 = *ngc;
	for (ig = 1; ig <= i__3; ++ig) {
	    do_fio(&c__1, (char *)&afiss[ig + j * 20], (ftnlen)sizeof(real));
	}
	e_wsfe();
/* L1010: */
    }

    io___53.ciunit = *iout;
    s_wsfe(&io___53);
    do_fio(&c__1, " * MACRO FERTILE CAPTURE XS BY GROUP", (ftnlen)36);
    e_wsfe();
    i__1 = *nowstp;
    for (j = 1; j <= i__1; ++j) {
	io___54.ciunit = *iout;
	s_wsfe(&io___54);
	i__2 = j - 1;
	do_fio(&c__1, (char *)&i__2, (ftnlen)sizeof(integer));
	i__3 = *ngc;
	for (ig = 1; ig <= i__3; ++ig) {
	    do_fio(&c__1, (char *)&cfert[ig + j * 20], (ftnlen)sizeof(real));
	}
	e_wsfe();
/* L1020: */
    }

    io___55.ciunit = *iout;
    s_wsfe(&io___55);
    do_fio(&c__1, " * XE-135 MICRO ABSORPTION XS BY GROUP", (ftnlen)38);
    e_wsfe();
    i__1 = *nowstp;
    for (j = 1; j <= i__1; ++j) {
	io___56.ciunit = *iout;
	s_wsfe(&io___56);
	i__2 = j - 1;
	do_fio(&c__1, (char *)&i__2, (ftnlen)sizeof(integer));
	i__3 = *ngc;
	for (ig = 1; ig <= i__3; ++ig) {
	    do_fio(&c__1, (char *)&sigxex[ig + j * 20], (ftnlen)sizeof(real));
	}
	e_wsfe();
/* L1030: */
    }

    io___57.ciunit = *iout;
    s_wsfe(&io___57);
    do_fio(&c__1, " * I -135 MICRO ABSORPTION XS BY GROUP", (ftnlen)38);
    e_wsfe();
    i__1 = *nowstp;
    for (j = 1; j <= i__1; ++j) {
	io___58.ciunit = *iout;
	s_wsfe(&io___58);
	i__2 = j - 1;
	do_fio(&c__1, (char *)&i__2, (ftnlen)sizeof(integer));
	i__3 = *ngc;
	for (ig = 1; ig <= i__3; ++ig) {
	    do_fio(&c__1, (char *)&sigi0x[ig + j * 20], (ftnlen)sizeof(real));
	}
	e_wsfe();
/* L1040: */
    }

    io___59.ciunit = *iout;
    s_wsfe(&io___59);
    do_fio(&c__1, " * SM-149 MICRO ABSORPTION XS BY GROUP", (ftnlen)38);
    e_wsfe();
    i__1 = *nowstp;
    for (j = 1; j <= i__1; ++j) {
	io___60.ciunit = *iout;
	s_wsfe(&io___60);
	i__2 = j - 1;
	do_fio(&c__1, (char *)&i__2, (ftnlen)sizeof(integer));
	i__3 = *ngc;
	for (ig = 1; ig <= i__3; ++ig) {
	    do_fio(&c__1, (char *)&sigsmx[ig + j * 20], (ftnlen)sizeof(real));
	}
	e_wsfe();
/* L1050: */
    }

    io___61.ciunit = *iout;
    s_wsfe(&io___61);
    do_fio(&c__1, " * PM-149 MICRO ABSORPTION XS BY GROUP", (ftnlen)38);
    e_wsfe();
    i__1 = *nowstp;
    for (j = 1; j <= i__1; ++j) {
	io___62.ciunit = *iout;
	s_wsfe(&io___62);
	i__2 = j - 1;
	do_fio(&c__1, (char *)&i__2, (ftnlen)sizeof(integer));
	i__3 = *ngc;
	for (ig = 1; ig <= i__3; ++ig) {
	    do_fio(&c__1, (char *)&sigpmx[ig + j * 20], (ftnlen)sizeof(real));
	}
	e_wsfe();
/* L1060: */
    }

    io___63.ciunit = *iout;
    s_wsle(&io___63);
    e_wsle();
    io___64.ciunit = *iout;
    s_wsle(&io___64);
    e_wsle();
    io___65.ciunit = *iout;
    s_wsfe(&io___65);
    e_wsfe();
    io___66.ciunit = *iout;
    s_wsle(&io___66);
    e_wsle();

L9000:
    return 0;
} /* dntedt_ */

#undef iwork


