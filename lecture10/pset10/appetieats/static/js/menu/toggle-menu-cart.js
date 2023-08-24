document.addEventListener("DOMContentLoaded", function() {
    const navLinks = document.querySelectorAll(".nav_link");
    const menuDiv = document.querySelector(".menu");
    const cartDiv = document.querySelector(".cart");

    navLinks.forEach(link => {
        link.addEventListener("click", function(event) {
            event.preventDefault();
            const target = this.getAttribute("href");

            if (target === "#menu") {
                menuDiv.style.transform = "translateX(0)";
                cartDiv.style.transform = "translateX(100%)";
                navLinks[0].classList.add("active");
                navLinks[1].classList.remove("active");
            } else if (target === "#cart") {
                menuDiv.style.transform = "translateX(-100%)";
                cartDiv.style.transform = "translateX(0)";
                navLinks[1].classList.remove("active");
                navLinks[0].classList.add("active");
            }
        });
    });
});
