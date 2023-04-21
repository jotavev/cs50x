// Example starter JavaScript for disabling form submissions if there are invalid fields
(function() {
    'use strict';
    window.addEventListener('load', function() {
        // Fetch all the forms we want to apply custom Bootstrap validation styles to
        var forms = document.getElementsByClassName('needs-validation');
        // Loop over them and prevent submission
        var validation = Array.prototype.filter.call(forms, function(form) {
            form.addEventListener('submit', function(event) {
                if (form.checkValidity() === false) {
                    event.preventDefault();
                    event.stopPropagation();
                }
                form.classList.add('was-validated');
            }, false);
        });
    }, false);
})();

function showModal() {
    const myModal = document.getElementById('modal');
    const modal = new bootstrap.Modal(myModal);
    modal.show();
}

function checkUrlToShowModal() {
  var url = window.location.href;
  if (url.endsWith("?")) {
    showModal();
  }
}

function openLink(link) {
    window.open(link, "_blank");
}

window.onload = function() {
  checkUrlToShowModal();
}
