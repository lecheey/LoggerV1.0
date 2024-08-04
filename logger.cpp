#include <iostream>
#include <fstream>
#include <filesystem>
#include <shared_mutex>
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
		if(logfile.is_open()){
			std::cout << "Лог-файл уже открыт" << std::endl;
		}
		else{
			std::cout << "Лог-файл открыт" << std::endl;	
			logfile.open(logpath, std::ios::in | std::ios::out | std::ios::app); // открытие для чтения/записи
		}
	}
		
	if(!logfile){
		std::cout << "Ошибка открытия файла!" << std::endl;
	}
}

Logger::~Logger(){
	if(logfile.is_open()){
		logfile.close();
		std::cout << "Лог-файл закрыт" << std::endl;
	}
	std::cout << "Завершение работы" << std::endl;
}

void Logger::LogRead(){
	m.lock_shared();	
	std::string _str;
	if(logfile.is_open()){
		while(getline(logfile, _str, '\n')){
			std::cout << _str << std::endl;
		}
		
		logfile.clear();
		logfile.seekg(0);
	}
	m.unlock_shared();
}

void Logger::LogWrite(std::string _time, std::string _name, std::string _message){
	m.lock();	
	if(logfile.is_open()){
		logfile << _time;	
		logfile << ';';	
		logfile << _name;	
		logfile << ';';	
		logfile << _message;	
		logfile << '\n';	
		
		logfile.clear();
		logfile.seekg(0);
	}
	m.unlock();
}
