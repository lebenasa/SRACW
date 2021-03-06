CFASP --084 ***CITATION*** CALC. ABS. IN SEARCH NUCLIDES /CF-FLUX,KLUX
C
      SUBROUTINE FASP(SS1,SIG,CONC,NJJR,PVOL,NCOMP,B1,XLAMDA, KVX,NVX,
     & MVX,LVX,NSETVX)
C
      INCLUDE  'CITPMINC'
CDEL  INTEGER RGX , MSX , ZNEX , ZDX , WZX
CDEL  PARAMETER ( RGX=100, MSX=211, ZDX=200, ZNEX=1000, WZX=100 )
C
      REAL*8 B1
C
      COMMON/ALSUB/BLSUB(30),TITL1(18),TITL2(18),IMAX,JMAX,KBMAX,KMAX,
     & LMAX,MMAX, NMAX,IMXP1,JMXP1,KBMXP1,NSETMX,NTO,MM1VX,KM1VX,IOIN,
     & IOUT,IOSIG,IOFLX,IO1,IO2,IO3,IO4,IO7,NER(100), IX(200),INNO(100),
     &  NGC(24),IEDG(24),ITMX(24),TIMX(6), GLIM(6),NDPL(24),IEDP1(24),
     & IEDP2(24),IEDP3(24), DPLH(6),NUAC(24),EPI(6),XMIS(6),NSRH(24),
     & XSRH1(6), XTR1(WZX),XTR2(WZX),NXTR1(WZX),NXTR2(WZX),SPARE(200),
     & IXPUT(200),XPUT(200)
      COMMON/ABURN/BBURN(30),NSIG1(50),NSIG2(50),NSIG3(50),N1N2R(2,ZDX),
     &  NSIG4(50),NSIG5(50),NSIG6(50),NJM(50),NJMM(50),NJNQ(50),NCH(50),
     &  NZON(ZDX),NXSET(ZDX),NXODR(ZDX),IDXSET(ZDX),NCLASS(ZDX),NDP(ZDX)
     &  , XNAME(3,ZDX)
C
      DIMENSION SS1(KVX,NVX,NSETVX),SIG(KVX,MVX,10),CONC(NVX,MVX),
     & NJJR(NVX,NSETVX),PVOL(LVX),NCOMP(LVX),B1(MVX,KVX)
C
      XWACH = SPARE(66)
      T11 = 1.0
      IF (IX(5).EQ.2) GO TO 101
      IF (IX(5).EQ.1) GO TO 100
      IF (IX(5).LT.0) GO TO 119
      STOP 2468
  100 IF (IX(128).LE.0) GO TO 116
  101 CONTINUE
      DO 103 M = 1,MMAX
      DO 102 K = 1,KMAX
      SIG(K,M,5) = 0.0
  102 CONTINUE
  103 CONTINUE
      IF (NSRH(10).EQ.(-1)) GO TO 111
      DO 110 M = 1,MMAX
      NS = NXSET(M)
      NR = NXODR(NS)
      NSX = NSIG2(NR)
      IF ((IX(44).EQ.0).AND.(IX(49).EQ.0)) GO TO 105
      IF (IX(49).GT.0) GO TO 104
      IF ((M.EQ.IX(44)).OR.(M.EQ.IX(45)).OR.(M.EQ.IX(46))
     & .OR.(M.EQ.IX(47)).OR.(M.EQ.IX(48))) GO TO 105
      GO TO 109
  104 IF (IX(49).NE.NCLASS(M)) GO TO 109
  105 CONTINUE
      DO 108 N=1,NSX
      DO 107 INI=12,18
      IF (NJJR(N,NR).NE.NSRH(INI)) GO TO 107
      DO 106 K = 1,KMAX
      SIG(K,M,5) = SIG(K,M,5)+CONC(N,M)*SS1(K,N,NR)
  106 CONTINUE
  107 CONTINUE
  108 CONTINUE
  109 CONTINUE
  110 CONTINUE
      GO TO 115
  111 CONTINUE
      IO18 = IX(85)
      REWIND IO18
      READ(IO18) NXZ
      READ(IO18) (NXTR1(I),I=1,NXZ)
      DO 114 I=1,NXZ
      M = NXTR1(I)
      NS = NXSET(M)
      NR = NXODR(NS)
      NSX = NSIG2(NR)
      READ(IO18) (XTR1(N),N=1,NSX)
      DO 113 N=1,NSX
      IF (XTR1(N).EQ.0.0) GO TO 113
      IF (NSRH(23).GT.0.AND.XTR1(N).LT.0.0) GO TO 113
      DO 112 K=1,KMAX
      SIG(K,M,5) = SIG(K,M,5)+CONC(N,M)*SS1(K,N,NR)
  112 CONTINUE
  113 CONTINUE
  114 CONTINUE
      REWIND IO18
  115 CONTINUE
  116 CONTINUE
      SPARE(48) = 0.0
      DO 118 K = 1,KMAX
      DO 117 M=1,MMAX
      SPARE(48) = SPARE(48) + B1(M,K)*SIG(K,M,5)
  117 CONTINUE
  118 CONTINUE
      GO TO 120
  119 T11 = XLAMDA
  120 T1 = T11*SPARE(48)/SPARE(56)
      SPARE(52) = T1
      IF (IX(5).EQ.2) GO TO 122
      WRITE(IOUT,1000)XWACH
      IF (IX(5).NE.1) GO TO 121
      IF (IX(128).LE.0) WRITE(IOUT,1001) SPARE(29),T1
      IF (IX(128).GT.0) WRITE(IOUT,1004) SPARE(29),T1
      GO TO 123
  121 CONTINUE
      IF (IX(5).EQ.-1) WRITE(IOUT,1002) XLAMDA,T1
      IF (IX(5).EQ.-2) WRITE(IOUT,1003)XLAMDA,T1
      GO TO 123
  122 CONTINUE
      WRITE(IOUT,1005) T1
  123 CONTINUE
      RETURN
 1000 FORMAT(1H0,'END OF CRITICALITY SEARCH - ITERATION TIME',0PF7.3,
     & ' MINUTES')
 1001 FORMAT('0SEARCH NUCLIDES WERE MULTIPLIED BY',1PE13.5,
     & ', FRACTION ABSORPTIONS IN SEARCH NUCLIDES ',0PF10.6)
 1002 FORMAT('0DENSITY OF 1/V CROSS SECTION IS',1PE13.5,
     & ', FRACTION ABSORPTIONS IN SEARCH PARAMETER',0PF10.6)
 1003 FORMAT(1H0,'BUCKLINGS WERE MULTIPLIED BY',1PE13.5,
     & ', FRACTION ABSORPTIONS IN SEARCH PARAMETER',0PF10.6)
 1004 FORMAT(1H0,'INPUT RELATIVE CONCENTRATION CHANGE TIMES ',1PE13.5,
     & ' HAS BEEN ADDED TO THE INITIAL SEARCH CONCENTRATIONS'/1H0,
     & 'FRACTION ABSORPTION IN SEARCH NUCLIDES ',0PF10.6)
 1005 FORMAT(1H0,'FRACTION ABSORPTION IN SEARCH NUCLIDES ',0PF10.6)
      END
