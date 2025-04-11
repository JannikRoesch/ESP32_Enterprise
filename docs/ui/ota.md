# OTA Modul – v2.0.0

## Übersicht
Das OTA-Modul erlaubt Firmware-Updates über HTTPs mit JSON-basierter Versionsprüfung.

## Konfiguration

| Einstellung             | Beschreibung                                          |
|--------------------------|-------------------------------------------------------|
| OTA URL                 | Direktlink zur .bin Datei                             |
| Update JSON URL         | JSON-Datei mit Version + Downloadlink                 |
| Automatischer Check     | Führt zyklisch einen Online-Vergleich durch           |
| Automatische Updates    | Installiert Updates ohne Benutzeraktion               |

## Beispiel JSON

```json
{
  "version": "2.0.1",
  "url": "https://example.com/firmware/esp32-v2.0.1.bin",
  "notes": "Fixes und Verbesserungen",
  "mandatory": false
}
```
