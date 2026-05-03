// Get the element
const box = document.getElementById("interactiveBox");

// Attach event listener for mouseenter
box.addEventListener("mouseenter", function() {
    box.style.backgroundColor = "#2ecc71"; // Change to green
    box.style.transform = "scale(1.1)"; // Slightly enlarge
    box.innerText = "Mouse Entered! \n(Try leaving now)";
});

// Attach event listener for mouseleave
box.addEventListener("mouseleave", function() {
    box.style.backgroundColor = "#e74c3c"; // Change to red
    box.style.transform = "scale(1.0)"; // Normal size
    box.innerText = "Mouse Left! \n(Hover again)";
});

// Extra: click event
box.addEventListener("click", function() {
    box.style.borderRadius = "50%"; // Make it a circle
    box.innerText = "Clicked! \nNow I'm round.";
});