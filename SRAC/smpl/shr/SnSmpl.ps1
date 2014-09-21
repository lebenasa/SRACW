#===============================================================================
#  <<  run SRAC  >>
#  SnSmpl.sh   : Analysis of STACY with PIJ, ANISN, and TWOTRAN
#  Options     : Pij(Geometry type IGT=4), ANISN, TWOTRAN
#===============================================================================
#


#
#============= Set by user =====================================================
#
#  LMN    : executable command of SRAC (SRAC/bin/*)
#  BRN    : burnup chain data          (SRAC/lib/burnlibT/*)
#  ODR    : directory in which output data will be stored
#  CASE   : case name which is refered as name of output files and PDS directory
#  WKDR   : working directory in which scratch files will be made and deleted
#  PDSD   : top directory name of PDS file
#

$SRAC_DIR = "E:\SRACW\SRAC"
$LMN = "SRAC.exe"
$BRN = "u4cm6fp50bp16T"
$ODR = "$SRAC_DIR\smpl\outp"
$Case = "SnSmpl"
$PDSD = "$SRAC_DIR\tmp"

#
#=============  mkdir for PDS  =================================================
#
#  PDS_DIR : directory name of PDS files
#  PDS file names must be identical with those in input data
#
$PDS_DIR = "$PDSD\$Case"
mkdir "$PDS_DIR"
mkdir "$PDS_DIR\UFAST"
mkdir "$PDS_DIR\UTHERMAL"
mkdir "$PDS_DIR\UMCROSS"
mkdir "$PDS_DIR\MACROWRK"
mkdir "$PDS_DIR\MACRO"
mkdir "$PDS_DIR\FLUX"
mkdir "$PDS_DIR\MICREF"

#  
#=============  Change if you like =============================================
#

$LM = "$SRAC_DIR/bin/$LMN"
$DATE = Get-Date -uformat "%Y.%m.%d.%H.%M.%S"
$WKDR = "$SRAC_DIR/SRACtmp.$Case.date $Date"
mkdir $WKDR
#
#-- File allocation
#  fu89 is used in any plot options, fu98 is used in the burnup option
#  Add other units if you would like to keep necessary files.
   $env:fu50 =  "$SRAC_DIR/lib/burnlibT/$BRN"
   $env:fu85 =  "$SRAC_DIR/lib/kintab.dat"
#  $env:fu89 =  "$ODR/$CASE.SFT89.$DATE.SAMPLE"
#  $env:fu98 =  "$ODR/$CASE.SFT98.$DATE.SAMPLE"
   $env:fu99 =  "$ODR/$CASE.SFT99.$DATE.SAMPLE"
   $OUTLST   =  "$ODR/$CASE.SFT06.$DATE.SAMPLE"
   
#
#=============  Exec SRAC code with the following input data ===================
#

cd $WKDR
$Input = @"
CELL
CRAC:  60.0 G/L : TEMP 40 C : HNO3 1 NOL : 53.52 CM HIGHT : DOPPLER 1
1 1 1 1 2   1 4 3 -2 0   0 0 1 0 2   1 1 0 0 0 / SRAC CONTROL
2.37826E-02 / R"=  16.700 CM  H"=  56.949 CM
*- PDS files ------2---------3---------4---------5---------6---------7--
* Note : All input line must be written in 72 columns except comments
*        even when environmental variables are expanded.
E:/SRACW/SRACLIB-EDF70/pds/pfast   Old  File
E:/SRACW/SRACLIB-EDF70/pds/pthml   O    F
E:/SRACW/SRACLIB-EDF70/pds/pmcrs   O    F
$PDS_DIR/UFAST      Scratch  Core
$PDS_DIR/UTHERMAL   S        C
$PDS_DIR/UMCROSS    S        C
$PDS_DIR/MACROWRK   S        C
$PDS_DIR/MACRO      S        C
$PDS_DIR/FLUX       S        C
$PDS_DIR/MICREF     S        C
************************************************************************
61 46 11  7 /
61(1)       /
46(1)       /
2 2 6 2 3 5 8 8 9 8 8 /
7 6 6 6 6 6 9         / 

3 20 20 20 2    2 20  0 0 0   1 0 10 30 0   0 60 0    / Pij Control
0 100 100 5 5 5 -1  0.0001 0.00001 0.001 1.0 10. 0.5  /
19(1) 2    / X-R
19(1) 2    / M-R
0.0  0.950 1.950 17*0.7500 15.0000 / RX
2  / NMAT
FUELX0FX  0  5 3.13150E+02 2.94000E+01 0.0 / FUEL  U= 60.0 G/CC
XH01H000  0  0  6.45244E-02
XN040000  0  0  9.02153E-04
XO060000  0  0  3.49747E-02
XU050000  2  0  1.41980E-04
XU080000  2  0  1.03898E-05
CLDDX0CX  0  7 2.93150E+02 6.00000E-01 0.0 / SUS304
XC020000  0  0  3.17290E-04
XSIN0000  0  0  1.69620E-03
XCRN0000  2  0  1.74080E-02
XMN50000  2  0  1.73430E-03
XFEN0000  2  0  5.78720E-02
XNIN0000  2  0  8.11160E-03
XS0N0000  0  0  4.45720E-05
0   / PEACO   
********************************************************************************
ANIS
WHOLE CORE 107G CALCULATION USING ANISN(S8P1) TO GET CONDENSED X-SEC.
0 0 0 1 0  0 0 0 0 0  0 -2 1 0 2  3 -1 0 0 0 / SRAC CONTROL
1.000E-15 / BUCKLING:NOT EFFECTIVE
15&
1 0 1 8 2  1 0 3 20 1  107 0 0 0 0  0 0 0 0 0  0 0 0 50 0  0 0 0 150 0
0 0 0 0 1  0
16*
0.00000E+00 0.00000E+00 1.00000E-05 1.42089E+00 5.39490E+01
0.00000E+00 0.00000E+00 0.00000E+00 0.00000E+00 5.00000E-01
5.00000E-05 5.00000E-02 1.00000E-02 0.00000E+00
00T
04*
0.0 0.950 1.950 17*0.750 15.000  / MESH BOUNDARY
08&
17(1) 2 2 3    / ZONE BY MESH
09&
    1  1  2    / MATERIAL BY ZONE
19&
    1  1  1    / P1 FOR ALL ZONES
27&
    1  2  3    / X-REGION BY ZONE
00T
2 / NMAT
CELLA012  0  0  0.0  0.0  0.0 / FUEL  U=60.0 G/CC
CELLA022  0  0  0.0  0.0  0.0 / SUS304
********************************************************************************
TWOC
WHOLE CORE 18 G CALCULATION USING TWOTRAN-2 (S8P1)
0 0 0 1 0   0 0 0 0 1   0 3 0 0 2   0 1 0 0 0 / SRAC CONTROL
1.000E-15 / ZERO BUCKLING
1 / NO OF TITLE CARD
WHOLE CORE 18 G CALCULATION USING TWOTRAN-2 (S8P1) : 2D-RZ : FORWARD
0 1 8 18 4   4 1 0 0 0   1 0 3 3 0  0 0 0 0 0    0 0 0 0 0  30 0 0
700 2   0 0 1 2 2  1 3 0 1 0  0 0    / 42I
0.00000E+00 0.00000E+00 0.00000E+00 0.00000E+00 0.00000E+00
0.00000E+00 1.00000E-05 1.00000E+00 0.00000E+00 0.00000E+00
 8  5  2  1    / FINE R-MESH
 2 25  2  1    / FINE Z-MESH
0.0   8.00   13.200  14.700  15.000  / R-MESH
0.0   1.50   52.449  53.949  54.249  / Z-MESH
  -2 -2 -2 -3
  -1 -1 -2 -3
  -2 -2 -2 -3
  -3 -3 -3 -3
  16(0)
3 / NMAT
ANISA010  0  0  0.0  0.0  0.0 / INNER FUEL
ANISA020  0  0  0.0  0.0  0.0 / OUTER FUEL
ANISA030  0  0  0.0  0.0  0.0 / SUS304
 
"@

$Input | &"$LM" >> $OUTLST

#
#========  Remove scratch files ================================================
#

cd "$SRAC_DIR"
rm -r "$WKDR"

#
#========  Remove PDS files if you don't keep them =============================
#

rm -r "$PDS_DIR"

#
#  rm -r $PDS_DIR/UFAST
#  rm -r $PDS_DIR/UTHERMAL
#  rm -r $PDS_DIR/UMCROSS
#  rm -r $PDS_DIR/MACROWRK
#  rm -r $PDS_DIR/MACRO
#  rm -r $PDS_DIR/FLUX
#  rm -r $PDS_DIR/MICREF