#include<iostream>
using namespace std;
class Amish
{
	int A; int B;
public:
	Amish()
	{
		A=0; B=-3;
	}
	Amish(int j){	A=j; B=j;}
	Amish(int i,int j){	A=i; B=j;}
	void show(){	cout<<A<<" "<<B<<"\n";}
	Amish operator,(Amish B)
	{
		B.A=A-B.A;
		B.B=this->B-B.B;
		return B;
	}
	int operator[](int i)
	{
		if(i==0)
			return A;
		return B;
	}
	
};

int main()
{
	Amish A(6,8),B(9,67);
	A.show();
	B.show();
	Amish C;
	cout<<A[0]<<" "<<A[345]<<'\n';
	cout<<B[0]<<" "<<B[-9876]<<'\n';
	C=(B,A);
	
	A.show();
	B.show();
	C.show();
}