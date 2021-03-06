      SUBROUTINE  SPLINE(FTAB  ,SFCTR ,SIG0  ,RTEMP ,FSIG0 ,FTEMP ,
     &                   X1    ,X2    ,Y1    ,Y2    ,C     ,D     ,
     &                   E     ,MXSIG0,MXTEMP,LNMAX ,IMAX  ,NTEMP ,
     &                   NSIG  ,NGMIN ,NGMAX  )
C
C
C     THIS SUBROUTINE OBTAINS SELF-SHIELDING FACTORS
C                         FROM F-TABLE BY SPLINE FITTING.
C
C     FTAB --- F-TABLE
C     SFCTR--- SELF-SHIELDING FACTOR
C     SIG0 --- SIGMA0
C     RTEMP--- TEMPERATURE OF RIGION
C     FSIG0--- SIGMA0 IN F-TABLE
C     FTEMP--- TEMPERATURE IN F-TABLE
C     IMAX --- NUMBER OF LIBRARY GROUPS
C     NSIG --- NUMBER OF SIGMA0 INDEX IN F-TABLE
C     NTEMP--- NUMBER OF TEMPERATURE INDEX IN F-TABLE
C     LNMAX--- MAX0(NSIG0,NTEMP)
C     NGMIN--- HIGHEST ENERGY GROUP FOR F-TABLE
C     NGMAX--- LOWEST ENERGY GROUP FOR F-TABLE
C
C     WORK DIMENSION --- X1,X2,Y1,Y2,C,D,E,DY
C
      DIMENSION  FTAB(MXSIG0,MXTEMP,IMAX),SFCTR(IMAX),
     &           SIG0(IMAX),FSIG0(MXSIG0),FTEMP(MXTEMP)
      DIMENSION  X1(MXTEMP),X2(MXSIG0),Y1(MXTEMP),Y2(MXSIG0),
     &           C(LNMAX),D(LNMAX),E(LNMAX),DY(2)
C
C     INITIAL SET
C
CJAIS ADDED FOR SFCTR INITIAL SET ***7/25/1985*** CCCCCCCCCCCCCCCCCCCCCC
      DO  1 N=1,IMAX
      SFCTR(N)=1.0
    1 CONTINUE
C
      DO 3  N=NGMIN,NGMAX
      DO 3  NT=1,NTEMP
      DO 2  J =1,NSIG
      IF(FTAB(J,NT,N).GT.0.0) GO TO 2
        WRITE(6,*) ' *** F-TABLE IS NEGATIVE OR ZERO ]]] RESET 1.0 '
        WRITE(6,*) ' ** J,NT,NG,FTAB : ',J,NT,N,FTAB(J,NT,N)
        FTAB(J,NT,N) = 1.0
    2 CONTINUE
    3 CONTINUE
CJAIS END CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
C     WRITE(6,2001) NGMIN,NGMAX
      DO 10 N = 1,NTEMP
      X1(N)   = ALOG(FTEMP(N))
   10 CONTINUE
      DO 20 N = 1,NSIG
      X2(N)   = ALOG(FSIG0(N))
   20 CONTINUE
      DY(1)   = 0.0
      DY(2)   = 0.0
CM    TT      = ALOG(RTEMP)
      RTEMPR  = RTEMP
      IF(RTEMP.LT.FTEMP(1)) RTEMPR = FTEMP(1)
      TT      = ALOG(RTEMPR)
C
C     F-TABLE SEARCH START
C
      DO 1000 I = NGMIN,NGMAX
      XX        = SIG0(I)
      IF(XX.LE.0.0)  XX = 0.0001
      XX        = ALOG(XX)
      IF(XX.LT.X2(NSIG)) GO TO  100
      DO 50 J=1,NTEMP
      Y1(J)=ALOG(FTAB(NSIG,J,I))
   50 CONTINUE
      GO TO 300
  100 CONTINUE
      IF(NSIG.GT.1.AND.XX.GT.X2(1)) GO TO 200
      DO 150 J=1,NTEMP
      Y1(J)=ALOG(FTAB(1,J,I))
  150 CONTINUE
      GO TO 300
C
C     SIGMA-0 LOOP
C
  200 CONTINUE
      DO 250 J=1,NTEMP
      DO 225 K=1,NSIG
      Y2(K)=ALOG(FTAB(K,J,I))
  225 CONTINUE
CKSK  CALL  INSPL(X2,Y2,DY,NSIG,C,D,E,ICON)
      CALL UINSPL(X2,Y2,DY,NSIG,C,D,E,ICON)
      IF(ICON.LE.100)  GO TO 235
      WRITE(6,230)
      STOP
  230 FORMAT(1H0,10X,'  SPLINE FIT ILL-CONDITIONED ---- STOP ')
  235 CONTINUE
      DO 240 K=1,NSIG
      LL=K
      IF(XX.LE.X2(K)) GO TO 245
  240 CONTINUE
  245 CONTINUE
      LL=LL-1
      IF(LL.LE.0)  LL=1
      X0=XX-X2(LL)
      Y1(J)=Y2(LL)+( (E(LL)*X0 + D(LL))*X0 + C(LL) )*X0
  250 CONTINUE
  300 CONTINUE
C
C     TEMPERATURE LOOP
C
      IF(NTEMP.GT.1)  GO TO 700
      SFCTR(I)=EXP(Y1(1))
      GO TO 1000
  700 CONTINUE
CKSK  CALL  INSPL(X1,Y1,DY,NTEMP,C,D,E,ICON)
      CALL UINSPL(X1,Y1,DY,NTEMP,C,D,E,ICON)
      IF(ICON.LE.100)  GO TO 750
      WRITE(6,230)
      STOP
  750 CONTINUE
      DO 800 J=1,NTEMP
      LL=J
      IF(TT.LE.X1(J))  GO TO 850
  800 CONTINUE
  850 CONTINUE
      LL=LL-1
      IF(LL.LE.0)  LL=1
      X0=TT-X1(LL)
      ANS=Y1(LL)+( (E(LL)*X0 + D(LL))*X0 + C(LL) )*X0
      SFCTR(I)=EXP(ANS)
 1000 CONTINUE
C     WRITE(6,2002) (SFCTR(I),I=1,IMAX)
 2001 FORMAT(1H ,' ##ISW NGMIN NGMAX## ',3I10)
 2002 FORMAT(1H ,' ##SFCTR## ',10F12.5)
C
C     END
C
      RETURN
      END
