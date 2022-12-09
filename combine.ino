
#include <Wire.h> 
//#include <Servo.h>

Servo myservo;
#define servoPin 11

/**
#include "DHT.h" 

DHT dht(DHTPIN, DHTTYPE);
**/

#define trigPin 12  // ultrasonic
#define echoPin 13  // ultrasonic

#include <Wire.h>
#include "Adafruit_MCP9808.h"

// Create the MCP9808 temperature sensor object
Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();

const int ShiftPWM_latchPin = 8;

#define SHIFTPWM_NOSPI
const int ShiftPWM_dataPin = 6;
const int ShiftPWM_clockPin = 7;

const bool ShiftPWM_invertOutputs = false;
const bool ShiftPWM_balanceLoad = false;

#include <ShiftPWM.h>


// variables for ultrasonic
int distance;
long duration;

// variables for servo
int pos = 0;


// variables for RGB LED colors:
int redColor = 0;
int greenColor = 0;
int blueColor = 0;
unsigned char maxBrightness = 255;
unsigned char pwmFrequency = 75;
unsigned int numRegisters = 3;              // num of shift reg used
unsigned int numOutputs = numRegisters * 8; // each has 8 output pins
unsigned int numRGBLeds = numOutputs / 3;   // 3 outputs decide 1 LED's color
unsigned long startTime = 0; // start time for the chosen fading mode

// global variables
int mode = 0;       // '0' for DAY; '1' for NIGHT
int progress = 0;   // '0' for nature: clockwise; '1' for anti-nature: anti-clockwise
float curr_temp = 0;  // for temperature comparison
float prev_temp = 0;  // for temperature comparison

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT

  myservo.attach(11);
  pinMode(servoPin, OUTPUT);
  myservo.write(0);
  
  // set the number of 8-bit registers that are used.
  ShiftPWM.SetAmountOfRegisters(numRegisters);
  // connection: RGBRGBRGBRGB...
  ShiftPWM.SetPinGrouping(1);
  ShiftPWM.Start(pwmFrequency, maxBrightness);
  
  tempsensor.begin(0x18);
  
  Serial.println("BEGIN! ");
  //dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:

  // ultrasonic input to decide mode
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if (distance < 5) {
    progress = 1;    
  } else {
    progress = 0;
  }

/**
  // for temperature & humanidty sensor
  float temp_hum[2] = {0}; 
  if(!dht.readTempAndHumidity(temp_hum)){
    Serial.print("Humidity: "); 
    Serial.print(temp_hum[0]);
    Serial.print(" %\t");
    Serial.print("Temperature: "); 
    Serial.print(temp_hum[1]);
    Serial.println(" C");
    
  } else { 
    Serial.println("Failed to read temprature and humidity.");
    ShiftPWM.SetAll(0);
  }

**/    

  tempsensor.wake();   
  float t = tempsensor.readTempC();
  Serial.print(t);
  Serial.println(" C");
  tempsensor.shutdown_wake(1);
  
  // if temperature goes up, turn to DAY mode
  curr_temp = t;
  if (curr_temp > prev_temp) {
    mode = 0;
  } else if (curr_temp < prev_temp) {  // turn to NIGHT mode
    mode = 1;
  }
  prev_temp = curr_temp;

  delay(200);


  if (mode == 0) {
    Serial.println("Mode: DAY");
    ShiftPWM.SetRGB(0, 30, 86, 8);     // greenland
    ShiftPWM.SetRGB(1, 30, 86, 8); 
    ShiftPWM.SetRGB(2, 30, 86, 8); 
    ShiftPWM.SetRGB(3, 220, 180, 40);  // sand
    ShiftPWM.SetRGB(4, 220, 180, 40); 
    ShiftPWM.SetRGB(5, 5, 8, 20);      // sea
    ShiftPWM.SetRGB(6, 5, 8, 20); 
    ShiftPWM.SetRGB(7, 167, 167, 167);  // snowland
  } else {
    Serial.println("Mode: NIGHT");
    ShiftPWM.SetRGB(0, 10, 10, 50);     // land - dark
    ShiftPWM.SetRGB(1, 10, 10, 50); 
    ShiftPWM.SetRGB(2, 200, 200, 150);  // land - bright
    ShiftPWM.SetRGB(3, 10, 10, 50); 
    ShiftPWM.SetRGB(4, 200, 200, 150); 
    ShiftPWM.SetRGB(5, 5, 0, 10); 
    ShiftPWM.SetRGB(6, 5, 0, 10);      // sea - dark
    ShiftPWM.SetRGB(7, 10, 10, 50); 
  }


  if (progress == 0 && pos < 180) {
    pos += 1;
  } else if (progress == 1 && pos > 0) {
    pos -= 1;
  }
   
  myservo.write(pos);
  
  delay(200);

  Serial.print("progress: ");
  Serial.println(progress);
  delay(2000);
 

}
