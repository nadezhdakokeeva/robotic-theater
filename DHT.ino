#include <DHT.h>
#include <DHT_U.h>

void setup() {
 DHT_Unified dht(7,DHT11);
 Serial.begin(9600);
 dht.begin();
}

void loop() {
  sensors_event_t event;
dht.temperature().getEvent(&event);
if(isnan(event.temperature))
    Serial.println("Error reading temperature!");
else
{
    Serial.print("Temperature: ");
    Serial.print(event.temperature);
    Serial.println(" *C");
}
dht.humidity().getEvent(&event);
if(isnan(event.relative_humidity))
    Serial.println("Error reading humidity!");
else
{
    Serial.print("Humidity: ");
    Serial.print(event.relative_humidity);
    Serial.println("%");
}
delay(500);
}
