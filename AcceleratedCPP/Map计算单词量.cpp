#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int main(){
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    string  s;
    map<string,int>counters; 
    while (cin>>s)
    {
        /* code */
        ++counters[s];//对s所对应的整数加1操作，读到新的s时，对应初始化的时候整形这样的简单类型初始化为0；
    }
    for (map<string,int>::const_iterator it=counters.begin();it!=counters.end();++it)
    {
        /* code */
        cout<<it->first<<"\t"<<it->second<<endl;//容器有一个伴随的库类型pair，简单的数据结构，在这里时pair<const K,V>键是常量，无法修改元素值。
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //默认使用split来调用xref
    map<string,vector<int> >ret=xref(cin);
    //输出结果
    for (map<string,vector<int> >::const_iterator it=ret.begin();it!=ret.end();++it)
    {
            cout<<it->first<<"出现的行数为：";
            vector<int>::const_iterator line_it=it->second.begin();
            cout<<*line_it; //输出第一行编号
            ++line_it;
            //如果还有就输出其他行
            while (line_it!=it->second.end())
            {
                cout<<","<<*line_it;
                ++line_it;
            }
            cout<<endl;
            
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    return 0;
}


//xref(cin);     在输入流中使用split查找单词。
//xref(cin,find_urls);      使用名为find_urls的函数查找单词
map<string,vector<int>> xref (istream& in,vector<string>find_words(const string&)=split){
    string line;
    int line_number=0;
    map<string,vector<int> >ret;//这里两个>>间要空格。
    //读一行
    while (getline(in,line))
    {
        ++line_number;
        //将输入行分割成单词
        vector<string>words=find_words(line);
        for (vector<string>::const_iterator it=words.begin(); it!=words.end();++it)
        {
            ret[*it].push_back(line_number);
        }
        
    }
    return ret;
}