@echo off

if not exist Binaries mkdir Binaries

set SRC=%cd%

pushd Binaries

cl %SRC%\Main.cpp -Zi -Fe:RunTests.exe -I %SRC%\Lib

popd