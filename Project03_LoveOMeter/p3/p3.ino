const int sensorPin = A0;                   // Analog input
const float baselineTemp = 20.0;

void setup() {
  Serial.begin(9600);                       // Open a serial port

  for(int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);    // Variable to store sensor reading
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  float voltage = (sensorVal/1024.0) * 5.0; // Convert the ADC reading to voltage
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", Degrees C: ");
  float temperature = (voltage - .5) * 100; // Convert the voltage to temperature in C
  Serial.println(temperature);

  if(temperature < baselineTemp + 2) {
    digitalWrite(2, HIGH);                  // RED LED 1
    digitalWrite(3, LOW);                   // RED LED 2
    digitalWrite(4, LOW);                   // RED LED 3
  } else if(
    temperature >= baselineTemp + 2 &&
    temperature < baselineTemp + 4) {
    digitalWrite(2, HIGH);                  // RED LED 1
    digitalWrite(3, HIGH);                  // RED LED 2
    digitalWrite(4, LOW);                   // RED LED 3
  } else if(
    temperature >= baselineTemp + 6) {
    digitalWrite(2, HIGH);                   // RED LED 1
    digitalWrite(3, HIGH);                   // RED LED 2
    digitalWrite(4, HIGH);                   // RED LED 3
  }
  delay(1000);
}