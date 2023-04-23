
const $html = document.querySelector("html");
const body = document.querySelector("main");
let toggle = document.querySelector(".toggle");
let getMode = localStorage.getItem("mode");
if(getMode && getMode === "dark") {
    $html.classList.add("dark-mode");
    toggle.classList.add("active");

}
console.log(getMode);


toggle.addEventListener("click", () => {
    $html.classList.toggle("dark-mode");

    if(!$html.classList.contains("dark-mode")) {
        return localStorage.setItem("mode", "light");
    }
    localStorage.setItem("mode", "dark");
});

toggle.addEventListener("click", () => toggle.classList.toggle("active"));
