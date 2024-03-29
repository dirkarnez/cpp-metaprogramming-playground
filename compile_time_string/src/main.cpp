#include <iostream>

namespace  variadic_toolbox
{
  template<unsigned  count,
    template<unsigned...> class  meta_functor, unsigned...  indices>
  struct  apply_range
  {
    typedef  typename apply_range<count - 1, meta_functor, count - 1, indices...>::result  result;
  };

  template<template<unsigned...> class  meta_functor, unsigned...  indices>
  struct  apply_range<0, meta_functor, indices...>
  {
    typedef  typename meta_functor<indices...>::result  result;
  };
}

namespace  compile_time
{
  template<char...  str>
  struct  string
  {
    static  constexpr  const char  chars[] = { str..., '\0' };
  };

  template<char...  str>
  constexpr  const char string<str...>::chars[];

  template<typename  lambda_str_type>
  struct  string_builder
  {
    template<unsigned... indices>
    struct  produce
    {
      typedef  string<lambda_str_type {}.chars[indices]...>  result;
    };
  };

  template<char...  str0, char...  str1>
  string<str0..., str1...>  operator+(string<str0...>, string<str1...>)
  {
    return {};
  }
}

#define  CSTRING(string_literal)                                                        \
    []{                                                                                 \
        struct  constexpr_string_type { const char * chars = string_literal; };         \
        return  variadic_toolbox::apply_range<sizeof(string_literal)-1,                 \
            compile_time::string_builder<constexpr_string_type>::produce>::result{};    \
    }()

int main()
{
  auto  str_hello = CSTRING("hello");
  auto  str_world = CSTRING(" world");

  const char* concat = (str_hello + str_world).chars;
  
  std::cout << "runtime concat: " << str_hello.chars << str_world.chars << "\n <=> \n";
  std::cout << "compile concat: " << concat << std::endl;
}
