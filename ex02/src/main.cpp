/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:29:12 by bkas              #+#    #+#             */
/*   Updated: 2024/09/13 10:52:56 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include "../inc/Identify.hpp"

/* **************************** [^] INCLUDES [^] **************************** */

/* ****************************** [v] MAIN [v] ****************************** */

int main() {
    /* ********** [v] DYNAMIC CAST [v] ********** */
    Base *b1 = 0;
    Base *b2 = 0;
    Base *b3 = 0;
    try {
        b1 = generate();
        b2 = generate();
        b3 = generate();

        identify(b1);
        identify(b2);
        identify(b3);

        identify(*b1);
        identify(*b2);
        identify(*b3);

        delete b1;
        delete b2;
        delete b3;
    } catch (exception &e) {
        if (b1) delete b1;
        if (b2) delete b2;
        if (b3) delete b3;
        cout << e.what() << endl;
    }
    /* ********** [^] DYNAMIC CAST [^] ********** */
}

/* ****************************** [^] MAIN [^] ****************************** */
