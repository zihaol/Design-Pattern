@echo on
@Rem debugĿ¼��releaseĿ¼��ָ���������ļ�

@PROMPT [Com] 
:PROMPT $t$d$g

:@for /f %%a in ('date /t') do @set date=%%a
:@date /t
:@time /t

@echo          -----------------
@echo   ������ %date% ������
@echo          -----------------
@echo.&echo off


@Rem ɾ��debugĿ¼��releaseĿ¼
@for /r . %%a in (.) do @if exist "%%a\debug" rd /s /q "%%a\debug"
@for /r . %%a in (.) do @if exist "%%a\release" rd /s /q "%%a\release"
@for /r . %%a in (.) do @if exist "%%a\Admin_release" rd /s /q "%%a\Admin_release"
@for /r . %%a in (.) do @if exist "%%a\ipch" rd /s /q "%%a\ipch"
@echo ��- ɾ��debugĿ¼��releaseĿ¼��ϡ�
@echo.&echo off


@Rem ɾ��ָ�������ļ�
@del /f /s /q .\*.obj >nul 2>nul
@del /f /s /q .\*.pch >nul 2>nul
@del /f /s /q .\*.idb >nul 2>nul
@del /f /s /q .\*.pdb >nul 2>nul
@del /f /s /q .\*.ncb >nul 2>nul
@del /f /s /q .\*.opt >nul 2>nul
@del /f /s /q .\*.suo >nul 2>nul
@del /f /s /q .\*.sbr >nul 2>nul
@del /f /s /q .\*.ilk >nul 2>nul
@del /f /s /q .\*.aps >nul 2>nul
@del /f /s /q .\*.db  >nul 2>nul
@del /f /s /q .\*.sdf  >nul 2>nul
@del /f /s /q .\*.user  >nul 2>nul
@echo ��- ɾ��ָ�������ļ���ϡ�

@echo.&pause
