// UltraSonic -Rootics Society
// by Javier Cuara <Jcuara@ucmerced.edu>


// Make Global Vars
// Will be used for conversions 
int inc=0;
int cm=0;

void setup() {
  // map 'sig' to the proper pin
  pinMode(7,INPUT);
  Serial.begin(9600);
  Serial.print("Distance");
  Serial.println("");
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
  Serial.print("Cm:" );
  Serial.print(cm);
  Serial.println(""); // This prints the a new line ... carriage return
  delay(250); // Wait for 100 millisecond(s)
}