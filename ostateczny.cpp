#include <iostream>
#include <ctime>
#include <time.h>

using namespace std;

//funkcja szukajaca najdluzszego malejacego podciagu za pomoca metody brute force
void ZnajdzNajwiekszyPodciagMalejacy(int A[], int N)  //BRUTE FORCE
{
	int jest=0;
	int najdluzszy=0;
	int iloscNajdluzszych=0;
	int *poczatekPodciagow=new int [N]; //dynamiczne alokowanie tablicy przechowujacej indeks pierwszej liczby podciagu
	int *koniecPodciagow=new int [N];	//dynamiczne alokowanie tablicy przechowujacej indeks ostatniej liczby podciagu
	
	for(int i=1; i<=N; i++)  //ilosc wyrazow -> dlugosc podciagu
	{
		for(int j=0; j<N-i; j++)  //indeks od ktorego zaczyna sie aktualnie sprawdzany podciag
		{
			for(int k=j; k<j+i-1; k++)   //granica indeksow w ktorych jest sprawdzany aktualny podciag
			{
				if(A[k] > A[k+1])   //warunek porownania liczb w danym podciagu
				{
					jest=1;
				}
				else {jest=0; break;}
			}
			
			if(jest==1)
			{
				if(i>najdluzszy)       //sprawdzanie czy aktualnie sprawdzana dlugosc jest wieksza od dotychczasowej najdluzszej
				{
					najdluzszy=i;
					iloscNajdluzszych=0;
					poczatekPodciagow[iloscNajdluzszych]=j;    //zapisywanie indeksu poczatkowego podciagu 
					koniecPodciagow[iloscNajdluzszych]=j+i-1;  //zapisywanie indeksu koncowego podciagu 
					iloscNajdluzszych++;     //zwiekszamy ilosc najdluzszych podciagow w razie wystapienia wiecej niz jednego podciagu takiej samej dlugosci
				}
				
				else if(i==najdluzszy)  //warunek dla wystapienia wiecej niz jednego podciagu tej samej dlugosci
				{
					poczatekPodciagow[iloscNajdluzszych]=j;  //zapisywanie indeksu poczatkowego podciagu 
					koniecPodciagow[iloscNajdluzszych]=j+i-1;//zapisywanie indeksu koncowego podciagu 
					iloscNajdluzszych++;
				}
			}
		}
	}
	if(najdluzszy>1)
	{
		cout<<"Najdluzszy podciag zawiera "<<najdluzszy<<" wyrazow:"<<endl;  
		cout<<"Wyjscie: "<<endl;
		for(int i=0; i<iloscNajdluzszych; i++)       //petla zewnetrzna wypisywania wartosci podciagow
		{
			cout<<"{ ";
			for(int j=poczatekPodciagow[i]; j<=koniecPodciagow[i]; j++)  //petla wewnetrzna wypisywania wartosci podciagow
			{
				cout<<A[j]<<" ";
			}
			cout<<"}"<<endl;
		}
		cout<<"Ilosc znalezionych podciagow: "<<iloscNajdluzszych<<endl<<endl;  
	}
	else {cout<<"Nie znaleziono najwiekszego podciagu.";}
	
	 // Zwolnienie pamieci
	delete [] poczatekPodciagow;
	delete [] koniecPodciagow;
}

//funkcja szukajaca najdluzszego malejaceego podciagu - wersja wydajniejsza
void ZnajdzNajdluzszyPodciagMalejacy2(int A[], int N)   //wydajniejszy
{
	int dlugosc=1;
	int najdluzszy=0;
	int IloscNajdluzszych=0;
	
	int *PoczatekNajdluzszego=new int[N];  //dynamiczne alokowanie tablicy przechowujacej indeks pierwszej liczby podciagu
	int *KoniecNajdluzszego=new int[N];   //dynamiczne alokowanie tablicy przechowujacej indeks ostatniej liczby podciagu
	
	//algorytm
	for(int i=1; i<=N; i++)
	{
		if(i<N && A[i]<A[i-1]) //porównanie elementow w tablicy A
		{
			dlugosc++;
		}
		else
		{
			if(dlugosc>najdluzszy)
			{
				najdluzszy=dlugosc;
				IloscNajdluzszych=0;
				PoczatekNajdluzszego[IloscNajdluzszych]=i-dlugosc; //tablica zapisujaca indeks poczatkowy znalezionego podciagu
				KoniecNajdluzszego[IloscNajdluzszych]=i-1;         //tablica zapisujaca indeks koncowy znalezionego podciagu
				IloscNajdluzszych++;  //zwiekszamy ilosc najdluzszych podciagow w razie wystapienia wiecej niz jednego podciagu takiej samej dlugosci
			}
			else if(dlugosc==najdluzszy)
			{
				PoczatekNajdluzszego[IloscNajdluzszych]=i-dlugosc;  //tablica zapisujaca indeks poczatkowy znalezionego podciagu
				KoniecNajdluzszego[IloscNajdluzszych]=i-1;  //tablica zapisujaca indeks koncowy znalezionego podciagu
				IloscNajdluzszych++;
			}
			dlugosc=1;
		}
	}
	
	if(najdluzszy>1)
	{
		cout<<"Najdluzszy podciag zawiera "<<najdluzszy<<" wyrazow:"<<endl;
		cout<<"Wyjscie: "<<endl;
		for(int i=0; i<IloscNajdluzszych; i++)    //petla zewnetrzna wypisywania wartosci podciagow
		{
			cout<<"{ ";
			for(int j=PoczatekNajdluzszego[i]; j<=KoniecNajdluzszego[i]; j++)  //petla wewnetrzna wypisywania wartosci podciagow
			{
				cout<<A[j]<<" ";
			}
			cout<<"}"<<endl;
		}
		cout<<"Ilosc znalezionych podciagow: "<<IloscNajdluzszych<<endl;
	}
	else {cout<<"Nie znaleziono najwiekszego podciagu.";}
	
	 // Zwolnienie pamieci
	delete[] PoczatekNajdluzszego;
	delete[] KoniecNajdluzszego;
}

int main()
{
	srand(time(NULL));
	for(int test=1; test<4; test++)
	{
		cout<<"TEST NR: "<<test<<endl;
		int N=rand()% 30 + 10;          //losowanie zakresu danych
		cout<<"Rozmiar tablicy wynosi: "<<N<<endl;
		cout<<"Wejscie: "<<endl;
		int *A=new int[N];             //tworzenie tablicy dynamicznej A[] przechowujacej dane
		cout<<"{ ";
		for(int i=0; i<N; i++)
		{
			A[i]=rand()%201-100;    //generowanie losowych liczb z zakresu od -100 do 100
			cout<<A[i]<<" ";
		}
		cout<<"}"<<endl;
		//obliczanie wyniku dwoma metodami
		cout<<endl<<"Program 1: "<<endl;
		ZnajdzNajwiekszyPodciagMalejacy(A, N);
		cout<<"Program 2: "<<endl;
		ZnajdzNajdluzszyPodciagMalejacy2(A, N);
		cout<<endl;
		
		// Zwolnienie pamieci
		delete[] A;
		cout<<endl<<endl;
	}
		
	
	return 0;
}