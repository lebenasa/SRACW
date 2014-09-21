/* bnpedt.f -- translated by f2c (version 20100827).
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
static integer c_b85 = 200000;
static integer c__35 = 35;
static integer c__150 = 150;
static integer c__50 = 50;
static integer c__4 = 4;

/* *********************************************************************** */
/*  PROGRAM TO EDIT MEMBER 'CASE'//BNUP IN MACRO OR MACROWRK FILE       * */
/*  VERSION : SRAC95 FOR UNIX                                           * */
/* *********************************************************************** */

/* Subroutine */ int bnpedt_(char *dirnam, integer *iout, integer *iprn, char 
	*memnam, integer *ngc, integer *nowstp, integer *ntnuc, integer *nzon,
	 char *case__, char *stdnuc, char *title, char *mtnm, integer *mtyp, 
	real *voldpz, real *days, real *expst, real *u235f, real *akeff, real 
	*akinf, real *crins, real *crint, real *powerl, real *flxnrm, real *
	powrzn, real *expszn, real *hminv, real *rlht, real *ydxe, real *ydi0,
	 real *ydsm, real *ydpm, char *nuclid, real *densty, real *sigxe, 
	real *sigi0, real *sigsm, real *sigpm, ftnlen dirnam_len, ftnlen 
	memnam_len, ftnlen case_len, ftnlen stdnuc_len, ftnlen title_len, 
	ftnlen mtnm_len, ftnlen nuclid_len)
{
    /* Format strings */
    static char fmt_7000[] = "(\002 \002,\002BNPEDT\002,114(\002=\002))";
    static char fmt_6000[] = "(/\002 BNUP-STEP  \002,10(5x,i2,5x):/(12x,10(5"
	    "x,i2,5x)))";
    static char fmt_6010[] = "(\002 DAYS       \002,1p10e12.5:/(12x,1p10e12."
	    "5))";
    static char fmt_6020[] = "(\002 MWD/TON    \002,1p10e12.5:/(12x,1p10e12."
	    "5))";
    static char fmt_6030[] = "(1x,a3,\002-%\002,6x,1p10e12.5:/(12x,1p10e12.5"
	    "))";
    static char fmt_6040[] = "(\002 K-EFF      \002,1p10e12.5:/(12x,1p10e12."
	    "5))";
    static char fmt_6050[] = "(\002 K-INF      \002,1p10e12.5:/(12x,1p10e12."
	    "5))";
    static char fmt_6060[] = "(\002 INS.-CR    \002,1p10e12.5:/(12x,1p10e12."
	    "5))";
    static char fmt_6070[] = "(\002 INT.-CR    \002,1p10e12.5:/(12x,1p10e12."
	    "5))";
    static char fmt_6080[] = "(\002 POWER(MW)  \002,1p10e12.5:/(12x,1p10e12."
	    "5))";
    static char fmt_6090[] = "(\002 FLX-NORM.  \002,1p10e12.5:/(12x,1p10e12."
	    "5))";
    static char fmt_6200[] = "(\002 ABS./CC    \002,1p10e12.5:/(12x,1p10e12."
	    "5))";
    static char fmt_6210[] = "(\002 MWD/TON    \002,1p10e12.5:/(12x,1p10e12."
	    "5))";
    static char fmt_6220[] = "(\002 POW(MW/CC) \002,1p10e12.5:/(12x,1p10e12."
	    "5))";
    static char fmt_6230[] = "(\002 HM-TON/CC  \002,1p10e12.5:/(12x,1p10e12."
	    "5))";
    static char fmt_6240[] = "(\002 J-ENG/FIS. \002,1p10e12.5:/(12x,1p10e12."
	    "5))";
    static char fmt_6250[] = "(\002 XE-135 YD  \002,1p10e12.5:/(12x,1p10e12."
	    "5))";
    static char fmt_6260[] = "(\002 I -135 YD  \002,1p10e12.5:/(12x,1p10e12."
	    "5))";
    static char fmt_6270[] = "(\002 SM-149 YD  \002,1p10e12.5:/(12x,1p10e12."
	    "5))";
    static char fmt_6280[] = "(\002 PM-149 YD  \002,1p10e12.5:/(12x,1p10e12."
	    "5))";
    static char fmt_6300[] = "(/\002 BNUP-STEP  \002,10(5x,i2,5x):/(12x,10(5"
	    "x,i2,5x)))";
    static char fmt_6310[] = "(1x,3(\002-\002),2x,4(\002-\002),1x,11(1x,10"
	    "(\002-\002)))";
    static char fmt_6320[] = "(1x,i3,2x,a4,1x,1p11e11.4:/(11x,1p11e11.4))";
    static char fmt_6330[] = "(1x,\002STEP:\002,i3,2x,1p10e11.4:/(11x,1p10e1"
	    "1.4))";
    static char fmt_7010[] = "(\002 \002,114(\002=\002),\002BNPEDT\002)";

    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    icilist ici__1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    , s_wsfe(cilist *), e_wsfe(void);

    /* Local variables */
    static integer i__, j, k, ig, ii, jj, irc, izn, leng, ipos, nzst;
    extern /* Subroutine */ int pdsin_(char *, char *, real *, integer *, 
	    integer *, integer *, ftnlen, ftnlen);
#define iwork ((integer *)&wkpds_1)
    static char member[8];

    /* Fortran I/O blocks */
    static cilist io___2 = { 0, 0, 0, 0, 0 };
    static cilist io___3 = { 0, 6, 0, 0, 0 };
    static cilist io___4 = { 0, 0, 0, 0, 0 };
    static cilist io___5 = { 0, 6, 0, 0, 0 };
    static cilist io___7 = { 0, 0, 0, 0, 0 };
    static cilist io___8 = { 0, 6, 0, 0, 0 };
    static cilist io___12 = { 0, 0, 0, 0, 0 };
    static cilist io___13 = { 0, 6, 0, 0, 0 };
    static cilist io___14 = { 0, 0, 0, 0, 0 };
    static cilist io___15 = { 0, 6, 0, 0, 0 };
    static cilist io___17 = { 0, 0, 0, 0, 0 };
    static cilist io___18 = { 0, 6, 0, 0, 0 };
    static cilist io___19 = { 0, 0, 0, 0, 0 };
    static cilist io___20 = { 0, 6, 0, 0, 0 };
    static cilist io___21 = { 0, 0, 0, 0, 0 };
    static cilist io___22 = { 0, 6, 0, 0, 0 };
    static cilist io___28 = { 0, 0, 0, 0, 0 };
    static cilist io___29 = { 0, 6, 0, 0, 0 };
    static cilist io___30 = { 0, 0, 0, 0, 0 };
    static cilist io___31 = { 0, 0, 0, fmt_7000, 0 };
    static cilist io___32 = { 0, 0, 0, 0, 0 };
    static cilist io___33 = { 0, 0, 0, 0, 0 };
    static cilist io___34 = { 0, 0, 0, 0, 0 };
    static cilist io___35 = { 0, 0, 0, "(1X,A,A)", 0 };
    static cilist io___36 = { 0, 0, 0, "(1X,A,A)", 0 };
    static cilist io___37 = { 0, 0, 0, "(1X,A,I3)", 0 };
    static cilist io___38 = { 0, 0, 0, "(1X,A,I3)", 0 };
    static cilist io___39 = { 0, 0, 0, "(1X,A,I3)", 0 };
    static cilist io___40 = { 0, 0, 0, 0, 0 };
    static cilist io___41 = { 0, 0, 0, fmt_6000, 0 };
    static cilist io___42 = { 0, 0, 0, fmt_6010, 0 };
    static cilist io___43 = { 0, 0, 0, fmt_6020, 0 };
    static cilist io___44 = { 0, 0, 0, fmt_6030, 0 };
    static cilist io___45 = { 0, 0, 0, fmt_6040, 0 };
    static cilist io___46 = { 0, 0, 0, fmt_6050, 0 };
    static cilist io___47 = { 0, 0, 0, fmt_6060, 0 };
    static cilist io___48 = { 0, 0, 0, fmt_6070, 0 };
    static cilist io___49 = { 0, 0, 0, fmt_6080, 0 };
    static cilist io___50 = { 0, 0, 0, fmt_6090, 0 };
    static cilist io___51 = { 0, 0, 0, 0, 0 };
    static cilist io___53 = { 0, 0, 0, 0, 0 };
    static cilist io___54 = { 0, 0, 0, 0, 0 };
    static cilist io___55 = { 0, 0, 0, fmt_6000, 0 };
    static cilist io___56 = { 0, 0, 0, fmt_6200, 0 };
    static cilist io___57 = { 0, 0, 0, fmt_6210, 0 };
    static cilist io___58 = { 0, 0, 0, fmt_6220, 0 };
    static cilist io___59 = { 0, 0, 0, fmt_6230, 0 };
    static cilist io___60 = { 0, 0, 0, fmt_6240, 0 };
    static cilist io___61 = { 0, 0, 0, fmt_6250, 0 };
    static cilist io___62 = { 0, 0, 0, fmt_6260, 0 };
    static cilist io___63 = { 0, 0, 0, fmt_6270, 0 };
    static cilist io___64 = { 0, 0, 0, fmt_6280, 0 };
    static cilist io___65 = { 0, 0, 0, "(/A)", 0 };
    static cilist io___66 = { 0, 0, 0, fmt_6300, 0 };
    static cilist io___67 = { 0, 0, 0, fmt_6310, 0 };
    static cilist io___68 = { 0, 0, 0, fmt_6320, 0 };
    static cilist io___69 = { 0, 0, 0, "(/A)", 0 };
    static cilist io___71 = { 0, 0, 0, fmt_6330, 0 };
    static cilist io___72 = { 0, 0, 0, "(/A)", 0 };
    static cilist io___73 = { 0, 0, 0, fmt_6330, 0 };
    static cilist io___74 = { 0, 0, 0, "(/A)", 0 };
    static cilist io___75 = { 0, 0, 0, fmt_6330, 0 };
    static cilist io___76 = { 0, 0, 0, "(/A)", 0 };
    static cilist io___77 = { 0, 0, 0, fmt_6330, 0 };
    static cilist io___78 = { 0, 0, 0, 0, 0 };
    static cilist io___79 = { 0, 0, 0, 0, 0 };
    static cilist io___80 = { 0, 0, 0, fmt_7010, 0 };
    static cilist io___81 = { 0, 0, 0, 0, 0 };



/* =========================== FOR MAIN ================================== */
/* DEL  PARAMETER (MAXNGC=20, MAXSTP=35, MAXNUC=110) */
/* DEL  PARAMETER (MAXZN=50) */
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
/* DEL  PARAMETER    (MAXWRK=100000) */
/* -------------------------------INPUT----------------------------------- */
/*   DIRNAM       : DIRECTORY NAME (A72) OF PDS : /XXX/XXX/MACRO01 */
/*   IOUT         : LOGICAL DEVICE FOR OUTPUT */
/*   IPRN         : =0(NO PRINT), =1(PRINT OUT IN DEVICE IOUT) */
/*   MEMNAM       : PDS MEMBER NAME TO EDIT(A8): ____BNUP */
/*   NGC          : NUMBER OF CONDENSED ENERGY GROUPS */
/* -------------------------------OUTPUT---------------------------------- */
/*   NOWSTP       : NUMBER OF BURNUP STEPS INCLUDING THE INITIAL STEP */
/*                  NOWSTP = 1 + NEP(INPUT IN BURNUP) */
/*   NTNUC        : TOTAL NUMBER OF DEPLETING NUCLIDES */
/*   NZON         : TOTAL NUMBER OF DEPLETING ZONE(=MATERIAL REGION) */
/*   CASE         : CASE IDENTIFICATION (A4) */
/*   STDNUC       : STANDARD NUCLIDE NAME (A4) TO INDICATE FRACTIONAL */
/*                  BURNED DENSITY (%), DEFALT:XU05 */
/*   TITLE        : COMMENT (A72) */
/*   MTNM(I)      : MATERIAL NAME (A4) BY DEPLETING ZONE, I=1...NZON */
/*                  THE FIRST 4-CHARACTERS OF THE MATERIAL NAME IN INPUT */
/*   MTYP(I)      : MATERIAL TYPE BY DEPLETING ZONE, I=1...NZON */
/*                  (=1:FISSILE & BURNABLE, =2:NOT FISSILE BUT BURNABLE) */
/*   VOLDPZ(I)    : VOLUME OF DEPLETING ZONE(I) (CC) */
/*   NUCLID(K)    : K-TH DEPLETING NUCLIDE NAME (A4), K=1....NTNUC */
/*                  EX. XU05,XPU9 */
/*   DAYS(J)      : ACCUMULATED BURNUP PERIOD (DAYS) BY STEP(J) */
/*   EXPST(J)     : ACCUMULATED BURNUP (MWD/T) BY STEP(J) */
/*   U235F(J)     : FRACTIONAL BURNED DENSITY OF STDNUC (%) */
/*   AKEFF(J)     : K-EFF BY STEP(J) */
/*   AKINF(J)     : K-INF BY STEP(J) */
/*   CRINS(J)     : INSTANTANEOUS CONVERSION RATIO BY STEP(J) */
/*   CRINT(J)     : INTEGRATED CONVERSION RATIO BY STEP(J) */
/*   POWERL(J)    : TOTAL POWER IN A UNIT-LENGTH(CM) LATTICE (MWT) */
/*   FLXNRM(J)    : NORMALIZATION FACTOR OF FLUX LEVEL BY STEP(J) */
/*   POWRZN(J,I)  : POWER DENSITY (W/CM3) BY STEP(J), ZONE(I) */
/*   EXPSZN(J,I)  : ACCUMULATED BURNUP (MWD/T) BY STEP(J), ZONE(I) */
/*                  IF MTYP(I)=2 => ACCUMULATED ABSORPTION RATE(ABS/CM3) */
/*   HMINV(J,I)   : HEAVY METAL DENSITY (TON/CC) BY STEP(J), ZONE(I) */
/*   RLHT(J,I)    : RELEASED ENERGY/FISSION (J/FISS) BY STEP(J), ZONE(I) */
/*   YDXE(J,I)    : FISSION YIELD OF XE-135 BY STEP(J), ZONE(I) */
/*   YDI0(J,I)    : FISSION YIELD OF I-135 BY STEP(J), ZONE(I) */
/*   YDSM(J,I)    : FISSION YIELD OF SM-149 BY STEP(J), ZONE(I) */
/*   YDPM(J,I)    : FISSION YIELD OF PM-149 BY STEP(J), ZONE(I) */
/*   DENSTY(J,K,I): DENSITY OF NUCLIDE(K) BY STEP(J), ZONE(I) */
/*   SIGXE(G,J,I) : MICRO ABSORPTION XS OF XE-135 IN GROUP(G) BY STEP(J) */
/*                  BY ZONE(I) */
/*   SIGI0(G,J,I) : MICRO ABSORPTION XS OF I-135 IN GROUP(G) BY STEP(J) */
/*                  BY ZONE(I) */
/*   SIGSM(G,J,I) : MICRO ABSORPTION XS OF SM-149 IN GROUP(G) BY STEP(J) */
/*                  BY ZONE(I) */
/*   SIGPM(G,J,I) : MICRO ABSORPTION XS OF PM-149 IN GROUP(G) BY STEP(J) */
/*                  BY ZONE(I) */
/* ----------------------------------------------------------------------- */
/* ************* */
/*  ZERO SET  *--------------------------------------------------------- */
/* ************* */
    /* Parameter adjustments */
    sigpm -= 721;
    sigsm -= 721;
    sigi0 -= 721;
    sigxe -= 721;
    densty -= 5286;
    nuclid -= 4;
    ydpm -= 36;
    ydsm -= 36;
    ydi0 -= 36;
    ydxe -= 36;
    rlht -= 36;
    hminv -= 36;
    expszn -= 36;
    powrzn -= 36;
    --flxnrm;
    --powerl;
    --crint;
    --crins;
    --akinf;
    --akeff;
    --u235f;
    --expst;
    --days;
    --voldpz;
    --mtyp;
    mtnm -= 4;

    /* Function Body */
    if (*ngc > 20) {
	io___2.ciunit = *iout;
	s_wsle(&io___2);
	do_lio(&c__9, &c__1, " ERROR(BNPEDT): NUMBER OF ENERGY GROUPS(=", (
		ftnlen)41);
	do_lio(&c__3, &c__1, (char *)&(*ngc), (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ") IS GREATER THAN THE SET VALUE(=", (ftnlen)33);
	do_lio(&c__3, &c__1, (char *)&c__20, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ")", (ftnlen)1);
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___3);
	    do_lio(&c__9, &c__1, " ERROR(BNPEDT): NUMBER OF ENERGY GROUPS(=", 
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

    if (*ngc <= 0) {
	io___4.ciunit = *iout;
	s_wsle(&io___4);
	do_lio(&c__9, &c__1, " ERROR(BNPEDT): NUMBER OF ENERGY GROUPS(=", (
		ftnlen)41);
	do_lio(&c__3, &c__1, (char *)&(*ngc), (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ") IS INVALID", (ftnlen)12);
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___5);
	    do_lio(&c__9, &c__1, " ERROR(BNPEDT): NUMBER OF ENERGY GROUPS(=", 
		    (ftnlen)41);
	    do_lio(&c__3, &c__1, (char *)&(*ngc), (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, ") IS INVALID", (ftnlen)12);
	    e_wsle();
	}
	s_stop("", (ftnlen)0);
    }

    for (i__ = 1; i__ <= 200000; ++i__) {
	wkpds_1.work[i__ - 1] = 0.f;
/* L10: */
    }

    if (s_cmp(memnam + 4, "BNUP", (ftnlen)4, (ftnlen)4) != 0) {
	io___7.ciunit = *iout;
	s_wsle(&io___7);
	do_lio(&c__9, &c__1, " CAUTION(BNPEDT): THE LAST 4 CHARACTER IS NOT", 
		(ftnlen)45);
	do_lio(&c__9, &c__1, " BNUP , MEMBER NAME = ", (ftnlen)22);
	do_lio(&c__9, &c__1, memnam, (ftnlen)8);
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___8);
	    do_lio(&c__9, &c__1, " CAUTION(BNPEDT): THE LAST 4 CHARACTER IS "
		    "NOT", (ftnlen)45);
	    do_lio(&c__9, &c__1, " BNUP , MEMBER NAME = ", (ftnlen)22);
	    do_lio(&c__9, &c__1, memnam, (ftnlen)8);
	    e_wsle();
	}
    }
/* ************************** */
/*  ----BNUP DATA EDIT     *--------------------------------------------- */
/* ************************** */
    s_copy(member, memnam, (ftnlen)8, (ftnlen)8);
    pdsin_(dirnam, member, wkpds_1.work, &leng, &irc, iout, (ftnlen)72, (
	    ftnlen)8);
    if (irc != 0) {
	io___12.ciunit = *iout;
	s_wsle(&io___12);
	do_lio(&c__9, &c__1, " ERROR(BNPEDT): PDSIN ERROR, CODE=", (ftnlen)34)
		;
	do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___13);
	    do_lio(&c__9, &c__1, " ERROR(BNPEDT): PDSIN ERROR, CODE=", (
		    ftnlen)34);
	    do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	    e_wsle();
	}
	s_stop("", (ftnlen)0);
    }
    if (leng > 200000) {
	io___14.ciunit = *iout;
	s_wsle(&io___14);
	do_lio(&c__9, &c__1, " ERROR(BNPEDT):REQUIRED WORK SIZE(=", (ftnlen)
		35);
	do_lio(&c__3, &c__1, (char *)&leng, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ") IS GREATER THAN THE SET VALUE(=", (ftnlen)33);
	do_lio(&c__3, &c__1, (char *)&c_b85, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ")", (ftnlen)1);
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___15);
	    do_lio(&c__9, &c__1, " ERROR(BNPEDT):REQUIRED WORK SIZE(=", (
		    ftnlen)35);
	    do_lio(&c__3, &c__1, (char *)&leng, (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, ") IS GREATER THAN THE SET VALUE(=", (ftnlen)
		    33);
	    do_lio(&c__3, &c__1, (char *)&c_b85, (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, ")", (ftnlen)1);
	    e_wsle();
	}
	s_stop("", (ftnlen)0);
    }
/* ------ 1:NOWSTP, 2:NTNUC, 3:NZON ----------------------------- */
    *nowstp = iwork[0];
    *ntnuc = iwork[1];
    *nzon = iwork[2];
    ipos = 10;

    if (*nowstp > 35) {
	io___17.ciunit = *iout;
	s_wsle(&io___17);
	do_lio(&c__9, &c__1, " ERROR(BNPEDT): NUMBER OF BURNUP STEP(=", (
		ftnlen)39);
	do_lio(&c__3, &c__1, (char *)&(*nowstp), (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ") IS GREATER THAN THE SET VALUE(=", (ftnlen)33);
	do_lio(&c__3, &c__1, (char *)&c__35, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ")", (ftnlen)1);
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___18);
	    do_lio(&c__9, &c__1, " ERROR(BNPEDT): NUMBER OF BURNUP STEP(=", (
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
	io___19.ciunit = *iout;
	s_wsle(&io___19);
	do_lio(&c__9, &c__1, " ERROR(BNPEDT): NUMBER OF DEP. NUCLIDES(=", (
		ftnlen)41);
	do_lio(&c__3, &c__1, (char *)&(*ntnuc), (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ") IS GREATER THAN THE SET VALUE(=", (ftnlen)33);
	do_lio(&c__3, &c__1, (char *)&c__150, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ")", (ftnlen)1);
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___20);
	    do_lio(&c__9, &c__1, " ERROR(BNPEDT): NUMBER OF DEP. NUCLIDES(=", 
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
    if (*nzon > 50) {
	io___21.ciunit = *iout;
	s_wsle(&io___21);
	do_lio(&c__9, &c__1, " ERROR(BNPEDT): NUMBER OF DEP. ZONE(=", (ftnlen)
		37);
	do_lio(&c__3, &c__1, (char *)&(*nzon), (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ") IS GREATER THAN THE SET VALUE(=", (ftnlen)33);
	do_lio(&c__3, &c__1, (char *)&c__50, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ")", (ftnlen)1);
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___22);
	    do_lio(&c__9, &c__1, " ERROR(BNPEDT): NUMBER OF DEP. ZONE(=", (
		    ftnlen)37);
	    do_lio(&c__3, &c__1, (char *)&(*nzon), (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, ") IS GREATER THAN THE SET VALUE(=", (ftnlen)
		    33);
	    do_lio(&c__3, &c__1, (char *)&c__50, (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, ")", (ftnlen)1);
	    e_wsle();
	}
	s_stop("", (ftnlen)0);
    }
/* ------ 11:CASE, 12:STDNUC, 13:TITLE ---------------- */
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
    ipos += 2;
    for (i__ = 1; i__ <= 18; ++i__) {
	ii = (i__ - 1 << 2) + 1;
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = 4;
	ici__1.iciunit = title + (ii - 1);
	ici__1.icifmt = "(A4)";
	s_wsfi(&ici__1);
	do_fio(&c__1, (char *)&iwork[ipos + i__ - 1], (ftnlen)sizeof(integer))
		;
	e_wsfi();
/* L100: */
    }
    ipos += 18;
/* ------ 14:MTNM, 15:MTYP, 16:VOLDPZ -------------------------- */
    i__1 = *nzon;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = 4;
	ici__1.iciunit = mtnm + (i__ << 2);
	ici__1.icifmt = "(A4)";
	s_wsfi(&ici__1);
	do_fio(&c__1, (char *)&iwork[ipos + i__ - 1], (ftnlen)sizeof(integer))
		;
	e_wsfi();
	mtyp[i__] = iwork[ipos + *nzon + i__ - 1];
	voldpz[i__] = wkpds_1.work[ipos + (*nzon << 1) + i__ - 1];
/* L110: */
    }
    ipos += *nzon * 3;
/* ------ 17:NUCLID ----------------------------------- */
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
/* L120: */
    }
/* ------ 18:DAYS, 19:EXPST, 20:U235F, 21:AKEFF, 22:AKINF */
/*       23:CRINS, 24:CRINT, 25:POWERL, 26:FLXNRM ------------------ */
    i__1 = *nowstp;
    for (j = 1; j <= i__1; ++j) {
	days[j] = wkpds_1.work[ipos + j - 1];
	expst[j] = wkpds_1.work[ipos + *nowstp + j - 1];
	u235f[j] = wkpds_1.work[ipos + (*nowstp << 1) + j - 1];
	akeff[j] = wkpds_1.work[ipos + *nowstp * 3 + j - 1];
	akinf[j] = wkpds_1.work[ipos + (*nowstp << 2) + j - 1];
	crins[j] = wkpds_1.work[ipos + *nowstp * 5 + j - 1];
	crint[j] = wkpds_1.work[ipos + *nowstp * 6 + j - 1];
	powerl[j] = wkpds_1.work[ipos + *nowstp * 7 + j - 1];
	flxnrm[j] = wkpds_1.work[ipos + (*nowstp << 3) + j - 1];
/* L130: */
    }
    ipos += *nowstp * 9;
/* ------ 27:POWRZN, 28:EXPSZN, 29:HMINV, 30:RLHT, 31:YDXE, */
/*       32:YDI0, 33:YDSM, 34:YDPM --------------------------------- */
    nzst = *nzon * *nowstp;
    i__1 = *nzon;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *nowstp;
	for (j = 1; j <= i__2; ++j) {
	    powrzn[j + i__ * 35] = wkpds_1.work[ipos + *nowstp * (i__ - 1) + 
		    j - 1];
	    expszn[j + i__ * 35] = wkpds_1.work[ipos + nzst + *nowstp * (i__ 
		    - 1) + j - 1];
	    hminv[j + i__ * 35] = wkpds_1.work[ipos + (nzst << 1) + *nowstp * 
		    (i__ - 1) + j - 1];
	    rlht[j + i__ * 35] = wkpds_1.work[ipos + nzst * 3 + *nowstp * (
		    i__ - 1) + j - 1];
	    ydxe[j + i__ * 35] = wkpds_1.work[ipos + (nzst << 2) + *nowstp * (
		    i__ - 1) + j - 1];
	    ydi0[j + i__ * 35] = wkpds_1.work[ipos + nzst * 5 + *nowstp * (
		    i__ - 1) + j - 1];
	    ydsm[j + i__ * 35] = wkpds_1.work[ipos + nzst * 6 + *nowstp * (
		    i__ - 1) + j - 1];
	    ydpm[j + i__ * 35] = wkpds_1.work[ipos + nzst * 7 + *nowstp * (
		    i__ - 1) + j - 1];
/* L140: */
	}
    }
    ipos += nzst << 3;
/* ------ 35:DENSTY ------------------------------------------------ */
    i__2 = *nzon;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = *ntnuc;
	for (k = 1; k <= i__1; ++k) {
	    i__3 = *nowstp;
	    for (j = 1; j <= i__3; ++j) {
		++ipos;
		densty[j + (k + i__ * 150) * 35] = wkpds_1.work[ipos - 1];
/* L150: */
	    }
	}
    }
/* ------ 36:SIGXE ------------------------------------------------- */
    i__3 = *nzon;
    for (i__ = 1; i__ <= i__3; ++i__) {
	i__1 = *nowstp;
	for (j = 1; j <= i__1; ++j) {
	    i__2 = *ngc;
	    for (ig = 1; ig <= i__2; ++ig) {
		++ipos;
		sigxe[ig + (j + i__ * 35) * 20] = wkpds_1.work[ipos - 1];
/* L160: */
	    }
	}
    }
/* ------ 37:SIGI0 ------------------------------------------------- */
    i__2 = *nzon;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = *nowstp;
	for (j = 1; j <= i__1; ++j) {
	    i__3 = *ngc;
	    for (ig = 1; ig <= i__3; ++ig) {
		++ipos;
		sigi0[ig + (j + i__ * 35) * 20] = wkpds_1.work[ipos - 1];
/* L170: */
	    }
	}
    }
/* ------ 38:SIGSM ------------------------------------------------- */
    i__3 = *nzon;
    for (i__ = 1; i__ <= i__3; ++i__) {
	i__1 = *nowstp;
	for (j = 1; j <= i__1; ++j) {
	    i__2 = *ngc;
	    for (ig = 1; ig <= i__2; ++ig) {
		++ipos;
		sigsm[ig + (j + i__ * 35) * 20] = wkpds_1.work[ipos - 1];
/* L180: */
	    }
	}
    }
/* ------ 39:SIGPM ------------------------------------------------- */
    i__2 = *nzon;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = *nowstp;
	for (j = 1; j <= i__1; ++j) {
	    i__3 = *ngc;
	    for (ig = 1; ig <= i__3; ++ig) {
		++ipos;
		sigpm[ig + (j + i__ * 35) * 20] = wkpds_1.work[ipos - 1];
/* L190: */
	    }
	}
    }
/* ------ DATA LENGTH CHECK ---------------------- */
    if (ipos != leng) {
	io___28.ciunit = *iout;
	s_wsle(&io___28);
	do_lio(&c__9, &c__1, " CAUTION(BNPEDT): DATA LENGTH IN PDS FILE(=", (
		ftnlen)43);
	do_lio(&c__3, &c__1, (char *)&leng, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ") IS MISMATCHED WITH EDIT LENGTH(=", (ftnlen)34)
		;
	do_lio(&c__3, &c__1, (char *)&ipos, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ")", (ftnlen)1);
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___29);
	    do_lio(&c__9, &c__1, " CAUTION(BNPEDT): DATA LENGTH IN PDS FILE(="
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
    io___30.ciunit = *iout;
    s_wsle(&io___30);
    e_wsle();
    io___31.ciunit = *iout;
    s_wsfe(&io___31);
    e_wsfe();
    io___32.ciunit = *iout;
    s_wsle(&io___32);
    e_wsle();
    io___33.ciunit = *iout;
    s_wsle(&io___33);
    do_lio(&c__9, &c__1, "    ***** HETEROGENEOUS BURNUP DATA :", (ftnlen)37);
    do_lio(&c__9, &c__1, " MEMBER NAME = ", (ftnlen)15);
    do_lio(&c__9, &c__1, memnam, (ftnlen)8);
    do_lio(&c__9, &c__1, " *****", (ftnlen)6);
    e_wsle();
    io___34.ciunit = *iout;
    s_wsle(&io___34);
    e_wsle();
    io___35.ciunit = *iout;
    s_wsfe(&io___35);
    do_fio(&c__1, "CASE    = ", (ftnlen)10);
    do_fio(&c__1, case__, (ftnlen)4);
    e_wsfe();
    io___36.ciunit = *iout;
    s_wsfe(&io___36);
    do_fio(&c__1, "TITLE   = ", (ftnlen)10);
    do_fio(&c__1, title, (ftnlen)72);
    e_wsfe();
    io___37.ciunit = *iout;
    s_wsfe(&io___37);
    do_fio(&c__1, "NOWSTP  =", (ftnlen)9);
    do_fio(&c__1, (char *)&(*nowstp), (ftnlen)sizeof(integer));
    e_wsfe();
    io___38.ciunit = *iout;
    s_wsfe(&io___38);
    do_fio(&c__1, "NTNUC   =", (ftnlen)9);
    do_fio(&c__1, (char *)&(*ntnuc), (ftnlen)sizeof(integer));
    e_wsfe();
    io___39.ciunit = *iout;
    s_wsfe(&io___39);
    do_fio(&c__1, "NZON    =", (ftnlen)9);
    do_fio(&c__1, (char *)&(*nzon), (ftnlen)sizeof(integer));
    e_wsfe();
    io___40.ciunit = *iout;
    s_wsle(&io___40);
    e_wsle();

    io___41.ciunit = *iout;
    s_wsfe(&io___41);
    i__3 = *nowstp - 1;
    for (j = 0; j <= i__3; ++j) {
	do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
    }
    e_wsfe();
    io___42.ciunit = *iout;
    s_wsfe(&io___42);
    i__3 = *nowstp;
    for (j = 1; j <= i__3; ++j) {
	do_fio(&c__1, (char *)&days[j], (ftnlen)sizeof(real));
    }
    e_wsfe();
    io___43.ciunit = *iout;
    s_wsfe(&io___43);
    i__3 = *nowstp;
    for (j = 1; j <= i__3; ++j) {
	do_fio(&c__1, (char *)&expst[j], (ftnlen)sizeof(real));
    }
    e_wsfe();
    io___44.ciunit = *iout;
    s_wsfe(&io___44);
    do_fio(&c__1, stdnuc + 1, (ftnlen)3);
    i__3 = *nowstp;
    for (j = 1; j <= i__3; ++j) {
	do_fio(&c__1, (char *)&u235f[j], (ftnlen)sizeof(real));
    }
    e_wsfe();
    io___45.ciunit = *iout;
    s_wsfe(&io___45);
    i__3 = *nowstp;
    for (j = 1; j <= i__3; ++j) {
	do_fio(&c__1, (char *)&akeff[j], (ftnlen)sizeof(real));
    }
    e_wsfe();
    io___46.ciunit = *iout;
    s_wsfe(&io___46);
    i__3 = *nowstp;
    for (j = 1; j <= i__3; ++j) {
	do_fio(&c__1, (char *)&akinf[j], (ftnlen)sizeof(real));
    }
    e_wsfe();
    io___47.ciunit = *iout;
    s_wsfe(&io___47);
    i__3 = *nowstp;
    for (j = 1; j <= i__3; ++j) {
	do_fio(&c__1, (char *)&crins[j], (ftnlen)sizeof(real));
    }
    e_wsfe();
    io___48.ciunit = *iout;
    s_wsfe(&io___48);
    i__3 = *nowstp;
    for (j = 1; j <= i__3; ++j) {
	do_fio(&c__1, (char *)&crint[j], (ftnlen)sizeof(real));
    }
    e_wsfe();
    io___49.ciunit = *iout;
    s_wsfe(&io___49);
    i__3 = *nowstp;
    for (j = 1; j <= i__3; ++j) {
	do_fio(&c__1, (char *)&powerl[j], (ftnlen)sizeof(real));
    }
    e_wsfe();
    io___50.ciunit = *iout;
    s_wsfe(&io___50);
    i__3 = *nowstp;
    for (j = 1; j <= i__3; ++j) {
	do_fio(&c__1, (char *)&flxnrm[j], (ftnlen)sizeof(real));
    }
    e_wsfe();
    io___51.ciunit = *iout;
    s_wsle(&io___51);
    e_wsle();

    i__3 = *nzon;
    for (izn = 1; izn <= i__3; ++izn) {
	io___53.ciunit = *iout;
	s_wsle(&io___53);
	e_wsle();
	io___54.ciunit = *iout;
	s_wsle(&io___54);
	do_lio(&c__9, &c__1, " ***** DEPLETING ZONE(", (ftnlen)22);
	do_lio(&c__3, &c__1, (char *)&izn, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ") : ", (ftnlen)4);
	do_lio(&c__9, &c__1, "MATERIAL NAME=", (ftnlen)14);
	do_lio(&c__9, &c__1, mtnm + (izn << 2), (ftnlen)4);
	do_lio(&c__9, &c__1, " : MATERIAL TYPE=", (ftnlen)17);
	do_lio(&c__3, &c__1, (char *)&mtyp[izn], (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, " : VOLUME(CC)=", (ftnlen)14);
	do_lio(&c__4, &c__1, (char *)&voldpz[izn], (ftnlen)sizeof(real));
	e_wsle();
	io___55.ciunit = *iout;
	s_wsfe(&io___55);
	i__1 = *nowstp - 1;
	for (j = 0; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	}
	e_wsfe();
	if (mtyp[izn] == 2) {
	    io___56.ciunit = *iout;
	    s_wsfe(&io___56);
	    i__1 = *nowstp;
	    for (j = 1; j <= i__1; ++j) {
		do_fio(&c__1, (char *)&expszn[j + izn * 35], (ftnlen)sizeof(
			real));
	    }
	    e_wsfe();
	} else {
	    io___57.ciunit = *iout;
	    s_wsfe(&io___57);
	    i__1 = *nowstp;
	    for (j = 1; j <= i__1; ++j) {
		do_fio(&c__1, (char *)&expszn[j + izn * 35], (ftnlen)sizeof(
			real));
	    }
	    e_wsfe();
	}
	io___58.ciunit = *iout;
	s_wsfe(&io___58);
	i__1 = *nowstp;
	for (j = 1; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&powrzn[j + izn * 35], (ftnlen)sizeof(real))
		    ;
	}
	e_wsfe();
	io___59.ciunit = *iout;
	s_wsfe(&io___59);
	i__1 = *nowstp;
	for (j = 1; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&hminv[j + izn * 35], (ftnlen)sizeof(real));
	}
	e_wsfe();
	io___60.ciunit = *iout;
	s_wsfe(&io___60);
	i__1 = *nowstp;
	for (j = 1; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&rlht[j + izn * 35], (ftnlen)sizeof(real));
	}
	e_wsfe();
	io___61.ciunit = *iout;
	s_wsfe(&io___61);
	i__1 = *nowstp;
	for (j = 1; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&ydxe[j + izn * 35], (ftnlen)sizeof(real));
	}
	e_wsfe();
	io___62.ciunit = *iout;
	s_wsfe(&io___62);
	i__1 = *nowstp;
	for (j = 1; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&ydi0[j + izn * 35], (ftnlen)sizeof(real));
	}
	e_wsfe();
	io___63.ciunit = *iout;
	s_wsfe(&io___63);
	i__1 = *nowstp;
	for (j = 1; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&ydsm[j + izn * 35], (ftnlen)sizeof(real));
	}
	e_wsfe();
	io___64.ciunit = *iout;
	s_wsfe(&io___64);
	i__1 = *nowstp;
	for (j = 1; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&ydpm[j + izn * 35], (ftnlen)sizeof(real));
	}
	e_wsfe();
	io___65.ciunit = *iout;
	s_wsfe(&io___65);
	do_fio(&c__1, " * NUMBER DENSITY (*E24 N/CC)", (ftnlen)29);
	e_wsfe();
	io___66.ciunit = *iout;
	s_wsfe(&io___66);
	i__1 = *nowstp - 1;
	for (j = 0; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	}
	e_wsfe();
	io___67.ciunit = *iout;
	s_wsfe(&io___67);
	e_wsfe();
	i__1 = *ntnuc;
	for (k = 1; k <= i__1; ++k) {
	    io___68.ciunit = *iout;
	    s_wsfe(&io___68);
	    do_fio(&c__1, (char *)&k, (ftnlen)sizeof(integer));
	    do_fio(&c__1, nuclid + (k << 2), (ftnlen)4);
	    i__2 = *nowstp;
	    for (j = 1; j <= i__2; ++j) {
		do_fio(&c__1, (char *)&densty[j + (k + izn * 150) * 35], (
			ftnlen)sizeof(real));
	    }
	    e_wsfe();
/* L1000: */
	}
/* L6330: */

	io___69.ciunit = *iout;
	s_wsfe(&io___69);
	do_fio(&c__1, " * XE-135 MICRO ABSORPTION XS BY GROUP", (ftnlen)38);
	e_wsfe();
	i__1 = *nowstp;
	for (jj = 1; jj <= i__1; ++jj) {
	    io___71.ciunit = *iout;
	    s_wsfe(&io___71);
	    i__2 = jj - 1;
	    do_fio(&c__1, (char *)&i__2, (ftnlen)sizeof(integer));
	    i__4 = *ngc;
	    for (ig = 1; ig <= i__4; ++ig) {
		do_fio(&c__1, (char *)&sigxe[ig + (jj + izn * 35) * 20], (
			ftnlen)sizeof(real));
	    }
	    e_wsfe();
/* L1010: */
	}

	io___72.ciunit = *iout;
	s_wsfe(&io___72);
	do_fio(&c__1, " * I -135 MICRO ABSORPTION XS BY GROUP", (ftnlen)38);
	e_wsfe();
	i__1 = *nowstp;
	for (jj = 1; jj <= i__1; ++jj) {
	    io___73.ciunit = *iout;
	    s_wsfe(&io___73);
	    i__2 = jj - 1;
	    do_fio(&c__1, (char *)&i__2, (ftnlen)sizeof(integer));
	    i__4 = *ngc;
	    for (ig = 1; ig <= i__4; ++ig) {
		do_fio(&c__1, (char *)&sigi0[ig + (jj + izn * 35) * 20], (
			ftnlen)sizeof(real));
	    }
	    e_wsfe();
/* L1020: */
	}

	io___74.ciunit = *iout;
	s_wsfe(&io___74);
	do_fio(&c__1, " * SM-149 MICRO ABSORPTION XS BY GROUP", (ftnlen)38);
	e_wsfe();
	i__1 = *nowstp;
	for (jj = 1; jj <= i__1; ++jj) {
	    io___75.ciunit = *iout;
	    s_wsfe(&io___75);
	    i__2 = jj - 1;
	    do_fio(&c__1, (char *)&i__2, (ftnlen)sizeof(integer));
	    i__4 = *ngc;
	    for (ig = 1; ig <= i__4; ++ig) {
		do_fio(&c__1, (char *)&sigsm[ig + (jj + izn * 35) * 20], (
			ftnlen)sizeof(real));
	    }
	    e_wsfe();
/* L1030: */
	}

	io___76.ciunit = *iout;
	s_wsfe(&io___76);
	do_fio(&c__1, " * PM-149 MICRO ABSORPTION XS BY GROUP", (ftnlen)38);
	e_wsfe();
	i__1 = *nowstp;
	for (jj = 1; jj <= i__1; ++jj) {
	    io___77.ciunit = *iout;
	    s_wsfe(&io___77);
	    i__2 = jj - 1;
	    do_fio(&c__1, (char *)&i__2, (ftnlen)sizeof(integer));
	    i__4 = *ngc;
	    for (ig = 1; ig <= i__4; ++ig) {
		do_fio(&c__1, (char *)&sigpm[ig + (jj + izn * 35) * 20], (
			ftnlen)sizeof(real));
	    }
	    e_wsfe();
/* L1040: */
	}
/* L2000: */
    }

    io___78.ciunit = *iout;
    s_wsle(&io___78);
    e_wsle();
    io___79.ciunit = *iout;
    s_wsle(&io___79);
    e_wsle();
    io___80.ciunit = *iout;
    s_wsfe(&io___80);
    e_wsfe();
    io___81.ciunit = *iout;
    s_wsle(&io___81);
    e_wsle();

L9000:
    return 0;
} /* bnpedt_ */

#undef iwork


