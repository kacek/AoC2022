
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	std::fstream input;
	input.open("input.txt", std::ios::in);
	
	std::vector <int> elves;
	std::string line;
	if (input.good() == true)
	{
		int sum = 0;
		while (!input.eof())
		{
			std::getline(input, line);
			if (line.length() == 0)
			{
				elves.push_back(sum);
				sum = 0;
			}
			else
			{
				sum += stoi(line);
			}
		}
		input.close();

		std::sort(elves.begin(), elves.end(), [](int a, int b) {return a > b; });

		std::cout << "top 3 elves:" << std::endl;
		std::cout << elves[0] << std::endl
				<< elves[1] << std::endl
				<< elves[2] << std::endl;
		std::cout << "sum of 3 best: " << elves[0] + elves[1] + elves[2] << std::endl;
	}
	else
	{
		std::cout << "error reading file" << std::endl;
	}
}
