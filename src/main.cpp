#include "main.h"
#include <set>
using namespace std;
using namespace demonic;

int main(int argc, char *argv[]) {
    string path = string_from_bash("echo $PATH");
    vector<string> path_vec = vector_from_string(path, ':');
    set<string> set_exec;

    for (const string &p : path_vec) {
        if (!p.empty()) {
            for (const string &exec : vector_from_string(string_from_bash("ls " + p), '\n')) {
                set_exec.insert(exec);
            }
        }
    }
    string search;

    if (!argv[1]) {
        for (const string &exec : set_exec) {
            if (!exec.empty()) {
                cout << exec << endl;
            }
        }
    } else {
        search = argv[1];
        for (const string &exec : set_exec) {
            if (!exec.empty() && string_in_string(search, exec))
                cout << string_highlight(exec, search, red, bold) << endl;
        }
    }
}



