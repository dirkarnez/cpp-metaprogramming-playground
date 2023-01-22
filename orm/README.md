orm
===

### Reference
- [Enum to String and Vice Versa in C++ - CodeProject](https://www.codeproject.com/Articles/42035/Enum-to-String-and-Vice-Versa-in-C)

### Sketches
```
// C++ program to demonstrate the use of class templates

#include <iostream>
using namespace std;

#include <iostream>
#include <tuple>
#include <functional>

//  CREATE TABLE Persons (
//     PersonID int,a
//     LastName varchar(255),
//     FirstName varchar(255),
//     Address varchar(255),
//     City varchar(255)
// );
int main()
{

    int a= 112;
    int* aptr= &a;
    string b;

    auto t = std::make_tuple(aptr, b);
    std::cout << "The value of t is "  << "("
              << *std::get<0>(t) << ", " << std::get<1>(t) << ")\n";

    int a2 = 2;
    int*  aptr2= &a2;
    t = std::make_tuple(aptr2, "435");
     std::cout << "The value of t is "  << "("
              << *std::get<0>(t) << ", " << std::get<1>(t) << ")\n";
}

// template <int N>
// struct Factorial 
// {
//     enum { value = N * Factorial<N - 1>::value };
// };

// template <>
// struct Factorial<0> 
// {
//     enum { value = 1 };
// };
```
### Reference
- [orm - Issue with rowset of boost tuples with SOCI c++ database access library - Stack Overflow](https://stackoverflow.com/questions/9064898/issue-with-rowset-of-boost-tuples-with-soci-c-database-access-library)
- [Wt::Dbo: a C++ ORM (Object Relational Mapping) library - YouTube](https://www.youtube.com/watch?v=gmFdAISBzmk)
- [c++ - 如何设计一个简单的C++ ORM_个人文章 - SegmentFault 思否](https://segmentfault.com/a/1190000007664316)
- [深入分析虚幻源码——TTuple - 知乎](https://zhuanlan.zhihu.com/p/250149211)
- [paulftw/hiberlite: C++ ORM for SQLite](https://github.com/paulftw/hiberlite)
- [如何设计一个简单的 C++ ORM | BOT Man JL](https://bot-man-jl.github.io/articles/?post=2016/How-to-Design-a-Naive-Cpp-ORM)
- [LiteSQL C++ Object Persistence Framework download | SourceForge.net](https://sourceforge.net/projects/litesql/)
- [如何设计一个更好的C++ ORM - BOT-Man - 博客园](https://www.cnblogs.com/BOT-Man/p/6127003.html)
- [BOT-Man-JL/ORM-Lite: Header-Only, Strong-Typed, Compile-time Object Relation Mapping (ORM) in Modern C++ :-)](https://github.com/BOT-Man-JL/ORM-Lite)
