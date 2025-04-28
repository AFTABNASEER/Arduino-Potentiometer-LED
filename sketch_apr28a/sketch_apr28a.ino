const int potPin = A0;    // Potentiometer connected to analog pin A0
const int ledPin = 10;     // LED connected to PWM pin D9

void setup() {
  Serial.begin(9600);      // Start serial communication for debugging
}

void loop() {
  int potValue = analogRead(potPin); // Read the potentiometer value (0-1023)

  // Map the potentiometer value to a brightness value with max at the center (512)
  int ledBrightness = map(abs(potValue - 512), 0, 512, 255, 0);

  // Print potentiometer value and LED brightness to serial monitor
  Serial.print("Potentiometer Reading: ");
  Serial.print(potValue);  
  Serial.print(" | LED Brightness: ");
  Serial.println(ledBrightness);

  analogWrite(ledPin, ledBrightness); // Set LED brightness based on the mapped value

  delay(100);  // Small delay for readability in the serial monitor
}
