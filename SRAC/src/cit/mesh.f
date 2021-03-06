CMESH --029 ***CITATION*** REGION VOLUMES AND MESH SPACING/ CF-IPTM
C
      SUBROUTINE MESH(ISTEP,RVOL,PVOL,LVX)
C
CDEL  INTEGER RGX , MSX , ZNEX , ZDX , WZX
CDEL  PARAMETER ( RGX=100, MSX=211, ZDX=200, ZNEX=1000, WZX=100 )
      INCLUDE  'CITPMINC'
C
      REAL *8 XDEL,ADR,YDELSQ,XNIPTS,XNJPTS,XNKPTS,TEMP,ZXYR,YDIST,
     & XDIST,ZDIST,YDEL,ZDEL,AXYR,XDIST1,XDIST2,YDIST1,YDIST2,XNTOPS,U1,
     &  U2,H,H1,H2,U3
C
      COMMON/ALSUB/BLSUB(30),TITL1(18),TITL2(18),IMAX,JMAX,KBMAX,KMAX,
     & LMAX,MMAX, NMAX,IMXP1,JMXP1,KBMXP1,NSETMX,NTO,MM1VX,KM1VX,IOIN,
     & IOUT,IOSIG,IOFLX,IO1,IO2,IO3,IO4,IO7,NER(100), IX(200),INNO(100),
     &  NGC(24),IEDG(24),ITMX(24),TIMX(6), GLIM(6),NDPL(24),IEDP1(24),
     & IEDP2(24),IEDP3(24), DPLH(6),NUAC(24),EPI(6),XMIS(6),NSRH(24),
     & XSRH1(6), XTR1(WZX),XTR2(WZX),NXTR1(WZX),NXTR2(WZX),SPARE(200),
     & IXPUT(200),XPUT(200)
      COMMON/AMESH/BMESH(30),NREGI,NREGJ,NREGKB,XSHI(RGX),XSHJ(RGX),
     & XSHKB(RGX), MSHI(RGX),MSHJ(RGX),MSHKB(RGX),Y(MSX),YY(MSX), X(MSX)
     &  ,XX(MSX),Z(MSX),ZZ(MSX), ZONVOL(ZNEX),AVZPD(ZNEX),PDI(MSX),
     & PDJ(MSX) , PDK(MSX)
C
      DIMENSION RVOL(LVX),PVOL(LVX)
      DIMENSION NX(6),TX(6)
C
C     SET NXY TO SAME NUMBER AS THE DIMENSION OF XX AND YY
      NXY = MSX
C
      IMAX = 1
      KBMAX = 1
      NDIM = IX(25)
      NGEM = IX(26)
      MGEM = 0
      H1 = 6*MSHI(1)*MSHJ(1)
      H2 = XSHI(1)*XSHJ(1)
      H = DSQRT(H2/H1)
      IF ((NGEM.EQ.8).OR.(NGEM.EQ.12)) MGEM = 8
  100 JMAX = 0
      DO 101 J = 1,NREGJ
      JMAX = JMAX+MSHJ(J)
  101 CONTINUE
C
      IF( JMAX .GE. MSX ) THEN
      WRITE(6,'(1X,A)')
     &' ** MESSAGE FROM JMAX IN SUBROUTINE MESH. **'
      WRITE(6,'(1X,A)')
     &'INSUFFICIENT MESH AREA NUMBER FOR MSX.'
      WRITE(6,'(1X,A,I5)')
     &'CURRENT NUMBER FOR MSX IS ',MSX
      WRITE(6,'(1X,A)')
     &'COULD YOU PLEASE CHECK YOUR NUMBER IN INCLUDE FILE IMMEDIATERY.'
      WRITE(6,'(1X,A)')
     &'I AM WILLING TO YOUR QUICK RESPONCE. THANK YOU.'
      STOP
      ENDIF
C
      IF (NDIM-2) 107,102,102
  102 IMAX = 0
  103 DO 104 I = 1,NREGI
      IMAX = IMAX+MSHI(I)
  104 CONTINUE
C
      IF( IMAX .GE. MSX ) THEN
      WRITE(6,'(1X,A)')
     &' ** MESSAGE FROM IMAX IN SUBROUTINE MESH. **'
      WRITE(6,'(1X,A)')
     &'INSUFFICIENT MESH AREA NUMBER FOR MSX.'
      WRITE(6,'(1X,A,I5)')
     &'CURRENT NUMBER FOR MSX IS ',MSX
      WRITE(6,'(1X,A)')
     &'COULD YOU PLEASE CHECK YOUR NUMBER IN INCLUDE FILE IMMEDIATERY.'
      WRITE(6,'(1X,A)')
     &'I AM WILLING TO YOUR QUICK RESPONCE. THANK YOU.'
      STOP
      ENDIF
C
      IF (NDIM-2) 107,107,105
  105 KBMAX = 0
      DO 106 KB = 1,NREGKB
      KBMAX = KBMAX+MSHKB(KB)
  106 CONTINUE
C
      IF(KBMAX .GE. MSX ) THEN
      WRITE(6,'(1X,A)')
     &' ** MESSAGE FROM KBMAX IN SUBROUTINE MESH. **'
      WRITE(6,'(1X,A)')
     &'INSUFFICIENT MESH AREA NUMBER FOR MSX.'
      WRITE(6,'(1X,A,I5)')
     &'CURRENT NUMBER FOR MSX IS ',MSX
      WRITE(6,'(1X,A)')
     &'COULD YOU PLEASE CHECK YOUR NUMBER IN INCLUDE FILE IMMEDIATERY.'
      WRITE(6,'(1X,A)')
     &'I AM WILLING TO YOUR QUICK RESPONCE. THANK YOU.'
      STOP
      ENDIF
C
  107 NRGNO = 0
      MESHGE = 0
      DO 125 KBR = 1,NREGKB
      NKBPTS = MSHKB(KBR)
      U3 = NKBPTS
      ZDIST = XSHKB(KBR)
      YDIST2 = 0.D+0
      DO 124 IR = 1,NREGI
      NIPTS = MSHI(IR)
      U1 = NIPTS
      YDIST = XSHI(IR)
      YDIST1 = YDIST2
      YDIST2 = YDIST2+XSHI(IR)
      XDIST2 = 0.D+0
      DO 123 JR = 1,NREGJ
      XDIST1 = XDIST2
      XDIST2 = XDIST2+XSHJ(JR)
      NJPTS = MSHJ(JR)
      U2 = NJPTS
      XDIST = XSHJ(JR)
      NTOPTS = NKBPTS*NIPTS*NJPTS
      XNTOPS = FLOAT(NTOPTS)
      NRGNO = NRGNO+1
      GO TO (108,109,110,111,112,113,114,115,116,117,118,119,120,121),
     & NGEM
  108 AXYR = XDIST
      GO TO 122
  109 AXYR = 3.141593*(XDIST2**2-XDIST1**2)
      GO TO 122
  110 AXYR = 4.0*3.141593/3.0*(XDIST2**3-XDIST1**3)
      GO TO 122
  111 AXYR = 1.0
      GO TO 122
  112 GO TO 122
  113 AXYR = YDIST*XDIST
      GO TO 122
  114 AXYR = 3.141593*(XDIST2**2-XDIST1**2)*YDIST
      GO TO 122
  115 AXYR = XDIST*(YDIST2**2-YDIST1**2)/2.0
      GO TO 122
  116 AXYR = 0.3608439* ((XDIST/U2)**2+(YDIST/U1)**2+ 0.4*XDIST*YDIST/
     & (U2*U1))*XNTOPS
      GO TO 122
  117 CONTINUE
      AXYR = 0.8660254040*XDIST*YDIST
C     SQRT(3)/2 = 0.8660254040
      GO TO 122
  118 AXYR = ZDIST*YDIST*XDIST
      GO TO 122
  119 AXYR = 0.5*ZDIST*XDIST*(YDIST2**2-YDIST1**2)
      GO TO 122
  120 AXYR = 0.3608439*ZDIST*((XDIST/U2)**2+(YDIST/U1)**2+ 0.4*XDIST*
     & YDIST/(U2*U1))*XNTOPS/U3
      GO TO 122
  121 CONTINUE
      AXYR = 0.8660254040*XDIST*YDIST*ZDIST
C     SQRT(3)/2 = 0.8660254040
  122 RVOL(NRGNO) = AXYR
      PVOL(NRGNO) = AXYR/XNTOPS
      IF ((NGEM.NE.9).OR.(NGEM.NE.13)) GO TO 123
      IF (NRGNO.EQ.1) GO TO 123
      IF (PVOL(1).NE.PVOL(NRGNO)) MESHGE = 1
  123 CONTINUE
  124 CONTINUE
  125 CONTINUE
      KB = 0
      ZZ(1) = 0.0
      ZXYR=0.D+0
      ADR = 0.0
      DO 133 KBR = 1,NREGKB
      NKBPTS = MSHKB(KBR)
      XNKPTS = FLOAT (NKBPTS)
      ZDEL = XSHKB(KBR)/XNKPTS
      DO 132 KNR = 1,NKBPTS
      KB = KB+1
      ZXYR=ZXYR+ZDEL
      IF (KB-1) 126,126,127
  126 AXYR=0.5D+0*ZDEL
      GO TO 130
  127 IF (KNR-1) 128,128,129
  128 AXYR = AXYR + 0.5*(ZDEL+ADR)
      GO TO 130
  129 AXYR=AXYR+ZDEL
  130 ZZ(KB+1)=ZXYR
      Z(KB)=AXYR
      IF (KNR-NKBPTS) 132,131,131
  131 ADR = ZDEL
  132 CONTINUE
  133 CONTINUE
      NREGIJ = NREGI
      IF (MGEM-8) 135,134,135
  134 NREGIJ = NREGJ
  135 I = 0
      YY(1) = 0.0
      ZXYR=0.D+0
      ADR = 0.0
      DO 147 IR = 1,NREGIJ
      IF (MGEM-8) 136,137,136
  136 NIPTS = MSHI(IR)
      XNIPTS = FLOAT(NIPTS)
      XDEL = XSHI(IR)/XNIPTS
      GO TO 138
  137 NIPTS = MSHJ(IR)
      XNIPTS = FLOAT(NIPTS)
      XDEL = XSHJ(IR)/XNIPTS
  138 DO 146 INR = 1,NIPTS
      I=I+1
      IF ((NGEM.NE.10).AND.(NGEM.NE.14)) GO TO 139
      Y(I) = YY(I)+H
      YY(I+1) = YY(I)+3.0*H
      PDI(I) = YY(I+1)-H
      GO TO 146
  139 CONTINUE
      ZXYR=ZXYR+XDEL
      IF (I-1) 140,140,141
  140 AXYR=0.5D+0*XDEL
      GO TO 144
  141 IF (INR-1) 142,142,143
  142 AXYR=AXYR+0.5*(XDEL+ADR)
      GO TO 144
  143 AXYR=AXYR+XDEL
  144 Y(I)=AXYR
      YY(I+1)=ZXYR
      IF (INR-NIPTS) 146,145,145
  145 ADR = XDEL
  146 CONTINUE
  147 CONTINUE
      ZTEMP = 1.0/3.0
      J = 0
      XX(1) = 0.0
      ZXYR=0.D+0
      ZDEL1 = ZZ(2)-ZZ(1)
      YDEL1 = YY(2)-YY(1)
      IF (NGEM-5) 148,148,149
  148 T1 = 1.0
      GO TO 152
  149 IF (NGEM-11) 150,151,151
  150 T1 = YDEL1
      GO TO 152
  151 T1 = YDEL1*ZDEL1
  152 CONTINUE
      YDELSQ = YY(2)**2-YY(1)**2
      NREGIJ = NREGJ
      IF (MGEM-8) 154,153,154
  153 NREGIJ = NREGI
  154 DO 164 JR = 1,NREGIJ
      IF (MGEM.EQ.8) GO TO 155
      NJPTS = MSHJ(JR)
      TEMP = PVOL(JR)/T1
      XNJPTS = FLOAT(NJPTS)
      XDEL = XSHJ(JR)/XNJPTS
      GO TO 156
  155 NJPTS = MSHI(JR)
      JS = (JR-1)*NREGJ+1
      TEMP = PVOL(JS)/T1
      XNJPTS = FLOAT(NJPTS)
      XDEL = XSHI(JR)/XNJPTS
  156 DO 163 JNR = 1,NJPTS
      J = J+1
      GO TO (157,158,161,163,163,157,158,159,157,160,157,159,157,160),
     & NGEM
  157 ZXYR=ZXYR+XDEL
      GO TO 162
  158 ZXYR= DSQRT(TEMP/3.141593+ZXYR**2)
      GO TO 162
  159 ZXYR= DSQRT(2.0*TEMP+ZXYR **2)
      GO TO 162
  160 CONTINUE
      X(J) = XX(J)+H
      XX(J+1) = X(J)+H
      GO TO 163
  161 ZXYR= (3.0*TEMP/(4.0*3.141593)+ZXYR**3)**ZTEMP
  162 CONTINUE
      XX(J+1)=ZXYR
  163 CONTINUE
  164 CONTINUE
      IF ((NGEM.EQ.10).OR.(NGEM.EQ.14)) GO TO 171
      JXLM = JMAX
      IF (MGEM.EQ.8) JXLM = IMAX
      DO 168 J = 1,JXLM
      GO TO (165,166,167,168,168,165,166,166,165,168,165,166,165,168),
     & NGEM
  165 X(J) = (XX(J+1)+XX(J))*0.5
      GO TO 168
  166 X(J) = SQRT((XX(J+1)**2+XX(J)**2)*0.5)
      GO TO 168
  167 X(J) = ((XX(J+1)**3+XX(J)**3)*0.5)**ZTEMP
  168 CONTINUE
      IF (MGEM-8) 171,169,171
  169 DO 170 N = 1,NXY
      TEMP1 = XX(N)
      TEMP2 = YY(N)
      XX(N) = TEMP2
      YY(N) = TEMP1
      TEMP1 = X(N)
      TEMP2 = Y(N)
      X(N) = TEMP2
      Y(N) = TEMP1
  170 CONTINUE
  171 CONTINUE
      IMXP1=IMAX+1
      JMXP1=JMAX+1
      KBMXP1 = KBMAX+1
      GO TO (172,174,175,175,175,176,179,180,181,182,183,187,188,189),
     & NGEM
  172 IF(ISTEP.EQ.1)WRITE(IOUT,1005)XX(JMAX+1)
  173 IF(ISTEP.EQ.1)WRITE(IOUT,1006)
      IF(ISTEP.EQ.1)WRITE(IOUT,1007)(MSHJ(J),XSHJ(J),J=1,NREGJ)
      IF(ISTEP.EQ.1)WRITE(IOUT,1008)JMAX
      IF(ISTEP.EQ.1)WRITE(IOUT,1009)
      IF(ISTEP.EQ.1)WRITE(IOUT,1010)(J,XX(J),J=2,JMXP1)
      IF(ISTEP.EQ.1)WRITE(IOUT,1011)
      IF(ISTEP.EQ.1)WRITE(IOUT,1010)(J,X(J),J=1,JMAX)
      GO TO 190
  174 IF(ISTEP.EQ.1)WRITE(IOUT,1012)XX(JMAX+1)
      GO TO 173
  175 IF(ISTEP.EQ.1)WRITE(IOUT,1013)XX(JMAX+1)
      GO TO 173
  176 IF(ISTEP.EQ.1)WRITE(IOUT,1014)XX(JMAX+1),YY(IMAX+1)
  177 IF(ISTEP.EQ.1)WRITE(IOUT,1006)
      IF(ISTEP.EQ.1)WRITE(IOUT,1007)(MSHJ(J),XSHJ(J),J=1,NREGJ)
      IF(ISTEP.EQ.1)WRITE(IOUT,1015)
      IF(ISTEP.EQ.1)WRITE(IOUT,1007)(MSHI(I),XSHI(I),I=1,NREGI)
      IF(ISTEP.EQ.1)WRITE(IOUT,1016)JMAX,IMAX
      IF(ISTEP.EQ.1)WRITE(IOUT,1009)
      IF(ISTEP.EQ.1)WRITE(IOUT,1010)(J,XX(J),J=2,JMXP1)
      IF(ISTEP.EQ.1)WRITE(IOUT,1017)
      IF(ISTEP.EQ.1)WRITE(IOUT,1010)(I,YY(I),I=2,IMXP1)
      IF(ISTEP.EQ.1)WRITE(IOUT,1011)
      IF(ISTEP.EQ.1)WRITE(IOUT,1010)(J,X(J),J=1,JMAX)
      IF (NGEM.NE.10) GO TO 178
      IF(ISTEP.EQ.1)WRITE(IOUT,1000)
      IF(ISTEP.EQ.1)WRITE(IOUT,1001)(I,Y(I),PDI(I),I=1,IMAX)
      GO TO 190
  178 CONTINUE
      IF(ISTEP.EQ.1)WRITE(IOUT,1017)
      IF(ISTEP.EQ.1)WRITE(IOUT,1010)(I,Y(I),I=1,IMAX)
      GO TO 190
  179 IF(ISTEP.EQ.1)WRITE(IOUT,1018)XX(JMAX+1),YY(IMAX+1)
      GO TO 177
  180 IF(ISTEP.EQ.1)WRITE(IOUT,1019)XX(JMAX+1),YY(IMAX+1)
      GO TO 177
  181 IF(ISTEP.EQ.1)WRITE(IOUT,1020)XX(JMAX+1),YY(IMAX+1)
      GO TO 177
  182 CONTINUE
      IF(ISTEP.EQ.1)WRITE(IOUT,1002)XX(JMAX+1),YY(IMAX+1)
      GO TO 177
  183 IF(ISTEP.EQ.1)WRITE(IOUT,1021)XX(JMAX+1),YY(IMAX+1),ZZ(KBMAX+1)
  184 IF(ISTEP.EQ.1)WRITE(IOUT,1006)
      IF(ISTEP.EQ.1)WRITE(IOUT,1007)(MSHJ(J),XSHJ(J),J=1,NREGJ)
      IF(ISTEP.EQ.1)WRITE(IOUT,1015)
      IF(ISTEP.EQ.1)WRITE(IOUT,1007)(MSHI(I),XSHI(I),I=1,NREGI)
      IF(ISTEP.EQ.1)WRITE(IOUT,1022)
      IF(ISTEP.EQ.1)WRITE(IOUT,1007)(MSHKB(I),XSHKB(I),I=1,NREGKB)
      IF(ISTEP.EQ.1)WRITE(IOUT,1023)JMAX,IMAX,KBMAX
      IF(ISTEP.EQ.1)WRITE(IOUT,1009)
      IF(ISTEP.EQ.1)WRITE(IOUT,1010)(J,XX(J),J=2,JMXP1)
      IF(ISTEP.EQ.1)WRITE(IOUT,1017)
      IF(ISTEP.EQ.1)WRITE(IOUT,1010)(I,YY(I),I=2,IMXP1)
      IF(ISTEP.EQ.1)WRITE(IOUT,1024)
      IF(ISTEP.EQ.1)WRITE(IOUT,1010)(KB,ZZ(KB),KB=2,KBMXP1)
      IF(ISTEP.EQ.1)WRITE(IOUT,1011)
      IF(ISTEP.EQ.1)WRITE(IOUT,1010)(J,X(J),J=1,JMAX)
      IF (NGEM.NE.14) GO TO 185
      IF(ISTEP.EQ.1)WRITE(IOUT,1000)
      IF(ISTEP.EQ.1)WRITE(IOUT,1001)(I,Y(I),PDI(I),I=1,IMAX)
      GO TO 186
  185 CONTINUE
      IF(ISTEP.EQ.1)WRITE(IOUT,1017)
      IF(ISTEP.EQ.1)WRITE(IOUT,1010)(I,Y(I),I=1,IMAX)
  186 CONTINUE
      IF(ISTEP.EQ.1)WRITE(IOUT,1024)
      IF(ISTEP.EQ.1)WRITE(IOUT,1010)(KB, Z(KB ),KB=1,KBMAX)
      GO TO 190
  187 IF(ISTEP.EQ.1)WRITE(IOUT,1025)XX(JMAX+1),YY(IMAX+1),ZZ(KBMAX+1)
      GO TO 184
  188 IF(ISTEP.EQ.1)WRITE(IOUT,1026)XX(JMAX+1),YY(IMAX+1),ZZ(KBMAX+1)
      GO TO 184
  189 CONTINUE
      IF(ISTEP.EQ.1)WRITE(IOUT,1003)XX(JMAX+1),YY(IMAX+1),ZZ(KBMAX+1)
      GO TO 184
  190 CONTINUE
      DO 191 J = 1,JMAX
      IF (XX(J)-XX(J+1)) 191,194,194
  191 CONTINUE
      DO 192 I = 1,IMAX
      IF (YY(I)-YY(I+1)) 192,194,194
  192 CONTINUE
      DO 193 KB = 1,KBMAX
      IF (ZZ(KB)-ZZ(KB+1)) 193,193,194
  193 CONTINUE
      GO TO 195
  194 NER(3) = 3
  195 IF (MESHGE.EQ.0) GO TO 196
      IF(ISTEP.EQ.1)WRITE(IOUT,1027)
  196 CONTINUE
      IF ((NGEM.NE.10).AND.(NGEM.NE.14)) GO TO 200
      DO 199 I = 1,NREGI
      T1 = 2*MSHI(I)
      T2 = XSHI(I)
      DO 198 J = 1,NREGJ
      T3 = MSHJ(J)
      T4 = XSHJ(J)
      T5 = (T1*T4)/(T2*T3)
      T6 = ABS(T5-1.0)
      IF (T6.LE.0.00001) GO TO 197
      IF(ISTEP.EQ.1)WRITE(IOUT,1004)I,J,T1,T4,T3,T2,T5
  197 CONTINUE
  198 CONTINUE
  199 CONTINUE
  200 CONTINUE
      IF(NGC(7).EQ.0) GO TO 201
      IO32 = IX(138)
      REWIND IO32
      WRITE(IO32)(TITL1(I),I=1,18),(TITL2(I),I=1,18),NUAC(5),JMAX,IMAX,
     &KBMAX,NGC(21),NGC(7),(X(J),J=1,JMAX),(Y(I),I=1,IMAX),(Z(KB),KB=1,
     &KBMAX)
      END FILE IO32
      REWIND IO32
  201 CONTINUE
      RETURN
 1000 FORMAT('0    I   ODD J  EVEN J')
 1001 FORMAT(1H ,I5,2F8.3,I5,2F8.3,I5,2F8.3,I5,2F8.3,I5,2F8.3,I5,2F8.3)
 1002 FORMAT(2H0 ,'TWO DIMENSIONAL TRIANGULAR GEOMETRY (X,Y)'
     & ,2H  ,'WIDTH',1PE14.6,2H  ,'HEIGHT',E14.6//)
 1003 FORMAT(2H0 ,'THREE DIMENSIONAL TRIANGULAR GEOMETRY (X,Y,Z)'
     & ,2H  ,'WIDTH',1PE14.6,2H  ,'HEIGHT',E14.6,2H  ,'DEPTH',E14.6//)
 1004 FORMAT('0******WARNING--TRIANGLES NOT EQULATERAL FOR HORIZONTAL-',
     &'VERTICAL REGION',2I3/' 2*I, WIDTH, J, HEIGHT, AND (2*I*WIDTH)/',
     &'/(J*HEIGHT) ARE',1P5E13.5)
 1005 FORMAT('0 ONE DIMENSIONAL SLAB GEOMETRY (X)  WIDTH',1PE14.6/
     &  /)
 1006 FORMAT('0 REGION SPECIFICATIONS'/'    PTS  REGION WIDTH')
 1007 FORMAT(1H ,I6,1PE14.6,I6,E14.6,I6,E14.6,I6,E14.6,I6,E14.6, I6,
     & E14.6)
 1008 FORMAT('0 X-DIR. POINTS',I4)
 1009 FORMAT('0 DISTANCES TO MESH INTERVAL',' INTERFACES'/
     & '0    J   DIST.')
 1010 FORMAT(1H ,I5,F8.3,I5,F8.3,I5,F8.3,I5,F8.3,I5,F8.3,I5,F8.3, I5,
     & F8.3,I5,F8.3,I5,F8.3)
 1011 FORMAT('0 DISTANCES TO FLUX POINTS'/'0    J   DIST.')
 1012 FORMAT('0 ONE DIMENSIONAL CYLINDRICAL GEOMETRY (R)'
     & ,'  WIDTH',1PE14.6//)
 1013 FORMAT('0 ONE DIMENSIONAL SPHERICAL GEOMETRY (R)'
     & ,'  WIDTH',1PE14.6//)
 1014 FORMAT('0 TWO DIMENSIONAL SLAB GEOMETRY (X,Y)'
     & ,'  WIDTH',1PE14.6,'  HEIGHT',E14.6//)
 1015 FORMAT('0   PTS  REGION HEIGHT')
 1016 FORMAT('0 X-DIR. POINTS',I4,'         Y-DIR. POINTS',I4)
 1017 FORMAT('0    I   DIST.')
 1018 FORMAT('0 TWO DIMENSIONAL CYLINDRICAL GEOMETRY (R,Z)'
     & ,'  WIDTH',1PE14.6,'  HEIGHT',E14.6//)
 1019 FORMAT('0 TWO DIMENSIONAL CIRCULAR GEOMETRY (R,THETA)'
     & ,'  WIDTH',1PE14.6,'  HEIGHT',E14.6//)
 1020 FORMAT('0 TWO DIMENSIONAL HEXAGIONAL GEOMETRY (X,Y)'
     & ,'  WIDTH',1PE14.6,'  HEIGHT',E14.6//)
 1021 FORMAT('0 THREE DIMENSIONAL SLAB GEOMETRY (X,Y,Z)'
     & ,'  WIDTH',1PE14.6,'  HEIGHT',E14.6,'  DEPTH',E14.6//)
 1022 FORMAT('0   PTS  REGION DEPTH')
 1023 FORMAT('0 X-DIR. POINTS',I4,'         Y-DIR. POINTS',I4,
     & '         Z-DIR. POINTS',I4)
 1024 FORMAT('0    KB   DIST')
 1025 FORMAT('0 THREE DIMENSIONAL CYLINDRICAL GEOMETRY (R,THETA,Z)'
     & ,'  WIDTH',1PE14.6,'  HEIGHT',E14.6,'  DEPTH',E14.6//)
 1026 FORMAT('0 THREE DIMENSIONAL HEXAGIONAL GEOMETRY (X,Y,Z)'
     & ,'  WIDTH',1PE14.6,'  HEIGHT',E14.6,'  DEPTH',E14.6//)
 1027 FORMAT('0******WARNING--REGION VOLUMES NOT EQUAL IN HEX GEOM.')
      END
