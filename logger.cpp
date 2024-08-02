#include <iostream>
#include <fstream>
#include <filesystem>
#include "logger.h"

Logger::Logger(){
	if(!fs::exists(logpath)){
		std::cout << "Создание лог-файла" << std::endl;	
		logfile.open(logpath, std::ios::in | std::ios::out | std::ios::app); // создание лог-файла с нужными правами
		fs::permissions(logpath,
			fs::perms::owner_read | fs::perms::owner_write |
			fs::perms::group_read | fs::perms::group_write,
			fs::perm_options::replace);
	}
	else{
		std::cout << "Лог открыт" << std::endl;	
		logfile.open(logpath, std::ios::in | std::ios::out | std::ios::app); // открытие для чтения/записи
	}
		
	if(!logfile){
		std::cout << "Ошибка открытия файла!" << std::endl;
	}
}

Logger::~Logger(){
	if(logfile.is_open()){
		logfile.close();
		std::cout << "лог закрыт" << std::endl;
	}
	std::cout << "выход" << std::endl;
}

void Logger::LogRead(){
	std::string _str;
	while(getline(logfile, _str, '\n')){
		std::cout << _str << std::endl;
	}	
}

void Logger::LogWrite(std::string _time, std::string _name, std::string _message){
	logfile << _time;	
	logfile << ';';	
	logfile << _name;	
	logfile << ';';	
	logfile << _message;	
	logfile << '\n';	
}
