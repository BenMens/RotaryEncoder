#include <RotaryEncoder.hpp>


RotaryEncoder encoder = RotaryEncoder();

void setup() {
  Serial.begin(115200);
  Serial.println("Started");

  encoder.begin(9, 10);
}


void loop() {

  encoder.loop();

  for (;encoder.value > 0; encoder.value--) {
      Serial.println(encoder.value);
  }

  for (;encoder.value < 0; encoder.value++) {
    Serial.println(encoder.value);
  }

}
