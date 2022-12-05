#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

void initializeCharMap(std::map<char, bool> &item)
{
	for (char i = 'a'; i <= 'z'; i++)
	{
		item[i] = false;
	}
	for (char i = 'A'; i <= 'Z'; i++)
	{
		item[i] = false;
	}
}

int getPriority(char a)
{
	if (a >= 'a' && a <= 'z')
		return a - 'a' + 1;
	else
		return a - 'A' + 27;
}

int calculatePhase1(std::vector<std::string> input)
{
	int score = 0;
	char searchChar;
	for (std::string line : input)
	{
		bool found = false;
		for (int i = 0; i < line.size() / 2; i++)
		{
			searchChar = line[i];
			for (int j = (line.size() / 2); j < line.size(); j++)
			{
				if (line[j] == searchChar)
				{
					found = true;
					break;
				}
			}

			if (found)
			{
				score += getPriority(searchChar);
				break;
			}
		}

	}
	return score;
}

int calculatePhase2(std::vector<std::string> input)
{
	std::vector<std::map<char, bool>> items;
	std::map<char, bool> item;
	for (std::string x : input)
	{
		item = std::map<char, bool>();
		initializeCharMap(item);
		for (char a : x)
		{
			item[a] = true;
		}
		items.push_back(item);
	}

	int score = 0;

	for (int i = 0; i < items.size()/3; i++)
	{
		for (auto const& x : items[i*3])
		{
			if (items[i*3][x.first] && items[i*3 + 1][x.first] && items[i*3 + 2][x.first])
			{
				score += getPriority(x.first);
				break;
			}
		}
	}
	return score;
}


int main()
{
	std::fstream input;
	input.open("input.txt", std::ios::in);
	if (input.good())
	{
		std::vector<std::string> packs;		
		std::string line;

		while (!input.eof())
		{
			std::getline(input, line);
			packs.push_back(line);
		}
		input.close();

		std::cout << "repeated item sum: " << calculatePhase1(packs) << std::endl;
		std::cout << "badges sum: " << calculatePhase2(packs) << std::endl;
	}
	else
		std::cout << "error reading file" << std::endl;
}