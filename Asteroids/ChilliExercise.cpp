int calculateDildos(int input) {
	if (input == 1) {
		return 0;
	}

	if (input % 2 == 0) {
		return 1 + calculateDildos(input / 2);
	}

	if (input % 3 == 0 || input % 5 == 0 || input % 9 == 0) {
		return 1 + calculateDildos(input - 1);
	}

	//for 7
	return 1 + calculateDildos(input + 1);
}