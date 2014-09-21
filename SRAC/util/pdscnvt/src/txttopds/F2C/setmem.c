/* setmem.f -- translated by f2c (version 20100827).
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

/* ----------------------------------------------------------------------- */
/*     CHARACTER LINE*72, MEMBER*8 */
/*     LINE = '*PUT CU050000 N   1234 ' */
/*     CALL SETMEM(LINE,MEMBER,LENG) */
/*     WRITE(6,*) ' MEMBER  = ',MEMBER */
/*     WRITE(6,*) ' LENG    = ',LENG */
/*     STOP */
/*     END */
/* ----------------------------------------------------------------------- */
/*     SETMEM : SET MEMBER NAME AND LENGTH FROM THE LINE DATA : */
/*              *PUT   CU050000  N    18 */
/* ----------------------------------------------------------------------- */
/* Subroutine */ int setmem_(char *line, char *member, integer *leng, ftnlen 
	line_len, ftnlen member_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsle(cilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_wsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(void)
	    ;

    /* Local variables */
    static integer i__, ic, le, ls, ic1e, ic2e, ic3e, ic4e, ic1s, ic2s, ic3s, 
	    ic4s;
    static char aleng[10];
    static integer lleng;

    /* Fortran I/O blocks */
    static cilist io___2 = { 0, 6, 0, 0, 0 };
    static icilist io___16 = { 0, aleng, 0, "(I10)", 10, 1 };



    s_copy(aleng, "          ", (ftnlen)10, (ftnlen)10);
    if (s_cmp(line, "*PUT", (ftnlen)4, (ftnlen)4) != 0) {
	s_wsle(&io___2);
	do_lio(&c__9, &c__1, " ERROR(SETMEM) : NOT COMMAND(*PUT) LINE ", (
		ftnlen)40);
	e_wsle();
	s_stop("", (ftnlen)0);
    }

    ic1s = 1;
    ic1e = 0;
    ic2s = 0;
    ic2e = 0;
    ic3s = 0;
    ic3e = 0;
    ic4s = 0;
    ic4e = 0;
    ic = 0;
    for (i__ = 1; i__ <= 72; ++i__) {
	if (*(unsigned char *)&line[i__ - 1] == ' ' && ic1e == 0) {
	    ic1e = i__ - 1;
	    if (ic1s > ic1e) {
		ic1e = ic1s;
	    }
	}
	if (ic1e == 0) {
	    goto L100;
	}
	if (*(unsigned char *)&line[i__ - 1] != ' ' && ic2s == 0) {
	    ic2s = i__;
	}
	if (ic2s == 0) {
	    goto L100;
	}
	if (*(unsigned char *)&line[i__ - 1] == ' ' && ic2e == 0) {
	    ic2e = i__ - 1;
	    if (ic2s > ic2e) {
		ic2e = ic2s;
	    }
	}
	if (ic2e == 0) {
	    goto L100;
	}
	if (*(unsigned char *)&line[i__ - 1] != ' ' && ic3s == 0) {
	    ic3s = i__;
	}
	if (ic3s == 0) {
	    goto L100;
	}
	if (*(unsigned char *)&line[i__ - 1] == ' ' && ic3e == 0) {
	    ic3e = i__ - 1;
	    if (ic3s > ic3e) {
		ic3e = ic3s;
	    }
	}
	if (ic3e == 0) {
	    goto L100;
	}
	if (*(unsigned char *)&line[i__ - 1] != ' ' && ic4s == 0) {
	    ic4s = i__;
	}
	if (ic4s == 0) {
	    goto L100;
	}
	if (*(unsigned char *)&line[i__ - 1] == ' ' && ic4e == 0) {
	    ic4e = i__ - 1;
	    if (ic4s > ic4e) {
		ic4e = ic4s;
	    }
	}
L100:
	;
    }
/*     WRITE(6,*) IC1S,IC1E */
/*     WRITE(6,*) IC2S,IC2E */
/*     WRITE(6,*) IC3S,IC3E */
/*     WRITE(6,*) IC4S,IC4E */
    s_copy(member, line + (ic2s - 1), (ftnlen)8, ic2e - (ic2s - 1));
    lleng = ic4e - ic4s + 1;
    ls = 10 - lleng + 1;
    le = 10;
    s_copy(aleng + (ls - 1), line + (ic4s - 1), le - (ls - 1), ic4e - (ic4s - 
	    1));
    s_rsfi(&io___16);
    do_fio(&c__1, (char *)&(*leng), (ftnlen)sizeof(integer));
    e_rsfi();
    return 0;
} /* setmem_ */

