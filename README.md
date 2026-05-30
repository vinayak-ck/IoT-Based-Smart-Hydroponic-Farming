# 🌱 IoT-Based Smart Hydroponic Farming System

An IoT-powered smart farming system that automates hydroponic crop monitoring using real-time sensor data — enabling efficient, soil-less farming with reduced water consumption.

---

## ✨ Features

- 🌡️ Real-time monitoring of temperature, humidity, and water level
- 💧 Automated water pump control based on sensor thresholds
- 🧪 pH and nutrient level tracking
- 📊 Web dashboard for live data visualization
- 🔔 Threshold alerts for critical conditions
- ♻️ Optimized water usage — minimal waste

---

## 🛠️ Tech Stack

| Layer | Tech |
|---|---|
| Microcontroller | Arduino / ESP32 |
| Sensors | DHT11 (temp/humidity), Ultrasonic (water level), pH sensor |
| Backend | Python |
| Frontend | HTML, CSS, JavaScript |
| Protocol | Serial / Wi-Fi (ESP32) |

---

## 🔌 Hardware Components

| Component | Purpose |
|---|---|
| ESP32 / Arduino | Main controller |
| DHT11 Sensor | Temperature & humidity |
| Ultrasonic Sensor | Water level detection |
| pH Sensor | Nutrient solution acidity |
| Relay Module | Control water pump |
| Water Pump | Automated irrigation |

---

## 🚀 Setup

### Hardware
1. Wire sensors to ESP32 per the circuit diagram
2. Upload `firmware/main.ino` using Arduino IDE
3. Configure Wi-Fi credentials in `config.h`

### Software
```bash
git clone https://github.com/vinayak-ck/IoT-Based-Smart-Hydroponic-Farming.git
cd IoT-Based-Smart-Hydroponic-Farming

pip install -r requirements.txt
python app.py
```

---

## 📊 Dashboard

The web dashboard shows:
- Live sensor readings (temperature, humidity, water level, pH)
- Historical trends with charts
- Pump status and manual override option

---

## 📬 Contact

Built by [Vinayak Kanavalli](https://github.com/vinayak-ck) — vckanavalli@gmail.com
