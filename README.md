# sonoTron
Teensy 3.6 based Vocoder with MIDI Control
### This project implement a Teensy 3.6 based 12 band Vocoder with MIDI control.
The Vocoder has the following characteristics:
* 12 bands
* MIDI adjustable bottom and top frequencies for the modulator and the carrier path
* line in for the modulator and the carrier path
* pink and white noise for the modulator and the carrier path
* MIDI adjustable envelope speed and envelope limiter
* MIDI adjustable filter resonance
* one MIDI input for a MIDI controller like https://github.com/ErikDorstel/midiKnobs

The project uses the Teensy Audio Library to implement the audio components like filter, peak measurement ... . This graphic shows the connections of the components used.
![image note found](https://raw.githubusercontent.com/ErikDorstel/sonoTron/master/documentation/ADT%20schematic.png)

The hardware used is very similar to https://github.com/ErikDorstel/octoTron . The only difference is the additional use of two line in ports.

The sonoTron Vocoder use a MIDI In port to control all vocoder parameters. The assigned MIDI controller numbers are part of the documentation.
