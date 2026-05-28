function changeTheme() {
  document.body.classList.toggle("dark-mode");
}
function checkNumber() {
  const num = document.getElementById("numInput").value;

  if (num === "") {
    alert("Please enter a number!");
  } else if (num % 2 === 0) {
    alert(num + " is an Even number.");
  } else {
    alert(num + " is an Odd number.");
  }
}

function changeText() {
  const msg = document.getElementById("message");
  msg.textContent = "You are learning DOM Manipulation with JavaScript!";
  msg.style.color = "blue";
}

console.log("---- JavaScript Examples ----");
let myVariable = 42;
console.log("Variable:", myVariable);

function greet(name) {
  return `Hello, ${name}!`;
}
console.log("Function:", greet("Student"));

let myArray = [10, 20, 30, 40];
console.log("Array:", myArray);

let myObject = { name: "Alice", age: 22, course: "Web Development" };
console.log("Object:", myObject);
