REM ***************** SET PATHS ************************************************
REM Required PATH Variable settings to tools: SWE-Generator.exe, hexview.exe, hex470.exe

rem Set current path
SET PROJ_PATH=%cd%
SET TOOL_PATH=%PROJ_PATH%\..\..\Tools
SET CCT_PATH=%TOOL_PATH%\CCT

REM **************** DELETE OLD FILES ******************************************

SET FILENAME=%1

del %FILENAME%.hex
del %FILENAME%.hex.map

REM **************** RUN CCT *********************************************** 
"%CCT_PATH%"\CCT %FILENAME%.out -NoSort


REM *************** Clean Up *********************************************

REM **************** END *******************************************************