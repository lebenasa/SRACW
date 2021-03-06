CABPR-VP-097 ***CITATION*** AVERAGE FLUX,ABS.,PROD CALCULATION/ CF-FLUX
C
CNN   SUBROUTINE ABPR(P2,B1,B2,B3,B4,B5,NRGN,IVX,JVX,KVX,LVX, SIG,PVOL,
CNN  & NCOMP,MVX,B2LKY,B3LKY,B4LKY,B5LKY)
C
      SUBROUTINE ABPR(P2,B1,B2,B3,B4,B5,NRGN,
     & IVX,JVX,KVX,LVX, SIG,PVOL,
     & NCOMP,MVX,B2LKY,B3LKY,B4LKY,B5LKY,WORK1,WORK2,B1WK,P2E,NRGNE)
C
CDEL  INTEGER RGX , MSX , ZNEX , ZDX , WZX
CDEL  PARAMETER ( RGX=100, MSX=211, ZDX=200, ZNEX=1000, WZX=100 )
      INCLUDE  'CITPMINC'
C
      REAL*8 B2LKY(MVX*KVX),B3LKY(MVX*KVX),B4LKY(MVX*KVX)
      REAL*8 B5LKY(MVX*KVX)
      REAL*8 P2,B1
CNN
      REAL*8 P2E,B1WK
CNN
      REAL*8 SUMXI,TPTSA,XADB,XPDB,XS1DB,XS2DB, TL,XRDB,CS1S,CS2S,XLL1,
     & D8,XADX,YADX, XLL2,XLL3,XLL4,XLL5,XLL6,XLEK,B2LK,B3LK,B4LK,B5LK,
     & D1,D2,D3,D4,D5, D6,D7,YADB,YPDB,YLEK,YS1S,YS2S,YS1DB,YS2DB,YRDB,
     & SPR50,XLAST
C
      COMMON/ADUBP/SUMXI(ZNEX)
     &                  ,TPTSA,XADB,XPDB,XS1DB,XS2DB, TL,XRDB,CS1S,CS2S,
     &  XLL1,D8,XADX,YADX, XLL2,XLL3,XLL4,XLL5,XLL6,XLEK,B2LK,B3LK,B4LK,
     &  B5LK,D1,D2,D3,D4,D5, D6,D7,YADB,YPDB,YLEK,YS1S,YS2S,YS1DB,YS2DB,
     &  YRDB,SPR50,XLAST
      COMMON/ALSUB/BLSUB(30),TITL1(18),TITL2(18),IMAX,JMAX,KBMAX,KMAX,
     & LMAX,MMAX, NMAX,IMXP1,JMXP1,KBMXP1,NSETMX,NTO,MM1VX,KM1VX,IOIN,
     & IOUT,IOSIG,IOFLX,IO1,IO2,IO3,IO4,IO7,NER(100), IX(200),INNO(100),
     &  NGC(24),IEDG(24),ITMX(24),TIMX(6), GLIM(6),NDPL(24),IEDP1(24),
     & IEDP2(24),IEDP3(24), DPLH(6),NUAC(24),EPI(6),XMIS(6),NSRH(24),
     & XSRH1(6), XTR1(WZX),XTR2(WZX),NXTR1(WZX),NXTR2(WZX),SPARE(200),
     & IXPUT(200),XPUT(200)
      COMMON/AFLUX/BFLUX(30),KXMN8,NIT,NIIT,NIIIT,JXP1,KSCT1,KSCT2,
     & ISTART,IEP, VRGP1,VRGP2,VRGP3,VRG1,VRG2,VRGK1,VRGK2,XABS,PROD,
     & XELK,RMX,RMN,XKEF1,XKEF2,XKEF3,EXFC1,EXFC2,EXFC3, NI3,IEXTR,
     & IRECV,VRGABS,LO3,LO4,XLAMDA,EPI1,EPI2, BETTA,SAMXI,IX25,IX28,I,J,
     &  KB,K,ITMAX,ITIME, BET(MSX),DEL(MSX)
C
CNN   DIMENSION P2(JVX,IVX,KVX),B1(MVX*KVX),B2(MVX*KVX),B3(MVX*KVX),
CNN  & B4(MVX*KVX),B5(MVX*KVX),NRGN(JVX,IVX)
      DIMENSION P2E(JVX*IVX,KVX),B1(MVX,KVX),B2(MVX*KVX),B3(MVX*KVX),
     & B4(MVX*KVX),B5(MVX*KVX),NRGNE(JVX*IVX)
      DIMENSION SIG(KVX,MVX,10),PVOL(LVX),NCOMP(LVX)
      DIMENSION P2(JVX,IVX,KVX),NRGN(JVX,IVX)
CNN
      DIMENSION WORK1(MVX,32),WORK2(MVX*32),B1WK(MVX*KVX)
CNN
      JIVX=JVX*IVX
      DO 100 K=1,MVX*KVX
        B1WK(K)=0.0
  100 CONTINUE
      IF(JIVX.LT.120) THEN
CNN
C
        DO 104 K = 1,KVX
          DO 103 I = 1,IVX
*VOCL LOOP,SCALAR
            DO 102 J = 1,JVX
              B1WK(MVX*(K-1)+NCOMP(NRGN(J,I)))=
     1                        B1WK(MVX*(K-1)+NCOMP(NRGN(J,I)))+
     2                        P2(J,I,K)*PVOL(NRGN(J,I))
  102       CONTINUE
  103     CONTINUE
  104   CONTINUE
C
      ELSE
C
CNN
        I128 = 32
        IZN  = MVX * I128
CNN
        DO 1901 K=1,KVX
CKSK    FOR NEC-SX3, BECAUSE WORK1=WORK2
CKSK      DO 1900 IZ=1,IZN
C           WORK2(IZ) = 0.0
C1900     CONTINUE
        CALL CLEA(WORK2,IZN,0.0)
C
        IE = 0
        DO 1902 II=0,(JIVX-1)/I128
          IS = IE + 1
          IS1 = IS - 1
          IE = IS1 + I128
          IF(IE.GT.JIVX) IE=JIVX
*VOCL LOOP,REPEAT(32)
*VOCL LOOP,NOVREC
          DO 1903 JI=IS,IE
            JA = JI - IS1
            ML = NCOMP(NRGNE(JI))
            WORK1(ML,JA) = WORK1(ML,JA) +
     2        P2E(JI,K) * PVOL(NRGNE(JI))
 1903     CONTINUE
 1902   CONTINUE
C
        IF (MVX.GT.5) THEN
          DO 1904 NN=1,I128,4
            DO 1905 I=1,MVX
              B1(I,K) = B1(I,K) + WORK1(I,NN) + WORK1(I,NN+1) +
     1                WORK1(I,NN+2) + WORK1(I,NN+3)
 1905       CONTINUE
 1904     CONTINUE
        ELSE
          DO 1915 I=1,MVX
            B1XX = 0.0
            DO 1914 NN=1,I128
              B1XX = B1XX + WORK1(I,NN)
 1914       CONTINUE
            B1(I,K) = B1XX
 1915     CONTINUE
        ENDIF
C
 1901   CONTINUE
CNN
      ENDIF
CNN
      IF(MVX.GE.KVX) THEN
        DO 106 K=1,KVX
          DO 105 M=1,MVX
            B2LKY(MVX*(K-1)+M)=(SIG(K,M,3)+SIG(K,M,9))*B1(M,K)
            B3   (MVX*(K-1)+M)=SIG(K,M,4)*B1(M,K)
            B3LKY(MVX*(K-1)+M)=SIG(K,M,4)*B1(M,K)*SUMXI(M)
            B4LKY(MVX*(K-1)+M)=SIG(K,M,5)*B1(M,K)
            B5LKY(MVX*(K-1)+M)=SIG(K,M,8)*B1(M,K)
  105     CONTINUE
  106   CONTINUE
      ELSE
        DO 206 M=1,MVX
          DO 205 K=1,KVX
            B2LKY(MVX*(K-1)+M)=(SIG(K,M,3)+SIG(K,M,9))*B1(M,K)
            B3   (MVX*(K-1)+M)=SIG(K,M,4)*B1(M,K)
            B3LKY(MVX*(K-1)+M)=SIG(K,M,4)*B1(M,K)*SUMXI(M)
            B4LKY(MVX*(K-1)+M)=SIG(K,M,5)*B1(M,K)
            B5LKY(MVX*(K-1)+M)=SIG(K,M,8)*B1(M,K)
  205     CONTINUE
  206   CONTINUE
      ENDIF
C
      DO 115 K=1,MVX*KVX
      XADB = XADB+B2LKY(K)
      XPDB = XPDB+B3LKY(K)
      XS1DB = XS1DB+B4LKY(K)
      XS2DB = XS2DB+B5LKY(K)
  115 CONTINUE
C
      DO 119 K=1,MVX*KVX
      B2(K)=B2LKY(K)+B2(K)
CCCC  B3(K)=B3LKY(K)
      B4(K)=B4LKY(K)
      B5(K)=B5LKY(K)
  119 CONTINUE
      RETURN
      END
