//lien : https://randomnerdtutorials.com/esp32-deep-sleep-arduino-ide-wake-up-sources/

#include <FastLED.h>
#include "M5Atom.h"
#include <esp_sleep.h>

const int buttonPin = 39; // Broche GPIO utilisée pour le bouton

volatile bool shouldWakeUp = false; // Variable de contrôle pour sortir du mode sleep

// How many leds in your strip?
#define NUM_LEDS 20
#define BRIGHTNESS  255

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define DATA_PIN 26
#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];
CRGB couleur = CRGB(0, 0, 0);

//function declaration
void modeLed(int levLed, int iconLight, int lightMandalou);


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
int cas = 0;
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
    if (cas > 65)cas = 0;
    Serial.println(cas);

    // Exemple : Imprimer un message après la sortie du mode sleep
    Serial.println("Sortie du mode sleep");

    switch (cas) {

//icone only
      case 0:  
        modeLed(0, 0, 0);  //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 1:  
        modeLed(20, 1, 0); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 2: 
        modeLed(40, 1, 0); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 3: 
        modeLed(60, 1, 0); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 4: 
        modeLed(80, 1, 0); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 5: 
        modeLed(100, 1, 0); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 6: 
        modeLed(120, 1, 0); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 7: 
        modeLed(140, 1, 0); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 8: 
        modeLed(160, 1, 0); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 9: 
        modeLed(180, 1, 0); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 10: 
        modeLed(200, 1, 0); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 11: 
        modeLed(220, 1, 0); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 12: 
        modeLed(240, 1, 0); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 13:
        modeLed(255, 1, 0); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;

//icone white
      case 14:  
        modeLed(0, 0, 1);  //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 15:  
        modeLed(20, 1, 1); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 16: 
        modeLed(40, 1, 1); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 17: 
        modeLed(60, 1, 1); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 18: 
        modeLed(80, 1, 1); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 19: 
        modeLed(100, 1, 1); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 20: 
        modeLed(120, 1, 1); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 21: 
        modeLed(140, 1, 1); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 22: 
        modeLed(160, 1, 1); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 23: 
        modeLed(180, 1, 1); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 24: 
        modeLed(200, 1, 1); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 25: 
        modeLed(220, 1, 1); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 26: 
        modeLed(240, 1, 1); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 27:
        modeLed(255, 1, 1); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;

//icone green

      case 28:  
        modeLed(0, 0, 2);  //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 29:  
        modeLed(20, 1, 2); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 30: 
        modeLed(40, 1, 2); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 31: 
        modeLed(60, 1, 2); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 32: 
        modeLed(80, 1, 2); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 33: 
        modeLed(100, 1, 2); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 34: 
        modeLed(120, 1, 2); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 35: 
        modeLed(140, 1, 2); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 36: 
        modeLed(160, 1, 2); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 37: 
        modeLed(180, 1, 2); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 38: 
        modeLed(200, 1, 2); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 39: 
        modeLed(220, 1, 2); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 40: 
        modeLed(240, 1, 2); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 41:
        modeLed(255, 1, 2); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;

//no icone white
      case 42:  
        modeLed(0, 0, 1);  //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 43:  
        modeLed(20, 0, 1); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 44: 
        modeLed(40, 0, 1); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 45: 
        modeLed(60, 0, 1); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 46: 
        modeLed(80, 0, 1); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 47: 
        modeLed(100, 0, 1); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 48: 
        modeLed(120, 0, 1); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 49: 
        modeLed(140, 0, 1); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 50: 
        modeLed(160, 0, 1); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 51: 
        modeLed(180, 0, 1); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 52: 
        modeLed(200, 0, 1); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 53: 
        modeLed(220, 0, 1); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 54: 
        modeLed(240, 0, 1); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 55:
        modeLed(255, 0, 1); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;

//no icone green

      case 56:  
        modeLed(0, 0, 2);  //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 57:  
        modeLed(20, 0, 2); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 58: 
        modeLed(40, 0, 2); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 59: 
        modeLed(60, 0, 2); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 60: 
        modeLed(80, 0, 2); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 61: 
        modeLed(100, 0, 2); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 62: 
        modeLed(120, 0, 2); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 63: 
        modeLed(140, 0, 2); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 64: 
        modeLed(160, 0, 2); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 65: 
        modeLed(180, 0, 2); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 66: 
        modeLed(200, 0, 2); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 67: 
        modeLed(220, 0, 2); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 68: 
        modeLed(240, 0, 2); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;
      case 69:
        modeLed(255, 0, 2); //modeLed(levLed,iconLight,lightMandalou 0:off 1:White 2:Green)
        break;


      default:
        Serial.println("probleme indexation led");
        break;
    }
  }

  delay(1000);  //debounce
  Serial.println("deep sleep");
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


void modeLed(int levLed, int iconLight, int lightMandalou)
{
  //all off
  for (i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB::Black;
  }

  //icone white green red,blue
  if (iconLight == 1)
  {
    leds[0] = CRGB(levLed , levLed , levLed); //white
    leds[1] = CRGB(0, levLed , 0); //vert
    leds[2] = CRGB(levLed , 0, 0); //rouge
    leds[3] = CRGB(0, 0, levLed); //bleu
  }

  //icone bas 4 led
  if (lightMandalou == 1)
  {
    leds[4] = CRGB(levLed , levLed , levLed ); //white 0->100%
    leds[8] = CRGB(levLed , levLed , levLed ); //white 0->100%
    leds[12] = CRGB(levLed , levLed , levLed ); //white 0->100%
    leds[16] = CRGB(levLed , levLed , levLed ); //white 0->100%
  }

  //icone bas 4 led
  if (lightMandalou == 2)
  {
    leds[4] = CRGB(0 , levLed , 0 ); //green 0->100%
    leds[8] = CRGB(0 , levLed , 0 ); //green 0->100%
    leds[12] = CRGB(0 , levLed , 0 ); //green 0->100%
    leds[16] = CRGB(0 , levLed , 0 ); //green 0->100%
  }
  FastLED.show();
  delay(10);
}
