#include "TDA7439.h"
#include <Arduino.h>
#include <Wire.h>

TDA7439::TDA7439() {
  Wire.begin();
}

void TDA7439::selectInput(int input) {
  switch (input) {
    case 1: input = TDA7439_INPUT_1; break;
    case 2: input = TDA7439_INPUT_2; break;
    case 3: input = TDA7439_INPUT_3; break;
    case 4: input = TDA7439_INPUT_4; break;
  }

  writeWire(TDA7439_SELECT_INPUT, input);
}

void TDA7439::inputGain(int gain) {
  writeWire(TDA7439_SELECT_GAIN, gain);
}

void TDA7439::setVolume(int volume) {
  if (volume == 0) {
    volume = TDA7439_MUTE;
  } else {
    volume = 48 - volume;
  }
  
  writeWire(TDA7439_SELECT_VOLUME, volume);
}

void TDA7439::setBass(int val){
  setSnd(val, TDA7439_SELECT_BASS);
}

void TDA7439::setMiddle(int val){
  setSnd(val, TDA7439_SELECT_MIDDLE);
}

void TDA7439::setTrebble(int val){
  setSnd(val, TDA7439_SELECT_TREBBLE);
}

void TDA7439::mute() {
  writeWire(TDA7439_SELECT_VOLUME, TDA7439_MUTE);
}

void TDA7439::speakerAttenuation(int att) {
  writeWire(TDA7439_RIGHT_ATTENUATION, att);
  writeWire(TDA7439_LEFT_ATTENUATION, att);
}

void TDA7439::setSnd(int val, int range) {
  if(val <= 0){
    val = val + 7;
  }else{
    val = 15 - val;
  }

  writeWire(range, val);
}

void TDA7439::writeWire(char a, char b) {
  Wire.beginTransmission(TDA7439_ADDRESS);
  Wire.write(a);
  Wire.write(b);
  Wire.endTransmission();
}