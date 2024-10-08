/*
   Arduino Robotic Hand Tutorial 
*/

#include<Servo.h>
#include<SoftwareSerial.h>

Servo Thumb, Index, Middle, Ring, Little;

SoftwareSerial mySerial(10, 11);

int ThumbPos, IndexPos, MiddlePos, RingPos, LittlePos;

int fingerSpeed = 20, HandSpeed = 20;

int BLED = 13;
int RLED = 12;
int PUSH = 8;
int SWITCH = 9;

void setup()
{
  mySerial.begin(9600);
  
  pinMode(BLED, OUTPUT);
  pinMode(RLED, OUTPUT);
  pinMode(PUSH, INPUT_PULLUP);
  pinMode(SWITCH, INPUT_PULLUP);

  Thumb.attach(2);
  Index.attach(3);
  Middle.attach(4);
  Ring.attach(5);
  Little.attach(6);

  Thumb.write(45);
  ThumbPos = 45;
  Index.write(45);
  IndexPos = 45;
  Middle.write(45);
  MiddlePos = 45;
  Ring.write(45);
  RingPos = 45;
  Little.write(45);
  LittlePos = 45;

  digitalWrite(RLED, LOW);
  digitalWrite(BLED, LOW);
}

void loop()
{
  int ProgSwitch;
  ProgSwitch = digitalRead(SWITCH);
  if(ProgSwitch == 0)
    {
      PUSH_BUTTON();
      digitalWrite(RLED, LOW);
      digitalWrite(BLED, HIGH);
    }

  else if(ProgSwitch == 1)
    {
      BLUETOOTH();
      digitalWrite(RLED, HIGH);
      digitalWrite(BLED, LOW);
    }
}

void PUSH_BUTTON()
{
  int PushState,i;
  PushState = digitalRead(PUSH);
  if(PushState == 0)
    {
      if(ThumbPos == 45 && IndexPos == 45 && MiddlePos == 45 && RingPos == 45 && LittlePos ==45)
        {
          for(i=45; i<=150; i++)
            {
              Index.write(i);
              Middle.write(i);
              Ring.write(i);
              Little.write(i);

              IndexPos = i;
              MiddlePos = i;
              RingPos = i;
              LittlePos = i;
              delay(HandSpeed);
            }

          for(i=45; i<=150; i++)
            {
              Thumb.write(i);
              ThumbPos = i;
              delay(HandSpeed);
            }
        }
      else if(ThumbPos == 150 && IndexPos == 150 && MiddlePos == 150 && RingPos == 150 && LittlePos == 150)
        {
          for(i=150; i>=45; i--)
            {
              Thumb.write(i);
              ThumbPos = i;
              delay(HandSpeed);
            }
          
          for(i=150; i>=45; i--)
            {
              Index.write(i);
              Middle.write(i);
              Ring.write(i);
              Little.write(i);

              IndexPos = i;
              MiddlePos = i;
              RingPos = i;
              LittlePos = i;
              delay(HandSpeed);
            }
        }
    }

  else if(PushState == 1)
    {
      Thumb.write(ThumbPos);
      Index.write(IndexPos);
      Middle.write(MiddlePos);
      Ring.write(RingPos);
      Little.write(LittlePos);
    }
}

void BLUETOOTH()
{
  char data;
  int i;
  if(mySerial.available())
    {
      data = mySerial.read();
      if(data == 'T')
        {
          if(ThumbPos == 45)
            {
              for(i=45; i<=150; i++)
                {
                  Thumb.write(i);
                  ThumbPos = i;
                  delay(fingerSpeed);
                }
            }

          else if(ThumbPos == 150)
            {
              for(i=150; i>=45; i--)
                {
                  Thumb.write(i);
                  ThumbPos = i;
                  delay(fingerSpeed);
                }
            }
        }
      
      else if(data == 'I')
        {
          if(IndexPos == 45)
            {
              for(i=45; i<=150; i++)
                {
                  Index.write(i);
                  IndexPos = i;
                  delay(fingerSpeed);
                }
            }

          else if(IndexPos == 150)
            {
              for(i=150; i>=45; i--)
                {
                  Index.write(i);
                  IndexPos = i;
                  delay(fingerSpeed);
                }
            }
        }

      else if(data == 'M')
        {
          if(MiddlePos == 45)
            {
              for(i=45; i<=150; i++)
                {
                  Middle.write(i);
                  MiddlePos = i;
                  delay(fingerSpeed);
                }
            }

          else if(MiddlePos == 150)
            {
              for(i=150; i>=45; i--)
                {
                  Middle.write(i);
                  MiddlePos = i;
                  delay(fingerSpeed);
                }
            }
        }

      else if(data == 'R')
        {
          if(RingPos == 45)
            {
              for(i=45; i<=150; i++)
                {
                  Ring.write(i);
                  RingPos = i;
                  delay(fingerSpeed);
                }
            }

          else if(RingPos == 150)
            {
              for(i=150; i>=45; i--)
                {
                  Ring.write(i);
                  RingPos = i;
                  delay(fingerSpeed);
                }
            }
        }

      else if(data == 'L')
        {
          if(LittlePos == 45)
            {
              for(i=45; i<=150; i++)
                {
                  Little.write(i);
                  LittlePos = i;
                  delay(fingerSpeed);
                }
            }

          else if(LittlePos == 150)
            {
              for(i=150; i>=45; i--)
                {
                  Little.write(i);
                  LittlePos = i;
                  delay(fingerSpeed);
                }
            }
        }

      else if(data == 'H')
        {
          if(ThumbPos == 45 && IndexPos == 45 && MiddlePos == 45 && RingPos == 45 && LittlePos == 45)
            {
              for(i=45; i<=150; i++)
                {
                  Index.write(i);
                  Middle.write(i);
                  Ring.write(i);
                  Little.write(i);
                  IndexPos = i;
                  MiddlePos = i;
                  RingPos = i;
                  LittlePos = i;
                  delay(HandSpeed);
                }

              for(i=45; i<=150; i++)
                {
                  Thumb.write(i);
                  ThumbPos = i;
                  delay(HandSpeed);
                }
            }

          else if(ThumbPos == 150 && IndexPos == 150 && MiddlePos == 150 && RingPos == 150 && LittlePos == 150)
            {
              for(i=150; i>=45; i--)
                {
                  Thumb.write(i);
                  ThumbPos = i;
                  delay(HandSpeed);
                }

              for(i=150; i>=45; i--)
                {
                  Index.write(i);
                  Middle.write(i);
                  Ring.write(i);
                  Little.write(i);
                  IndexPos = i;
                  MiddlePos = i;
                  RingPos = i;
                  LittlePos = i;
                  delay(HandSpeed);
                }
            }
          else
            {
              mySerial.println("Err: Position of all fingers are not same");
            }
        }
    }  
}
