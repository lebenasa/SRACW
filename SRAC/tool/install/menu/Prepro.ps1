<#
    SRAC Installation Conductor for Windows - Pre-processor
    Author: Leben Asa (GMU-2014)
    Pre-processor to generate system-dependent source programs, makefile,
    and shell script for Windows with C and Fortran installed.
    
    NOTE: Feature may differ from original script by Keisuke Okumura.
          I have no responsibility to any troubles regarding this
          script usage.
#>

if($SRAC_Code -eq $null) {
    "Please run this script from PunchMe.ps1."
    exit
}

$Syst   = "pc-windows"
$Sysad  = "windows-gfortran"
$Fortran= "gfortran"
$FFlag  = "-fno-automatic -o2 -funroll-loops"
$CComp  = "gcc"
$CFlag  = "-DPOSIX_C"

#
#========== Selection of Compile Driver and Option (FORTRAN)===============
#
$conf = "n"
while ($conf -ne "y") {
    "Present Fortran compiler driver name : $Fortran"
    $conf = Read-Host "Is that right? (y/n/q:quit)?"
    if ($conf -eq "q") { exit }
    if ($conf -ne "y") { $Fortran = Read-Host "Enter available Fortran compiler name:" }
}

$conf = "n"
while ($conf -ne "y") {
    "Present Fortran compile option (blank = no option) : $FFlag"
    $conf = Read-Host "Is that right? (y/n/q:quit)?"
    if ($conf -eq "q") { exit }
    if ($conf -ne "y") { 
        $FFlag = Read-Host "Enter available compile option as-is (e.g. -O2 -B):"
    }
}

#
#========== Selection of Compile Driver and Option (C)=====================
#
$conf = "n"
while ($conf -ne "y") {
    "Present C compiler driver name : $CComp"
    $conf = Read-Host "Is that right? (y/n/q:quit)?"
    if ($conf -eq "q") { exit }
    if ($conf -ne "y") { $CComp = Read-Host "Enter available C compiler name:" }
}

$conf = "n"
while ($conf -ne "y") {
    "Present C compile option (blank = no option) : $CFlag"
    $conf = Read-Host "Is that right? (y/n/q:quit)?"
    if ($conf -eq "q") { exit }
    if ($conf -ne "y") { 
        $CFlag = Read-Host "Enter available compile option as-is (e.g. -A -B):"
    }
}

#
#========== System-dependent Source Programs ==============================
#
"Installation of system-dependent source programs started."
cd "$SRAC_Code/src/extnl"
cp "$Syst/*.f"
cp "$Syst/*.c"
"Installation of system-dependent source programs completed."

#
#========== System-dependent Makefile =====================================
#
" Installation of system-dependent Makefile started."
function changeMk($file) { 
    $a = $file -replace "Fortran-Driver", "$Fortran"
    $b = $a -replace "Scalar_Option", ""
    $b -replace '.\(SRAC_CODE\)', "$SRAC_Code"
}
#----------- Kintab --------------------------------------
$Target = "$SRAC_Code/tool/kintab"
$org = Get-Content "$Target/Makefile.org"
changeMk $org | Set-Content "$Target/Makefile"
#----------- TXTtoPDS ------------------------------------
$Target  = "$SRAC_Code/util/pdscnvt/src/txttopds"
$org = Get-Content "$Target/MakeTP.org"
changeMk $org | Set-Content "$Target/MakeTP"
#----------- PDStoTXT ------------------------------------
$Target  = "$SRAC_Code/util/pdscnvt/src/pdstotxt"
$org = Get-Content "$Target/MakePT.org"
changeMk $org | Set-Content "$Target/MakePT"
#----------- PDSMDL(BnupEdit) ----------------------------
$Target  = "$SRAC_Code/util/pdsmdl/main/BnupEdit"
$org = Get-Content "$Target/Makefile.org"
changeMk $org | Set-Content "$Target/Makefile"
#----------- PDSMDL(FluxEdit) ----------------------------
$Target  = "$SRAC_Code/util/pdsmdl/main/FluxEdit"
$org = Get-Content "$Target/Makefile.org"
changeMk $org | Set-Content "$Target/Makefile"
#----------- PDSMDL(FluxPlot) ----------------------------
$Target  = "$SRAC_Code/util/pdsmdl/main/FluxPlot"
$org = Get-Content "$Target/Makefile.org"
changeMk $org | Set-Content "$Target/Makefile"
#----------- PDSMDL(MacroEdit) ---------------------------
$Target  = "$SRAC_Code/util/pdsmdl/main/MacroEdit"
$org = Get-Content "$Target/Makefile.org"
changeMk $org | Set-Content "$Target/Makefile"
#----------- PDSMDL(MicroEdit) ---------------------------
$Target  = "$SRAC_Code/util/pdsmdl/main/MicroEdit"
$org = Get-Content "$Target/Makefile.org"
changeMk $org | Set-Content "$Target/Makefile"
#----------- PDSMDL(AnisnXS)------------------------------
$Target  = "$SRAC_Code/util/pdsmdl/main/AnisnXS"
$org = Get-Content "$Target/Makefile.org"
changeMk $org | Set-Content "$Target/Makefile"
"Installation of system-dependent Makefile completed."

"All process of pre-processor completed."