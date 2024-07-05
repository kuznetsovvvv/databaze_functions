#include"Functions.h"

void DataInitialization() {
	//create temporary file which contains actual information
	ofstream _buf("Buffer.txt");

	if (!_buf) 
		cout << "Ошибка создания буферного файла!" << endl;
	
	_buf.close();
}

void DataEntry() {
	string _surname;
	string _phoneNum;
	string _city;
	int n;


	cout << "Введите количество данных: ";
	cin >> n;

	ofstream record("Buffer.txt", ios::app);
	if (record) {
		record << n << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "Введите данные №1 (Фамилия): ";
			cin >> _surname;

			cout << "Введите данные №2 (Номер телефона): ";
			cin >> _phoneNum;

			cout << "Введите данные №3 (Город): ";
			cin >> _city;

			record << _surname << endl;
			record << _phoneNum << endl;
			if (i < n - 1) 
				record << _city << endl;
			
			else 
				record << _city;
				cout << "____________________________" << endl;
			

		}
	}
	else 
		cout << "Ошибка открытия файла!" << endl;
	

	record.close();


	


}



void DataReading(string filename) {
	ifstream reading(filename); //stream of reading data
	ofstream record("Buffer.txt", ios::out); // stream of write data to file
	if (reading) {
		if (record) {
			string _surname;
			string _phoneNum;
			string _city;
			int n;

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++)
			{
				reading >> _surname;
				reading >> _phoneNum;
				reading >> _city;
				record << _surname << endl;
				record << _phoneNum << endl;
				if (i < n - 1) 
					record << _city << endl;
				
				else 
					record << _city;
				
			}
			cout << "Data has read" << endl;
		}
		else 
			cout << "Ошибка открытия буфера" << endl;
		

	}
	else 
		cout << "Error with open file!" << endl;
	

	reading.close();
	record.close();

}



void Print() {

	ifstream reading("Buffer.txt");
	if (reading) {

		string _surname;
		string _phoneNum;
		string _city;
		int n;

		reading >> n;
		cout << "Количество данных: " << n << endl << endl;

		for (int i = 0; i < n; i++)
		{
			cout << "Данные об №" << i + 1 << endl;
			reading >> _surname;
			cout << "Данные №1 (Фамилия): " << _surname << endl;

			reading >> _phoneNum;
			cout << "Данные №2 (Номер телефона): " << _phoneNum << endl;

			reading >> _city;
			cout << "Данные №3 (Город): " << _city << endl;

			cout << "_____________________________________________" << endl;
		}


	}
	else 
		cout << "Ошибка открытия файла!" << endl;
	
	reading.close();
}


void DataChange() {


	Copy();



	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);
	if (reading) {
		if (record) {

			string _surname;
			string _phoneNum;
			string _city;
			int n,_n;
			reading >> n;
			cout<< "Enter number redacted element (1 to " << n << "): ";
			cin >> _n;
			_n--;
			system("cls");
			record << n << endl;
			if (_n >= 0 && _n < n) {
				for (int i = 0; i < n; i++)
				{
					if (i != _n) {
						reading >> _surname;
						record << _surname << endl;

						reading >> _phoneNum;
						record << _phoneNum << endl;
						reading >> _city;
						if (i < n - 1) 
							record << _city << endl;
						else 
							record << _city;
						
					}
					else {
						cout << "Введите данные №1 (Фамилия): " << endl;
						cin >> _surname;

						cout << "Введите данные №2 (Номер телефона): " << endl;
						cin >> _phoneNum;

						cout << "Введите данные №3 (Город): " << endl;
						cin >> _city;

						record << _surname << endl;
						record << _phoneNum << endl;
						if (i < n - 1) 
							record << _city << endl;
						
						else 
							record << _city;
						
						reading >> _surname;
						reading >> _phoneNum;
						reading >> _city;
					}
				}
				cout << "Данные изменены!" << endl;
			}
			else 
				cout << "Номер введен не верно!" << endl;
			




		}
		else 
			cout << "Ошибка открытия файла!" << endl;
		

	}
	else 
		cout << "Ошибка открытия буферного файла!" << endl;
	



	record.close();
	reading.close();
	remove("Buffer_.txt");
}


void Copy() {
	ifstream reading("Buffer.txt");
	ofstream record("Buffer_.txt", ios::out);
	if (reading) {
		if (record) {

			string _surname;
			string _phoneNum;
			string _city;
			int n;
			
			reading >> n;
			record << n << endl;
			for (int i = 0; i < n; i++)
			{
				reading >> _surname;
				record << _surname << endl;

				reading >> _phoneNum;
				record << _phoneNum << endl;

				reading >> _city;
				if (i<n-1) 
					record << _city << endl;
				
				else 
					record << _city;
				
			}
		}
		else 
			cout << "Error with open file!" << endl;
		
	}
	else 
		cout << "Error with open Buffer file!" << endl;
	

	record.close();
	reading.close();

}

void DeleteData() {
	Copy();
	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);
	if (reading) {
		if (record) {
			string _surname;
			string _phoneNum;
			string _city;
			int n, _n;

			reading >> n;
			int b = n - 1;

			cout << "Выберите номер изменяемого элемента (от 1 до " << n << "): ";
			cin >> _n;
			_n--;

			system("cls");

			record << b << endl;
			if(_n>=0 && _n<n){
				for (int i = 0; i < n; i++)
				{
					if (i != _n) {
						reading >> _surname;
						record << _surname << endl;

						reading >> _phoneNum;
						record << _phoneNum << endl;

						reading >> _city;
						if (i < n - 1) {
							record << _city << endl;
						}
						else {
							record << _city;
						}
					}
					else {
						reading >> _surname;
						reading >> _phoneNum;
						reading >> _city;
					}
				}
				cout << "Данные удалены!" << endl;
			}
			else {
				cout << "Номер введен не верно!" << endl;
			}
		}
		else {
			cout << "Ошибка открытия файла!" << endl;
		}
	}
	else {
		cout << "Ошибка открытия буферного файла!" << endl;
	}

	record.close();
	reading.close();
	remove("Buffer_.txt");
}


void AddData() {
	string _surname;
	string _phoneNum;
	string _city;
	int n = AmountOfData() + 1;


	ofstream record("Buffer.txt", ios::app);
	ofstream record_("Buffer.txt", ios::out | ios::in);

	if (record_) {
		record_ << n << endl;
	}
	else {
		cout << "Ошибка октрытия буферного файла!" << endl;
	}

	if (record) {
		record << endl;

		cout << "Введите данные №1 (Фамилия): ";
		cin >> _surname;

		cout << "Введите данные №2 (Номер телефона): ";
		cin >> _phoneNum;

		cout << "Введите данные №3 (Город): ";
		cin >> _city;

		record << _surname << endl;
		record << _phoneNum << endl;
		record << _city;
	}
	else {
		cout << "Ошибка открытия файла!" << endl;
	}
	record.close();
	record_.close();
}

int AmountOfData() {
	ifstream _buf("Buffer.txt");
	int n;

	if (_buf) {
		_buf >> n;
	}
	else {
		cout << "Ошибка открытия буферного файла!" << endl;
	}
	_buf.close();

	return n;
}

void SaveData(string filename) {
	ifstream reading("Buffer.txt");
	ofstream record(filename, ios::out);
	if (reading) {
		if(record){
			string _surname;
			string _phoneNum;
			string _city;
			int n;

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++)
			{
				reading >> _surname;
				record << _surname << endl;

				reading >> _phoneNum;
				record << _phoneNum << endl;

				reading >> _city;
				if (i < n - 1) {
					record << _city << endl;
				}
				else {
					record << _city;
				}
			}
			cout << "Данные сохранены в файле " << filename << endl;
		}
		else {
			cout << "Ошибка открытия буферного файла!" << endl;
		}
	}
	else {
		cout << "Ошибка открытия файла!" << endl;
	}
	record.close();
	reading.close();

}


bool DataCleaning() {
	bool clear = false;

	fstream _buf("Buffer.txt", ios::out);

	if (!_buf) {
		cout << "Ошибка открытия файла!" << endl;
	}
	_buf.clear();//clear file

	if ( _buf.peek() == EOF) { 
		clear = true;
	}
	else {
		clear = false;
	}

	_buf.close();

	return clear;
}
