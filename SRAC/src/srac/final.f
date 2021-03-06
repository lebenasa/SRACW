C ************************ 1987/5/20 ***** ON ITFLUX *******************
                    SUBROUTINE FINAL
C ************************ 1987/5/20 ***** ON ITFLUX *******************
     1 ( FLUX,QG,FG,SIN,SS,SOUT,NL,ABG,BAL,RL,HL,TL,VL,
     1   NM,IT,JT,XRADA,YRADA,XRAD,YRAD )
C
      COMMON /TW1C/ DD(1),LIM1,IA(210)
      COMMON /WORK/AAA(1),LIM2,AA(130)
      DIMENSION D(212),A(132)
      EQUIVALENCE (D(1),DD(1)),(AAA(1),A(1))
      EQUIVALENCE (D(112),IPFX),(D(107),IGCDMP),(D(124),I2),(D(126),I4),
     1(D(113),LTFX),(D(114),LXFX),(D(157),NOUT),(D(164),ITFLUX)
C
      DIMENSION FLUX(NM,IT,JT),QG(1),FG(1),SIN(1),SS(1),SOUT(1),NL(1),
     1ABG(1),BAL(1),RL(1),HL(1),TL(1),VL(1),XRADA(1),YRADA(1),XRAD(1),
     2YRAD(1)
C
      EQUIVALENCE (IA(4),IGM),(IA(11),IEVT),(IA(25),IMC),(IA(27),JMC),
     1(IA(29),IXM),(IA(30),IYM),(IA(32),IGEOM),(IA(60),IP),(IA(61),JP),
     2(IA(62),IGP),(IA(73),ISPANF),(A(76),LFL),(A(78),LFISA),
     3(A(23),ICONV)
C
      INTEGER G
      REAL NL
C
      CHARACTER*6 NXYZ01(3),NXYZ02(3),NXYZ04(3)
      REAL *8  XTEMP
C
CKSK  DATA NXYZ01/6HX     ,6HR     ,6HR     /
CKSK  DATA NXYZ02/6HY     ,6HZ     ,6HT     /
CKSK  DATA NXYZ04/6HX MESH,6HR MESH,6HR MESH/
      DATA NXYZ01/'X     ','R     ','R     '/
      DATA NXYZ02/'Y     ','Z     ','T     '/
      DATA NXYZ04/'X MESH','R MESH','R MESH'/
C
      WRITE (NOUT,190)
C
C     BALANCE TABLES
C
      WRITE (NOUT,200)(I,QG(I),FG(I),SIN(I),SS(I),SOUT(I),NL(I),I=1,IGP)
      WRITE (NOUT,210)(I,ABG(I),BAL(I),RL(I),HL(I),TL(I),VL(I),I=1,IGP)
C
C     MONITOR LINE
C
      ICONV=1
      ITEMP=IGCDMP
      IGCDMP=0
      CALL MONITR (BAL)
      IGCDMP=ITEMP
      IF (IEVT.NE.4) GO TO 130
C
C     PRINT MODIFIED RADIAL AND AXIAL VALUES
C
      WRITE (NOUT,220)
      IF (IXM.GT.0) GO TO 100
      WRITE (NOUT,230)NXYZ01(IGEOM)
      GO TO 110
  100 WRITE (NOUT,240)NXYZ01(IGEOM),NXYZ01(IGEOM)
      IMP=IMC+1
      WRITE (NOUT,250)(I,XRADA(I),XRAD(I),I=1,IMP)
  110 IF (IYM.GT.0) GO TO 120
      WRITE (NOUT,230)NXYZ02(IGEOM)
      GO TO 130
  120 WRITE (NOUT,260)NXYZ02(IGEOM),NXYZ02(IGEOM)
      JMP=JMC+1
      WRITE (NOUT,250)(J,YRADA(J),YRAD(J),J=1,JMP)
C
C     PRINT FLUXES
C
  130 REWIND ITFLUX
      DO 150 G=1,IGM
CKSK  CALL REED (0,IPFX+(G-1)*LTFX,A(LFL),LXFX,1)
      CALL REED (0,IPFX+(G-1)*LTFX,AAA(LFL),LXFX,1)
      IF (I2.EQ.2) GO TO 142
      NMT=NM
      IF (I2.EQ.0) GO TO 140
      IF (NM.EQ.1) GO TO 140
      WRITE (NOUT,270)G
      NMT=1
      GO TO 141
  140 WRITE (NOUT,280)G
      IF (NM.GT.1) WRITE (NOUT,290)NXYZ01(IGEOM),NXYZ02(IGEOM)
  141 CONTINUE
       XTEMP = DFLOAT(NMT)
CKSK   CALL WWRITE (4,2,FLUX,NM,IT,JT,XTEMP,6H      ,6H      ,
C2004  CALL WWRITE (4,2,FLUX,NM,IT,JT,XTEMP,'      ','      ',
Cmod 1NXYZ04(IGEOM))
       CALL WWRITE (4,2,FLUX,NM,IT,JT,'      ','      ','      ',
     1              NXYZ04(IGEOM) , NMT )
Cend
CKH
  142        KKK=1
  143 WRITE(ITFLUX) ((FLUX(KKK,I,J),I=1,IT),J=1,JT)
CKH
  150 CONTINUE
  160 IF (I4.NE.0) GO TO 180
      IF (FG(IGP).NE.0.0) GO TO 170
      WRITE (NOUT,300)
      GO TO 180
  170 CONTINUE
C
C     PRINT FISSION SUMMARY
C
      WRITE (NOUT,310)
       XTEMP = DFLOAT(1)
CKSK   CALL WWRITE (4,2,A(LFISA),1,IT,JT,XTEMP,6H      ,6H      ,
CKSK   CALL WWRITE (4,2,AAA(LFISA),1,IT,JT,XTEMP,6H      ,6H      ,
C2004  CALL WWRITE (4,2,AAA(LFISA),1,IT,JT,XTEMP,'      ','      ',
Cmod 1NXYZ04(IGEOM) )
       CALL WWRITE (4,2,AAA(LFISA),1,IT,JT,'      ','      ','      ',
     1              NXYZ04(IGEOM) , 1  )
Cend
  180 RETURN
C
C
  190 FORMAT (1H0/////16H FINAL PRINTING ////)
  200 FORMAT (1H0,13X,7H SOURCE,5X,14HFISSION SOURCE,10X,10HIN SCATTER,8
     1X,12HSELF SCATTER,9X,11HOUT SCATTER,9X,11HNET LEAKAGE,/(I4,1PE16.7
     2,1P5E20.7))
  210 FORMAT (///,9X,11H ABSORPTION,5X,15HNEUTRON BALANCE,7X,14H RIGHT L
     1EAKAGE,3X,18HHORIZONTAL LEAKAGE,6X,11HTOP LEAKAGE,8X,16HVERTICAL L
     2EAKAGE,/(I4,1PE16.7,1P5E20.7))
  220 FORMAT (///34H0 DELTA CALCULATION FINAL RESULTS )
  230 FORMAT (25H0 NO MODIFICATION IN THE ,A1,10H DIRECTION)
  240 FORMAT (1H0,6X,1HI,9X,9HMODIFIED ,A1,6X,9HORIGINAL ,A1//)
  250 FORMAT (1H ,I7,4X,2E16.8)
  260 FORMAT (1H0,6X,1HJ,9X,9HMODIFIED ,A1,6X,9HORIGINAL ,A1//)
  270 FORMAT (1H0///36H ISOTROPIC FLUX COMPONENT FOR GROUP ,I4)
  280 FORMAT (1H0///27H FLUX COMPONENTS FOR GROUP ,I4)
  290 FORMAT (21H0SECOND COMPONENT IS ,A1,29H DIRECTION CURRENT, THIRD I
     1S ,A1,19H DIRECTION CURRENT //)
  300 FORMAT (1H0///28H FISSION FG ( IGP ) IS ZERO ////)
  310 FORMAT (1H0///14H FISSION EDIT ////)
      END
