#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;
int Maxsum(vector<int> a)
{
	int sum=0;
	int Max=0;
	#if 0
	for(int i = 0;i < a.size();i++)
	{			
		if(sum < 0)
			sum = a[i];
		else
			sum += a[i];
		if(sum > Max)
			Max = sum;
	}
	#endif
	for(vector<int>::iterator p = a.begin();p != a.end();p++)
	{
		if(sum < 0)
			sum = *p;
		else
			sum += *p;
		if(sum > Max)
			Max = sum;
	}
	return Max;
}
int main()
{
	vector<int> s;
	int val;
	do
	{
		cin>>val;
		s.push_back(val);
	}while(val != -1);
	cout<<Maxsum(s)<<endl;
	system("pause");
}