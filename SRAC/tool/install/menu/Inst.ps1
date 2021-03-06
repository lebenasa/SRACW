<#
    SRAC Installation Conductor for Windows
    Author: Leben Asa (GMU-2014)
    Menu command for installation.
    
    NOTE: Feature may differ from original script by Keisuke Okumura.
          I have no responsibility to any trouble regarding this
          script usage.
#>

if($SRAC_Code -eq $null) {
    "Please run this script from PunchMe.ps1."
    exit
}

"============================================================="
"1) Utility programs, 2) Bickley function table, 3) SRAC load
module can be installed here. Before these installation, the
pre-processor must be executed. The utility programs must be
installed before the Bickley function table.
If SRAC load module can not be installed well, go to the
custom-installation menu.
"

$menu = " "
while($menu -ne "q") {
"
  +++++++++++++++++++< Installation Menu >++++++++++++++++++++++++
  +                                                              +
  +  1 : Installation of utility programs                        +
  +  2 : Installation of Bickley function table (binary)         +
  +  3 : Installation of SRAC load module                        +
  +                                                              +
  +  h : Help                                                    +
  +  q : bye-bye                                                 +
  +                                                              +
  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
"
[string]$number = Read-Host "Set number==>"
switch($number) {
    '1' { 
        $conf = Read-Host "Sure (y/n)? ==> "
        if ($conf -eq "y") { 
            ""
            "Please wait. . ."
            $Output = "$SRAC_Code/tmp/UtilInst.outlist"
            &"$SRAC_Code/tool/install/UtilInst.ps1" >> $Output
            "Results were written in $Output"
            ""
        }
     }
    '2' { 
        $conf = Read-Host "Do you install right now (not batch job)? (y/n)? ==> "
        if ($conf -eq "y") { 
            $conf2 = Read-Host "Bickley function table instalation will start. Ready (y/n)? ==> "
            if ($conf2 -eq "y") {
                $Output = "$SRAC_Code/tmp/DataInst.outlist"
                &"$SRAC_Code/tool/install/DataInst.ps1" >> $Output
                ""
                "Please wait. . . (background job)"
                "Results will be written in $Output"
                ""
            }
            elseif ($conf2 -eq "n") {
                "
                Edit the following shellscript as you like, and submit it.
                Shellscript: $SRAC_Code/tool/install/DataInst.ps1
                "
            }
        }
     }
    '3' { 
        $conf = Read-Host "Do you install right now (not batch job)? (y/n)? ==> "
        if ($conf -eq "y") { 
            $conf2 = Read-Host "Load module instalation will start. Ready (y/n)? ==> "
            if ($conf2 -eq "y") {
                $Output = "$SRAC_Code/tmp/lmmk.outlist"
                &"$SRAC_Code/tool/install/lmmk.ps1" >> $Output
                ""
                "Please wait. . . (background job)"
                "Results will be written in $Output"
                ""
            }
            elseif ($conf2 -eq "n") {
                "
                Edit the following shellscript as you like, and submit it.
                Shellscript: $SRAC_Code/tool/install/lmmk.ps1
                "
            }
        }
     }
    'h' { "$SRAC_Code/tool/install/help/help3.txt"; Read-Host "Return>" }
    'q' { "Bye"; $menu="q" }
    default { "$number is invalid number. " }
    }
}