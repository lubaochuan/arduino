/*
 * Use Arduino nano with MDD10A driver to control
 * DC motors in sign-magnitude mode.
 * 
 */
// define pin names
int motor_1_pwm = 3;
int motor_1_dir = 4;

// the setup routine runs once when you press reset:
void setup() {
  pinMode(motor_1_pwm, OUTPUT);
  pinMode(motor_1_dir, OUTPUT);
  digitalWrite(motor_1_dir, HIGH);

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  for (int i=0; i<256; i++){
    analogWrite(motor_1_pwm, i);
    Serial.print("motor_1_dir = ");
    Serial.println(i);
    delay(500);
  }
}
