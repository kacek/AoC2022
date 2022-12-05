#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::fstream input;
	input.open("input.txt", std::ios::in);
	if (input.good())
	{
		std::string line;
		std::pair<int, int> range1;
		std::pair<int, int> range2;
		int subsets = 0;
		int overlaps = 0;
		while (!input.eof())
		{
			std::getline(input, line);
			sscanf_s(line.c_str(), "%d-%d,%d-%d", &range1.first, &range1.second, &range2.first, &range2.second);

			if (((range1.first >= range2.first) && (range1.second <= range2.second)) || ((range2.first >= range1.first) && (range2.second <= range1.second)))
				subsets++;

			if ((range1.first <= range2.second) && (range1.second >= range2.first))
				overlaps++;
		}
		input.close();
		std::cout << "amount of subsets: " << subsets << std::endl;
		std::cout << "amount of overlaps: " << overlaps << std::endl;
	}
	else
	{
		input.close();
		std::cout << "error reading file" << std::endl;
	}
}