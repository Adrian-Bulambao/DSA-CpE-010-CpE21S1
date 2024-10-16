#include <iostream>
#include <cstdlib> //for generating random integers
#include <time.h> //will be used for our seeding function
#include <utility>
#include "sorting.h"

using namespace std;

const int max_size = 100;
int vote_count(int arr[], int size, int vote) {
 int count = 0;
 for (int i = 0; i<size; i++){
 	if(arr[i]==vote){
 		count++;
	 }
 }
 return count;
}

int main(int argc, char** argv) { 
    int dataset[max_size];
    int m = sizeof(dataset) / sizeof(dataset[0]);
    srand(time(0));
    for (int i = 0; i < max_size; i++) {
      dataset[i] = rand() % (5)+1;
    }
    
    //show your datasets content
    /*cout<<"Before sorting:"<<endl;
    for(int i = 0; i < max_size; i++){
    std::cout << dataset[i] << " ";
    }*/
    
    cout<<"The votes:"<<endl;
    for(int i = 0; i < max_size; i++){
    std::cout << dataset[i] << " ";
    }
    cout<<"\n";
    
    /*int m = sizeof(dataset) / sizeof(dataset[0]);
	bubbleSort(dataset, m);
	cout<<"\nAfter sorting:"<<endl;
	for(int i = 0; i < max_size; i++){
    std::cout << dataset[i] << " ";
    }*/
    
    /*cout<<"\nAfter selection sort:"<<endl;
    selectionSort(dataset,max_size);
    for(int i = 0; i < max_size; i++){
    std::cout << dataset[i] << " ";
    }*/
    
    cout<<"\nAfter sorting the votes:"<<endl;
    selectionSort(dataset,max_size);
    for(int i = 0; i < max_size; i++){
    std::cout << dataset[i] << " ";
    }
    cout<<"\n";

    /*cout<<"\nAfter selection sort:"<<endl;
    insertionSort(dataset,max_size);
    for(int i = 0; i < max_size; i++){
    std::cout << dataset[i] << " ";
    }*/
    
    int key = 1;
    int count1 = vote_count(dataset, m, key);
    cout << "\nNumber of votes for Bo Dalton Capistrano:" << count1 << std::endl;
    
    key = 2;
    int count2 = vote_count(dataset, m, key);
    cout << "\nNumber of votes for Cornelius Raymon Agustin:" << count2 << std::endl;
    
    key = 3;
    int count3 = vote_count(dataset, m, key);
    cout << "\nNumber of votes for Deja Jayla Bañaga:" << count3 << std::endl;
    
    key = 4;
    int count4 = vote_count(dataset, m, key);
    cout << "\nNumber of votes for Lalla Brielle Yabut:" << count4 << std::endl;
    
    key = 5;
    int count5 = vote_count(dataset, m, key);
    cout << "\nNumber of votes for Franklin Relano Castro:" << count5 << std::endl;
    
    
    
    
	return 0;
}


    
