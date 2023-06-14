#include <FastLED.h>
#include "M5Atom.h"
#include <esp_sleep.h>
#include <esp_deep_sleep.h>

const int buttonPin = 39; // Broche GPIO utilisée pour le bouton

volatile bool shouldWakeUp = false; // Variable de contrôle pour sortir du mode sleep

// How many leds in your strip?
#define NUM_LEDS 20
#define BRIGHTNESS  100

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define DATA_PIN 26
#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];
CRGB couleur = CRGB(0, 0, 0);

void setup() {
  M5.begin(true, false, true);

  Serial.begin(1500000);
  delay(300);

  Serial.println("Setup");

  uint32_t ui32XtalFreq = getXtalFrequencyMhz(); // In MHz
  uint32_t ui32CpuFreq  = getCpuFrequencyMhz();  // In MHz
  uint32_t ui32ApbFreq  = getApbFrequency();     // In Hz

  Serial.print("Frequence horloge:");
  Serial.println(ui32XtalFreq);
  Serial.print("frequence du CPU:");
  Serial.println(ui32CpuFreq);
  Serial.print("Frequence du bus APB:");
  Serial.println(ui32ApbFreq);

  //change frequency 80MHz, 120 240
  Serial.print("Changement frequence CPU a 240MHz:");
  bool boolCpuFreq = false;
  boolCpuFreq = setCpuFrequencyMhz(80);
  Serial.println(boolCpuFreq);

  ui32XtalFreq = getXtalFrequencyMhz(); // In MHz
  ui32CpuFreq  = getCpuFrequencyMhz();  // In MHz
  ui32ApbFreq  = getApbFrequency();     // In Hz

  Serial.print("Frequence horloge:");
  Serial.println(ui32XtalFreq);
  Serial.print("frequence du CPU:");
  Serial.println(ui32CpuFreq);
  Serial.print("Frequence du bus APB:");
  Serial.println(ui32ApbFreq);

  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
  FastLED.setBrightness( BRIGHTNESS );

  //wakeup
  pinMode(buttonPin, INPUT);
  //attachInterrupt(digitalPinToInterrupt(buttonPin), wakeUp, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(buttonPin), enterSleep, CHANGE);
  //touchAttachInterrupt(digitalPinToInterrupt(buttonPin), enterSleep, CHANGE);

  uint64_t pinBitMask = 0x0000000800000000; // Masque de bits pour la broche 39
  //esp_sleep_enable_ext1_wakeup(pinBitMask, ESP_EXT1_WAKEUP_ANY_HIGH); // Activer le réveil externe sur la broche 39
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_39, 0); // Activer le réveil externe sur la broche 39

  //esp_sleep_enable_ext0_wakeup(GPIO_NUM_39, 0);
}

int i = 0;
int cas = 2;
int ledLevelBaseVeilleRed = 30;
int ledLevelBaseVeilleGreen = 0;
int ledLevelBaseVeilleBlue = 0;


int ledLevelEmotionRed = 255;
int ledLevelEmotionGreen = 0;
int ledLevelEmotionBlue = 0;

void loop() {

  Serial.println("loop");
  shouldWakeUp = true;
  if (shouldWakeUp) {

    shouldWakeUp = false;
    // Effectuer les actions nécessaires pour arrêter le mode sleep
    shouldWakeUp = false; // Réinitialiser la variable de contrôle

    cas++;
    Serial.print("cas n°");
    if (cas > 9)cas = 0;
    Serial.println(cas);

    // Exemple : Imprimer un message après la sortie du mode sleep
    Serial.println("Sortie du mode sleep");

    switch (cas) {
      case 0:
        //nothing
        break;
      case 1:
        //all off
        for (i = 0; i < NUM_LEDS; i++)
        {
          leds[i] = CRGB::Black;
        }
        FastLED.show();
        delay(1000);
        break;
      case 2:
        //red base haut 1
        for (i = 0; i < NUM_LEDS; i++)
        {
          leds[i] = CRGB::Black;
        }
        for (i = 0; i < 4; i++)
        {
          couleur = CRGB(ledLevelBaseVeilleRed, ledLevelBaseVeilleGreen, ledLevelBaseVeilleBlue);
          leds[i] = couleur;
        }

        couleur = CRGB(ledLevelEmotionRed, ledLevelEmotionGreen, ledLevelEmotionBlue);
        leds[4] = couleur;

        FastLED.show();
        delay(1000);
        break;
      case 3:
        //red base haut 1
        for (i = 0; i < NUM_LEDS; i++)
        {
          leds[i] = CRGB::Black;
        }
        for (i = 0; i < 4; i++)
        {
          couleur = CRGB(ledLevelBaseVeilleRed, ledLevelBaseVeilleGreen, ledLevelBaseVeilleBlue);
          leds[i] = couleur;
        }


        couleur = CRGB(ledLevelEmotionRed, ledLevelEmotionGreen, ledLevelEmotionBlue);
        leds[6] = couleur;

        FastLED.show();
        delay(1000);
        break;
      case 4:
        //red base haut 1
        for (i = 0; i < NUM_LEDS; i++)
        {
          leds[i] = CRGB::Black;
        }
        for (i = 0; i < 4; i++)
        {
          couleur = CRGB(ledLevelBaseVeilleRed, ledLevelBaseVeilleGreen, ledLevelBaseVeilleBlue);
          leds[i] = couleur;
        }
        couleur = CRGB(ledLevelEmotionRed, ledLevelEmotionGreen, ledLevelEmotionBlue);
        leds[8] = couleur;

        FastLED.show();
        delay(1000);
        break;
      case 5:
        //red base haut 1
        for (i = 0; i < NUM_LEDS; i++)
        {
          leds[i] = CRGB::Black;
        }
        for (i = 0; i < 4; i++)
        {
          couleur = CRGB(ledLevelBaseVeilleRed, ledLevelBaseVeilleGreen, ledLevelBaseVeilleBlue);
          leds[i] = couleur;
        }


        couleur = CRGB(ledLevelEmotionRed, ledLevelEmotionGreen, ledLevelEmotionBlue);
        leds[10] = couleur;

        FastLED.show();
        delay(1000);
        break;
      case 6:
        //red base haut 1
        for (i = 0; i < NUM_LEDS; i++)
        {
          leds[i] = CRGB::Black;
        }
        for (i = 0; i < 4; i++)
        {
          couleur = CRGB(ledLevelBaseVeilleRed, ledLevelBaseVeilleGreen, ledLevelBaseVeilleBlue);
          leds[i] = couleur;
        }


        couleur = CRGB(ledLevelEmotionRed, ledLevelEmotionGreen, ledLevelEmotionBlue);
        leds[12] = couleur;

        FastLED.show();
        delay(1000);
        break;
      case 7:
        //red base haut 1
        for (i = 0; i < NUM_LEDS; i++)
        {
          leds[i] = CRGB::Black;
        }
        for (i = 0; i < 4; i++)
        {
          couleur = CRGB(ledLevelBaseVeilleRed, ledLevelBaseVeilleGreen, ledLevelBaseVeilleBlue);
          leds[i] = couleur;
        }


        couleur = CRGB(ledLevelEmotionRed, ledLevelEmotionGreen, ledLevelEmotionBlue);
        leds[14] = couleur;

        FastLED.show();
        delay(1000);
        break;
      case 8:
        //red base haut 1
        for (i = 0; i < NUM_LEDS; i++)
        {
          leds[i] = CRGB::Black;
        }
        for (i = 0; i < 4; i++)
        {
          couleur = CRGB(ledLevelBaseVeilleRed, ledLevelBaseVeilleGreen, ledLevelBaseVeilleBlue);
          leds[i] = couleur;
        }


        couleur = CRGB(ledLevelEmotionRed, ledLevelEmotionGreen, ledLevelEmotionBlue);
        leds[16] = couleur;

        FastLED.show();
        delay(1000);
        break;

      case 9:
        //red base haut 1
        for (i = 0; i < NUM_LEDS; i++)
        {
          leds[i] = CRGB::Black;
        }
        for (i = 0; i < 4; i++)
        {
          couleur = CRGB(ledLevelBaseVeilleRed, ledLevelBaseVeilleGreen, ledLevelBaseVeilleBlue);
          leds[i] = couleur;
        }


        couleur = CRGB(ledLevelEmotionRed, ledLevelEmotionGreen, ledLevelEmotionBlue);
        leds[18] = couleur;

        FastLED.show();
        delay(1000);
        break;

      default:
        break;
    }
  }

  //Serial.println("deep sleep");
  //esp_deep_sleep_start();
  // Entrer en mode sleep
  Serial.println("deep sleep");
  //esp_deep_sleep_start();
  esp_light_sleep_start();

}


void wakeUp() {
  shouldWakeUp = true;
}

void enterSleep() {
  //detachInterrupt(buttonInterrupt); // Détacher l'interruption du bouton
  Serial.println("bouton change");
  // Code pour préparer l'entrée en mode sleep
  // ...

  shouldWakeUp = true;

  // Entrer en mode sleep
  //Serial.println("deep sleep fct enterSleep");
  //esp_deep_sleep_start();
}
