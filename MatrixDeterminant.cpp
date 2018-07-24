#include <iostream>
#define ARRAYSIZE 3

using namespace std;

int** declareArray(int size){
	int** array	= new int*[size];
	for(int i = 0; i < size; i++){
		array[i] = new int[size];
	}
	return array;
}

void fillArray(int** array, int size){
	int arrayContent = 1;
	for(int y = 0; y < size; y++){
		for(int x = 0; x < size; x++){
			array[y][x] = arrayContent;
			arrayContent++;
		}
	}
}

void printArray(int** array, int size){
	for(int y = 0; y < size; y++){
		for(int x = 0; x < size; x++){
			cout << array[y][x] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int determinant(int** matrix, int size){
	if(size == 2){
		return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
	} else {
		bool isNegativeAddition = false;
		int determinantResult = 0;
		
		for(int x = 0; x < size; x++){
			int i = 0;
			int *numbersForNewRecursiveCall = new int[(size - 1) * (size - 1)];
			
			for(int sy = 0; sy < size; sy++){
				for(int sx = 0; sx < size; sx++){
					if(sy != 0 && sx != x){
						numbersForNewRecursiveCall[i] = matrix[sy][sx];
						i++;
					}
				}
			}
				
			i = 0;
			int **subMatrix = declareArray(size-1);
			for(int sy = 0; sy < size-1; sy++){
				for(int sx = 0; sx < size-1; sx++){
					subMatrix[sy][sx] = numbersForNewRecursiveCall[i];
					i++;
				}
			}
			
			if(isNegativeAddition == true){
				determinantResult = determinantResult + (matrix[0][x] * determinant(subMatrix, size-1) * -1);
				isNegativeAddition = false;
			} else {
				determinantResult = determinantResult + (matrix[0][x] * determinant(subMatrix, size-1));
				isNegativeAddition = true;
			}
			
		}
		return determinantResult;
	}
}

int main(){
	int arraySize = 0;
	cout << "Cual desea que sea el tamaño de la matriz?_";
	cin >> arraySize;
	int **matrix = declareArray(arraySize);
	
	for(int y = 0; y < arraySize; y++){
		for(int x = 0; x < arraySize; x++){
			cout << "Matrix[" << y << "][" << x << "]: ";
			cin >> matrix[y][x];
		}
	}
	
	cout << "Determinante: " << determinant(matrix, arraySize) << endl;
	
	system("PAUSE");
	return 0;
}
