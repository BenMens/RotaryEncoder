#include "RotaryEncoder.hpp"

#include <arduino.h>

RotaryEncoder::RotaryEncoder() {}

void RotaryEncoder::begin(uint8_t pin1, uint8_t pin2, bool halfRes)
{
    this->pin1 = pin1;
    this->pin2 = pin2;
    this->halfRes = halfRes;

    this->value = 0;

    pinMode(pin1, INPUT);
    pinMode(pin2, INPUT);
}

void RotaryEncoder::loop()
{
    uint8_t sample = this->sample;

    sample =
        (sample << 2) + digitalRead(this->pin1) * 2 + digitalRead(this->pin2);
    sample &= 0x0f;

    this->sample = sample;

    switch (sample) {
        case 13:
        case 2:
        case 4:
        case 11:
            this->count++;
            break;
        case 14:
        case 8:
        case 1:
        case 7:
            this->count--;
            break;
    }

    if (halfRes) {
        if ((sample & 3) == 3 || (sample & 3) == 0) {
            if (this->count >= 2) {
                this->value--;
            } else if (this->count <= -2) {
                this->value++;
            }

            this->count = 0;
        }
    } else {
        if ((sample & 3) == 3) {
            if (this->count >= 3) {
                this->value--;
            } else if (this->count <= -3) {
                this->value++;
            }

            this->count = 0;
        }
    }
}
