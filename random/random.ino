//this variable will hold a random number generated by the random() function
long randomNumber;

//Set up - this is where you get things "set-up". It will only run once
void setup() {
  
  //setup serial communications through the USB
  Serial.begin(9600);

  //Let's make it more random
  randomSeed(42);   
      
}//close setup

void loop() {
  
  //generate a random number
  //randomNumber = random(2,5);
  randomNumber = random(0,2);
 
  //display the random number on the serial monitor
  Serial.print("The Random Number is = ");
  Serial.println(randomNumber);
  
}