#include <cstdlib>
#include <fstream>
#include <string>
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

    std::string line;
    uint64_t sum = 0; 
    char digits[3] = {}; // Two digit number + null terminator

    while (std::getline(infile, line)) {
        
        // Get first and last digit
        const auto first_idx = line.find_first_of("0123456789");
        const auto last_idx = line.find_last_of("0123456789");
        
        digits[0] = line[first_idx];
        digits[1] = line[last_idx];
        
        sum += std::atoi(digits);
    }
    
    std::println("Answer: {}", sum);
}
