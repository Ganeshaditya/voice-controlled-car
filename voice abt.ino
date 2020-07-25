#include <SoftwareSerial.h>
SoftwareSerial BT(0,1); //TX, RX respetively
String voice;
int L1 = 4;
int L2 = 5;
int R1 = 8;
int R2 = 9;
int trigPin = 12;
int echoPin = 13;
int ENA = 3;
int ENB = 10;
long duration, distance;

void setup() {
  
  Serial.begin(9600); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  // put your setup code here, to run once:

}
void loop() {
    while (BT.available())
    {  //Check if there is an available byte to read
       delay(10); //Delay added to make thing stable
       char c = BT.read(); //Conduct a serial read
        voice += c;
    }
        digitalWrite(trigPin,HIGH);
        delayMicroseconds(1000);
        digitalWrite(trigPin, LOW);
        duration=pulseIn(echoPin, HIGH);
        distance =(duration/2)/29.1;
        delay(10);
        Serial.println(distance);
          if (voice.length() > 0)
          {
              Serial.println(voice);
             if(voice == "*go#")
                {
                  if(distance>50)
                  {
                analogWrite(ENA, 500);
                analogWrite(ENB, 500); 

                digitalWrite(L1, HIGH);
                digitalWrite(L2, LOW);
                digitalWrite(R1, HIGH);
                digitalWrite(R2, LOW);
                }
                   else if(distance>40 && distance<50)
                     {
                        analogWrite(ENA, 250);
                        analogWrite(ENB, 250); 
                        digitalWrite(L1, HIGH);
                        digitalWrite(L2, LOW);
                        digitalWrite(R1, HIGH);
                        digitalWrite(R2, LOW);
                       }
                        else if(distance>35 && distance<40)
                         {
                            analogWrite(ENA, 120);
                            analogWrite(ENB, 120); 
                            digitalWrite(L1, HIGH);
                            digitalWrite(L2, LOW);
                            digitalWrite(R1, HIGH);
                            digitalWrite(R2, LOW);
                          }
                         else if(distance<30)
                          {
                            analogWrite(ENA, 100);
                            analogWrite(ENB, 100); 
                            digitalWrite(L1, LOW);
                            digitalWrite(L2, LOW);
                            digitalWrite(R1, LOW);
                            digitalWrite(R2, LOW);
                           }
                }
                
              else if(voice == "*back#")
              {
                analogWrite(ENA, 500);
                analogWrite(ENB, 500); 
                digitalWrite(L1, LOW);
                digitalWrite(L2, HIGH);
                digitalWrite(R1, LOW);
                digitalWrite(R2, HIGH);
              
              }
              else if(voice == "*right#")
              {
                analogWrite(ENA, 500);
                analogWrite(ENB, 500); 

                digitalWrite(L1, HIGH);
                digitalWrite(L2, LOW);
                digitalWrite(R1, LOW);
                digitalWrite(R2, HIGH);
                delay(400);
                digitalWrite(L1, HIGH);
                digitalWrite(L2, LOW);
                digitalWrite(R1, HIGH);
                digitalWrite(R2, LOW);
                
              }
              else if(voice == "*left#")
              {
                analogWrite(ENA, 500);
                analogWrite(ENB, 500); 

                digitalWrite(L1, LOW);
                digitalWrite(L2, HIGH);
                digitalWrite(R1, HIGH);
                digitalWrite(R2, LOW);
                delay(400);
                digitalWrite(L1, HIGH);
                digitalWrite(L2, LOW);
                digitalWrite(R1, HIGH);
                digitalWrite(R2, LOW);
                
              }
              else if(voice == "*stop#")
              {
                digitalWrite(L1, LOW);
                digitalWrite(L2, LOW);
                digitalWrite(R1, LOW);
                digitalWrite(R2, LOW);
               }
               
         }
          voice=""; //Reset the variable after initiating
           
                         if(distance<30)
                          {
                            analogWrite(ENA, 100);
                            analogWrite(ENB, 100); 
                            digitalWrite(L1, LOW);
                            digitalWrite(L2, LOW);
                            digitalWrite(R1, LOW);
                            digitalWrite(R2, LOW);
                           }
}

 
