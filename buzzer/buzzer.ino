/*
  Buzzer System

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.
*/

// constants won't change. They're used here to set pin numbers:
const int redButtonPin = 2;     //D2
const int yellowButtonPin = 4;  //D4 
const int redLedPin =  13;      //D13
const int yellowLedPin = 12;    //D12
const int buzzerPin = 9;        //D6

// variables will change:
int redButtonState = 0;
int yellowButtonState = 0;
int over = 0;

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(redButtonPin, INPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(yellowButtonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  if(over != 1){
    redButtonState = digitalRead(redButtonPin);
    yellowButtonState = digitalRead(yellowButtonPin);

    if (redButtonState == LOW) {
      tone(buzzerPin, 440); // place note A4
      digitalWrite(redLedPin, HIGH);
      delay(500);
      noTone(buzzerPin);
      over=1;
    } else if(yellowButtonState == LOW) {
      tone(buzzerPin, 440); // place note A4
      digitalWrite(yellowLedPin, HIGH);
      delay(500);
      noTone(buzzerPin);
      over=1;
    }
  }
}
