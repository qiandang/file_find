#include<iostream>
#include<map>//存储容器，元素为关键字及其对应值
#include<fstream>//从文件读取或者向文件写入数据
#include<sstream>//从string读取或者向string写入数据
#include<set>//存储容器，只有关键字
#include<vector>
#include<string>

#include<cstdlib>

//#include "make_plural.h"

using namespace std;

typedef vector<string>::size_type line_no;
vector<string>  file;
map<string,set<line_no>> wm;//不同的值对应同一关键字

void input_file(ifstream &is){
	string text;
	while(getline(is,text)){//文件中的每一行
		file.push_back(text);
		int n = file.size()-1;//该行行号
		istringstream line(text);//构造一个istringstream即line并从text读取数据,为了将一行分解为单独的单词
		string word;
		while(line >> word){
			wm[word].insert(n);
		}
	}
}

ostream &query_and_print(const string &sought,ostream &os){
	auto iter = wm.find(sought);
	if(iter==wm.end())
	{
		os << sought << "出现了0次" << endl;
	}
	else{
		auto lines = iter->second;
		os << sought << "出现了" << lines.size() << "次" << endl;
		for(auto num:lines)
			os << "\t(第" << num+1 << "行）" << *(file.begin()+num) << endl;
	}
	return os;
}

void run(ifstream &infile){
	input_file(infile);//对指定文件建立相应的向量集和map存储
	while(true){
		cout << "enter a word for finding,or q to quit:" << endl;
		//system("pause");
		string s;
		if(!(cin>>s)||(s=="q"))break;
		else{
			query_and_print(s,cout) << endl;
		}
	}
}

int main(int argc,char **argv){
	ifstream infile;
	infile.open("my.txt");
	if(!infile){
		cerr<<"cant open"<<endl;
		return EXIT_FAILURE;
	}
	run(infile);
	system("pause");
	return 0;
}


