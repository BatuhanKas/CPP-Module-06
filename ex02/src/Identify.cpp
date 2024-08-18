/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 02:30:59 by bkas              #+#    #+#             */
/*   Updated: 2024/08/18 21:42:45 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include "../inc/Identify.hpp"

/* **************************** [^] INCLUDES [^] **************************** */

/* *********************** [v] VIRTUAL DESTRUCTOR [v] *********************** */

Base::~Base() {}

/* *********************** [^] VIRTUAL DESTRUCTOR [^] *********************** */

static unsigned long getMs() { /*
    1 second = 1000 milisecond.
    1 microsecond = 0.001 milisecond.

    changing both of them miliseconds. */
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

Base* generate(void) {
    srand(getMs());

    int random = rand() % 3;

    switch (random) {
        case 0:
            return new A;
            break;
        case 1:
            return new B;
            break;
        case 2:
            return new C;
            break;
        default:
            cout << "Impossible." << endl;
            break;
    }
    return 0;
}

void identify(Base* p) {
    if (p) {
        int i = 0;
        string name = typeid(*p).name();
        while (isdigit(name[i])) i++;
        cout << &name[i] << endl;
    }
}

// void identify(Base& p) {
    
// }
