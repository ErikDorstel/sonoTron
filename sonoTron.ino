#include <Audio.h>
#include <Metro.h>

const bool logging=true;

AudioInputI2S            i2sin;
AudioOutputI2S           i2sout;
AudioSynthNoiseWhite     noise1;
AudioSynthNoisePink      pink1;
AudioMixer4              mixer1;
AudioMixer4              mixer2;
AudioMixer4              mixer3;
AudioMixer4              mixer4;
AudioMixer4              mixer5;
AudioMixer4              mixer6;
AudioMixer4              mixer7;
AudioAnalyzePeak         peak1;
AudioAnalyzePeak         peak2;
AudioAnalyzePeak         peak3;
AudioAnalyzePeak         peak[17];
AudioFilterStateVariable filter11[17];
AudioFilterStateVariable filter12[17];
AudioFilterStateVariable filter21[17];
AudioFilterStateVariable filter22[17];
AudioConnection          patchCord1(i2sin, 0, mixer1, 0);
AudioConnection          patchCord2(i2sin, 1, mixer2, 0);
AudioConnection          patchCord3(noise1, 0, mixer2, 1);
AudioConnection          patchCord4(noise1, 0, mixer1, 1);
AudioConnection          patchCord5(pink1, 0, mixer2, 2);
AudioConnection          patchCord6(pink1, 0, mixer1, 2);
AudioConnection          patchCord7(mixer1, peak1);
AudioConnection          patchCord8(mixer1, 0, filter11[6], 0);
AudioConnection          patchCord9(mixer1, 0, filter11[5], 0);
AudioConnection          patchCord10(mixer1, 0, filter11[4], 0);
AudioConnection          patchCord11(mixer1, 0, filter11[3], 0);
AudioConnection          patchCord12(mixer1, 0, filter11[2], 0);
AudioConnection          patchCord13(mixer1, 0, filter11[1], 0);
AudioConnection          patchCord14(mixer1, 0, filter11[7], 0);
AudioConnection          patchCord15(mixer1, 0, filter11[8], 0);
AudioConnection          patchCord16(mixer1, 0, filter11[9], 0);
AudioConnection          patchCord17(mixer1, 0, filter11[10], 0);
AudioConnection          patchCord18(mixer1, 0, filter11[11], 0);
AudioConnection          patchCord19(mixer1, 0, filter11[12], 0);
AudioConnection          patchCord20(mixer1, 0, filter11[13], 0);
AudioConnection          patchCord21(mixer1, 0, filter11[14], 0);
AudioConnection          patchCord22(mixer1, 0, filter11[15], 0);
AudioConnection          patchCord23(mixer1, 0, filter11[16], 0);
AudioConnection          patchCord24(mixer2, 0, filter21[1], 0);
AudioConnection          patchCord25(mixer2, 0, filter21[2], 0);
AudioConnection          patchCord26(mixer2, 0, filter21[3], 0);
AudioConnection          patchCord27(mixer2, 0, filter21[4], 0);
AudioConnection          patchCord28(mixer2, 0, filter21[5], 0);
AudioConnection          patchCord29(mixer2, 0, filter21[6], 0);
AudioConnection          patchCord30(mixer2, 0, filter21[7], 0);
AudioConnection          patchCord31(mixer2, 0, filter21[8], 0);
AudioConnection          patchCord32(mixer2, 0, filter21[9], 0);
AudioConnection          patchCord33(mixer2, 0, filter21[10], 0);
AudioConnection          patchCord34(mixer2, 0, filter21[11], 0);
AudioConnection          patchCord35(mixer2, 0, filter21[12], 0);
AudioConnection          patchCord36(mixer2, peak2);
AudioConnection          patchCord37(mixer2, 0, filter21[13], 0);
AudioConnection          patchCord38(mixer2, 0, filter21[14], 0);
AudioConnection          patchCord39(mixer2, 0, filter21[15], 0);
AudioConnection          patchCord40(mixer2, 0, filter21[16], 0);
AudioConnection          patchCord41(filter21[1], 0, filter22[1], 0);
AudioConnection          patchCord42(filter21[2], 1, filter22[2], 0);
AudioConnection          patchCord43(filter21[3], 1, filter22[3], 0);
AudioConnection          patchCord44(filter21[4], 1, filter22[4], 0);
AudioConnection          patchCord45(filter21[5], 1, filter22[5], 0);
AudioConnection          patchCord46(filter21[6], 1, filter22[6], 0);
AudioConnection          patchCord47(filter21[7], 1, filter22[7], 0);
AudioConnection          patchCord48(filter21[8], 1, filter22[8], 0);
AudioConnection          patchCord49(filter11[1], 0, filter12[1], 0);
AudioConnection          patchCord50(filter11[7], 1, filter12[7], 0);
AudioConnection          patchCord51(filter11[2], 1, filter12[2], 0);
AudioConnection          patchCord52(filter11[3], 1, filter12[3], 0);
AudioConnection          patchCord53(filter11[8], 1, filter12[8], 0);
AudioConnection          patchCord54(filter11[4], 1, filter12[4], 0);
AudioConnection          patchCord55(filter11[5], 1, filter12[5], 0);
AudioConnection          patchCord56(filter11[6], 1, filter12[6], 0);
AudioConnection          patchCord57(filter22[2], 1, mixer3, 1);
AudioConnection          patchCord58(filter22[1], 0, mixer3, 0);
AudioConnection          patchCord59(filter22[3], 1, mixer3, 2);
AudioConnection          patchCord60(filter22[5], 1, mixer4, 0);
AudioConnection          patchCord61(filter22[4], 1, mixer3, 3);
AudioConnection          patchCord62(filter22[6], 1, mixer4, 1);
AudioConnection          patchCord63(filter22[7], 1, mixer4, 2);
AudioConnection          patchCord64(filter22[8], 1, mixer4, 3);
AudioConnection          patchCord65(filter12[2], 1, peak[2], 0);
AudioConnection          patchCord66(filter12[1], 0, peak[1], 0);
AudioConnection          patchCord67(filter12[3], 1, peak[3], 0);
AudioConnection          patchCord68(filter12[5], 1, peak[5], 0);
AudioConnection          patchCord69(filter12[6], 1, peak[6], 0);
AudioConnection          patchCord70(filter12[8], 1, peak[8], 0);
AudioConnection          patchCord71(filter12[4], 1, peak[4], 0);
AudioConnection          patchCord72(filter12[7], 1, peak[7], 0);
AudioConnection          patchCord73(filter21[9], 1, filter22[9], 0);
AudioConnection          patchCord74(filter21[10], 1, filter22[10], 0);
AudioConnection          patchCord75(filter21[11], 1, filter22[11], 0);
AudioConnection          patchCord76(filter21[12], 1, filter22[12], 0);
AudioConnection          patchCord77(filter21[13], 1, filter22[13], 0);
AudioConnection          patchCord78(filter21[15], 1, filter22[15], 0);
AudioConnection          patchCord79(filter21[14], 1, filter22[14], 0);
AudioConnection          patchCord80(filter21[16], 2, filter22[16], 0);
AudioConnection          patchCord81(filter22[11], 1, mixer5, 2);
AudioConnection          patchCord82(filter22[9], 1, mixer5, 0);
AudioConnection          patchCord83(filter22[10], 1, mixer5, 1);
AudioConnection          patchCord84(filter11[9], 1, filter12[9], 0);
AudioConnection          patchCord85(filter22[15], 1, mixer6, 2);
AudioConnection          patchCord86(filter11[10], 1, filter12[10], 0);
AudioConnection          patchCord87(filter11[13], 1, filter12[13], 0);
AudioConnection          patchCord88(filter22[13], 1, mixer6, 0);
AudioConnection          patchCord89(filter22[12], 1, mixer5, 3);
AudioConnection          patchCord90(filter11[12], 1, filter12[12], 0);
AudioConnection          patchCord91(filter11[14], 1, filter12[14], 0);
AudioConnection          patchCord92(filter11[15], 1, filter12[15], 0);
AudioConnection          patchCord93(filter11[16], 2, filter12[16], 0);
AudioConnection          patchCord94(filter11[11], 1, filter12[11], 0);
AudioConnection          patchCord95(filter22[14], 1, mixer6, 1);
AudioConnection          patchCord96(filter22[16], 2, mixer6, 3);
AudioConnection          patchCord97(filter12[9], 1, peak[9], 0);
AudioConnection          patchCord98(filter12[10], 1, peak[10], 0);
AudioConnection          patchCord99(filter12[11], 1, peak[11], 0);
AudioConnection          patchCord100(filter12[14], 1, peak[14], 0);
AudioConnection          patchCord101(filter12[12], 1, peak[12], 0);
AudioConnection          patchCord102(filter12[13], 1, peak[13], 0);
AudioConnection          patchCord103(filter12[15], 1, peak[15], 0);
AudioConnection          patchCord104(filter12[16], 2, peak[16], 0);
AudioConnection          patchCord105(mixer3, 0, mixer7, 0);
AudioConnection          patchCord106(mixer4, 0, mixer7, 1);
AudioConnection          patchCord107(mixer5, 0, mixer7, 2);
AudioConnection          patchCord108(mixer6, 0, mixer7, 3);
AudioConnection          patchCord109(mixer7, 0, i2sout, 0);
AudioConnection          patchCord110(mixer7, 0, i2sout, 1);
AudioConnection          patchCord111(mixer7, peak3);
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
  noise1.amplitude(1); pink1.amplitude(1);
  for (byte c=1;c<=16;c++) { carrierGain[c]=1; }
  setModulatorSource(1,0,0);
  setCarrierSource(1,0,0);
  setModulatorFrequency(50,5000);
  setCarrierFrequency(50,5000);
  setFilterResonance(5);
  setOutputAmplifier(2);
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
  if (modulatorLevel[1] > carrierGain[1]) { carrierGain[1] /= envelopeSpeed; mixer3.gain(0, carrierGain[1]); }
  if (modulatorLevel[1] < carrierGain[1]) { carrierGain[1] *= envelopeSpeed; mixer3.gain(0, carrierGain[1]); }
  if (modulatorLevel[2] > carrierGain[2]) { carrierGain[2] /= envelopeSpeed; mixer3.gain(1, carrierGain[2]); }
  if (modulatorLevel[2] < carrierGain[2]) { carrierGain[2] *= envelopeSpeed; mixer3.gain(1, carrierGain[2]); }
  if (modulatorLevel[3] > carrierGain[3]) { carrierGain[3] /= envelopeSpeed; mixer3.gain(2, carrierGain[3]); }
  if (modulatorLevel[3] < carrierGain[3]) { carrierGain[3] *= envelopeSpeed; mixer3.gain(2, carrierGain[3]); }
  if (modulatorLevel[4] > carrierGain[4]) { carrierGain[4] /= envelopeSpeed; mixer3.gain(3, carrierGain[4]); }
  if (modulatorLevel[4] < carrierGain[4]) { carrierGain[4] *= envelopeSpeed; mixer3.gain(3, carrierGain[4]); }
  if (modulatorLevel[5] > carrierGain[5]) { carrierGain[5] /= envelopeSpeed; mixer4.gain(0, carrierGain[5]); }
  if (modulatorLevel[5] < carrierGain[5]) { carrierGain[5] *= envelopeSpeed; mixer4.gain(0, carrierGain[5]); }
  if (modulatorLevel[6] > carrierGain[6]) { carrierGain[6] /= envelopeSpeed; mixer4.gain(1, carrierGain[6]); }
  if (modulatorLevel[6] < carrierGain[6]) { carrierGain[6] *= envelopeSpeed; mixer4.gain(1, carrierGain[6]); }
  if (modulatorLevel[7] > carrierGain[7]) { carrierGain[7] /= envelopeSpeed; mixer4.gain(2, carrierGain[7]); }
  if (modulatorLevel[7] < carrierGain[7]) { carrierGain[7] *= envelopeSpeed; mixer4.gain(2, carrierGain[7]); }
  if (modulatorLevel[8] > carrierGain[8]) { carrierGain[8] /= envelopeSpeed; mixer4.gain(3, carrierGain[8]); }
  if (modulatorLevel[8] < carrierGain[8]) { carrierGain[8] *= envelopeSpeed; mixer4.gain(3, carrierGain[8]); }
  if (modulatorLevel[9] > carrierGain[9]) { carrierGain[9] /= envelopeSpeed; mixer5.gain(0, carrierGain[9]); }
  if (modulatorLevel[9] < carrierGain[9]) { carrierGain[9] *= envelopeSpeed; mixer5.gain(0, carrierGain[9]); }
  if (modulatorLevel[10] > carrierGain[10]) { carrierGain[10] /= envelopeSpeed; mixer5.gain(1, carrierGain[10]); }
  if (modulatorLevel[10] < carrierGain[10]) { carrierGain[10] *= envelopeSpeed; mixer5.gain(1, carrierGain[10]); }
  if (modulatorLevel[11] > carrierGain[11]) { carrierGain[11] /= envelopeSpeed; mixer5.gain(2, carrierGain[11]); }
  if (modulatorLevel[11] < carrierGain[11]) { carrierGain[11] *= envelopeSpeed; mixer5.gain(2, carrierGain[11]); }
  if (modulatorLevel[12] > carrierGain[12]) { carrierGain[12] /= envelopeSpeed; mixer5.gain(3, carrierGain[12]); }
  if (modulatorLevel[12] < carrierGain[12]) { carrierGain[12] *= envelopeSpeed; mixer5.gain(3, carrierGain[12]); }
  if (modulatorLevel[13] > carrierGain[13]) { carrierGain[13] /= envelopeSpeed; mixer6.gain(0, carrierGain[13]); }
  if (modulatorLevel[13] < carrierGain[13]) { carrierGain[13] *= envelopeSpeed; mixer6.gain(0, carrierGain[13]); }
  if (modulatorLevel[14] > carrierGain[14]) { carrierGain[14] /= envelopeSpeed; mixer6.gain(1, carrierGain[14]); }
  if (modulatorLevel[14] < carrierGain[14]) { carrierGain[14] *= envelopeSpeed; mixer6.gain(1, carrierGain[14]); }
  if (modulatorLevel[15] > carrierGain[15]) { carrierGain[15] /= envelopeSpeed; mixer6.gain(2, carrierGain[15]); }
  if (modulatorLevel[15] < carrierGain[15]) { carrierGain[15] *= envelopeSpeed; mixer6.gain(2, carrierGain[15]); }
  if (modulatorLevel[16] > carrierGain[16]) { carrierGain[16] /= envelopeSpeed; mixer6.gain(3, carrierGain[16]); }
  if (modulatorLevel[16] < carrierGain[16]) { carrierGain[16] *= envelopeSpeed; mixer6.gain(3, carrierGain[16]); }
  if ((timer.check() == 1) and logging) {
    Serial.print("Modulator: "); Serial.print(peak1.read());
    Serial.print(" Carrier: "); Serial.print(peak2.read());
    Serial.print(" Output: "); Serial.print(peak3.read()); Serial.println(""); logUtil(); } }

void MIDIsetControl(byte channel, byte control, byte value) {
  float fvalue, lvalue; fvalue=float(value)/127; lvalue=pow(fvalue,3);
  if (control==0) { modulatorButtom=(lvalue*4950)+50; setModulatorFrequency(modulatorButtom,modulatorTop); }
  if (control==1) { modulatorTop=(lvalue*4950)+50; setModulatorFrequency(modulatorButtom,modulatorTop); }
  if (control==2) { carrierButtom=(lvalue*4950)+50; setCarrierFrequency(carrierButtom,carrierTop); }
  if (control==3) { carrierTop=(lvalue*4950)+50; setCarrierFrequency(carrierButtom,carrierTop); }
  if (control==4) { envelopeSpeed=((fvalue/2)+0.4996); }
  if (control==5) { envelopeLimit=fvalue; }
  if (control==6) { setFilterResonance((fvalue*4.3)+0.7); }
  if (control==7) { setOutputAmplifier(lvalue*10); }
  if (control==8) {
    if ((value&96)==0) { setModulatorSource(1,0,0); }
    if ((value&96)==32) { setModulatorSource(0,1,0); }
    if ((value&96)==64) { setModulatorSource(0,0,1); }
    if ((value&96)==96) { setModulatorSource(0,0,1); } }
  if (control==9) {
    if ((value&96)==0) { setCarrierSource(1,0,0); }
    if ((value&96)==32) { setCarrierSource(0,1,0); }
    if ((value&96)==64) { setCarrierSource(0,0,1); }
    if ((value&96)==96) { setCarrierSource(0,0,1); } } }

void setFilterResonance(float r) { for (byte c=1;c<=16;c++) { filter11[c].resonance(r); filter12[c].resonance(r); filter21[c].resonance(r); filter22[c].resonance(r); } }

void setOutputAmplifier(float g) { mixer7.gain(0,g); mixer7.gain(1,g); mixer7.gain(2,g); mixer7.gain(3,g); }

void setModulatorFrequency(float b,float t) { for (byte c=1;c<=16;c++) { float freq=b*pow(t/b,(c-1)/15.0); filter11[c].frequency(freq); filter12[c].frequency(freq); } }

void setCarrierFrequency(float b,float t) { for (byte c=1;c<=16;c++) { float freq=b*pow(t/b,(c-1)/15.0); filter21[c].frequency(freq); filter22[c].frequency(freq); } }

void setModulatorSource(byte a, byte b, byte c) { mixer1.gain(0,a); mixer1.gain(1,b); mixer1.gain(2,c); mixer1.gain(3,0); }

void setCarrierSource(byte a, byte b, byte c) { mixer2.gain(0,a); mixer2.gain(1,b); mixer2.gain(2,c); mixer2.gain(3,0); }

void logUtil() {
  Serial.print("Memory: "); Serial.print(AudioMemoryUsage()); Serial.print("/"); Serial.print(AudioMemoryUsageMax());
  Serial.print(" CPU: "); Serial.print(AudioProcessorUsage()); Serial.print("/"); Serial.println(AudioProcessorUsageMax()); }
