#include <fstream>
#include <string>
#include <iostream>
#include <vector>

int main() { 
    std::ifstream file("input_1.txt");
    std::string str; 
    std::vector<std::string> v{};
    while (std::getline(file, str))
    {
        v.push_back(str);
    }

    int initial_position{50};
    int res_a{0}, res_b{0};
    for (const std::string& s : v) {
        int multiplier{};
        int move{};
        int total_move{};
        bool flipped{};
        multiplier = (s[0] == 'L') ? -1 : 1;
        move = std::stoi(s.substr(1));
        total_move = (multiplier * move) % 100;
        res_b += move / 100;

        if (initial_position == 0 && multiplier == -1) {
            res_b--;
        }

        initial_position += total_move;
        
        flipped = false;
        if (initial_position > 99) {
            initial_position -= 100;
            res_b++;
            flipped = true;
        } else if (initial_position < 0) {
            initial_position += 100;
            res_b++;
            flipped = true;
        } 
        if (initial_position == 0) {
            res_a++;
            res_b += !flipped;
        }

        if (initial_position < 0 || initial_position > 99) {
            throw std::runtime_error("Position out of allowed range");
        }
    }
    std::cout << "Part A: " << res_a << '\n';
    std::cout << "Part B: " << res_b << '\n';
    

    return 0;
}