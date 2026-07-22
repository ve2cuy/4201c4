rem echo off
..\JWasm.exe -bin %1.asm -Fo %1.bin
copy %1.BIN %1.com
echo Compilation terminee: %1