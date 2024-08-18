/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 02:30:59 by bkas              #+#    #+#             */
/*   Updated: 2024/08/18 19:56:00 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include "../inc/Serializer.hpp"

/* **************************** [^] INCLUDES [^] **************************** */

/* *********************** [v] VIRTUAL DESTRUCTOR [v] *********************** */

Identify::~Identify() {}

/* *********************** [^] VIRTUAL DESTRUCTOR [^] *********************** */

Base *generate(void) {
    // time_t current_time = time(NULL);
    // srand(current_time);

    // int random = rand();
    // cout << random << endl;
}

unsigned long getMs() {
    /*
        1 second = 1000 milisecond.
        1 microsecond = 0.001 milisecond.

        changing both of them miliseconds.
    */
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}
