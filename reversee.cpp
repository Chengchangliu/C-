#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
#include <fstream>


std::string Reverse(std::string str)
{
	char tmp;
	int len = str.size();
	for (int i = 0; i<len / 2; i++)
	{
		//swap  
		tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = tmp;

	}
	return str;
}

int main(void) {
	std::ofstream file("reverse_input.txt");
	if (file.is_open()) {
		file << "123\n";
		file << "abc\n";
		file.close();
	}
	std::string line;
	std::vector <std::string> str;
	std::vector <std::string>::const_iterator Vec;

	std::ifstream input("reverse_input.txt");
	if (input.is_open()) {
		while (getline(input, line)) {
			char tmp;
			int len = (int)line.size();
			for (int i = 0; i<(len / 2); i++) {
				//swap
				tmp = line[i];
				line[i] = line[len - 1 - i];
				line[len - 1 - i] = tmp;
			}
			str.push_back(line);
		}

	}
	else {
		std::cout << "Didn't open." << std::endl;
	}
	reverse(str.begin(), str.end());
	for (Vec = str.begin(); Vec != str.end(); Vec++)
		std::cout << *Vec << std::endl;
	system("pause");
	return 0;
}
