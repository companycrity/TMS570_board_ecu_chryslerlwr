@Echo Off
setlocal



set SWC=ArbLmt

FOR /D %%G in ("..\..\*_EPS_*") DO set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

 

set BSWMDDIR_ARBLMT=%INTPJTDIR%\Tools\AsrProject\Generators\Components\_Schemes\%SWC%\bswmd
set GENDEFDIR_ARBLMT=%INTPJTDIR%\Tools\AsrProject\Generators\Artt\%SWC%


mkdir %BSWMDDIR_ARBLMT%
mkdir %GENDEFDIR_ARBLMT%



copy ..\generate\Ap_ArbLmt_*.arxml	%BSWMDDIR_ARBLMT%
copy ..\generate\Ap_ArbLmt_*.tt	%GENDEFDIR_ARBLMT%
copy ..\generate\Ap_ArbLmt_*.bat	%GENDEFDIR_ARBLMT%


pause
:end

endlocal

