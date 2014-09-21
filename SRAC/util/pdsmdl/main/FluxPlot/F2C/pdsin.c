/* pdsin.f -- translated by f2c (version 20100827).
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

/* *********************************************************************** */
/* UTILITY PROGRAM TO READ/WRITE CONTENTS OF PDS FILE                   * */
/* PDSIN / PDSOUT(ENTRY)                                                * */
/* *********************************************************************** */
/* Subroutine */ int pdsin_0_(int n__, char *dirnam, char *member, real *work,
	 integer *leng, integer *irc, integer *iout, ftnlen dirnam_len, 
	ftnlen member_len)
{
    /* Format strings */
    static char fmt_6000[] = "(a,a,a,i7,a,a)";

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void), s_wsfe(cilist *), do_fio(integer *, char *, ftnlen),
	     e_wsfe(void);

    /* Local variables */
    static integer ierr, nleng;
    extern /* Subroutine */ int pdsrd_(char *, real *, integer *, integer *, 
	    ftnlen), pdsnm_(char *, char *, char *, integer *, integer *, 
	    ftnlen, ftnlen, ftnlen), pdssr_(char *, integer *, ftnlen);
    static integer iexst;
    extern /* Subroutine */ int pdswt_(char *, real *, integer *, integer *, 
	    ftnlen);
    static char filnam[81];

    /* Fortran I/O blocks */
    static cilist io___4 = { 0, 0, 0, 0, 0 };
    static cilist io___5 = { 0, 6, 0, 0, 0 };
    static cilist io___6 = { 0, 0, 0, 0, 0 };
    static cilist io___7 = { 0, 6, 0, 0, 0 };
    static cilist io___9 = { 0, 0, 0, 0, 0 };
    static cilist io___10 = { 0, 0, 0, 0, 0 };
    static cilist io___11 = { 0, 6, 0, 0, 0 };
    static cilist io___12 = { 0, 0, 0, 0, 0 };
    static cilist io___13 = { 0, 6, 0, 0, 0 };
    static cilist io___14 = { 0, 0, 0, 0, 0 };
    static cilist io___15 = { 0, 6, 0, 0, 0 };
    static cilist io___16 = { 0, 0, 0, fmt_6000, 0 };
    static cilist io___17 = { 0, 0, 0, 0, 0 };
    static cilist io___18 = { 0, 6, 0, 0, 0 };
    static cilist io___19 = { 0, 0, 0, 0, 0 };
    static cilist io___20 = { 0, 6, 0, 0, 0 };
    static cilist io___21 = { 0, 0, 0, 0, 0 };
    static cilist io___22 = { 0, 6, 0, 0, 0 };
    static cilist io___23 = { 0, 0, 0, 0, 0 };
    static cilist io___24 = { 0, 6, 0, 0, 0 };
    static cilist io___25 = { 0, 0, 0, 0, 0 };
    static cilist io___26 = { 0, 6, 0, 0, 0 };
    static cilist io___27 = { 0, 0, 0, 0, 0 };
    static cilist io___28 = { 0, 6, 0, 0, 0 };
    static cilist io___29 = { 0, 0, 0, fmt_6000, 0 };



/* ----------------------------------------------------------------------- */
/*     IRC : ERROR CODE */
/*         = 0 NORMAL END */
/*         = 1 MEMBER NOT FOUND IN READ MODE */
/*         = 2 MEMBER NAME IS EMPTY OR INVALID */
/*         = 3 DIRECTORY NAME IS EMPTY OR INVALID */
/*         = 4 MEMBER ALREADY EXIST IN WRITE MODE */
/*         = 5 PDS OPEN ERROR */
/*         = 6 PDS CLOSE ERROR */
/*         = 7 PDS READ ERROR */
/*         = 8 PDS WRITE ERROR */
/* ----------------------------------------------------------------------- */


    /* Parameter adjustments */
    --work;

    /* Function Body */
    switch(n__) {
	case 1: goto L_pdsout;
	}

    *irc = 0;
    pdsnm_(dirnam, member, filnam, &nleng, &ierr, (ftnlen)72, (ftnlen)8, (
	    ftnlen)81);
    if (ierr != 0) {
	if (ierr == 1) {
	    *irc = 2;
	    io___4.ciunit = *iout;
	    s_wsle(&io___4);
	    do_lio(&c__9, &c__1, " XX MEMBER NAME IS INVALID:", (ftnlen)27);
	    do_lio(&c__9, &c__1, member, (ftnlen)8);
	    e_wsle();
	    if (*iout != 6) {
		s_wsle(&io___5);
		do_lio(&c__9, &c__1, " XX MEMBER NAME IS INVALID:", (ftnlen)
			27);
		do_lio(&c__9, &c__1, member, (ftnlen)8);
		e_wsle();
	    }
	    return 0;
	} else if (ierr == 2) {
	    *irc = 3;
	    io___6.ciunit = *iout;
	    s_wsle(&io___6);
	    do_lio(&c__9, &c__1, " XX DIRECTORY NAME IS INVALID:", (ftnlen)30)
		    ;
	    do_lio(&c__9, &c__1, dirnam, (ftnlen)72);
	    e_wsle();
	    if (*iout != 6) {
		s_wsle(&io___7);
		do_lio(&c__9, &c__1, " XX DIRECTORY NAME IS INVALID:", (
			ftnlen)30);
		do_lio(&c__9, &c__1, dirnam, (ftnlen)72);
		e_wsle();
	    }
	    return 0;
	} else {
	    return 0;
	}
    }

    pdssr_(filnam, &iexst, (ftnlen)81);
    if (iexst == 1) {
	io___9.ciunit = *iout;
	s_wsle(&io___9);
	do_lio(&c__9, &c__1, " ** MEMBER ", (ftnlen)11);
	do_lio(&c__9, &c__1, member, (ftnlen)8);
	do_lio(&c__9, &c__1, " NOT FOUND IN ", (ftnlen)14);
	do_lio(&c__9, &c__1, dirnam, (ftnlen)72);
	e_wsle();
	*irc = 1;
	return 0;
    }

    pdsrd_(filnam, &work[1], leng, &ierr, (ftnlen)81);
    if (ierr != 0) {
	if (ierr == 1) {
	    *irc = 5;
	    io___10.ciunit = *iout;
	    s_wsle(&io___10);
	    do_lio(&c__9, &c__1, " XX PDS OPEN ERROR IN ", (ftnlen)22);
	    do_lio(&c__9, &c__1, filnam, (ftnlen)81);
	    e_wsle();
	    if (*iout != 6) {
		s_wsle(&io___11);
		do_lio(&c__9, &c__1, " XX PDS OPEN ERROR IN ", (ftnlen)22);
		do_lio(&c__9, &c__1, filnam, (ftnlen)81);
		e_wsle();
	    }
	    return 0;
	} else if (ierr == 2) {
	    *irc = 6;
	    io___12.ciunit = *iout;
	    s_wsle(&io___12);
	    do_lio(&c__9, &c__1, " XX PDS CLOSE ERROR IN ", (ftnlen)23);
	    do_lio(&c__9, &c__1, filnam, (ftnlen)81);
	    e_wsle();
	    if (*iout != 6) {
		s_wsle(&io___13);
		do_lio(&c__9, &c__1, " XX PDS CLOSE ERROR IN ", (ftnlen)23);
		do_lio(&c__9, &c__1, filnam, (ftnlen)81);
		e_wsle();
	    }
	    return 0;
	} else {
	    *irc = 7;
	    io___14.ciunit = *iout;
	    s_wsle(&io___14);
	    do_lio(&c__9, &c__1, " XX PDS READ ERROR IN ", (ftnlen)22);
	    do_lio(&c__9, &c__1, filnam, (ftnlen)81);
	    e_wsle();
	    if (*iout != 6) {
		s_wsle(&io___15);
		do_lio(&c__9, &c__1, " XX PDS READ ERROR IN ", (ftnlen)22);
		do_lio(&c__9, &c__1, filnam, (ftnlen)81);
		e_wsle();
	    }
	    return 0;
	}
    } else {
	io___16.ciunit = *iout;
	s_wsfe(&io___16);
	do_fio(&c__1, " ** MEMBER : ", (ftnlen)13);
	do_fio(&c__1, member, (ftnlen)8);
	do_fio(&c__1, " WAS READ  (", (ftnlen)12);
	do_fio(&c__1, (char *)&(*leng), (ftnlen)sizeof(integer));
	do_fio(&c__1, " WORDS) FROM ", (ftnlen)13);
	do_fio(&c__1, dirnam, (ftnlen)72);
	e_wsfe();
	return 0;
    }

/* ======================================================================= */


L_pdsout:

/* ======================================================================= */

    *irc = 0;
    pdsnm_(dirnam, member, filnam, &nleng, &ierr, (ftnlen)72, (ftnlen)8, (
	    ftnlen)81);
    if (ierr != 0) {
	if (ierr == 1) {
	    *irc = 2;
	    io___17.ciunit = *iout;
	    s_wsle(&io___17);
	    do_lio(&c__9, &c__1, " XX MEMBER NAME IS INVALID:", (ftnlen)27);
	    do_lio(&c__9, &c__1, member, (ftnlen)8);
	    e_wsle();
	    if (*iout != 6) {
		s_wsle(&io___18);
		do_lio(&c__9, &c__1, " XX MEMBER NAME IS INVALID:", (ftnlen)
			27);
		do_lio(&c__9, &c__1, member, (ftnlen)8);
		e_wsle();
	    }
	    return 0;
	} else if (ierr == 2) {
	    *irc = 3;
	    io___19.ciunit = *iout;
	    s_wsle(&io___19);
	    do_lio(&c__9, &c__1, " XX DIRECTORY NAME IS INVALID:", (ftnlen)30)
		    ;
	    do_lio(&c__9, &c__1, dirnam, (ftnlen)72);
	    e_wsle();
	    if (*iout != 6) {
		s_wsle(&io___20);
		do_lio(&c__9, &c__1, " XX DIRECTORY NAME IS INVALID:", (
			ftnlen)30);
		do_lio(&c__9, &c__1, dirnam, (ftnlen)72);
		e_wsle();
	    }
	    return 0;
	} else {
	    return 0;
	}
    }

    pdssr_(filnam, &iexst, (ftnlen)81);
    if (iexst == 0) {
	*irc = 4;
	io___21.ciunit = *iout;
	s_wsle(&io___21);
	do_lio(&c__9, &c__1, " XX MEMBER ", (ftnlen)11);
	do_lio(&c__9, &c__1, member, (ftnlen)8);
	do_lio(&c__9, &c__1, " ALREADY EXIST IN ", (ftnlen)18);
	do_lio(&c__9, &c__1, dirnam, (ftnlen)72);
	e_wsle();
	if (*iout != 6) {
	    s_wsle(&io___22);
	    do_lio(&c__9, &c__1, " XX MEMBER ", (ftnlen)11);
	    do_lio(&c__9, &c__1, member, (ftnlen)8);
	    do_lio(&c__9, &c__1, " ALREADY EXIST IN ", (ftnlen)18);
	    do_lio(&c__9, &c__1, dirnam, (ftnlen)72);
	    e_wsle();
	}
	return 0;
    }

    pdswt_(filnam, &work[1], leng, &ierr, (ftnlen)81);
    if (ierr != 0) {
	if (ierr == 1) {
	    *irc = 5;
	    io___23.ciunit = *iout;
	    s_wsle(&io___23);
	    do_lio(&c__9, &c__1, " XX PDS OPEN ERROR IN ", (ftnlen)22);
	    do_lio(&c__9, &c__1, filnam, (ftnlen)81);
	    e_wsle();
	    if (*iout != 6) {
		s_wsle(&io___24);
		do_lio(&c__9, &c__1, " XX PDS OPEN ERROR IN ", (ftnlen)22);
		do_lio(&c__9, &c__1, filnam, (ftnlen)81);
		e_wsle();
	    }
	    return 0;
	} else if (ierr == 2) {
	    *irc = 6;
	    io___25.ciunit = *iout;
	    s_wsle(&io___25);
	    do_lio(&c__9, &c__1, " XX PDS CLOSE ERROR IN ", (ftnlen)23);
	    do_lio(&c__9, &c__1, filnam, (ftnlen)81);
	    e_wsle();
	    if (*iout != 6) {
		s_wsle(&io___26);
		do_lio(&c__9, &c__1, " XX PDS CLOSE ERROR IN ", (ftnlen)23);
		do_lio(&c__9, &c__1, filnam, (ftnlen)81);
		e_wsle();
	    }
	    return 0;
	} else {
	    *irc = 8;
	    io___27.ciunit = *iout;
	    s_wsle(&io___27);
	    do_lio(&c__9, &c__1, " XX PDS WRITE ERROR IN ", (ftnlen)23);
	    do_lio(&c__9, &c__1, filnam, (ftnlen)81);
	    e_wsle();
	    if (*iout != 6) {
		s_wsle(&io___28);
		do_lio(&c__9, &c__1, " XX PDS WRITE ERROR IN ", (ftnlen)23);
		do_lio(&c__9, &c__1, filnam, (ftnlen)81);
		e_wsle();
	    }
	    return 0;
	}
    } else {
	io___29.ciunit = *iout;
	s_wsfe(&io___29);
	do_fio(&c__1, " ** MEMBER : ", (ftnlen)13);
	do_fio(&c__1, member, (ftnlen)8);
	do_fio(&c__1, " WAS WRITTEN (", (ftnlen)14);
	do_fio(&c__1, (char *)&(*leng), (ftnlen)sizeof(integer));
	do_fio(&c__1, " WORDS) IN ", (ftnlen)11);
	do_fio(&c__1, dirnam, (ftnlen)72);
	e_wsfe();
/* L6100: */
	return 0;
    }
    return 0;
} /* pdsin_ */

/* Subroutine */ int pdsin_(char *dirnam, char *member, real *work, integer *
	leng, integer *irc, integer *iout, ftnlen dirnam_len, ftnlen 
	member_len)
{
    return pdsin_0_(0, dirnam, member, work, leng, irc, iout, dirnam_len, 
	    member_len);
    }

/* Subroutine */ int pdsout_(char *dirnam, char *member, real *work, integer *
	leng, integer *irc, integer *iout, ftnlen dirnam_len, ftnlen 
	member_len)
{
    return pdsin_0_(1, dirnam, member, work, leng, irc, iout, dirnam_len, 
	    member_len);
    }

