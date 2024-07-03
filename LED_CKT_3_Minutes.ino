
#include "EEPROM.h"
volatile uint8_t state = 0;
volatile uint32_t initial_time = 0;
volatile uint32_t current_time = 0;
volatile uint8_t init_time_flg = true;
void setup() 
{
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
   digitalWrite(1, HIGH);
  state = EEPROM.read(0);
  delay(100); 
}

void loop() 
{
  EEPROM.write(0,state);
  delay(100);
  if(init_time_flg == true)
  {
    initial_time = millis();
    init_time_flg = false;
  }
  current_time = millis();
  if(digitalRead(2) == 0)
  {
    delay(200);
    initial_time = current_time;
    if(state<5)
    {
      state+=1;
     }
     if(state == 10)
     {
      state = 1;
      }
   }
   if(digitalRead(3) == 0)
  {
//    digitalWrite(1, HIGH);
    delay(200);
    initial_time = current_time;
    if(state == 10)
    {
     state = 5;
    }
    else if(state>1)
    {
     state-=1;
    }
   }
  switch(state)
  {
    case 1:
        digitalWrite(1, HIGH);
        analogWrite(0, 50);
        break;
     case 2:
        digitalWrite(1, HIGH);
        analogWrite(0, 100);
        break;
      case 3:
        digitalWrite(1, HIGH);
        analogWrite(0, 150);
        break;
      case 4:
        digitalWrite(1, HIGH);
        analogWrite(0, 200);
        break;
     case 5:
        digitalWrite(1, HIGH);
        analogWrite(0, 255);
        break;
     case 10:
        analogWrite(0,0);
        digitalWrite(1, LOW);
        break;
      default:
        break;
    }
    if((current_time-initial_time) > 180000)
    {
     initial_time = current_time;
     state = 10;
   }
}
