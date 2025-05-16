#include <Adafruit_BMP280.h>
#include <DHT.h>
#include <lsm6dsm.h>
DHT dht(D0,DHT11);
LSM6DSM IMU;
Adafruit_BMP280 bmp;
void setup() {
  Serial.begin(115200);
  IMU.begin();
  dht.begin();
  bmp.begin(0x76);
}

void loop() {
  float x = IMU.readFloatAccelX();  
  float y = IMU.readFloatAccelY();
  float z = IMU.readFloatAccelZ();
  float basinc = bmp.readPressure();
  float sicaklik = dht.readTemperature();
  float nem = dht.readHumidity();
  Serial.print("X:");
  Serial.print(x);
  Ser