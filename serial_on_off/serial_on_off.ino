/*
Overview: Turn LED On/Off using serial monitor
Description: Waits for a character on serial and turns LED on/off based on characters given
Circuit: Attach LED to Pin 13 (or whatever is default)
Usage: Open serial monitor, type "a" for on and "b" for off
Author: Eric Gonzales
*/

char serialRead;
String inputString = "";

void setup() {
    Serial.begin(9600); // set the baud rate to 9600, should be same as what you use in serial monitor
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    if (Serial.available()) {
        while (Serial.available()) {
            inputString += (char)Serial.read(); //read the input
        }

        Serial.println(inputString);

        while (Serial.available() > 0) {
            serialRead = Serial.read(); //clear the serial buffer
        }

        //in case of a, turn led on. in case of b, turn the led off.
        if (inputString == "a") {
            digitalWrite(LED_BUILTIN, HIGH);
        } else if (inputString == "b") {
            digitalWrite(LED_BUILTIN, LOW);
        }

        inputString = "";
    }
}
