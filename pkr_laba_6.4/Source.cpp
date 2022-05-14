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
	cout << "��������� ������� ������: "; cin >> Low;
	cout << "��������� ������� ������: "; cin >> High;
	cout << "ʳ������ �������� ������: "; cin >> N;
	cout << "�������� �������������� ���� V1: "; cin >> V1;
	cout << "�������� �������������� ���� V2: "; cin >> V2;
	CreateCycle(L, N, Low, High);
	cout << "����������� ������:" << endl;
	Print(L);
	cout << "����� ������:" << endl;
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
		if (L->info == V1) // �������� �� ������� �� ������� �������� V1
		{
			Insert(L, V2); 
			L = L->link; // ������� �� ���������� ��������
			
		}
		else
		{
			L = L->link; // ������� �� ���������� ��������
		}
	}
	if(L->link == first) // ���� ������ �� 1 �������
	{
		if (L->info == V1) // ���� ��� ������� = V1
			Insert(L, V2);
	}
}

void Print(Elem *L)
{
	if (L == NULL)
		return;

	Elem *first = L;
	cout << setw(4) << L->info; // ���� ������� ��������
	while (L->link != first)
	{
		L = L->link;// ������� �� ����������
		cout << setw(4) << L->info;// ���� ����������
	}
	cout << endl;
}
