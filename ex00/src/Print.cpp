/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:16:02 by bkas              #+#    #+#             */
/*   Updated: 2024/08/03 17:26:40 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include "../inc/ScalarConverter.hpp"

/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] CHAR TYPE [v] *************************** */

void ScalarConverter::printChar(char c) {
    cout << "char: ";
    if (c <= 0 || c >= CHAR_MAX) {
        cout << "Impossible to print" << endl;
        return;
    }
    isprint(c) ? cout << "\"" << c << "\"" << endl
               : cout << "Not displayable" << endl;
}

/* *************************** [^] CHAR TYPE [^] *************************** */

/* **************************** [v] INT TYPE [v] **************************** */

void ScalarConverter::printInt(int i) {
    cout << "int: ";
    // const char *str = lit.c_str();
    // int num = atoi(str);
    if (i >= INT_MIN && i <= INT_MAX)
        cout << i << endl;
    else
        cout << "Impossible to Convert" << endl;
}

/* **************************** [^] INT TYPE [^] **************************** */
