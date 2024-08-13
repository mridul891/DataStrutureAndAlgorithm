// given an array of integers fintd the elements which have an even number of digits

#include <iostream>
#include <vector>
using namespace std;
int main()
{

    vector<int> ans{12 ,3242,234234,523 ,45646546 ,5455 ,8};
    int size = ans.size();
    cout << "The size of the array is : "<<size <<endl;
    
    cout << "The ELements are " <<endl;
    for ( int i = 0 ; i < size ; i ++){
        int noofdigits = 0;
        int number = ans[i] ; 
        while ( number > 0 ){
            noofdigits++;
            number = number/10;
        }
        if ( noofdigits %2 == 0 ){
            cout << ans[i] <<endl ;
        }
    }
}