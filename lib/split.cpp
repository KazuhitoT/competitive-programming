#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

std::vector<std::string> split(const std::string& str, char delim = ','){
    std::istringstream iss(str);
    std::string tmp;
    std::vector<std::string> res;
    while (getline(iss, tmp, delim)) res.push_back(tmp);
    return res;
}

int main() {
    auto vs = split("a,,b,,c", ",,");
    for(auto s: vs) {
        std::cout << s << std::endl;
    }

    return 0;
}