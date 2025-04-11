function checkForUpdate() {
  fetch("/check_update")
    .then(res => res.json())
    .then(data => {
      alert(`Update-Check:\nAktuell: ${data.current}\nVerfügbar: ${data.version}`);
    });
}
