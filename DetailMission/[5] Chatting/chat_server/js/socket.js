$(function() {
  var socket = io();
  $("form").submit(function(e) {
    e.preventDefault(); // prevents page reloading
    socket.emit("chat message", $("#send").val());
    $("#send").val("");
    return false;
  });
  socket.on("chat message", function(msg) {
    $("#messages").append($("<li>").text(msg));
  });
});
