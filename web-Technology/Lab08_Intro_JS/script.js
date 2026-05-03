// 1. Mouse Events to change title color
function changeTitleColor(color) {
    document.getElementById("mainHeading").style.color = color;
}

// 2. Dialog Boxes
function showAlert() {
    alert("This is a simple alert box!");
}

function showConfirm() {
    let result = confirm("Do you want to proceed?");
    let text = result ? "You clicked OK!" : "You clicked Cancel!";
    document.getElementById("dialogResult").innerText = text;
}

function showPrompt() {
    let name = prompt("Please enter your name:", "Guest");
    if (name != null && name != "") {
        document.getElementById("dialogResult").innerText = "Hello, " + name + "!";
    }
}

// 3. DOM Methods
function modifyList() {
    let list = document.getElementById("myList");
    list.style.backgroundColor = "#e0f7fa";
    
    let listItems = document.getElementsByClassName("list-item");
    for (let i = 0; i < listItems.length; i++) {
        listItems[i].style.fontWeight = "bold";
        listItems[i].style.color = "blue";
    }
    
    let allLis = list.getElementsByTagName("li");
    allLis[2].innerText = "Item 3 Modified using TagName!";
}