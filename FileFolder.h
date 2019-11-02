#pragma once
#include<iostream>
#include<deque>
#include<time.h>
#include <chrono>
#include <iomanip>
#include <sstream>
#include"File.h"
#include"txtFile.h"
class FileFolder:public File
{

public:
	FileFolder(std::string name,std::string type);
	FileFolder();
	void setName(std::string name);
	std::string getName();
	void showData();
	void add();
	void addFileFolder(FileFolder* file);
	void browseFilefolder();
	void reName();
	void deleteFileFolder();
	void function();
};

