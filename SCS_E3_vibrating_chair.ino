/*  Author: Benjamin Low (benjamin.low@digimagic.com.sg)
 *  
 *  Description: 
 *      The vibrating chair for Science Centre of Singapore E3 
 *  exhibition, for two of the Oculus Rift stations. The Arduino
 *  controls a three channel relay by listening to commands at 
 *  the serial port. 
 *      Arduino pin 8 simulates a physical momentary 
 *  switch so that the 12 VDC massage cushion can be software controlled. 
 *  Pins 10 and 11 each control an AC powered appliance which are, in this
 *  case, two hairdryers.
 *  
 *  Last updated: 24 Nov 2015
 */

#define dc_pin 8
#define ac_pin_1 10
#define ac_pin_2 11

void setup() {
  Serial.begin(9600);
  pinMode(dc_pin, OUTPUT);
  pinMode(ac_pin_1, OUTPUT);
  pinMode(ac_pin_2, OUTPUT);
}

void loop() {

  if (Serial.available()) {
        byte incoming = Serial.read();
        if (incoming == '1') {
                digitalWrite(dc_pin, HIGH);
                Serial.println("on");
                delay(100);
        }
        else if (incoming == '2') {
                digitalWrite(dc_pin, LOW);
                Serial.println("off");
                delay(100);
        }
        else if (incoming == '3') {
                digitalWrite(ac_pin_1, HIGH);
                Serial.println("ac 1 on");
                delay(100);
        } 
        else if (incoming == '4') {
                digitalWrite(ac_pin_1, LOW);
                Serial.println("ac 1 off");
                delay(100);
        }
         else if (incoming == '5') {
                digitalWrite(ac_pin_2, HIGH);
                Serial.println("ac 2 on");
                delay(100);
        } 
        else if (incoming == '6') {
                digitalWrite(ac_pin_2, LOW);
                Serial.println("ac 2 off");
                delay(100);
        }
  }
  
}
