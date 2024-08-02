#include <iostream>
#include "logger.h"
#include "func.h"

int main(){
	Logger logger;
	
	char a;
	while(true){
		std::cout << "1 - показать 2 - сохранить q - выход: ";
		std::cin >> a;

		if(a == '1'){
			logger.LogRead();
		}
		else if(a == '2'){
			logger.LogWrite(getTime(), "Phone", "Завершение работы");
			std::cout << "новая запись в лог" << std::endl;
		}
		else if(a == 'q'){
			break;
		}
	}

	return 0;
}
