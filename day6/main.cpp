#include <iostream>
#include <fstream>

bool checkForMatch(char* buffer,int size)
{
	bool match = true;
	for (int i = 0; i < size-1; i++)
		for (int j = i + 1; j < size; j++)
			if (buffer[i] == buffer[j])
				match = false;
	return match;
}

int main()
{
	std::fstream file;
	file.open("input.txt", std::ios::in);
	if (file.good())
	{
		char c;

//--------------------------------------PART 1 -----------------------------------------------------

		char buffer1[4];
		int iterator1 = 4; //first pattern appearance can happen on 4th character
		//populate buffer with first 4 characters;
		for (int i = 0; i < 4; i++)
		{
			file.get(c);
			buffer1[i] = c;
		}
		//check initial buffer for hit
		if (checkForMatch(buffer1,4))
			file.seekg(0, std::ios::end); //prevent main loop from happening by reaching EOF
		//analyze rest of input data
		while (!file.eof())
		{
			iterator1++;
			file.get(c);
			buffer1[(iterator1 - 1) % 4] = c;
			if (checkForMatch(buffer1,4))
				break;
		}

//--------------------------------------PART 2-------------------------------------------------------

		char buffer2[14];
		int iterator2 = 14; //first pattern appearance can happen on 14th character
		
		file.clear();
		file.seekg(0); //reset file stream

		//populate buffer with first 14 characters;
		for (int i = 0; i < 14; i++)
		{
			file.get(c);
			buffer2[i] = c;
		}

		//check initial buffer for hit
		if (checkForMatch(buffer2, 14))
			file.seekg(0, std::ios::end); //prevent main loop from happening by reaching EOF

		//analyze rest of input data
		while (!file.eof())
		{
			iterator2++;
			file.get(c);
			buffer2[(iterator2 - 1) % 14] = c;
			if (checkForMatch(buffer2, 14))
				break;
		}
		file.close();
		std::cout << "Part1: Packet marker found at position " << iterator1 << std::endl;
		std::cout << "Part2: Message marker found at position " << iterator2 << std::endl;
	}
	else
	{
		file.close();
		std::cout << "Error reading file" << std::endl;
	}
}