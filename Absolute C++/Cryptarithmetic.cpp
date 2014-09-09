// This program is designed to solve a certain cryptarithmetic puzzle. In cryptarithmetic puzzles		//
// mathematical equations are written using letters. Each letter can be a digit from 0 to 9 but			//
// no two letters can be the same. A sample problem: SEND + MORE = MONEY has a solution with S = 9		//
// R = 8, O = 0, M = 1, Y = 2, E = 5, N = 6, D = 7. So we have that 9567 + 1085 = 10652. The following	//
// program solves the puzzle TOO + TOO + TOO + TOO = GOOD.												//

#include <iostream>

int main()
{
	int t, o, g, d;
	int good = 0, too = 0;

	for (int i = 0; i <= 9; i++)
	{
		t = i;

		for (int j = 0; j <= 9; j++)
		{
			o = j;

			for (int k = 0; k <= 9; k++)
			{
				g = k;

				for (int m = 0; m <= 9; m++)
				{
					d = m;

					if ((t == o) || (t == d) || (t == g) || (g == o) || (g == d) || (d == o))
						continue;// Make sure values are unique

					too = (100 * t) + (10 * o) + o;
					good = (1000 * g) + (100 * o) + (10 * o) + d;
					if (4 * too == good)
					{
						std::cout << "Too + Too + Too + Too = " << 4 * too << std::endl;
						std::cout << "Good = " << good << std::endl;
						std::cout << "So t = " << t << ", o  = " << o << ", g = " << g << ", d = " << d
							<< std::endl << std::endl;
					}
					else
						continue;
				}

			}

		}




	}
	return 0;
}
