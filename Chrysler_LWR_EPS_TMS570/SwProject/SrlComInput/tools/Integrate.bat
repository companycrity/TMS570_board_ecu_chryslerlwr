@Echo Off
setlocal



set SWC=SrlComInput

FOR /D %%G in ("..\..\..\..\*_EPS_*") DO set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

 

set BSWMDDIR_SRLCOMINPUT=%INTPJTDIR%\Tools\AsrProject\Generators\Components\_Schemes\%SWC%\bswmd
set GENDEFDIR_SRLCOMINPUT=%INTPJTDIR%\Tools\AsrProject\Generators\Artt\%SWC%


mkdir %BSWMDDIR_SRLCOMINPUT%
mkdir %GENDEFDIR_SRLCOMINPUT%



copy ..\generate\Ap_SrlComInput_*.arxml	%BSWMDDIR_SRLCOMINPUT%
copy ..\generate\Ap_SrlComInput_*.tt	%GENDEFDIR_SRLCOMINPUT%
copy ..\generate\Ap_SrlComInput_*.bat	%GENDEFDIR_SRLCOMINPUT%


pause
:end

endlocal

