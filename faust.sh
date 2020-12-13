set -e

faust2esp32 -AC101 -lib FaustSawtooth.dsp
unzip -o -j FaustSawtooth.zip -d ./main
rm -rf FaustSawtooth.zip
