/* Halloween Costume 2014 
 Version 1.1
 */

// Pin Setup
int tleft = 2;
int bleft = 5;
int tright = 6;
int bright = 3 ;
int center = 9;

//Timing 
int delayBetweenCycles = 30*1000;




void setup(void)
{
  pinMode(tleft,OUTPUT);
  pinMode(bleft,OUTPUT);
  pinMode(tright,OUTPUT);
  pinMode(bright,OUTPUT);
  pinMode(center,OUTPUT);

  digitalWrite(tleft, LOW);
  digitalWrite(bleft, LOW);
  digitalWrite(tright,LOW);
  digitalWrite(bright,LOW);
  digitalWrite(center,LOW);
}


void loop(void)
{

  startup_sequence();

  delay(delayBetweenCycles);
  all_off();
  delay(delayBetweenCycles);

  fade_circle(center,15);

  delay(delayBetweenCycles);

}

void startup_sequence(void)
{
  digitalWrite(center,HIGH);
  delay(1000);

  flash_circle(200,3);


  all_on();
  delay(1500);
  all_off();
  digitalWrite(center,HIGH);

  flash_circle(70,4);

  all_on();
  delay(1500);
  all_off();
  digitalWrite(tleft,HIGH); 
  digitalWrite(center,HIGH);

}

void all_on(void)
{
  digitalWrite(tleft,HIGH);
  digitalWrite(bleft,HIGH);
  digitalWrite(tright,HIGH);
  digitalWrite(bright,HIGH);
  digitalWrite(center,HIGH); 
}

void all_off(void)
{
  digitalWrite(tleft,LOW);
  digitalWrite(bleft,LOW);
  digitalWrite(tright,LOW); 
  digitalWrite(bright,LOW);
  digitalWrite(center,LOW); 
}

void flash_one(int pin, int delay_ms)
{
  digitalWrite(pin,HIGH);
  delay(delay_ms);
  digitalWrite(pin,LOW);
  delay(delay_ms);
}

void flash_all(int delay_ms)
{
  all_on();
  delay(delay_ms);
  all_off();
  delay(delay_ms); 
}


void flash_circle(int delay_ms, int ntimes)
{   
  for (int ii=0; ii<ntimes; ii++)
  {
    flash_one(tleft,delay_ms);
    flash_one(tright,delay_ms);
    flash_one(bright,delay_ms);
    flash_one(bleft,delay_ms);
  }
}



void fade_up(int led)
{
  int brightness = 0;
  int fadeAmount = 5;

  do{
    analogWrite(led,brightness);
    brightness= brightness + fadeAmount;
    delay(30);
  }
  while(brightness != 255);
}

void fade_down(int led)
{
  int brightness = 255;
  int fadeAmount = 5;

  do{
    analogWrite(led,brightness);
    brightness= brightness - fadeAmount;
    delay(30);
  }
  while(brightness != 0); 
}

void fade_circle(int led, int ntimes)
{
  for (int ii=0;ii<ntimes;ii++)
  {
    digitalWrite(led,LOW);

    fade_up(led);
    fade_down(led); 

    digitalWrite(led,LOW);
  }
}






