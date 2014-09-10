/* This program takes as input a number n and attempts to guess its square root
   by means of the Babylonian algorithm.*/

#include <iostream>

int main()
{
	double n;
	std::cout << "Enter a number n to compute Babylonian Algorithm: ";
	std::cin >> n;
	std::cout << std::endl;
	double guess = n / 2, r, oldGuess = guess;
	
	do
	{
		oldGuess = guess;
		r = n / guess;
		guess = (guess + r) / 2;
	} while ((oldGuess - guess) > .01);
	
	std::cout << "Guess is " << guess << std::endl;
	return 0;
}