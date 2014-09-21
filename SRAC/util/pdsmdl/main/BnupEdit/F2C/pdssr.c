/* pdssr.f -- translated by f2c (version 20100827).
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

/* *********************************************************************** */
/* UTILITY PROGRAM TO SEARCH PDS MEMBER                                 * */
/* FILNAM = DIRNAM/MEMBER                                               * */
/* *********************************************************************** */
/* Subroutine */ int pdssr_(char *filnam, integer *iexst, ftnlen filnam_len)
{
    /* System generated locals */
    inlist ioin__1;

    /* Builtin functions */
    integer f_inqu(inlist *);

    /* Local variables */
    static logical ex;



/* -------------------------------INPUT----------------------------------- */
/*     FILNAM     : FULL FILE NAME (A80) OF PDS MEMBER */
/*                  /XXX/XXX/MACRO/CASEA010 */
/* -------------------------------OUTPUT---------------------------------- */
/*     IEXST      : = 0  EXIST */
/*                  = 1  NOT EXIST */
/* ----------------------------------------------------------------------- */

    ioin__1.inerr = 0;
    ioin__1.infilen = 81;
    ioin__1.infile = filnam;
    ioin__1.inex = &ex;
    ioin__1.inopen = 0;
    ioin__1.innum = 0;
    ioin__1.innamed = 0;
    ioin__1.inname = 0;
    ioin__1.inacc = 0;
    ioin__1.inseq = 0;
    ioin__1.indir = 0;
    ioin__1.infmt = 0;
    ioin__1.inform = 0;
    ioin__1.inunf = 0;
    ioin__1.inrecl = 0;
    ioin__1.innrec = 0;
    ioin__1.inblank = 0;
    f_inqu(&ioin__1);
    if (! ex) {
	*iexst = 1;
    } else {
	*iexst = 0;
    }
    return 0;
} /* pdssr_ */

