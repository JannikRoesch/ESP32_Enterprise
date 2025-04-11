document.addEventListener("DOMContentLoaded", function () {
  const form = document.getElementById("cfgForm");
  const log = document.getElementById("log");

  fetch('/config')
    .then(res => res.json())
    .then(cfg => {
      document.getElementById("mqtt").value = cfg.mqtt_host || '';
      document.getElementById("ota").value = cfg.ota_url || '';
    });

  form.addEventListener("submit", e => {
    e.preventDefault();
    const payload = {
      mqtt_host: document.getElementById("mqtt").value,
      ota_url: document.getElementById("ota").value
    };
    fetch('/save', {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify(payload)
    }).then(r => r.text())
      .then(res => log.textContent = "Gespeichert:\n" + JSON.stringify(payload, null, 2));
  });
});
