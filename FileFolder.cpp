#include "FileFolder.h"
FileFolder::FileFolder(std::string name,std::string type)
{
	this->file_name = name;
	auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::stringstream ss;
	ss << std::put_time(localtime(&t), "%F %T");
	this->date = ss.str();
	this->Typename = type;
}

FileFolder::FileFolder()
{
	this->file_name = "newFileFolder";
	auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::stringstream ss;
	ss <<std::put_time(localtime(&t), "%F %T");
	this->date=ss.str();
	this->Typename = "FileFolder";
}

void FileFolder::setName(std::string name)
{
	this->file_name = name;
	auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::stringstream ss;
	ss << std::put_time(localtime(&t), "%F %T");
	this->date = ss.str();
}

std::string FileFolder::getName()
{
	return this->file_name;
}

void FileFolder::showData()
{
	std::cout << this->file_name << "             "<<this->date<< "              " <<this->Typename<<std::endl;
}

void FileFolder::add()
{
	std::string name,type;
	std::cout << "please input the name of File" << std::endl;
	std::cin >> name;
	std::cout << "please input the type of this file" << std::endl;
	std::cin >> type;
	int choice=0;
	File* file;
	if (type == "FileFolder")
		file = new FileFolder(name, type);
	else if (type == "txt")
		file = new txtFile(name, type);
	filelist.push_back(file);
}

void FileFolder::addFileFolder(FileFolder* file)
{
	if (file != nullptr)
		filelist.push_back(file);
	std::cout << "Add Wrong!!!" << std::endl;
}

void FileFolder::browseFilefolder()
{
	std::cout << "Name		     last modefied time                Type" << std::endl;
	std::cout << "-----------------------------------------------------------------" << std::endl;
	int i=1;
	for(File* var : filelist)
	{
		std::cout << i++ << ": "; var->showData();
	}
	std::cout << "-----------------------------------------------------------------" << std::endl;
}

void FileFolder::reName()
{
	std::cout << "please input name" << std::endl;
	std::string name;
	std::cin >> name;
	this->setName(name);
}

void FileFolder::deleteFileFolder()
{
	std::cout << "please input the number of the FIleFolder you want to delete" << std::endl;
	int num;
	std::cin >> num;
	if (num > filelist.size())
	{
		std::cout << "no such a FileFolder" << std::endl;
		return;
	}
	std::deque<File*>::iterator it=filelist.begin();
	for (int i = 0; i < num-1; i++, it++);
	filelist.erase(it);
}

void FileFolder::function()
{
	while (true) {
		std::cout << "-----------------------------" << std::endl;
		std::cout << this->file_name << std::endl;
		std::cout << "-----------------------------" << std::endl;
		this->browseFilefolder();
		std::cout << "1,Open File" << std::endl;
		std::cout << "2,Rename File" << std::endl;
		std::cout << "3,Delete File" << std::endl;
		std::cout << "4,New File" << std::endl;
		std::cout << "0,Exit" << std::endl;
		std::cout << "-----------------------------------------------------------------" << std::endl;

		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1: {
			std::cout << "please input the number of File you want to open" << std::endl;
			this->browseFilefolder();
			int num;
			std::cin >> num;
			if(num<=filelist.size())
				filelist[num - 1]->function();
			else
			{
				std::cout << "the File is not exist!!!" << std::endl;
				break;
			}
			break;
		}
		case 2: {
			std::cout << "please input the number of File you want to rename" << std::endl;
			int num;
			this->browseFilefolder();
			std::cin >> num;
			if (num <= filelist.size())
				filelist[num - 1]->reName();
			else
			{
				std::cout << "the FileFolder is not exist!!!" << std::endl;
				break;
			}
			break;
		}
		case 3:this->deleteFileFolder(); break;
		case 4:this->add();
		default:
			break;
		}
		if (choice == 0)
			break;
	}
}
