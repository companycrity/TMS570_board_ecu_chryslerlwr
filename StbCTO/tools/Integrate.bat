@Echo Off
setlocal



set SWC=StbCTO

FOR /D %%G in ("..\..\*_EPS_*") DO set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

 

set BSWMDDIR_STBCTO=%INTPJTDIR%\Tools\AsrProject\Generators\Components\_Schemes\%SWC%\bswmd
set GENDEFDIR_STBCTO=%INTPJTDIR%\Tools\AsrProject\Generators\Artt\%SWC%


mkdir %BSWMDDIR_STBCTO%
mkdir %GENDEFDIR_STBCTO%



copy ..\generate\Ap_StbCTO_*.arxml	%BSWMDDIR_STBCTO%
copy ..\generate\Ap_StbCTO_*.tt	%GENDEFDIR_STBCTO%
copy ..\generate\Ap_StbCTO_*.bat	%GENDEFDIR_STBCTO%


pause
:end

endlocal

