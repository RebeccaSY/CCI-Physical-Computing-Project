# CCI-Physical-Computing-Project

## WEEK 06  

My initial project proposal is to build an intelligent illumination system which can contribute to our living environment.  
* INPUTs:  
  * Process the picture / colour detected, consider this as the environment condition
  * If there is an object approaching the system, it means human is getting involved in the environment
* OUTPUTs: 
  * LED cube with different colour patterns. Colourful illumination can contribute to the energy of human bodies. 
  * Sound or Servo, which could add on to the feedback


## WEEK 07  

I started to get the required sensors and get familiar with them.  
According to feedback, I plan to focus on Arduino hardware part instead of image processing. I will use a colour sensor to take inputs from environment, instead of a camera which take images. 

Colour sensor TSC3200:  
**(NOT ACCURATE)**  ![Image text](https://github.com/RebeccaSY/CCI-Physical-Computing-Project/blob/main/pictures/colorsensor-1.jpg)  

Ultrasonic sensor (get the distance):  OK  
![Image text](https://github.com/RebeccaSY/CCI-Physical-Computing-Project/blob/main/pictures/ultrasonic-1.jpg)

RGB LED common cathode (single):  OK  


## WEEK 08  

I want to build a geometry of a bird's shape, with LEDs attached on it. LED The LEDs absorb colours from the colour sensor. The user can use objects of different colours to decoration the illumination system. The colours also represent the virtual environment created by the user. If all of the colours are colours that exist on the satellite map of Earth, the bird will flap its wings, approach the object detected. Otherwise, the bird turn 180° to the back and leave the object detected.  
  
**PROBLEM:**  
**The shape of the geometry is complex when building with paper, when some movements are required.**  
  
RGB LED (soldered in parallel):  OK  
![Image text](https://github.com/RebeccaSY/CCI-Physical-Computing-Project/blob/main/pictures/LEDtwo-1.jpg)  
![Image text](https://github.com/RebeccaSY/CCI-Physical-Computing-Project/blob/main/pictures/LEDtwo-2.jpg)  
  
Temperature & humidity sensor:  
The reading of DHT11 temperature & humidity sensor is only in whole numbers, and changes very slowly with the change of environment. **(NOT IDEAL)**  
![Image text](https://github.com/RebeccaSY/CCI-Physical-Computing-Project/blob/main/pictures/dht11-1.png)  
![Image text](https://github.com/RebeccaSY/CCI-Physical-Computing-Project/blob/main/pictures/dht11.png)  
  
**Next step:**  
Three inputs are needed to control one LED's colour, how to control many LEDs to have different colours?  

## WEEK 09  
RGB LED (multiple with different colors):  OK
Shift register 74HC595N is used to control 8 output pins with 3 input pins. I connected 3 shift registers in parallel, 3 x 8 = 24 output pins can be used to control the colours of 24 / 3 = 8 LEDs, with only 3 output pins on Arduino board used. 
  
Refer to this tutorial https://www.youtube.com/watch?v=hqVpxCPFaQk :+1:  

![Image text](https://github.com/RebeccaSY/CCI-Physical-Computing-Project/blob/main/pictures/LED-multi.png)  
  
Temperature sensor (another):  OK  
![Image text](https://github.com/RebeccaSY/CCI-Physical-Computing-Project/blob/main/pictures/mcp9808.png)  

Servo MG995:  OK but sometimes not rotating smoothly.  
![Image text](https://github.com/RebeccaSY/CCI-Physical-Computing-Project/blob/main/pictures/servo-1.jpg)  

  
**PROBLEM:**  
**TSC3200 Color Sensor stopped working!** Light off when connected with power.  
I ordered another one. However, Royal Mail delivery may be affected by the strike, there is **no guarantee** on delivery time.  

## WEEK 10  

Connecting all the inputs and outputs together:  
  
**PROBLEM**  
**There is conflict between ShiftPWM library and Servo library. They can't run in the same program.**  
The reason may be that they each use a timer.  I then looked at the readme file of two libraries. I should changed to other output pins cause some were disabled.  
**I decided to focus on technology, and didn't end up with building an accurate world map** I used the map as a cover with colours mixed inside.  

Soldering & Housing  
![Image text](https://github.com/RebeccaSY/CCI-Physical-Computing-Project/blob/main/pictures/solder.png)  
![Image text](https://github.com/RebeccaSY/CCI-Physical-Computing-Project/blob/main/pictures/map-1.jpg)    
![Image text](https://github.com/RebeccaSY/CCI-Physical-Computing-Project/blob/main/pictures/map-2.jpg)    
![Image text](https://github.com/RebeccaSY/CCI-Physical-Computing-Project/blob/main/pictures/map-3.jpg)  
![Image text](https://github.com/RebeccaSY/CCI-Physical-Computing-Project/blob/main/pictures/combine.jpg)  
  
  VIDEO  https://youtu.be/9fyXw67YxEo
  
  
