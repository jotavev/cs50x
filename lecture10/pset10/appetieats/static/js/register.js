function goPage(step) {
    const steps = [
        document.querySelector("#firstStep"),
        document.querySelector("#secondStep"),
        document.querySelector("#thirdStep"),
        document.querySelector("#fourthStep")
    ];
    const currentStep = steps[step - 2]

    if (currentStep) {

        const requiredFields = currentStep.querySelectorAll(".required")

        for (let i = 0; i < requiredFields.length; i++) {
            if (!requiredFields[i].reportValidity() == true) {
                requiredFields[i].reportValidity();
                return
            }
        }
    }

    for (let i = 0; i < steps.length; i++) {
        steps[i].style.display = "none";
    }
    if (step >= 1 && step <= steps.length) {
        steps[step - 1].style.display = "block";
    } else {
        console.error("check step number");
    }
}
