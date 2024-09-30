#include <iostream>
using namespace std;
int array [] = {5,4,3,2,1};
int count = 5;
int main(){
    int counter, i;
    for (i = 0; i < count/2; ++i) {
        counter = array[count-i-1];
        array[i] = counter;
        array[count-i-1] = array[i];
        
}
for (i = 0; i < count; ++i) {
    cout << array[i] << " ";
}
  return 0;
}

