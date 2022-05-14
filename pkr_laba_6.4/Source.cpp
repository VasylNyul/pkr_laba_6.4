#include <iostream>
#include <iomanip>
#include <windows.h>
#include <time.h>

using namespace std;

struct Elem
{
	Elem* link;
	int info;
};

void CreateCycle(Elem*& first, int N, int Low, int High);
void Insert(Elem*& L, int value);
void Scan(Elem* L, int V1, int V2);
void Print(Elem* L);

int main()
{
	srand((unsigned)time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Elem* L = NULL;

	int Low, High, N, V1, V2;
	cout << "Найменший елемент списку: "; cin >> Low;
	cout << "Найбільший елемент списку: "; cin >> High;
	cout << "Кількість елементів списку: "; cin >> N;
	cout << "Значення інформаційного поля V1: "; cin >> V1;
	cout << "Значення інформаційного поля V2: "; cin >> V2;
	CreateCycle(L, N, Low, High);
	cout << "Оригінальний список:" << endl;
	Print(L);
	cout << "Новий список:" << endl;
	Scan(L, V1, V2);
	Print(L);

	return 0;
}

void CreateCycle(Elem *&first, int N, int Low, int High)
{
	for (int i = 0; i < N; i++)
	{
		int value = Low + rand() % (High - Low + 1);
		Insert(first, value);
	}
}

void Insert(Elem *&L, int value)
{
	Elem* tmp = new Elem; // 1
	tmp->info = value; // 2
	if (L != NULL)
	{
		Elem* T = L; // 3
		while (T->link != L)
			T = T->link; // 4
		T->link = tmp; // 5
	}
	else
	{
		L = tmp; // 6
	}
	tmp->link = L; // 7
}

void Scan(Elem *L, int V1, int V2)
{
	if (L == NULL)
		return;

	Elem *first = L; // 1
	while (L->link != first) 
	{
		if (L->info == V1) // перевірка чи елемент має вказане значення V1
		{
			Insert(L, V2); 
			L = L->link; // перехід до наступного елементу
			
		}
		else
		{
			L = L->link; // перехід до наступного елементу
		}
	}
	if(L->link == first) // якщо список має 1 елемент
	{
		if (L->info == V1) // якщо цей елемент = V1
			Insert(L, V2);
	}
}

void Print(Elem *L)
{
	if (L == NULL)
		return;

	Elem *first = L;
	cout << setw(4) << L->info; // вивід першого елементу
	while (L->link != first)
	{
		L = L->link;// перехід до наступного
		cout << setw(4) << L->info;// вивід наступного
	}
	cout << endl;
}
