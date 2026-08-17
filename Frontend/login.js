const loginForm = document.getElementById("loginForm");

loginForm.addEventListener("submit", function (event) {

    event.preventDefault();

    const username =
        document.getElementById("username").value.trim();

    const password =
        document.getElementById("password").value;

    const errorMessage =
        document.getElementById("errorMessage");


    // Temporary frontend testing only
    if (username === "admin" && password === "admin123") {

        errorMessage.style.color = "green";
        errorMessage.textContent =
            "Login successful!";

    } else {

        errorMessage.style.color = "red";
        errorMessage.textContent =
            "Invalid username or password.";

    }

});