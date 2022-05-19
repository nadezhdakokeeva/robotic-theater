void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
 while(Serial.available())
{
    int c=Serial.read();
    
    
    if(c=='1')
    {
        digitalWrite(13,HIGH);
        Serial.println("Led On");
    }
    else if(c=='0')
    {
        digitalWrite(13,LOW);
        Serial.println("Led Off");
    }
}
}
