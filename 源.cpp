#include<iostream>
#include<map>//�洢������Ԫ��Ϊ�ؼ��ּ����Ӧֵ
#include<fstream>//���ļ���ȡ�������ļ�д������
#include<sstream>//��string��ȡ������stringд������
#include<set>//�洢������ֻ�йؼ���
#include<vector>
#include<string>

#include<cstdlib>

//#include "make_plural.h"

using namespace std;

typedef vector<string>::size_type line_no;
vector<string>  file;
map<string,set<line_no>> wm;//��ͬ��ֵ��Ӧͬһ�ؼ���

void input_file(ifstream &is){
	string text;
	while(getline(is,text)){//�ļ��е�ÿһ��
		file.push_back(text);
		int n = file.size()-1;//�����к�
		istringstream line(text);//����һ��istringstream��line����text��ȡ����,Ϊ�˽�һ�зֽ�Ϊ�����ĵ���
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
		os << sought << "������0��" << endl;
	}
	else{
		auto lines = iter->second;
		os << sought << "������" << lines.size() << "��" << endl;
		for(auto num:lines)
			os << "\t(��" << num+1 << "�У�" << *(file.begin()+num) << endl;
	}
	return os;
}

void run(ifstream &infile){
	input_file(infile);//��ָ���ļ�������Ӧ����������map�洢
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


