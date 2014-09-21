/* ugtenv.f -- translated by f2c (version 20100827).
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

/* Subroutine */ int ugtenv_(char *envnam, char *envval, ftnlen envnam_len, 
	ftnlen envval_len)
{
    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer leng;
    extern /* Subroutine */ int getenv_(char *, char *, ftnlen, ftnlen);

/* ========================================================= */
/*  GET CHARACTERS ALLOCATED TO ENVIROMENTAL PARAMETER */
/*  ORIGINAL FUNCTION IS "GETENV", BUT IT IS SYSTEM-DEPENDENT */
/*  EX. SETENV FILE1 /USER/OKUMURA/KEISUKE.DATA */
/*      INPUT  : ENVNAM = 'FILE1' */
/*      OUTPUT : ENVVAL = '/USER/OKUMURA/KEISUKE.DATA' */

/* ========================================================= */

    leng = i_indx(envnam, " ", envnam_len, (ftnlen)1) - 1;
    if (leng <= 0) {
	getenv_(envnam, envval, envnam_len, envval_len);
    } else {
	getenv_(envnam, envval, leng, envval_len);
    }
    return 0;
} /* ugtenv_ */

