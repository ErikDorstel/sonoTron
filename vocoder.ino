#include <Audio.h>
#include <Metro.h>

AudioInputI2S            i2sin;           
AudioOutputI2S           i2sout;           
AudioFilterStateVariable filter11[13];        
AudioFilterStateVariable filter21[13]; 
AudioFilterStateVariable filter12[13]; 
AudioFilterStateVariable filter22[13]; 
AudioAnalyzePeak         peak[13]; 
AudioMixer4              mixer1; 
AudioMixer4              mixer2; 
AudioMixer4              mixer3;         
AudioMixer4              mixer4; 
AudioConnection          patchCord1(i2sin, 0, filter11[1], 0);
AudioConnection          patchCord2(i2sin, 0, filter11[2], 0);
AudioConnection          patchCord3(i2sin, 0, filter11[3], 0);
AudioConnection          patchCord4(i2sin, 0, filter11[4], 0);
AudioConnection          patchCord5(i2sin, 0, filter11[5], 0);
AudioConnection          patchCord6(i2sin, 0, filter11[6], 0);
AudioConnection          patchCord7(i2sin, 0, filter11[12], 0);
AudioConnection          patchCord8(i2sin, 0, filter11[11], 0);
AudioConnection          patchCord9(i2sin, 0, filter11[10], 0);
AudioConnection          patchCord10(i2sin, 0, filter11[9], 0);
AudioConnection          patchCord11(i2sin, 0, filter11[8], 0);
AudioConnection          patchCord12(i2sin, 0, filter11[7], 0);
AudioConnection          patchCord13(i2sin, 1, filter21[1], 0);
AudioConnection          patchCord14(i2sin, 1, filter21[2], 0);
AudioConnection          patchCord15(i2sin, 1, filter21[3], 0);
AudioConnection          patchCord16(i2sin, 1, filter21[4], 0);
AudioConnection          patchCord17(i2sin, 1, filter21[5], 0);
AudioConnection          patchCord18(i2sin, 1, filter21[6], 0);
AudioConnection          patchCord19(i2sin, 1, filter21[7], 0);
AudioConnection          patchCord20(i2sin, 1, filter21[8], 0);
AudioConnection          patchCord21(i2sin, 1, filter21[9], 0);
AudioConnection          patchCord22(i2sin, 1, filter21[10], 0);
AudioConnection          patchCord23(i2sin, 1, filter21[11], 0);
AudioConnection          patchCord24(i2sin, 1, filter21[12], 0);
AudioConnection          patchCord25(filter11[1], 0, filter12[1], 0);
AudioConnection          patchCord26(filter11[2], 1, filter12[2], 0);
AudioConnection          patchCord27(filter11[3], 1, filter12[3], 0);
AudioConnection          patchCord28(filter11[4], 1, filter12[4], 0);
AudioConnection          patchCord29(filter11[5], 1, filter12[5], 0);
AudioConnection          patchCord30(filter11[6], 1, filter12[6], 0);
AudioConnection          patchCord31(filter21[1], 0, filter22[1], 0);
AudioConnection          patchCord32(filter21[2], 1, filter22[2], 0);
AudioConnection          patchCord33(filter21[3], 1, filter22[3], 0);
AudioConnection          patchCord34(filter21[4], 1, filter22[4], 0);
AudioConnection          patchCord35(filter21[5], 1, filter22[5], 0);
AudioConnection          patchCord36(filter21[6], 1, filter22[6], 0);
AudioConnection          patchCord37(filter12[1], 0, peak[1], 0);
AudioConnection          patchCord38(filter12[2], 1, peak[2], 0);
AudioConnection          patchCord39(filter12[3], 1, peak[3], 0);
AudioConnection          patchCord40(filter12[4], 1, peak[4], 0);
AudioConnection          patchCord41(filter12[5], 1, peak[5], 0);
AudioConnection          patchCord42(filter12[6], 1, peak[6], 0);
AudioConnection          patchCord43(filter22[1], 0, mixer1, 0);
AudioConnection          patchCord44(filter22[2], 1, mixer1, 1);
AudioConnection          patchCord45(filter22[3], 1, mixer2, 0);
AudioConnection          patchCord46(filter22[4], 1, mixer2, 1);
AudioConnection          patchCord47(filter22[5], 1, mixer3, 0);
AudioConnection          patchCord48(filter22[6], 1, mixer3, 1);
AudioConnection          patchCord49(filter21[7], 1, filter22[7], 0);
AudioConnection          patchCord50(filter21[8], 1, filter22[8], 0);
AudioConnection          patchCord51(filter21[9], 1, filter22[9], 0);
AudioConnection          patchCord52(filter21[10], 1, filter22[10], 0);
AudioConnection          patchCord53(filter21[11], 1, filter22[11], 0);
AudioConnection          patchCord54(filter21[12], 2, filter22[12], 0);
AudioConnection          patchCord55(filter22[7], 1, mixer1, 2);
AudioConnection          patchCord56(filter22[8], 1, mixer1, 3);
AudioConnection          patchCord57(filter22[9], 1, mixer2, 2);
AudioConnection          patchCord58(filter22[10], 1, mixer2, 3);
AudioConnection          patchCord59(filter22[11], 1, mixer3, 2);
AudioConnection          patchCord60(filter22[12], 2, mixer3, 3);
AudioConnection          patchCord61(filter11[7], 1, filter12[7], 0);
AudioConnection          patchCord62(filter11[8], 1, filter12[8], 0);
AudioConnection          patchCord63(filter11[9], 1, filter12[9], 0);
AudioConnection          patchCord64(filter11[10], 1, filter12[10], 0);
AudioConnection          patchCord65(filter11[11], 1, filter12[11], 0);
AudioConnection          patchCord66(filter11[12], 2, filter12[12], 0);
AudioConnection          patchCord67(mixer2, 0, mixer4, 1);
AudioConnection          patchCord68(mixer3, 0, mixer4, 2);
AudioConnection          patchCord69(mixer1, 0, mixer4, 0);
AudioConnection          patchCord70(filter12[7], 1, peak[7], 0);
AudioConnection          patchCord71(filter12[8], 1, peak[8], 0);
AudioConnection          patchCord72(filter12[9], 1, peak[9], 0);
AudioConnection          patchCord73(filter12[10], 1, peak[10], 0);
AudioConnection          patchCord74(filter12[11], 1, peak[11], 0);
AudioConnection          patchCord75(filter12[12], 2, peak[12], 0);
AudioConnection          patchCord76(mixer4, 0, i2sout, 0);
AudioConnection          patchCord77(mixer4, 0, i2sout, 1);
AudioControlSGTL5000     sgtl5000_1;

Metro timer = Metro(5);

void setup() {
  float freq;
  Serial.begin(9600);
  AudioMemory(50);
  sgtl5000_1.enable(); sgtl5000_1.volume(0.8); sgtl5000_1.unmuteLineout(); sgtl5000_1.lineOutLevel(29);
  sgtl5000_1.inputSelect(AUDIO_INPUT_LINEIN); sgtl5000_1.lineInLevel(5);
  mixer4.gain(0,0.33); mixer4.gain(1,0.33); mixer4.gain(2,0.33); mixer4.gain(3,0);
  for (byte c=1;c<=12;c++) {
    freq=50.0*pow(4000/50.0,(c-1)/11.0);
    filter11[c].frequency(freq); filter11[c].resonance(1); filter11[c].octaveControl(1);
    filter12[c].frequency(freq); filter12[c].resonance(1); filter12[c].octaveControl(1);
    filter21[c].frequency(freq); filter21[c].resonance(1); filter21[c].octaveControl(1);
    filter22[c].frequency(freq); filter22[c].resonance(1); filter22[c].octaveControl(1); }
  delay(1000); }

void loop() {
  if (timer.check() == 1) {
      mixer1.gain(0,peak[1].read()); mixer1.gain(1,peak[2].read()); mixer1.gain(2,peak[7].read()); mixer1.gain(3,peak[8].read());
      mixer2.gain(0,peak[3].read()); mixer2.gain(1,peak[4].read()); mixer2.gain(2,peak[9].read()); mixer2.gain(3,peak[10].read());
      mixer3.gain(0,peak[5].read()); mixer3.gain(1,peak[6].read()); mixer3.gain(2,peak[11].read()); mixer3.gain(3,peak[12].read()); } }

void logUtil() {
  Serial.println(AudioMemoryUsage()); Serial.println(AudioMemoryUsageMax());
  Serial.println(AudioProcessorUsage()); Serial.println(AudioProcessorUsageMax()); }
