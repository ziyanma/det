#include <iostream>
#include <cmath>
using namespace std;

//helper function return reduced item
int** reduce(int row, int a, int b, int**mat){
	int** red=new int*[row-1];
	for (int i=0; i<row-1; i++){
		red[i]=new int[row-1];
		int it=0;
		for (int j=0; j<row; j++){
			if (j!=b){
				red[i][it]=mat[i+1][j];
				it++;
			}
		}
	}
	return red;
}

int determinant(int row, int col, int** mat){
	if (row==1){
		return mat[0][0];
	}
	else {
		int result=0;
		int multiplier=-1;
		for (int i=0; i<col; i++){
			multiplier*=-1;
			result+=multiplier*mat[0][i]*
				determinant(row-1,col-1,reduce(row,0,i,mat));
		}
		return result;
	}
}

int main(){
	int row,col;
	cout<<"Input row #"<<endl;
	cin>>row;
	col=row;
	int** matrix=new int*[row];
	for (int i=0; i<row; i++){
		matrix[i]=new int[col];
	}
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			cin>>matrix[i][j];
		}
	}
	cout<<determinant(row,col,matrix)<<endl;
}
