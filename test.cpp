/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:39:22 by bkas              #+#    #+#             */
/*   Updated: 2024/09/12 17:02:54 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>

// #include <cstdint>
// #include <iomanip>
#include <iostream>

using namespace std;

class Base {
   public:
    virtual ~Base(){};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

int main() {
    /* ***** [v] static cast [v] ***** */

    float f = 42.14;
    int x = static_cast<int>(f);
    cout << x << endl;

    char a = static_cast<char>(x);
    cout << a << endl;

    /* ***** [^] static cast [^] ***** */

    /** -------------------------------- **/

    /* ***** [v] dynamic cast [v] ***** */
    // Pointer Version

    Base *arr = new C;

    if (dynamic_cast<B *>(arr)) {
        cout << "b success" << endl;
    } else if (dynamic_cast<A *>(arr)) {
        cout << "a success" << endl;
    } else {
        cout << "cast failed " << endl;
    }

    // Reference Version
    try {
        B &b = dynamic_cast<B &>(*arr);
        cout << "b success reference" << endl;
    } catch (exception &e) {
        try {
            A &a = dynamic_cast<A &>(*arr);
            cout << "a success reference" << endl;
        } catch (exception &e) {
            cout << "cast failed ref " << e.what() << endl;
        }
    }

    /* ***** [^] dynamic cast [^] ***** */

    /** -------------------------------- **/

    /* ****** [v] const cast [v] ****** */

    int ahmet = 42;
    const int *ptr2 = &ahmet;

    cout << *ptr2 << endl;

    int *newptr = const_cast<int *>(ptr2);
    *newptr = 28;

    cout << *newptr << endl;

    /** const cast devami asd.cpp'de */

    /* ****** [^] const cast [^] ****** */

    /** -------------------------------- **/

    /* ******* [v] reinterpret cast [v] ******* */

    int l = 122;
    void *kl = reinterpret_cast<void *>(&l);
    int *y = reinterpret_cast<int *>(kl);
    char *ss = reinterpret_cast<char *>(y);
    cout << "ss; " << ss << endl;

    /* ******* [^] reinterpret cast [^] ******* */

    {
        char m;
        int a2 = 97;
        m = static_cast<char>(a2);
        cout << m << endl;
    }
}
