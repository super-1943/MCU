@echo off

rem
rem  DrvBuild.bat used to build the driver from a .BAT script 
rem             You can also run this from the IDE which is very
rem			    handy.
rem   
rem
rem  Syntax:  DrvBuild [args1] [args2]
rem			  where
rem				args1 - target of build, ether:
rem						win2kcheck, win2kfree
rem					    xpcheck, xpfree
rem				
rem			    args2 - additional flags
rem
rem		For example:
rem			DrvBuild  xpfree  
rem		    DrvBuild  win2kchk c  Use 'c' for full rebuild.
rem
rem
rem  NOTE: You'll need the following environment vars set
rem
rem		    DDK_WIN2K = path to root of Windows 2K DDK
rem			DDK_XP    = path to root of NET DDK
rem
rem

rem ============ check args ======
if	"%1" == "-" goto help 
if  "%1" == ""  goto help

@echo.
@echo ===== Building driver  ========


:createdir
rem Create directories if necessary
rem if NOT EXIST sys\wdm\chk\i386  mkdir sys\wdm\chk\i386
rem if NOT EXIST sys\wdm\fre\i386  mkdir sys\wdm\fre\i386


if "%1"=="win2kcheck" goto win2kcheck
if "%1"=="win2kfree"  goto win2kfree
if "%1"=="xpcheck" goto xpcheck
if "%1"=="xpfree"  goto xpfree



@echo ****** Command Error ****
goto help



:win2kcheck
rem @echo on
if "%DDK_WIN2K%" == "" goto NoEnvironment
echo ==== DDK directory is: %DDK_WIN2K%
if EXIST %DDK_WIN2K%\bin\setenv.bat set DDKBATSET=%DDK_WIN2K%\bin\setenv
rem if this subdir exists then use this instead
if EXIST %DDK_WIN2K%\bin\w2k\set2k.bat 	set DDKBATSET=%DDK_WIN2K%\bin\w2k\set2k
call %DDKBATSET% %DDK_WIN2K% checked
goto envcheck

:win2kfree
if "%DDK_XP%" == "" goto NoEnvironment
if EXIST %DDK_WIN2K%\bin\setenv.bat set DDKBATSET=%DDK_WIN2K%\bin\setenv
rem if this subdir exists then use this instead
if EXIST %DDK_WIN2K%\bin\w2k\set2k.bat 	set DDKBATSET=%DDK_WIN2K%\bin\w2k\set2k
call %DDKBATSET% %DDK_WIN2K% free
goto envcheck

:xpfree
goto envcheck


:xpcheck
goto envcheck




:envcheck
if "%DDKBUILDENV%" == "checked" @echo ======= DEBUG BUILD =======
if "%DDKBUILDENV%" == "free"	@echo ======= FREE BUILD =======
if "%DDKBUILDENV%" == "chk"		@echo ======= DEBUG BUILD =======
if "%DDKBUILDENV%" == "fre"		@echo ======= FREE BUILD =======

if "%DDKBUILDENV%" == "" goto NoEnvironment
if "%USB_ROOT%" == ""    goto NoUSBRoot




cd /D %USB_ROOT%

@echo.
@echo Using %USB_ROOT% as project root
@echo.

@echo =========================================



rem ==============
rem  If Win2K, NET then call build
rem  without full path
rem
call build -Zew%2


:browsebuild

@echo
@echo ====================================
@echo Building browse information files

@echo off

bscmake /o UsbCryptDriver.bsc *.sbr 

@echo ddkbuild complete

goto End



:help
rem    Display error message and correct syntax
rem
@echo.  	
@echo.  	
@echo     drvbuild [target] [c]
@echo.  	
@echo		where c is: Clean all objs
@echo.       
@echo		target is:
@echo.   
@echo		win2kcheck, win2kfree
@echo.      xpfree xpcheck
@echo.


goto End

:NoUSBRoot

@echo !!! No USB_ROOT environment variable not set!!!!


goto End

:NoEnvironment
@echo.
@echo !!!!!!!! ERROR NO DDK ENVIRONMENT SET !!!!
@echo.
@echo The following environment vars need to be set
@echo.
@echo    DDK_WIN2K = Path to Windows 2000 DDK
@echo    DDK_XP    = Path to XPDDK
@echo.
@echo    USB_ROOT = Path to root of driver source code
@echo.
@echo.


:End




