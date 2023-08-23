function toggleOverlay() {
    const products = this.parentElement.nextElementSibling;
    console.log(products)
    products.classList.toggle('overlay');
}

const viewAllButtons = document.querySelectorAll('.view-all-button');

viewAllButtons.forEach(button => {
    button.addEventListener('click', toggleOverlay);
});
