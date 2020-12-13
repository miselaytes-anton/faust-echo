set -e

idf.py build
idf.py -p /dev/cu.usbserial-0001 flash
idf.py monitor