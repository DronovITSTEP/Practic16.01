#include <iostream>
#include <Windows.h>

using namespace std;

//длина строки
void len() {
    char str[256];
    cout << "Введите строку: ";
    gets_s(str); // для ввода всей строки (с учетом пробельных символов)
    cout << strlen(str);
}
//копирование строк
void copy() {
    char* c = new char[125] {"Hello World"};
    char* c2 = new char[125];
    //c2 = c; // Так делать нельзя. Указателю присваивается адрес другого указателя
    strcpy_s(c2, 12,c); // 12 - это буферная память, необходимя для копирования
    cout << c2 << " " << c << endl;

    char str[125]{"Hello World"};
    char str2[125]{};
    strcpy_s(str2, str); // т.к. массивы статические (из размер const), то буферную память указывать не нужно
    cout << str2 << " " << str;
}
//конкатенация (сложение) строк
void cancat() {
    char* str = new char[25] {"Hello "};
    char* str2 = new char[25] {"C++ World"};
    //strcat_s(str, strlen(str) + strlen(str2) +1, str2);
    strncat_s(str, strlen(str) + strlen(str2) + 1, str2 + 4, 5);
    cout << str << " " << str2;
}

void cancat2() {
    char* fam = new char[125];
    char* im = new char[125];
    char* otch = new char[125];
    cout << "введите фамилию: "; cin >> fam;
    cout << "введите имя: "; cin >> im;
    cout << "введите отчество: "; cin >> otch;

    char* res = new char[strlen(fam) + strlen(im) + strlen(otch) + 3];
    strcpy_s(res, strlen(res), fam);
    strcat_s(res, strlen(res) + 2, " ");
    strcat_s(res, strlen(res)+strlen(im) + 1, im);
    strcat_s(res, strlen(res) + 2, " ");
    strcat_s(res, strlen(res) + strlen(otch) + 1, otch);

    delete[]fam;
    delete[]im;
    delete[]otch;

    cout << res;
}

//поиск символов
void strchar() {
    char* filename = new char[125];
    cout << "Введите имя файла: "; gets_s(filename, 125);
    if (strchr(filename, '.')) cout << "Всё ок!\n";
    else strcat_s(filename, 125, ".TXT");
    cout << filename;
}

//поиск подстрок
void strstring() {
    char* filename = new char[125];
    cout << "Введите имя файла: "; gets_s(filename, 125);
    _strupr_s(filename, 125); // перевод в нижний регистр
    cout << filename << endl;
    char* p = strstr(filename, "TXT");
    if (p) strcpy_s(p, 4, "DAT");
    cout << filename;
}

void strp() {
    char* filename = new char[125];
    cout << "Введите имя файла: "; gets_s(filename, 125);
    if (char* p = strpbrk(filename, "dfhe")) strcpy_s(p, 6, "llo");
    cout << filename;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //len();
    //copy();
    //cancat();
    //cancat2();
    //strchar();
    //strstring();
    strp();
}
