#include <iostream>
#include <cmath>

using namespace std;

int main (){
	int sum [19] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			for(int k = 0; k < 6; k++){
				sum[i+j+k+3]++;
			}
		}
	}
	double a;
	for(int i = 3; i < 19; i++){
		double p = (sum[i]/pow(6,3))*100;
		a += p;
		cout<<i<<" : "<<p<<"%"<<endl;
	}
	cout<<a;
	return 0;
}
