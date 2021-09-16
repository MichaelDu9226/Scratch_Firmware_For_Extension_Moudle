#include "Arduino.h"
#include <Wire.h>
#include "MH_TCS34725.h"

//Dexarm connect to PORT1&SERIAL1
#define RXD1 26
#define TXD1 27

//Color Sensor connect to PORTA
#define I2C_SDA 0
#define I2C_SCL 32

//Item detected sensor connect to PORTB
#define DETECTED_PIN 33

//color sensor
MH_TCS34725 tcs = MH_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);

volatile boolean detected_state = false;

//deteced function
void deteced()
{
  Serial.println("item detected");
  Serial1.print("M1115\r\n");
}

void check_color()
{
  uint16_t r, g, b, c, colorTemp, lux;
  delay(4000);
  tcs.getRGBC(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature(r, g, b);
  lux = tcs.calculateLux(r, g, b);
  
  if((r > 1200)&&(g < 1200)&&(b < 1200))
  {
    Serial.println("RED Color Deteced");
    Serial1.print("M1116\r\n");
  }else if((r < 1200)&&(g > 1200)&&(b < 1200))
  {
    Serial.println("GREEN Color Deteced");
    Serial1.print("M1117\r\n");
  }else if((r < 1200)&&(g < 1500)&&(b > 1200))
  {
    Serial.println("BLUE Color Deteced");
    Serial1.print("M1118\r\n");
  }else if((r > 2000)&&(g > 2000)&&(c > 2000))
  {
    Serial.println("YELLOW Color Deteced");
    Serial1.print("M1119\r\n");
  }
}

void setup()
{
  Serial.begin(115200);
  
  Wire.begin(I2C_SDA, I2C_SCL);
  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }
  Serial1.begin(1000000, SERIAL_8N1, RXD1, TXD1);
  pinMode(DETECTED_PIN, INPUT);
  attachInterrupt(DETECTED_PIN, deteced, FALLING);
}

void loop()
{
  check_color();
  delay(1000);
}
