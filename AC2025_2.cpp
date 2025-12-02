#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() { 
    ifstream file("input_2.txt");
    string s;
    vector<long int> start, finish;
    getline(file, s);

    int left_pointer{0}, right_pointer{0};
    while (right_pointer < s.length()) {
        string substring{};
        long int tmp;
        if (s[right_pointer] == '-') {
            substring = s.substr(left_pointer, right_pointer-left_pointer);
            tmp = stol(substring);
            start.push_back(tmp);
            left_pointer = right_pointer + 1;
        } else if (s[right_pointer] == ',') {
            substring = s.substr(left_pointer, right_pointer-left_pointer);
            tmp = stol(substring);
            finish.push_back(tmp);
            // cout << "finish " << tmp << '\n';
            left_pointer = right_pointer + 1;
        }

        right_pointer++;
    }
    // No comma at the end of the line
    finish.push_back(stoi(s.substr(left_pointer, right_pointer-left_pointer)));

    /*
    for_each(start.begin(), start.end(), [](long i) {
      	cout << i << " ";
    });
    cout << "\n\n";

    for_each(finish.begin(), finish.end(), [](long i) {
      	cout << i << " ";
    });
    */
    
    long total{0};
    for (int i{0}; i < start.size(); i++) {
        for (long j{start[i]}; j <= finish[i]; j++) {
            if (j < 10) {
                continue;
            }
            string num_as_string = to_string(j);
            string first_half = num_as_string.substr(0, num_as_string.length() / 2);
            string second_half = num_as_string.substr(num_as_string.length() / 2);
            if (first_half == second_half) {
                total += j;
            }
        }
    }

    std::cout << "total " << total << '\n';
    
    long new_total{0};
    
    for (int i{0}; i < start.size(); i++) {
        for (long j{start[i]}; j <= finish[i]; j++) {
            if (j < 10) {
                continue;
            }
            string num_as_string = to_string(j);
            int string_length = num_as_string.length();
            set<string> unique_str{};
            for (int k{2}; k <= string_length; k++) {
                if (string_length % k == 0) {
                    set<string> unique{};
                    for (int l{}; l < k; l++) {
                        unique.insert(num_as_string.substr(num_as_string.length() / k * l, num_as_string.length() / k));
                    }
                    if (unique.size() == 1 && unique_str.find(num_as_string) == unique_str.end()) {
                        unique_str.insert(num_as_string);
                        new_total += j;
                    }
                }
            }
        }
    }
    std::cout << "new total " << new_total << '\n';
    return 0;
}
