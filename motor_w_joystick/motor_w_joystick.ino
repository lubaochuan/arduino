#define PWM_MAX 70
#define FORWARD_HIGH 1023
#define FORWARD_LOW 584
#define BACKWARD_HIGH 496
#define BACKWARD_LOW 0
#define LEFT_HIGH 480
#define LEFT_LOW 0
#define RIGHT_HIGH 1023
#define RIGHT_LOW 565

//#define DEBUG 1

// define pin names
int xAxis = A0;
int yAxis = A1;
int motor_left_pwm = 5;
int motor_left_dir = 6;
int motor_left_speed = 0;
int motor_right_pwm = 3;
int motor_right_dir = 4;
int motor_right_speed = 0;

// the setup routine runs once when you press reset:
void setup() {
  pinMode(motor_right_pwm, OUTPUT);
  pinMode(motor_right_dir, OUTPUT);
  pinMode(motor_left_pwm, OUTPUT);
  pinMode(motor_left_dir, OUTPUT);
  digitalWrite(motor_right_dir, LOW);
  digitalWrite(motor_left_dir, LOW);
#ifdef DEBUG
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
#endif
}

// the loop routine runs over and over again forever:
void loop() {
  int xValue = analogRead(xAxis);
  int yValue = analogRead(yAxis);

#ifdef DEBUG
  // echo sensor values
  Serial.print("x = ");
  Serial.print(xValue);
  Serial.print("\ty = ");
  Serial.println(yValue);
  delay(250);
#endif

  // Y-axis used for forward and backward control
  if (yValue < BACKWARD_HIGH) {
    // Set motros backward
    digitalWrite(motor_left_dir, LOW);
    digitalWrite(motor_right_dir, HIGH);

    // Convert the declining Y-axis readings for going backward from 434 to 0 into 0 to 255 value for the PWM signal for increasing the motor speed
    motor_left_speed = map(yValue, BACKWARD_HIGH, BACKWARD_LOW, 0, PWM_MAX);
    motor_right_speed = motor_left_speed;
  } else if (yValue > FORWARD_LOW) {
    // Set motors forward
    digitalWrite(motor_left_dir, HIGH);
    digitalWrite(motor_right_dir, LOW);

    // Convert the declining Y-axis readings for going backward from 450 to 896 into 0 to 255 value for the PWM signal for increasing the motor speed
    motor_left_speed = map(yValue, FORWARD_LOW, FORWARD_HIGH, 0, PWM_MAX);
    motor_right_speed = motor_left_speed;
  } else{
    motor_left_speed = 0;
    motor_right_speed = 0;
  }

  // X-axis used for left and right control
  if (xValue < LEFT_HIGH) {
    // Convert the declining X-axis readings from 440 to 0 into increasing 0 to 255 value
    int xMapped = map(xValue, LEFT_HIGH, LEFT_LOW, 0, PWM_MAX);
  
    // Move to left - decrease left motor speed, increase right motor speed
    // Add steering threshold to make it easier to go straight
    if(xMapped > 20){
      motor_left_speed -= xMapped;
      motor_right_speed += xMapped;
    }
  } else if (xValue > RIGHT_LOW) {
    // Convert the increasing X-axis readings from 470 to 896 into 0 to 255 value
    int xMapped = map(xValue, RIGHT_LOW, RIGHT_HIGH, 0, PWM_MAX);
    // Move right - decrease right motor speed, increase left motor speed
    if(xMapped > 20){
      motor_left_speed += xMapped;
      motor_right_speed -= xMapped;
    }
  }

  // Confine the range from 0 to PWM_MAX
  if (motor_left_speed < 0) {
    motor_left_speed = 0;
  }
  if (motor_left_speed > PWM_MAX) {
    motor_left_speed = PWM_MAX;
  }

  if (motor_right_speed < 0) {
    motor_right_speed = 0;
  }
  if (motor_right_speed > PWM_MAX) {
    motor_right_speed = PWM_MAX;
  }

  // Prevent buzzing at low speeds (Adjust according to your motors. My motors couldn't start moving if PWM value was below value of 70)
  if (motor_left_speed < 10) {
    motor_left_speed = 0;
  }
  if (motor_right_speed < 10) {
    motor_right_speed = 0;
  }

#ifdef DEBUG
  Serial.print("left speed = ");
  Serial.print(motor_left_speed);
  Serial.print("\t right speed = ");
  Serial.println(motor_right_speed);
#endif

  analogWrite(motor_left_pwm, motor_left_speed);
  analogWrite(motor_right_pwm, motor_right_speed);
}
