int switchState = 0;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  // (switchState) Checks the chosen pin for voltage
  switchState = digitalRead(2);

  if (switchState == LOW) { // The button is NOT pressed
    digitalWrite(3, HIGH);  // GREEN
    digitalWrite(4, LOW);   // RED 1
    digitalWrite(5, LOW);   // RED 2
  } else {                  // The button IS pressed
    digitalWrite(3, LOW);   // GREEN
    digitalWrite(4, LOW);   // RED 1
    digitalWrite(5, HIGH);  // RED 2

    delay(250);             // Wait for a quarter second
    digitalWrite(4, HIGH);  // Toggle the LEDs
    digitalWrite(5, LOW);
    delay(250);             // Wait for a quarter second
  }
}