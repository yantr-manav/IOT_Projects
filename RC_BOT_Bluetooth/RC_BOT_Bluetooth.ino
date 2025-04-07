#include <BluetoothSerial.h>

// Initialize Bluetooth Serial for ESP32
BluetoothSerial BT;

// ============================
// Motor Driver Pin Definitions
// ============================

// Top-Right Motor
#define TR_EN 12
#define TR_IN1 14
#define TR_IN2 27

// Bottom-Right Motor
#define BR_IN1 25
#define BR_IN2 26
#define BR_EN 33

// Top-Left Motor
#define TL_EN 2
#define TL_IN1 5
#define TL_IN2 4

// Bottom-Left Motor
#define BL_IN1 18
#define BL_IN2 19
#define BL_EN 21

#define SPEED 255 // Max motor speed (PWM value from 0 to 255)

void setup() {
    Serial.begin(115200);                  // Start Serial Monitor
    BT.begin("ESP32_RC_Car");              // Set Bluetooth device name

    // Set all motor input pins as OUTPUT
    pinMode(TR_IN1, OUTPUT);
    pinMode(TR_IN2, OUTPUT);
    pinMode(BR_IN1, OUTPUT);
    pinMode(BR_IN2, OUTPUT);
    pinMode(TL_IN1, OUTPUT);
    pinMode(TL_IN2, OUTPUT);
    pinMode(BL_IN1, OUTPUT);
    pinMode(BL_IN2, OUTPUT);

    // Set enable (PWM) pins as OUTPUT
    pinMode(TR_EN, OUTPUT);
    pinMode(BR_EN, OUTPUT);
    pinMode(TL_EN, OUTPUT);
    pinMode(BL_EN, OUTPUT);

    stopCar();  // Ensure motors are off at startup
    Serial.println("Bluetooth RC Car Ready");

    // Set initial motor speed
    analogWrite(TR_EN, SPEED);
    analogWrite(BR_EN, SPEED);
    analogWrite(TL_EN, SPEED);
    analogWrite(BL_EN, SPEED);
}

// ============================
// Movement Functions
// ============================

// Stop all motors
void stopCar() {
    digitalWrite(TR_IN1, LOW);
    digitalWrite(TR_IN2, LOW);
    digitalWrite(BR_IN1, LOW);
    digitalWrite(BR_IN2, LOW);
    digitalWrite(TL_IN1, LOW);
    digitalWrite(TL_IN2, LOW);
    digitalWrite(BL_IN1, LOW);
    digitalWrite(BL_IN2, LOW);
}

// Move all motors forward
void forward() {
    digitalWrite(TR_IN1, HIGH); digitalWrite(TR_IN2, LOW);
    digitalWrite(BR_IN1, HIGH); digitalWrite(BR_IN2, LOW);
    digitalWrite(TL_IN1, HIGH); digitalWrite(TL_IN2, LOW);
    digitalWrite(BL_IN1, HIGH); digitalWrite(BL_IN2, LOW);
}

// Move all motors backward
void backward() {
    digitalWrite(TR_IN1, LOW); digitalWrite(TR_IN2, HIGH);
    digitalWrite(BR_IN1, LOW); digitalWrite(BR_IN2, HIGH);
    digitalWrite(TL_IN1, LOW); digitalWrite(TL_IN2, HIGH);
    digitalWrite(BL_IN1, LOW); digitalWrite(BL_IN2, HIGH);
}

// Turn Right: left motors forward, right motors backward
void turnRight() {
    digitalWrite(TR_IN1, LOW); digitalWrite(TR_IN2, HIGH);     // TR reverse
    digitalWrite(BR_IN1, LOW); digitalWrite(BR_IN2, HIGH);     // BR reverse
    digitalWrite(TL_IN1, HIGH); digitalWrite(TL_IN2, LOW);     // TL forward
    digitalWrite(BL_IN1, HIGH); digitalWrite(BL_IN2, LOW);     // BL forward
}

// Turn Left: left motors backward, right motors forward
void turnLeft() {
    digitalWrite(TR_IN1, HIGH); digitalWrite(TR_IN2, LOW);     // TR forward
    digitalWrite(BR_IN1, HIGH); digitalWrite(BR_IN2, LOW);     // BR forward
    digitalWrite(TL_IN1, LOW); digitalWrite(TL_IN2, HIGH);     // TL reverse
    digitalWrite(BL_IN1, LOW); digitalWrite(BL_IN2, HIGH);     // BL reverse
}

// ============================
// Main Loop - Bluetooth Control
// ============================
void loop() {
    // Check for incoming Bluetooth data
    if (BT.available()) {
        char command = BT.read();         // Read single character command
        Serial.print("Received: ");
        Serial.println(command);

        // Match command with respective movement
        switch (command) {
            case 'F': forward(); break;   // Move Forward
            case 'B': backward(); break;  // Move Backward
            case 'L': turnLeft(); break;  // Turn Left
            case 'R': turnRight(); break; // Turn Right
            case 'S': stopCar(); break;   // Stop
            default: stopCar(); break;    // Unknown command -> Stop
        }
    }
}
