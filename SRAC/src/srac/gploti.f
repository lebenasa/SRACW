C             GPLOTI              LEVEL=1        DATE=81.02.23
      SUBROUTINE  GPLOTI(IPLT,IMAX3,X,Y,WITHX,WITHY,IP,NP,IST,NLOGX,
     &NLOGY, XWIDE,YWIDE,IXMIN,IYMIN,AX1,AX2,AY1,AY2,MSCALE,RATIOX,
     &RATIOY, XTITLE,YTITLE,TITLE, MM,IDA,IDR,IDN,JMAX1)
      DIMENSION   XTITLE(1),YTITLE(1),TITLE(1), IDA(1),IDR(1),IDN(1)
      DOUBLE PRECISION  IDA,IDR,IDN
      REAL   X(IMAX3),Y(IMAX3)
      REAL  Q(6),R(6)
C     PRINT 300, IPLT,IMAX3,IP,NP,IST
  300 FORMAT(1H ,20X,'AAAA',5X,12I6)
      IMAX= IMAX3-3
      IMAXX = IMAX
      IF(IP.GT.20)  IMAXX=IMAX+1
      IF(IPLT.EQ.0) GO TO 200
      ICPLS=  FLOAT(JMAX1)/10. +0.995
      CPLS =  FLOAT(ICPLS)*60.
      INITAL = IPLT
      CALL  SEPTE(INITAL,WITHX+CPLS-100.)
      CALL  LSCALE(IMAX3,IMAXX,X,WITHX,XWIDE,NLOGX,IDX,IXMIN,AX1,AX2,
     &MSCALE,RATIOX)
      CALL  LSCALE(IMAX3,IMAX ,Y,WITHY,YWIDE,NLOGY,IDY,IYMIN,AY1,AY2,
     &MSCALE,RATIOY)
      CALL  FLPLOT(NLOGX,NLOGY,WITHX,WITHY,IDX,IDY,IXMIN,IYMIN,AX1,AX2,
     & AY1,AY2)
      CALL  TITLEP(WITHX,WITHY,XTITLE,YTITLE,TITLE )
      CALL  PLTCL (IMAX3,IMAXX,IMAX,X,Y,IP,NP,IST)
C     PRINT 300,IPLT,IMAX3,IP,NP,IST
      RETURN
  200 CONTINUE
      CALL  FSCALE(IMAXX,IMAX,X,Y,NLOGX,NLOGY,XWIDE,YWIDE,IXMIN,IYMIN,
     & AX1, AX2,AY1,AY2,WITHX,WITHY )
      CALL  PLTCL (IMAX3,IMAXX,IMAX,X,Y,IP,NP,IST)
C
C     COMMENT   PLOT
C
      M= MM
      MZ =  FLOAT(MM)/10. + 0.98
      CPLUS=  60*(MZ-1)
      Q(1)= WITHX + 10.+CPLUS
      Q(2)= WITHX + 16.+CPLUS
      Q(3)= WITHX + 22.+CPLUS
      Q(4)= WITHX + 28.+CPLUS
      MJ= MOD(M,10)
      IF(MJ.EQ.0) MJ=10
      YY= WITHY- 22.0*FLOAT(MJ)
      R(1) = YY
      R(2) = YY+5.
      R(3) = YY+10.
      J=3
      IF(IP.GT.20)  J=4
      CALL   PLTCL(6,J,3,Q,R,IP,NP,IST)
      YY= R(3)
      XX=Q(4)+5.
      CALL  SYMBOL (XX,YY,4., IDA(M),0.,8)
      CALL  SYMBOL (XX,YY-6., 4., IDR(M),0.,8)
      CALL  SYMBOL (XX,YY-12.,4., IDN(M),0.,8)
C
      RETURN
      END
