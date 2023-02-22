#include <SoftwareSerial.h>

//create SoftwareSerial for Pin UART
SoftwareSerial mySer(D2, D1); // RX | TX create SoftwareSerial for Pin UART

void setup() {
  Serial.begin(115200);
  mySer.begin(115200);
}


void loop() {


  if (Serial.available()) {      // If anything comes in Serial (USB),
    char data = Serial.read();
    mySer.write(data);
  }

  if (mySer.available()) {      // If anything comes in Serial (Pin RX UART),
    char data = mySer.read();
    Serial.print(data);
  }


}