// test max (stall) amp current each motor draws
// define pin names
int motor_left_pwm = 5;
int motor_left_dir = 6;
int motor_left_speed = 0;

// the setup routine runs once when you press reset:
void setup() {
  pinMode(motor_left_pwm, OUTPUT);
  pinMode(motor_left_dir, OUTPUT);
  digitalWrite(motor_left_dir, LOW);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  motor_left_speed = 80;
 
  //Serial.print("left speed = ");
  //Serial.print(motor_left_speed);
  //Serial.print("\t right speed = ");
  //Serial.println(motor_right_speed);
  analogWrite(motor_left_pwm, motor_left_speed);
  delay(500);
}
