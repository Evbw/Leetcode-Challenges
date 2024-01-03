#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        // Create a reversed version of the number
        int reversed_x = 0;
        int original_x = x;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;

            // Check for overflow/underflow
            if (reversed_x > INT_MAX/10 || (reversed_x == INT_MAX / 10 && pop > 7)) return false;
            if (reversed_x < INT_MIN/10 || (reversed_x == INT_MIN / 10 && pop < -8)) return false;

            reversed_x = reversed_x * 10 + pop;
        }

        // Check if the original and reversed numbers are the same
        return original_x == reversed_x;
    }
};

int reverseInt(int x) {
    int reversed = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;

        reversed = reversed * 10 + pop;
    }
    return reversed;
}

int main() {
    Solution answer;
    int input;
    cout<<"Enter a number to see if it's a palindrome: ";
    cin>>input;

    if (input < 0) {
        cout<<"False"<<endl;
        cout<<"From left to right, it reads "<<input<<". ";
        input = input * -1;
        cout<<"From right to left, it becomes "<<reverseInt(input)<<"-. Therefore it is not a palindrome."<<endl;
    }
    else if (answer.isPalindrome(input)) {
        cout<<"True"<<endl;
        cout<<input<<" reads as "<<input<<" from left to right and from right to left."<<endl;
    }
    else {
        cout<<"False"<<endl;
        cout<<"From left to right, it reads "<<input<<". ";
        cout<<"From right to left, it becomes "<<reverseInt(input)<<". Therefore it is not a palindrome."<<endl;
    }

    return 0;
}