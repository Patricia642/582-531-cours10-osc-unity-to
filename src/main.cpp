#include <Arduino.h>
#include <FastLED.h>
#include <MicroOscSlip.h>
MicroOscSlip<128> monOsc(&Serial);

// gestion du hub
#include <M5_PbHub.h>
M5_PbHub myPbHub;

#include <VL53L0X.h>
VL53L0X  myTOF;

//CRGB keyPixel;
CRGB atomPixel;

#define KEY_CHANNEL_ANGLE 0

void setup() {
    // NE JAMAIS OUBLIER !!!
    Serial.begin(115200);
    Wire.begin();
    myTOF.init();
    myPbHub.begin();

    FastLED.addLeds<WS2812, 27, GRB>(&atomPixel, 1);
    atomPixel = CRGB(255,0,0); // ROUGE
    FastLED.show();
    delay(1000); // PAUSE 1 SECONDE
    atomPixel = CRGB(255,255,0); // JAUNE
    FastLED.show();
    delay(1000); // PAUSE 1 SECONDE
    atomPixel = CRGB(0,255,0); // VERT
    FastLED.show();
    delay(1000); // PAUSE 1 SECONDE
    atomPixel = CRGB(0,0,0);
    FastLED.show(); // PAUSE 1 SECONDE



}

void loop() { 

    // oscslip key unit
    int mesure = myTOF.readRangeSingleMillimeters();
    monOsc.sendInt("/MESURE", mesure);

    // oscslip key unit
    int press = myPbHub.analogRead(KEY_CHANNEL_ANGLE);
    monOsc.sendInt("/ANGLE", press);
    delay(100);
}

