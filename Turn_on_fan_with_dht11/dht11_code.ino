
#include "DHT.h"

#define DHTPIN 8     // what pin we're connected to

int LEDpin=13;
int relay = 9;

#define DHTTYPE DHT11   // DHT 11 

// Initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); 
  Serial.println("DHTxx test!");
  pinMode(relay,OUTPUT);
 
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  
if (t> 28){
  digitalWrite(relay, LOW);
  Serial.print("The bulb is ON");
  delay(1000);
  }
  else{
    digitalWrite(relay, HIGH);
    Serial.print("The bulb is OFF");
    delay(1000);
  }
Serial.print("Humidity= ");
Serial.println(h);
Serial.print("Temperature= ");
Serial.print(t);
  
}
