/*
   A couple simple functions to test using the motor shield with
   two wheels on seperate motors.
*/

int state = 0;
// Pins fürs (?) Rad (Channel A)
int dirA = 12;
int pwrA = 3;
int brkA = 9;

// Pins fürs (?) Rad (Channel)
int dirB = 13;
int pwrB = 11;
int brkB = 8;

// define work duties
int w_low = 50;
int w_high = 100;

// state: standing=0, forward=1, backward=2, turnA=3, turnB=4


void setup() {

  // --- define pins --- //

  pinMode(dirA, OUTPUT);
  pinMode(pwrA, OUTPUT);
  pinMode(brkA, OUTPUT);

  pinMode(dirB, OUTPUT);
  pinMode(pwrB, OUTPUT);
  pinMode(brkB, OUTPUT);

  // ------------------- //

}


void loop() {
  slow();
  delay(2000);
  brake();
  delay(1000);
  fast();
  delay(2000);
  brake();
  delay(1000);
}

void brake() {

  digitalWrite(brkA, HIGH);
  analogWrite(pwrA, 0);
  digitalWrite(brkB, HIGH);
  analogWrite(pwrB, 0);
  state = 0;

}

void reverse() {

  // don't look this is not good code

  // standing
  if (state == 0)
    return;

  digitalWrite(brkA, LOW);
  digitalWrite(brkB, LOW);

  // forward
  if (state == 1) {

    digitalWrite(dirA, LOW);
    digitalWrite(dirB, LOW);
    state = 2;

  } else if (state == 2) {

    digitalWrite(dirA, HIGH);
    digitalWrite(dirB, HIGH);
    state = 1;

  } else if (state == 3)
    turnB();

  else if (state == 4)
    turnA();


}

void slow() {

  digitalWrite(brkA, LOW);
  digitalWrite(brkB, LOW);

  analogWrite(pwrA, w_low);
  analogWrite(pwrB, w_low);

}

void fast() {

  digitalWrite(brkA, LOW);
  digitalWrite(brkB, LOW);

  analogWrite(pwrA, w_high);
  analogWrite(pwrB, w_high);

}

void turnA() {

  digitalWrite(brkA, LOW);
  digitalWrite(brkB, LOW);

  digitalWrite(dirA, HIGH);
  analogWrite(pwrA, w_low);

  digitalWrite(dirB, LOW);
  analogWrite(pwrB, w_low);

  state = 3;

}


void turnB() {

  digitalWrite(brkA, LOW);
  digitalWrite(brkB, LOW);

  digitalWrite(dirB, HIGH);
  digitalWrite(pwrB, LOW);

  digitalWrite(dirA, LOW);
  digitalWrite(pwrA, LOW);

  state = 4;

}
