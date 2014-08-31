hex2bin tusb2136.hex
copy tusb2136.bin c:\windows\system32\drivers\default.bin
copy tusb2136.bin c:\keil\c51\binaries\tusb3210.bin
cd c:\keil\c51\binaries\
GOBIN 3210FwOnly
