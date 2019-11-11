#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

	string add(string &A,string &B)
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

//asume a >= b	
	string sub(string &A,string &B)
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

	bool cmp(string &A,string &B)
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


string mul(string a,string b)
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
		for(int i=0;i<lA;i++)
			cout<<A[i]<<" ";
		cout<<"*\n";
		for(int i=0;i<(lA-1);i++)
		{
			if(A[i]>=10)
			{
				A[i+1]+=(A[i]/10); A[i]%=10;
			}
		}

		for(int i=0;i<lA;i++)
			cout<<A[i]<<" ";
		cout<<"*\n";
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

void print(string A)
{
	int i=0;
	while(A[i])
		{cout<<A[i]; i++;}
	return;
}
int main()
{
	//ifstream ci; ci.open("input.txt");
	//ofstream co; co.open("output.txt"); 
	
	int i,j,k;
	i=0;
	cin>>k;
	while(k--)
	{
		string A,B; cin>>A>>B;
		cout<<mul(A,B)<<" \n";
	}
	return 0;
}