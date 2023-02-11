#include <iostream>
#include <vector>

#include <unistd.h>

#include "util/logger.h"

using namespace std;
using cmdline_args_t = vector<string>;

int main(int argc, char *argv[]) {
    cmdline_args_t args(&argv[0], &argv[argc]);

    if (argc > 1) {
        cout << "<pid>:<ppid>" << endl;

        return 0;
    }

    cout << getpid() << ":" << getppid() << endl;
}
