#include <vector>
#include <iostream>
#include <array>

using namespace std;

void Task_1()
{
	cout << "Task 1 \n\n";
}

void Task_2()
{
	cout << "\nTask 2\n\n";
}

void END()
{
	cout << "END \n\n";
}
/* 
Task 1
Создать программу, которая считывает целое число типа int.
И поставить «защиту от дурака»: если пользователь вводит что-то кроме одного целочисленного значения,
нужно вывести сообщение об ошибке и предложить ввести число еще раз. Пример неправильных введенных строк
*/

void Exercise1()
{
	int num;

	cout << "Введите ваше число: ";

	while (true)
	{
		cin >> num;

		if (cin.good() && cin.peek() == '\n')
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		cin.clear();
		cerr << "[Ошибка] введите целое число: ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "Ваше число: " << num << endl;
}

/*
Task 2
Создать собственный манипулятор endll для стандартного потока вывода,
который выводит два перевода строки и сбрасывает буфер.
*/

template<typename _CharT, typename _Traits>
inline basic_ostream<_CharT, _Traits>&
endll(basic_ostream<_CharT, _Traits>& os)
{
	return flush((os.put(os.widen('\n'))).put(os.widen('\n')));
}

void Exercise2()
{
	cout << "Начало" << endll;
	cout << "Конец" << endll;
}

int main()
{
	setlocale(LC_ALL, "rus");
	{
		Task_1();
		Exercise1();
	}

	{
		Task_2();
		Exercise2();
		END();
		
	}
}; 
