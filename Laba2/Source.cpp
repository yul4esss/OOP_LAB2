#include <iostream>
#include <string>
#include <locale>


using namespace std;

class Student;
class Group {

	public:
		//виводимо дані про студентів
		void Info(Student& s1);

};

class Student {

	private:
		friend Group;
		string surname;
		int gradeBookNum;
		static const int n = 3;
		int* grades;
		float avg;

	public:

	//конструктор
	Student() {
		surname = "Unknown";
		gradeBookNum = 0;
		grades = new int[n];
	}
	
	//деструктор
	~Student() {
		delete[] grades;
	}

	//методи та функції для внесення та отримання даних про студентів
	void SetSurname() {
		cin >> surname;
	}

	string GetSurname() {
		return surname;
	}

	void SetGradeBookNum() {
		cin >> gradeBookNum;
	}

	int GetGradeBookNum() {
		return gradeBookNum;
	}

	void SetGrades() {
		for (int i = 0; i < n; i++) {
			cin >> grades[i];
			if (grades[i] < 0) {
				cout << "\nВведіть оцінки, що більші за нуль" << endl;
				exit(0);
			}
		}
	}

	void PrintGrades() {
		for (int i = 0; i < n; i++) {
			cout << grades[i] << " ";
		}
	}

	//Підрахунок середнього арифметичного
	void CountAverage() {
		float sum = 0;
		for (int i = 0; i < n; i++) {
			sum += grades[i];
			avg = sum / n;
		}
	}

	float GetAverage() {
		return avg;
	}

};

//метод для класу Group, щоб вивести дані про студетів групи
void Group::Info(Student& s1) {
	cout << "\n" << "Номер залiкової книжки: " << s1.GetGradeBookNum() << " Прiзвище: " << s1.GetSurname() << " " << "Оцiнки ";
	s1.PrintGrades();
}




int main() {

	setlocale(LC_ALL, "Ukrainian");

	Student s1[3];
	Group s2;

	const int n = 3;

	//Введення даних про студентів
	for (int i = 0; i < n; i++) {
		cout << "Введiть номер залiкової книжки " << i+1 << " студента" << endl;
		s1[i].SetGradeBookNum();
	}

	for (int i = 0; i < n; i++) {
		cout << "Введiть прiзвище " << i + 1 << " студента" << endl;
		s1[i].SetSurname();
	}

	for (int i = 0; i < n; i++) {
		cout << "Введiть оцiнки " << i + 1 << " студента" << endl;
		s1[i].SetGrades();
	}

	//Виведення даних про студентів
	cout << "Вашi данi" << endl;
	for (int i = 0; i < n; i++) {
		s2.Info(s1[i]);
	}
		
	//Підрахунок та виведення середнього арифметичного
	for (int i = 0; i < n; i++) {
		s1[i].CountAverage();
		cout << "\nСереднє арифметичне " << i + 1 << " студента" << endl;
		cout << s1[i].GetAverage();
	}


	//Студнти з середнім арифметичним, що є більшим, ніж задане
	int num;
	cout << "\nВведiть число, яке має перевищувати середнє арифметичне" << endl;
	cin >> num;
	
	if (num < 0) {
		cout << "Число має бути додатнім " << endl;
		exit(0);
	}
	else {
		cout << "Студенти зi середнiм арифметичним, яке є більше за задане " << endl;
		for (int i = 0; i < n; i++) {
			if (s1[i].GetAverage() > num) {
				cout << s1[i].GetSurname() << " " << s1[i].GetAverage() << endl;
			}
		}
	}

	//Студент з найкращим середнім балом
	cout << "Студент з максимальним середнiм балом" << endl;
	float max = s1[0].GetAverage();
	for (int i = 0; i < n; ++i)
	{
		if (s1[i].GetAverage() == max)
		{
			cout << s1[i].GetSurname();
		}
	}

	for (int i = 0; i < n; i++) {
		if (s1[i].GetAverage() > max) {
			max = s1[i].GetAverage();
		}
	}
	cout << " " << max << endl;


	system("pause");


	return 0;
}