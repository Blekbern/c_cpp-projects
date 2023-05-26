#include <iostream>
#include <vector>
using namespace std;

class CNumbers {
    public:
        int m_Num;
        int m_Cnt = 0;
        CNumbers( int num ) {
            m_Num = num;
            m_Cnt = 1;
        }
    void addNum( int num );
};

void CNumbers::addNum( int num ) {
    m_Num = num;
    m_Cnt++;
}

int findOdd( vector <int> arr ) {
    int odd;
    vector <CNumbers> nums;
    CNumbers temp( arr[0] );
    nums.push_back( temp );
    for( uint i = 1; i < arr.size(); i++ ) {
        for( uint j = 0; j < nums.size(); j++ ) {
            if( arr[i] == nums[j].m_Num ) {
                nums[j].m_Cnt++;
                if( (nums[j].m_Cnt % 2) - 1 == 0 ) {
                    odd = nums[j].m_Num;
                }
            } else {
                nums[j].addNum( arr[i] );
            }
        }
    }
    return odd;
}


int main( void ) {
    cout << findOdd( {20,1,-1,2,-2,3,3,5,5,1,2,4,20,4,-1,-2,5} ) << endl;   // 5
    cout << findOdd( {1,1,2,-2,5,2,4,4,-1,-2,5} ) << endl;                  // -1
    cout << findOdd( {20,1,1,2,2,3,3,5,5,4,20,4,5} ) << endl;               // 5
    cout << findOdd( {10} ) << endl;                                        // 10
    cout << findOdd( {1,1,1,1,1,1,10,1,1,1,1} ) << endl;                    // 10
    cout << findOdd( {5,4,3,2,1,5,4,3,2,10,10} ) << endl;                   // 1



    return 0;
}