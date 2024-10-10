#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHTPIN A0
#define DHTTYPE DHT11
#define rel A1

LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C address 0x27 (from DIYables LCD), 16 column and 2 rows
DHT dht(DHTPIN, DHTTYPE);


void setup()
{
   Serial.begin(9600); // initialize serial
  pinMode(rel, OUTPUT);
  dht.begin();     // initialize the sensor
  lcd.init();      // initialize the lcd
  lcd.backlight(); // open the backlight 
  digitalWrite(rel,HIGH);
}

void loop()
{//digitalWrite(rel,HIGH);
 // delay(2000); // wait a few seconds between measurements
 //digitalWrite(rel,LOW);
 //delay(2000);
  float humi  = dht.readHumidity();    // read humidity
  float tempC = dht.readTemperature(); // read temperature

  lcd.clear();
  // check if any reads failed
 /* if (isnan(humi) || isnan(tempC)) {
    lcd.setCursor(0, 0);
    lcd.print("Failed");
  } else {*/
    lcd.setCursor(0, 0);  // start to print at the first row
    lcd.print("Temp: ");
    lcd.print(tempC);     // print the temperature
    lcd.print((char)223); // print ° character
    lcd.print("C");

    lcd.setCursor(0, 1);  // start to print at the second row
    lcd.print("Humi: ");
    lcd.print(humi);      // print the humidity
    lcd.print("%");
    if(humi<=50||tempC>37)
    {digitalWrite(rel,LOW);
     delay(2000);
     digitalWrite(rel,HIGH);
     delay(2000);
     }
     if(humi>50||tempC<37)
     {digitalWrite(rel,HIGH);
     delay(1000);}
    
     
 // }
}