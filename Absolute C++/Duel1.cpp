/*The following is an exercise from Absolute C++.

In the land of Puzzlevania, Aaron, Bob, and Charlie had an argument over which
one of them was the greatest puzzle-solver of all time. To end the argument once
and for all, they agreed on a duel to the death. Aaron was a poor shot and only hit
his target with a probability of 1/3. Bob was a bit better and hit his target with a
probability of 1/2. Charlie was an expert marksman and never missed. A hit means
a kill and the person hit drops out of the duel.

To compensate for the inequities in their marksmanship skills, the three decided
that they would fire in turns, starting with Aaron, followed by Bob, and then by
Charlie. The cycle would repeat until there was one man standing. That man
would be remembered for all time as the Greatest Puzzle-Solver of All Time.
An obvious and reasonable strategy is for each man to shoot at the most accurate
shooter still alive, on the grounds that this shooter is the deadliest and has the best
chance of hitting back.

Write a program to simulate the duel using this strategy. Your program should use
random numbers and the probabilities given in the problem to determine whether
a shooter hits his target.*/

#include <iostream>
#include <ctime>
#include <string>

void aaronShoots(bool& target, std::string& name);
//Randomly return 0,1, or 2. If !=1, missed shot.

void bobShoots(bool& target, std::string& name);
//Randomly return 0 or 1. If ==0, missed shot.

void charlieShoots(bool& target, std::string& name);
//Return 1 since Charlie is Deadshot.

int main()
{
	srand((int)time(0));

	int shot = 0, aaronWin = 0, bobWin = 0, charlieWin = 0;
	std::string aaron = "Aaron", bob = "Bob", charlie = "Charlie";

	for (int i = 0; i < 10000; i++)
	{
		bool aaronAlive = true, bobAlive = true, charlieAlive = true;//Reset alive for loop

		while ((aaronAlive && bobAlive) || (aaronAlive && charlieAlive) || (bobAlive && charlieAlive))
		{
			if (charlieAlive)//Aaron always targets Charlie if he is alive
			{
				aaronShoots(charlieAlive, charlie);
				if (!(bobAlive || charlieAlive))
				{
					aaronWin++;
				}
			}

			else//Aaron targets Bob if Charlie is dead
			{
				aaronShoots(bobAlive, bob);
				if (!(bobAlive || charlieAlive))
				{
					aaronWin++;
				}
			}

			if (bobAlive && charlieAlive)
			{
				bobShoots(charlieAlive, charlie);//Bob always targets Charlie if he is alive
				if (charlieAlive)
				{
					charlieShoots(bobAlive, bob);//Charlie targets Bob since he has better aim than Aaron
				}
			}

			else if (!bobAlive && !charlieAlive)
			{

			}

			else if (!bobAlive && aaronAlive)
			{
				charlieShoots(aaronAlive, aaron);
				charlieWin++;
			}

			else
			{
				bobShoots(aaronAlive, aaron);
				if (!aaronAlive)
					bobWin++;
			}
		}
	}
	std::cout << "Aaron's wins: " << aaronWin << ".\n";
	std::cout << "Bob's wins: " << bobWin << ".\n";
	std::cout << "Charlie's wins: " << charlieWin << ".\n";

	return 0;
}


void aaronShoots(bool& target, std::string& name)
{
	int shot = (rand() % 3);
	if (shot == 1)
	{
		target = false;
	}

}

void bobShoots(bool& target, std::string& name)
{
	int shot = (rand() % 2);
	if (shot == 1)
	{
		target = false;
	}
}

void charlieShoots(bool& target, std::string& name)
{
	target = false;
}