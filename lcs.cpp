#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

// to find the max value of 2 numbers
int max(int a , int b){
if (a>b) return a;
else return b;
}

int main(int argc,char*argv[]){
int l[2];
string st[2];
int count =0,size=0;

if(argc ==2){
ifstream ab("string.txt");
string s;

while(getline(ab,s)){
st[size] = s;
size++;
l[count]= s.length();
count++;
}

//cout<<l[0]<<","<<l[1];

int r =l[0]+1, c =l[1]+1;
string s1= st[0] ,s2 =st[1];
//cout<<s1<<","<<s2<<endl;

// dynamic 2-d array to find the length of LCS and LCS 
int** lcs = new int*[r];
for(int i = 0; i < r;i++){
    lcs[i] = new int[c];
}

// dynamic 2-d array to keep track of the path to find LCS
string** output = new string*[r];
for(int i = 0; i < r;i++){
    output[i] = new string[c];
}
for(int i=0;i<r;i++){
	for(int j=0;j<c;j++){
	  lcs[i][j]=0;
	}
}

if(r-1 ==0 || c-1 ==0) cout<<"Length of LCS is 0"<<endl;
else {

//LCS Algorithm
for (int i = 1; i <= r-1; i++) {
		for (int j = 1; j <= c-1; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
				output[i][j]="diag";
			} else {
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
				if(lcs[i][j]==lcs[i - 1][j])  output[i][j]="top";
				else if (lcs[i][j]==lcs[i][j-1]) output[i][j]="left";
			}
		}
	}
	//cout<<"Length of LCS is "<<lcs[r-1][c-1]<<endl;

		string result = "";
		int a = r-1;
		int b = c-1;

//To print the LCS by backtracking 		
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
	
			if (output[a][b] == "diag") {
				result = s1[a - 1] + result;
				a--;
				b--;
			} else if (output[a][b] == "left") {
				b--;
			} else if (output[a][b] == "top") {
				a--;
			}
		}
	   }
	cout<<result<<" "<<lcs[r-1][c-1]<<endl;
  }

}

return 0;
}
