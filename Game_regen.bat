@ECHO OFF

:SETUP

SET SOLUTIONROOT=%~dp0
CD %SOLUTIONROOT%

SET FBUILDROOT=%CD%\Bin
SET FBUILDCMD=%FBUILDROOT%\FBuild.exe
SET SOLUTIONPATHFILE=Build\_solution_path.bff

IF EXIST "%FBUILDCMD%" GOTO CHECKFILE

ECHO FBuild was not found in "%FBUILDROOT%"! Stopping execution.
ECHO It can be downloaded on http://fastbuild.org/docs/download.html.
SET ERRORLEVEL=127
GOTO END

:CHECKFILE
IF EXIST "%SOLUTIONPATHFILE%" GOTO RUN

:CREATEFILE
ECHO Creating "%SOLUTIONPATHFILE%" ...
ECHO .SolutionPath           = '%CD%'> Build\_solution_path.bff
ECHO Done.

:RUN
CALL %FBUILDCMD% -cachewrite -cacheread -nooutputbuffering -config Game.bff %*
GOTO END

:END
IF %ERRORLEVEL% NEQ 0 EXIT /b %ERRORLEVEL%
PAUSE

@ECHO ON