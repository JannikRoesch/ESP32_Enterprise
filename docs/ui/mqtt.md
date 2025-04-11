# -------------------------
# 📁 docs/ui/mqtt.md (Beispieldoku)
# -------------------------
Konfiguration

| Feld         | Beschreibung                |
|--------------|-----------------------------|
| Host         | IP oder Domain des Brokers  |
| Port         | Standard: 1883              |
| Topic Pub    | Gerät sendet Status         |
| Topic Sub    | Gerät empfängt Kommandos    |

Beispiel
```json
{
  "mqtt_host": "192.168.1.50",
  "mqtt_port": 1883,
  "topic_pub": "esp32/status",
  "topic_sub": "esp32/cmd"
}

```
