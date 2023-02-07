#include <iostream>
#include <type_traits>

int main() {
   std::cout << std::boolalpha;

   std::cout << "std::remove_reference<int>::type is int? "
      << std::is_same<int, std::remove_reference<int>::type>::value << '\n';
   std::cout << "std::remove_reference<int&>::type is int? "
      << std::is_same<int, std::remove_reference<int&>::type>::value << '\n';
   std::cout << "std::remove_reference<int&&>::type is int? "
      << std::is_same<int, std::remove_reference<int&&>::type>::value << '\n';
   std::cout << "std::remove_reference<const int&>::type is const int? "
      << std::is_same<const int,
      std::remove_reference<const int&>::type>::value << '\n';

   class A {};
#   define REF(x) << #x " ?: " << x << '\n'
    std::cout << std::boolalpha
    REF( std::is_reference_v<A> )
    REF( std::is_reference_v<A&> )
    REF( std::is_reference_v<A&&> )
    REF( std::is_reference_v<long> )
    REF( std::is_reference_v<long&> )
    REF( std::is_reference_v<long&&> )
    REF( std::is_reference_v<double*> )
    REF( std::is_reference_v<double*&> )
    REF( std::is_reference_v<double*&&> );
#   undef REF
}
