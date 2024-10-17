// This example code is in the Public Domain (or CC0 licensed, at your option.)
// By Evandro Copercini - 2018
//
// This example creates a bridge between Serial and Classical Bluetooth (SPP)
// and also demonstrate that SerialBT have the same functionalities of a normal Serial
// Note: Pairing is authenticated automatically by this device

#include "BluetoothSerial.h"

String device_name = "ESP32-BT-Slave";

// Check if Bluetooth is available
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

// Check Serial Port Profile
#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Port Profile for Bluetooth is not available or not enabled. It is only available for the ESP32 chip.
#endif

#define RXp2 3
#define Txp2 1

BluetoothSerial SerialBT;
int count;
uint8_t eval;
const int ecgPin = 35;
void setup() {
  Serial.begin(9600, SERIAL_8N1,RXp2,Txp2);
  Serial1.begin(115200);
  SerialBT.begin(device_name);  //Bluetooth device name
  //SerialBT.deleteAllBondedDevices(); // Uncomment this to delete paired devices; Must be called after begin
  Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());
}

void loop() {
    //val = analogRead(ecgPin);
    //dtostrf(val, 4, 2, eval);
    //eval = val * 1024;

    eval = Serial.read();
    //dtostrf(val, 4, 2, eval);
    if (eval == 'a'){
      SerialBT.write('\r');
      SerialBT.write('\n');
    }
    else{
    SerialBT.write(eval);
    }
    


  delay(20);
}