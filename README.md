# sonoTron
Teensy 3.6 based Vocoder with MIDI Control
### This project implement a Teensy 3.6 based 16 band Vocoder with MIDI control.
The Vocoder has the following characteristics:
* 16 bands with logarithmic distribution
* cascaded filters with 24dB/octave
* MIDI controlled bottom and top frequencies for the modulator and the carrier path
* line in for the modulator and the carrier path
* pink and white noise for the modulator and the carrier path
* four VCO with one LFO for the modulator and the carrier path
* MIDI controlled envelope speed, envelope limiter, filter resonance, vco and lfo
* one MIDI input for a MIDI controller like https://github.com/ErikDorstel/midiKnobs

The project uses the Teensy Audio Library to implement the audio components like filter, peak measurement ... . This graphic shows the connections of the components used.
![image note found](https://raw.githubusercontent.com/ErikDorstel/sonoTron/master/documentation/ADT%20schematic.png)

The hardware used is very similar to https://github.com/ErikDorstel/octoTron . The only difference is the additional use of two line in ports.

The sonoTron Vocoder use a MIDI In port to control all vocoder parameters. The assigned MIDI controller numbers and the schematic are part of the documentation.

The CPU usage of a Teensy 3.6 is up to 80 percent.
