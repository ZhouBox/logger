#include <iostream>
#include <type_traits>

namespace zz {

template <typename T>
void unpack(T&& t)
{
    std::cout << std::forward<T>(t) << ' ';
}

template <typename ... Args>
void debugLogImpl(Args&& ... args)
{
    int dummy[] = {0, (unpack(std::forward<Args>(args)), 0)...};
    std::cout << '\n';
}

template <typename ... Args>
void debugLog(Args&& ... args)
{
    debugLogImpl(std::forward<Args>(args)...);
}

}


#define DEBUG_LOG(...) zz::debugLog(__VA_ARGS__)
