<#
    SRAC Installation Conductor for Windows
    Author: Leben Asa (GMU-2014)
    Install SRAC load module (look at lmmk.sh)
    
    NOTE: Feature may differ from original script by Keisuke Okumura.
          I have no responsibility to any trouble regarding this
          script usage.
#>

if($SRAC_Code -eq $null) {
    "Don't forget to edit SRAC_Code to correct SRAC installation directory."
    "Running script with manual SRAC_Code definition"
    $global:SRAC_Code = " "
}

#Check whether needed variables exist. Otherwise use default parameters.
if($Fortran -eq $null) {
    $global:Fortran = "gfortran"
}
if($FFlag -eq $null) {
    $global:FFlag = "-fno-automatic -o2 -funroll-loops"
}
if($CComp -eq $null) {
    $global:CComp = "gcc"
}
if($CFlag -eq $null) {
    $global:CFlag = "-DPOSIX_C"
}

#---------- Set Load Module Name & Directory Name of Include Statement
$LMN = "$SRAC_Code/bin/SRAC.100m"
$INC = "$SRAC_Code/src/inc/srac100m"

#---------- Make Working Directory -------------------------------
$Date = "date " + Get-Date -uformat "%Y.%m.%d.%H.%M.%S"
$Workdir = "$SRAC_Code/tmp/tmpSRAC.$Date"

#
#---------- Copy Source Programs into Working Directory ----------
#
mkdir $Workdir
cd "$SRAC_Code/src"
cp plot/*.f          $Workdir
cp extnl/*.f         $Workdir
cp extnl/*.c         $Workdir
cp common/*.f        $Workdir
cp srac/*.f          $Workdir
cp read/*.f          $Workdir
cp burn/*.f          $Workdir
cp cit/*.f           $Workdir
cp pij/*.f           $Workdir
cp "$INC/*"          $Workdir

#---------- Compile C programs ----------------
cd $Workdir
$CComp -c $CFlags *.c
"--- end compile process for C-programs ---"
$Fortran =c $FFlags *.f
"--- end compile process for Fortran-programs ---"

#---------- Link all objects --------
$Fortran -o $LMN $FFlags *.o
"--- end linking process ---"

cd ..
Remove-Item $Workdir

#---------- End Process -----------------------