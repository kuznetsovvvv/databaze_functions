#pragma once

#include<iostream>
#include<fstream>
#include<string>
//#include<Windows.h>
using namespace std;


//function prototypes
void DataInitialization();// inizialization data
void DataEntry(); //entry data by hand
void DataReading(string filename);// read data from file
void Print();//print data
bool DataCleaning();//clean data
void DataChange();// change data about people
void Copy(); //cope data
int AmountOfData(); // amount of data
void DeleteData(); //delete data
void AddData(); // add data
void SaveData(string filename);// save data

