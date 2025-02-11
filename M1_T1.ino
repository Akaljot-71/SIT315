const int motionSensorPin = 13;
const int ledPin = 2;

void setup() {
  pinMode(motionSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int motionDetected = digitalRead(motionSensorPin);
  
  if (motionDetected == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Motion detected");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("No motion");
  }
  
  delay(500);
}
