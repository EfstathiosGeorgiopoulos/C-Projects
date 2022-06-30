//integer to binary number converter
#include <iostream>
#include <fstream>
using namespace std;

int main () {
	int x;
	ifstream input ("integer.in");
	ofstream output;
	output.open("binary.out", ios::out | ios::trunc);
	while(input>>x){
		int arr [8] = {0, 0, 0, 0, 0, 0, 0, 0};
		int num = x, con = 128;;
		while(con>=1 && x > 0){
			if(x>=con){
				if(con >= 128){
					arr[0] = 1;
					x = x - 128;
				}else if(con >= 64){
					arr[1] = 1;
					x = x - 64;
				}else if(con >= 32){
					arr[2] = 1;
					x = x - 32;
				}else if(con >= 16){
					arr[3] = 1;
					x = x - 16;
				}else if(con >= 8){
					arr[4] = 1;
					x = x - 8;
				}else if(con >= 4){
					arr[5] = 1;
					x = x - 4;
				}else if(con >= 2){
					arr[6] = 1;
					x = x - 2;
				}else if(con == 1){
					arr[7] = 1;
					x = x - 1;
				}
			}
			con = con/2;
		}
		for(int i = 0; i < 8; i++){
			output<<arr[i];
		}
		output<<" "<<endl;
	}
	output.close();
	input.close();
	return 0;
}
