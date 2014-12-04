/*带括号的四则运算表达式字符串*/
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
using namespace std;

void Delspaces(char* str);				//去掉表达式里的空格
double expr(char* str);					//计算整个表达式的值
double term(char* str, int& index);		//得到每个小项的值
double number(char* str, int& index);	//获取数字
char* extract(char* str, int& index);	//获取括号里的字符串

const int MAX = 100;
int main()
{
	char buffer[MAX] = {0};
	cout<<"Enter an expression:"<<endl;
	while(1)
	{
		cin.getline(buffer, sizeof(buffer));
		Delspaces(buffer);
		if(!buffer[0])
		{
			return 0;
		}
		cout<<"\t= "<<expr(buffer)<<endl;
	}
}

void Delspaces(char* str)
{
	int i = 0;
	int j = 0;
	while((*(str + i) = *(str + j++)) != '\0')
	{
		if(*(str + i) != ' ')
		{
			i++;
		}
	}
}

double expr(char* str)
{
	double value = 0.0;		//存储结果
	int index = 0;			//保存当前字符位置
	
	value = term(str, index);	//得到第一个term
	while(1)
	{
		switch(*(str + index++))
		{
		case '\0':				//到达字符串的末尾
			return value;		//返回所得值
		case '+':
			value += term(str, index);
			break;
		case '-':
			value -= term(str, index);
			break;
		default:
			cout<<endl<<"There's an error"<<endl;
			exit(1);
		}
	}
}

double term(char* str, int& index)
{
	double value = 0.0;					//存放结果的变量

	value = number(str, index);

	//循环，遇到* 或/计算值，算作一项,遇到+ 或-则不算，直接返回value
	while((*(str + index) == '*') || (*(str + index) == '/'))
	{
		if(*(str + index) == '*')
		{
			value *= number(str, ++index);
		}
		if(*(str + index) == '/')
		{
			value /= number(str, ++index);
		}
	}
	return value;
}

double number(char* str, int& index)
{
	double value = 0.0;
	
	if(*(str + index) == '(')		//遇到（）则将其中的算式计算成一个数字
	{
		char* psubstr = NULL;
		psubstr = extract(str, ++index);
		value = expr(psubstr);
		delete[] psubstr;
		return value;
	}

	while(isdigit(*(str + index)))
	{
		value = 10 * value + (*(str + index++) - '0');
	}

	if(*(str + index) != '.')
	{
		return value;
	}

	double factor = 1.0;
	while(isdigit(*(str + (++index))))
	{
		factor *=0.1;
		value = value + (*(str + index) - '0') * factor;
	}
	return value;
}

char* extract(char* str, int& index)
{
	char buffer[MAX];
	char* pstr = NULL;
	int numL = 0;
	int bufindex = index;

	do
	{
		buffer[index - bufindex] = *(str + index);
		switch(buffer[index - bufindex])
		{
		case ')':
			if(numL == 0)
			{
				buffer[index - bufindex] = '\0';
				++index;
				pstr = new char[index - bufindex + 1];
				if(pstr == NULL)
				{
					cout<<"Menory allocation failed,"
						<<" Program terminated.";
					exit(1);	
				}
				strcpy(pstr, buffer);
				return pstr;
			}
			else
			{
				numL--;
			}
			break;
		case '(':
			numL++;
			break;
		}
	}while(*(str + index++) != '\0');

	cout<<"Need  )"<<endl;
	exit(1);
	return pstr;
}