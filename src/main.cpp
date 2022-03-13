#include <Arduino.h>

#define salida 25

volatile bool toggle = true;
void IRAM_ATTR onTimer();     //LA RAM ES MAS RAPIDA

hw_timer_t *timer = NULL; //esto es n apuntador de tipo hw timer 

void setup() {
  Serial.begin(9600);

  pinMode(salida,OUTPUT);
  timer = timerBegin(0, 80, true);

  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, 1000000, true);
  timerAlarmEnable(timer);
  
}

void loop() {
  digitalWrite(salida, toggle);
}

void IRAM_ATTR onTimer(){
  toggle ^= true;
}