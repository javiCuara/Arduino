/*LED ARDUINO - Robotics Society
 * By Javier Cuara <jcuara@ucmerced.edu>
*/

// make varibales for Red, Green, and Blue 
// map these variables to the corresponding pins you
// attached them to.

int Red = 13, Green = 12, Blue = 11;

// To make the LED Change color in setup we need to set these pins 
// to output mode, "pinMode()" will set a specified pin to take in
// inputs or output 


// Note that this function will only run once 
void setup(/*This function is for setup*/)
{
  pinMode(13, Red);
  pinMode(12, Green);
  pinMode(14, Blue);
  Serial.begin(9600);
}


void loop()
{
	// The highest "brightest" value you can
	// assign to a pin is 255 
	analogWrite(Red, 50);
	analogWrite(Blue, 25);
	analogWrite(Green, 25);
  
  
  	delay(300); // wait for 'x' milliseconds
}
