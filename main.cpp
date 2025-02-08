int red = 13, yellow = 12, green = 11; //Declare the led variables 
int button = 5; //Declare the button location

unsigned long lastTime = 0; //To store the milliseconds passed previously
int time = 0; //To store the time passed since last state change
int state = 0; //To store the state of the lights

void setup() {
  //Set the output pins
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
}

void loop() {
  unsigned long k = millis();
  time += k - lastTime; //Adding the time passed
  lastTime = k; //Setting the last value of millis()

  //If time exceeds one second increment the state and reset the timer
  if (time >= 1000) {
    time = 0;
    state = (++state)%3;
  }

  //If the button is pressed, set the red led to high or change the state to high
  if (digitalRead(button)) state = 0;

  //Handling all the states
  switch(state) {
    case 0:
    digitalWrite(red, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
    break;
    
    case 2:
    digitalWrite(red, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(green, LOW);
    break;
    
    case 1:
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(green, HIGH);
    break;
  }
}
