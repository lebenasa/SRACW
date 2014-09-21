######################################################################
#    run PDSMDL on VPP-500/42 :
#    main : FluxPlot : prepare plot tables for neutron spectrum by R-Region
#                      or X-Region.       (by Leben Asa)
######################################################################
#
# Fortran logical unit usage
#   6   standard output (Plot Data)
#  49   device used for PDS files (internally defined) 
#  99   text:message from PDSMDL (PDS read/write monitor)
#
#=============  Set by user ===================================
$SRAC_DIR = "E:\SRACW\SRAC"
#  LMD    : load module name
#  ODR    : directory in which output data will be stored
#  CASE   : case name which is refered as output file name
#  FLUX   : directory name of FLUX PDS(A72)
#     
$LMN = "FluxPlot.exe"
$ODR = "$SRAC_DIR\tmp"
$CASE = "FluxPlot"
$FLUX = "$SRAC_DIR\tmp\Sample\FLUX"
#  
#=============  Change if you like ============================
#
$LM = "$SRAC_DIR\util\pdsmdl\bin\$LMN"
$DATE = Get-Date -uformat "%Y.%m.%d.%H.%M.%S"
$env:fu99 = "$ODR\pdsmdl99.$CASE.$DATE"
$OUTLST = "$ODR\pdsmdl06.$CASE.$DATE"
#
#=============  Exec user's PDSMDL code =======================
# 
# INPUT (1) : directory name of FLUX
# INPUT (2) : member name(A8), repeat until blank card
#
$Input = @"
$FLUX 
TESTA002
TESTA012
TESTA112

"@
$Input | &"$LM" >> $OUTLST
#  rm $ODR/pdsmdl99.$CASE.$DATE
