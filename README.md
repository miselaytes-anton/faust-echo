# Faust echo

Simple echo effect using [Faust](https://faust.grame.fr/) on [ESP32 board](https://www.seeedstudio.com/Ai-Thinker-A1S-Wi-Fi-BT-Audio-Development-Kit-p-3160.html).

## Set up

Follow [this tutorial](https://faustdoc.grame.fr/tutorials/esp32/).

## Build

1. First lets convert `FaustEcho.dsp` to `FaustEcho.cpp`

```
./faust.sh
```

2. Now we need a manual step. In `FaustEcho.cpp` we need to move`fRec8` from `mydsp` class to the global scope, make it static and add EXT_RAM_ATTR to it, so that it becomes:

```cpp
static float fRec8[262144] EXT_RAM_ATTR;

class mydsp : public dsp {
   // ...
}
```

3. Flash the micro controller:

```
./flash
```

## Links

- https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html
- https://github.com/espressif/arduino-esp32/issues/595#issuecomment-423796631

## Todo

- possibly add a pot or use buttons to control volume
