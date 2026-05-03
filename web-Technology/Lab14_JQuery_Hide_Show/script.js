$(document).ready(function(){
    // Hide method
    $("#hideBtn").click(function(){
        $("#box").hide("slow");
    });

    // Show method
    $("#showBtn").click(function(){
        $("#box").show("fast");
    });
    
    // Toggle method (bonus)
    $("#toggleBtn").click(function(){
        $("#box").toggle(500);
    });
});