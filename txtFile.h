#pragma once
#include "File.h"
#include"FileFolder.h"
class txtFile :	public File
{
	std::string data;
public:
	txtFile(std::string name, std::string type);
	txtFile();
	void setName(std::string name);
	void reName();
	void edit();
	void showTxt();
	void showData();
	void function();
};

