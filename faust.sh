set -e

faust2esp32 -AC101 -lib FaustSawtooth.dsp
unzip -o -j FaustSawtooth.zip -d faust
cp faust/FaustSawtooth.cpp main
cp faust/FaustSawtooth.h main
rm -rf faust
rm -rf FaustSawtooth.zip
