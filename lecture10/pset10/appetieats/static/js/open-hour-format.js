    function formatTimeInput(input) {
        const cleanedInput = input.replace(/[^\d]/g, '');

        if (cleanedInput.length >= 3) {
            const hours = cleanedInput.slice(0, 2);
            const minutes = cleanedInput.slice(2, 4);
            return `${hours}:${minutes}`;
        }

        return cleanedInput;
    }

    function handleTimeInput(inputElement) {
        const currentValue = inputElement.value;

        const formattedValue = formatTimeInput(currentValue);

        inputElement.value = formattedValue;
    }

const timeInputs = document.querySelectorAll('.time');
console.log(timeInputs)
    timeInputs.forEach((input) => {
        input.addEventListener('input', () => handleTimeInput(input));
    });
