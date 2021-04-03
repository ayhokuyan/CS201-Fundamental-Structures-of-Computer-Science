#include <iostream>
#include <chrono>
#include <stdlib.h>
using namespace std;

/*
	Solution with Cubic time complexity O(N^3)
*/
int maxSumCub(int*& arr, int size){
    int maxSum = 0;
    for(int i=0; i<size; i++){
        for(int j=i; j<size; j++){
            int tempSum = 0;

            for(int k=i; k<=j; k++){
                tempSum += arr[k];
            }
            if(tempSum > maxSum){
                maxSum = tempSum;
            }
        }
    }
    return maxSum;
}

/*
	Solution with Quadratic time Complexity O(N^2)
*/
int maxSumQuad(int*& arr, int size){
   int maxSum = 0;

   for(int i=0; i<size; i++){
       int thisSum = 0;
       for (int j = i; j < size; j++){
           thisSum += arr[j];

            if(thisSum > maxSum)
                maxSum = thisSum;
       }
       
   }
   return maxSum;
}

int max3(int a, int b, int c){
    return max(a,max(b,c));
}

/*
	Recursive Solution with time complexity O(NlogN)
*/
int maxSumRec(int*& arr, int left, int right){
    if(left==right){
        if(arr[left] > 0)
            return arr[left];
        else
            return 0;
        
    }

    int center = (left+right)/2;
    int maxLeftSum = maxSumRec(arr,left,center);
    int maxRightSum = maxSumRec(arr,center+1,right);

    int maxLeftBorderSum = 0, leftBorderSum = 0;
    for(int i = center; i >= left; i--){
        leftBorderSum += arr[i];
        if(leftBorderSum >maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }

    int maxRightBorderSum =0, rightBorderSum = 0;
    for(int j=center+1; j<=right; j++){
        rightBorderSum += arr[j];
        if(rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }

    return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}

/*
	Linear Time Complexity Solution
*/
int maxSumLin(int*& arr, int size){
    int maxSum = 0, thisSum = 0;
    
    for(int j=0; j < size; j++){
        thisSum += arr[j];

        if(thisSum > maxSum)
            maxSum = thisSum;
        else if(thisSum < 0)
            thisSum = 0;
    }
    return maxSum;
}

/**
	This method creates a dynamic array using pass by reference in the parameter list 
	with a minimum value of -100 and maximum of 100. 
*/
void createArray(int size, int*& arr){
    int min = -100;
    int max = 100;
    if(arr != NULL)
        delete[] arr;
    arr = new int[size];
    for(int i=0; i<size; i++){
        int randomNum = min + (rand() % (max-min+1));
        arr[i] = randomNum;
    }
} 


//This is the method that has been used to obtain the comparison table
int main(){
    int sizes[] = {1,10,20,40,80,100,200,300,400,600,800,1000,1200,1400,1600,1800,2000,2400,3200,4000};
    int size = 20;
    int* gen1 = new int[3]{1,2,3};

    chrono::time_point< std::chrono::system_clock > startTime;
    chrono::duration< double, milli > elapsedTime;

    cout << "Cub:" << endl;   
    for(int i= 0; i < size ; i++){
        createArray(sizes[i],gen1);
        startTime = chrono::system_clock::now();
        maxSumCub(gen1,sizes[i]);
        elapsedTime = chrono::system_clock::now() - startTime;
        cout << elapsedTime.count() << ", ";
    }
    cout << endl;

    cout << "Quad:" << endl;   
    for(int i= 0; i < size ; i++){
        createArray(sizes[i],gen1);
        startTime = chrono::system_clock::now();
        maxSumQuad(gen1,sizes[i]);
        elapsedTime = chrono::system_clock::now() - startTime;
        cout << elapsedTime.count() << ", ";
    }
    cout << endl;

    cout << "Log:" << endl;   
    for(int i= 0; i < size ; i++){
        createArray(sizes[i],gen1);
        startTime = chrono::system_clock::now();
        maxSumRec(gen1,0,sizes[i]-1);
        elapsedTime = chrono::system_clock::now() - startTime;
        cout << elapsedTime.count() << ", ";
    }
    cout << endl;

    cout << "Lin:" << endl;   
    for(int i= 0; i < size ; i++){
        createArray(sizes[i],gen1);
        startTime = chrono::system_clock::now();
        maxSumLin(gen1,sizes[i]);
        elapsedTime = chrono::system_clock::now() - startTime;
        cout << elapsedTime.count() << ", ";
    }
    delete[] gen1;
    cout << endl;

    return 0;
}

/*
	These main methods are used to obtain the data used for the other plots in the report.
	They are not to be considered as part of the homework assignemnt. I have put these in here as an
	answer to the question regarding where I have found the other ecexution time data that I have discussed
	throughout the report. Regards.
*/

/*
int main(){
	int* gen1 = NULL;

	chrono::time_point< std::chrono::system_clock > startTime;
	chrono::duration< double, milli > elapsedTime;

	for (int i = 10; i < 10010; i=i+500){
		createArray(i,gen1);
		cout << "Size = " << i << endl;
		//Cubic
		startTime = chrono::system_clock::now();
		cout << maxSumCub(gen1,i) << endl;
		elapsedTime = chrono::system_clock::now() - startTime;
		cout << "Cubic:     " << elapsedTime.count() << " ms" << endl;
		//Quadratic
		startTime = chrono::system_clock::now();
		cout << maxSumQuad(gen1,i) << endl;
		elapsedTime = chrono::system_clock::now() - startTime;
		cout << "Quadratic: " << elapsedTime.count() << " ms" << endl;
		//NLogN
		startTime = chrono::system_clock::now();
		cout << maxSumRec(gen1,0,i-1) << endl;
		elapsedTime = chrono::system_clock::now() - startTime;
		cout << "Logaritmic:" << elapsedTime.count() << " ms" << endl;
		//Linear
		startTime = chrono::system_clock::now();
		cout << maxSumLin(gen1,i) << endl;
		elapsedTime = chrono::system_clock::now() - startTime;
		cout << "Linear:    " << elapsedTime.count() << " ms" << endl;
	}
}*/

/*
int main(){
	int* gen1 = new int[3]{1,2,3};

	chrono::time_point< std::chrono::system_clock > startTime;
	chrono::duration< double, milli > elapsedTime;

	cout << "Cubic:" << endl;
	for (int i = 1; i < 201; i=i+5){
		createArray(i,gen1);
		startTime = chrono::system_clock::now();
		maxSumCub(gen1,i);
		elapsedTime = chrono::system_clock::now() - startTime;
		cout << elapsedTime.count() << ", ";
	}
	cout << endl;

	cout << "Quadratic:" << endl;
	for (int i = 1; i < 201; i=i+5){
		createArray(i,gen1);
		startTime = chrono::system_clock::now();
		maxSumQuad(gen1,i);
		elapsedTime = chrono::system_clock::now() - startTime;
		cout << elapsedTime.count() << ", ";
	}
	cout << endl;


	cout << "Log:" << endl;
	for (int i = 1; i < 201; i=i+5){
		createArray(i,gen1);
		startTime = chrono::system_clock::now();
		maxSumRec(gen1,0,i-1);
		elapsedTime = chrono::system_clock::now() - startTime;
		cout << elapsedTime.count() << ", ";
	}
	cout << endl;


	cout << "Lin:" << endl;
	for (int i = 1; i < 201; i=i+5){
		createArray(i,gen1);
		startTime = chrono::system_clock::now();
		maxSumLin(gen1,i);
		elapsedTime = chrono::system_clock::now() - startTime;
		cout << elapsedTime.count() << ", ";
	}
	cout << endl;

	delete[] gen1;
}*/




