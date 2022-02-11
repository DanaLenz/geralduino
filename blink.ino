void setup() {

  Serial.begin(9600);

}

void loop() {

  int password;

  // read input once
  while(!Serial.available())
    ;

  while(Serial.available()){

    int newDigit = Serial.read();
    
    // Shift all digits left, add new last digit
    password = (password*10) + newDigit;
  }

  // Send to LED:
  Serial.print("Password is: ");
  Serial.println(password);

}
