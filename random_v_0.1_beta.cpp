#include<iostream>
#include<stack>
#include<time.h>
#include<stdio.h>
#include<vector>
using namespace std;

int TIMES;				//._rd
int MAX;				//.rd_
int BADASS;				//check type of error message
int TYPE;				//for instant expend
int STEP;				//decided which stack to put
bool flag=false;
vector<char> vec;
stack<int> times;		//save the imput of TIMES
stack<int> max;			//save the imput of MAX

void str2int() {			//translate string in vector to int, and put it into stack
	if (flag == true) {
		int n = vec.size();
		int num=0;
		for (int i = 0; i<n; i++)
		{
			num = vec[i]-'0' + num * 10;
		}
		if (STEP == 1) times.push(num);
		else if (STEP == 3)max.push(num);
		flag = false;
		vec.clear();
	}
}


void error(int param) {
	switch (param) {
	case 1:cout << "ILLEGAL IMPUT!!  Please check out your summary" << endl;
	}
}

void classify(char c) {
	if (c == '.')
		STEP = 1;
	else if (c >= '0'&&c<='9') {
		flag = true;
		vec.push_back(c);
	}
	else if (c >= 'a'&&c <= 'z') {
		str2int();
		if (STEP == 1 && c == 'r')
		{
			STEP = 2;
		}
		else if (STEP == 2 && c == 'd'){
			STEP = 3;
		}
		else {
			error(1);
		}
	}
}
void free() {
	while (!times.empty())times.pop();
	while (!max.empty())max.pop();
	TIMES = 1;
	MAX = 100;
	vec.clear();
}
void display(int res) {
	cout << res << endl;
	for (int i = 0; i<24; i++)cout << "*";
	cout << endl;
	free();
}
void random() {
	int res;
	TIMES = times.empty() ? 1 : times.top();
	//cout << TIMES << endl;
	MAX = max.empty() ? 100 : max.top();
	//cout << MAX << endl;
	res = TIMES * (rand() % MAX + 1);
	display(res);
}




void welcome() {
	for (int i = 0; i<24; i++)cout << "*";
	cout << endl;
	cout << "    Random  V_0.1_beta    " << endl;
	for (int i = 0; i<24; i++)cout << "*";
	cout << endl;
}

int main() {
	welcome();
	char c;
	srand((int)time(0));
	while (1) {
		free();
		c = getchar();
		//int i = 0;
		while (c != '\n') {
			//cout << i++ << endl;
			//cout << "STEP= " << STEP <<" c= "<<c<< endl;
			classify(c);
			c = getchar();
		}
		//cout << "circle over" << endl;
		str2int();
		//cout << "change over" << endl;
		random();
	}
}