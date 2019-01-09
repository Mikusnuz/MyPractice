function changeYear() {
  let year = document.getElementById("year").value;
  let hidden = document.getElementById("hidden").value;
  document.getElementById(year).style.display = "block";
  if (hidden == "null") {
    document.getElementById(year).style.display = "block";
    document.getElementById("hidden").value = year;
  } else {
    document.getElementById(hidden).style.display = "none";
    document.getElementById(year).style.display = "block";
    document.getElementById("hidden").value = year;
  }
}
