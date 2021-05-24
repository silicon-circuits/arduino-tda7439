#ifndef TDA7439_H
#define TDA7439_H

// Datasheet: 0x88 8bit address
// Wire.h appends the extra (lsb write) bit.
#define TDA7439_ADDRESS 0x44

#define TDA7439_SELECT_INPUT   0x00
#define TDA7439_SELECT_GAIN    0x01
#define TDA7439_SELECT_VOLUME  0x02
#define TDA7439_SELECT_BASS    0x03
#define TDA7439_SELECT_MIDDLE  0x04
#define TDA7439_SELECT_TREBBLE 0x05

#define TDA7439_RIGHT_ATTENUATION 0x06
#define TDA7439_LEFT_ATTENUATION  0x07

#define TDA7439_INPUT_1 0x03
#define TDA7439_INPUT_2 0x02
#define TDA7439_INPUT_3 0x01
#define TDA7439_INPUT_4 0x00
#define TDA7439_MUTE    0x38

#include <Arduino.h>
class TDA7439 {
  public:
  TDA7439();
  void selectInput(int input); // 1 to 4
  void inputGain(int gain); // 0 to 30
  void setVolume(int volume); // 0 to 48 ( 0 is mute)
  void setBass(int val); // -7 to 7
  void setMiddle(int val); // -7 to 7
  void setTrebble(int val); // -7 to 7
  void mute();
  void speakerAttenuation(int att); // 0 to 79 (db)
  private:
  void setSnd(int val, int range);
  void writeWire(char a, char b);
};

#endif //TDA7439_H