let hr = document.getElementById('hr');
let mn = document.getElementById('mn');
let sc = document.getElementById('sc');
let intervalId;

setInterval(()=>{
    let day = new Date();

    hh.innerHTML = (day.getHours()<10?"0":"") + day.getHours();
    mm.innerHTML = (day.getMinutes()<10?"0":"") + day.getMinutes();
    sc.innerHTML = (day.getSeconds()<10?"0":"") + day.getSeconds();
},1000)

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const rpmElement = document.querySelector(".gear");        
const speedElement = document.querySelector(".speedometer");
const tempElement = document.querySelector(".temp-fuel");
const fuelElement = document.querySelector(".temp-fuel");      

var Rpm = document.getElementById('rpmvalue');
var dbRefrpm = firebase.database().ref('Rpm');
var Speed = document.getElementById('speedvalue');
var dbRefspeed = firebase.database().ref('Speed');
var Temp = document.getElementById('tempvalue');
var dbReftemp = firebase.database().ref('Temp');
var Fuel = document.getElementById('fuelvalue');
var dbReffuel = firebase.database().ref('Fuel');

dbRefrpm.on('value', snap => {
    console.log("Rpm: " + snap.val());
    Rpm.innerHTML = snap.val();
    setRpmValue(rpmElement, snap.val());
});  

dbRefspeed.on('value', snap => {
    console.log("Speed: " + snap.val());
    Speed.innerHTML = snap.val();
    setSpeedValue(speedElement, snap.val());
});

dbReftemp.on('value', snap => {
    console.log("Temp: " + snap.val());
    Temp.innerHTML = snap.val();
    setTempValue(tempElement, snap.val()/100);
});  

dbReffuel.on('value', snap => {
    console.log("Fuel: " + snap.val());
    Fuel.innerHTML = snap.val();
    setFuelValue(fuelElement, snap.val()/100);
});

function setRpmValue(gear, valuerpm) {
    if (valuerpm > 8) {
        return;
    }
    gear.querySelector(".gear--needle").style.transform = `rotate(${(valuerpm - 6)*36}deg)`;
}                  

function setSpeedValue(speed, valuespeed) {
    if (valuespeed < 0 || valuespeed > 300) {
        return;
    }
    speed.querySelector(".speedometer--needle").style.transform = `rotate(${(valuespeed - 160)}deg)`;
    if (valuespeed >= 150 && valuespeed <=300) {
        // setInterval(()=>{
        //     const element = document.getElementsByClassName("text--speed")[0];
        //     const currentColor = element.style.color;
        //     if (currentColor === "red") {
        //         element.style.color = "white";
        //     } else {
        //         element.style.color = "red";
        //     }
        // },500) 
        document.getElementsByClassName("text--speed")[0].style.color = "red";
        showWarningSpeedToast ();
    }
    else{
        document.getElementsByClassName("text--speed")[0].style.color = "white";
    }
    document.getElementsByClassName("km")[0].innerText = valuespeed;     
}

function setTempValue(temp, valuetemp) {
    if (valuetemp < 0 || valuetemp > 1) {
        return;
    }
    else {
        temp.querySelector(".temp--needle").style.transform = `rotate(${(valuetemp - 2)*50 - 15}deg)`;
        if (valuetemp >= 0.8 && valuetemp <=1) {
            intervalId = setInterval(()=>{
                const element = document.querySelector(".icon-signal .fi");
                const currentColor = element.style.color;
                if (currentColor === "red") {
                    element.style.color = "white";
                } else {
                    element.style.color = "red";
                }
            },500);
            showWarningTempToast ();
            console.log('toan',intervalId);
        }
        else{
            clearInterval(intervalId);
            document.querySelector(".icon-signal .fi").style.color = "white";
            console.log('toan',intervalId);
        } 
    }
    
}
  

function setFuelValue(fuel, valuefuel) {
    if (valuefuel < 0 || valuefuel > 1) {
        return;
    }
    fuel.querySelector(".fuel--needle").style.transform = `rotate(${(2 - valuefuel)*50 + 15}deg)`;
   
    if (valuefuel >= 0 && valuefuel <=0.2) {  
        intervalId = setInterval(()=>{
            const element = document.querySelector(".icon-signal .fa-solid");
            const currentColor = element.style.color;
            if (currentColor === "red") {
                element.style.color = "white";
            } else {
                element.style.color = "red";
            }
        },1000);     
        showWaringFuelToast ();
    }
    else{
        clearInterval(intervalId);
        document.querySelector(".icon-signal .fa-solid").style.color = "white";
    }
} 

// Toast function
function toast({
    title = '',
    message = '',
    type = 'info',
    duration = 3000
}) {
    const main = document.getElementById('toast');
    if (main) {
        const toast = document.createElement('div');

        // Auto remove toast
        const autoRemoveId = setTimeout(function() {
            main.removeChild(toast);
        }, duration + 2000);

        //Remove toast when click
        toast.onclick = function(e) {
            if (e.target.closest('.toast__close')) {
                main.removeChild(toast);
                clearTimeout(autoRemoveId);
            }
        }

        const icons = {
            success: 'fa fa-check-circle',
            info: 'fa fa-info-circle',
            warning: 'fa fa-exclamation-circle',
            error: 'fa fa-exclamation-circle',
        };
        const icon = icons[type];
        const delay = (duration / 1000).toFixed(2);

        toast.classList.add('toast',`toast--${type}`);
        toast.style.animation = `animation: slideInleft ease 0.3s, fadeOut linear 1s ${delay}s forwards;`;
        toast.innerHTML = `
            <div class="toast__icon">
                <i class="${icon}" aria-hidden="true"></i>
            </div>
            <div class="toast__body">
                <h3 class="toast__title">${title}</h3>
                <p class="toast__msg">${message}</p>
            </div>
            <div class="toast__close">
                <i class="fa fa-times" aria-hidden="true"></i>
            </div>
        `;
        main.appendChild(toast);

        
    }
}



function showWarningTempToast () {
    toast({
    title: 'Warning!',
    message: 'Engine overheating',
    type: 'warning',
    duration: 3000
});
}

function showWarningSpeedToast () {
    toast({
    title: 'Warning!',
    message: 'You drive too fast',
    type: 'warning',
    duration: 3000
});
}

function showWaringFuelToast () {
    toast({
    title: 'Warning!',
    message: 'Gasoline is about to run out',
    type: 'warning',
    duration: 3000
});
}

