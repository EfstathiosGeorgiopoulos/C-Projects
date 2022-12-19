#include<bits/stdc++.h> 
#include<iostream>
#include<cmath>
#include<fstream>
#include<string>

using namespace std; 

ofstream output; 

void combinationUtil(int arr[], int data[], int start, int end, int index, int r); 
void printCombination(int arr[], int n, int r) { 
	int data[r]; 
	combinationUtil(arr, data, 0, n, 0, r); 
} 
void combinationUtil(int arr[], int data[], int start, int end, int index, int r) { 
	if (index == r) 
	{ 
		for (int j = 0; j < r; j++) 
			output<<data[j]; 
		output<<endl; 
		return; 
	} 
	for (int i = start; i < end; i++) 
	{ 
		data[index] = arr[i]; 
		combinationUtil(arr, data, start, 
						end, index+1, r); 
	} 
} 
int main() {  
	output.open("comb.in", ios::out | ios::trunc);
	int arr[] = {1, 2, 3, 4, 5, 6}; 
	int r;
	cout<<"Insert the number of dises: "<<endl;
	cin>>r;
	int n = sizeof(arr)/sizeof(arr[0]); 
	printCombination(arr, n, r); 
	output.close();
	ifstream input ("comb.in");
	int sum[6*r + 1];
	for(int i = 0; i < sizeof(sum)/sizeof(sum[0]); i++){
		sum[i] = 0;
	}
	string s;
	for(int i = 0; i < pow(6, r); i++){
		int u = 0;
		input>>s;
		for(int j = 0; j < s.size(); j++){
			if(s[j] == '1'){
				u+=1;
			}else if(s[j] == '2'){
				u+=2;
			}else if(s[j] == '3'){
				u+=3;
			}else if(s[j] == '4'){
				u+=4;
			}else if(s[j] == '5'){
				u+=5;
			}else if(s[j] == '6'){
				u+=6;
			}else{
				u+=0;
			}
		}
		sum[u]++;
	}
	input.close();
	ofstream out;
	out.open("probabilities.out", ios::out | ios::trunc);
	for(int i = 0; i < sizeof(sum)/sizeof(sum[0]); i++){
		out<<"Sum of "<<i<<" : "<<(sum[i]/pow(6,r))*100<<"%"<<"\n";
	}
	out.close();
}
