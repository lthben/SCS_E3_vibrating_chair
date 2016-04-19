/*  Author: Benjamin Low (benjamin.low@digimagic.com.sg)
 *
 *  Description:
 *      The vibrating chair for Science Centre of Singapore E3
 *  exhibition, for two of the Oculus Rift stations. The Arduino
 *  controls a three channel relay by listening to commands at
 *  the serial port.
 *      Arduino pin 8 simulates a physical momentary
 *  switch so that the 12 VDC massage cushion can be software controlled.
 *  Pins 10 and 11 ehairdryerh control an hairdryer powered appliance which are, in this
 *  case, two hairdryers.
 *
 *  Last updated: 24 Nov 2015
 */

#define dc_pin 8
#define hairdryer_pin_1 10
#define hairdryer_pin_2 11
#define read_pin A0

boolean is_on;

void setup() {
  Serial.begin(9600);
  pinMode(dc_pin, OUTPUT);
  pinMode(hairdryer_pin_1, OUTPUT);
  pinMode(hairdryer_pin_2, OUTPUT);
  pinMode(read_pin, INPUT);
}

void loop() {

  if (Serial.available()) {

    byte incoming = Serial.read();

    if (incoming == '1') { //turn on vibration
        
        power_status_check();
        
      if (is_on == false) {
        toggle_switch();
        Serial.println("vibration on");
      }
    }

    else if (incoming == '2') { //turn off vibration

        power_status_check();
        
      if (is_on == true) {
        toggle_switch();
        Serial.println("vibration off");
      }
    }
    else if (incoming == '3') {
      digitalWrite(hairdryer_pin_1, HIGH);
      Serial.println("hairdryer 1 on");
      delay(100);
    }
    else if (incoming == '4') {
      digitalWrite(hairdryer_pin_1, LOW);
      Serial.println("hairdryer 1 off");
      delay(100);
    }
    else if (incoming == '5') {
      digitalWrite(hairdryer_pin_2, HIGH);
      Serial.println("hairdryer 2 on");
      delay(100);
    }
    else if (incoming == '6') {
      digitalWrite(hairdryer_pin_2, LOW);
      Serial.println("hairdryer 2 off");
      delay(100);
    }
    else if (incoming == '7') {
      power_status_check();
    }
  }
}

void toggle_switch() {
  digitalWrite(dc_pin, HIGH);
  delay(100);
  digitalWrite(dc_pin, LOW);
  delay(100);
}

void power_status_check() {

  int value = analogRead(read_pin);

  if (value < 1000) {
    is_on = true;
  } else {
    is_on = false;
  }
}

