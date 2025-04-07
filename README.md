# 🚗 Bluetooth-Controlled ESP32 4WD Robot Car

This project demonstrates a **Bluetooth-enabled 4-wheel drive robotic car using ESP32**, which can be controlled via simple Bluetooth commands from a smartphone or other Bluetooth-enabled devices.

---

## 📦 Components Used

| Component               | Quantity | Description                                                |
|------------------------|----------|------------------------------------------------------------|
| ESP32 Dev Board        | 1        | Microcontroller with built-in Bluetooth and WiFi          |
| L298N Motor Driver     | 2        | Controls the 4 DC motors (2 motors per driver)             |
| DC Motors              | 4        | For 4-wheel drive                                          |
| Wheels                 | 4        | Compatible with DC motors                                  |
| Power Supply (Battery) | 1        | 7.4V or 12V Li-ion / LiPo Battery pack                     |
| Jumper Wires           | —        | For making necessary connections                           |
| Breadboard (optional)  | 1        | For organizing circuits (optional)                         |
| Chassis                | 1        | Body frame for mounting all components                     |

---

## 🔌 Pin Configuration

| Motor         | Enable Pin | Input1   | Input2   |
|---------------|------------|----------|----------|
| Top Right     | GPIO 12    | GPIO 14  | GPIO 27  |
| Bottom Right  | GPIO 33    | GPIO 25  | GPIO 26  |
| Top Left      | GPIO 2     | GPIO 5   | GPIO 4   |
| Bottom Left   | GPIO 21    | GPIO 18  | GPIO 19  |

---

## 🎮 Command Format (Bluetooth Input)

| Command | Action      |
|---------|-------------|
| `F`     | Forward     |
| `B`     | Backward    |
| `L`     | Turn Left   |
| `R`     | Turn Right  |
| `S`     | Stop        |

---

## 🧠 Working Principle

- **Bluetooth Serial** communication is established using `BluetoothSerial.h`.
- Commands received over Bluetooth are parsed using `BT.read()` and trigger movement functions.
- `analogWrite()` sets the motor speed through EN pins.
- Each motor is controlled independently for precise direction control.

---

## 🛠 Setup Instructions

1. Connect the ESP32 to the motor drivers according to the pin configuration table.
2. Power the ESP32 and motor drivers using a suitable battery (7.4V or 12V).
3. Upload the code to your ESP32 via the Arduino IDE.
4. Open a Bluetooth terminal app and pair with **ESP32_RC_Car**.
5. Send commands (`F`, `B`, `L`, `R`, `S`) and the robot will respond accordingly.

---

## 🖼 Circuit/Wiring Diagram

![Wiring Diagram](./A_README_document_and_wiring_diagram_image_display.png)

> **Note**: Ensure the battery voltage is within a safe operating range and polarities are correctly connected.

---

## ✅ Features

- Wireless Bluetooth control
- Four-motor independent control
- Directional movements: forward, backward, left, right
- Speed control using PWM
- Easy expandability for sensors

---

## 🔧 Future Improvements

- Integrate Ultrasonic sensor for obstacle avoidance
- Add IR sensors for line following
- Create a custom Android control app
- Implement voice control

---

## 📄 License

MIT License. Feel free to use, modify, and distribute this project with proper attribution.

---

## 🙌 Contributions

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change or improve.

---
