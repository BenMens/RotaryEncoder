#ifndef _ROTARY_ENCODER_H
#define _ROTARY_ENCODER_H

#include <stdint.h>
class RotaryEncoder
{
   private:
    uint8_t pin1;
    uint8_t pin2;
    uint8_t sample = 0;
    int8_t count = 0;
    bool halfRes;

   public:
    int8_t value;

    RotaryEncoder();
    void begin(uint8_t pin1, uint8_t pin2, bool halfRes = false);

    void loop();
};

#endif
