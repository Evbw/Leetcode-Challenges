#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int romanToInt(const string& s) {
    // Create a map to associate Roman numerals to their integer values
    unordered_map<char, int> roman_map = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int total = 0;
    int prev = 0;

    // Iterate through the string from right to left
    for (int i = s.length() - 1; i >= 0; i--) {
        int int_value = roman_map[s[i]];

        // We follow the Roman rules that if the value of the number is less than the previous
        // value, subtract it. Otherwise, we add it
        if (int_value < prev) {
            total -= int_value;
        } else {
            total += int_value;
            prev = int_value;
        }
    }

    return total;
}

int main() {
    // Test the function with examples
    string s1 = "III";
    string s2 = "LVIII";
    string s3 = "MCMXCIV";

    cout << "Roman numeral " << s1 << " equals " << romanToInt(s1) << endl;
    cout << "Roman numeral " << s2 << " equals " << romanToInt(s2) << endl;
    cout << "Roman numeral " << s3 << " equals " << romanToInt(s3) << endl;

    return 0;
}
