#===============================================================================
#  <<  run SRAC  >>
#  PIE.sh      : Analysis of Post Irradiation Experiment (PIE) of a sample UO2
#                fuel (87C08) irradiated up to 31.4 GWd/t in a PWR (Mihama-3)
#  Options     : Pij(Geometry type IGT=4), PEACO, BURN-UP with cooling time
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
$Case = "PIE"
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
   $env:fu98 =  "$ODR/$CASE.SFT98.$DATE.SAMPLE"
   $env:fu99 =  "$ODR/$CASE.SFT99.$DATE.SAMPLE"
   $OUTLST   =  "$ODR/$CASE.SFT06.$DATE.SAMPLE"
   
#
#=============  Exec SRAC code with the following input data ===================
#

cd $WKDR
$Input = @"
NO08
PIE analysis of Mihama-3 Sample 87C08 : JAERI-M 93-061 pp162
1 1 1 1 2   1 4 3 -2 1   0 0 0 0 1   2 1 0 0 1 / SRAC CONTROL
1.000E-20 / Geometrical buckling for P1/B1 calculation
*- PDS files ------2---------3---------4---------5---------6---------7--
* Note : All input line must be written in 72 columns except comments
*        even when environmental variables are expanded.
*--------1---------2---------3---------4---------5---------6---------7--
E:/SRACW/SRACLIB-EDF70/pds/pfast   Old  File
E:/SRACW/SRACLIB-EDF70/pds/pthml   O    F
E:/SRACW/SRACLIB-EDF70/pds/pmcrs   O    F
$PDS_DIR/UFAST       Scratch  Core
$PDS_DIR/UTHERMAL    S        C
$PDS_DIR/UMCROSS     S        C
$PDS_DIR/MACROWRK    S        C
$PDS_DIR/MACRO       S        C
$PDS_DIR/FLUX        S        C
$PDS_DIR/MICREF      S        C
************************************************************************
62 45  1 1 /  107 group => 2 group
62(1)      /  Energy group structure suggested for LWR analyses
45(1)      /
62         / Fast    1 group
45         / Thermal 1 group
***** Enter one blank line after input for energy group structure

***** Input for PIJ (Collision Probability Method)
4 7 7 3 1   1 7 0 0 0   5 0 6 15 0   0 45 0         / Pij Control
0 50 50 5 5 5 -1  0.0001 0.00001 0.001 1.0 10. 0.5  /
1 1 1 2 3 3 3  /  R-S
3(1)           /  X-R
1 2 3          /  M-R
* effective cell pitch to presearve a spectrum index at sample fuel
0.0  0.2682 0.3793 0.4645   0.536   0.611 0.686 0.7610  / RX
****** Input for material specification
3 / NMAT
FUE1X01X  0 5 1150.  0.929   0.0  / 1 : UO2 fuel (3.25a/o)
XU040000  2 0  6.8257E-6       /1
XU050000  2 0  7.3957E-4       /2
XU080000  2 0  2.2005E-2       /3
XU060000  2 0  7.5020E-6       /4
XO060000  0 0  4.5518E-2       /5
CLD1X02X  0 3  608.  0.142   0.0  / 2 : cladding
XZRN0000  0 0  4.2982E-2       /1
XFEN0000  0 0  1.4838E-4       /2
XCRN0000  0 0  7.5891E-5       /3
MOD1X03X  0 4  588.  1.0     0.0  / 3 : moderator
XH01H000  0 0  4.6368E-2       /1  Density at 588K = 0.6936 g/cc
XO060000  0 0  2.3184E-2       /2
XB000000  0 0  3.7885E-6       /3
XB010000  0 0  1.5541E-5       /4
****** Input for cell burn-up calculation
20 3 1 1 0  0 0 0 0 1  10(0)   / IBC : burnup control
* Power history is normalized to achieve exporsure of sample fuel : 31.4GWd/t
3(1.73488e-04)    &
  0.00000e+00     & cooling
3(2.45971e-04)
  0.00000e+00     & cooling
4(2.45971e-04)
  0.00000e+00     & cooling
4(2.40521e-04)
2(1.92866e-04)
  0.00000e+00     / Power (MW/cm)
* Exposure in unit : accumulated days
10.0 100.0 215.0  &
603.0             & cooling
613.0 650.0 760.0
769.0             & cooling
780.0 850.0 900.0 939.0
1115.0            & cooling
1125.0 1200.0 1300.0 1467.0
1480.0 1495.0
3320.0            & cooling (5 years after irradiation)
* optional input for IBC10 (specification of burnable materials)
1 0 0    / Boron in water is not depleted
****** Input for PEACO option
0    / no plot

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