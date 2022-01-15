@setlocal enableextensions enabledelayedexpansion
@ECHO off
REM #-------------------------------------------------------------------------------------------------------------------
REM |      File: generate.bat
REM |   Project: Common Manufacturing Services Generator
REM |   Created: 2013-01-29
REM |  Modified: 2013-03-27
REM |    Author: Jared Julien
REM |     Email: jared.julien@nexteer.com
REM | Copyright: (c) 2013 Neexter Automotive
REM |
REM |  This batch file will get the path to the common component from the cmsgen.ini file (in the same directory as
REM |  this file) and kick off the generator.
REM | Date        Rev   Author    Change Description
REM | ==========  ====  ========  =====================================================================================
REM | 2013-01-29  1     JWJ       Initial file creation
REM | 2013-03-27  2     JWJ       Updated to perform path lookup from config file instead of hard code
REM #-------------------------------------------------------------------------------------------------------------------

REM -----[ Configuration Options ]--------------------------------------------------------------------------------------
SET config=cmsgen.ini
SET section=[DEFAULT]
SET key=commonPath

REM -----[ Common Component Path Lookup ]-------------------------------------------------------------------------------
SET currarea=
SET commonPath=
FOR /f "usebackq delims=" %%a IN ("!config!") DO (
    SET ln=%%a
    IF "x!ln:~0,1!"=="x[" (
        SET currarea=!ln!
    ) ELSE (
        FOR /f "tokens=1,2 delims==: " %%b IN ("!ln!") DO (
            SET currkey=%%b
            SET currval=%%c
            IF "x!section!"=="x!currarea!" IF "x!key!"=="x!currkey!" (
                SET commonPath=!currval!
            )
        )
    )
)

REM -----[ Generator Call ]---------------------------------------------------------------------------------------------
IF NOT [!commonPath!] == [] (
    %commonPath:/=\%\tools\CMSGen\cmsgen.exe %config%
) ELSE (
    ECHO Path not found in %config%
    SET ERRORLEVEL=1
)

REM -----[ Pause on Error ]---------------------------------------------------------------------------------------------
IF ERRORLEVEL 1 PAUSE

endlocal