#include <TinyWireM.h>   // I2C master library for ATtiny85

#define SI5351_ADDR 0x60
#define LED_PIN 1

// ClockBuilder Pro register dump
const uint8_t regs[][2] = {
    {2, 0x53},
    {3, 0x00},
    {4, 0x20},
    {7, 0x00},
    {15, 0x00},
    {16, 0x0F},
    {17, 0x0F},
    {18, 0x0F},
    {19, 0x8C},
    {20, 0x8C},
    {21, 0x8C},
    {22, 0x8C},
    {23, 0x8C},
    {26, 0xC3},
    {27, 0x50},
    {28, 0x00},
    {29, 0x0F},
    {30, 0x4A},
    {31, 0x00},
    {32, 0x66},
    {33, 0x60},
    {42, 0xB1},
    {43, 0xA1},
    {44, 0x00},
    {45, 0x77},
    {46, 0xE0},
    {47, 0x00},
    {48, 0x00},
    {49, 0xA0},
    {50, 0x00},
    {51, 0x01},
    {52, 0x00},
    {53, 0x5F},
    {54, 0x80},
    {55, 0x00},
    {56, 0x00},
    {57, 0x00},
    {58, 0xEC},
    {59, 0x8B},
    {60, 0x00},
    {61, 0x76},
    {62, 0xC3},
    {63, 0xA1},
    {64, 0xA9},
    {65, 0x1F},
    {90, 0x00},
    {91, 0x00},
    {149, 0x00},
    {150, 0x00},
    {151, 0x00},
    {152, 0x00},
    {153, 0x00},
    {154, 0x00},
    {155, 0x00},
    {162, 0x00},
    {163, 0x00},
    {164, 0x00},
    {165, 0x00},
    {166, 0x00},
    {167, 0x00},
    {183, 0x92}
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
