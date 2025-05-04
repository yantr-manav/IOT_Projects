# IOT_Projects

This repository contains a collection of IoT (Internet of Things) projects developed by [yantr-manav](https://github.com/yantr-manav). The projects focus on wireless control, automation, and microcontroller-based systems, providing hands-on examples for learning and development in the IoT domain.

---

## 📁 Projects

### 🔧 RC_BOT_Bluetooth

A Bluetooth-controlled robot that can be remotely operated using a smartphone or Bluetooth-enabled device.

#### 🚀 Features

- Wireless control via Bluetooth
- Supports basic movement: forward, backward, left, and right
- Compact, modular design for ease of setup

#### 🧰 Technologies Used

- Arduino or compatible microcontroller
- Bluetooth module (e.g., HC-05)
- Motor driver (e.g., L298N)
- DC motors, chassis, power supply
- C++ for microcontroller code

#### 🛠️ Setup Instructions

1. **Hardware Setup**  
   Assemble the components:
   - Connect the Bluetooth module to the microcontroller (TX, RX, VCC, GND)
   - Connect the motor driver and motors
   - Power the setup appropriately (e.g., battery pack)

2. **Software Upload**  
   - Open the Arduino IDE
   - Load the source code from `RC_BOT_Bluetooth`
   - Select the correct board and COM port
   - Upload the code

3. **Connect via Bluetooth**  
   - Use a mobile app like "Bluetooth Terminal" or a custom app
   - Pair with the HC-05 module (default password: `1234`)
   - Send command characters like:
     - `F` for Forward
     - `B` for Backward
     - `L` for Left
     - `R` for Right
     - `S` for Stop

---

## 🧑‍💻 Getting Started

Clone the repository and explore the project folders:

```bash
git clone https://github.com/yantr-manav/IOT_Projects.git
cd IOT_Projects/RC_BOT_Bluetooth
