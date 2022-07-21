#include <iostream>
#include <cmath>

using namespace std;

int main () {
	int x, y, bit;
	cin>>x;
	cin>>bit;
	int con = pow(2, bit - 1);
	string num;
	for(int i = 0; i < bit; i++){
		num.append("0");
	}
	for(int i = 0; i < bit; i++){
		y = pow(2, i);
		if(x >= con/y){
			num[i] = '1';
			x = x - con/y;
		}
	}
	cout<<num<<endl;
	return 0;
}
