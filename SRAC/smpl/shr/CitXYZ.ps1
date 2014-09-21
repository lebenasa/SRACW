#===============================================================================
#  <<  run SRAC  >>
#  CitXYZ.sh   : Sample calculation for a 3-D X-Y-Z geometry with CITATION
#                PIJ => CITATION (X-Y-Z)
#  Options     : Pij(Geometry type IGT=4, 9, 16), PEACO
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
$Case = "CitXYZ"
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
FUL1
Cell calculation for inner fuel (3.2 w/o UO2) with PIJ
1 1 1 1 2   1 4 3 -2 1   0 0 0 0 1   2 1 0 0 0 / SRAC CONTROL
1.000E-20 / Geometrical buckling for P1/B1 calculation
*- PDS files ------2---------3---------4---------5---------6---------7--
* Note : All input line must be written in 72 columns except comments
*        even when environmental variables are expanded.
E:/SRACW/SRACLIB-EDF70/pds/pfast   Old  File
E:/SRACW/SRACLIB-EDF70/pds/pthml   O    F
E:/SRACW/SRACLIB-EDF70/pds/pmcrs   O    F
$PDS_DIR/UFAST     Scratch  Core
$PDS_DIR/UTHERMAL  S        C
$PDS_DIR/UMCROSS   S        C
$PDS_DIR/MACROWRK  S        C
$PDS_DIR/MACRO     S        C
$PDS_DIR/FLUX      S        C
$PDS_DIR/MICREF    S        C
************************************************************************
62 45  1 1 /  107 group => 2 group
62(1)      /  Energy group structure suggested for LWR analyses
45(1)      /
62         /
45         /
***** Enter one blank line after input for energy group structure

***** Input for PIJ (Collision Probability Method)
4 7 7 3 1   1 7 0 0 0   5 0 6 45 0   0 90 0         / Pij Control
0 50 50 5 5 5 -1  0.0001 0.00001 0.001 1.0 10. 0.5  /
1 1 1 2 3 3 3  /  R-T
3(1)           /  X-R
1 2 3          /  M-R
0.0 0.236714 0.334764 0.41  0.475  0.5267 0.5783 0.630   / RX
4  / NMAT
FUE1X01X  0 3  900.   0.82     0.0  / 1 : Inner fuel 3.2 w/o
XU050000  2 0  7.2270E-4       /1
XU080000  2 0  2.1585E-2       /2
XO060000  0 0  4.4616E-2       /3
CLD1X02X  0 3  600.   0.13     0.0  / 2 : Cladding
XZRN0000  0 0  3.8032E-2       /1
XCRN0000  0 0  6.7152E-5       /2
XFEN0000  0 0  1.3129E-4       /3
MOD1X03X  0 2  581.   1.0      0.0  / 3 : Moderator
XH01H000  0 0  4.7508E-2       /1
XO060000  0 0  2.3754E-2       /2
REFLX04X  0 6  581.   1.0      0.0  / 4 : Reflector
XH01H000  0 0  4.7508E-2       /1
XO060000  0 0  2.3754E-2       /2
XFEN0000  0 0  1.7886E-2       /3
XCRN0000  0 0  5.2140E-3       /4
XNIN0000  0 0  2.4294E-3       /5
XMN50000  0 0  2.5977E-4       /6
0  / PEACO
FUL2
Outer fuel (2.1 w/o UO2), Same geometry with the above case
1 1 1 1 2   1 4 3 -2 1   1 0 0 0 1   2 1 0 0 0 / SRAC CONTROL
1.000E-20 / Geometrical buckling for P1/B1 calculation
3  / NMAT
FUE2X06X  0 3  900.   0.82     0.0  / 1 : Outer fuel 2.1 w/o
XU050000  2 0  4.7428E-4       /1
XU080000  2 0  2.1831E-2       /2
XO060000  0 0  4.4610E-2       /3
CLD2X07X  0 3  600.   0.13     0.0  / 2 : Cladding
XZRN0000  0 0  3.8032E-2       /1
XCRN0000  0 0  6.7152E-5       /2
XFEN0000  0 0  1.3129E-4       /3
MOD2X08X  0 2  581.   1.0      0.0  / 3 : Moderator
XH01H000  0 0  4.7508E-2       /1
XO060000  0 0  2.3754E-2       /2
0  / PEACO
CORE
Sample for CITATION-3D(X-Y-Z), 1/8 CORE
0 0 0 1 0  0 0 0 0 1  0 5 0 0 2  0 1 0 0 0 / SRAC CONTROL
1.0000E-20 / Buckling (not effective for core calculation)
3 0 -1 / NM NXR ID
1 1    / IXKY IDELAY (Calculate kinetics parameters)
5.0cm mesh size in each direction
EPS(FLUX) < 1.0E-4, EPS(KEFF) < 1.0E-5,  ZONE 4:BLACKNESS
001
  0  0  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0  0  0  0  0  0
  1  0  0  0  0  0  0  0  0  0  0  1  1  0  0  0  0  0  0  0  0  0  0  1
900
  0.
003
  0  0  0  0 11  0  0  0  0  0  1  0  0  1  0  1  4  1  0  0  0  0  0  0
  0.0001    0.00001
* Flux and power density are normalized to core power : 3411MWt*1/8(=0.125)
  0.0       0.0         3411.0      1.0         0.1250
004
  2 10.00000  4 20.00000  4 20.00000  4 20.00000  4 20.00000  4 20.00000
  4 20.00000  4 20.00000  4 20.00000  0
  4 20.00000  4 20.00000  4 20.00000  4 20.00000  4 20.00000  4 20.00000
  4 20.00000  4 20.00000  2 10.00000  0
  4 20.00000 34 170.0000  0
005
  3  3  3  3  4  4  4  4  4
  3  3  3  3  3  3  4  4  4
  3  3  3  3  3  3  3  4  4
  3  3  3  3  3  3  3  3  4
  3  3  3  3  3  3  3  3  4
  3  3  3  3  3  3  3  3  3
  3  3  3  3  3  3  3  3  3
  3  3  3  3  3  3  3  3  3
  3  3  3  3  3  3  3  3  3    / Axial reflector
*
  3  3  3  3  4  4  4  4  4
  2  2  2  3  3  3  4  4  4
  1  1  2  2  2  3  3  4  4
  1  1  1  1  2  2  3  3  4
  1  1  1  1  1  2  2  3  4
  1  1  1  1  1  1  2  3  3
  1  1  1  1  1  1  2  2  3
  1  1  1  1  1  1  1  2  3
  1  1  1  1  1  1  1  2  3    / Core
008
 -2  1  1
999

1 2 3   / Matterial No. by Zone
3       / NMAT for Core
FUL1A010  0 0    0.0  0.0  0.0   / Homogenized inner fuel
FUL2A010  0 0    0.0  0.0  0.0   / Homogenized outer fuel
REFLA040  0 0    0.0  0.0  0.0   / Reflector

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