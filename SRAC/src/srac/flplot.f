      SUBROUTINE  FLPLOT(NLOGX,NLOGY,WITHX,WITHY,IDX,IDY,IXMIN,IYMIN,
     *AX1,AX2,AY1,AY2)
      REAL  XD(10),YD(10)
      XWIDE=WITHX/FLOAT(IDX)
      YWIDE=WITHY/FLOAT(IDY)
C     FLAME
      NPENX=2
      NPENY=2
      IF(NLOGX.EQ.0) NPENX=3
      IF(NLOGY.EQ.0) NPENY=3
      CALL PLOT( 0.,0.,3)
      CALL PLOT( WITHX, 0.,NPENX)
      CALL PLOT( WITHX, WITHY,NPENY)
      CALL PLOT( 0. ,   WITHY,NPENX)
      CALL PLOT( 0. , 0., NPENY)
C     LOG  SCALE  LINE  PLOT
      IF(NLOGX.EQ.0)  GO TO 641
      IDX1=IDX-1
      IF(IDX1.LE.0)  GO  TO 641
      DO  640  I=1,IDX1,2
      XX=XWIDE*FLOAT(I)
      CALL  PLOT (XX,0.,3)
      CALL  PLOT (XX,WITHY,2)
      IF(I+1.GT.IDX1)   GO TO  640
      XX=XWIDE*FLOAT(I+1)
      CALL PLOT(XX,WITHY,3)
      CALL PLOT(XX,0.,2)
  640 CONTINUE
      IF(MOD(IDX1,2).NE.0)  CALL PLOT(WITHX,WITHY,3)
      CALL PLOT (WITHX,0.,3)
  641 CONTINUE
      IF(NLOGY.EQ.0)  GO TO 646
      IDY1=IDY-1
      IF(IDY1.LE.0)   GO TO 646
      CALL PLOT(WITHX,WITHY,3)
      DO  645  I=1,IDY1,2
      YY=YWIDE*FLOAT(I)
      CALL PLOT(WITHX,YY,3)
      CALL PLOT(0.,YY,2)
      IF(I+1.GT.IDY1)  GO TO  645
      YY=YWIDE*FLOAT(I+1)
      CALL PLOT(0.,YY,3)
      CALL PLOT(WITHX,YY,2)
  645 CONTINUE
      IF(MOD(IDY1,2).EQ.0)  CALL PLOT(WITHX,0.,3)
  646 CONTINUE
      CALL PLOT(0.,0.,3)
C     STEP PLOT
      DO 650 I=1,9
      XD(I)=ALOG10(FLOAT(I))*XWIDE
      YD(I)=ALOG10(FLOAT(I))*YWIDE
  650 CONTINUE
      IF(NLOGX.EQ.0) GO TO  662
      HIGHT=XWIDE/50.*2.
      IF(HIGHT.GT.5.)  HIGHT=5.
      IDXP=IDX+1
      DO  669   N=1,IDXP
      IF(N.GT.IDX)   GO TO  667
      DO 660  I=1,9
      XX=XWIDE*FLOAT(N-1)+XD(I)
      IF(I.EQ.1) GO TO 83
      CALL NUMBER(XX,-7.,HIGHT,FLOAT(I),0.,-1)
   83 CONTINUE
      IF( I.EQ.1.OR.I.EQ.5) GO TO661
      CALL  PLOT (XX,-2., 3)
      CALL PLOT(XX, 2., 2)
      GO TO  660
  661 CALL  PLOT( XX,-3., 3)
      CALL  PLOT( XX, 3., 2)
  660 CONTINUE
  667 CONTINUE
      XX=XWIDE*(FLOAT(N-1))
      XXX=XX+5.*(10./7.)+1.
      AN=IXMIN+N-1
      CALL  NUMBER(XX,-10.,5.,10.,0.,-1)
      CALL  NUMBER(XXX,-5.,4.,AN, 0.,-1)
  669 CONTINUE
      CALL PLOT(WITHX,0.,3)
  662 CONTINUE
      IF(NLOGY.EQ.0)  GO TO  400
      DO  6670  N=1,IDY
      DO  6670  I=1,9
      YY= YWIDE* FLOAT(N-1)+YD(I)
      IF(I.EQ.1.OR.I.EQ.5)  GO  TO  6671
      CALL  PLOT(WITHX,YY,3)
      CALL  PLOT(WITHX-2.,YY,2)
      GO  TO  6670
 6671 CONTINUE
      CALL  PLOT(WITHX,YY,3)
      CALL  PLOT(WITHX-3.,YY,2)
 6670 CONTINUE
      CALL PLOT(WITHX,0.,3)
  400 CONTINUE
      CALL PLOT(0.,0.,3)
      IF(NLOGY.EQ.0)  GO TO 663
      HIGHT=YWIDE/50.*2.
      IF(HIGHT.GT.5.)  HIGHT=5.
      GW= HIGHT *0.666 +1.
      IDYP=IDY+1
      DO  672  N=1,IDYP
      IF(N.GT.IDY)  GO TO  184
      DO  670  I=1,9
      YY= YWIDE*FLOAT(N-1)+YD(I)
      IF(I.EQ.1) GO TO 183
      CALL NUMBER(-3.-GW,YY,HIGHT,FLOAT(I),0.,-1)
  183 CONTINUE
      IF(I.EQ.1.OR.I.EQ.5) GO TO 671
      CALL  PLOT(-2.,YY,3)
      CALL  PLOT(+2.,YY,2)
      GO  TO  670
  671 CALL  PLOT(-3.,YY,3)
      CALL  PLOT( 3.,YY,2)
  670 CONTINUE
  184 CONTINUE
      YY=YWIDE*(FLOAT(N-1))
      AN=IYMIN+N-1
      CALL  NUMBER(-20.,YY,5.,10.,0.,-1)
      CALL  NUMBER(-12.,YY+5.,4.,AN,0.,-1)
  672 CONTINUE
  663 CONTINUE
      IF(NLOGX.EQ.0)  GO TO  300
      CALL PLOT(0.,WITHY,3)
      DO 6660  N=1,IDX
      DO 6660  I=1,9
      XX=XWIDE*FLOAT(N-1)+XD(I)
      IF(I.EQ.1.OR.I.EQ.5)  GO TO  6661
      CALL  PLOT (XX,WITHY,3)
      CALL  PLOT (XX,WITHY-2.,+2)
      GO  TO  6660
 6661 CONTINUE
      CALL PLOT (XX,WITHY,3)
      CALL PLOT (XX,WITHY-3.,2)
 6660 CONTINUE
      CALL PLOT(0.,WITHY,3)
  300 CONTINUE
      CALL PLOT(0.,0.,3)
      IF(NLOGX.NE.0)   GO  TO  665
CKSK  CALL AXIS(0.,0.,1H    , -1,WITHX,0., AX1, AX2,10.)
      CALL AXIS(0.,0.,' '   , -1,WITHX,0., AX1, AX2,10.)
CKSK  CALL AXIS(0.,WITHY,1H ,+1,WITHX,0., AX1, AX2,10.)
      CALL AXIS(0.,WITHY,' ',+1,WITHX,0., AX1, AX2,10.)
  665 IF(NLOGY.NE.0)   GO  TO  666
CKSK  CALL AXIS(0.,0., 1H    , 1,WITHY,90., AY1, AY2,10.)
      CALL AXIS(0.,0., ' '   , 1,WITHY,90., AY1, AY2,10.)
CKSK  CALL  AXIS(WITHX,0.,2H   ,-2,WITHY,90., AY1, AY2,10.)
      CALL  AXIS(WITHX,0.,'  ' ,-2,WITHY,90., AY1, AY2,10.)
  666 CONTINUE
      RETURN
      END