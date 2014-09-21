/* uioset.f -- translated by f2c (version 20100827).
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

/* ===================================================================== */
/*  call uioint for initialization of i/o unit */
/*  the uioint is originally "ioinit.f" in sun-ews */
/*  set system dependent parameter */

/*        cctl        is .true. to turn on fortran-66 carriage control */
/*        bzro        is .true. to cause blank space to be zero on input */
/*        apnd        is .true. to open files at their end */
/*        prefix      is a string defining environment variables to */
/*                       be used to initialize logical units. */
/*                       ex. setenv fu02 file2.dat */
/*        vrbose      is .true. if the caller wants output showing the */
/*                       lu association */
/*        istder      is a device number of standerd error output */
/*        ideft       =0 : not open for the device prefix is not defined. */
/*                    =1 : open by defalt name(temp.nn) if prefix is not */
/*                         defined and ioform .GE. 0 (except 5,6 istder). */
/*        mxunit      maximum number of openable i/o devices */
/*                    mxunit = 64(Sun), 48(HP) */

/* ===================================================================== */
/* Subroutine */ int uioset_(void)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static logical ret, apnd, cctl, bzro;
    static integer ideft, istder;
    static char prefix[8];
    static logical vrbose;
    extern logical uioint_(logical *, logical *, logical *, char *, logical *,
	     integer *, integer *, integer *, ftnlen);
    static integer mxunit;

    /* Fortran I/O blocks */
    static cilist io___10 = { 0, 6, 0, 0, 0 };




    cctl = TRUE_;
    bzro = FALSE_;
    apnd = FALSE_;
    vrbose = FALSE_;
/*     vrbose = .true. */
    s_copy(prefix, "fu", (ftnlen)8, (ftnlen)2);
    istder = 0;
    ideft = 0;
    mxunit = 64;

/* c    systems other than BSD UNIX : ex. HP(istder = 7) */
/* c    systems for that rewind is allowed only for already opened device, */
/* c    set ideft = 1 (ex. HP) */
/* c    in HP, maximum number of openable i/o devices is 48. */

    ret = uioint_(&cctl, &bzro, &apnd, prefix, &vrbose, &istder, &ideft, &
	    mxunit, (ftnlen)8);
    if (ret) {
	return 0;
    } else {
	s_wsle(&io___10);
	do_lio(&c__9, &c__1, " I/O INITIALIZATION ERROR, STOP AT UIOSET ROUT"
		"INE", (ftnlen)49);
	e_wsle();
	s_stop("", (ftnlen)0);
    }
    return 0;
} /* uioset_ */

