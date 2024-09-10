/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asd.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:24:05 by bkas              #+#    #+#             */
/*   Updated: 2024/09/10 19:13:56 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>

// #include <cstdint>
// #include <iomanip>
#include <iostream>

class Base {
   private:
    const int _x;

   public:
    Base(int x) : _x(x){};
    virtual ~Base(){};
    void display() { cout << "xval: " << _x << endl; };
    void setx(int x) { const_cast<int &>(_x) = x; };
    int getx() { return _x; };
};

int main() {
    Base *b2 = new Base(15);
    b2->setx(20);
    b2->display();
}