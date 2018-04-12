/* Hardware-in-loop - Robotics Society
 * by Javier Cuara <jcuara@ucmerced.edu> 
*/
#include <LiquidCrystal.h> // This is the LCD Library


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int inc=0;
int cm=0;

int redP =10 ;
int greenP = 9;
int blueP =8;

void setup() {
  pinMode(7,INPUT);
  pinMode(redP,OUTPUT);
  pinMode(greenP,OUTPUT);
  pinMode(blueP,OUTPUT);
  
  Serial.begin(9600);
  lcd.begin(13, 2);
  lcd.setCursor(0,0);
  lcd.print("Distance");
}
long Ultrasonic(int pin)
{
	
  pinMode(pin, OUTPUT);  // Clear the trigger
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  // Sets the pin on HIGH state for 10 micro seconds
  digitalWrite(pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin, LOW);
  pinMode(pin, INPUT);
  // Reads the pin, and returns the sound wave travel time in microseconds
  return pulseIn(pin, HIGH);
	
}

void loop() {
  
  cm = 0.01723 * Ultrasonic(7);
  inc = (cm / 2.54);
  
  if(inc <=20)
  {
	analogWrite(redP, 255);
	analogWrite(greenP, 0);
	analogWrite(blueP, 0);
    lcd.setCursor(0, 1);
    lcd.print("DANGER   ");
  	delay(200);
  }
  if(inc >20 && inc <30)
  {
	analogWrite(redP, 255);
	analogWrite(greenP, 0);
	analogWrite(blueP, 150);
  }
  lcd.setCursor(0,1);  //Set cursor to first column of second row
  lcd.print("                "); //Print blanks to clear the row
  lcd.setCursor(0, 1);
  lcd.print(inc);
  lcd.print(" inches");
  delay(250); // Wait for 100 millisecond(s)
 
 // lcd.print(cm);
}