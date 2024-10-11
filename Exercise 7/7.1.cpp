#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int linearSearch(int arr[], int size, int target){
	for(int i =0; i<size;i++){
		if (arr[i]==target){
		return i; //return the index if found
		}
	}
	return -1; // return -1 if not found
}

int main(int argc, char** argv) {
	int arr[] = {5,3,8,4,2};
	int size = sizeof(arr)/sizeof(arr[0]);
	int target;
	
	cout<<"Enter a number to search: ";
	cin>>target;
	
	
	int result = linearSearch(arr,size,target);
	if (result!=-1){
		cout<<"Element found at index:"<<result<<endl;
	}	
	else{
		cout<<"Element not found"<<endl;
	}
	return 0;
}
