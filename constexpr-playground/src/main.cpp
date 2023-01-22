constexpr int sq(int n)
{
  return n * n;
}

#include <iostream>

int main()
{
    //  mov     DWORD PTR [rbp-4], 3
    constexpr int N = 3;
    
    // mov     DWORD PTR [rbp-8], 9
    constexpr int N_SQ = sq(N);
    std::cout << N_SQ << std::endl;
    
    int number = 0;
    std::cin >> number;
    
    // sq is called like normally function
    std::cout << sq(number);
}
