#include <iostream>
#include <ctime>
#include <time.h>

using namespace std;

void ZnajdzNajwiekszyPodciagMalejacy(int A[], int N)  //BRUTE FORCE
{
	int jest=0;
	int najdluzszy=0;
	int iloscNajdluzszych=0;
	int poczatekPodciagow[N];
	int koniecPodciagow[N];
	
	for(int i=1; i<=N; i++)  //ilosc wyrazow -> dlugosc podciagu
	{
		for(int j=0; j<N-i; j++)  //indeks od ktorego zaczyna sie podciag
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
				if(i>najdluzszy)
				{
					najdluzszy=i;
					iloscNajdluzszych=0;
					poczatekPodciagow[iloscNajdluzszych]=j;
					koniecPodciagow[iloscNajdluzszych]=j+i-1;
					iloscNajdluzszych++;
				}
				
				else if(i==najdluzszy)
				{
					poczatekPodciagow[iloscNajdluzszych]=j;
					koniecPodciagow[iloscNajdluzszych]=j+i-1;
					iloscNajdluzszych++;
				}
			}
		}
	}
	if(najdluzszy>1)
	{
		cout<<"Najdluzszy podciag zawiera "<<najdluzszy<<" wyrazow:"<<endl;
		for(int i=0; i<iloscNajdluzszych; i++)
		{
			cout<<"{ ";
			for(int j=poczatekPodciagow[i]; j<=koniecPodciagow[i]; j++)
			{
				cout<<A[j]<<" ";
			}
			cout<<"}"<<endl;
		}
		cout<<"Ilosc znalezionych podciagow: "<<iloscNajdluzszych<<endl;
	}
	else {cout<<"Nie znaleziono najmniejszego podciagu.";}
}

int main()
{
	srand(time(NULL));
	for(int test=1; test<4; test++)
	{
		cout<<"TEST NR: "<<test<<endl;
		//int N=120000;
		int N=rand()% 100000 + 10;
		cout<<"N wynosi: "<<N<<endl;
		int *A=new int[N];
		cout<<"{ ";
		for(int i=0; i<N; i++)
		{
			A[i]=rand()%200-99;
			//cout<<T[i]<<" ";
		}
		cout<<"}"<<endl;
		clock_t start = clock();
		ZnajdzNajwiekszyPodciagMalejacy(A, N);
		
		clock_t end = clock();
		double elapsed = double(end - start)/CLOCKS_PER_SEC;
		cout<<"Czas wykonywania programu: "<<elapsed;
		
		delete[] A;
		cout<<endl<<endl;
	}
		/*
	int N;
	srand(time(NULL));
	N=rand()% 30;
	cout<<"N wynosi: "<<N<<endl;
	int *T=new int[N];
	for(int i=0; i<N; i++)
	{
		T[i]=rand()%21-10;
		cout<<T[i]<<endl;
	}
	cout << "=========================" << endl;
	
	ZnajdzNajwiekszyPodciagMalejacy(T, N);
	*/
	
	return 0;
}