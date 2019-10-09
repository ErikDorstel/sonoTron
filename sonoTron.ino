#include <Audio.h>
#include <Metro.h>
#include "ADT.h"

const bool logging=true;

Metro timer = Metro(1000);
float modulatorLevel[17], carrierGain[17];
float envelopeSpeed=0.995, envelopeLimit=0.1;
float modulatorButtom=50, modulatorTop=5000, carrierButtom=50, carrierTop=5000;

void setup() {
  Serial.begin(9600);
  Serial3.begin(31250,SERIAL_8N1);
  AudioMemory(50);
  sgtl5000_1.enable(); sgtl5000_1.volume(0.8); sgtl5000_1.unmuteLineout(); sgtl5000_1.lineOutLevel(29);
  sgtl5000_1.inputSelect(AUDIO_INPUT_LINEIN); sgtl5000_1.lineInLevel(5);
  noise.amplitude(1); pink.amplitude(1);
  for (byte c=1;c<=16;c++) { carrierGain[c]=1; }
  setModulatorSource(1,0,0,0);
  setCarrierSource(1,0,0,0);
  setModulatorFrequency(50,5000);
  setCarrierFrequency(50,5000);
  setFilterResonance(5);
  setOutputAmplifier(2);
  setMixerVCO(0.25,0.25,0.25,0.25);
  setLFO1(1,100,WAVEFORM_SINE);
  setLFO2(1,100,WAVEFORM_SINE);
  setVCO1(1,300,WAVEFORM_SAWTOOTH,1);
  setVCO2(1,300,WAVEFORM_SAWTOOTH,1);
  setVCO3(1,300,WAVEFORM_SAWTOOTH,1);
  setVCO4(1,300,WAVEFORM_SAWTOOTH,1);
  delay(1000); }

void loop() {
  byte MIDIinA; static byte MIDIstatusA=0, MIDIchannelA=0, MIDIpara1A=0, MIDIpara2A=0;
  if (Serial3.available() > 0) { MIDIinA = Serial3.read();
    if ((MIDIinA & 128) == 128) { MIDIstatusA=MIDIinA & 240; MIDIchannelA=MIDIinA & 15; MIDIpara1A=255; MIDIpara2A=255; } else {
    if (MIDIpara1A==255) { MIDIpara1A=MIDIinA; } else if (MIDIpara2A==255) { MIDIpara2A=MIDIinA;
      if (MIDIstatusA==0xB0) { MIDIsetControl(MIDIchannelA,MIDIpara1A,MIDIpara2A); }
      MIDIpara1A=255; MIDIpara2A=255; } } }
      
  for (byte c=1;c<=16;c++) { if (peak[c].available()) { modulatorLevel[c]=peak[c].read()*envelopeLimit; } }
  if (modulatorLevel[1] > carrierGain[1]) { carrierGain[1] /= envelopeSpeed; mixer1.gain(0, carrierGain[1]); } else
  if (modulatorLevel[1] < carrierGain[1]) { carrierGain[1] *= envelopeSpeed; mixer1.gain(0, carrierGain[1]); }
  if (modulatorLevel[2] > carrierGain[2]) { carrierGain[2] /= envelopeSpeed; mixer1.gain(1, carrierGain[2]); } else
  if (modulatorLevel[2] < carrierGain[2]) { carrierGain[2] *= envelopeSpeed; mixer1.gain(1, carrierGain[2]); }
  if (modulatorLevel[3] > carrierGain[3]) { carrierGain[3] /= envelopeSpeed; mixer1.gain(2, carrierGain[3]); } else
  if (modulatorLevel[3] < carrierGain[3]) { carrierGain[3] *= envelopeSpeed; mixer1.gain(2, carrierGain[3]); }
  if (modulatorLevel[4] > carrierGain[4]) { carrierGain[4] /= envelopeSpeed; mixer1.gain(3, carrierGain[4]); } else
  if (modulatorLevel[4] < carrierGain[4]) { carrierGain[4] *= envelopeSpeed; mixer1.gain(3, carrierGain[4]); }
  if (modulatorLevel[5] > carrierGain[5]) { carrierGain[5] /= envelopeSpeed; mixer2.gain(0, carrierGain[5]); } else
  if (modulatorLevel[5] < carrierGain[5]) { carrierGain[5] *= envelopeSpeed; mixer2.gain(0, carrierGain[5]); }
  if (modulatorLevel[6] > carrierGain[6]) { carrierGain[6] /= envelopeSpeed; mixer2.gain(1, carrierGain[6]); } else
  if (modulatorLevel[6] < carrierGain[6]) { carrierGain[6] *= envelopeSpeed; mixer2.gain(1, carrierGain[6]); }
  if (modulatorLevel[7] > carrierGain[7]) { carrierGain[7] /= envelopeSpeed; mixer2.gain(2, carrierGain[7]); } else
  if (modulatorLevel[7] < carrierGain[7]) { carrierGain[7] *= envelopeSpeed; mixer2.gain(2, carrierGain[7]); }
  if (modulatorLevel[8] > carrierGain[8]) { carrierGain[8] /= envelopeSpeed; mixer2.gain(3, carrierGain[8]); } else
  if (modulatorLevel[8] < carrierGain[8]) { carrierGain[8] *= envelopeSpeed; mixer2.gain(3, carrierGain[8]); }
  if (modulatorLevel[9] > carrierGain[9]) { carrierGain[9] /= envelopeSpeed; mixer3.gain(0, carrierGain[9]); } else
  if (modulatorLevel[9] < carrierGain[9]) { carrierGain[9] *= envelopeSpeed; mixer3.gain(0, carrierGain[9]); }
  if (modulatorLevel[10] > carrierGain[10]) { carrierGain[10] /= envelopeSpeed; mixer3.gain(1, carrierGain[10]); } else
  if (modulatorLevel[10] < carrierGain[10]) { carrierGain[10] *= envelopeSpeed; mixer3.gain(1, carrierGain[10]); }
  if (modulatorLevel[11] > carrierGain[11]) { carrierGain[11] /= envelopeSpeed; mixer3.gain(2, carrierGain[11]); } else
  if (modulatorLevel[11] < carrierGain[11]) { carrierGain[11] *= envelopeSpeed; mixer3.gain(2, carrierGain[11]); }
  if (modulatorLevel[12] > carrierGain[12]) { carrierGain[12] /= envelopeSpeed; mixer3.gain(3, carrierGain[12]); } else
  if (modulatorLevel[12] < carrierGain[12]) { carrierGain[12] *= envelopeSpeed; mixer3.gain(3, carrierGain[12]); }
  if (modulatorLevel[13] > carrierGain[13]) { carrierGain[13] /= envelopeSpeed; mixer4.gain(0, carrierGain[13]); } else
  if (modulatorLevel[13] < carrierGain[13]) { carrierGain[13] *= envelopeSpeed; mixer4.gain(0, carrierGain[13]); }
  if (modulatorLevel[14] > carrierGain[14]) { carrierGain[14] /= envelopeSpeed; mixer4.gain(1, carrierGain[14]); } else
  if (modulatorLevel[14] < carrierGain[14]) { carrierGain[14] *= envelopeSpeed; mixer4.gain(1, carrierGain[14]); }
  if (modulatorLevel[15] > carrierGain[15]) { carrierGain[15] /= envelopeSpeed; mixer4.gain(2, carrierGain[15]); } else
  if (modulatorLevel[15] < carrierGain[15]) { carrierGain[15] *= envelopeSpeed; mixer4.gain(2, carrierGain[15]); }
  if (modulatorLevel[16] > carrierGain[16]) { carrierGain[16] /= envelopeSpeed; mixer4.gain(3, carrierGain[16]); } else
  if (modulatorLevel[16] < carrierGain[16]) { carrierGain[16] *= envelopeSpeed; mixer4.gain(3, carrierGain[16]); }
  if ((timer.check() == 1) and logging) {
    Serial.print("Modulator: "); Serial.print(peak1.read());
    Serial.print(" Carrier: "); Serial.print(peak2.read());
    Serial.print(" Output: "); Serial.print(peak3.read()); Serial.println(""); logUtil(); } }

void MIDIsetControl(byte channel, byte control, byte value) {
  float fvalue=float(value)/127, lvalue=pow(fvalue,3);
  switch (control) {
    case 0: modulatorButtom=(lvalue*4950)+50; setModulatorFrequency(modulatorButtom,modulatorTop); break;
    case 1: modulatorTop=(lvalue*4950)+50; setModulatorFrequency(modulatorButtom,modulatorTop); break;
    case 2: carrierButtom=(lvalue*4950)+50; setCarrierFrequency(carrierButtom,carrierTop); break;
    case 3: carrierTop=(lvalue*4950)+50; setCarrierFrequency(carrierButtom,carrierTop); break;
    case 4: envelopeSpeed=((fvalue/2)+0.495); break;
    case 5: envelopeLimit=fvalue; break;
    case 6: setFilterResonance((fvalue*4.3)+0.7); break;
    case 7: setOutputAmplifier(lvalue*10); break;
    case 8: lfo1.begin(getWaveform(value)); break;
    case 9: lfo2.begin(getWaveform(value)); break;
    case 10: vco1.begin(getWaveform(value)); break;
    case 11: vco2.begin(getWaveform(value)); break;
    case 12: vco3.begin(getWaveform(value)); break;
    case 13: vco4.begin(getWaveform(value)); break;
    case 14: switch (value&96) {
      case 0: setModulatorSource(1,0,0,0); break;
      case 32: setModulatorSource(0,1,0,0); break;
      case 64: setModulatorSource(0,0,1,0); break;
      case 96: setModulatorSource(0,0,0,1); break; } break;
    case 15: switch (value&96) {
      case 0: setCarrierSource(1,0,0,0); break;
      case 32: setCarrierSource(0,1,0,0); break;
      case 64: setCarrierSource(0,0,1,0); break;
      case 96: setCarrierSource(0,0,0,1); break; } break;
    case 16: lfo1.amplitude(fvalue); break;
    case 17: lfo2.amplitude(fvalue); break;
    case 18: vco1.amplitude(fvalue); break;
    case 19: vco2.amplitude(fvalue); break;
    case 20: vco3.amplitude(fvalue); break;
    case 21: vco4.amplitude(fvalue); break;
    case 22: vco1.frequencyModulation((fvalue*11)+1); vco2.frequencyModulation((fvalue*11)+1); break;
    case 23: vco3.frequencyModulation((fvalue*11)+1); vco4.frequencyModulation((fvalue*11)+1); break;
    case 24: lfo1.frequency(lvalue*1000); break;
    case 25: lfo2.frequency(lvalue*1000); break;
    case 26: vco1.frequency(lvalue*5000); break;
    case 27: vco2.frequency(lvalue*5000); break;
    case 28: vco3.frequency(lvalue*5000); break;
    case 29: vco4.frequency(lvalue*5000); break; } }

void setFilterResonance(float r) { for (byte c=1;c<=16;c++) { filter11[c].resonance(r); filter12[c].resonance(r); filter21[c].resonance(r); filter22[c].resonance(r); } }

void setOutputAmplifier(float g) { mixer14.gain(0,g); mixer14.gain(1,g); mixer14.gain(2,g); mixer14.gain(3,g); }

void setModulatorFrequency(float b,float t) { for (byte c=1;c<=16;c++) { float freq=b*pow(t/b,(c-1)/15.0); filter11[c].frequency(freq); filter12[c].frequency(freq); } }

void setCarrierFrequency(float b,float t) { for (byte c=1;c<=16;c++) { float freq=b*pow(t/b,(c-1)/15.0); filter21[c].frequency(freq); filter22[c].frequency(freq); } }

void setModulatorSource(float a, float b, float c, float d) { mixermodulator.gain(0,a); mixermodulator.gain(1,b); mixermodulator.gain(2,c); mixermodulator.gain(3,d); }

void setCarrierSource(float a, float b, float c, float d) { mixercarrier.gain(0,a); mixercarrier.gain(1,b); mixercarrier.gain(2,c); mixercarrier.gain(3,d); }

void setMixerVCO(float a, float b, float c, float d) { mixervco.gain(0,a); mixervco.gain(1,b); mixervco.gain(2,c); mixervco.gain(3,d); }

byte getWaveform(byte value) { switch (value&96) {
  case 0: return(WAVEFORM_SINE);
  case 32: return(WAVEFORM_SAWTOOTH);
  case 64: return(WAVEFORM_SQUARE);
  case 96: return(WAVEFORM_TRIANGLE); } return(0); }

void setVCO1(float a, float f, byte w, byte o) { vco1.begin(a,f,w); vco1.frequencyModulation(o); }
void setVCO2(float a, float f, byte w, byte o) { vco2.begin(a,f,w); vco2.frequencyModulation(o); }
void setVCO3(float a, float f, byte w, byte o) { vco3.begin(a,f,w); vco3.frequencyModulation(o); }
void setVCO4(float a, float f, byte w, byte o) { vco4.begin(a,f,w); vco4.frequencyModulation(o); }
void setLFO1(float a, float f, byte w) { lfo1.begin(a,f,w); }
void setLFO2(float a, float f, byte w) { lfo2.begin(a,f,w); }

void logUtil() {
  Serial.print("Memory: "); Serial.print(AudioMemoryUsage()); Serial.print("/"); Serial.print(AudioMemoryUsageMax());
  Serial.print(" CPU: "); Serial.print(AudioProcessorUsage()); Serial.print("/"); Serial.println(AudioProcessorUsageMax()); }
