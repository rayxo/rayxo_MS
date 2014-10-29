#include<iostream>
#include<cstdlib>
#include<vector>
#include<cassert>
using namespace std;
template<typename T>
class Minstack
{
public:
	vector<T> datas;
	vector<T> Mindatas;
	void push(T val);
	void pop();
	T min();
	void display();	
};
template<typename T>
void Minstack<T>::push(T val)
{
	datas.push_back(val);
	if(Mindatas.empty() || val < datas[Mindatas.back()])
		Mindatas.push_back(datas.size() - 1);
}
template<typename T>
void Minstack<T>::pop()
{
	assert(!datas.empty());
	if(datas.back() == datas[Mindatas.back()])
		Mindatas.pop_back();
	datas.pop_back();
}
template<typename T>
T Minstack<T>::min()
{
	assert(!datas.empty() && !Mindatas.empty());
	return datas[Mindatas.back()];
}
template<typename T>
void Minstack<T>::display()
{
	cout<<"datas: ";
	for(int i = 0;i < datas.size(); i++)
		cout<<datas[i]<<" ";
	cout<<endl;
	cout<<"Mindatas: ";
	for(int i = 0;i < Mindatas.size();i++)
		cout<<datas[Mindatas[i]]<<" ";
	cout<<endl;
	//cout<<"Min: "<<datas[Mindatas.back()]<<endl;
	cout<<"Min: "<<min()<<endl;
}
int main()
{
	Minstack<int> s;
	s.push(3);
	s.display();
	s.push(4);
	s.display();
	s.push(2);
	s.display();
	s.push(0);
	s.display();
	s.push(7);
	s.display();
	s.push(3);
	s.display();
	s.pop();
	s.display();
	s.pop();
	s.display();
	s.pop();
	s.display();
	s.pop();
	s.display();
	s.pop();
	s.display();	
	s.push(8);
	s.display();
	s.push(1);
	s.display();
	system("pause");
}