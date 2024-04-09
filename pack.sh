#!/bin/bash
if [ ! -f "build/as5600_example.uf2" ]; then
    echo "Compiled binnary cannot be found, not continuing!"
    exit 1
fi

todays_date=$(date +'%d%m%Y')

readme="This archive contains prebuilt example.
You can connect pi pico in flash mode and copy as5600_example.uf2 file into pi pico's memory.

Connect as5600 SDA pin 4 and scl to pin 5 (default I2C pins) on pi pico.

You'll need serial monitor to display messages from pi pico.
For messages to display properly your serial monitor should respect carriage returns.
"

echo "$readme" >> readme.txt

zip -j "build/dwm_pico_as5600_${todays_date}_v" LICENSE COPYING readme.txt build/as5600_example.uf2

rm -f readme.txt