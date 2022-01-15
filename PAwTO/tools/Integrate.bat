@Echo Off
setlocal



set SWC=PAwTO

FOR /D %%G in ("..\..\*_EPS_*") DO set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

 

set BSWMDDIR_PAWTO=%INTPJTDIR%\Tools\AsrProject\Generators\Components\_Schemes\%SWC%\bswmd
set GENDEFDIR_PAWTO=%INTPJTDIR%\Tools\AsrProject\Generators\Artt\%SWC%


mkdir %BSWMDDIR_PAWTO%
mkdir %GENDEFDIR_PAWTO%



copy ..\generate\Ap_PAwTO_*.arxml	%BSWMDDIR_PAWTO%
copy ..\generate\Ap_PAwTO_*.tt	%GENDEFDIR_PAWTO%
copy ..\generate\Ap_PAwTO_*.bat	%GENDEFDIR_PAWTO%


pause
:end

endlocal

