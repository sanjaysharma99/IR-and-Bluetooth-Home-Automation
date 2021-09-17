#include <IRremote.h>
int recv_pin=11;
int led[4]={3,4,5,6};
int state[4]={LOW,LOW,LOW,LOW};
IRrecv irrecv(recv_pin);
decode_results results;
char ivar;

void setup()
{
    for(int i=0;i<4;i++)
    {
        pinMode(led[i],OUTPUT);
    }
    irrecv.enableIRIn();
    Serial.begin(9600);
}

void loop()
{
    if(irrecv.decode(&results))
    {
      Serial.println(results.value,HEX);
      drive1();
      irrecv.resume();
    }
    if(Serial.available()>0)
    {
        ivar=Serial.read();
        drive2();
    }
}
void drive1()
{
    if(results.value==0xFD08F7)
    {
      state[0]=!state[0];
      digitalWrite(led[0],state[0]);
    }
    if(results.value==0xFD8877)
    {
      state[1]=!state[1];
      digitalWrite(led[1],state[1]);
    }
    if(results.value==0xFD48B7)
    {
      state[2]=!state[2];
      digitalWrite(led[2],state[2]);
    }
    if(results.value==0xFD28D7)
    {
      state[3]=!state[3];
      digitalWrite(led[3],state[3]);
    }
}
void drive2()
{
    if(ivar=='o')
    {
      state[0]=!state[0];
      digitalWrite(led[0],state[0]);
    }
    if(ivar=='A')
    {
      state[1]=!state[1];
      digitalWrite(led[1],state[1]);
    }
    if(ivar=='R')
    {
      state[2]=!state[2];
      digitalWrite(led[2],state[2]);
    }
    if(ivar=='D')
    {
      state[3]=!state[3];
      digitalWrite(led[3],state[3]);
    }
}