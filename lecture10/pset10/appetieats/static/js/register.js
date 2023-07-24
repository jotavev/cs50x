function goPage(step) {
    const steps = [
        document.querySelector("#firstStep"),
        document.querySelector("#secondStep"),
        document.querySelector("#thirdStep"),
        document.querySelector("#fourthStep")
    ];
    for (let i = 0; i < steps.length; i++) {
        steps[i].style.display = "none";
    }
    console.log(steps)
    if (step >= 1 && step <= steps.length) {
        steps[step - 1].style.display = "block";
    } else {
        console.error("check step number");
    }
}
