/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
#include <LiquidCrystal.h>
 
Servo myservo1;  // create servo object to control a servo 
Servo myservo2;
LiquidCrystal lcd(11, 10, 5, 4, 3, 2);
 
int pos = 0, dis=0;    // variable to store the servo position
  int stop=0;
int move=0;
 
void setup() 
{ 
   lcd.print("WELCOME TO GPCET");
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object 
  
  lcd.begin(16, 2);
  
  
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(12,OUTPUT);

  
} 
 
void loop()
{ 

  if (dis==0)
{
 
  dis++;
}
  lcd.display();
  delay(100);
  int val = analogRead(0);
  if (val>2)
  {
    if (stop==0)
{
    lcd.setCursor(0, 0);
    lcd.print("     STOP       ");
  stop++;
}
stop--;
    
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    tone(12,1000,5000);
    delay(2000);
  for (pos = 30; pos <= 100; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo1.write(pos);              // tell servo to go to position in variable 'pos' 
   // myservo2.write(150-pos);1
    delay(5);                       // waits 15ms for the servo to reach the position 
  } 
  
  delay(3000);
  
  for(pos = 100; pos>=30; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo1.write(pos);              // tell servo to go to position in variable 'pos' 
    // myservo2.write(150-pos);
    delay(20);                       // waits 15ms for the servo to reach the position 
  }
  
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    if (move==0)
{
    lcd.setCursor(0, 0);
    lcd.print("   YOU CAN GO   ");
  move++;
}
move--;
  }
 delay(100); 
} 


