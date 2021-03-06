<#
    SRAC Installation Conductor for Windows
    Author: Leben Asa (GMU-2014)
    Install SRAC load module (look at lmmk.sh)
    
    NOTE: Feature may differ from original script by Keisuke Okumura.
          I have no responsibility to any trouble regarding this
          script usage.
          
    UPDATE: Using GFortran may cause segmentation fault in SRAC. Compile
            using lmmake.ps1 instead.
#>

if($SRAC_Code -eq $null) {
    "Don't forget to edit SRAC_Code to correct SRAC installation directory."
    "Running script with manual SRAC_Code definition"
    $global:SRAC_Code = "D:/SRACs/SRAC"
}

" XXX Production of SRAC load module started."

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
$Date = Get-Date -uformat "%Y.%m.%d.%H.%M.%S"
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
cp cit/*.f          $Workdir
cp burn/*.f           $Workdir
cp pij/*.f           $Workdir
cp "$INC/*"          $Workdir

#---------- Compile C programs ----------------
cd $Workdir
&"$CComp" -c $CFlags *.c
"--- end compile process for C-programs ---"
&"$Fortran" -c $FFlags *.f
"--- end compile process for Fortran-programs ---"

#---------- Link all objects --------
&"$Fortran" -o $LMN $FFlags *.o
"--- end linking process ---"
cd "$SRAC_Code/bin"

function LmToExe {
    $Dir = Get-Location
    mkdir "tmp"
    cp '*.100m' "tmp"
    Get-ChildItem *.100m | Rename-Item -NewName { $_.name -replace '\.100m', '.exe' }
    Move-Item "tmp/*" -Destination $Dir
    Remove-Item "tmp"
}

LmToExe
cd .
Remove-Item $Workdir

" XXX Production of SRAC load module completed."
" XXX All processes completed."

#---------- End Process -----------------------