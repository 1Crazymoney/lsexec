#ifndef lsexec
#define lsexec

#include "../lib/demonic/demonic.h"
#include <iostream>
#include <algorithm>
std::vector<std::string> path_to_vec(std::string to_vec) {
    int pos = 0, len = 0;
    std::vector<std::string> vec;
    for (int i = 0; i < to_vec.length(); i++) {
        char c = to_vec[i];
        if (c == ':') {
            vec.push_back(to_vec.substr(pos, len));
            len = 0;
            pos = i + 1;
        } else if (i == to_vec.length() - 1) {
            int end = to_vec.length() - pos;
            vec.push_back(to_vec.substr(pos, end));
        } else {
            len++;
        }
    }
    return vec;
}
#endif //lsexec
