#include <iostream>
#include <stdint.h>

#define PRINT(x) std::cout << x << std::endl;

union U32Word
{
    uint32_t as_uint32;
    uint16_t low;
    uint16_t high;
};

int foo(float* f, int* i) {
    *i = 1;
    *f = 0.0f;
    return *i;
}


uint32_t swap_words(uint32_t arg)
{
    U32Word word;
    uint16_t low;
    uint16_t high;
    word.as_uint32 = arg;
    high = word.high;
    low = word.low;
    word.low = high;
    word.high = low;
    return word.as_uint32;
}


int main()
{
    float some_number = 5.5f;

    PRINT(some_number);

    int some_number_int = static_cast<int>(some_number);

    PRINT(some_number_int);



    int x = 0;
    std::cout << x << "\n";
    x = foo(reinterpret_cast<float*>(&x), &x);
    std::cout << x << "\n";


    std::cin;


}