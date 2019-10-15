// define pin names
int xAxis = A0;

void setup() {
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  int xValue = analogRead(xAxis);

  Serial.print("x = ");
  Serial.println(xValue);
  delay(250);
}
