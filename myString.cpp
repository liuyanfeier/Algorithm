#include<iostream>
#include<cstring>

using namespace std;

class _string
{
	friend std::istream& operator>>(std::istream& is, _string& a);
	friend std::ostream& operator<<(std::ostream& os,_string& a);

public:
	_string()     //默认构造函数
	{ 
		length = 0;
		b=new char[1];
		b[0]='\0';
	}             
	_string(char *a);   //构造函数
	_string(int n,char a);
	~_string(); //析构函数
	_string(_string &a);  //复制构造函数
	int size(){return length;}  //获得字符串长度
	_string operator+(const _string& a);   //重载'+'操作符
	_string& operator+=(const _string& a);   //重载'+='操作符
	_string& operator=(const _string& a);   //重载赋值操作符
	char& operator[]( int n);   //重载下标操作符
	_string  substr(int pos,int n);   //返回子字符串
	_string  substr(int pos);   //返回子字符串


private:
	char *b;
	int length;
};



_string::_string(char *a)     //构造函数
{
	length = strlen(a);   
	b = new char[length+1];
	for(int  i= 0;i<length;i++)
	{
		b[i] = a[i];
	}
	b[length] = '\0';
}

_string::_string(int n,char a)
{
	b=new char[n+1];
	for(int  i= 0;i<n;i++)
	{
		b[i] =a;
	}
	b[n] = '\0';
}

_string::~_string()     //析构函数
{
	delete []b;
	length=0;
}

_string::_string(_string &a)      //复制构造函数
{
	length=a.size();
	b=new char [length+1];
	for(int  i = 0;i<length;i++)
	{
		b[i] = a.b[i];
	}
	b[length] = '\0';
}

_string  _string::operator+(const _string& a)    //重载+
{
	int newLen = length+a.length;
	char *str;
	str = new char[newLen+1];
	int count = 0;
	for(int i = 0;i<length;i++)
	{
		str[i] = this->b[i];
		count++;
	}

	for(int i =0;count<newLen;count++,i++)
	{
		str[i] = a.b[i];
	}
	str[newLen] = '\0';
	_string temp(str);

	return temp;
}

_string&  _string:: operator+=(const _string& a)   //重载+=
{
	int newLen = length+a.length;
	char *str;
	str = new char[newLen+1];
	int count = 0;
	for(int i = 0;i<length;i++)
	{
		str[i] = this->b[i];
		count++;
	}

	for(int i =0;count<newLen;count++,i++)
	{
		str[i] = a.b[i];
	}
	str[newLen] = '\0';
	_string temp(str);
	*this=temp;
	return *this;
}
_string& _string:: operator=(const _string &a)    //重载=
{
	if(this==&a)
		return *this;

	delete []b;
	length = a.length;
	b = new char[length+1];
	for(int  i = 0;i<length;i++)
	{
		b[i] = a.b[i];
	}
	b[length] = '\0';
	return *this;

}

char& _string:: operator[]( int n)  //重载下标操作符
{
	if(n>length)
		return b[length-1];
	else
		return b[n];
}

ostream& operator<<(ostream& os, _string& a)  //重载输出符
{
	os<<a.b;
	return os;
}
istream& operator>>(std::istream& is, _string& a)  //重载输入符
{   
	is>>a.b ;
	a.length=strlen(a.b);
	return is;
}

_string  _string::substr(int pos, int n)    //两个接受不同参数的substr函数，返回子字符串
{
	char *p = new char[n+1];
	for(int i=0;i<n;i++)
	{
		p[i]=b[pos];
		pos++;
	}
	p[n]='\0';
	_string k(p);
	k.length=n;
	return  k;
}

_string  _string::substr(int pos)
{
	int len=length;
	char *p=new char[len-pos+1];
	int t=pos;
	for(int i=0;t<len;t++,i++)
	{
		p[i]=b[t];
	}
	p[t]='\0';
	_string k(p);
	k.length=len-pos;
	return  k;
}



int main()
{
    _string a("1234");
    cout<<a.size()<<endl;
    _string b("5678");
    a+=b;
    cout<<a.size()<<endl;
    _string aa("111");
    _string bb("222");
    _string c;
    c=aa+bb;
    cout<<"c size  1  "<<c.size()<<endl;
    c=aa;
    cout<<"c size  2  "<<c.size()<<endl;
   c="1234567";
    cout<<"c size  3  "<<c.size()<<endl;
    cout<<c<<endl;
    _string xxx(10,'2');
    cout<<"xxx is  "<<xxx<<endl;
    _string str;
    
	cout<<"substr"<<endl;
	_string abc("1234567");
	_string xx=abc.substr(3,3);
	cout<<"xx is "<<xx<<endl;
	_string qq=abc.substr(3);
	cout<<"qq is "<<qq<<endl;



	return 0;
}
