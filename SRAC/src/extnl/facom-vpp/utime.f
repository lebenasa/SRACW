      SUBROUTINE UTIME(ITIME)
C
C     TIME IS FACOM BUILTIN SERVICE ROUTINE TO RETURN CURRENT TIME.
C     ITIME(OUTPUT) : CURRENT TIME IN THE CURRENT DATE IN MILI-SECOND
C                     FROM AM 0:00.
C
      CALL TIME(ITIME)
      RETURN
      END
