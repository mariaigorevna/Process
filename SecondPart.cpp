/// g++ SecondPart.cpp -std=c++17 -lstdc++fs -o laba

#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <vector>
#include <filesystem>

int main()
{
	pid_t pid;
	std::string path;
	std::vector<std::string> vecPaths;		

	std::cout << "Type directory path: ";
	std::cin >> path;
	for (const auto &entry : std::filesystem::directory_iterator(path)) 
	{
		vecPaths.push_back(entry.path());		
	}

	if (vecPaths.size() == 0)		
	{
		std::cerr << "Error: Empty directory\n";
		return 1;
	}

	for (const auto filePath : vecPaths)		
	{
		switch(pid=fork())		
		{
		case -1:		
			std::cerr << "Process create error\n";
			exit(1);

		case 0:			
			std::cout << "Baby\n";
			execl("FirstPart", "FirstPart", filePath.c_str(), NULL);
			exit(0);

		default:		
			std::cout << "Parent\n";
			wait(0);
		}
	}

	return 0;
}
