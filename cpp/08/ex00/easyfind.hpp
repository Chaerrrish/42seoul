#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <stdexcept>
# include <algorithm>

template<typename T>
typename T::const_iterator easyfind(const T& container, int val) {
    typename T::const_iterator iter = std::find(container.begin(), container.end(), val);
    if (iter == container.end())
        throw std::runtime_error("Element not found in container");
    return iter;
}

#endif
