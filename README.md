# CCI-Physical-Computing-Project

## WEEK 06  

My initial project proposal is to build an interactive illumination system which can contribute to our living environment.  
* INPUT:  
  * Process the picture / colour detected, consider this as the environment condition
  * If there is an object approaching the system, it means human is getting involved in the environment
* OUTPUS: 
  * LED cube with different colour patterns. Colourful illumination can contribute to the energy of human bodies. 
  * Sound or Servo, which could add on to the feedback


## WEEK 07  

I started to get the required sensors and get familiar with them.  

Colour sensor:  


Ultrasonic sensor:  


RGB LED (single):  


## WEEK 08  

RGB LED (soldered in parallel):  
  
Temperature & humidity sensor:  
  
**Next step:**  
Three inputs are needed to control one LED's colour, how to control many LEDs to have different colours?  

## WEEK 09  
RGB LED (multiple with different colors):  
Shift register 74HC595N is used to control 8 output pins with 3 input pins. I connected 3 shift registers in parallel, 3 x 8 = 24 output pins can be used to control the colours of 24 / 3 = 8 LEDs, with only 3 output pins on Arduino board used. 
  
Refer to this tutorial https://www.youtube.com/watch?v=hqVpxCPFaQk :+1:  
  
**PROBLEM:**  
**TSC3200 Color Sensor stopped working!** Light off when connected with power.  
I ordered a new one. However, Royal Mail delivery may be affected by the strike, there is no guarantee on delivery time.  

## WEEK 10  

MAP:  

Housing:  
