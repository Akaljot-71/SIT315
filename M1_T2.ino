const int pirPin = 2;     
const int ledPin = 13;    
bool motionDetected = false;

void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(pirPin), motionDetectedInterrupt, RISING);
  Serial.println("System listening...");
}

void loop() {
  if (motionDetected) {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED ON");
    delay(1000); 
    digitalWrite(ledPin, LOW);
    Serial.println("LED OFF");
    motionDetected = false; 
  }
}

void motionDetectedInterrupt() {
  motionDetected = true;
  Serial.println("Motion Detected!");
}
