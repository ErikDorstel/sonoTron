#include <Audio.h>
#include <Metro.h>

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
AudioAnalyzePeak         peak1;
AudioAnalyzePeak         peak2;
AudioAnalyzePeak         peak3;
AudioAnalyzePeak         peak[13];
AudioFilterStateVariable filter11[13];
AudioFilterStateVariable filter12[13];
AudioFilterStateVariable filter21[13];
AudioFilterStateVariable filter22[13];
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
AudioConnection          patchCord20(mixer2, 0, filter21[1], 0);
AudioConnection          patchCord21(mixer2, 0, filter21[2], 0);
AudioConnection          patchCord22(mixer2, 0, filter21[3], 0);
AudioConnection          patchCord23(mixer2, 0, filter21[4], 0);
AudioConnection          patchCord24(mixer2, 0, filter21[5], 0);
AudioConnection          patchCord25(mixer2, 0, filter21[6], 0);
AudioConnection          patchCord26(mixer2, 0, filter21[7], 0);
AudioConnection          patchCord27(mixer2, 0, filter21[8], 0);
AudioConnection          patchCord28(mixer2, 0, filter21[9], 0);
AudioConnection          patchCord29(mixer2, 0, filter21[10], 0);
AudioConnection          patchCord30(mixer2, 0, filter21[11], 0);
AudioConnection          patchCord31(mixer2, 0, filter21[12], 0);
AudioConnection          patchCord32(mixer2, peak2);
AudioConnection          patchCord33(filter21[1], 0, filter22[1], 0);
AudioConnection          patchCord34(filter21[2], 1, filter22[2], 0);
AudioConnection          patchCord35(filter21[3], 1, filter22[3], 0);
AudioConnection          patchCord36(filter21[4], 1, filter22[4], 0);
AudioConnection          patchCord37(filter21[5], 1, filter22[5], 0);
AudioConnection          patchCord38(filter21[6], 1, filter22[6], 0);
AudioConnection          patchCord39(filter22[1], 0, mixer3, 0);
AudioConnection          patchCord40(filter22[2], 1, mixer3, 1);
AudioConnection          patchCord41(filter22[3], 1, mixer4, 0);
AudioConnection          patchCord42(filter22[4], 1, mixer4, 1);
AudioConnection          patchCord43(filter22[5], 1, mixer5, 0);
AudioConnection          patchCord44(filter22[6], 1, mixer5, 1);
AudioConnection          patchCord45(filter11[1], 0, filter12[1], 0);
AudioConnection          patchCord46(filter11[2], 1, filter12[2], 0);
AudioConnection          patchCord47(filter11[3], 1, filter12[3], 0);
AudioConnection          patchCord48(filter11[4], 1, filter12[4], 0);
AudioConnection          patchCord49(filter11[5], 1, filter12[5], 0);
AudioConnection          patchCord50(filter11[6], 1, filter12[6], 0);
AudioConnection          patchCord51(filter12[1], 0, peak[1], 0);
AudioConnection          patchCord52(filter12[2], 1, peak[2], 0);
AudioConnection          patchCord53(filter12[3], 1, peak[3], 0);
AudioConnection          patchCord54(filter12[4], 1, peak[4], 0);
AudioConnection          patchCord55(filter12[5], 1, peak[5], 0);
AudioConnection          patchCord56(filter12[6], 1, peak[6], 0);
AudioConnection          patchCord57(filter21[7], 1, filter22[7], 0);
AudioConnection          patchCord58(filter21[8], 1, filter22[8], 0);
AudioConnection          patchCord59(filter21[9], 1, filter22[9], 0);
AudioConnection          patchCord60(filter21[10], 1, filter22[10], 0);
AudioConnection          patchCord61(filter21[11], 1, filter22[11], 0);
AudioConnection          patchCord62(filter21[12], 2, filter22[12], 0);
AudioConnection          patchCord63(filter22[7], 1, mixer3, 2);
AudioConnection          patchCord64(filter22[8], 1, mixer3, 3);
AudioConnection          patchCord65(filter22[9], 1, mixer4, 2);
AudioConnection          patchCord66(filter22[10], 1, mixer4, 3);
AudioConnection          patchCord67(filter22[11], 1, mixer5, 2);
AudioConnection          patchCord68(filter22[12], 2, mixer5, 3);
AudioConnection          patchCord69(mixer3, 0, mixer6, 0);
AudioConnection          patchCord70(mixer4, 0, mixer6, 1);
AudioConnection          patchCord71(mixer5, 0, mixer6, 2);
AudioConnection          patchCord72(filter11[7], 1, filter12[7], 0);
AudioConnection          patchCord73(filter11[8], 1, filter12[8], 0);
AudioConnection          patchCord74(filter11[9], 1, filter12[9], 0);
AudioConnection          patchCord75(filter11[10], 1, filter12[10], 0);
AudioConnection          patchCord76(filter11[11], 1, filter12[11], 0);
AudioConnection          patchCord77(filter11[12], 2, filter12[12], 0);
AudioConnection          patchCord78(mixer6, 0, i2sout, 0);
AudioConnection          patchCord79(mixer6, 0, i2sout, 1);
AudioConnection          patchCord80(mixer6, peak3);
AudioConnection          patchCord81(filter12[7], 1, peak[7], 0);
AudioConnection          patchCord82(filter12[8], 1, peak[8], 0);
AudioConnection          patchCord83(filter12[9], 1, peak[9], 0);
AudioConnection          patchCord84(filter12[10], 1, peak[10], 0);
AudioConnection          patchCord85(filter12[11], 1, peak[11], 0);
AudioConnection          patchCord86(filter12[12], 2, peak[12], 0);
AudioControlSGTL5000     sgtl5000_1;

Metro timer1 = Metro(5);
Metro timer2 = Metro(1000);

void setup() {
  float freq;
  Serial.begin(9600);
  AudioMemory(50);
  sgtl5000_1.enable(); sgtl5000_1.volume(0.8); sgtl5000_1.unmuteLineout(); sgtl5000_1.lineOutLevel(29);
  sgtl5000_1.inputSelect(AUDIO_INPUT_LINEIN); sgtl5000_1.lineInLevel(5);
  noise1.amplitude(1); pink1.amplitude(1);
  mixer1.gain(0,1); mixer1.gain(1,0); mixer1.gain(2,0); mixer1.gain(3,0);
  mixer2.gain(0,0); mixer2.gain(1,0); mixer2.gain(2,1); mixer2.gain(3,0);
  mixer6.gain(0,5); mixer6.gain(1,5); mixer6.gain(2,5); mixer6.gain(3,0);
  for (byte c=1;c<=12;c++) {
    freq=50.0*pow(1000/50.0,(c-1)/11.0); Serial.print(freq); Serial.print(" - ");
    filter11[c].frequency(freq); filter11[c].resonance(1); filter11[c].octaveControl(1);
    filter12[c].frequency(freq); filter12[c].resonance(1); filter12[c].octaveControl(1);
    filter21[c].frequency(freq); filter21[c].resonance(1); filter21[c].octaveControl(1);
    filter22[c].frequency(freq); filter22[c].resonance(1); filter22[c].octaveControl(1); }
  delay(1000); Serial.println(""); }

void loop() {
  if (timer1.check() == 1) {
      mixer3.gain(0,peak[1].read()); mixer3.gain(1,peak[2].read()); mixer3.gain(2,peak[7].read()); mixer3.gain(3,peak[8].read());
      mixer4.gain(0,peak[3].read()); mixer4.gain(1,peak[4].read()); mixer4.gain(2,peak[9].read()); mixer4.gain(3,peak[10].read());
      mixer5.gain(0,peak[5].read()); mixer5.gain(1,peak[6].read()); mixer5.gain(2,peak[11].read()); mixer5.gain(3,peak[12].read()); }
  if (timer2.check() == 1) { Serial.print(peak1.read()); Serial.print(" - "); Serial.print(peak2.read()); Serial.print(" - "); Serial.print(peak3.read()); Serial.println(""); } }

void logUtil() {
  Serial.println(AudioMemoryUsage()); Serial.println(AudioMemoryUsageMax());
  Serial.println(AudioProcessorUsage()); Serial.println(AudioProcessorUsageMax()); }
