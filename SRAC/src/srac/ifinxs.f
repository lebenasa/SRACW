      SUBROUTINE IFINXS ( CRX,IH1,IG1,IG3,MTT,EXTRA,IEXTRA,EXTRA8,SONME,
     &IG4,SOID,MTP,MCR )
C
C     READS STANDARD INTERFACE FILE ISOTXS FOR CROSS SECTIONS
C     FISSION AND VELOCITY DATA ARE NOT LOADED FROM THE FILE
C     IF IHT .GE. 5, THE N,2N AND TRANSPORT CROSS SECTIONS ARE
C     POSITIONED IN THE CORRECT TWOTRAN FORMAT
C
C     COMMON /UNITS/
C
      COMMON /TW1C/ DD(1),LIM1,IA(210)
      EQUIVALENCE (IA(155),NOUT),(IA(165),ISOTXS)
C
      DIMENSION CRX(IH1,IG1,1), SONME(IG4,IG3)
      DIMENSION MTT(*), EXTRA(*), EXTRA8(*), IEXTRA(*), SOID(*)
      DIMENSION IDENT ( 4 ), IIDENT ( 1 ), XSPEC ( 1 )
      DIMENSION ER1(3), ER3(5), ER4(5), ER5(7)
C
      EQUIVALENCE (IA(2),ISCT),(IA(4),IGM),(IA(16),IHT),(IA(17),IHS),
     &(IA(18),IHM)
      EQUIVALENCE (IDENT(4),IIDENT(1))
C
CSASA REAL*8 SONME,EXTRA8,SOID,IDENT,XSPEC,ER1,ER3,ER4,ER5
      REAL*8 SONME,EXTRA8,SOID,IDENT,XSPEC
      CHARACTER*8 ER1,ER3,ER4,ER5
C
      DATA ER1/'GROUP ','DISAGR','EES   '/
      DATA ER3/'MATERI','AL NOT',' FOUND',' ON FI','LE    '/
      DATA ER4/'MATERI','AL GRE','ATER T','HAN ON',' FILE '/
      DATA ER5/'ERROR ','IN TAB','LE POS','ITION ','SPECIF','ICATIO',
     &'N     '/
C
      WRITE (NOUT,520)
      NERR=0
C
C     LOAD X-SECTIONS SET POSITION NUMBERS
C
C     CALL LOAD (6HISOTXS,6H ID NO,MTT,MTT,MTP,-1)
      CALL REED (ISOTXS,0,0.0,0,4)
C
C     READ FILE IDENTIFICATION VECTOR
C
      CALL REED (ISOTXS,IDENT(4),IDENT,4,10)
      WRITE ( NOUT, 530 ) ( IDENT ( I ), I = 1, 3 ), IIDENT ( 1 )
C
C     READ SPECIFICATION VECTOR
C
      CALL REED (ISOTXS,IEXTRA,0.0,9,5)
      WRITE (NOUT,540)(IEXTRA(I),I=1,9)
      NEG=IEXTRA(1)
      NISO=IEXTRA(2)
      MAXU=IEXTRA(3)
      MAXD=IEXTRA(4)
      LMAX=IEXTRA(5)
      ICHIST=IEXTRA(6)
      NSCMAX=IEXTRA(7)
      NCBLOK=IEXTRA(8)
      NSBLOK=IEXTRA(9)
      NUPS=IHS-IHT-1
      NDNS=IHM-IHS
      IF ( NEG .EQ. IGM ) GO TO 90
      CALL ERROR ( 2, ER1, 3 )
      GO TO 441
C
C     READ FILE DATA RECORD
C
   90 CONTINUE
      NWDS=12+NISO
      CALL REED (ISOTXS,0,EXTRA8,NWDS,9)
      WRITE ( NOUT, 450 ) ( EXTRA8 ( I ), I = 1, 12 )
      DO 100 J=1,NISO
  100 SOID(J)=EXTRA8(J+12)
      ISCTP=ISCT+1
      IF (NCBLOK.EQ.1) GO TO 120
C
C     SKIP FISSION SPECTRUM AND VELOCITIES
C
      DO 110 I=1,NCBLOK
  110 CALL REED (ISOTXS,0,DUM,1,2)
  120 IF (MTP.GT.NISO) GO TO 430
      IFLAG=0
      DO 140 J=1,MTP
      DO 130 I=1,NISO
      IF (MTT(J).LE.NISO) GO TO 140
  130 CONTINUE
      IFLAG=1
      WRITE (NOUT,460)MTT(J)
  140 CONTINUE
      IF ( IFLAG .EQ. 0 ) GO TO 141
      CALL ERROR ( 2, ER3, 5 )
      GO TO 441
  141 CONTINUE
      WRITE (NOUT,470)
      ISTMTP=0
      DO 410 ISO=1,NISO
      DO 150 IST=1,MTP
      IF (ISO.EQ.MTT(IST)) GO TO 200
  150 CONTINUE
C
C     SKIP DATA FOR THIS ISOTOPE.  COMPUTATION OF NUMBER OF RECORDS TO
C     BE SKIPPED IS POSSIBLE, BUT IT IS SAFER TO PROGRAM THE DUMMY READS
C
      NWDS=2*NSCMAX+15
      CALL REED (ISOTXS,XSPEC,IEXTRA(2),NWDS,11)
      NCIBLK=IEXTRA(8)
      ICHI=IEXTRA(9)
      IFIS=IEXTRA(10)
      CALL REED (ISOTXS,0,DUM,1,2)
      IF (IFIS.LE.0.OR.ICHI.LE.0.OR.NCIBLK.LE.1) GO TO 170
      DO 160 I=1,NCIBLK
  160 CALL REED (ISOTXS,0,DUM,1,2)
  170 IF (LMAX.LE.0) GO TO 410
      J1=15+NSCMAX
      DO 190 J=1,NSCMAX
      J1=J1+1
      IF (IEXTRA(J1).LE.0) GO TO 190
      DO 180 I=1,NSBLOK
  180 CALL REED (ISOTXS,0,DUM,1,2)
  190 CONTINUE
      GO TO 410
C
C     READ DATA FOR THIS ISOTOPE
C
  200 M=1+(ISCT+1)*(IST-1)
      ISTMTP=ISTMTP+1
      IDXEM=MCR+IST*(ISCT+1)
      NWDS=(2*NEG+2)*NSCMAX+15
C
C     ISOTOPE CONTROL
C
      CALL REED (ISOTXS,XSPEC,EXTRA(2),NWDS,11)
      SONME(1,IST)=XSPEC(1)
      SONME(2,IST)=EXTRA(4)
      NCIBLK=IEXTRA(8)
      ICHI=IEXTRA(9)
      IFIS=IEXTRA(10)
      IALF=IEXTRA(11)
      INP=IEXTRA(12)
      IN2N=IEXTRA(13)
      IND=IEXTRA(14)
      INT=IEXTRA(15)
      LIDSCT=16
      LLORD=LIDSCT+NSCMAX
      LJBAND=LLORD+NSCMAX
      LIJJ=LJBAND+NEG*NSCMAX
      JTMP=LIJJ+NEG*NSCMAX
C
C     PRINCIPAL CROSS SECTIONS RECORD
C
      NWDS=(4+IFIS*(ICHI*(1/NCIBLK)+2)+IALF+INP+IN2N+IND+INT)*NEG
      CALL REED (ISOTXS,0,EXTRA(JTMP),NWDS,2)
      DO 260 J=1,NEG
      JJ1=JTMP+J-1
      JJ=JJ1+2*NEG
      CRX(IHT,J,M)=EXTRA(JJ)
      J1=JTMP+3*NEG+J-1
      CRX(IHT-2,J,M)=EXTRA(J1)
      IF (IHT.GE.6) CRX(IHT-5,J,M)=EXTRA(J1)
      IF (IHT.GE.5) CRX(IHT-3,J,M)=EXTRA(JJ1)
      CRX(IHT-1,J,M)=0.0
      ITMP=JTMP+4*NEG+J-1
      IF (IFIS.LE.0) GO TO 210
      J2=ITMP+NEG
      IF (IHT.EQ.4) CRX(IHT-3,J,M)=EXTRA(ITMP)
      CRX(IHT-2,J,M)=CRX(IHT-2,J,M)+EXTRA(ITMP)
      CRX(IHT-1,J,M)=EXTRA(ITMP)*EXTRA(J2)
      ITMP=ITMP+2*NEG
      IF (ICHI.LE.0.OR.NCIBLK.GT.1) GO TO 210
      ITMP=ITMP+ICHI*NEG
  210 IF (IALF.LE.0) GO TO 220
      CRX(IHT-2,J,M)=CRX(IHT-2,J,M)+EXTRA(ITMP)
      IF (IHT.GE.7) CRX(IHT-6,J,M)=EXTRA(ITMP)
      ITMP=ITMP+NEG
  220 IF (INP.LE.0) GO TO 230
      CRX(IHT-2,J,M)=CRX(IHT-2,J,M)+EXTRA(ITMP)
      IF (IHT.GE.8) CRX(IHT-7,J,M)=EXTRA(ITMP)
      ITMP=ITMP+NEG
  230 IF (IN2N.LE.0) GO TO 240
      CRX(IHT-2,J,M)=CRX(IHT-2,J,M)-EXTRA(ITMP)
      IF (IHT.GE.5) CRX(IHT-4,J,M)=EXTRA(ITMP)
      ITMP=ITMP+NEG
  240 IF (IND.LE.0) GO TO 250
      CRX(IHT-2,J,M)=CRX(IHT-2,J,M)+EXTRA(ITMP)
      IF (IHT.GE.9) CRX(IHT-8,J,M)=EXTRA(ITMP)
      ITMP=ITMP+NEG
  250 IF (INT.LE.0) GO TO 260
      CRX(IHT-2,J,M)=CRX(IHT-2,J,M)+EXTRA(ITMP)
      IF (IHT.GE.10) CRX(IHT-9,J,M)=EXTRA(ITMP)
  260 CONTINUE
C
C     ISOTOPE CHI DATA
C
      IF (IFIS.LE.0.OR.ICHI.LE.0.OR.NCIBLK.LE.1) GO TO 280
      DO 270 N=1,NCIBLK
  270 CALL REED (ISOTXS,0,DUM,1,2)
  280 CONTINUE
C
C     SCATTERING DATA
C
      JJ=LIDSCT-1
      JJJ=LLORD-1
      MAXORD=0
      MAXU=0
      MAXD=0
      DO 381 NB = 1, NSCMAX
      JJ=JJ+1
      JJJ=JJJ+1
C
C     IEXTRA(JJJ)=LORD(NB)
C     IEXTRA(JJ)=IDSCT(NB)
C
      IF ( IEXTRA ( JJJ ) .LE. 0 ) GO TO 381
      IF (IEXTRA(JJ).LT.100) GO TO 300
C
C     BLOCK NB DOES NOT CONTAIN TOTAL SCAT XSECS--SKIP IT
C
      DO 290 I=1,NSBLOK
  290 CALL REED (ISOTXS,0,DUM,1,2)
      GO TO 381
C
C     BLOCK NB CONTAINS TOTAL SCAT XSECS--STORE THEM
C
  300 IORD1=IEXTRA(JJ)+1
      IORD2=IORD1+IEXTRA(JJJ)-1
      IRS=(NEG-1)/NSBLOK+1
      DO 380 NSB=1,NSBLOK
      JL=(NSB-1)*IRS+1
      JU=NSB*IRS
      IF (JU.GT.NEG) JU=NEG
      NWDS=0
      J1=LJBAND-1+(NB-1)*NEG
C
C     COMPUTE SIZE OF SCATTERING SUB-BLOCK
C
      DO 310 J=JL,JU
      ITMP=J1+J
  310 NWDS=NWDS+IEXTRA(ITMP)
C
C     IEXTRA(ITMP)=JBAND(J,NB)
C
      NWDS=NWDS*IEXTRA(JJJ)
C
C     READ SCATTERING SUB-BLOCK
C
      CALL REED (ISOTXS,0,EXTRA(JTMP),NWDS,2)
      NWDS=JTMP-1
      DO 370 I=IORD1,IORD2
      MAXORD=MAX0(MAXORD,I)
      KIM1=M+I-1
      DO 360 J=JL,JU
      IF (I.GT.ISCTP) GO TO 340
      INDEX1=1
      IF (I.EQ.1) INDEX1=IHT+1
      DO 320 INDEX=INDEX1,IHM
  320 CRX(INDEX,J,KIM1)=0.0
      J1=LIJJ-1+(NB-1)*NEG+J
      IJJ=IEXTRA(J1)
      MAXLP=IJJ-1
      J1=LJBAND-1+(NB-1)*NEG+J
      JBAND=IEXTRA(J1)
      MAXLD=JBAND-IJJ
      MAXU=MAX0(MAXU,MAXLP)
      MAXD=MAX0(MAXD,MAXLD)
      IP1=IHS+1-IJJ
      IP2=IP1+JBAND-1
      DO 330 IT=IP1,IP2
      NWDS=NWDS+1
  330 CRX(IT,J,KIM1)=EXTRA(NWDS)
      IF (IP1.LE.IHT.OR.IP2.GT.IHM) GO TO 350
      GO TO 360
  340 WRITE (NOUT,480)SOID(IST),I,J
      GO TO 360
  350 WRITE (NOUT,490)SOID(IST),I,J,NUPS,MAXLP,NDNS,MAXLD
      NERR=NERR+1
  360 CONTINUE
  370 CONTINUE
  380 CONTINUE
  381 CONTINUE
      IF (MAXORD.GE.ISCTP) GO TO 400
      LMAXP1=MAXORD+1
      DO 390 I=LMAXP1,ISCTP
      KIM1=M+I-1
      DO 390 J=1,NEG
      DO 390 INDEX=1,IHM
  390 CRX(INDEX,J,KIM1)=0.0
  400 WRITE (NOUT,500) SOID(ISO),SONME(1,IST),SONME(2,IST),MAXORD,MAXU,
     &MAXD,IDXEM
      IF (ISTMTP.EQ.MTP) GO TO 420
  410 CONTINUE
  420 CALL REED (ISOTXS,0,0.0,0,4)
      GO TO 440
  430 WRITE (NOUT,510)(MTT(M),M=1,IG3)
      CALL ERROR ( 2, ER4, 5 )
      GO TO 441
  440 CONTINUE
      IF ( NERR .EQ. 0 ) RETURN
      CALL ERROR ( 2, ER5, 7 )
  441 CONTINUE
      CALL REED ( ISOTXS, 0, 0.0, 0, 4 )
      RETURN
C
  450 FORMAT (1H0, 12A6 )
  460 FORMAT ('0ISOTOPE ',I6,' NOT IN ISOTXS FILE')
  470 FORMAT ('0ISOTOPE   ABSOLUTE   TEMPERATURE   MAX ORDER     MAX G',
     &'ROUPS     MAX GROUPS       ISOTROPIC NUCLIDE'/' LABEL     LABEL',
     &'     (DEG K)       OF SCATTER    OF UPSCATTER   OF DOWNSCATTER ',
     &'  POSITION IN TABLE')
  480 FORMAT (' SCATTERING ORDER ON ISOTXS FILE GREATER THAN REQUESTED',
     &' FOR ',A6,3X,' SCATTERING ORDER',I4,' GROUP',I4)
  490 FORMAT ('0ERROR IN READING TOTAL SCATTERING FROM ISOTXS FILE FOR',
     & A6,3X,' SCATTERING ORDER',I4,' GROUP',I4/' TWOTRAN UPSCATTER',
     &'ING=',I4,' STANDARD FILE UPSCATTERING=',I4/' TWOTRAN DOWNSCATTE',
     &'RING=',I4,' STANDARD FILE DOWNSCATTERING=',I4)
  500 FORMAT (1X,A6,4X,A6,1PE16.5,6X,I3,11X,I3,12X,I3,16X,I3)
  510 FORMAT ('0NUMBER OF ISOTOPES REQUESTED MORE THAN CONTENTS OF STA',
     &'NDARD FILE'/' ISOTOPES REQUESTED'/(I6))
  520 FORMAT ('0     INTERFACE FILE ISOTXS IS USED TO OBTAIN INPUT CRO',
     &'SS SECTIONS')
  530 FORMAT (1H0,A6,' FILE NAME '/1X,A6,' USER IDENTIFICATION '/1X,A6
     &/1X,I6,' VERSION  ')
  540 FORMAT (1H ,I6,' NGROUP   '/1X,I6,' NISO     '/1X,I6,' MAXUP    '
     &  /1X,I6,' MAXD     '/1X,I6,' MAXORD   '/1X,I6,' ICHIST   '/1X,
     &I6,' NSCMAX   '/1X,I6,' NCBLOK   '/1X,I6,' NSBLOK   '//)
      END