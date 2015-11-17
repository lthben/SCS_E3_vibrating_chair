/*  Author: Benjamin Low (benjamin.low@digimagic.com.sg)
 *  Description: 
 *  
 *  For vibrating chair for Science Centre of Singapore E3 
 *  exhibition.
 *  
 *  Controls a relay. Listens to a command at 
 *  the serial port and sends a short "high" signal to a relay
 *  that simulates a physical momentary switch so that
 *  the cushion can be software controlled. 
 */

#define write_pin 6

void setup() {
  Serial.begin(9600);
  pinMode(write_pin, OUTPUT);
}

void loop() {

        digitalWrite(write_pin, LOW);

  if (Serial.available()) {
        byte incoming = Serial.read();
        if (incoming == '1') {
                digitalWrite(write_pin, HIGH);
                Serial.println("on");
                delay(100);
        }
  }
}
