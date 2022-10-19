#include <iostream>
#include <string>
#include <cmath>
//Структуры применяются для группировки переменных

struct date {
	int day;
	int month;
	int year;
};

struct person {
	std::string name;
	date birthday;
	int salary;
};

void show_person(person &P) {
	std::cout << " Имя --> " << P.name << '\n';
	std::cout << " Дата рождения --> " << P.birthday.day << '.' <<
		P.birthday.month << '.' << P.birthday.year << '\n' <<
		" Зарплата --> " << P.salary << '\n';
}

// Неоптимальная функция тк занимает много памяти при создании
person input_person() {
	person tmp;
	std::cout << " Введите имя --> ";
	//std::cin.ignore();
	getline(std::cin, tmp.name);
	std::cout << " Введите дату рождения --> ";
	std::cin >> tmp.birthday.day >> tmp.birthday.month >> tmp.birthday.year;
	std::cout << " Введите зарплату --> ";
	std::cin >> tmp.salary;
	return tmp;
}

// Оптимальная функция тк использует ссылку и не занимает места в памяти
void fill_person(person &P) {
	std::cout << " Введите имя --> ";
	getline(std::cin, P.name);
	std::cout << " Введите дату рождения --> ";
	std::cin >> P.birthday.day >> P.birthday.month >> P.birthday.year;
	std::cout << " Введите зарплату --> ";
	std::cin >> P.salary;
}

// Задание 1. Персона с монетами
struct persona {
	std::string name;
	int age = 0;
	int coin[5]{};
};
void show_persona(persona& P) {
	std::cout << " Имя --> " << P.name <<
		"\n Возраст --> " << P.age << '\n';
	std::cout << " Монеты --> ";
	for (int i = 0; i < 5; i++)
		std::cout << P.coin[i] << ", ";
	std::cout << "\b\b.\n";
}
inline int year_of_birth(persona &P, int num) {
	return num - P.age;
}
int cash(persona& P) {
	int x = 0;
	for (int i = 0; i < 5; i++)
		x += P.coin[i];
	return x;
}

// Задача 2. point.
struct point {
	double x, y = 0;
};
int compare_distance(point& A, point& B) {
	double dist1 = sqrt(pow(A.x,2) + pow(A.y,2));
	double dist2 = sqrt(pow(B.x, 2) + pow(B.y, 2));
	if (dist1 > dist2)
		return 1;
	if (dist1 < dist2)
		return -1;
	return 0;
}


int main() {
	setlocale(LC_ALL, "Russian");
	int x = 0; // Строки 76 и 77 идентичны
	int y{};

	// Просто структура person
	/*struct person { // Объявление структуры person. Для ее реализации создаются объекты p1 и p2.
		std::string name = "Smith";
		int age = 18;
		std::string position = "programer";
		int salary = 15;
	} p1, p2{"Fgfg", 42, "dsffsdf", 679};

	// Обращение к полям объекта структуры
	p1.name = "Gleb";
	p1.age = 27;
	// p1.position = "DD";
	p1.salary = 101;

	std::cout << " Имя --> " << p1.name << "\n Возраст --> " << p1.age << '\n';
	std::cout << " Должность --> " << p1.position << "\n З/п --> " << p1.salary << '\n';
	std::cout << "------------------------\n";
	std::cout << " Имя --> " << p2.name << "\n Возраст --> " << p2.age << '\n';
	std::cout << " Должность --> " << p2.position << "\n З/п --> " << p2.salary << '\n';
	std::cout << "------------------------\n";

	// Изменение всего содержимого объекта структуры
	p2 = {" Rfjsfj", 53, "fk;sfp[f", 657};

	// Прямое присваивание поля объекта p2 значений из полей объекта p1
	p2 = p1;

	// Альтернативный способ создания объекта структуры. (название_структуры имя_объекта {};
	person p3{"fjhosdfj", 34, "dfsdf", 65};
	std::cout << " Имя --> " << p3.name << "\n Возраст --> " << p3.age << '\n';
	std::cout << " Должность --> " << p3.position << "\n З/п --> " << p3.salary << '\n';
	*/

	// Структуры person и date
	/*person p4;
	p4.name = "Gleb";
	//p4.birthday.day = 13;
	//p4.birthday.month = 9;
	//p4.birthday.year = 1995;
	p4.birthday = { 13, 9, 1995 };
	p4.salary = 101;

	person p5{
		"tgh,'",
		{4,4,1998},
		654
	};

	person* pp5 = &p5;

	std::cout << " Имя --> " << pp5->name << '\n';
	std::cout << " Дата рождения --> " << pp5->birthday.day << '.' << 
		pp5->birthday.month << '.' << pp5->birthday.year << '\n' <<
		" Зарплата --> " << pp5->salary << '\n';
	std::cout << "------------------------\n";
	show_person(p4);

	//person p6 = input_person();
	person p6;
	fill_person(p6);
	std::cout << "------------------------\n";
	show_person(p6);
	*/
	
	// Задание 1. Персона с монетами
	/*std::cout << "\t\tЗадача 1.\n Объект\n";
	persona A { 
		"Glen",
		25, 
		{1,1,2,5,10} 
	};
	show_persona(A);
	std::cout << " Год рождения --> " << year_of_birth(A, 2022) << '\n';
	std::cout << " Общая сумма накоплений объекта --> " << cash(A) << '\n';
	*/

	// Задание 2.
	std::cout << "\t\tЗадача 2.\n Point.\n";
	point A = { 2,2 };
	point B = { 23,23 };
	std::cout << " Точка А -->	" << A.x << ' ' << A.y << '\n';
	std::cout << " Точка В -->	" << B.x << ' ' << B.y << '\n';
	std::cout << "Узнаем какой отрезок длиннее --> " << compare_distance(A, B) << '\n';


	return 0;
}