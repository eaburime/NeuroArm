#include <Servo.h>

// Define Servo Motors for Finger Movements
Servo thumb;
Servo indexFinger;
Servo middleFinger;
Servo ringFinger;
Servo pinky;

// Define EKG Sensor Input Pin
const int ekgPin = A0;  // Analog pin for EKG sensor
int ekgValue = 0;       // Variable to store sensor reading

void setup() {
    Serial.begin(9600);  // Start serial communication for debugging
    
    // Attach servo motors to Arduino pins
    thumb.attach(3);
    indexFinger.attach(5);
    middleFinger.attach(6);
    ringFinger.attach(9);
    pinky.attach(10);
    
    Serial.println("NeuroArm Initialized...");
}

void loop() {
    // Read the muscle activity from EKG sensor
    ekgValue = analogRead(ekgPin);
    
    Serial.print("EKG Signal: ");
    Serial.println(ekgValue); // Print the signal for debugging

    // If muscle activity is detected (threshold can be adjusted)
    if (ekgValue > 500) {
        Serial.println("Muscle movement detected! Moving fingers...");
        
        // Move fingers to simulate a grip
        thumb.write(0);        // Close thumb
        indexFinger.write(30); // Close index
        middleFinger.write(30);// Close middle
        ringFinger.write(30);  // Close ring
        pinky.write(30);       // Close pinky
    } else {
        // Relax the fingers
        thumb.write(90);
        indexFinger.write(90);
        middleFinger.write(90);
        ringFinger.write(90);
        pinky.write(90);
    }

    delay(100); // Short delay to stabilize readings
}

