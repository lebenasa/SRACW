C             INPUTW              LEVEL=1        DATE=81.11.14
      SUBROUTINE INPUTW (NMAT,MTNAME,NGR)
C
      COMMON /TW1C/ DD(1),LIM1,IA(210)
      DIMENSION D(212)
      EQUIVALENCE (D(1),DD(1))
C
      EQUIVALENCE (IA(12),ISTART)
      DIMENSION MTNAME(2,NMAT)
C
      CALL INPT11 (NMAT,MTNAME,NGR)
      IF (IABS(ISTART).EQ.6) GO TO 100
      CALL INPT12
      CALL INPT13
  100 CONTINUE
      RETURN
      END
