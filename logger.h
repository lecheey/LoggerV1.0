#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <shared_mutex>

namespace fs = std::filesystem; 

class Logger{
private:
	fs::path logpath{"log.txt"};
	std::fstream logfile;
	std::shared_mutex m;

public:
	Logger();
	~Logger();

	void LogRead();
	void LogWrite(std::string _time, std::string _name, std::string _message);
};
