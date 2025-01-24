#include <iostream>
#include <iomanip>
#include <ctime>
#include <time.h>

using namespace std;

void ZnajdzNajdluzszyPodciagMalejacy2(int A[], int N)
{
	int dlugosc=1;
	int najdluzszy=0;
	int IloscNajdluzszych=0;
	
	int *PoczatekNajdluzszego=new int[N];
	int *KoniecNajdluzszego=new int[N];
	
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
				PoczatekNajdluzszego[IloscNajdluzszych]=i-dlugosc;
				KoniecNajdluzszego[IloscNajdluzszych]=i-1;
				IloscNajdluzszych++;
			}
			else if(dlugosc==najdluzszy)
			{
				PoczatekNajdluzszego[IloscNajdluzszych]=i-dlugosc;
				KoniecNajdluzszego[IloscNajdluzszych]=i-1;
				IloscNajdluzszych++;
			}
			dlugosc=1;
		}
	}
	
	if(najdluzszy>1)
	{
		cout<<"Najdluzszy podciag zawiera "<<najdluzszy<<" wyrazow:"<<endl;
		cout<<"Wyjscie: "<<endl;
		for(int i=0; i<IloscNajdluzszych; i++)
		{
			cout<<"{ ";
			for(int j=PoczatekNajdluzszego[i]; j<=KoniecNajdluzszego[i]; j++)
			{
				cout<<A[j]<<" ";
			}
			cout<<"}"<<endl;
		}
		cout<<"Ilosc znalezionych podciagow: "<<IloscNajdluzszych<<endl;
	}
	else {cout<<"Nie znaleziono najmniejszego podciagu.";}
	
	delete[] PoczatekNajdluzszego;
	delete[] KoniecNajdluzszego;
}



int main()
{
	srand(time(NULL));
	for(int test=1;test<4;test++)
	{
		cout<<"TEST NR "<<test<<":"<<endl;
		int N=rand()% 30+11;
		int *A=new int[N];
		cout<<"Rozmiar tablicy wynosi: "<<N<<endl;
		cout<<"Wejscie: "<<endl;
		cout<<"{ ";
		for(int i=0; i<N; i++)
		{
			A[i]=rand()%200-99;
			cout<<A[i]<<setw(4);
		}
		cout<<"}"<<endl;
		ZnajdzNajdluzszyPodciagMalejacy2(A, N);
		cout<<endl;
		delete []A;
	}
	/*
	int N=10,A[N]={-10,5,8,1,-4,-4,10,3,-1,1};
	ZnajdzNajdluzszyPodciagMalejacy2(A, N);
	*/
	return 0;
}