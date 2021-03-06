      SUBROUTINE CLUP
      COMMON / PIJ1C / NX,NY,NTPIN,NAPIN,NCELL,NM,NGR,NGA,NDPIN,
     1                 IDIVP,BETM,NX1,IDUM(7),NDPIN1
     2                ,NDR,NDA,LL,L0,RO1,DRO,FVOL,RAN,ISERI,I30(7)
      COMMON / PIJ2C / IGT,NZ,NR,NRR,NXR,IBOUND,IDRECT,LCOUNT,IEDPIJ,
     1                 IFORM,NTTAB,NUTAB,SZ,IDUM14(26),
     2                 LCMMR,LCNREG,LCIRR,LCIXR,LCMAR,LCMAT,LCVOL,
     3                 LCVOLR,LCVOLX,LCVOLM,NO2,AA(950)
      COMMON / PIJC /L00,L01,L02,L03,L04,L05,L06,L07,L08,L09,
     1               L10,L11,L12,L13,L14,L15,L16,L17,L18,L19,L20,L21,
     2               L22,L23,L24,L25,L26,L27,L28,L29,L30,L31,L32,L33,
     3               L34,L35,DD(65)
      COMMON / MAINC / DDM(63),NOUT1,NOUT2,DUM66(30),MXDIM,DUM97(4)
     *                 ,CASENM(2),TITLE(18),DUMM(880)
      COMMON / WORK/ A(30000)
C 1   RX  BY L01
C 2   RPP BY L02
C 3   RDP BY L03
C 4   NPIN  BY L04
C 5   THETA BY L05
C 6   TY    BY L06
C 8   D     BY L08
C 9   IM    BY L09
C 10  IP    BY L10
C 11  II    BY L11
C 12  XX    BY L12
C 14  S     BY L14
C 25  XXX   BY L25
C 26  III   BY L26
C 27  V     BY L27
      L28 = L27 +NZ
C 28  NTR
      L29 = L28 + NX1 + NAPIN
C 29  NAMEP
      L30 = L29 + 2*NDPIN*NAPIN
C 30  NAMER
      L31 = L30 + NX  +  NAPIN
C 31  F
      L32 = L31 + NDPIN1*NAPIN
C 32  LAST
      LAST = L32
      IF(LAST.LE.MXDIM) GO TO 100
      LAST=LAST-MXDIM
      WRITE(NOUT1,9000) LAST,MXDIM
      STOP
  100 CONTINUE
      WRITE(NOUT1,9010) LAST,MXDIM
 9010 FORMAT(10X,'STRAGE USED',I10,' FROM ',I10, 'IN CLUP STEP'/)
 9000 FORMAT(' **DIMENSION OVER ',I10,' FROM ',I10, 'IN CLUP STEP'/)
      CALL CLIN (A(L04),A(L01),A(L03),A(L02),
     1           A(L28),A(L27),A(L29),A(L30),A(L31))
C     SUBROUTINE CLIN(NPIN,RX,RDP,RPP,NTR,V,NAMEP,NAMER,F)
      CALL VOLPIJ (AA(LCNREG),AA(LCIRR),AA(LCIXR),
     1          AA(LCMMR),A(L27),AA(LCVOL),AA(LCVOLR),
     4          AA(LCVOLX),AA(LCVOLM))
C
      CALL MAKETC(AA(LCNREG),AA(LCIRR),AA(LCMMR),AA(LCVOL),A(L14),
     1          A(L09),A(L10),A(L11),A(L12),A(L25),A(L26),
     2          A(L01),A(L02),A(L03),A(L04),A(L05),A(L06),A(L28),
     3          A(L29),A(L30),A(L31))
      RETURN
      END
