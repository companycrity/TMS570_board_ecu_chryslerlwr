@echo ########################################
@echo Internal RTE Installation Batch
@echo ########################################
@echo .
@echo ***********************************
@echo Copy Common Dlls
@echo ***********************************

if not exist "%CommonProgramFiles%\Vector"          mkdir "%CommonProgramFiles%\Vector"
if not exist "%CommonProgramFiles%\Vector\DaVinci"  mkdir "%CommonProgramFiles%\Vector\DaVinci"

copy /Y "DaVinciCommon\DVSharedComponentProxy.dll" "%CommonProgramFiles%\Vector\DaVinci"
copy /Y "DaVinciCommon\MultiOsMgr.dll"             "%CommonProgramFiles%\Vector\DaVinci"
copy /Y "DaVinciCommon\DriverConfig.dll"           "%CommonProgramFiles%\Vector\DaVinci"

@echo .
@echo ***********************************
@echo Register Common Dlls
@echo ***********************************
@echo .
"%windir%/system32/regsvr32.exe" /s "%CommonProgramFiles%\Vector\DaVinci\DVSharedComponentProxy.dll"
"%windir%/system32/regsvr32.exe" /s "%CommonProgramFiles%\Vector\DaVinci\MultiOsMgr.dll"
"%windir%/system32/regsvr32.exe" /s "%CommonProgramFiles%\Vector\DaVinci\DriverConfig.dll"



