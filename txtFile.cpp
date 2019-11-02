#include "txtFile.h"

txtFile::txtFile(std::string name, std::string type)
{
	this->file_name = name;
	auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::stringstream ss;
	ss << std::put_time(localtime(&t), "%F %T");
	this->date = ss.str();
	this->Typename = type;
	data = "";
}

txtFile::txtFile()
{
	this->file_name = "newTxt";
	auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::stringstream ss;
	ss << std::put_time(localtime(&t), "%F %T");
	this->date = ss.str();
	this->Typename = "txt";
	data = "";
}

void txtFile::setName(std::string name)
{
	this->file_name = name;
	auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::stringstream ss;
	ss << std::put_time(localtime(&t), "%F %T");
	this->date = ss.str();
}

void txtFile::reName()
{
	std::cout << "please input name" << std::endl;
	std::string name;
	std::cin >> name;
	this->setName(name);
}

void txtFile::edit()
{
	std::cout << "editing...(press enter to save and exit edit)" << std::endl;
	std::cout << "===============================" << std::endl;
	std::cin >> this->data;
	std::cout << "===============================" << std::endl;
	auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::stringstream ss;
	ss << std::put_time(localtime(&t), "%F %T");
	this->date = ss.str();
}

void txtFile::showTxt()
{
	std::cout << "===============================" << std::endl;
	std::cout << data << std::endl;
	std::cout << "===============================" << std::endl;
}

void txtFile::showData()
{
	std::cout << this->file_name << "             " << this->date << "              " << this->Typename << std::endl;
}

void txtFile::function()
{
	while (true)
	{
		std::cout << "-----------------------------" << std::endl;
		std::cout << this->file_name << std::endl;
		std::cout << "-----------------------------" << std::endl;
		this->showTxt();
		std::cout << "1,edit" << std::endl;
		std::cout << "0,Exit" << std::endl;
		std::cout << "-----------------------------------------------------------------" << std::endl;
		int choice;
		std::cout << "please input your choice" << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 1:this->edit(); break;
		default:
			break;
		}
		if (choice == 0)
			break;
	}
}
