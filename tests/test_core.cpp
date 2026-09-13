#include "ethash-light/work.h"

#include <cstdlib>
#include <iostream>

#define CHECK(cond)                                                          \
    do {                                                                     \
        if (!(cond)) {                                                       \
            std::cerr << "fail: " #cond " (" << __FILE__ << ":" << __LINE__  \
                      << ")\n";                                              \
            return 1;                                                        \
        }                                                                    \
    } while (0)

int main() {
    auto a = ethashlt::make_job("pool");
    auto b = ethashlt::make_job("pool");
    CHECK(a.id == b.id);
    CHECK(ethashlt::hash_nonce(a, 1) != ethashlt::hash_nonce(a, 2));
    CHECK(ethashlt::bench(8) == 8);
    CHECK(ethashlt::algo() != nullptr);
    std::cout << "ok\n";
    return 0;
}
