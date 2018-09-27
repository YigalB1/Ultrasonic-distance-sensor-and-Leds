int ledPins[] = {5,6,7,8,9,10,11,12};   
const int trigPin = 14;  // defines Ultrasonic pins numbers
const int echoPin = 13;  // defines Ultrasonic pins numbers

int distance;


void setup()
{
  
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  //pinMode(ledPin, OUTPUT);      // sets the digital pin as output
  
  //for (int thisPin = 5; thisPin =< 12; thisPin++) {
  //pinMode(thisPin, OUTPUT);
  for (int thisPin = 0; thisPin <= 7; thisPin++) {
    // initialize the output pins:
    pinMode(ledPins[thisPin], OUTPUT);
    digitalWrite(ledPins[thisPin], HIGH);   // sets the LED off
  }
  
  Serial.begin(9600); // Starts the serial communication
  
}

void loop()
{
  
  
  for (int i = 0; i <= 7; i++) {
    digitalWrite(ledPins[i], LOW);   // sets the LED on
    delay(1000);                  // waits for a second
    digitalWrite(ledPins[i], HIGH);    // sets the LED off
    delay(100);                  // waits for a second
  }
  
  
  
  
  int dist=readDistance();
  Serial.print("Distance is:  ");
  Serial.println(dist);
  delay(500);
}



int readDistance() {
  //trig starta as HIGH
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  int duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance= duration*0.034/2;

  return(distance);
}
