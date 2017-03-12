rem @echo off
SET program="%1"
if %program% == "" goto err

echo 1
%program% output1.txt 6
if ERRORLEVEL 1 goto testFailed

echo 2
%program% output2.txt 0
if ERRORLEVEL 1 goto testFailed

echo 3
%program% output3.txt 255
if ERRORLEVEL 1 goto testFailed

echo 4
%program% output4.txt 124
if ERRORLEVEL 1 goto testFailed

echo 5
%program% output5.txt 1111
if ERRORLEVEL 1 goto testFailed

echo 6
%program% output5.txt
if ERRORLEVEL 1 goto testFailed

echo OK
exit /B

:err
echo Usage: test.bat <Path to program>