/* micedt.f -- translated by f2c (version 20100827).
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
/*  PROGRAM TO EDIT EFFECTIVE MICRO XS FROM MICREF FILE                 * */
/*  VERSION : SRAC95 FOR UNIX                                           * */
/* *********************************************************************** */

/* Subroutine */ int micedt_(char *dirnam, integer *iout, integer *iprn, char 
	*micnm, integer *ng, integer *ngf, real *xsec, ftnlen dirnam_len, 
	ftnlen micnm_len)
{
    /* Format strings */
    static char fmt_7000[] = "(\002 \002,\002MICEDT\002,114(\002=\002))";
    static char fmt_7010[] = "(\002 \002,114(\002=\002),\002MICEDT\002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);

    /* Local variables */
    static integer j, ig, irc, nnc, nnf, ngt, nnp, nnt, isw, ieff, icap, leng,
	     ifis, isct;
    extern /* Subroutine */ int pdsin_(char *, char *, real *, integer *, 
	    integer *, integer *, ftnlen, ftnlen);
#define iwork ((integer *)&wkpds_1)
    static char member[8];

    /* Fortran I/O blocks */
    static cilist io___7 = { 0, 0, 0, 0, 0 };
    static cilist io___8 = { 0, 6, 0, 0, 0 };
    static cilist io___9 = { 0, 0, 0, 0, 0 };
    static cilist io___10 = { 0, 6, 0, 0, 0 };
    static cilist io___12 = { 0, 0, 0, 0, 0 };
    static cilist io___13 = { 0, 6, 0, 0, 0 };
    static cilist io___14 = { 0, 0, 0, 0, 0 };
    static cilist io___15 = { 0, 6, 0, 0, 0 };
    static cilist io___17 = { 0, 0, 0, 0, 0 };
    static cilist io___18 = { 0, 6, 0, 0, 0 };
    static cilist io___19 = { 0, 0, 0, 0, 0 };
    static cilist io___20 = { 0, 6, 0, 0, 0 };
    static cilist io___23 = { 0, 0, 0, 0, 0 };
    static cilist io___24 = { 0, 6, 0, 0, 0 };
    static cilist io___26 = { 0, 0, 0, 0, 0 };
    static cilist io___27 = { 0, 6, 0, 0, 0 };
    static cilist io___28 = { 0, 0, 0, 0, 0 };
    static cilist io___29 = { 0, 6, 0, 0, 0 };
    static cilist io___30 = { 0, 0, 0, 0, 0 };
    static cilist io___31 = { 0, 6, 0, 0, 0 };
    static cilist io___33 = { 0, 0, 0, 0, 0 };
    static cilist io___34 = { 0, 6, 0, 0, 0 };
    static cilist io___39 = { 0, 0, 0, 0, 0 };
    static cilist io___40 = { 0, 0, 0, fmt_7000, 0 };
    static cilist io___41 = { 0, 0, 0, 0, 0 };
    static cilist io___42 = { 0, 0, 0, 0, 0 };
    static cilist io___43 = { 0, 0, 0, 0, 0 };
    static cilist io___44 = { 0, 0, 0, 0, 0 };
    static cilist io___45 = { 0, 0, 0, 0, 0 };
    static cilist io___46 = { 0, 0, 0, 0, 0 };
    static cilist io___47 = { 0, 0, 0, 0, 0 };
    static cilist io___48 = { 0, 0, 0, "(A)", 0 };
    static cilist io___49 = { 0, 0, 0, "(A/(1P10E12.5))", 0 };
    static cilist io___50 = { 0, 0, 0, "(A/(1P10E12.5))", 0 };
    static cilist io___51 = { 0, 0, 0, "(A/(1P10E12.5))", 0 };
    static cilist io___52 = { 0, 0, 0, "(A/(1P10E12.5))", 0 };
    static cilist io___53 = { 0, 0, 0, "(A/(1P10E12.5))", 0 };
    static cilist io___54 = { 0, 0, 0, "(A/(1P10E12.5))", 0 };
    static cilist io___55 = { 0, 0, 0, 0, 0 };
    static cilist io___56 = { 0, 0, 0, fmt_7010, 0 };
    static cilist io___57 = { 0, 0, 0, 0, 0 };



/* =========================== FOR MAIN ================================== */
/* DEL  PARAMETER  (MAXNG=107, MAXXS=10) */
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
/* DEL  PARAMETER  (MAXWRK=15000) */

/* ---------------------------- INPUT ------------------------------------ */
/*     DIRNAM     : DIRECTORY NAME (A72) OF PDS : /XXX/XXX/MICREF01 */
/*     IOUT       : LOGICAL DEVICE FOR OUTPUT */
/*     IPRN       : =0(NO PRINT), =1(PRINT OUT IN DEVICE IOUT) */
/*     MICNM      : MEMBER NAME(A8) OF MICRO XS (XZZMCBFT) */
/*                   X  : INTERNALY SET */
/*                   ZZM: NUCLIDE-TAG */
/*                   C  : CHEMICAL-TAG (USUALY C='0') */
/*                   B  : BURNUP-TAG */
/*                   F  : MIXTURE-TAG */
/*                   T  : TEMPERATURE-TAG(NEAREST T-TAG TO MIXTURE TEMP) */
/*                        CAUTION:T-TAG IN SRAC INPUT IS INEFFECTIVE */
/*                   EXAMPLE MICNM='XU0804Z9' */
/* ---------------------------- OUTPUT ----------------------------------- */
/*     NGF        : NUMBER OF FAST ENERGY GROUPS */
/*     NG         : NUMBER OF TOTAL ENERGY GROUPS */
/*     XSEC(G,I)  : MICROSCOPIC CROSS SECTION */
/*                  I=1 : PRODUCTION */
/*                  I=2 : FISSION */
/*                  I=3 : CAPTURE */
/*                  I=4 : ABSORPTION */
/*                  I=5 : TOTAL */
/*                  I=6 : FISSION SPECTRUM */
/* ----------------------------------------------------------------------- */
/* ************************** */
/*      ZERO SETTING       *-------------------------------------------- */
/* ************************** */
    /* Parameter adjustments */
    xsec -= 108;

    /* Function Body */
    for (ig = 1; ig <= 107; ++ig) {
	for (j = 1; j <= 10; ++j) {
	    xsec[ig + j * 107] = 0.f;
/* L100: */
	}
    }
/* ************************************* */
/*  READ NUMBER OF ENERGY GROUP       *--------------------------------- */
/* ************************************* */
    s_copy(member, "CONTF002", (ftnlen)8, (ftnlen)8);
    pdsin_(dirnam, member, wkpds_1.work, &leng, &irc, iout, (ftnlen)72, (
	    ftnlen)8);
    if (irc != 0) {
	io___7.ciunit = *iout;
	s_wsle(&io___7);
	do_lio(&c__9, &c__1, " ERROR(MICEDT): PDSIN ERROR, CODE=", (ftnlen)34)
		;
	do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___8);
	    do_lio(&c__9, &c__1, " ERROR(MICEDT): PDSIN ERROR, CODE=", (
		    ftnlen)34);
	    do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	    e_wsle();
	}
	s_stop("", (ftnlen)0);
    }
    *ngf = iwork[0];

    s_copy(member, "CONTT002", (ftnlen)8, (ftnlen)8);
    pdsin_(dirnam, member, wkpds_1.work, &leng, &irc, iout, (ftnlen)72, (
	    ftnlen)8);
    if (irc != 0) {
	if (irc == 1) {
	    io___9.ciunit = *iout;
	    s_wsle(&io___9);
	    do_lio(&c__9, &c__1, " CAUTION(MICEDT): MEMBER CONTT000 NOT FOUND"
		    , (ftnlen)43);
	    do_lio(&c__9, &c__1, " THEN, NGT=0 IS ASSUMED", (ftnlen)23);
	    e_wsle();
	    if (*iout != 6) {
		s_wsle(&io___10);
		do_lio(&c__9, &c__1, " CAUTION(MICEDT): MEMBER CONTT000 NOT "
			"FOUND", (ftnlen)43);
		do_lio(&c__9, &c__1, " THEN, NGT=0 IS ASSUMED", (ftnlen)23);
		e_wsle();
	    }
	    ngt = 0;
	} else {
	    io___12.ciunit = *iout;
	    s_wsle(&io___12);
	    do_lio(&c__9, &c__1, " ERROR(MICEDT): PDSIN ERROR, CODE=", (
		    ftnlen)34);
	    do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	    e_wsle();
	    if (*iout != 6) {
		s_wsle(&io___13);
		do_lio(&c__9, &c__1, " ERROR(MICEDT): PDSIN ERROR, CODE=", (
			ftnlen)34);
		do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
		e_wsle();
	    }
	    s_stop("", (ftnlen)0);
	}
    } else {
	ngt = iwork[0];
    }

    *ng = *ngf + ngt;
    if (*ng > 107) {
	io___14.ciunit = *iout;
	s_wsle(&io___14);
	do_lio(&c__9, &c__1, " ERROR(MICEDT): NUMBER OF ENERGY GROUPS(=", (
		ftnlen)41);
	do_lio(&c__3, &c__1, (char *)&(*ng), (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ") IS GREATER THAN THE SET VALUE(=", (ftnlen)33);
	do_lio(&c__3, &c__1, (char *)&c__107, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ")", (ftnlen)1);
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___15);
	    do_lio(&c__9, &c__1, " ERROR(MICEDT): NUMBER OF ENERGY GROUPS(=", 
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
/* ************************************* */
/*  READ CONTROL MEMBER OF FAST GROUP *--------------------------------- */
/*  CzzmFbxt or CzzmF000              * */
/* ************************************* */
    s_copy(member, micnm, (ftnlen)8, (ftnlen)8);
    *(unsigned char *)member = 'C';
    *(unsigned char *)&member[4] = 'F';
    ieff = 1;
    pdsin_(dirnam, member, wkpds_1.work, &leng, &irc, iout, (ftnlen)72, (
	    ftnlen)8);
    if (irc == 1) {
	s_copy(member + 5, "000", (ftnlen)3, (ftnlen)3);
	ieff = 0;
	pdsin_(dirnam, member, wkpds_1.work, &leng, &irc, iout, (ftnlen)72, (
		ftnlen)8);
	if (irc != 0) {
	    io___17.ciunit = *iout;
	    s_wsle(&io___17);
	    do_lio(&c__9, &c__1, " ERROR(MICEDT): PDSIN ERROR, CODE=", (
		    ftnlen)34);
	    do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	    e_wsle();
	    if (*iout != 6) {
		s_wsle(&io___18);
		do_lio(&c__9, &c__1, " ERROR(MICEDT): PDSIN ERROR, CODE=", (
			ftnlen)34);
		do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
		e_wsle();
	    }
	    s_stop("", (ftnlen)0);
	}
    } else if (irc != 0) {
	io___19.ciunit = *iout;
	s_wsle(&io___19);
	do_lio(&c__9, &c__1, " ERROR(MICEDT): PDSIN ERROR, CODE=", (ftnlen)34)
		;
	do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___20);
	    do_lio(&c__9, &c__1, " ERROR(MICEDT): PDSIN ERROR, CODE=", (
		    ftnlen)34);
	    do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	    e_wsle();
	}
	s_stop("", (ftnlen)0);
    }

    icap = iwork[0];
    ifis = iwork[1];
/* ******************************************* */
/*  READ FAST GROUP XS FROM MICREF          *--------------------------- */
/*  MzzmFbxt or MzzmF000                    * */
/* ******************************************* */
    *(unsigned char *)member = 'M';
    pdsin_(dirnam, member, wkpds_1.work, &leng, &irc, iout, (ftnlen)72, (
	    ftnlen)8);
    if (irc != 0) {
	io___23.ciunit = *iout;
	s_wsle(&io___23);
	do_lio(&c__9, &c__1, " ERROR(MICEDT): PDSIN ERROR, CODE=", (ftnlen)34)
		;
	do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___24);
	    do_lio(&c__9, &c__1, " ERROR(MICEDT): PDSIN ERROR, CODE=", (
		    ftnlen)34);
	    do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	    e_wsle();
	}
	s_stop("", (ftnlen)0);
    }
/* ------- READ SIG-C ------- */
    isw = 0;
    if (icap == 1) {
	i__1 = *ngf;
	for (j = 1; j <= i__1; ++j) {
	    xsec[j + 321] = wkpds_1.work[j - 1];
	    xsec[j + 428] = wkpds_1.work[j - 1];
/* L200: */
	}
	isw = *ngf;
    }
/* ------- READ SIG-F AND SET SIG-P, SIG-A, */
    if (ifis == 1) {
	i__1 = *ngf;
	for (j = 1; j <= i__1; ++j) {
	    xsec[j + 107] = wkpds_1.work[isw + j - 1] * wkpds_1.work[isw + *
		    ngf + j - 1];
	    xsec[j + 214] = wkpds_1.work[isw + j - 1];
	    xsec[j + 428] = wkpds_1.work[isw + j - 1] + xsec[j + 321];
	    xsec[j + 642] = wkpds_1.work[isw + (*ngf << 1) + j - 1];
/* L210: */
	}
    }
/* ------- READ SIG-T ------- */
    isw = icap * *ngf + ifis * 3 * *ngf + *ngf;
    i__1 = *ngf;
    for (j = 1; j <= i__1; ++j) {
	xsec[j + 535] = wkpds_1.work[isw + j - 1];
/* L220: */
    }
/* **************************************** */
/*  READ CONTROL MEMBER OF THERMAL GROUP *------------------------------- */
/*  CzzmTbxt or CzzmT00t (Czzmc00t)      * */
/* **************************************** */
/*  present SRAC do not support C-Tag in MICREF */
    if (ngt <= 0) {
	goto L1000;
    }
    s_copy(member, micnm, (ftnlen)8, (ftnlen)8);
    *(unsigned char *)member = 'C';
    *(unsigned char *)&member[4] = 'T';
    ieff = 1;
    pdsin_(dirnam, member, wkpds_1.work, &leng, &irc, iout, (ftnlen)72, (
	    ftnlen)8);
    if (irc == 1) {
/* KSK    MEMBER(5:5) = MICNM(5:5) */
	s_copy(member + 5, "00", (ftnlen)2, (ftnlen)2);
	ieff = 0;
	pdsin_(dirnam, member, wkpds_1.work, &leng, &irc, iout, (ftnlen)72, (
		ftnlen)8);
	if (irc != 0) {
	    io___26.ciunit = *iout;
	    s_wsle(&io___26);
	    do_lio(&c__9, &c__1, " ERROR(MICEDT): PDSIN ERROR, CODE=", (
		    ftnlen)34);
	    do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	    e_wsle();
	    if (*iout != 6) {
		s_wsle(&io___27);
		do_lio(&c__9, &c__1, " ERROR(MICEDT): PDSIN ERROR, CODE=", (
			ftnlen)34);
		do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
		e_wsle();
	    }
	    s_stop("", (ftnlen)0);
	}
    } else if (irc != 0) {
	io___28.ciunit = *iout;
	s_wsle(&io___28);
	do_lio(&c__9, &c__1, " ERROR(MICEDT): PDSIN ERROR, CODE=", (ftnlen)34)
		;
	do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___29);
	    do_lio(&c__9, &c__1, " ERROR(MICEDT): PDSIN ERROR, CODE=", (
		    ftnlen)34);
	    do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	    e_wsle();
	}
	s_stop("", (ftnlen)0);
    }
/*     IF(WORK(2).EQ.0) THEN */
/*       ISCT=0 */
/*     ELSE */
/*       ISCT=1 */
/*     ENDIF */
/* ******************************* */
/*  READ THERMAL XS FROM MICREF *---------------------------------------- */
/*  KzzmTbxt or Kzzmc00t        * */
/* ******************************* */
    *(unsigned char *)member = 'K';
    pdsin_(dirnam, member, wkpds_1.work, &leng, &irc, iout, (ftnlen)72, (
	    ftnlen)8);
    if (irc != 0) {
	io___30.ciunit = *iout;
	s_wsle(&io___30);
	do_lio(&c__9, &c__1, " ERROR(MICEDT): PDSIN ERROR, CODE=", (ftnlen)34)
		;
	do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___31);
	    do_lio(&c__9, &c__1, " ERROR(MICEDT): PDSIN ERROR, CODE=", (
		    ftnlen)34);
	    do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	    e_wsle();
	}
	s_stop("", (ftnlen)0);
    }

    if (leng == ngt * 5) {
	isct = 0;
    } else if (leng == ngt * (ngt + 5)) {
	isct = 1;
    } else {
	io___33.ciunit = *iout;
	s_wsle(&io___33);
	do_lio(&c__9, &c__1, " ERROR(MICEDT): LENGTH(", (ftnlen)23);
	do_lio(&c__3, &c__1, (char *)&leng, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ") OF MEMBER:", (ftnlen)12);
	do_lio(&c__9, &c__1, member, (ftnlen)8);
	do_lio(&c__9, &c__1, " IS NOT CONSISTENT", (ftnlen)18);
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___34);
	    do_lio(&c__9, &c__1, " ERROR(MICEDT): LENGTH(", (ftnlen)23);
	    do_lio(&c__3, &c__1, (char *)&leng, (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, ") OF MEMBER:", (ftnlen)12);
	    do_lio(&c__9, &c__1, member, (ftnlen)8);
	    do_lio(&c__9, &c__1, " IS NOT CONSISTENT", (ftnlen)18);
	    e_wsle();
	}
    }

    nnc = isct * ngt * ngt + ngt;
    nnf = nnc + (ngt << 1);
    nnp = nnc + ngt * 3;
    nnt = nnc + ngt;
    i__1 = ngt;
    for (j = 1; j <= i__1; ++j) {
	xsec[*ngf + j + 107] = wkpds_1.work[nnf + j - 1] * wkpds_1.work[nnp + 
		j - 1];
	xsec[*ngf + j + 214] = wkpds_1.work[nnf + j - 1];
	xsec[*ngf + j + 321] = wkpds_1.work[nnc + j - 1];
	xsec[*ngf + j + 428] = wkpds_1.work[nnc + j - 1] + wkpds_1.work[nnf + 
		j - 1];
	xsec[*ngf + j + 535] = wkpds_1.work[nnt + j - 1];
/* L300: */
    }
/* ************************** */
/*     PRINT OUT           *-------------------------------------------- */
/* ************************** */
L1000:
    if (*iprn == 1) {
	io___39.ciunit = *iout;
	s_wsle(&io___39);
	e_wsle();
	io___40.ciunit = *iout;
	s_wsfe(&io___40);
	e_wsfe();
	io___41.ciunit = *iout;
	s_wsle(&io___41);
	e_wsle();
	io___42.ciunit = *iout;
	s_wsle(&io___42);
	do_lio(&c__9, &c__1, "    ***** MICRO XS MEMBER NAME = ", (ftnlen)33);
	do_lio(&c__9, &c__1, micnm, (ftnlen)8);
	do_lio(&c__9, &c__1, "*****", (ftnlen)5);
	e_wsle();
	io___43.ciunit = *iout;
	s_wsle(&io___43);
	e_wsle();
	io___44.ciunit = *iout;
	s_wsle(&io___44);
	do_lio(&c__9, &c__1, "    NGF = ", (ftnlen)10);
	do_lio(&c__3, &c__1, (char *)&(*ngf), (ftnlen)sizeof(integer));
	e_wsle();
	io___45.ciunit = *iout;
	s_wsle(&io___45);
	do_lio(&c__9, &c__1, "    NGT = ", (ftnlen)10);
	do_lio(&c__3, &c__1, (char *)&ngt, (ftnlen)sizeof(integer));
	e_wsle();
	io___46.ciunit = *iout;
	s_wsle(&io___46);
	do_lio(&c__9, &c__1, "    NG  = ", (ftnlen)10);
	do_lio(&c__3, &c__1, (char *)&(*ng), (ftnlen)sizeof(integer));
	e_wsle();
	io___47.ciunit = *iout;
	s_wsle(&io___47);
	e_wsle();
	io___48.ciunit = *iout;
	s_wsfe(&io___48);
	do_fio(&c__1, "**** MICROSCOPIC CROSS SECTION ****", (ftnlen)35);
	e_wsfe();
	io___49.ciunit = *iout;
	s_wsfe(&io___49);
	do_fio(&c__1, " PRODUCTION", (ftnlen)11);
	i__1 = *ng;
	for (ig = 1; ig <= i__1; ++ig) {
	    do_fio(&c__1, (char *)&xsec[ig + 107], (ftnlen)sizeof(real));
	}
	e_wsfe();
	io___50.ciunit = *iout;
	s_wsfe(&io___50);
	do_fio(&c__1, " FISSION   ", (ftnlen)11);
	i__1 = *ng;
	for (ig = 1; ig <= i__1; ++ig) {
	    do_fio(&c__1, (char *)&xsec[ig + 214], (ftnlen)sizeof(real));
	}
	e_wsfe();
	io___51.ciunit = *iout;
	s_wsfe(&io___51);
	do_fio(&c__1, " CAPTURE   ", (ftnlen)11);
	i__1 = *ng;
	for (ig = 1; ig <= i__1; ++ig) {
	    do_fio(&c__1, (char *)&xsec[ig + 321], (ftnlen)sizeof(real));
	}
	e_wsfe();
	io___52.ciunit = *iout;
	s_wsfe(&io___52);
	do_fio(&c__1, " ABSORPTION", (ftnlen)11);
	i__1 = *ng;
	for (ig = 1; ig <= i__1; ++ig) {
	    do_fio(&c__1, (char *)&xsec[ig + 428], (ftnlen)sizeof(real));
	}
	e_wsfe();
	io___53.ciunit = *iout;
	s_wsfe(&io___53);
	do_fio(&c__1, " TOTAL     ", (ftnlen)11);
	i__1 = *ng;
	for (ig = 1; ig <= i__1; ++ig) {
	    do_fio(&c__1, (char *)&xsec[ig + 535], (ftnlen)sizeof(real));
	}
	e_wsfe();
	io___54.ciunit = *iout;
	s_wsfe(&io___54);
	do_fio(&c__1, " FISS.SPECT", (ftnlen)11);
	i__1 = *ng;
	for (ig = 1; ig <= i__1; ++ig) {
	    do_fio(&c__1, (char *)&xsec[ig + 642], (ftnlen)sizeof(real));
	}
	e_wsfe();
	io___55.ciunit = *iout;
	s_wsle(&io___55);
	e_wsle();
	io___56.ciunit = *iout;
	s_wsfe(&io___56);
	e_wsfe();
	io___57.ciunit = *iout;
	s_wsle(&io___57);
	e_wsle();
    }

/* L9000: */
    return 0;
} /* micedt_ */

#undef iwork


