#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

class RandomNumber
{
public:
	int Random(int);
};

int RandomNumber::Random(int count)
{	
    srand(time(NULL)+count);
	return (rand()%(count));
}

class Queen
{
	friend void nQueen(int);
private:
	bool Place(int k); //�Ϸ��Լ��
	bool QueensLV(); //�������n���ʺ����˹ά��˹�㷨
	int n,*x,*y;//�ʺ����n��������xy 
};

bool Queen::Place(int k)
{
	for(int j=1;j<k;j++)
       if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k])) return false;
    
	return true;     
}

bool Queen::QueensLV()
{
	RandomNumber rnd;
	int k=1,count=1;
	while((k<=n)&&(count>0))
	{
		count=0;
		for(int i=1;i<=n;i++) //��һ�е���n�� 
		{
			x[k]=i;//k��ʾ��k�У�x[k]��ʾ��x[k]�� 
			if(Place(k)) y[count++]=i;
		}
		if(count>0) x[k++]=y[rnd.Random(count)];
	}
	return (count>0);    //��ʾ���óɹ� 
}

void nQueen(int n)
{
	Queen X;
	X.n=n;
	int *p= new int[n+1];
	for(int i=0;i<=n;i++) p[i]=0;
	X.x=p;
	while(!X.QueensLV());//��������ֱ���ɹ�����ѭ��
	//for(int i=1;i<=n;i++) cout<<p[i]<<" ";
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			cout<<" ";
		    for(int j=1;j<=n;j++) cout<<"     "<<j;
		}	        	       
	    cout<<endl<<endl<<i<<"     "; 
	    {
	    	for(int j=1;j<=n;j++)
	    	{
	    		if(p[i]==j) cout<<"O"<<endl;
	    		else if(p[i]==0) 
				{
				   cout<<endl;
				   break;
				}
	    		else cout<<"      ";
	    		
			}	    	
		}	   
	}
	cout<<endl;
	delete[] p;	
}

int main()
{
/*	int n;
    do
	{
	   cout<<"������n=";
	   cin>>n;
	   cout<<"����"<<n<<"����������һ��������(û������Ż�4~6���)"<<endl; 
	   
	   cout<<endl;
	}while(n>0);*/
	cout<<"����5����������һ��������"<<endl;
    nQueen(5);
	return 0;
}
