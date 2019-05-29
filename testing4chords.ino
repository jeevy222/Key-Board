
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>

#include <SerialFlash.h>
#include <Bounce.h>

#include "AudioSampleD_1.h"
#include "AudioSampleE_1.h"
#include "AudioSampleF_1.h"
#include "AudioSampleG_1.h"


// Create the Audio components.  These should be created in the
// order data flows, inputs/sources -> processing -> outputs
//
AudioPlayMemory    sound0;
AudioPlayMemory    sound1;  // six memory players, so we can play
AudioPlayMemory    sound2;  // all six sounds simultaneously
AudioPlayMemory    sound3;
AudioPlayMemory    sound4;
AudioPlayMemory    sound5;
AudioMixer4        mix1;    // two 4-channel mixers are needed in
AudioMixer4        mix2;    // tandem to combine 6 audio sources
AudioOutputI2S     headphones;
AudioOutputAnalog  dac;     // play to both I2S audio board and on-chip DAC

// Create Audio connections between the components
//
AudioConnection c1(sound0, 0, mix1, 0);
AudioConnection c2(sound1, 0, mix1, 1);
AudioConnection c3(sound2, 0, mix1, 2);
AudioConnection c4(sound3, 0, mix1, 3);
AudioConnection c5(mix1, 0, mix2, 0);   // output of mix1 into 1st input on mix2
AudioConnection c6(sound4, 0, mix2, 1);
AudioConnection c7(sound5, 0, mix2, 2);
AudioConnection c8(mix2, 0, headphones, 0);
AudioConnection c9(mix2, 0, headphones, 1);
AudioConnection c10(mix2, 0, dac, 0);

// Create an object to control the audio shield.
// 
AudioControlSGTL5000 audioShield;

const int ldrPin1 = 2;    // the number of the LDR pin
const int ldrPin2 = 8;
const int ldrPin3 = 16;
const int ldrPin4 = 20;

void setup() {

    AudioMemory(20);

  // turn on the output
  audioShield.enable();
  audioShield.volume(0.8);



  // put your setup code here, to run once:
    Serial.begin(9600);
  pinMode(ldrPin1, INPUT);   //initialize the LDR pin1 as an input
  pinMode(ldrPin2, INPUT);   //initialize the LDR pin2 as an input
  pinMode(ldrPin3, INPUT);   //initialize the LDR pin3 as an input
  pinMode(ldrPin4, INPUT);   //initialize the LDR pin4 as an input
//  AudioMemory(10);           // Audio connections require memory to work
//  audioShield.enable();      // turn on the output
//  audioShield.volume(0.5);
//  mixer1.gain(0, 0.4);       // reduce the gain on mixer channels, so more than 1                          mixer1.gain(1, 0.4);       // sound can play simultaneously without clipping
//  mixer1.gain(2, 0.4);
//  mixer1.gain(3, 0.4);

}
void loop() 
{
  // put your main code here, to run repeatedly:
   int ldrStatus1 = digitalRead(ldrPin1);   // read the status of the LDR value
   int ldrStatus2 = digitalRead(ldrPin2);
   int ldrStatus3 = digitalRead(ldrPin3);
   int ldrStatus4 = digitalRead(ldrPin4);

  //check if the LDR status is <=300
  // Play the respective sound.
  // The audio library will play each sound through the mixers
  // so any combination can play simultaneously.

  if (ldrStatus1 == LOW) {
    sound0.play(AudioSampleD_1);
    delay(200);
  }
  else
  {Serial.print ("11111 NOT WORKING");
         
  }
   
     if (ldrStatus2 == LOW) {
    sound1.play(AudioSampleE_1);
    delay(200);
  }
  else
  {Serial.print ("11111 NOT WORKING");
  }
  
  if (ldrStatus3 == LOW) {
    sound2.play(AudioSampleF_1);
    delay(200);
  }
  else
  {Serial.print ("11111 NOT WORKING");
  }

   if (ldrStatus4 == LOW) {
    sound3.play(AudioSampleG_1);
    delay(200);
  }
  else
  {Serial.print ("11111 NOT WORKING");
  }
  }





  
