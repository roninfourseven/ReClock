#include <TinyWireM.h>   // I2C master library for ATtiny85

#define SI5351_ADDR 0x60
#define LED_PIN 1

// ClockBuilder Pro register dump
const uint8_t regs[][2] = {
  { 2, 0x53 },
{ 3, 0x00 },
{ 4, 0x20 },
{ 7, 0x00 },
{ 15, 0x00 },
{ 16, 0x0F },
{ 17, 0x8C },
{ 18, 0x8C },
{ 19, 0x8C },
{ 20, 0x8C },
{ 21, 0x8C },
{ 22, 0x8C },
{ 23, 0x8C },
{ 26, 0xEB },
{ 27, 0xC2 },
{ 28, 0x00 },
{ 29, 0x0F },
{ 30, 0xF2 },
{ 31, 0xB6 },
{ 32, 0x04 },
{ 33, 0x1C },
{ 42, 0x00 },
{ 43, 0x01 },
{ 44, 0x00 },
{ 45, 0x7C },
{ 46, 0x80 },
{ 47, 0x00 },
{ 48, 0x00 },
{ 49, 0x00 },
{ 90, 0x00 },
{ 91, 0x00 },
{ 149, 0x00 },
{ 150, 0x00 },
{ 151, 0x00 },
{ 152, 0x00 },
{ 153, 0x00 },
{ 154, 0x00 },
{ 155, 0x00 },
{ 162, 0x00 },
{ 163, 0x00 },
{ 164, 0x00 },
{ 165, 0x00 },
{ 183, 0x92 }

};

void writeReg(uint8_t reg, uint8_t val) {
    TinyWireM.beginTransmission(SI5351_ADDR);
    TinyWireM.write(reg);
    TinyWireM.write(val);
    TinyWireM.endTransmission();
}

void setup() {

    TinyWireM.begin();

    // Write all registers
    for (uint8_t i = 0; i < sizeof(regs)/2; i++) {
        writeReg(regs[i][0], regs[i][1]);
    }
    // Optional: reset PLLs (recommended by Silicon Labs)
    // Register 177: bit 7 = reset PLLA, bit 6 = reset PLLB
    // writeReg(177, 0xA0);

    // Done
}

void loop() {
    // Nothing to do but flash the LED to say done — ATtiny just configures the Si5351 once at boot
    digitalWrite(LED_PIN, LOW);   // LED ON
    delay(100);
    digitalWrite(LED_PIN, HIGH);  // LED OFF
    delay(100);
}
