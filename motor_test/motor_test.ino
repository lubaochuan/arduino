/*
 * Use Arduino nano with MDD10A driver to control
 * DC motors in anti-hased mode.
 * 
 */
// define pin names
int motor_1_pwm = 3;
int motor_2_pwm = 4;
int motor_1_dir = 5;
int motor_2_dir = 6;

// the setup routine runs once when you press reset:
void setup() {
  pinMode(motor_1_pwm, OUTPUT);
  pinMode(motor_2_pwm, OUTPUT);
  pinMode(motor_1_dir, OUTPUT);
  pinMode(motor_2_dir, OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(motor_1_pwm, HIGH);
  digitalWrite(motor_2_pwm, HIGH);
  for (int i=0; i<256; i++){
    analogWrite(motor_1_dir, i);
    analogWrite(motor_2_dir, 256-i);
    Serial.print("motor_1_dir = ");
    Serial.println(i);
    delay(500);
  }
}
