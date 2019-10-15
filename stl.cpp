#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


void sort(vector<string>& name, vector<string>& time, vector<string>& prod) {
	for (int i = 0; i < name.size() -1 ; i++) {
		for (int j = 0; j < name.size()-i -1; j++) {
			const char* str1 = name[j].c_str();
			const char* str2 = name[j+1].c_str();
			if (strcmp(str1, str2) > 0) {
				name[j].swap(name[j + 1]);
			}
		}

	}
}

void sortByDuration(vector<string>& nomer, vector<string>& fromWhom, vector<string>& whom,
	vector<string>& data, vector<string>& time, vector<string>& duration) {
	for (int i = 0; i < duration.size() - 1; i++) {
		for (int j = 0; j < duration.size() - i - 1; j++) {
			const char* str1 = duration[j].c_str();
			const char* str2 = duration[j + 1].c_str();
			if (strcmp(str1, str2) > 0) {
				fromWhom[j].swap(fromWhom[j + 1]);
				whom[j].swap(whom[j + 1]);
				data[j].swap(data[j + 1]);
				time[j].swap(time[j + 1]);
				duration[j].swap(duration[j + 1]);
			}
		}
	}

}

void sortByData(vector<string>& nomer, vector<string>& fromWhom, vector<string>& whom,
	vector<string>& data, vector<string>& time, vector<string>& duration) {

	for (int i = 0; i < data.size() - 1; i++) {
		for (int j = 0; j < data.size() - i - 1; j++) {
			const char* str1 = data[j].c_str();
			const char* str2 = data[j + 1].c_str();
			if (strcmp(str1, str2) > 0) {
				fromWhom[j].swap(fromWhom[j + 1]);
				whom[j].swap(whom[j + 1]);
				data[j].swap(data[j + 1]);
				time[j].swap(time[j + 1]);
				duration[j].swap(duration[j + 1]);
			}
			else if (strcmp(str1, str2) == 0) {
				const char* str1 = time[j].c_str();
				const char* str2 = time[j + 1].c_str();
				if (strcmp(str1, str2) > 0) {
					fromWhom[j].swap(fromWhom[j + 1]);
					whom[j].swap(whom[j + 1]);
					data[j].swap(data[j + 1]);
					time[j].swap(time[j + 1]);
					duration[j].swap(duration[j + 1]);
				}
			}
		}
	}
}

void outputInfo(vector<string>& nomer, vector<string>& fromWhom, vector<string>& whom,
	vector<string>& data, vector<string>& time, vector<string>& duration) {

	for (auto i = 0; i < nomer.size(); i++)
	{
		cout << nomer[i] << " " << fromWhom[i] << " " << whom[i] << " ";
		cout << data[i] << " " << time[i] << " " << duration[i] << endl;
	}
}

void addCall(vector<string>& nomer, vector<string>& fromWhom, vector<string>& whom,
	vector<string>& data, vector<string>& time, vector<string>& duration, int sellNumber) {
	string str;

	int newNomer = nomer.size() + 1;
	str = to_string(newNomer);
	string str1 = str + ")";
	auto it = nomer.end();
	nomer.insert(it, str1);

	cout << "Введите от кого был звонок :" << endl;
	cin >> str;
	it = fromWhom.begin();
	advance(it, sellNumber);
	fromWhom.insert(it, str);

	cout << "Введите кому был звонок :" << endl;
	cin >> str;
	it = whom.begin();
	advance(it, sellNumber);
	whom.insert(it, str);

	cout << "Введите дату звонка :" << endl;
	cin >> str;
	it = data.begin();
	advance(it, sellNumber);
	data.insert(it, str);

	cout << "Введите время звонка:" << endl;
	cin >> str;
	it = time.begin();
	advance(it, sellNumber);
	time.insert(it, str);

	cout << "Введите продолжительность звонка :" << endl;
	cin >> str;
	it = duration.begin();
	advance(it, sellNumber);
	duration.insert(it, str);
}

void deleteCall(vector<string>& nomer, vector<string>& fromWhom, vector<string>& whom,
	vector<string>& data, vector<string>& time, vector<string>& duration, int sellNumber) {

	auto it = nomer.end();
	advance(it, -1);
	nomer.erase(it);

	it = fromWhom.begin();
	advance(it, sellNumber);
	fromWhom.erase(it);

	it = whom.begin();
	advance(it, sellNumber);
	whom.erase(it);

	it = data.begin();
	advance(it, sellNumber);
	data.erase(it);

	it = time.begin();
	advance(it, sellNumber);
	time.erase(it);

	it = duration.begin();
	advance(it, sellNumber);
	duration.erase(it);
}

void outputFromWho(vector<string>& nomer, vector<string>& fromWhom, vector<string>& whom,
	vector<string>& data, vector<string>& time, vector<string>& duration, string nameSearch) {
	for (int i = 0; i < nomer.size(); i++) {
		if (nameSearch == fromWhom[i]) {
			cout << nomer[i] << " " << fromWhom[i] << " " << whom[i] << " ";
			cout << data[i] << " " << time[i] << " " << duration[i] << endl;
		}
	}
}

void outputWho(vector<string>& nomer, vector<string>& fromWhom, vector<string>& whom,
	vector<string>& data, vector<string>& time, vector<string>& duration, string nameSearch) {
	for (int i = 0; i < nomer.size(); i++) {
		if (nameSearch == whom[i]) {
			cout << nomer[i] << " " << fromWhom[i] << " " << whom[i] << " ";
			cout << data[i] << " " << time[i] << " " << duration[i] << endl;
		}
	}
}

void overWriteFile(vector<string>& nomer, vector<string>& fromWhom, vector<string>& whom,
	vector<string>& data, vector<string>& time, vector<string>& duration) {
	ofstream fout("C:\\Users\\Maks\\source\\repos\\lab22\\INFO.txt");
	for (auto i = 0; i < nomer.size(); i++)
	{
		fout << nomer[i] << " " << fromWhom[i] << " " << whom[i] << " ";
		fout << data[i] << " " << time[i] << " " << duration[i] << endl;
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");


	ifstream fin;
	fin.exceptions(ifstream::badbit | ifstream::failbit);

	try {
		fin.open("C:\\Users\\Maks\\source\\repos\\lab22\\INFO.txt");
	}
	catch (const std::exception & ex) {
		cout << ex.what() << endl;
		cout << "ОШИБКА!" << endl;
	}

	vector<string> nomer;
	vector<string> fromWhom;
	vector<string> whom ;
	vector<string> data;
	vector<string> time;
	vector<string> duration;

	int count = 0;
	while (fin) {
		string str;
		fin >> str;
		count++;
		switch (count)
		{
		case 1:
			if (str == "\0") {
				break;
			}
			nomer.push_back(str);
			continue;
		case 2:
			fromWhom.push_back(str);
			continue;
		case 3:
			whom.push_back(str);
			continue;
		case 4:
			data.push_back(str);
			continue;
		case 5:
			time.push_back(str);
			continue;
		case 6:
			duration.push_back(str);
			count = 0;
			continue;
		default:
			continue;
		}

	}

	int a=-1;
	while (a != 0) {
		cout << "Выберите действие: " << endl;
		cout << "Закончить работу - '0'"<< endl;
		cout << "Вывод списка - '1' " << endl;
		cout << "Добавить звонок - '2'" << endl;
		cout << "Удалить звонок - '3'" << endl;
		cout << "Сортировка по длительности - '4'" << endl;
		cout << "Вывод всех звонков человека, кторый звонил кому-либо - '5'"<< endl;
		cout << "Вывод всех вызово человека, которому звонил кто-либо - '6'" << endl;
		cout << "Сортировка по дате - '7'" << endl;
		cin >> a;
		cout << endl;
		int sellNomer;
		int sellNomer2;
		string nameSearch;
		switch (a)
		{
		case 1:
			outputInfo(nomer, fromWhom, whom, data, time, duration);
			continue;
			cout << endl;
		case 2:
			cout << "Выберите на какой номер нужно добавить звонок"<< endl;
			cin >> sellNomer;
			addCall(nomer, fromWhom, whom, data, time, duration, sellNomer);
			overWriteFile(nomer, fromWhom, whom, data, time, duration);
			cout << endl;
			continue;
		case 3:
			cout << "Выберите номер звонка, который хотите удалить"<< endl;
			cin >> sellNomer2;
			deleteCall(nomer, fromWhom, whom, data, time, duration, sellNomer2);
			overWriteFile(nomer, fromWhom, whom, data, time, duration);
			cout << endl;
			continue;
		case 4:
			sortByDuration(nomer, fromWhom, whom, data, time, duration);
			overWriteFile(nomer, fromWhom, whom, data, time, duration);
			cout << endl;
			continue;
		case 5:
			cout << "Введите челвека, чьи звонки хотите вывести:" << endl;
			cin >> nameSearch;
			outputFromWho(nomer, fromWhom, whom, data, time, duration, nameSearch);
			cout << endl;
			continue;
		case 6:
			cout << "Введите человека, чтобы вывести звонки, которые ему были получены"<< endl;
			cin >> nameSearch;
			outputWho(nomer, fromWhom, whom, data, time, duration, nameSearch);
			cout << endl;
			continue;
		case 7:
			sortByData(nomer, fromWhom, whom, data, time, duration);
			overWriteFile(nomer, fromWhom, whom, data, time, duration);
			continue;
		default:
			break;
		}
	}
}
