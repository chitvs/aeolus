#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define BMP280_I2C_ADDRESS 0x76
#define DHTPIN 2
#define DHTTYPE DHT22

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);
Adafruit_BMP280 bmp;
bool bmpFound = false;

void setup() {
  Serial.begin(9600);
  while(!Serial);
  
  lcd.init();
  lcd.backlight();
  dht.begin();
  
  bmpFound = bmp.begin(BMP280_I2C_ADDRESS);
  
  if (bmpFound) {
    Serial.println("BMP280 ok!");
  } else {
    Serial.println("BMP280 error");
  }
}

void loop() {
  
  // DHT22 - Temperature and humidity
  lcd.setCursor(0, 0);
  float humidity = dht.readHumidity();
  float tempDHT = dht.readTemperature();
  
  if (isnan(humidity) || isnan(tempDHT)) {
    lcd.print("DHT22 error     ");
  } else {
    lcd.print("T:");
    lcd.print(tempDHT, 2);
    lcd.print("C H:");
    lcd.print(humidity, 1);
    lcd.print("%  ");
  }
  
  // BMP280 - Altitude and pressure
  lcd.setCursor(0, 1);
  if (bmpFound) {
    float tempBMP = bmp.readTemperature();
    float pressure = bmp.readPressure() / 100.0F;
    float altitude = bmp.readAltitude(1018.0);
    
    lcd.print("P:");
    lcd.print(pressure, 0);
    lcd.print("hPa A:");
    lcd.print(altitude, 0);
    lcd.print("m  ");
  } else {
    lcd.print("BMP280 error    ");
  }
  
  // Serial output matching the LCD display
  Serial.print("DHT22 - Temp: ");
  if (isnan(tempDHT)) Serial.print("NaN"); else Serial.print(tempDHT, 2);
  Serial.print(" C, Humidity: ");
  if (isnan(humidity)) Serial.print("NaN"); else Serial.print(humidity, 1);
  Serial.println(" %");
  
  if (bmpFound) {
    Serial.print("BMP280 - Pressure: ");
    Serial.print(bmp.readPressure() / 100.0F, 0);
    Serial.print(" hPa, Altitude: ");
    Serial.print(bmp.readAltitude(1018.0), 0);
    Serial.println(" m");
  } else {
    Serial.println("BMP280 not available");
  }
  
  delay(2000);
}
