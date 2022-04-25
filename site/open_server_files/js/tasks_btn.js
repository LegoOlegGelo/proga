let btn = document.getElementById("tasks_btn");
let list = document.getElementById("tasks_menu");

let state = 0

function tasks_btn_onclick() {
    if (state == 0)
    {
        list.style.visibility = "visible";
        list.style.display = "block";
        state = 1
    }
    else
    {
        list.style.visibility = "none";
        list.style.display = "none";
        state = 0
    }
}

btn.onclick = tasks_btn_onclick;



let cookie_ok = document.getElementById("ok_cookie");
let notify = document.getElementById("notify_div");

function tasks_btn_onclick1() {
    notify.style.visibility = "none";
    notify.style.display = "none";
    
}

cookie_ok.onclick = tasks_btn_onclick1;