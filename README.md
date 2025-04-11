# 🚀 ESP32 Enterprise Library (v2.0.0)

Modularer C++-Framework für professionelles ESP32-Development.  
**Automation, Web-UI, OTA, MQTT, TinyML & mehr.**

## 📚 Inhaltsverzeichnis
1. [Features](#features)
2. [Quickstart](#quickstart)
3. [Admin UI](#admin-ui)
4. [Beispielanwendung](#beispielanwendung)
5. [Dokumentation](#dokumentation)
6. [Changelog](#changelog)

## 🧩 Features
| Modul             | Beschreibung                                  |
|-------------------|-----------------------------------------------|
| WiFi / MQTT       | Verbindung & Kommunikation                    |
| OTA (v2.0.0)      | Update-Check, Auto-Update, Version-Vergleich  |
| Automation Engine | Trigger → Aktion Logik                        |
| WebConfig UI      | Admin UI mit modularen Tabs                   |
| TinyML (Beta)     | TensorFlow Lite Integration                   |

## ⚙️ Quickstart
```bash
pio run --target uploadfs
pio run --target upload
pio device monitor
```

## 🌐 Admin UI
- `http://<esp32-ip>`
- Tabs: Dashboard, Netzwerk, MQTT, OTA, Automation

## 🧪 Beispielprojekt
- Im Ordner `examples/EnterpriseDemo_v1_9/` enthalten.
- Demonstriert **WiFi**, **OTA**, **Automation**, **WebUI** und **Logging**.

## 📘 Dokumentation
- `docs/ui/*.md` für jedes Modul
- `docs/CHANGELOG.md` für Versionen

---

<div align="center">
	<img src="https://jannikroesch.com/src/img/logos/jr/jr-slim-transparent-lightfont/jr-logo-slim-transparent-lightfont-svg.svg" height="64px" />
	<p>Copyright © 2024 Jannik Roesch</p>
	</br>
	<p>Author: Jannik Roesch</p>
	<p>License: MIT</p>
	<p>https://github.com/JannikRoesch</p>
	<p>https://jannikroesch.dev/</p>
	
</div>