#include <Audio.h>
#include <Metro.h>

const bool logging=true;

AudioInputI2S            i2sin;
AudioOutputI2S           i2sout;
AudioSynthNoiseWhite     noise;
AudioSynthNoisePink      pink;
AudioSynthWaveform       lfo;
AudioSynthWaveformModulated vco1;
AudioSynthWaveformModulated vco2;
AudioSynthWaveformModulated vco3;
AudioSynthWaveformModulated vco4;
AudioMixer4              mixermodulator;
AudioMixer4              mixercarrier;
AudioMixer4              mixervco;
AudioAnalyzePeak         peak1;
AudioAnalyzePeak         peak2;
AudioAnalyzePeak         peak3;
AudioAnalyzePeak         peak[17];
AudioFilterStateVariable filter11[17];
AudioFilterStateVariable filter12[17];
AudioFilterStateVariable filter21[17];
AudioFilterStateVariable filter22[17];
AudioMixer4              mixer1;
AudioMixer4              mixer2;
AudioMixer4              mixer3;
AudioMixer4              mixer4;
AudioMixer4              mixer14;
AudioConnection          patchCord1(noise, 0, mixercarrier, 1);
AudioConnection          patchCord2(noise, 0, mixermodulator, 1);
AudioConnection          patchCord3(i2sin, 0, mixermodulator, 0);
AudioConnection          patchCord4(i2sin, 1, mixercarrier, 0);
AudioConnection          patchCord5(lfo, 0, vco1, 0);
AudioConnection          patchCord6(lfo, 0, vco2, 0);
AudioConnection          patchCord7(lfo, 0, vco3, 0);
AudioConnection          patchCord8(lfo, 0, vco4, 0);
AudioConnection          patchCord9(pink, 0, mixercarrier, 2);
AudioConnection          patchCord10(pink, 0, mixermodulator, 2);
AudioConnection          patchCord11(vco4, 0, mixervco, 3);
AudioConnection          patchCord12(vco2, 0, mixervco, 1);
AudioConnection          patchCord13(vco3, 0, mixervco, 2);
AudioConnection          patchCord14(vco1, 0, mixervco, 0);
AudioConnection          patchCord15(mixervco, 0, mixermodulator, 3);
AudioConnection          patchCord16(mixervco, 0, mixercarrier, 3);
AudioConnection          patchCord17(mixercarrier, 0, filter21[1], 0);
AudioConnection          patchCord18(mixercarrier, 0, filter21[2], 0);
AudioConnection          patchCord19(mixercarrier, 0, filter21[3], 0);
AudioConnection          patchCord20(mixercarrier, 0, filter21[4], 0);
AudioConnection          patchCord21(mixercarrier, 0, filter21[5], 0);
AudioConnection          patchCord22(mixercarrier, 0, filter21[6], 0);
AudioConnection          patchCord23(mixercarrier, 0, filter21[7], 0);
AudioConnection          patchCord24(mixercarrier, 0, filter21[8], 0);
AudioConnection          patchCord25(mixercarrier, 0, filter21[9], 0);
AudioConnection          patchCord26(mixercarrier, 0, filter21[10], 0);
AudioConnection          patchCord27(mixercarrier, 0, filter21[11], 0);
AudioConnection          patchCord28(mixercarrier, 0, filter21[12], 0);
AudioConnection          patchCord29(mixercarrier, peak2);
AudioConnection          patchCord30(mixercarrier, 0, filter21[13], 0);
AudioConnection          patchCord31(mixercarrier, 0, filter21[14], 0);
AudioConnection          patchCord32(mixercarrier, 0, filter21[15], 0);
AudioConnection          patchCord33(mixercarrier, 0, filter21[16], 0);
AudioConnection          patchCord34(mixermodulator, peak1);
AudioConnection          patchCord35(mixermodulator, 0, filter11[6], 0);
AudioConnection          patchCord36(mixermodulator, 0, filter11[5], 0);
AudioConnection          patchCord37(mixermodulator, 0, filter11[4], 0);
AudioConnection          patchCord38(mixermodulator, 0, filter11[3], 0);
AudioConnection          patchCord39(mixermodulator, 0, filter11[2], 0);
AudioConnection          patchCord40(mixermodulator, 0, filter11[1], 0);
AudioConnection          patchCord41(mixermodulator, 0, filter11[7], 0);
AudioConnection          patchCord42(mixermodulator, 0, filter11[8], 0);
AudioConnection          patchCord43(mixermodulator, 0, filter11[9], 0);
AudioConnection          patchCord44(mixermodulator, 0, filter11[10], 0);
AudioConnection          patchCord45(mixermodulator, 0, filter11[11], 0);
AudioConnection          patchCord46(mixermodulator, 0, filter11[12], 0);
AudioConnection          patchCord47(mixermodulator, 0, filter11[13], 0);
AudioConnection          patchCord48(mixermodulator, 0, filter11[14], 0);
AudioConnection          patchCord49(mixermodulator, 0, filter11[15], 0);
AudioConnection          patchCord50(mixermodulator, 0, filter11[16], 0);
AudioConnection          patchCord51(filter21[1], 0, filter22[1], 0);
AudioConnection          patchCord52(filter21[2], 1, filter22[2], 0);
AudioConnection          patchCord53(filter21[3], 1, filter22[3], 0);
AudioConnection          patchCord54(filter21[4], 1, filter22[4], 0);
AudioConnection          patchCord55(filter21[5], 1, filter22[5], 0);
AudioConnection          patchCord56(filter21[6], 1, filter22[6], 0);
AudioConnection          patchCord57(filter21[7], 1, filter22[7], 0);
AudioConnection          patchCord58(filter21[8], 1, filter22[8], 0);
AudioConnection          patchCord59(filter11[1], 0, filter12[1], 0);
AudioConnection          patchCord60(filter11[7], 1, filter12[7], 0);
AudioConnection          patchCord61(filter11[2], 1, filter12[2], 0);
AudioConnection          patchCord62(filter11[3], 1, filter12[3], 0);
AudioConnection          patchCord63(filter11[8], 1, filter12[8], 0);
AudioConnection          patchCord64(filter11[4], 1, filter12[4], 0);
AudioConnection          patchCord65(filter11[5], 1, filter12[5], 0);
AudioConnection          patchCord66(filter11[6], 1, filter12[6], 0);
AudioConnection          patchCord67(filter22[2], 1, mixer1, 1);
AudioConnection          patchCord68(filter22[1], 0, mixer1, 0);
AudioConnection          patchCord69(filter22[3], 1, mixer1, 2);
AudioConnection          patchCord70(filter22[5], 1, mixer2, 0);
AudioConnection          patchCord71(filter22[4], 1, mixer1, 3);
AudioConnection          patchCord72(filter22[6], 1, mixer2, 1);
AudioConnection          patchCord73(filter22[7], 1, mixer2, 2);
AudioConnection          patchCord74(filter22[8], 1, mixer2, 3);
AudioConnection          patchCord75(filter12[2], 1, peak[2], 0);
AudioConnection          patchCord76(filter12[1], 0, peak[1], 0);
AudioConnection          patchCord77(filter12[3], 1, peak[3], 0);
AudioConnection          patchCord78(filter12[5], 1, peak[5], 0);
AudioConnection          patchCord79(filter12[6], 1, peak[6], 0);
AudioConnection          patchCord80(filter12[8], 1, peak[8], 0);
AudioConnection          patchCord81(filter12[4], 1, peak[4], 0);
AudioConnection          patchCord82(filter12[7], 1, peak[7], 0);
AudioConnection          patchCord83(filter21[9], 1, filter22[9], 0);
AudioConnection          patchCord84(filter21[10], 1, filter22[10], 0);
AudioConnection          patchCord85(filter21[11], 1, filter22[11], 0);
AudioConnection          patchCord86(filter21[12], 1, filter22[12], 0);
AudioConnection          patchCord87(filter21[13], 1, filter22[13], 0);
AudioConnection          patchCord88(filter21[15], 1, filter22[15], 0);
AudioConnection          patchCord89(filter21[14], 1, filter22[14], 0);
AudioConnection          patchCord90(filter21[16], 2, filter22[16], 0);
AudioConnection          patchCord91(filter22[11], 1, mixer3, 2);
AudioConnection          patchCord92(filter22[9], 1, mixer3, 0);
AudioConnection          patchCord93(filter22[10], 1, mixer3, 1);
AudioConnection          patchCord94(filter22[15], 1, mixer4, 2);
AudioConnection          patchCord95(filter22[13], 1, mixer4, 0);
AudioConnection          patchCord96(filter22[12], 1, mixer3, 3);
AudioConnection          patchCord97(filter22[14], 1, mixer4, 1);
AudioConnection          patchCord98(filter22[16], 2, mixer4, 3);
AudioConnection          patchCord99(filter11[9], 1, filter12[9], 0);
AudioConnection          patchCord100(filter11[10], 1, filter12[10], 0);
AudioConnection          patchCord101(filter11[13], 1, filter12[13], 0);
AudioConnection          patchCord102(filter11[12], 1, filter12[12], 0);
AudioConnection          patchCord103(filter11[14], 1, filter12[14], 0);
AudioConnection          patchCord104(filter11[15], 1, filter12[15], 0);
AudioConnection          patchCord105(filter11[16], 2, filter12[16], 0);
AudioConnection          patchCord106(filter11[11], 1, filter12[11], 0);
AudioConnection          patchCord107(mixer4, 0, mixer14, 3);
AudioConnection          patchCord108(mixer3, 0, mixer14, 2);
AudioConnection          patchCord109(mixer1, 0, mixer14, 0);
AudioConnection          patchCord110(mixer2, 0, mixer14, 1);
AudioConnection          patchCord111(filter12[9], 1, peak[9], 0);
AudioConnection          patchCord112(filter12[10], 1, peak[10], 0);
AudioConnection          patchCord113(filter12[11], 1, peak[11], 0);
AudioConnection          patchCord114(filter12[14], 1, peak[14], 0);
AudioConnection          patchCord115(filter12[12], 1, peak[12], 0);
AudioConnection          patchCord116(filter12[13], 1, peak[13], 0);
AudioConnection          patchCord117(filter12[15], 1, peak[15], 0);
AudioConnection          patchCord118(filter12[16], 2, peak[16], 0);
AudioConnection          patchCord119(mixer14, 0, i2sout, 0);
AudioConnection          patchCord120(mixer14, 0, i2sout, 1);
AudioConnection          patchCord121(mixer14, peak3);
AudioControlSGTL5000     sgtl5000_1;

Metro timer = Metro(1000);
float modulatorLevel[17], carrierGain[17];
float envelopeSpeed=0.996, envelopeLimit=0.1;
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
  setLFO(1,100,WAVEFORM_SINE);
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
      // if (MIDIstatusA==0x80) { MIDIsetNoteOff(MIDIchannelA,MIDIpara1A,MIDIpara2A); }
      // if (MIDIstatusA==0x90) { MIDIsetNoteOn(MIDIchannelA,MIDIpara1A,MIDIpara2A); }
      if (MIDIstatusA==0xB0) { MIDIsetControl(MIDIchannelA,MIDIpara1A,MIDIpara2A); }
      // if (MIDIstatusA==0xE0) { MIDIsetPitchbend(MIDIchannelA,MIDIpara1A+(128*MIDIpara2A)); }
      MIDIpara1A=255; MIDIpara2A=255; } } }
      
  for (byte c=1;c<=16;c++) { if (peak[c].available()) { modulatorLevel[c]=peak[c].read()*envelopeLimit; } }
  if (modulatorLevel[1] > carrierGain[1]) { carrierGain[1] /= envelopeSpeed; mixer1.gain(0, carrierGain[1]); }
  if (modulatorLevel[1] < carrierGain[1]) { carrierGain[1] *= envelopeSpeed; mixer1.gain(0, carrierGain[1]); }
  if (modulatorLevel[2] > carrierGain[2]) { carrierGain[2] /= envelopeSpeed; mixer1.gain(1, carrierGain[2]); }
  if (modulatorLevel[2] < carrierGain[2]) { carrierGain[2] *= envelopeSpeed; mixer1.gain(1, carrierGain[2]); }
  if (modulatorLevel[3] > carrierGain[3]) { carrierGain[3] /= envelopeSpeed; mixer1.gain(2, carrierGain[3]); }
  if (modulatorLevel[3] < carrierGain[3]) { carrierGain[3] *= envelopeSpeed; mixer1.gain(2, carrierGain[3]); }
  if (modulatorLevel[4] > carrierGain[4]) { carrierGain[4] /= envelopeSpeed; mixer1.gain(3, carrierGain[4]); }
  if (modulatorLevel[4] < carrierGain[4]) { carrierGain[4] *= envelopeSpeed; mixer1.gain(3, carrierGain[4]); }
  if (modulatorLevel[5] > carrierGain[5]) { carrierGain[5] /= envelopeSpeed; mixer2.gain(0, carrierGain[5]); }
  if (modulatorLevel[5] < carrierGain[5]) { carrierGain[5] *= envelopeSpeed; mixer2.gain(0, carrierGain[5]); }
  if (modulatorLevel[6] > carrierGain[6]) { carrierGain[6] /= envelopeSpeed; mixer2.gain(1, carrierGain[6]); }
  if (modulatorLevel[6] < carrierGain[6]) { carrierGain[6] *= envelopeSpeed; mixer2.gain(1, carrierGain[6]); }
  if (modulatorLevel[7] > carrierGain[7]) { carrierGain[7] /= envelopeSpeed; mixer2.gain(2, carrierGain[7]); }
  if (modulatorLevel[7] < carrierGain[7]) { carrierGain[7] *= envelopeSpeed; mixer2.gain(2, carrierGain[7]); }
  if (modulatorLevel[8] > carrierGain[8]) { carrierGain[8] /= envelopeSpeed; mixer2.gain(3, carrierGain[8]); }
  if (modulatorLevel[8] < carrierGain[8]) { carrierGain[8] *= envelopeSpeed; mixer2.gain(3, carrierGain[8]); }
  if (modulatorLevel[9] > carrierGain[9]) { carrierGain[9] /= envelopeSpeed; mixer3.gain(0, carrierGain[9]); }
  if (modulatorLevel[9] < carrierGain[9]) { carrierGain[9] *= envelopeSpeed; mixer3.gain(0, carrierGain[9]); }
  if (modulatorLevel[10] > carrierGain[10]) { carrierGain[10] /= envelopeSpeed; mixer3.gain(1, carrierGain[10]); }
  if (modulatorLevel[10] < carrierGain[10]) { carrierGain[10] *= envelopeSpeed; mixer3.gain(1, carrierGain[10]); }
  if (modulatorLevel[11] > carrierGain[11]) { carrierGain[11] /= envelopeSpeed; mixer3.gain(2, carrierGain[11]); }
  if (modulatorLevel[11] < carrierGain[11]) { carrierGain[11] *= envelopeSpeed; mixer3.gain(2, carrierGain[11]); }
  if (modulatorLevel[12] > carrierGain[12]) { carrierGain[12] /= envelopeSpeed; mixer3.gain(3, carrierGain[12]); }
  if (modulatorLevel[12] < carrierGain[12]) { carrierGain[12] *= envelopeSpeed; mixer3.gain(3, carrierGain[12]); }
  if (modulatorLevel[13] > carrierGain[13]) { carrierGain[13] /= envelopeSpeed; mixer4.gain(0, carrierGain[13]); }
  if (modulatorLevel[13] < carrierGain[13]) { carrierGain[13] *= envelopeSpeed; mixer4.gain(0, carrierGain[13]); }
  if (modulatorLevel[14] > carrierGain[14]) { carrierGain[14] /= envelopeSpeed; mixer4.gain(1, carrierGain[14]); }
  if (modulatorLevel[14] < carrierGain[14]) { carrierGain[14] *= envelopeSpeed; mixer4.gain(1, carrierGain[14]); }
  if (modulatorLevel[15] > carrierGain[15]) { carrierGain[15] /= envelopeSpeed; mixer4.gain(2, carrierGain[15]); }
  if (modulatorLevel[15] < carrierGain[15]) { carrierGain[15] *= envelopeSpeed; mixer4.gain(2, carrierGain[15]); }
  if (modulatorLevel[16] > carrierGain[16]) { carrierGain[16] /= envelopeSpeed; mixer4.gain(3, carrierGain[16]); }
  if (modulatorLevel[16] < carrierGain[16]) { carrierGain[16] *= envelopeSpeed; mixer4.gain(3, carrierGain[16]); }
  if ((timer.check() == 1) and logging) {
    Serial.print("Modulator: "); Serial.print(peak1.read());
    Serial.print(" Carrier: "); Serial.print(peak2.read());
    Serial.print(" Output: "); Serial.print(peak3.read()); Serial.println(""); logUtil(); } }

void MIDIsetControl(byte channel, byte control, byte value) {
  float fvalue=float(value)/127; float lvalue=pow(fvalue,3);
  if (control==0) { modulatorButtom=(lvalue*4950)+50; setModulatorFrequency(modulatorButtom,modulatorTop); }
  if (control==1) { modulatorTop=(lvalue*4950)+50; setModulatorFrequency(modulatorButtom,modulatorTop); }
  if (control==2) { carrierButtom=(lvalue*4950)+50; setCarrierFrequency(carrierButtom,carrierTop); }
  if (control==3) { carrierTop=(lvalue*4950)+50; setCarrierFrequency(carrierButtom,carrierTop); }
  if (control==4) { envelopeSpeed=((fvalue/2)+0.4996); }
  if (control==5) { envelopeLimit=fvalue; }
  if (control==6) { setFilterResonance((fvalue*4.3)+0.7); }
  if (control==7) { setOutputAmplifier(lvalue*10); }
  if (control==8) {
    if ((value&96)==0) { lfo.begin(WAVEFORM_SINE); }
    if ((value&96)==32) { lfo.begin(WAVEFORM_SAWTOOTH); }
    if ((value&96)==64) { lfo.begin(WAVEFORM_SQUARE); }
    if ((value&96)==96) { lfo.begin(WAVEFORM_TRIANGLE); } }
  if (control==9) {
    if ((value&96)==0) { vco1.begin(WAVEFORM_SINE); }
    if ((value&96)==32) { vco1.begin(WAVEFORM_SAWTOOTH); }
    if ((value&96)==64) { vco1.begin(WAVEFORM_SQUARE); }
    if ((value&96)==96) { vco1.begin(WAVEFORM_TRIANGLE); } }
  if (control==10) {
    if ((value&96)==0) { vco2.begin(WAVEFORM_SINE); }
    if ((value&96)==32) { vco2.begin(WAVEFORM_SAWTOOTH); }
    if ((value&96)==64) { vco2.begin(WAVEFORM_SQUARE); }
    if ((value&96)==96) { vco2.begin(WAVEFORM_TRIANGLE); } }
  if (control==11) {
    if ((value&96)==0) { vco3.begin(WAVEFORM_SINE); }
    if ((value&96)==32) { vco3.begin(WAVEFORM_SAWTOOTH); }
    if ((value&96)==64) { vco3.begin(WAVEFORM_SQUARE); }
    if ((value&96)==96) { vco3.begin(WAVEFORM_TRIANGLE); } }
  if (control==12) {
    if ((value&96)==0) { vco4.begin(WAVEFORM_SINE); }
    if ((value&96)==32) { vco4.begin(WAVEFORM_SAWTOOTH); }
    if ((value&96)==64) { vco4.begin(WAVEFORM_SQUARE); }
    if ((value&96)==96) { vco4.begin(WAVEFORM_TRIANGLE); } }
  if (control==13) { vco1.frequencyModulation((fvalue*11)+1); vco2.frequencyModulation((fvalue*11)+1); vco3.frequencyModulation((fvalue*11)+1); vco4.frequencyModulation((fvalue*11)+1); }
  if (control==14) {
    if ((value&96)==0) { setModulatorSource(1,0,0,0); }
    if ((value&96)==32) { setModulatorSource(0,1,0,0); }
    if ((value&96)==64) { setModulatorSource(0,0,1,0); }
    if ((value&96)==96) { setModulatorSource(0,0,0,1); } }
  if (control==15) {
    if ((value&96)==0) { setCarrierSource(1,0,0,0); }
    if ((value&96)==32) { setCarrierSource(0,1,0,0); }
    if ((value&96)==64) { setCarrierSource(0,0,1,0); }
    if ((value&96)==96) { setCarrierSource(0,0,0,1); } }
  if (control==16) { lfo.amplitude(fvalue); }
  if (control==17) { vco1.amplitude(fvalue); }
  if (control==18) { vco2.amplitude(fvalue); }
  if (control==19) { vco3.amplitude(fvalue); }
  if (control==20) { vco4.amplitude(fvalue); }
  if (control==24) { lfo.frequency(lvalue*1000); }
  if (control==25) { vco1.frequency(lvalue*5000); }
  if (control==26) { vco2.frequency(lvalue*5000); }
  if (control==27) { vco3.frequency(lvalue*5000); }
  if (control==28) { vco4.frequency(lvalue*5000); } }

void setFilterResonance(float r) { for (byte c=1;c<=16;c++) { filter11[c].resonance(r); filter12[c].resonance(r); filter21[c].resonance(r); filter22[c].resonance(r); } }

void setOutputAmplifier(float g) { mixer14.gain(0,g); mixer14.gain(1,g); mixer14.gain(2,g); mixer14.gain(3,g); }

void setModulatorFrequency(float b,float t) { for (byte c=1;c<=16;c++) { float freq=b*pow(t/b,(c-1)/15.0); filter11[c].frequency(freq); filter12[c].frequency(freq); } }

void setCarrierFrequency(float b,float t) { for (byte c=1;c<=16;c++) { float freq=b*pow(t/b,(c-1)/15.0); filter21[c].frequency(freq); filter22[c].frequency(freq); } }

void setModulatorSource(float a, float b, float c, float d) { mixermodulator.gain(0,a); mixermodulator.gain(1,b); mixermodulator.gain(2,c); mixermodulator.gain(3,d); }

void setCarrierSource(float a, float b, float c, float d) { mixercarrier.gain(0,a); mixercarrier.gain(1,b); mixercarrier.gain(2,c); mixercarrier.gain(3,d); }

void setMixerVCO(float a, float b, float c, float d) { mixervco.gain(0,a); mixervco.gain(1,b); mixervco.gain(2,c); mixervco.gain(3,d); }

void setVCO1(float a, float f, byte w, byte o) { vco1.begin(a,f,w); vco1.frequencyModulation(o); }
void setVCO2(float a, float f, byte w, byte o) { vco2.begin(a,f,w); vco2.frequencyModulation(o); }
void setVCO3(float a, float f, byte w, byte o) { vco3.begin(a,f,w); vco3.frequencyModulation(o); }
void setVCO4(float a, float f, byte w, byte o) { vco4.begin(a,f,w); vco4.frequencyModulation(o); }
void setLFO(float a, float f, byte w) { lfo.begin(a,f,w); }

void logUtil() {
  Serial.print("Memory: "); Serial.print(AudioMemoryUsage()); Serial.print("/"); Serial.print(AudioMemoryUsageMax());
  Serial.print(" CPU: "); Serial.print(AudioProcessorUsage()); Serial.print("/"); Serial.println(AudioProcessorUsageMax()); }
