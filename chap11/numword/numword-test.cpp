// numword-test.cpp by Bill Weinman [bw.org]
// updated 2022-03-24
#include <format>
#include <iostream>

#include "numword.h"

namespace bw {
    template<typename... Args>
    constexpr void print(const std::string_view str_fmt, Args&&... args) {
        std::cout << std::vformat(str_fmt, std::make_format_args(args...));
    }
};

int main() {
    bw::numword nw{};
    uint64_t n{};

    bw::print("n is {}, {}\n", nw.getnum(), nw.words());

    nw = 3; bw::print("n is {}, {}\n", nw.getnum(), nw.words());
    nw = 47; bw::print("n is {}, {}\n", nw.getnum(), nw.words());
    nw = 73; bw::print("n is {}, {}\n", nw.getnum(), nw.words());
    nw = 1492; bw::print("n is {}, {}\n", nw.getnum(), nw.words());
    nw = 10012; bw::print("n is {}, {}\n", nw.getnum(), nw.words());
    
    n = 100073; bw::print("n is {}, {}\n", n, bw::numword{n}.words());
    n = 1000000; bw::print("n is {}, {}\n", n, bw::numword{n}.words());
    n = 1000000001; bw::print("n is {}, {}\n", n, bw::numword{n}.words());
    n = 123000000000; bw::print("n is {}, {}\n", n, bw::numword{n}.words());

    n = 474142398123; bw::print("n is {}, {}\n", n, nw(n));
    n = 1474142398007; bw::print("n is {}, {}\n", n, nw(n));
    n = 999000000000000; bw::print("n is {}, {}\n", n, nw(n));
    n = 999999999999999999; bw::print("n is {}, {}\n", n, nw(n));
    n = 1000000000000000000; bw::print("n is {}, {}\n", n, nw(n));
    
    return 0;
}
