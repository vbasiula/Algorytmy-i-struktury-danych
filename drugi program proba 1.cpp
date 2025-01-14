#include <iostream>
#include <iomanip>

using namespace std;

void ZnajdzNajdluzszyPodciagMalejacy2(int A[], int N)
{
	int dlugosc=1;
	int najdluzszy=0;
	int IloscNajdluzszych=0;
	int NajwiekszaDlugosc=0;
	int PoczatekPodciagu[N];
	int PoczatekNajdluzszego[N];
	int KoniecNajdluzszego[N];
	const int brakCiagu=-2;
	int T[N];
	
	//porónywanie wartosci i wpisywanie indeksow do tablicy T
	for(int i=0; i<N; i++)
	{
		if(i>0 && A[i-1]>A[i] )
		{
			T[i-1]=i-1;
			T[i]=i;
		}
		else 
		{
			T[i]=brakCiagu;
		}
	}
	for(int i=0; i<N; i++)
	{
		cout<<T[i]<<setw(4);
	}
	//algorytm
	for(int i=1; i<=N; i++)
	{
		if(i<N && T[i]==T[i-1]+1) //porównanie elementow w tablicy T
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
	
	
	cout<<endl;
	if(najdluzszy>1)
	{
		cout<<"Najdluzszy podciag zawiera "<<najdluzszy<<" wyrazow:"<<endl;
		for(int i=0; i<IloscNajdluzszych; i++)
		{
			cout<<"{ ";
			for(int j=PoczatekNajdluzszego[i]; j<=KoniecNajdluzszego[i]; j++)
			{
				cout<<A[j]<<" ";
			}
			cout<<"}"<<endl;
		}
	}
	else {cout<<"Nie znaleziono najmniejszego podciagu.";}
}



int main()
{
	int N=10,A[N]={-10,5,8,1,-4,-4,10,3,2,1};
	for(int i=0; i<N; i++)
	{
		cout<<A[i]<<setw(4);
	}
	cout<<endl;
	ZnajdzNajdluzszyPodciagMalejacy2(A, N);
	
	return 0;
}