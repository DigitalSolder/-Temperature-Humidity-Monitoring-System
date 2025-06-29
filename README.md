**Enhanced Temperature & Humidity Monitoring System** 

---

# 🌡️ AI-Enhanced Temperature & Humidity Monitoring System

**An Intelligent Environment Monitoring Project using ESP32, OLED, DHT22, RTC, and AI-Mimicked Logic (Simulated on Wokwi)**

---

## 📘 Overview

This project is a **smart temperature and humidity monitoring system** that simulates **AI-based decision-making** using an ESP32 microcontroller. It uses a set of predefined rules derived from **machine learning logic** to trigger alerts intelligently based on environmental conditions and time of day.

The system displays real-time data on an OLED screen, includes a manual **alert mute button**, and can be fully simulated on the **Wokwi platform**.

---

## 🎯 Project Objectives

* 🤖 Simulate basic **AI/ML alert logic** without requiring a trained model
* 🌡️ Monitor temperature and humidity using **DHT22**
* ⏰ Use **time-of-day** in decision-making via RTC DS1307
* 🖥️ Show live environmental data on an **OLED display**
* 🔔 Trigger alerts (LED & buzzer) based on smart decision logic
* 🔇 Allow user to **mute/unmute alerts** using a push button

---

## 🧠 Key Features

### 🔍 Sensors

* 🌡️ **DHT22** – Measures ambient temperature and humidity
* ⏰ **RTC DS1307** – Provides accurate time data (used in logic)

---

### ⚙️ Actuators & Indicators

* 🔔 **Buzzer** – Activates when an AI-like rule-based alert is triggered
* 💡 **LED** – Indicates an alert condition visually
* 🔘 **Push Button** – Toggles mute mode for alerts

---

### 🖥️ User Interface

#### 📟 **OLED Display (SSD1306)**

Displays:

* 🕒 Current time (from RTC)
* 🌡️ Temperature (°C)
* 💧 Humidity (%)
* 🔍 AI Alert status (e.g., “AI ALERT!” or “Normal”)

#### 💬 **Serial Monitor**

* Logs temperature, humidity, time, and system status
* Displays mute status and alert status during runtime

---

## 🤖 Simulated AI Logic

Instead of fixed thresholds, the system uses an **AI-inspired logic tree** based on environmental conditions and time:

```
IF temperature > 32°C AND humidity > 75% → ALERT
ELSE IF temperature > 30°C AND time is between 12–3 PM → ALERT
ELSE IF humidity > 85% AND time is between 6–11 PM → ALERT
ELSE → No Alert
```

This logic mimics a **decision tree classifier** trained from user behavior or environmental patterns.

---

## 🧰 Components Used

| Component        | Function                           |
| ---------------- | ---------------------------------- |
| **ESP32**        | Core controller                    |
| **DHT22**        | Temperature & humidity sensor      |
| **RTC DS1307**   | Real-time clock module             |
| **SSD1306 OLED** | Displays real-time system info     |
| **Buzzer**       | Audio alert on abnormal conditions |
| **LED**          | Visual alert indicator             |
| **Push Button**  | Toggles alert mute mode            |

---

## 🔧 Technologies Used

* **ESP32** with Arduino framework
* **DHT sensor library**
* **Adafruit SSD1306** and **RTClib**
* **Simulated AI/ML logic** (hardcoded rules from decision tree)
* **Wokwi** for simulation

---

## 🧪 System Behavior & Logic

| Condition                        | Action                                       |
| -------------------------------- | -------------------------------------------- |
| Temp > 32°C and Humidity > 75%   | Trigger alert                                |
| Temp > 30°C from 12 PM – 3 PM    | Trigger alert                                |
| Humidity > 85% from 6 PM – 11 PM | Trigger alert                                |
| Button Press                     | Mute/unmute buzzer & LED                     |
| OLED                             | Always displays live sensor and alert status |

---

## 📺 OLED Display Example

```
Time: 14:05
Temp: 31.8 C
Hum : 77.3 %
Status: AI ALERT!
```

---

## 💡 Applications

* 🏠 Smart Climate Monitoring in homes/offices
* 🎓 Academic & research projects (AI + IoT)
* 📈 ML rule emulation without hardware complexity
* 🔬 Edge AI simulation on microcontrollers

---

## 🔁 Future Scope

* Integrate **TinyML** models with TensorFlow Lite Micro (on real ESP32)
* Expand to include light, motion, or CO₂ sensors
* Add **wireless connectivity** (MQTT, Firebase) for real-time cloud sync

---

## 🔗 Try It Live on Wokwi

🎮 **Wokwi Simulation Link**
🔗 [https://wokwi.com/projects/433874417151259137](https://wokwi.com/projects/433874417151259137)

---

Would you like a GitHub-friendly `README.md` version or PDF download too?
