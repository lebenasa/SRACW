      SUBROUTINE UTIME(ITIME)
C
C     TIME IS FACOM BUILTIN SERVICE ROUTINE TO RETURN CURRENT TIME.
C     ITIME(OUTPUT) : CURRENT TIME IN THE CURRENT DATE IN MILI-SECOND
C                     FROM AM 0:00.
C
      DIMENSION JTIME(3)
      CALL $ITIME(JTIME)
      ITIME = 3600 * JTIME(1) + 60 * JTIME(2) + JTIME(3)
      ITIME = 1000 * ITIME
      RETURN
      END
