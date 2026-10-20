# 🚂 Automated Smart Railway Crossing and Obstacle Detection System

An autonomous embedded railway safety framework designed and simulated using **Arduino Uno (ATmega328P)** and **Proteus 8 Professional**. The system eliminates human error at unmanned level crossings by utilizing ultrasonic echo sensing, automated servo barrier gates, audio-visual alarms, and a real-time alphanumeric LCD interface.

Developed during the Embedded Systems & IoT Internship at **NexGen Technology, Puducherry**.

---

## 🚀 Key Features

- **Autonomous Train Detection:** Uses an HC-SR04 ultrasonic sensor to calculate real-time distance and trigger crossing procedures.
- **Automated Barrier Control:** SG90 micro-servo dynamically drives gate opening ($0^\circ$) and closing ($90^\circ$).
- **Multi-Modal Warning System:**
  - 🔴 **Red LED + Active Buzzer:** Warning triggered when a train enters the critical detection zone ($<100\text{ cm}$).
  - 🟢 **Green LED:** Safe status indication when the track is clear.
- **Live Status Display:** $16\times2$ LCD displays track clearance and crossing state in real time.
- **EDA Simulation Verified:** Circuit schematic, logic timings, and hex execution fully validated in **Proteus 8 Professional**.

---

## 🛠️ Hardware & Pin Configuration

| Component | Pin (Arduino Uno) | Mode | Function |
| :--- | :--- | :--- | :--- |
| **HC-SR04 (Trig / Echo)** | Pin 9 / Pin 8 | Output / Input | Ultrasonic pulse triggering & flight time echo |
| **SG90 Servo Motor** | Pin 10 | PWM | Level-crossing barrier gate rotation |
| **Active Buzzer** | Pin 13 | Output | Acoustic critical alert |
| **Red LED** | Pin 7 | Output | Danger / Gate Closed visual alert |
| **Green LED** | Pin 6 | Output | Track Clear / Gate Open visual signal |
| **16x2 LCD (RS, E, D4–D7)**| Pins 12, 11, 5, 4, 3, 2 | 4-bit Parallel | Real-time text telemetry display |

---

## ⚙️ Algorithmic Logic & State Machine

1. **Distance Calculation:**
   $$\text{Distance (cm)} = \frac{\text{Echo Pulse Duration } (\mu\text{s}) \times 0.0343}{2}$$
2. **Alert State ($\text{Distance} < 100\text{ cm}$):**
   - Servo Barrier rotates to $90^\circ$ (Gate Closes).
   - Red LED turns ON; Buzzer sounds.
   - LCD displays: `TRAIN DETECTED! / GATE CLOSING...`.
3. **Normal State ($\text{Distance} \ge 100\text{ cm}$):**
   - Servo Barrier returns to $0^\circ$ (Gate Opens).
   - Green LED turns ON; Buzzer silences.
   - LCD displays: `TRACK CLEAR / GATE OPEN`.

---

## 📂 Repository Contents

```
├── smart_railway_crossing.ino    # Arduino control firmware
├── Smart Railway Crossing.pdf     # Engineering design presentation & Proteus results
└── README.md                     # System documentation & simulation analysis
```

---

## 💻 Simulation & Execution

1. **Arduino IDE:**
   - Compile `smart_railway_crossing.ino`.
   - Export compiled Binary (`.hex` file) via `Sketch -> Export Compiled Binary`.
2. **Proteus 8 Professional:**
   - Double-click the ATmega328P / Arduino component.
   - Load the generated `.hex` binary file into the program property.
   - Run simulation and toggle the ultrasonic sensor test voltage to verify dynamic gate closure and LCD output.
