######################################################################
#    run PDSMDL
#    main : MicroEdit : print micro xs in the 99th device (by Leben Asa)
######################################################################
#
# Fortran logical unit usage
#   6   standard output
#  49   device used for PDS files (internally defined) 
#  99   text:message from PDSMDL (PDS read/write monitor)
#
#=============  Set by user ===================================
$SRAC_DIR = "E:\SRACW\SRAC"
#  LMD    : load module name
#  ODR    : directory in which output data will be stored
#  CASE   : case name which is refered as output file name
#  MICREF : directory name of MICREF PDS(A72)
#     
$LMN = "MicroEdit.exe"
$ODR = "$SRAC_DIR\tmp"
$CASE = "MicroEdit"
$MACRO = "$SRAC_DIR\tmp\PWRBurn/MICREF"
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
# INPUT (1) : directory name of MICREF 
# INPUT (2) : member name(A8), repeat until blank card
#
$Input = @"
$MICREF
XAM1X519
XNP7X519

"@
$Input | &"$LM" >> $OUTLST
#  rm $ODR/pdsmdl99.$CASE.$DATE
