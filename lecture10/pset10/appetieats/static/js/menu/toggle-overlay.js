const viewAllButtons = document.querySelectorAll('.view-all-button');
const backButtons = document.querySelectorAll('.back-button');
const overlayContainers = document.querySelectorAll('.overlay');

viewAllButtons.forEach((button, index) => {
    button.addEventListener('click', () => {
        overlayContainers[index].classList.add('active');
    });
});

backButtons.forEach((button, index) => {
    button.addEventListener('click', () => {
        overlayContainers[index].classList.remove('active');
    });
});
