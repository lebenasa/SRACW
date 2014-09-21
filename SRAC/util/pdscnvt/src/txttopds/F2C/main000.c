/* main000.f -- translated by f2c (version 20100827).
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
    integer ntnuc1, ntnuc2, nzon2, nzon3;
} setdt_;

#define setdt_1 setdt_

/* Table of constant values */

static integer c__1 = 1;
static integer c__9 = 9;
static integer c__3 = 3;
static integer c_b34 = 300000;

/* ----------------------------------------------------------------------- */
/*     MAIN PROGRAM TO */
/*     CONVERT TEXT-PDS TO PDS FOR SRAC95-UNIX (TXTTOPDS) */
/*     ASSUMPTION FOR TEXT FORMAT : */
/*      (1) FIRST LINE IS COMMENT */
/*      (2) COMMAND LINE FORMAT IS AS FOLLOWING: */
/*          *PUT  MENBER  TYPE  LENG */
/*          '*PUT' MUST BE LOCATED FROM THE FIRST COLUMN */
/*          '*PUT', MEMBER NAME(<A9), TYPE(ANY), LENG(<A11) ARE DIVIDED */
/*            BY SOME BLANKS */
/*      (3) DATA FORMAT (12A=1PE12.5) FOR FLOATING NUMBER */
/*      (4) DATA FORMAT (12A=11A,1X) FOR INTEGER NUMBER */
/*      (5) DATA FORMAT (12A=1X,A4,7X) FOR CHARACTER DATA */
/*      (6) 1-6 DATA(FLOATING OR INTEGER OR CHARACTER) IN A LINE */
/*      (7) FLOATING NUMBER ALWAYS INCLUDE '.' IN A DATA(A12) */

/*      SAMPLE : */
/*      COMMENT(1 LINE) */
/*      *PUT CU050000 N      9 */
/*                0           0  1.00000E-01......... */
/*                1 -2.00000E-04        125 ......... */
/*      *PUT MU050000 N     14 */
/*       1.00000E+02 2.00000E-02-3.00000E-04......... */
/*       1.00000E+02 2.00000E-02-3.00000E-04......... */
/*      -1.00000E+02 2.00000E-02 */
/*      ........... */
/*      ........... */
/*      *FIN */

/*   SPECIAL TREATMENT WILL BE DONE TO TREAT CHARACTER DATA FOR THE */
/*   MEMBERS : ----DN-T IN MACRO/MACROWRK */
/*             ----BNUP IN MACRO/MACROWRK */
/*             ----REST IN MACRO/MACROWRK */
/* ----------------------------------------------------------------------- */
/* Main program */ int MAIN__(void)
{
    /* System generated locals */
    integer i__1, i__2;
    alist al__1;

    /* Builtin functions */
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void),
	     s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer f_rew(alist *), s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, l, ld, irc;
    static real data[6];
    static integer leng;
    static char line[72];
    static integer nmem, ipos, kpos, iout;
    static real work[300000];
    static integer ldata, iotxt;
    extern /* Subroutine */ int setda1_(char *, integer *, real *, integer *, 
	    ftnlen), setda2_(char *, integer *, real *, integer *, ftnlen), 
	    setda3_(char *, integer *, real *, integer *, ftnlen);
    static char member[8], dirnam[72];
    extern /* Subroutine */ int setdat_(char *, integer *, real *, ftnlen), 
	    setmem_(char *, char *, integer *, ftnlen, ftnlen), uioset_(void),
	     pdsout_(char *, char *, real *, integer *, integer *, integer *, 
	    ftnlen, ftnlen), txtlin_(integer *, integer *);

    /* Fortran I/O blocks */
    static cilist io___3 = { 0, 5, 0, "(A72)", 0 };
    static cilist io___5 = { 0, 6, 0, 0, 0 };
    static cilist io___6 = { 0, 6, 0, 0, 0 };
    static cilist io___7 = { 0, 6, 0, 0, 0 };
    static cilist io___9 = { 0, 0, 0, "(A72)", 0 };
    static cilist io___11 = { 0, 0, 0, "(A72)", 0 };
    static cilist io___12 = { 0, 0, 0, 0, 0 };
    static cilist io___13 = { 0, 0, 0, 0, 0 };
    static cilist io___14 = { 0, 0, 0, 0, 0 };
    static cilist io___17 = { 0, 6, 0, 0, 0 };
    static cilist io___21 = { 0, 0, 0, "(A72)", 0 };
    static cilist io___28 = { 0, 6, 0, 0, 0 };



    uioset_();
    iotxt = 10;
    iout = 6;
/* ******************** */
/*  READ INPUT DATA  * */
/* ******************** */
/*     DIRNAM : FULL NAME OF DIRECTORY FOR PDS */
/*     EX:/DG05/UFS02/J9347/SRAC95/LIB/PDS/PFAST/PFASTJ2 */
    s_rsfe(&io___3);
    do_fio(&c__1, dirnam, (ftnlen)72);
    e_rsfe();
    if (*(unsigned char *)dirnam == ' ') {
	s_wsle(&io___5);
	do_lio(&c__9, &c__1, " ERROR(MAIN) : DIRECTORY NAME IS INVALID", (
		ftnlen)40);
	e_wsle();
	s_wsle(&io___6);
	do_lio(&c__9, &c__1, " THE FIRST COLUMN SHOULD BE NON-BLANK", (ftnlen)
		37);
	e_wsle();
	s_wsle(&io___7);
	do_lio(&c__9, &c__1, " DIRNAM = ", (ftnlen)10);
	do_lio(&c__9, &c__1, dirnam, (ftnlen)72);
	e_wsle();
	s_stop("", (ftnlen)0);
    }
/* ******************** */
/*  READ TEXT PDS    * */
/* ******************** */
    nmem = 0;
    al__1.aerr = 0;
    al__1.aunit = iotxt;
    f_rew(&al__1);
/* ----- SKIP 1 RECORD */
    io___9.ciunit = iotxt;
    s_rsfe(&io___9);
    do_fio(&c__1, line, (ftnlen)72);
    e_rsfe();
/* ----- SET MEMBER NAME & DATA LENGTH */
L1000:
    io___11.ciunit = iotxt;
    s_rsfe(&io___11);
    do_fio(&c__1, line, (ftnlen)72);
    e_rsfe();
    if (s_cmp(line, "*FIN", (ftnlen)4, (ftnlen)4) == 0) {
	io___12.ciunit = iout;
	s_wsle(&io___12);
	e_wsle();
	io___13.ciunit = iout;
	s_wsle(&io___13);
	do_lio(&c__9, &c__1, " NUMBER OF MEMBERS WRITTEN IN PDS=", (ftnlen)34)
		;
	do_lio(&c__3, &c__1, (char *)&nmem, (ftnlen)sizeof(integer));
	e_wsle();
	io___14.ciunit = iout;
	s_wsle(&io___14);
	do_lio(&c__9, &c__1, " ********** JOB END **********", (ftnlen)30);
	e_wsle();
	goto L9999;
    }
    setmem_(line, member, &leng, (ftnlen)72, (ftnlen)8);
    if (leng > 300000) {
	s_wsle(&io___17);
	do_lio(&c__9, &c__1, " ERROR (MAIN) : WORK AREA(MAXWK=", (ftnlen)32);
	do_lio(&c__3, &c__1, (char *)&c_b34, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ") IS LESS THAN REQUIRED SIZE(=", (ftnlen)30);
	do_lio(&c__3, &c__1, (char *)&leng, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, " IN MEMBER:", (ftnlen)11);
	do_lio(&c__9, &c__1, member, (ftnlen)8);
	e_wsle();
	s_stop("", (ftnlen)0);
    }
/* ----- SET NUMBER OF LINES TO BE READ FOR PDS DATA */
    txtlin_(&leng, &ldata);
/* ----- SET PDS DATA IN WORK DIMENSION */
    setdt_1.ntnuc1 = 0;
    setdt_1.ntnuc2 = 0;
    setdt_1.nzon2 = 0;
    setdt_1.nzon3 = 0;
    ipos = 0;
    i__1 = ldata;
    for (l = 1; l <= i__1; ++l) {
	io___21.ciunit = iotxt;
	s_rsfe(&io___21);
	do_fio(&c__1, line, (ftnlen)72);
	e_rsfe();
	kpos = ipos + 1;
	if (l != ldata) {
	    ld = 6;
	    if (s_cmp(member + 4, "DN", (ftnlen)2, (ftnlen)2) == 0 && *(
		    unsigned char *)&member[7] == 'T') {
		setda1_(line, &ld, data, &kpos, (ftnlen)72);
	    } else if (s_cmp(member + 4, "BNUP", (ftnlen)4, (ftnlen)4) == 0) {
		setda2_(line, &ld, data, &kpos, (ftnlen)72);
	    } else if (s_cmp(member + 4, "REST", (ftnlen)4, (ftnlen)4) == 0) {
		setda3_(line, &ld, data, &kpos, (ftnlen)72);
	    } else {
		setdat_(line, &ld, data, (ftnlen)72);
	    }
	    i__2 = ld;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		++ipos;
		work[ipos - 1] = data[i__ - 1];
/* L110: */
	    }
	} else {
	    ld = leng - (ldata - 1) * 6;
	    if (s_cmp(member + 4, "DN", (ftnlen)2, (ftnlen)2) == 0 && *(
		    unsigned char *)&member[7] == 'T') {
		setda1_(line, &ld, data, &kpos, (ftnlen)72);
	    } else if (s_cmp(member + 4, "BNUP", (ftnlen)4, (ftnlen)4) == 0) {
		setda2_(line, &ld, data, &kpos, (ftnlen)72);
	    } else if (s_cmp(member + 4, "REST", (ftnlen)4, (ftnlen)4) == 0) {
		setda3_(line, &ld, data, &kpos, (ftnlen)72);
	    } else {
		setdat_(line, &ld, data, (ftnlen)72);
	    }
	    i__2 = ld;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		++ipos;
		work[ipos - 1] = data[i__ - 1];
/* L120: */
	    }
	}
/* L100: */
    }
/* ************************** */
/*  WRITE WORK DATA IN PDS * */
/* ************************** */
    pdsout_(dirnam, member, work, &leng, &irc, &iout, (ftnlen)72, (ftnlen)8);
    if (irc != 0) {
	s_wsle(&io___28);
	do_lio(&c__9, &c__1, " ERROR(MAIN) : PDS ERROR, CODE =", (ftnlen)32);
	do_lio(&c__3, &c__1, (char *)&irc, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, " MEMBER =", (ftnlen)9);
	do_lio(&c__9, &c__1, member, (ftnlen)8);
	e_wsle();
	s_stop("", (ftnlen)0);
    } else {
	++nmem;
    }
    goto L1000;
L9999:
    s_stop("", (ftnlen)0);
    return 0;
} /* MAIN__ */

/* *********************************************************************** */

/*  UIOUNT   : SET UNFORMATED(0) OR FORMATED(1) */
/*             FOR EACH I/O DEVICE */

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
    ioform[10] = 1;
    return 0;
} /* uiount_ */

