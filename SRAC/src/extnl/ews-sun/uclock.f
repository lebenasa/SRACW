      subroutine uclock(icpu)
C  For Sun-EWS
C --------------------------------------------------
C  uclock is originally a facom builtin service routine to return
C  current used cpu time(sec) in 4-byte integer.
C
C  icpu(output)  : current used cpu time (sec) in 4-byte integer
C
C --------------------------------------------------
C  Here, SunFortran Survice routine(etime) is used.
C  icpu is a user time + system time.
C --------------------------------------------------
C
      real*4      e, etime, t(2)
      integer*4   icpu
C
      e = etime(t)
C     e:elapsed time(sec), if e=-1.0 error
C     t(1): user time(sec)
C     t(2): system time(sec)
C
      if(e.eq.-1.0) return
      icpu = int(t(1)+t(2))
      return
      end
