/* uioint.f -- translated by f2c (version 20100827).
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

/* uioint(originaly ioinit) : initialize the I/O system */
/*        @(#)ioinit.f 1.8 89/02/09 SMI; from UCB 1.5 */
/* synopsis: */
/*        logical function uioint (cctl, bzro, apnd, prefix, vrbose, */
/*                                 istder, ideft, mxunit) */
/*        logical cctl, bzro, apnd, vrbose */
/*        character*(*) prefix */
/*        integer istder, ideft, mxunit */

/* where: */
/*        cctl        is .true. to turn on fortran-66 carriage control */
/*        bzro        is .true. to cause blank space to be zero on input */
/*        apnd        is .true. to open files at their end */
/*        prefix      is a string defining environment variables to */
/*                       be used to initialize logical units. */
/*        vrbose      is .true. if the caller wants output showing the */
/*                       lu association */
/*        istder      is a device number of standerd error output */
/*        ideft       =0 : not open for the device prefix is not defined. */
/*                    =1 : open by defalt name(temp.nn) if prefix is not */
/*                         defined and ioform .GE. 0 (except 5,6 istder). */
/*        mxunit      maximum number of openable i/o devices */
/*                    mxunit = 64(Sun), 48(HP) */

/* returns: */
/*        .true. if all went well */

/* -------------------------------------------------------------------- */
/*  David L. Wasley (U.C.Bekeley) */
/*  Modified by M.Sasaki (The Japan Research Institute Ltd., Tokyo,Japan) */
/*  Modified by K.Okumura (JAERI) and M.Ido (ITJ) */

/*  * Make applicable to systems other than BSD UNIX such as HP. */
/*  * Make applicable to also unformatted files. */

/*     I/O unit # of standard error may be other than 0 (ex. 7 in HP) */
/*     Function "lnblnk" may not exist. */
/*     Function "perror" may not exist. */
/*     Using tabs in program source may cause trouble. */
/*     REWIND is not allowed for not-opened devices in HP */
/*     See also the subroutines (uioset.f, uiount.f) */
/* ---------------------------------------------------------------------- */

logical uioint_(logical *cctl, logical *bzro, logical *apnd, char *prefix, 
	logical *vrbose, integer *istder, integer *ideft, integer *mxunit, 
	ftnlen prefix_len)
{
    /* Format strings */
    static char fmt_2002[] = "(\002 uioint: initializing from \002,a,\002n"
	    "n\002)";
    static char fmt_2005[] = "(\002 uioint: number of opened unit is upper-l"
	    "imit\002)";
    static char fmt_2000[] = "(\002 uioint: logical unit \002,i2,\002 opened"
	    " to \002,a)";
    static char fmt_2003[] = "(\002 uioint: \002,a,\002: FILE OPEN ERROR "
	    "\002)";
    static char fmt_2001[] = "(\002 uioint: no initialization found for \002"
	    ",a)";
    static char fmt_2004[] = "(\002 uioint: cctl=\002,a,\002, bzro=\002,a"
	    ",\002, apnd=\002,a)";

    /* System generated locals */
    integer i__1;
    logical ret_val;
    icilist ici__1;
    olist o__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer i_len(char *, ftnlen), s_cmp(char *, char *, ftnlen, ftnlen), 
	    i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void), s_wsfi(icilist *), 
	    e_wsfi(void), f_open(olist *);

    /* Local variables */
    static integer nb, lp, lu;
    static logical iok;
    static integer ieof, ictl;
    static logical fenv, ienv;
    static char form[16];
    static integer izro;
    static char torf1[8], torf2[8], torf3[8], ename[32], fname[256], blank[16]
	    , tname[8];
    static integer ntunt, lnblnk, ioform[100];
    extern /* Subroutine */ int ugtenv_(char *, char *, ftnlen, ftnlen), 
	    uiount_(integer *);

    /* Fortran I/O blocks */
    static cilist io___15 = { 0, 0, 0, fmt_2002, 0 };
    static icilist io___18 = { 0, tname+5, 0, "(i2.2)", 2, 1 };
    static cilist io___19 = { 0, 0, 0, fmt_2005, 0 };
    static cilist io___20 = { 0, 0, 0, fmt_2005, 0 };
    static cilist io___22 = { 0, 0, 0, fmt_2000, 0 };
    static cilist io___23 = { 0, 0, 0, fmt_2003, 0 };
    static cilist io___24 = { 0, 0, 0, fmt_2001, 0 };
    static cilist io___28 = { 0, 0, 0, fmt_2004, 0 };



/* :automatic may be invalid in some systems(SX3) */
/* DEL    automatic        iok, fenv, ienv, ename, fname, form, blank */
/* DEL    integer*2        ieof,  ictl,  izro */
/* :full specification of open parameter is desirable. */
/* MOD    character        form, blank */

/* ################################################################### */
/* IF (Version of Sun SPARC Fortran Compiler .GE. 3.0) THEN */
/*       common /__ioiflg/        ieof, ictl, izro */
/* ELSE */
/* DEL    common /ioiflg/          ieof, ictl, izro */
/* ENDIF */
/* ################################################################### */

/* :ioform <0 not open, = 0 open in unformatted, =1 open in formatted */
/* ioform is set in program dependent subroutine (uiount) */

/* -------------- Process Start ----------------------------------------- */

    ntunt = 0;
    s_copy(tname, "temp.nm", (ftnlen)8, (ftnlen)7);
    uiount_(ioform);

    if (*cctl) {
	ictl = 1;
/* : SUN Specific file form 'PRINT' may not be supported in other systems. */
/* MOD        form = 'PRINT' */
	s_copy(form, "FORMATTED", (ftnlen)16, (ftnlen)9);
    } else {
	ictl = 0;
/* MOD        form = 'f' */
	s_copy(form, "FORMATTED", (ftnlen)16, (ftnlen)9);
    }

    if (*bzro) {
	izro = 1;
/* MOD        blank = 'z' */
	s_copy(blank, "ZERO", (ftnlen)16, (ftnlen)4);
    } else {
	izro = 0;
/* MOD        blank = 'n' */
	s_copy(blank, "NULL", (ftnlen)16, (ftnlen)4);
    }

/* KSK standard I/O device should not open for IBM AIX RS/6000 */
/*    because fort.5, fort.6 will be allocated. */
/* IBM    open (unit=5, form=form, blank=blank) */
/* IBM    open (unit=6, form=form, blank=blank) */
    ntunt += 2;

    if (*apnd) {
	ieof = 1;
    } else {
	ieof = 0;
    }

    iok = TRUE_;
    fenv = FALSE_;
    ienv = FALSE_;
    lp = i_len(prefix, prefix_len);

    if (lp > 0 && lp <= 30 && s_cmp(prefix, " ", prefix_len, (ftnlen)1) != 0) 
	    {
	ienv = TRUE_;
	nb = i_indx(prefix, " ", prefix_len, (ftnlen)1);
	if (nb == 0) {
	    nb = lp + 1;
	}
	s_copy(ename, prefix, (ftnlen)32, prefix_len);
	if (*vrbose) {
	    io___15.ciunit = *istder;
	    s_wsfe(&io___15);
	    do_fio(&c__1, ename, nb - 1);
	    e_wsfe();
	}

/* MOD        do 200 lu = 0, nounit-1 */
	for (lu = 1; lu <= 99; ++lu) {
	    ici__1.icierr = 0;
	    ici__1.icirnum = 1;
	    ici__1.icirlen = 32 - (nb - 1);
	    ici__1.iciunit = ename + (nb - 1);
	    ici__1.icifmt = "(i2.2)";
	    s_wsfi(&ici__1);
	    do_fio(&c__1, (char *)&lu, (ftnlen)sizeof(integer));
	    e_wsfi();
/* KSK            call getenv (ename, fname) */
	    ugtenv_(ename, fname, (ftnlen)32, (ftnlen)256);
/* :REWIND is not allowed for not-opened devices in HP */
/* MOD            if (fname .eq. " ") go to 200 */
	    if (ioform[lu - 1] < 0) {
		goto L200;
	    }
	    if (lu == 5 || lu == 6 || lu == *istder) {
		goto L200;
	    }
	    if (s_cmp(fname, " ", (ftnlen)256, (ftnlen)1) == 0 && *ideft != 0)
		     {
		s_wsfi(&io___18);
		do_fio(&c__1, (char *)&lu, (ftnlen)sizeof(integer));
		e_wsfi();
		s_copy(fname, tname, (ftnlen)256, (ftnlen)8);
	    }
	    if (s_cmp(fname, " ", (ftnlen)256, (ftnlen)1) == 0) {
		goto L200;
	    }

	    if (ioform[lu - 1] == 1) {
		o__1.oerr = 1;
		o__1.ounit = lu;
		o__1.ofnmlen = 256;
		o__1.ofnm = fname;
		o__1.orl = 0;
		o__1.osta = 0;
		o__1.oacc = "SEQUENTIAL";
		o__1.ofm = "FORMATTED";
		o__1.oblnk = 0;
		i__1 = f_open(&o__1);
		if (i__1 != 0) {
		    goto L100;
		}
		if (lu != 5 || lu != 6) {
		    ++ntunt;
		}
		if (ntunt == *mxunit) {
		    io___19.ciunit = *istder;
		    s_wsfe(&io___19);
		    e_wsfe();
		}
	    } else {
		o__1.oerr = 1;
		o__1.ounit = lu;
		o__1.ofnmlen = 256;
		o__1.ofnm = fname;
		o__1.orl = 0;
		o__1.osta = 0;
		o__1.oacc = "SEQUENTIAL";
		o__1.ofm = "UNFORMATTED";
		o__1.oblnk = 0;
		i__1 = f_open(&o__1);
		if (i__1 != 0) {
		    goto L100;
		}
		if (lu != 5 || lu != 6) {
		    ++ntunt;
		}
		if (ntunt == *mxunit) {
		    io___20.ciunit = *istder;
		    s_wsfe(&io___20);
		    e_wsfe();
		}
	    }

/* MOD            if (vrbose) write (0, 2000) lu, fname(:lnblnk(fname)) */
	    lnblnk = i_indx(fname, " ", (ftnlen)256, (ftnlen)1) - 1;
	    if (lnblnk < 0) {
		lnblnk = i_len(fname, (ftnlen)256);
	    }
	    if (*vrbose) {
		io___22.ciunit = *istder;
		s_wsfe(&io___22);
		do_fio(&c__1, (char *)&lu, (ftnlen)sizeof(integer));
		do_fio(&c__1, fname, lnblnk);
		e_wsfe();
	    }

	    fenv = TRUE_;
	    goto L200;

L100:
	    io___23.ciunit = *istder;
	    s_wsfe(&io___23);
	    do_fio(&c__1, ename, nb + 1);
	    e_wsfe();
/* :Function "perror" may not exist. */
/* MOD            call perror (fname(:lnblnk)) */
	    iok = FALSE_;

L200:
	    ;
	}
    }

    if (*vrbose) {
	if (ienv && ! fenv) {
	    io___24.ciunit = *istder;
	    s_wsfe(&io___24);
	    do_fio(&c__1, ename, nb - 1);
	    e_wsfe();
	}
/* :l-type in format 2004 may be invalid in some systems(SX3). */
/* MOD        write (istder, 2004) cctl, bzro, apnd */
	s_copy(torf1, "false", (ftnlen)8, (ftnlen)5);
	s_copy(torf2, "false", (ftnlen)8, (ftnlen)5);
	s_copy(torf3, "false", (ftnlen)8, (ftnlen)5);
	if (*cctl) {
	    s_copy(torf1, "true", (ftnlen)8, (ftnlen)4);
	}
	if (*bzro) {
	    s_copy(torf2, "true", (ftnlen)8, (ftnlen)4);
	}
	if (*apnd) {
	    s_copy(torf3, "true", (ftnlen)8, (ftnlen)4);
	}
	io___28.ciunit = *istder;
	s_wsfe(&io___28);
	do_fio(&c__1, torf1, (ftnlen)8);
	do_fio(&c__1, torf2, (ftnlen)8);
	do_fio(&c__1, torf3, (ftnlen)8);
	e_wsfe();
/* :Flushing standard error output has no meaning. */
/* MOD        call flush (0) */
    }

    ret_val = iok;

    return ret_val;
/* :'$' format specifier may be invalid in some systems. */
/* :l-type may be invalid in some systems(SX3). */
/* 2003   format ('ioinit: ', a, ' ', $) */
/* 2004   format (' uioint: cctl=', l, ', bzro=', l, ', apnd=', l) */
} /* uioint_ */

