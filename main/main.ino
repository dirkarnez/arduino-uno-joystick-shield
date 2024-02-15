#include <SoftwareSerial.h>

const byte xPin = A0;
const byte yPin = A1;

SoftwareSerial ss(4, 7);

void setup()
{
   Serial.begin(38400);
   ss.begin(38400);
}

void loop()
{
   static unsigned long timer = 0;
   unsigned long interval = 1000;
   if (millis() - timer >= interval)
   {
      timer = millis();
      int xValue = analogRead(xPin);
      int yValue = analogRead(yPin);
      Serial.print("x value = ");
      Serial.print(xValue);
      Serial.print("   y value = ");
      Serial.println(yValue);
      char buffer[15];
      snprintf(buffer, 14, "%d,%d", xValue, yValue);
      Serial.println(buffer);
      ss.println(buffer);
   }
}
