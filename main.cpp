#include "matrix_operations.h"
#include <iostream>

int main() {
    std::cout << "Arm64 Matrix Operations Benchmark" << std::endl;
    std::cout << "=================================" << std::endl;

#if defined(__aarch64__)
    std::cout << "Running on aarch64 architecture with NEON-friendly optimizations" << std::endl;
#elif defined(__x86_64__) || defined(_M_X64)
    std::cout << "Running on x86-64 architecture with fallback optimizations" << std::endl;
#else
    std::cout << "Running on an unsupported architecture; using portable fallback" << std::endl;
#endif

    benchmark_matrix_ops();

    return 0;
}
