#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>

int main()
{
	std::fstream file;
	file.open("input.txt", std::ios::in);
	if (file.good())
	{
		std::string line;
		std::stack<std::string> input;

		//bufferring input stacks for further processig
		while (true)
		{
			std::getline(file, line);
			if (line[1] != '1')		//break if found end of stack definitions
				input.push(line);
			else
				break;
		}

		//initialize stacks
		std::vector<std::stack<char>> stacks1;
		for (int i = 0; i <= line.length() / 4; i++)
		{
			stacks1.push_back(std::stack<char>());
		}

		//populating initial stacks
		while (!input.empty())
		{
			line = input.top();
			for (int i = 1; i < line.length(); i += 4)
			{
				if(line[i]!=' ')
					stacks1[i/4].push(line[i]);
			}
			input.pop();
		}

		std::vector<std::stack<char>> stacks2(stacks1); //clone initial stacks for part 2
		std::stack<char> tempStack;	//stack for handling multiple moves

		//execute commands
		while (!file.eof())
		{
			int amount, inputStack, outputStack;
			char temp;
			std::getline(file, line);
			if (line.length() == 0)	//skip empty line
				continue;
			sscanf_s(line.c_str(), "move %d from %d to %d", &amount, &inputStack, &outputStack);
			for (int i = 0; i < amount; i++)
			{
				//part 1 (whole)
				temp = stacks1[inputStack - 1].top();
				stacks1[inputStack - 1].pop();
				stacks1[outputStack - 1].push(temp);

				//part 2 (taking out items from input stack)
				temp = stacks2[inputStack - 1].top();
				stacks2[inputStack - 1].pop();
				tempStack.push(temp);
			}
			//part 2 (storing items in output stack)
			while (!tempStack.empty())
			{
				stacks2[outputStack - 1].push(tempStack.top());
				tempStack.pop();
			}
		}
		file.close();

		//print result for part 1
		std::cout << "part 1 result: ";
		for (int i = 0; i < stacks1.size(); i++)
		{
			std::cout << stacks1[i].top();
		}
		std::cout << std::endl;

		//print result for part 2
		std::cout << "part 2 result: ";
		for (int i = 0; i < stacks2.size(); i++)
		{
			std::cout << stacks2[i].top();
		}
		std::cout << std::endl;
	}
	else
	{
		file.close();
		std::cout << "Error reading file" << std::endl;
	}
}