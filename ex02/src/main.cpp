/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:29:12 by bkas              #+#    #+#             */
/*   Updated: 2024/09/09 16:06:40 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include "../inc/Identify.hpp"

/* **************************** [^] INCLUDES [^] **************************** */

/* ****************************** [v] MAIN [v] ****************************** */

int main() {
    /* ********** [v] DYNAMIC CAST [v] ********** */
    try {
        Base *b1 = generate();
        if (!b1) return 0;

        Base *b2 = generate();
        if (!b2) {
            delete b1;
            return 0;
        }

        Base *b3 = generate();
        if (!b3) {
            delete b1;
            delete b2;
            return 0;
        }

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
        cout << e.what() << endl;
    }
    /* ********** [^] DYNAMIC CAST [^] ********** */
}

/* ****************************** [^] MAIN [^] ****************************** */
