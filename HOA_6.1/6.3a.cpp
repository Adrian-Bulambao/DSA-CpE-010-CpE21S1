#include <iostream>
#include <cstdlib> //for generating random integers
#include <time.h> //will be used for our seeding function
#include <utility>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
void binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;	
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            cout << "Searching is successful at position " << mid << "." << endl;
            return;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << "Searching is unsuccessful." << endl;
    return;
}


int main(int argc, char** argv) {
    //generate random values
    int data[] = {3, 5, 7, 9, 11, 13};
    int m = sizeof(data) / sizeof(data[0]);
    int item_f;

    for(int i = 0; i < m; i++){
        std::cout << data[i] << " ";
    }

    cout << "\nEnter a number to search: ";
    cin >> item_f;
    binarySearch(data,m,item_f);


    return 0;
}
