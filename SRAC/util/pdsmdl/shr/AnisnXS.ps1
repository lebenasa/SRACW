######################################################################
#    run PDSMDL 
#    main : AnisnXS : convert Macroscopic XS in PDS 
#           to ANISN type binary XS data     (by Leben Asa)
######################################################################
#
# Fortran logical unit usage
#   1   Anisn type binary XS data
#   6   standard output (PDS monitor, original XS is printed here)
#  49   device used for PDS files (internally defined)
#  99   output text (ANISN form XS data is printed here)
#
#=============  Set by user ===================================
$SRAC_DIR = "E:\SRACW\SRAC"
#  LMD    : load module name
#  ODR    : directory in which output data will be stored
#  CASE   : case name which is refered as output file name
#  MACRO  : directory name of MACRO/MACROWRK PDS(A72)
#     
$LMN = "AnisnXS.exe"
$ODR = "$SRAC_DIR\tmp"
$CASE = "AnisnXS"
$MACRO = "$SRAC_DIR\tmp\ANISNXS\MACRO"
#  
#=============  Change if you like ============================
#
$LM = "$SRAC_DIR\util\pdsmdl\bin\$LMN"
$DATE = Get-Date -uformat "%Y.%m.%d.%H.%M.%S"
$env:fu01 = "$ODR\pdsmdl01.$CASE.$DATE"
$env:fu99 = "$ODR\pdsmdl99.$CASE.$DATE"
$OUTLST = "$ODR\pdsmdl06.$CASE.$DATE"
#
#=============  Exec user's PDSMDL code =======================
# 
# Block-1 : directory name of MACRO or MACROWRK (A72)
# Block-2 : Control options  NPL, MCOPT, IDEBUG, MSAVE (free fromat)
#           NPL   : PL-order (corresponding members are necessary)
#                   Note: NPL=0 means transport corrected P0 XS
#           MCOPT : option for negative XS caused by transport correction
#                 = 0 : no correction (only warning message)
#                 = 1 : correct as follows (necessary for Monte Carlo code)
#                       SIGTR(g)=SIGTR(g)+ABS(SIGS(g->g), and SIGS=0
#           IDEBUG: Print option for debugging 
#                   (Print Anisn format XS data on fu99)
#           MSAVE : option to reduce output library data size
#                 = 0 : down-scattering size is foced to be NG-1
#                       (suggested option)
#                 = 1 : down-scattering size is searched 
#                       (output library may not be available in some codes)
# Block-3 : member name and material ID number to be used other codes.(A8,I10)
#           4-th and 8-th character of member name is automatically
#           replaced by code.
#           Repeat Block-3 until blank card is entered
#
$Input = @"
$MACRO
0 1 1 0
PUO2A010      1000             / fuel
PUO2A020      2000             / clad
PUO2A030      3000             / moderator

"@
$Input | &"$LM" >> $OUTLST
#  rm $ODR/pdsmdl06.$CASE.$DATE
