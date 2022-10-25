#include <iostream>
#include <string>
#include <locale>


using namespace std;

class Student;
class Group {

	public:
		//�������� ��� ��� ��������
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

	//�����������
	Student() {
		surname = "Unknown";
		gradeBookNum = 0;
		grades = new int[n];
	}
	
	//����������
	~Student() {
		delete[] grades;
	}

	//������ �� ������� ��� �������� �� ��������� ����� ��� ��������
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
				cout << "\n������ ������, �� ����� �� ����" << endl;
				exit(0);
			}
		}
	}

	void PrintGrades() {
		for (int i = 0; i < n; i++) {
			cout << grades[i] << " ";
		}
	}

	//ϳ�������� ���������� �������������
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

//����� ��� ����� Group, ��� ������� ��� ��� ������� �����
void Group::Info(Student& s1) {
	cout << "\n" << "����� ���i���� ������: " << s1.GetGradeBookNum() << " ��i�����: " << s1.GetSurname() << " " << "��i��� ";
	s1.PrintGrades();
}




int main() {

	setlocale(LC_ALL, "Ukrainian");

	Student s1[3];
	Group s2;

	const int n = 3;

	//�������� ����� ��� ��������
	for (int i = 0; i < n; i++) {
		cout << "����i�� ����� ���i���� ������ " << i+1 << " ��������" << endl;
		s1[i].SetGradeBookNum();
	}

	for (int i = 0; i < n; i++) {
		cout << "����i�� ��i����� " << i + 1 << " ��������" << endl;
		s1[i].SetSurname();
	}

	for (int i = 0; i < n; i++) {
		cout << "����i�� ��i��� " << i + 1 << " ��������" << endl;
		s1[i].SetGrades();
	}

	//��������� ����� ��� ��������
	cout << "���i ���i" << endl;
	for (int i = 0; i < n; i++) {
		s2.Info(s1[i]);
	}
		
	//ϳ�������� �� ��������� ���������� �������������
	for (int i = 0; i < n; i++) {
		s1[i].CountAverage();
		cout << "\n������ ����������� " << i + 1 << " ��������" << endl;
		cout << s1[i].GetAverage();
	}


	//������� � ������� ������������, �� � ������, �� ������
	int num;
	cout << "\n����i�� �����, ��� �� ������������ ������ �����������" << endl;
	cin >> num;
	
	if (num < 0) {
		cout << "����� �� ���� ������� " << endl;
		exit(0);
	}
	else {
		cout << "�������� �i ������i� ������������, ��� � ����� �� ������ " << endl;
		for (int i = 0; i < n; i++) {
			if (s1[i].GetAverage() > num) {
				cout << s1[i].GetSurname() << " " << s1[i].GetAverage() << endl;
			}
		}
	}

	//������� � ��������� ������� �����
	cout << "������� � ������������ ������i� �����" << endl;
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