#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
	size_t i;
	argc = argc;
	std::string infile = argv[1];
	std::string outfile = infile + ".replace";
	std::string replaced = argv[2];
	std::string replace_with = argv[3];
	std::string input_str;
	std::ifstream in(infile.c_str());
	std::ofstream out(outfile.c_str());

	if (!in.is_open())
		std::cout << "File could not be opened." << std::endl;
	else if (!out.is_open())
	{
		std::cout << "File could not be opened." << std::endl;
		in.close();
	}
	else
	{
		for (std::string line; getline(in, line);)
		{
			input_str += line;
			input_str += '\n';
		}
		i = input_str.find(replaced, 0);
		while (i != std::string::npos)
		{
			input_str.erase(i, replaced.length());
			input_str.insert(i, replace_with);
			i = input_str.find(replaced, i);
		}
		out << input_str;
		in.close();
		out.close();
	}
}