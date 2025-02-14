#define PIR_PIN 2
#define TEMP_SENSOR_PIN A1
#define LED_PIN 13

bool motionDetected = false;

void motionISR();

void setup() {
    pinMode(PIR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);

    Serial.begin(9600); 
    Serial.println("System Started");

    attachInterrupt(digitalPinToInterrupt(PIR_PIN), motionISR, RISING);
}

void loop() {
    if (motionDetected) {
        Serial.println("Motion Detected!");
        digitalWrite(LED_PIN, HIGH);
      	Serial.println("LED ON");
        delay(2000);
        digitalWrite(LED_PIN, LOW);
        Serial.println("LED OFF.");
        motionDetected = false;
    }
    checkTemperature();
    delay(2000);
}

void motionISR() {
    motionDetected = true;
}

void checkTemperature() {
    int sensorValue = analogRead(TEMP_SENSOR_PIN);
    float voltage = (sensorValue / 1023.0) * 5.0;
    float temperature = (voltage - 0.5) * 100;

    Serial.print("Temperature detected: ");
    Serial.print(temperature);
    Serial.println(" °C");  

    if (temperature > 30.0) {
        Serial.println("High Temperature Detected!");
        digitalWrite(LED_PIN, HIGH);
        Serial.println("LED turned ON");
        delay(1000);
        digitalWrite(LED_PIN, LOW);
        Serial.println("LED turned OFF.");
    }
}
