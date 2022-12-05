#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main()
{
	std::fstream input;
	input.open("input.txt", std::ios::in);

	if (input.good() == true)
	{
		//part 1
		//two dimensional map to define scores for each possible pair
		// A, X = rock
		// B, Y = paper
		// C, Z = scissors
		std::map<std::pair<char, char>, int> results;
		results[std::make_pair('A', 'X')] = 4;
		results[std::make_pair('A', 'Y')] = 8;
		results[std::make_pair('A', 'Z')] = 3;

		results[std::make_pair('B', 'X')] = 1;
		results[std::make_pair('B', 'Y')] = 5;
		results[std::make_pair('B', 'Z')] = 9;

		results[std::make_pair('C', 'X')] = 7;
		results[std::make_pair('C', 'Y')] = 2;
		results[std::make_pair('C', 'Z')] = 6;

		//part 2
		//two dimensional map to define scores for each possible pair
		// A= rock
		// B= paper
		// C= scissors
		// X= lose
		// Y= draw
		// Z= win
		std::map<std::pair<char, char>, int> results2;
		results2[std::make_pair('A', 'X')] = 3;
		results2[std::make_pair('A', 'Y')] = 4;
		results2[std::make_pair('A', 'Z')] = 8;

		results2[std::make_pair('B', 'X')] = 1;
		results2[std::make_pair('B', 'Y')] = 5;
		results2[std::make_pair('B', 'Z')] = 9;

		results2[std::make_pair('C', 'X')] = 2;
		results2[std::make_pair('C', 'Y')] = 6;
		results2[std::make_pair('C', 'Z')] = 7;

		int score = 0; //part 1 score
		int score2 = 0; //part 2 score 
		
		std::string round;
		while (!input.eof())
		{
			std::getline(input, round);
			if (round.size() == 3)
			{
				score += results[std::make_pair(round[0], round[2])];
				score2 += results2[std::make_pair(round[0], round[2])];
			}
		}
		input.close();

		std::cout <<"part 1 score:" << score << std::endl;
		std::cout <<"part 2 score:" << score2 << std::endl;

	}
	else
		std::cout << "error reading file" << std::endl;
}