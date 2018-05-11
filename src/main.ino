#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire(D2);
float temp;
int rpm;

DallasTemperature sensors(&oneWire);
//Temp
int fan =D1;

void setup() {
    Serial.begin(9600);
    pinMode(fan, OUTPUT);
}

void loop(void) {
  sensors.requestTemperatures();
  temp = sensors.getTempCByIndex(0)-2;
  Serial.println(temp);
  rpm = map(temp, 20, 30, 255, 1023);

  if(temp < 22){
    rpm = 0;
  }
  if(temp > 30){
    rpm = 1023;
  }
  analogWrite(fan, rpm);
  delay(10); //just here to slow down the output so it is easier to read

}
