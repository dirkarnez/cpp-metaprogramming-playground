template <int N>
struct foo
{
    /*
    enum is a hack - do not use it unless you are using a ancient compiler
    https://stackoverflow.com/questions/899917/why-do-people-use-enums-in-c-as-constants-while-they-can-use-const
    */
    static const int Value = foo<N-1>::Value + N;
};

template <>
struct foo<0>
{
    static const int Value = 0;
};

int main() {
    static_assert(foo<10>::Value + 11 == foo<11>::Value, "");
    return foo<10>::Value;
}
