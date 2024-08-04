#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <thread>
#include "logger.h"
#include "func.h"

int main(){
	Logger logger;
    
	std::vector<std::thread> threads{}; // массив потоков
	int a{20}; // число потоков
	
	// потоки
	for(int i = 0; i < a; i++){
		std::string b = "поток " + std::to_string(i);
		
		// случайные потоки на чтение
		if(i == 6 || i == 14 || i == 18){
			threads.push_back(std::thread([&logger](){
				logger.LogRead();
			}));
		}
		
		// потоки на запись
		else{
			threads.push_back(std::thread([&logger,i,b](){
				logger.LogWrite(getTime(), b, "важное сообщение");
			}));
		}
    }

    std::for_each(threads.begin(), threads.end(), [] (std::thread &t)
         { t.join(); });

	return 0;
}
