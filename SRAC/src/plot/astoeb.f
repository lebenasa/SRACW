C
C----------------------------------------------------------------------C
C                                                                      C
C       ASTOEB : TRANSFORM ASCII CHARACTER TO EBCDIC CHARACTER         C
C                                                                      C
C----------------------------------------------------------------------C
C
      SUBROUTINE    ASTOEB ( ASC , EBC )
C
      INTEGER       EBCDIC(128)
      CHARACTER*1   ASC
      INTEGER       EBC
C
CMSASA ... DOES NOT WORK ON LITTELE-ENDIAN
C     CHARACTER*4    CASC
C     EQUIVALENCE  ( IASC , CASC )
C
      DATA (EBCDIC(I),I=1,128)/
     1       0,   1,   2,   3,  55,  45,  46,  47,  22,   5,
     2       9,  11,  12,  13,  14,  15,  16,  17,  18, 176,
     3      60,  61,  50,  38,  24,  25,  55,  39,  28,  29,
     4      30,  31,  64,  90, 127, 123, 224, 108,  80, 125,
     5      77,  93,  92,  78, 107, 109,  75,  97, 240, 241,
     6     242, 243, 244, 245, 246, 247, 248, 249, 122,  94,
     7      76, 126, 110, 111, 124, 193, 194, 195, 196, 197,
     8     198, 199, 200, 201, 209, 210, 211, 212, 213, 214,
     9     215, 216, 217, 226, 227, 228, 229, 230, 231, 232,
     A     233,  74,  91,  90,  95,  97, 121, 129, 130, 131,
     B     132, 133, 134, 135, 136, 137, 145, 146, 147, 148,
     C     149, 150, 151, 152, 153, 162, 163, 164, 165, 166,
     D     167, 168, 169, 192,  79, 208, 161,   7 /
C
CMSASA
*     IASC       =  0
C
*     CASC(4:4)  =  ASC
*     EBC        =  EBCDIC(IASC+1)
C
      EBC = EBCDIC(ICHAR(ASC)+1)
C
      RETURN
      END
