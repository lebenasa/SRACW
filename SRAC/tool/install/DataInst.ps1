<#
    SRAC Installation Conductor for Windows
    Author: Leben Asa (GMU-2014)
    Generate kintab.dat (Bickley function table) for SRAC/ASMBURN
    Load modules must be prepared before this job.
    
    NOTE: Feature may differ from original script by Keisuke Okumura.
          I have no responsibility to any troubles regarding this
          script usage.
#>

if($SRAC_Code -eq $null) {
    "Please run this script from PunchMe.ps1."
    exit
}

#
#=== Bickley Function Table(kintab.dat) ===================================
#
" XXX Production of Bickley function table started."
$env:fu10 = "$SRAC_Code/lib/kintab.dat"
$Outlist = "$SRAC_Code/tmp/kintab.outlist"
#Copy-Item "$SRAC_Code/tool/kintab/kintab.out" "$SRAC_Code/tool/kintab/kintab.exe"
&"$SRAC_Code/tool/kintab/kintab.exe" | Set-Content $Outlist
" XXX Production of Bickley function table completed."
#
#==========================================================================
#
" XXX All processes completed."
" XXX Confirm output messages written in $SRAC_Code/tmp/kintab.outlist."