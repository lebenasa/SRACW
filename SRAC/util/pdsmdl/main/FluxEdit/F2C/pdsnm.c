/* pdsnm.f -- translated by f2c (version 20100827).
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

static integer c__3 = 3;

/* *********************************************************************** */
/* UTILITY PROGRAM TO GIVE FULL NAME OF PDS MEMBER                      * */
/* FILNAM = DIRNAM/MEMBER                                               * */
/* *********************************************************************** */
/* Subroutine */ int pdsnm_(char *dirnam, char *member, char *filnam, integer 
	*nleng, integer *ierr, ftnlen dirnam_len, ftnlen member_len, ftnlen 
	filnam_len)
{
    /* System generated locals */
    address a__1[3];
    integer i__1[3];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);

    /* Local variables */
    static integer i__, mleng, nlengw;



/* -------------------------------INPUT----------------------------------- */
/*     DIRNAM     : DIRECTORY NAME (A72) OF PDS : /XXX/XXX/MACRO */
/*     MEMBER     : PDS MEMBER NAME (A8) : CASEA010 */
/* -------------------------------OUTPUT---------------------------------- */
/*     FILNAM     : FULL FILE NAME (A80) OF PDS MEMBER */
/*                  /XXX/XXX/MACRO/CASEA010 */
/*     NLENG      : LENGTH OF FILE NAME */
/*     IERR       : ERROR CODE =0 : NORMAL END */
/*                             =1 : MEMBER NAME IS EMPTY OR INVALID */
/*                             =2 : DIRECTORY NAME IS EMPTY OR INVALID */
/* ----------------------------------------------------------------------- */

    *ierr = 0;
    if (*(unsigned char *)member == ' ') {
	*ierr = 1;
	return 0;
    }
    if (*(unsigned char *)dirnam == ' ') {
	*ierr = 2;
	return 0;
    }

    s_copy(filnam, " ", (ftnlen)81, (ftnlen)1);
    *nleng = 0;
    for (i__ = 1; i__ <= 72; ++i__) {
	if (*(unsigned char *)&dirnam[i__ - 1] != ' ') {
	    ++(*nleng);
	} else {
	    goto L200;
	}
/* L100: */
    }
L200:
    if (*nleng == 0) {
	*ierr = 2;
	return 0;
    }

    mleng = 0;
    for (i__ = 1; i__ <= 8; ++i__) {
/* KSK    IF(MEMBER(I:I).NE.' ') THEN */
	if (*(unsigned char *)&member[i__ - 1] != ' ' && *(unsigned char *)&
		member[i__ - 1] != '\t') {
	    ++mleng;
	} else {
	    goto L400;
	}
/* L300: */
    }

L400:
    if (mleng == 0) {
	*ierr = 1;
	return 0;
    }
    nlengw = *nleng;
    *nleng = *nleng + 1 + mleng;
/* Writing concatenation */
    i__1[0] = nlengw, a__1[0] = dirnam;
    i__1[1] = 1, a__1[1] = "/";
    i__1[2] = 8, a__1[2] = member;
    s_cat(filnam, a__1, i__1, &c__3, (*nleng));
    return 0;
} /* pdsnm_ */

