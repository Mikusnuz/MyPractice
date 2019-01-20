let express = require("express");
let app = express();
let http = require("http").Server(app);
let io = require("socket.io")(http);
var path = require("path");
var UDPPORT = 3001;
var TCPPORT = 3000;
var HOST = "127.0.0.1";
var dgram = require("dgram");
var server = dgram.createSocket("udp4");

function sendTo(msg) {
  msg = new Buffer(msg);
  server.send(msg, 0, msg.length, TCPPORT, HOST, (err, bytes) => {
    if (err) throw err;
    console.log("Server => Client : " + msg);
  });
}

app.get("/", function(req, res) {
  res.sendFile(__dirname + "/index.html");
});

server.on("message", (msg, remote) => {
  io.emit("chat message", msg.toString());
});

io.on("connection", socket => {
  socket.on("chat message", msg => {
    io.emit("chat message", msg.toString());
    sendTo(msg);
  });
});

http.listen(TCPPORT, () => {
  console.log("listening on *: SOCKETIO");
});
server.on("listening", () => {
  var addr = server.address();
  console.log("listening on *: UDP");
});

server.bind(UDPPORT, HOST);
app.use(express.static(path.join(__dirname, "css")));
app.use(express.static(path.join(__dirname, "js")));
