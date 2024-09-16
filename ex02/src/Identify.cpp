/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 02:30:59 by bkas              #+#    #+#             */
/*   Updated: 2024/09/16 10:11:18 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include "../inc/Identify.hpp"

/* **************************** [^] INCLUDES [^] **************************** */

/* *********************** [v] VIRTUAL DESTRUCTOR [v] *********************** */

Base::~Base() {}

/* *********************** [^] VIRTUAL DESTRUCTOR [^] *********************** */

/* ************************* [v] GET MILISECOND [v] ************************* */

static unsigned long getMs() { /*
    1 second = 1000 milisecond.
    1 microsecond = 0.001 milisecond.

    changing both of them miliseconds. */
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

/* ************************* [^] GET MILISECOND [^] ************************* */

/* **************************** [v] GENERATE [v] **************************** */

Base* generate(void) {
    system("sleep 0.025");
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

/* **************************** [^] GENERATE [^] **************************** */

/* ************************** [v] IDENTIFY PTR [v] ************************** */

void identify(Base* p) {
    if (castToDynamic(p, A))
        cout << "Pointer: Object Type is: A" << endl;
    else if (castToDynamic(p, B))
        cout << "Pointer: Object Type is: B" << endl;
    else if (castToDynamic(p, C))
        cout << "Pointer: Object Type is: C" << endl;
    else
        cout << "Wrong Object Type!" << endl;
}

/* ************************** [^] IDENTIFY PTR [^] ************************** */

/* *********************** [v] IDENTIFY REFERENCE [v] *********************** */

void identify(Base& p) {
    try {
        A& a = dynamicRef(p, A);
        (void)a;
        cout << "Ref: Object Type is: A" << endl;
    } catch (exception& e) {
        try {
            B& b = dynamicRef(p, B);
            (void)b;
            cout << "Ref: Object Type is: B" << endl;
        } catch (exception& e) {
            try {
                C& c = dynamicRef(p, C);
                (void)c;
                cout << "Ref: Object Type is: C" << endl;
            } catch (exception& e) {
                cout << "Wrong Object Type!" << endl;
            }
        }
    }
}

/* *********************** [^] IDENTIFY REFERENCE [^] *********************** */
