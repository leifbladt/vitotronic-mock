int incomingByte = 0;    // for incoming serial data
long timer = 0;
bool session = false;

void setup() {
  Serial.begin(4800, SERIAL_8E2);
}

void loop() {

  if (!session && (millis() > timer + 2000)) {
    timer = millis();
    Serial.print((char)0x05);
    
  }
  
  // send data only when you receive data:
  if (Serial.available() > 0) {

    // read the incoming byte:
    incomingByte = Serial.read();

    if ((char)incomingByte != (char)0x04) {
      session = false;
      // ACK
      Serial.print((char)0x06);
    }
  }
}
