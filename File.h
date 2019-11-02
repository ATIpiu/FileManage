#pragma once
#include<iostream>
#include<deque>
class File {
protected:
	std::string file_name;
	std::deque<File*> filelist;
	std::string date;//最后修改日期
	std::string Typename;//文件类型
public:
	virtual void showData() = 0;
	virtual void function() = 0;
	virtual void reName() = 0;
};

