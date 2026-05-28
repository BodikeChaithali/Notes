let boxes=document.querySelectorAll(".box");
let resetbtn=document.querySelector("#Reset-btn");
let turnO = true;
 const winpatterns = [
    [0,1,2],
    [0,3,6],
    [0,4,8],
    [1,4,7],
    [2,5,8],
    [2,4,6],
    [3,4,5],
    [6,7,8]
 ];
 boxes.forEach((box) => {
    boxes.addEventListener("click",() => {
        console.log("Box was clicked");
        if(turnO === true) {
            box.innertext = "O";
            turnO = false;
        }
        else {
            box.innertext="X";
            turnO = true;
        }
        box.disabled = true;

        checkwinner();
    });
 });
  const checkwinner = () => {
    for(let pattern of winpatterns) 
  }