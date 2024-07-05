#include"Functions.h"

int _stateMenu;
void Menu() {
	cout << "Выберите действие:" << endl;
		cout <<"(0) Выход из программы." << endl;
		cout <<"(1) Ввод данных." << endl;
		cout <<"(2) Вывод данных." << endl;
		cout <<"(3) Изменение данных." << endl;
		cout <<"(4) Удаление данных." << endl;
		cout <<"(5) Добавлление данных." << endl;
		cout <<"(6) Сохранение данных." << endl;
		cout <<"Ваш выбор: ";
		cin >> _stateMenu;
}
/*
Данные: 

Фамилия
Номер телефона
Адрес
*/






int main()
{
	setlocale(LC_ALL, "RU");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	DataInitialization();
	Menu();


	int _actions;
	string filename;
	while (_stateMenu != 0) {
		switch (_stateMenu) {
		case 1:
			system("cls");//clear console


			cout << "Ввод вручную или из файла?(1-да, остальные цифры-нет): ";
			cin >> _actions;
			system("cls");//очиска консоли

			if (_actions==1) {
				//ввод вручную
				DataEntry();
			}
			else {
				//чтение из файла
				cout << "Введите название файла: ";
				cin >> filename;
				DataReading(filename);
			}
			system("pause");
			system("cls");
			Menu();
			break;

		case 2:
			system("cls");
			Print();

			system("pause");
			system("cls");
			Menu();
			break;
		case 3:
			system("cls");

			DataChange();

			system("pause");
			system("cls");
			Menu();
			break;
		case 4:
			system("cls");

			DeleteData();
			system("pause");
			system("cls");
			Menu();
			break;
		case 5:
			system("cls");

			AddData();

			system("pause");
			system("cls");
			Menu();
			break;
		case 6:
			system("cls");

			cout << "Введите название файла: ";
			cin >> filename;

			system("cls");
			SaveData(filename);

			system("pause");
			system("cls");
			Menu();
			break;
		default:
			cout << "Неправильно выбран пункт меню!" << endl;
			break;
		}
	}




	system("cls");
	if (DataCleaning()) 
		cout << "Data cleared!" << endl;
	
	else 
		cout << "Data didn't clear!" << endl;
	

	cout << "End of program." << endl;
	system("pause");
	return 0;
}


