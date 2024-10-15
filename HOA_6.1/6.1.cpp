#include <iostream>
#include <cstdlib> //for generating random integers
#include <time.h> //will be used for our seeding function
#include <utility>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

const int max_size = 50;


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


    return 0;
}
