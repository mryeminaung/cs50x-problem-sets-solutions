document.addEventListener("DOMContentLoaded", function() {
    const contactForm = document.getElementById("contactForm");

    if (contactForm) {
        contactForm.addEventListener("submit", function(event) {
            event.preventDefault();
            setTimeout(() => {
                alert("Thank you for your message! We will get back to you soon.");
            }, 3000);
        });
    }
});
