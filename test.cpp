/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:39:22 by bkas              #+#    #+#             */
/*   Updated: 2024/08/18 18:13:40 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdint>
#include <iostream>

using namespace std;

template <typename T>
T* xor_ptrs(T* t1, T* t2) {
    return reinterpret_cast<T*>(reinterpret_cast<uintptr_t>(t1) ^
                                reinterpret_cast<uintptr_t>(t2));
}

int main(int argc, char const* argv[]) {
    int x = 9;
    int y = 10;

    // cout << &x << endl;
    int* xyz = &x;
    // uintptr_t val = reinterpret_cast<uintptr_t>(*xyz);
    uintptr_t val = (uintptr_t)x;
    cout << val << endl;
    int* a = reinterpret_cast<int*>(val);
    // cout << a << endl;
}
