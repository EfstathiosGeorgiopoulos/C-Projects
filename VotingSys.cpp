#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k, q, x, out, s;

int main () {
	vector <int> myvector;
	ifstream input ("voting.in");
	input>>n>>m>>k;
	for(int i = 0; i <= m; i++){
		myvector.push_back(0);
	}
	for(int i = 1; i <= k; i++){
		input>>q;
		myvector[q] = myvector[q] + 1;
	}
	x = n - k;
	for(int i = 1; i <= m; i++){
		s = myvector[i];
		myvector[i] = myvector[i] + x;
		int max = *max_element(myvector.begin(), myvector.end());
		int range = count(myvector.begin(), myvector.end(), max);
		if(myvector[i]==max && range==1){
			out++;
		}
		myvector[i]=s;
	}
	ofstream output;
	output.open("voting.out", ios::out | ios::trunc);
	output<<out;
	output.close();
	input.close();
	return 0;
}
