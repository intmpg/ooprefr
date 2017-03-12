rem @echo off
SET program="%1"
if %program% == "" goto err

echo 1
%program% input.txt output.txt
if ERRORLEVEL 1 goto testFailed

echo 2
%program% input2.txt output2.txt
if ERRORLEVEL 1 goto testFailed

echo 3
%program% input3.txt output3.txt
if ERRORLEVEL 1 goto testFailed

echo 4
%program% input4.txt output4.txt
if ERRORLEVEL 1 goto testFailed

echo 5
%program% input5.txt output5.txt
if ERRORLEVEL 1 goto testFailed

echo 6
%program% input6.txt output6.txt
if ERRORLEVEL 1 goto testFailed

echo 7
%program% input6.txt
if ERRORLEVEL 1 goto testFailed

echo 8
%program% input7.txt
if ERRORLEVEL 1 goto testFailed


echo OK
exit /B

:testFailed
echo Testing failed
exit /B

:err
echo Usage: launch.bat <Path to program>