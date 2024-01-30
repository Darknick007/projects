let game = false; //gioco

//variabili di lavoro che rappresentano oggetti html/css
var targetElement = document.querySelector(".target");
var button = document.getElementById("restart");
var containergame = document.getElementById("game");
var dot = document.getElementById("dot");
var score = document.getElementById("score");

var targets = []; //array di target
var target; //target singolo membro di array targets
const numtargets = 3; // numeri di quanti target ci sono
var numrandomX; //posizione casuale X in cui il target verrà mosso
var numrandomY; //posizione casuale Y in cui il target verrà mosso
var counter=0; //volte in cui è stato premuto un target
var accuracy; // precisione ovvero click/numtargetmoved
var click=0; //click nel game
var numTargetMoved = 0; //numeri movimenti bersagli
const GamelenghtMs = 10000;  //modificare per modificare durata gioco
const IntervalMsRandPos = 2000;  //modificare per modificare velocità targetElement
var i; //variabile di lavoro
var precision=0; // % di bersagli colpiti in base ai click
var Dotx; //X dove il punto verrà inserito
var Doty; //Y dove il punto verrà inserito
//var maxWidth = window.innerWidth * 0.9 - 100; //usato per generare un punto casuale per il target (-100 perchè grandezza target)
//var maxHeight = window.innerHeight * 0.9 -100; //usato per generare un punto casuale per il target
var Results= []; //arrray che si salva i risultati




  
    
  

button.addEventListener("click", ()=> {
    
    if(game){
        alert("riavvio");
    }
    else{
        //riavvio i dati
        game=true;
        counter=0;
        click=0;
        numTargetMoved=0;
        //avvio il gioco
        startGame();
    }
})

containergame.addEventListener("click", function(event) {
    if (event.target === containergame) {
        // mostra il pallino grigio nella posizione del clic
         Dotx = event.clientX - containergame.getBoundingClientRect().left;
         Doty = event.clientY - containergame.getBoundingClientRect().top;

        dot.style.left = Dotx + 'px';
        dot.style.top = Doty + 'px';
        dot.style.display = 'block';

        // nascondere pallino dopo x secondi
        setTimeout(function() {
          dot.style.display = 'none';
        }, 5000);
      }
   click = click+1;
   console.log(click);
    
}); 
















function startGame() {
    //genero i target
    GenerateTargets();
    //aggiungo click ai target

    
    addEventListenerToTargets();
    //setto interval che ogni secondo deve essere spostato targetElement
    interval = setInterval(() => {
      
      moveTargets();
      SetTexts();
    }, IntervalMsRandPos);
    //setto secondi tempo che finisce lo spostamento
    setTimeout(() => {
      clearInterval(interval);
      game = false;
      //rimuovo elementi dell'array dalla pagina
      Remove();
      //salvo statistiche

    }, GamelenghtMs);
    
  }










function RandomPosition(element){
    
     numrandomX= Math.floor(Math.random()*1600  + 1);
     numrandomY= Math.floor(Math.random()*600 + 1);
    element.style.left = numrandomX + "px";
    element.style.top = numrandomY + "px";
    //ogni movimento del target significa che c'è stata un occasione in più per cliccare il target
    
    console.log(numTargetMoved)
}






function GenerateTargets(){
    for(i=0;i<numtargets;i++){
        target = document.createElement("div");
        target.className = "target";
        containergame.appendChild(target);
        
        targets.push(target);
        RandomPosition(target);
    }
    

    
}

function moveTargets(){
    //sposta ogni target in modo casuale
    targets.forEach(target =>{
        RandomPosition(target);
    });
    numTargetMoved += numtargets;
    console.log(numTargetMoved);
}

function addEventListenerToTargets() {
    //aggiungo i click per ogni target dentro a targets
    targets.forEach(target => {
        target.addEventListener("click", () => {
            counter = counter+ 1;
            console.log("Counter:", counter);            
            target.style.top = "-600px";
        });
    });
}

function SetTexts(){
    precision = (counter / click) * 100;
    score.textContent = "Score= " + counter + "/" + numTargetMoved + " Precision:" + precision.toFixed(2) + "%";


}
function Remove() {
    //rimuovo i target dentro a targets da containergame usando i parentnode
    targets.forEach(target => {
        if (target.parentNode) {
            target.parentNode.removeChild(target);
        }
    });
    // svuoto l'array
    targets = [];
}
function Savestats(){
    Results.push(precision);
    Results.push(counter);
    Results.push(numTargetMoved);
}