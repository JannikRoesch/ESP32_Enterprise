#!/bin/bash
echo "📦 Initialisiere ESP32 Enterprise Library v2.0.0..."
pio lib install
pio run
echo "🔁 Optional: Web UI hochladen mit:"
echo "    pio run --target uploadfs"
echo "⚡ Flashen mit:"
echo "    pio run --target upload"
