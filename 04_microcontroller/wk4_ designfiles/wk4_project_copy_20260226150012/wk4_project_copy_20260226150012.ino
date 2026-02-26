const int buttonPin = D0;
const int motorPinA1A = D1;
const int motorPinA1B = D2;
 int buttonState;
 int lastButtonState = HIGH;
 int numberOfButtonPress = 0;
 int startTime;
 int timeLength = 3000;
bool timerOn = false;
int pressDelay = 40;
int lastPressTime ;

void setup() {
pinMode (buttonPin, INPUT_PULLUP);
pinMode(motorPinA1A, OUTPUT);
pinMode (motorPinA1A, OUTPUT);
digitalWrite (motorPinA1A, HIGH);
digitalWrite (motorPinA1B, HIGH);
Serial.begin (9600);
  // put your setup code here, to run once:
}

void loop() {
  buttonState = digitalRead (buttonPin);
  //reads last bounce time to see if it has changed and resets
  if (buttonState != lastButtonState){
     lastPressTime = millis();
  }
//starts button reading process and leads to loop
  if((millis() - lastPressTime) > pressDelay){
    buttonState = digitalRead (buttonPin);
  }

  
    if (lastButtonState == HIGH && buttonState == LOW){
      if (!timerOn){
        timerOn = true;
        startTime = millis();
        numberOfButtonPress = 0;
        Serial.println ("Counting started");
      }
      numberOfButtonPress++;
      Serial.println("Number of presses: ");
      Serial.println (numberOfButtonPress);
    }
    lastButtonState = digitalRead (buttonPin);

    if(timerOn && (millis()- startTime >= timeLength)) {
      Serial.print( "Total Button Presses: ");
      Serial.println (numberOfButtonPress); 
      spinMotor(); //starts the motor spinning process

    //this resets back to original
      timerOn = false;
      numberOfButtonPress = 0;
    // need to add this when i figure out the spinmotor function
    //need to also have it reset potentially
  }
  //check if push botton is pushed
  //start 3000 ms timer
  //count how many times button is pushed by adding 1 to the count every time it is pushed through the loop, before time is at 0
  //after time gets to zero turn motor x amount of times the button was pushed

  // put your main code here, to run repeatedly:

}

void spinMotor (){
  int result;
  result  = numberOfButtonPress * 100;
  Serial.print ("motor spinning time:");
  Serial.println(result);

  digitalWrite(motorPinA1A, LOW);
  digitalWrite (motorPinA1B, HIGH);
   Serial.print ("motor state:");
  Serial.println(digitalRead(motorPinA1A));
  //puts motor on
  delay(result);
  //keeps motor on for certain amount of time
  digitalWrite(motorPinA1A, HIGH);
  digitalWrite(motorPinA1B, HIGH);
  //turns it off
  Serial.println("Motor off.");

}