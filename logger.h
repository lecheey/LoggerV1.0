#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem; 

class Logger{
private:
	fs::path logpath{"log.txt"};
	std::fstream logfile;
public:
	Logger();
	~Logger();

	void LogRead();
	void LogWrite(std::string _time, std::string _name, std::string _message);
};
