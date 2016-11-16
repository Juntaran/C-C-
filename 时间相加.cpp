/*
	给定两个合法的时间（格式固定：hh:mm:ss，时间合法，不用考虑其它情况），
	输入两个时间相加后的结果；注意，相加后的结果也必需是一个合法的时间；
	附合法时间定义：小时在[00-23]之间，分钟和秒分别是在[00-59]之间；

*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// 整型转换为string
string Int2Str(int num){
    string str = "";
    if(num == 0){
        str = "0";
        return str;
    }//if
    while(num){
        str.insert(str.begin(),num % 10 + '0');
        num /= 10;
    }//while
    return str;
}

// 两个合法时间相加
string TimeAdd(string t1,string t2)
{
    int h1 = atoi(t1.substr(0,2).c_str());
    int h2 = atoi(t2.substr(0,2).c_str());
    int m1 = atoi(t1.substr(3,2).c_str());
    int m2 = atoi(t2.substr(3,2).c_str());
    int s1 = atoi(t1.substr(6,2).c_str());
    int s2 = atoi(t2.substr(6,2).c_str());

    int s = (s1 + s2) % 60;
    int m = (m1 + m2 + (s1 + s2) / 60) % 60;
    int h = (h1 + h2 + (m1 + m2) / 60) % 24;

    string str = "";
    if(h < 10){
        str += "0";
    }
    str += Int2Str(h) + ":";
    if(m < 10){
        str += "0";
    }
    str += Int2Str(m) + ":";
    if(s < 10){
        str += "0";
    }
    str += Int2Str(s);
    return str;
}


int main()
{
	string t1, t2;
    while (cin >> t1 >> t2)
        cout << TimeAdd(t1, t2) << endl;
    return 0;
}