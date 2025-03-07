#include<iostream>
using namespace std;

// class Solution {
// public:
//     bool checkPowersOfThree(int n) {
//         if(n==1){
//             return true;
//         }
//         int power = 0;
//         while(pow(3,power) <= n){
//             power++;
//         }

//         int index = power-1;
//         cout<<"index"<<index<<endl;
//         while(index>=0){
//             if(pow(3,index) <= n){
//                 n = n - pow(3,index);
//             }
//                 index--;
//         }

//         cout<<n<<endl;
//         return n==0;

//     }
// };

class Solution {
    public:
        bool checkPowersOfThree(int n) {
            while(n > 0) {
                if(n % 3 == 2) return false;
                n /= 3;
            }
            return true;
        }
    };