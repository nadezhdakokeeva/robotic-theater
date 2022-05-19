// пин управления скоростью мотора (с подержкой ШИМ)
#define P_SPEED   6
// пин выбора направления движения мотора
#define P_DIR     7
#define SPEED     100   //1..255
#define TIME_LEN  1400   //длина пробега мотора, около 800мс

byte LED_pin[4] = {9, 10, 11, 13};

void setup() 
{
  // пины в режим выхода
  pinMode(P_DIR, OUTPUT); 
  pinMode(P_SPEED, OUTPUT);
} 

void moveDrive(int dir, int spd){
  digitalWrite(P_DIR, dir);       // задаёт направление
  analogWrite(P_SPEED, spd);    // задаёт скорость  
}

void loop() 
{ 

 byte j =0;
 
 moveDrive(LOW, 80);
 moveDrive(HIGH, TIME_LEN);
 
 for( j=0; j<4; j++){
  analogWrite(LED_pin[j], 255);
  delay(100);
 }
 delay(500);
 for( j=0; j<4; j++){
  analogWrite(LED_pin[j], 0);
  delay(100);
 }
 delay(500);
}
