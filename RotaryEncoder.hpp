#ifndef _ROTARY_ENCODER_H
#define _ROTARY_ENCODER_H

class RotaryEncoder {
private:
  uint8_t pin1;
  uint8_t pin2;
  byte sample = 0;
  int8_t count = 0;

  public:
    int8_t value;

    RotaryEncoder();
    void begin(uint8_t pin1, uint8_t pin2);

    void loop();

};

#endif
