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


//variables

int incCas = 0;
int incLight = 0;
int nmled = 0;
int iconActive = 0;  //0:off 1:white 2:red 3:green 4:blue

int flipButton = 0;

#define PERIOD_WAIT_BUTTON 500

unsigned long nowTimeMillis = 0;
unsigned long updateTimeButton = 0;

//function declaration
void modeLed(int levLed, int iconLight, int lightMandalou, int nbled );
void testLed();



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

  nowTimeMillis = millis();

  Serial.println("loop");
  shouldWakeUp = true;
  //if (shouldWakeUp) {

  if (nowTimeMillis > updateTimeButton )
  {
    updateTimeButton = nowTimeMillis + PERIOD_WAIT_BUTTON;

    if (flipButton == 0) {


      shouldWakeUp = false;
      // Effectuer les actions nécessaires pour arrêter le mode sleep
      shouldWakeUp = false; // Réinitialiser la variable de contrôle

      cas++;
      Serial.print("cas n°");
      if (cas > 652)cas = 0;
      Serial.println(cas);

      // Exemple : Imprimer un message après la sortie du mode sleep
      Serial.println("Sortie du mode sleep");

      incCas = 0;

      //*********************************************************************************************************************
      /*
        .__                                 ________  ______________________
        |  | _____    _____ ______   ____   \_____  \ \_   _____/\_   _____/
        |  | \__  \  /     \\____ \_/ __ \   /   |   \ |    __)   |    __)
        |  |__/ __ \|  Y Y  \  |_> >  ___/  /    |    \|     \    |     \
        |____(____  /__|_|  /   __/ \___  > \_______  /\___  /    \___  /
                \/      \/|__|        \/          \/     \/         \/
      */
      //*********************************************************************************************************************
      //white
      // veilleuse off led 1 icone white
      incLight = 0;
      nmled = 4;
      iconActive = 1;  //0:off 1:white 2:red 3:green 4:blue
      int lightActive = 0; //0:off 1:white 2:green
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);



      // 14 etape par cas
      // veilleuse off led 2 icone white
      incLight = 0;
      nmled = 5;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);


      // veilleuse off led 3 icone white
      incLight = 0;
      nmled = 6;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);


      // veilleuse off led 4 icone white
      incLight = 0;
      nmled = 7;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);



      //****************************************************************************************************************
      //red
      // veilleuse off led 1 icone white
      incLight = 0;
      nmled = 4;
      iconActive = 2;  //0:off 1:white 2:red 3:green 4:blue
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);



      // 14 etape par cas
      // veilleuse off led 2 icone white
      incLight = 0;
      nmled = 5;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);


      // veilleuse off led 3 icone white
      incLight = 0;
      nmled = 6;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);


      // veilleuse off led 4 icone white
      incLight = 0;
      nmled = 7;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);






      //****************************************************************************************************************
      //green
      // veilleuse off led 1 icone white
      incLight = 0;
      nmled = 4;
      iconActive = 3;  //0:off 1:white 2:red 3:green 4:blue
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);



      // 14 etape par cas
      // veilleuse off led 2 icone white
      incLight = 0;
      nmled = 5;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);


      // veilleuse off led 3 icone white
      incLight = 0;
      nmled = 6;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);


      // veilleuse off led 4 icone white
      incLight = 0;
      nmled = 7;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);






      //****************************************************************************************************************
      //blue
      // veilleuse off led 1 icone white
      incLight = 0;
      nmled = 4;
      iconActive = 4;  //0:off 1:white 2:red 3:green 4:blue
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);



      // 14 etape par cas
      // veilleuse off led 2 icone white
      incLight = 0;
      nmled = 5;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);


      // veilleuse off led 3 icone white
      incLight = 0;
      nmled = 6;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);


      // veilleuse off led 4 icone white
      incLight = 0;
      nmled = 7;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);







      //*********************************************************************************************************************
      /*
        .__                                 __________.____       _____    _______  _________   ___ ______________
        |  | _____    _____ ______   ____   \______   \    |     /  _  \   \      \ \_   ___ \ /   |   \_   _____/
        |  | \__  \  /     \\____ \_/ __ \   |    |  _/    |    /  /_\  \  /   |   \/    \  \//    ~    \    __)_
        |  |__/ __ \|  Y Y  \  |_> >  ___/   |    |   \    |___/    |    \/    |    \     \___\    Y    /        \
        |____(____  /__|_|  /   __/ \___  >  |______  /_______ \____|__  /\____|__  /\______  /\___|_  /_______  /
                \/      \/|__|        \/          \/        \/       \/         \/        \/       \/        \/
      */
      //*********************************************************************************************************************
      //white
      // veilleuse off led 1 icone white
      incLight = 0;
      nmled = 4;
      iconActive = 1;  //0:off 1:white 2:red 3:green 4:blue
      lightActive = 1; //0:off 1:white 2:green
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);



      // 14 etape par cas
      // veilleuse off led 2 icone white
      incLight = 0;
      nmled = 5;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);


      // veilleuse off led 3 icone white
      incLight = 0;
      nmled = 6;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);


      // veilleuse off led 4 icone white
      incLight = 0;
      nmled = 7;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);



      //****************************************************************************************************************
      //red
      // veilleuse off led 1 icone white
      incLight = 0;
      nmled = 4;
      iconActive = 2;  //0:off 1:white 2:red 3:green 4:blue
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);



      // 14 etape par cas
      // veilleuse off led 2 icone white
      incLight = 0;
      nmled = 5;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);


      // veilleuse off led 3 icone white
      incLight = 0;
      nmled = 6;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);


      // veilleuse off led 4 icone white
      incLight = 0;
      nmled = 7;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);






      //****************************************************************************************************************
      //green
      // veilleuse off led 1 icone white
      incLight = 0;
      nmled = 4;
      iconActive = 3;  //0:off 1:white 2:red 3:green 4:blue
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);



      // 14 etape par cas
      // veilleuse off led 2 icone white
      incLight = 0;
      nmled = 5;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);


      // veilleuse off led 3 icone white
      incLight = 0;
      nmled = 6;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);


      // veilleuse off led 4 icone white
      incLight = 0;
      nmled = 7;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);






      //****************************************************************************************************************
      //blue
      // veilleuse off led 1 icone white
      incLight = 0;
      nmled = 4;
      iconActive = 4;  //0:off 1:white 2:red 3:green 4:blue
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);



      // 14 etape par cas
      // veilleuse off led 2 icone white
      incLight = 0;
      nmled = 5;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);


      // veilleuse off led 3 icone white
      incLight = 0;
      nmled = 6;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);


      // veilleuse off led 4 icone white
      incLight = 0;
      nmled = 7;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);








      //*********************************************************************************************************************
      /*
        .__                                 ____   _______________________________________________
        |  | _____    _____ ______   ____   \   \ /   /\_   _____/\______   \__    ___/\_   _____/
        |  | \__  \  /     \\____ \_/ __ \   \   Y   /  |    __)_  |       _/ |    |    |    __)_
        |  |__/ __ \|  Y Y  \  |_> >  ___/    \     /   |        \ |    |   \ |    |    |        \
        |____(____  /__|_|  /   __/ \___  >    \___/   /_______  / |____|_  / |____|   /_______  /
                \/      \/|__|        \/                     \/         \/                   \/
      */
      //*********************************************************************************************************************
      //green
      // veilleuse off led 1 icone white
      incLight = 0;
      nmled = 4;
      iconActive = 1;  //0:off 1:white 2:red 3:green 4:blue
      lightActive = 2; //0:off 1:white 2:green
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);



      // 14 etape par cas
      // veilleuse off led 2 icone white
      incLight = 0;
      nmled = 5;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);


      // veilleuse off led 3 icone white
      incLight = 0;
      nmled = 6;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);


      // veilleuse off led 4 icone white
      incLight = 0;
      nmled = 7;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);



      //****************************************************************************************************************
      //red
      // veilleuse off led 1 icone white
      incLight = 0;
      nmled = 4;
      iconActive = 2;  //0:off 1:white 2:red 3:green 4:blue
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);



      // 14 etape par cas
      // veilleuse off led 2 icone white
      incLight = 0;
      nmled = 5;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);


      // veilleuse off led 3 icone white
      incLight = 0;
      nmled = 6;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);


      // veilleuse off led 4 icone white
      incLight = 0;
      nmled = 7;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);






      //****************************************************************************************************************
      //green
      // veilleuse off led 1 icone white
      incLight = 0;
      nmled = 4;
      iconActive = 3;  //0:off 1:white 2:red 3:green 4:blue
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);



      // 14 etape par cas
      // veilleuse off led 2 icone white
      incLight = 0;
      nmled = 5;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);


      // veilleuse off led 3 icone white
      incLight = 0;
      nmled = 6;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);


      // veilleuse off led 4 icone white
      incLight = 0;
      nmled = 7;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);






      //****************************************************************************************************************
      //blue
      // veilleuse off led 1 icone white
      incLight = 0;
      nmled = 4;
      iconActive = 4;  //0:off 1:white 2:red 3:green 4:blue
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);



      // 14 etape par cas
      // veilleuse off led 2 icone white
      incLight = 0;
      nmled = 5;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);


      // veilleuse off led 3 icone white
      incLight = 0;
      nmled = 6;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);


      // veilleuse off led 4 icone white
      incLight = 0;
      nmled = 7;  //4-7
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);





      //*********************************************************************************************************************
      /*
        .__                                 ____   _______________________________________________               .__
        |  | _____    _____ ______   ____   \   \ /   /\_   _____/\______   \__    ___/\_   _____/   ____   ____ |  | ___.__.
        |  | \__  \  /     \\____ \_/ __ \   \   Y   /  |    __)_  |       _/ |    |    |    __)_   /  _ \ /    \|  |<   |  |
        |  |__/ __ \|  Y Y  \  |_> >  ___/    \     /   |        \ |    |   \ |    |    |        \ (  <_> )   |  \  |_\___  |
        |____(____  /__|_|  /   __/ \___  >    \___/   /_______  / |____|_  / |____|   /_______  /  \____/|___|  /____/ ____|
                  \/      \/|__|        \/                     \/         \/                   \/              \/     \/
      */
      //*********************************************************************************************************************
      //green
      // veilleuse off led 1 icone white
      incLight = 0;
      nmled = 0;
      iconActive = 0;  //0:off 1:white 2:red 3:green 4:blue
      lightActive = 2; //0:off 1:white 2:green
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);








      //*********************************************************************************************************************
      /*
.__                                 __________.____       _____    _______  _________   ___ ______________               .__         
|  | _____    _____ ______   ____   \______   \    |     /  _  \   \      \ \_   ___ \ /   |   \_   _____/   ____   ____ |  | ___.__.
|  | \__  \  /     \\____ \_/ __ \   |    |  _/    |    /  /_\  \  /   |   \/    \  \//    ~    \    __)_   /  _ \ /    \|  |<   |  |
|  |__/ __ \|  Y Y  \  |_> >  ___/   |    |   \    |___/    |    \/    |    \     \___\    Y    /        \ (  <_> )   |  \  |_\___  |
|____(____  /__|_|  /   __/ \___  >  |______  /_______ \____|__  /\____|__  /\______  /\___|_  /_______  /  \____/|___|  /____/ ____|
          \/      \/|__|        \/          \/        \/       \/         \/        \/       \/        \/              \/     \/     
      */
      //*********************************************************************************************************************
      //green
      // veilleuse off led 1 icone white
      incLight = 0;
      nmled = 0;
      iconActive = 0;  //0:off 1:white 2:red 3:green 4:blue
      lightActive = 1; //0:off 1:white 2:green
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = incLight + 20;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);
      incCas++;
      incLight = 255;
      if (cas == incCas) modeLed(incLight, iconActive, lightActive, nmled);



    }

  }


  Serial.print("increment:");
  Serial.println(incCas);
  //delay(500);  //debounce
  //Serial.println("deep sleep");
  //esp_light_sleep_start();

  //debug evite appui bouton
  if (M5.Btn.wasPressed()) {
    flipButton++;
    if (flipButton >= 2) flipButton = 0;
    delay(500);
  }

  M5.update();    //Read the press state of the key.
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


void modeLed(int levLed, int iconLight, int lightMandalou, int nbled )
{
  //all off
  for (i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB::Black;
  }

  //icone white green red,blue
  if (iconLight == 1)
  {
    leds[nbled] = CRGB(levLed , levLed , levLed); //white
  }

  if (iconLight == 2)
  {
    leds[nbled] = CRGB(levLed , 0 , 0); //red
  }

  if (iconLight == 3)
  {
    leds[nbled] = CRGB(0 , levLed , 0); //green
  }

  if (iconLight == 4)
  {
    leds[nbled] = CRGB(0 , 0 , levLed); //blue
  }

  //icone bas 4 led
  if (lightMandalou == 1)
  {
    leds[0] = CRGB(levLed , levLed , levLed ); //white 0->100%
    leds[1] = CRGB(levLed , levLed , levLed ); //white 0->100%
    leds[2] = CRGB(levLed , levLed , levLed ); //white 0->100%
    leds[3] = CRGB(levLed , levLed , levLed ); //white 0->100%
  }

  //icone bas 4 led
  if (lightMandalou == 2)
  {
    leds[0] = CRGB(0 , levLed , 0 ); //green 0->100%
    leds[1] = CRGB(0 , levLed , 0 ); //green 0->100%
    leds[2] = CRGB(0 , levLed , 0 ); //green 0->100%
    leds[3] = CRGB(0 , levLed , 0 ); //green 0->100%
  }
  FastLED.show();
  delay(10);
}



void testLed()
{
  int j = 0;
  //all off
  for (i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB::Black;
  }

  j = j + 1;
  j = j % 20;
  leds[j] = CRGB::Red;

  FastLED.show();
  delay(200);

}
