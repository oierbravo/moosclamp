Arduino OSC Moodlamp
========================
Installation
------------

- Install required libraries.
  - [Oscuino](https://github.com/tambien/oscuino)
  - [Moodlamp](https://github.com/oierbravo/arduino-moodlamp-library)
- Modify sketch for your network ( ip, mac and inPort).
- Upload the sketch

- IMPORTANT!!Ethernet Shield required. Only tested with official one.

Demo video
---------
Comming.

OSC
--------
	/moosclamp/rgb [int] [int] [int]
Sets value for the 3 colors.

	/moosclamp/red [int]
Sets red value. Doesn't affect other colors.

	/moosclamp/green [int]

Sets red value. Doesn't affect other colors.

	/moosclamp/blue [int]
Sets red value. Doesn't affect other colors.

	/moosclamp/color/red
	/moosclamp/color/green
	/moosclamp/color/blue
	/moosclamp/color/white
	/moosclamp/color/black
	/moosclamp/color/orange
	/moosclamp/color/yellow
	/moosclamp/color/purple
	/moosclamp/color/cyan
Sets a predefined color.

	/moosclamp/mode/manual
Sets manual mode.

	/moosclamp/mode/cycle
Sets cycle mode.

	/moosclamp/mode/cycle
Sets cycle mode.

	/moosclamp/speed [int]
Sets time between each step.

	/moosclamp/off
Sets all color values to zero.


LICENSE
------
LGPL. See LICENSE.txt

Autor
-----
[Oier Bravo Urtasun](https://github.com/oierbravo)
