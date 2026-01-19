document.addEventListener("DOMContentLoaded", function () {
	partOneLogic();
	partTwoLogic();
});

function partOneLogic() {
	// Part 1: Multiple Choice

	// get elements using querySelector
	let btnAll = document.querySelectorAll(".btn");
	let btn1 = document.querySelector(".btn1");
	let btn2 = document.querySelector(".btn2");
	let btn3 = document.querySelector(".btn3");
	let btn4 = document.querySelector(".btn4");
	let btn5 = document.querySelector(".btn5");
	let correctAlert = document.querySelector(".correct-alert");
	let incorrectAlert = document.querySelector(".incorrect-alert");

	// pre-define correct answer
	let correctAnsId = 2;

	// checking answer
	let handleAnswerCheck = (e, ansId) => {
		if (ansId === correctAnsId) {
			// remove bg colors of all incorrect answers
			btnAll.forEach((btn, i) => {
				if (i !== correctAnsId) btn.classList.remove("incorrect-answer");
			});
			// add bg color to current correct answer
			e.target.classList.add("correct-answer");
			// show correct alert
			correctAlert.style.display = "block";
			incorrectAlert.style.display = "none";
		} else {
			btnAll.forEach((btn, i) => {
				// remove bg color from correct answer
				if (i == correctAnsId) btn.classList.remove("correct-answer");
				// remove be colors of other incorrect answers
				else btn.classList.remove("incorrect-answer");
			});
			// add bg color to current incorrect answer
			e.target.classList.add("incorrect-answer");
			// show incorrect alert
			correctAlert.style.display = "none";
			incorrectAlert.style.display = "block";
		}
	};

	btn1.addEventListener("click", (event) => {
		handleAnswerCheck(event, 0);
	});

	btn2.addEventListener("click", (event) => {
		handleAnswerCheck(event, 1);
	});

	btn3.addEventListener("click", (event) => {
		handleAnswerCheck(event, 2);
	});

	btn4.addEventListener("click", (event) => {
		handleAnswerCheck(event, 3);
	});

	btn5.addEventListener("click", (event) => {
		handleAnswerCheck(event, 4);
	});
}

function partTwoLogic() {
	// Part 2: Free Response

	// get elements using querySelector
	let ansInput = document.querySelector("#ans-input");
	let ansForm = document.querySelector("#free-response");
	let freeCorrectAlert = document.querySelector(".free-correct-alert");
	let freeIncorrectAlert = document.querySelector(".free-incorrect-alert");

	// define correct answer
	let correctAnswer = "belongsToMany";

	let handleFreeResponse = (e) => {
		e.preventDefault();
		// if input is empty, show alert
		if (!ansInput.value.trim()) {
			ansInput.classList.remove("free-correct-input");
			ansInput.classList.remove("free-incorrect-input");

			freeCorrectAlert.style.display = "none";
			freeIncorrectAlert.style.display = "none";

			setTimeout(() => {
				alert("Type something...");
			}, 100);
		} else {
			if (ansInput.value.trim() === correctAnswer) {
				ansInput.classList.add("free-correct-input");
				ansInput.classList.remove("free-incorrect-input");

				freeCorrectAlert.style.display = "block";
				freeIncorrectAlert.style.display = "none";
			} else {
				ansInput.classList.add("free-incorrect-input");
				ansInput.classList.remove("free-correct-input");

				freeCorrectAlert.style.display = "none";
				freeIncorrectAlert.style.display = "block";
			}
		}
	};

	ansForm.addEventListener("submit", (event) => handleFreeResponse(event));
}
