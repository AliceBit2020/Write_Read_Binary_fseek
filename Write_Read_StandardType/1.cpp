#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <io.h>
using namespace std;


struct Student
{
	char name[20];////
	char surname[20];///
	int age;///4b + 4b
	double GPA;  ////
};

struct StudentPtr
{
	char* name;////8b
	char* surname;///8b
	int age;///8b
	double GPA;  ////8b
};

void WriteStudentPtr(FILE* f, const StudentPtr& st)
{
	int len;

	len = strlen(st.name) + 1;///   '\0'
	fwrite(&len, sizeof(int), 1, f);
	fwrite(st.name, sizeof(char), len, f);

	len = strlen(st.surname) + 1;
	fwrite(&len, sizeof(int), 1, f);
	fwrite(st.surname, sizeof(char), len, f);

	fwrite(&st.age, sizeof(int), 1, f);
	fwrite(&st.GPA, sizeof(double), 1, f);
}

void main()
{
	/*Student st1;
	strcpy(st1.name, "Olga");*/


	StudentPtr st2;
	st2.name = new char[20] {"Olena"};

	//cout << st1.name << endl;
	//cout << st2.name << endl;

	

	//	cout << sizeof(Student) << endl;
	///////////////////////////////////////////////////////////////////////////////


	const char* filepath = "1.txt";

	FILE * f1 = nullptr;
	fopen_s(&f1, filepath, "wb");

	int a =5;
	double d = 40.5;
	Student st;
	st.age = 20;
	st.GPA = 11.5;
	strcpy_s(st.name, 20, "Ivan");
	strcpy_s(st.surname, 20, "Ivanov");



	fwrite(&a, sizeof(int),1, f1);/////  передаємо зміну, її розмір, кількість,куди f1
	fwrite(&d, sizeof(double), 1, f1);
	fwrite(&st, sizeof(Student), 1, f1);
	fclose(f1);


	/////1.   В якому порядку записали так і зчитуємо, прямий доступ/послідовний доступ
	//FILE * f2 = nullptr;
	//fopen_s(&f2, filepath, "rb");
	//int a2;
	//fread(&a2, sizeof(int),1, f2);
	//double d2;
	//fread(&d2, sizeof(double), 1, f2);
	//Student st2;
	//fread(&st2, sizeof(Student), 1, f2);

	//fclose(f2);
	//cout << a2 << endl << d2 << endl <<  endl;
	//cout << st2.name << endl << st2.surname << endl << st2.age << endl << st2.GPA << endl << endl;

	/////////////////////////////////////////////////////////////////////////////////////////////////

	///////*int fseek(
	//////	FILE * stream,
	//////	long offset,
	//////	int origin
	//////);
	//////	Parameters
	//////	stream
	//////	Pointer to FILE structure.

	//////	offset
	//////	Number of bytes from origin.

	//////	origin
	//////	Initial position.
	//////	SEEK_END: End of the file.
	//////	SEEK_SET : Beginning of the file.
	//////	SEEK_CUR : Current position of the file pointer.​

	//////	Return Value
	//////	If successful, fseekand _fseeki64 returns 0. Otherwise, it returns a nonzero value.*/



	///2.     Довільний доступ
		FILE * f3 = nullptr;
		fopen_s(&f3, "1.txt", "rb");


	fseek(f3, -sizeof(Student), SEEK_END);
	Student st3;
	fread(&st3, sizeof(Student), 1, f3);


	cout << st3.name << endl << st3.surname << endl << st3.age << endl << st3.GPA << endl;
	int a3;
	fseek(f3, 0, SEEK_SET);
	fread(&a3, sizeof(int), 1, f3);
	cout << a3 << endl;

	double d3;
	fseek(f3,0, SEEK_CUR);
	int count = 1;
	fread(&d3, sizeof(double), count, f3);

	fseek(f3, sizeof(double), SEEK_CUR);
	fread(&st3, sizeof(Student), 1, f3);
	cout << st3.name << endl << st3.surname << endl << st3.age << endl << st3.GPA << endl;


	double d3;
	fread(&d3, sizeof(double), 1, f3);
	cout << d3 << endl;
	fclose(f3);
	

	Student* arrSt = new Student[15];

}

