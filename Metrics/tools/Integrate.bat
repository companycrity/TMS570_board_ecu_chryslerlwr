setlocal

set BSWMDDIR=BMW_UKL_MCV_EPS_TMS570\Tools\AsrProject\Generators\Components\_Schemes\Metrics\bswmd
set GENDEFDIR=BMW_UKL_MCV_EPS_TMS570\Tools\AsrProject\Generators\Artt\Metrics

mkdir ..\..\%BSWMDDIR%
mkdir ..\..\%GENDEFDIR%

copy ..\generate\*.arxml	..\..\%BSWMDDIR%
copy ..\generate\*.tt	..\..\%GENDEFDIR%
copy ..\generate\*.bat	..\..\%GENDEFDIR%

:end

endlocal

