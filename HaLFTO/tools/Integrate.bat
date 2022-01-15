@Echo Off
setlocal



set SWC=HaLFTO

FOR /D %%G in ("..\..\*_EPS_*") DO set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

 

set BSWMDDIR_HALFTO=%INTPJTDIR%\Tools\AsrProject\Generators\Components\_Schemes\%SWC%\bswmd
set GENDEFDIR_HALFTO=%INTPJTDIR%\Tools\AsrProject\Generators\Artt\%SWC%


mkdir %BSWMDDIR_HALFTO%
mkdir %GENDEFDIR_HALFTO%



copy ..\generate\Ap_HaLFTO_*.arxml	%BSWMDDIR_HALFTO%
copy ..\generate\Ap_HaLFTO_*.tt	%GENDEFDIR_HALFTO%
copy ..\generate\Ap_HaLFTO_*.bat	%GENDEFDIR_HALFTO%


pause
:end

endlocal

