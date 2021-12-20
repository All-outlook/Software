#include <SPI.h>
unsigned char knob;
void setup() {
  // put your setup code here, to run once:
    SPCR |= bit(SPE);
  pinMode(MISO, OUTPUT);
  SPI.attachInterrupt();
  Serial.begin(38400);
}

void loop() {
  Serial.println(knob);
}

ISR(SPI_STC_vect) {
  knob = SPDR;
  SPDR = 78;
}
