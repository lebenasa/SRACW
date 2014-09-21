######################################################################
#
#                        convert a binary-pds to a text-ps
#    PDS ===> TEXT       pdstotxt.out : load module, (make -f MakePT)  
#                        by Leben Asa
#
######################################################################
$SRAC_DIR = "E:\SRACW\SRAC"
#
#---------- Set by user -----------------
#
#  TEXT : file name of the output text (?.txt)
#  DIRT : directory name in which the produced text will be stored
#  DIRP : directory name in which the pds members exist
#  DIRO : directory name in which output message will be stored
#  DIRW : work-directory name in which a member list file will be produced
#         the member list file will be removed in the last step
#
$TEXT = "pfastj32.txt"
$DIRT = "$SRAC_DIR\tmp"
$DIRP = "E:\SRACW\SRACLIB-JDL33\pds\pfast"
$DIRO = "$SRAC_DIR\tmp"
$DIRW = "$SRAC_DIR\tmp"
#
#---------- Change if you like ----------
#
#  OMSG : file name of output message
$CASE = "casename"
$DATE = Get-Date -uformat "%Y.%m.%d.%H.%M.%S"
$OMSG = "PDStoTXT.$CASE.$DATE"
#
#***** generate member list file *****
#
cd "$DIRP"
#
#  you can select members by using meta-character
#  ls -1               > $DIRW/memlist.$DATE
#  ls -1  ????????     > $DIRW/memlist.$DATE
#  ls -1  ????A0?[0ZN] > $DIRW/memlist.$DATE
#  ls -1  ?PU[0-9]*    > $DIRW/memlist.$DATE
#  ls -1  ?U0[0-9]*   >> $DIRW/memlist.$DATE
#
cd "$SRAC_DIR"
#
#---------- Do not change ---------------
#
$TXT = "$DIRT\$TEXT"
$OUTP = "$DIRO\$OMSG"
$LM = "$SRAC_DIR\util\pdscnvt\bin\pdstotxt.exe"
#
   $env:fu10 = "$TXT"
   $env:fu11 = "$DIRW/memlist.$DATE"
#
$Input = @"
$DIRP
"@
$Input | &"$LM" >> $OUTLST
rm "$DIRW/memlist.$DATE"
