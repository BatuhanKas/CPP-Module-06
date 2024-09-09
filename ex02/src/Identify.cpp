/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 02:30:59 by bkas              #+#    #+#             */
/*   Updated: 2024/09/09 16:18:49 by bkas             ###   ########.fr       */
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
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

Base* generate(void) {
    system("sleep 0.2");
    srand(getMs());

    int random = rand() % 3;

    switch (random) {
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
        default:
            cout << "Impossible." << endl;
            return NULL;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        cout << "Pointer: Object Type is: A" << endl;
    else if (dynamic_cast<B*>(p))
        cout << "Pointer: Object Type is: B" << endl;
    else if (dynamic_cast<C*>(p))
        cout << "Pointer: Object Type is: C" << endl;
    else
        cout << "Wrong Object Type!" << endl;
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        cout << "Ref: Object Type is: A" << endl;
    } catch (exception& e) {
        try {
            B& b = dynamic_cast<B&>(p);
            (void)b;
            cout << "Ref: Object Type is: B" << endl;
        } catch (exception& e) {
            try {
                C& c = dynamic_cast<C&>(p);
                (void)c;
                cout << "Ref: Object Type is: C" << endl;
            } catch (exception& e) {
                cout << "Wrong Object Type!" << endl;
            }
        }
    }
}
