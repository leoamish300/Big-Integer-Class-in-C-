#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;
class BigInteger
{
	string str; 
	char sign;
	string sub_big(string &A,string &B);
	string add_big(string &A,string &B);
	string mul_big(string &A,string &B);
	bool isValid(string &A);
	bool cmp(string &A,string &B);
public:
	void assignDataMembers(string &A);
	BigInteger()
	{
		str="0"; sign='+';
	}
	BigInteger(string A)
	{
		assignDataMembers(A);
	}
	void show()
	{
		if(sign == '-' && str[0]!='0')
		cout<<sign<<str<<'\n';
		else
			cout<<str<<'\n';
	}
	BigInteger add(BigInteger &A,BigInteger &B);
	BigInteger sub(BigInteger &A,BigInteger &B);
	BigInteger mul(BigInteger &A,BigInteger &B);
	void add(BigInteger &A);
	void sub(BigInteger &A);
	void mul(BigInteger &A);
	BigInteger operator+(BigInteger B)
	{
		BigInteger C;
		C=add(*this,B);	return C;
	}
	BigInteger operator-(BigInteger B)
	{
		BigInteger C;
		C=sub(*this,B);	return C;
	}
	BigInteger operator*(BigInteger B)
	{
		BigInteger C;
		C=mul(*this,B); return C;
	}
	
};
void BigInteger::assignDataMembers(string &A)
	{
		str.clear();
		int l=A.size();
		if(isValid(A))
		 {
		 	int j=0;
		 	if(A[0]=='+' || A[0]=='-')
		 		j++;
		 	while(A[j]=='0' && j<l)
		 		j++;
		 	if(j==l)
		 		j--;
		 	str.assign(A.substr(j,l-j));
		 	if(A[0]=='-')
		 		sign='-';
		 	else
		 		sign='+';
		 }
		else
			{str="0"; sign='+';}
	}
string BigInteger::add_big(string &A,string &B)
	{
		int la=A.size(),lb=B.size();
		int i,j,k,lc=max(la,lb)+1;
		vector<int> C(lc,0);

		for(int i=0;i<lc;i++)
		{
			if(la>i)
				C[i]+=(A[la-i-1]-'0');
			if(lb>i)
				C[i]+=(B[lb-i-1]-'0');
		}
		for(i=0;i<(lc-1);i++)
		{
			C[i+1]+=(C[i]/10);
			C[i]=C[i]%10;
		}
		j=lc-1;
		while(j>=0 && C[j]==0)
			j--;
		j++;
		if(j==0)
			j++;
		string D(j,'\0');
		for(int i=0;i<j;i++)
			D[i]=C[j-i-1]+'0';
		return D;
	}
string BigInteger::sub_big(string &A,string &B)
	{ 
		int la=A.size(),lb=B.size();
		int i,j,k,lc=max(la,lb);
		vector<int> C(lc,0);

		for(int i=0;i<lc;i++)
		{
			if(la>i)
				C[i]+=(A[la-i-1]-'0');
			if(lb>i)
				C[i]-=(B[lb-i-1]-'0');
		}
		for(i=0;i<(lc-1);i++)
		{
			if(C[i]<0)
			{
				C[i]+=10; C[i+1]--;
			}
		}
		j=lc-1;
		while(j>=0 && C[j]==0)
			j--;
		j++;
		if(j==0)
			j++;
		string D(j,'\0');
		for(int i=0;i<j;i++)
			D[i]=C[j-i-1]+'0';
		return D;
	}
string BigInteger::mul_big(string &a,string &b)
	{
	int la=a.size(),lb=b.size(),lA,lB;
	lA=la+lb;

	vector<int> A(lA,0);
	for(int i=0;i<la;i++)
		{
			for(int j=0;j<lb;j++)
			{
				int ii=la-i-1,jj=lb-j-1;
				A[ii+jj]+=((a[i]-'0')*(b[j]-'0'));
			}
		}
		for(int i=0;i<(lA-1);i++)
		{
			if(A[i]>10)
			{
				A[i+1]+=(A[i]/10); A[i]%=10;
			}
		}
		int j=lA-1;
		while(j>=0 && A[j]==0)
			j--;
		j++;
		if(j==0)
			j++;
		string B(j,'0');
		for(int i=0;i<j;i++)
			B[i]=A[j-i-1]+'0';
	return B;
	}
bool BigInteger::isValid(string &A)
	{
		if(A.size() == 0)
			return false;
		if(A[0]!='+' && A[0]!='-' && (A[0]<'0' || A[0]>'9'))
			return false;
		if(A[0]=='+' || A[0]=='-')
		{
			if(A.size() < 2)
				return false;
		}
		for(int i=1;i<A.size();i++)
		{
			if(A[i]<'0' || A[i]>'9')
			return false;
		}
		return true;
	}
bool BigInteger::cmp(string &A,string &B)
	{
		int la=A.size(),lb=B.size(),i,j;
		if(la > lb)
			return true;
		if(lb > la)
			return false;
		for(int i=0;i<la;i++)
		{
			if(B[i]>A[i])
				return false;
		}
		return true;
	}

BigInteger BigInteger::add(BigInteger &A,BigInteger &B)
	{
		BigInteger C;
		if(A.sign == B.sign)
		{
			(C.str).assign(C.add_big(A.str,B.str));
			C.sign=A.sign;
		}
		else
		{
			if(C.cmp(A.str,B.str))
			{
				C.sign=A.sign; (C.str).assign(C.sub_big(A.str,B.str));
			}
			else
			{
				C.sign=B.sign; (C.str).assign(C.sub_big(B.str,A.str));
			}
		}
		return C;
	}
BigInteger BigInteger::sub(BigInteger &A,BigInteger &B)
	{
		BigInteger C;
		if(A.sign != B.sign)
		{
			(C.str).assign(C.add_big(A.str,B.str));
			C.sign=A.sign;
		}
		else
		{
			if(C.cmp(A.str,B.str))
			{
				C.sign=A.sign; (C.str).assign(C.sub_big(A.str,B.str));
			}
			else
			{
				(C.str).assign(C.sub_big(B.str,A.str));
				if(B.sign=='-')
					C.sign='+';
				else
					C.sign='-';
			}
		}
		return C;
	}
BigInteger BigInteger::mul(BigInteger &A,BigInteger &B)
	{
		BigInteger C;
		(C.str).assign(mul_big(A.str,B.str));
		if(A.sign == B.sign)
			C.sign='+';
		else
			C.sign='-';
		return C;
	}
void BigInteger::add(BigInteger &A)
	{
		*this=add(*this,A);
	}
void BigInteger::sub(BigInteger &A)
	{
		*this=sub(*this,A);
	}
void BigInteger::mul(BigInteger &A)
	{
		*this=mul(*this,A);
	}

void power(string &A,int B)
{
	BigInteger R,x; string a; a.clear(); a.assign("1");
	x.assignDataMembers(A);
	R.assignDataMembers(a);
	while(B > 0)
	{
		if(B%2 == 1)
			R.mul(x);
		B=B/2;
		cout<<B<<" **\n";
		x=x*x;
	}
	R.show();
}


int main()
{
	ifstream ci; ci.open("input.txt");
	ofstream co; co.open("output.txt"); 
	
	string A; int b;
	cin>>A>>b;
	power(A,b);
	
}