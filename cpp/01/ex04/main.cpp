#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout<<"Input Error!"<<std::endl;
        return (1);
    }

    std::string fileName = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    if (fileName.length() == 0 || s1.length() == 0 || s2.length() == 0)
	{
		std::cout<<"argv Error!"<<std::endl;
		return 1;
	}

    std::ifstream ifs;
    ifs.open(fileName);
    if (!ifs.is_open())
    {
        std::cout<<"file open failed!"<<std::endl;
        return (1);
    }

    std::ofstream ofs;
    std::string newFile = fileName + ".replace";
    ofs.open(newFile);
    if (!ofs.is_open())
    {
        std::cout<<"file open failed"<<std::endl;
        return (1);
    }

    std::string	temp;
    bool found = false;

	while (1)
	{
		std::getline(ifs, temp);

		size_t pos = 0;
		while (1)
		{
			pos = temp.find(s1, pos);
		
			if (pos == std::string::npos) {
				break;
			}
            found = true;
			temp.erase(pos, s1.length());
			temp.insert(pos, s2);
			pos += s2.length();
		}
		ofs << temp;
		if (ifs.eof())
			break ;
		ofs << std::endl;
	}

    if (!found) {
        std::cout << "String '" << s1 << "' not found in file!" << std::endl;
        ifs.close();
        ofs.close();
        return 1;
    }

	ifs.close();
	ofs.close();
	
	return 0;

}