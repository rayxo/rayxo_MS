#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;
class Sort
{
public:
	void push(int val);
	void display();	
	void Qsort();	//快速排序
	void Heapsort();	//堆排序
	void Insertsort();	//插入排序
	void Bubblesort();	//冒泡排序
	void Shellsort();	//谢尔排序

private:
	vector<int> datas;
	void Quicksort(int beg, int end);
	void Heapadjust(int size, int i);
	void Buildheap();
};
void Sort::push(int val)
{
	datas.push_back(val);
}
void Sort::display()
{
	cout<<"datas: ";
	for(int i = 0;i < datas.size(); i++)
		cout<<datas[i]<<" ";
	cout<<endl;
}
void Sort::Qsort()
{
	Quicksort(0, datas.size() - 1);
	cout<<"Quicksort: ";
}
void Sort::Quicksort(int beg, int end)
{
	if(beg < end)
	{
		int pivot = datas[beg];	
		int start = beg;
		int last = end;	
		while(beg < end)
		{			
			while(beg < end && datas[end] > pivot)
				end--;
			datas[beg] = datas[end];
			while(beg < end && datas[beg] <= pivot)
				beg++;
			datas[end] = datas[beg];
		}
		datas[beg] = pivot;
		Quicksort(start, beg - 1);
		Quicksort(beg + 1, last);
	}	
}
void Sort::Heapadjust(int size, int i)
{
	int left = 2 * i + 1;
	int right = left + 1;
	int Maxindex = i;
	if(left < size && datas[left] > datas[Maxindex])
		Maxindex = left;
	if(right < size && datas[right] > datas[Maxindex])
		Maxindex = right;
	if(Maxindex != i)
	{
		swap(datas[i], datas[Maxindex]);
		Heapadjust(size, Maxindex);
	}
}
void Sort::Buildheap()
{
	for(int i = datas.size() / 2; i >= 0; i--)
	{
		Heapadjust(datas.size(), i);
	}
}
void Sort::Heapsort()
{
	Buildheap();
	for(int i = datas.size() - 1; i > 0; i--)
	{
		swap(datas[0], datas[i]);
		Heapadjust(i, 0);
	}
	cout<<"Heapsort: ";
}
void Sort::Insertsort()
{
	for(int i = 1; i < datas.size(); i++)
	{
		if(datas[i] < datas[i - 1])
		{
			int k = i;
			int tmp = datas[i];
			while(k > 0 && datas[k - 1] > tmp)
			{
				datas[k] = datas[--k];
			}
			datas[k] = tmp;
		}
	}
	cout<<"Insertsort: ";
}
void Sort::Bubblesort()
{
	int flag = datas.size();
	while(flag > 0)
	{
		int i = flag;
		flag = 0;
		for(int j = 1; j < i; j++)
		{
			if(datas[j] < datas[j - 1])
			{
				swap(datas[j], datas[j - 1]);
				flag = j;
			}
		}
	}
	cout<<"Bubblesort: ";
}
#if 0
void Quicksort(int *a, int beg, int end)
{
	if(beg < end)
	{
		int pivot = a[beg];	
		int start = beg;
		int last = end;	
		while(beg < end)
		{			
			while(beg < end && a[end] > pivot)
				end--;
			a[beg] = a[end];
			while(beg < end && a[beg] <= pivot)
				beg++;
			a[end] = a[beg];
		}
		a[beg] = pivot;
		Quicksort(a, start, beg - 1);
		Quicksort(a, beg + 1, last);
	}	
}
void Heapadjust(int *a, int size, int i)
{
	int left = 2 * i + 1;
	int right = left + 1;
	int Maxindex = i;
	if(left < size && a[left] > a[Maxindex])
		Maxindex = left;
	if(right < size && a[right] > a[Maxindex])
		Maxindex = right;
	if(Maxindex != i)
	{
		swap(a[i], a[Maxindex]);
		Heapadjust(a, size, Maxindex);
	}
}
void Buildheap(int *a, int size)
{
	for(int i = size / 2; i >= 0; i--)
	{
		Heapadjust(a, size, i);
	}
}
void Heapsort(int *a, int size)
{
	Buildheap(a, size);
	for(int i = size - 1; i > 0; i--)
	{
		swap(a[0], a[i]);
		Heapadjust(a, i, 0);
	}
}
#endif
int main()
{
	Sort a;
	a.push(2);
	a.push(4);
	a.push(3);
	a.push(5);
	a.push(1);
	a.display();
	cout << "Please choice sort modle(1--qsort,2--heapsort,3--insertsort,4--bubblesort):";
	int ch;
	cin >> ch;
	switch(ch)
	{
		case 1:a.Qsort();	break;
		case 2:a.Heapsort();	break;
		case 3:a.Insertsort();	break;
		case 4:a.Bubblesort();	break;
		default: break;
	}
	//a.Bubblesort();
	//a.Qsort();
	a.display();
	system("pause");
}