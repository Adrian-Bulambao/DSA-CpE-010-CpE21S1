#include <iostream>
#include <cstdlib> //for generating random integers
#include <time.h> //will be used for our seeding function
#include <utility>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

const int max_size = 50;

void linearSearch(int data[], int n, int item) {
    // Step 1: Initialize index to 0
    int i = 0;

    // Step 2: Repeat while i <= n
    while (i <= n) {
        // Check if the current element matches the item
        if (item == data[i]) {
            cout << "Searching is successful. Item found at index: " << i << endl;
            return; // Exit the function if found
        }
        i++; // Increment index to continue searching
    }

    // If we reach here, it means the item was not found
    cout << "Searching is unsuccessful." << endl;
}

int main(int argc, char** argv) {
    //generate random values
    int dataset[max_size];
    srand(time(0));
    for(int i = 0; i < max_size; i++){
    dataset[i] = rand();
    }
    //show your datasets content
    for(int i = 0; i < max_size; i++){
    std::cout << dataset[i] << " ";
    }

    int n = max_size;

    // Item to search for
    int item;
    cout<<" "<<endl;
    cout << "Enter the number to search: ";
    cin >> item;

    // Call the linearSearch function
    linearSearch(dataset, n, item);

    return 0;
}
