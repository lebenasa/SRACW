######################################################################
#
#                        convert a text-ps to a binary-pds
#    TEXT ===> PDS       txttopds.out : load module, (make -f MakeTP)
#                        by Leben Asa
#
#---------- Set by user -----------------
$SRAC_DIR = "E:\SRACW\SRAC"
#
#  TEXT : file name of the input text-ps (?.txt)
#  DIRT : directory name in which the text file exists
#  DIRP : directory name in which the produced pds members will be stored
#  DIRO : directory name in which output message will be stored
$TEXT = "macro.txt"
$DIRT = "$SRAC_DIR\tmp"
$DIRP = "$SRAC_DIR\tmp\MacroPDS"
$DIRO = "$SRAC_DIR\tmp"
mkdir "$DIRP"
#
#---------- Change if you like ----------
#
#  OMSG : file name of output message
$CASE = "casename"
$DATE = Get-Date -uformat "%Y.%m.%d.%H.%M.%S"
$OMSG = "TXTtoPDS.$CASE.$DATE"
#
#---------- Do not change ---------------
#
$TXT = "$DIRT\$TEXT"
$OUTP = "$DIRO\$OMSG"
$LM = "$SRAC_DIR\util\pdscnvt\bin\txttopds.exe"
#
   $env:fu10 = "$TXT"
#
$Input = @"
$DIRP
"@
$Input | &"$LM" >> $OUTLST
