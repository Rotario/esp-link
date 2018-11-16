/**** Using a Teensy 3.1 to Connect an ESP8266 to PC USB Serial *******/
//     Compiled with Arduino 1.60 and Teensyduino 1.21b6
//     ESP8266 Firmware: AT21SDK95-2015-01-24.bin

#define FIRMWARE_UPLOADING 0 //0 for firmware upload, 1 for checking ESP is connected correctly
long LED_14_TimeOn=0;
int on = 0;

void setup() {
        pinMode(8, OUTPUT); //IO0 
      digitalWrite(8, FIRMWARE_UPLOADING); //IO0 LOW for firmware upload
      pinMode(LED_BUILTIN, OUTPUT);
      pinMode(9, OUTPUT);  // IO2 Pullup
      digitalWrite(9, HIGH);
      pinMode(10, OUTPUT);  // IO15
      digitalWrite(10, LOW); //IO15 LOW for normal operation 


      
    // Setup computer to Teensy serial
    Serial.begin(115200);
    // Setup Teensy to ESP8266 serial
    // Use baud rate 115200 during firmware update
    Serial1.begin(115200);
    //Serial.print("setup Done");

}

void loop() {

    // Send bytes from ESP8266 -> Teensy to Computer
    if ( Serial1.available() ) {
        Serial.write( Serial1.read() );
    }

    // Send bytes from Computer -> Teensy back to ESP8266
    if ( Serial.available() ) {
        Serial1.write( Serial.read() );
    }

    if (millis() - LED_14_TimeOn > 200) {
      LED_14_TimeOn = millis();
      on = !on;
      digitalWriteFast(LED_BUILTIN, on);
  }
 

}
