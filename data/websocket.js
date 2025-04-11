const logElem = document.getElementById("wsLog");
const socket = new WebSocket(`ws://${location.hostname}:81/`);

socket.onmessage = function (event) {
  logElem.textContent += event.data + "\\n";
  logElem.scrollTop = logElem.scrollHeight;
};
