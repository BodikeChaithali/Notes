let boxes=document.querySelectorAll(".Box");
let reset=document.querySelector(".reset-button");
let turnO=true;
const winningPartten=[
    [0,1,2],
    [3,4,5],
    [6,7,8],
    [0,3,6],
    [1,4,7],
    [2,5,8],
    [0,4,8],
    [2,4,6]
];

boxes.forEach((Box)=>{
    Box.addEventListener("click",()=>{
        if(turnO){
            Box.innerText="O";
            turnO=false;
        }else{
            Box.innerText="X";
            turnO=true;
        }
        Box.disabled = true
        checkWin();
    })
});

const checkWin=()=>{
    for(let pattern of winningPartten){
        const [a,b,c]=pattern;
        if(boxes[a].innerText && boxes[a].innerText===boxes[b].innerText && boxes[a].innerText===boxes[c].innerText){
            // alert(`${boxes[a].innerText} has won the game`);
            disableBoxes();
            return;
        }
    }
}