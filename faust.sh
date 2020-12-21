set -e

faust2esp32 -AC101 -lib FaustEcho.dsp
unzip -o -j FaustEcho.zip -d faust-echo
cp faust-echo/FaustEcho.cpp main
cp faust-echo/FaustEcho.h main
rm -rf faust-echo
rm -rf FaustEcho.zip
