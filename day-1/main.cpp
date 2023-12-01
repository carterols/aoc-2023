#include <cstdlib>

#include <algorithm>
#include <array>
#include <fstream>
#include <string>
#include <string_view>
#include <print>

auto main(int argc, char** argv) -> int {
    if (argc < 2) {
        std::println(stderr, "Expected first argument to be input file");
        return 1; 
    }

    std::string file_name = argv[1];
    std::ifstream infile(file_name);
    
    if (!infile) {
        std::println(stderr, "Invalid file {}!", file_name);
        return 1;
    }

    // List of valid 'digit' words
    std::array<std::string_view, 9> valid_digits {
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"
    };

    constexpr int MAX_DIGIT_LENGTH = 5; // Maximum of 5 characters in 'one' - 'nine'

    std::string line;
    uint64_t sum = 0; 
    char digits[3] = {}; // Two digit number + null terminator

    while (std::getline(infile, line)) {
        // Get first digit
        for (size_t i = 0; i < line.size(); ++i) {
            auto c = line.at(i);
            if (c >= '0' && c <= '9') {
                digits[0] = c;
                break;
            }
            else {
                size_t found_pos = std::string::npos;
                std::string_view sub_word = line;
                sub_word = sub_word.substr(i, MAX_DIGIT_LENGTH);
                for (size_t j = 0; j < valid_digits.size(); ++j) {
                    std::string_view word = valid_digits[j];
                    if (sub_word.starts_with(word)) {
                        found_pos = j + 1;
                        break;
                    }
                }

                if (found_pos != std::string::npos) {
                    digits[0] = std::to_string(found_pos)[0];
                    break;
                }
            }
        }

        // Get the last digit
        for (size_t i = line.size() - 1; i >= 0; --i) {
            auto c = line.at(i);
            if (c >= '0' && c <= '9') {
                digits[1] = c;
                break;
            }
            else {
                size_t found_pos = std::string::npos;
                std::string_view sub_word = line;
                sub_word = sub_word.substr(i, MAX_DIGIT_LENGTH);
                for (size_t j = 0; j < valid_digits.size(); ++j) {
                    std::string_view word = valid_digits[j];
                    if (sub_word.starts_with(word)) {
                        found_pos = j + 1;
                        break;
                    }
                }

                if (found_pos != std::string::npos) {
                    digits[1] = std::to_string(found_pos)[0];
                    break;
                }
            }
        }

        sum += std::atoi(digits);
    }
    
    std::println("Answer: {}", sum);
}
