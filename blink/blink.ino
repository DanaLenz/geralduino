void setup() {

  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  String input;
  if (Serial.available()) {
    input = Serial.readStringUntil('\n');
  }
  for (int i = 0, x = input.length(); i < x; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay((input[i] - '0') * 1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  } 

}
