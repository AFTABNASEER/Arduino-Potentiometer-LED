# Arduino Potentiometer LED Control

## Description
This is a simple Arduino project that demonstrates how to control an LED's brightness using a potentiometer. The LED's brightness is mapped in a reversed manner: as the potentiometer value increases, the LED dims, and as the potentiometer value decreases, the LED brightens. 

Both the potentiometer value and the corresponding LED brightness are printed on the Serial Monitor for real-time feedback, allowing you to monitor the values as you adjust the potentiometer.

## Components
- Arduino UNO (or any other compatible Arduino board)
- Potentiometer (connected to analog pin A0)
- LED (connected to PWM pin D9)
- Jumper wires

## Circuit
- Connect the middle pin of the potentiometer to analog pin A0 on the Arduino.
- Connect one of the outer pins of the potentiometer to 5V.
- Connect the other outer pin of the potentiometer to GND.
- Connect the long leg (anode) of the LED to pin D9 on the Arduino.
- Connect the short leg (cathode) of the LED to GND.

## Code
```cpp
const int potPin = A0;    // Potentiometer connected to analog pin A0
const int ledPin = 9;     // LED connected to PWM pin D9

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

#How to Use
1. Upload the code to your Arduino board.

2. Open the Serial Monitor (Tools > Serial Monitor or click the magnifying glass icon).

3. Turn the potentiometer to control the LED brightness, with the LED brightest at the middle position of the potentiometer.

