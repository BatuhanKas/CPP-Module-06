/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:16:02 by bkas              #+#    #+#             */
/*   Updated: 2024/08/05 15:37:06 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include "../inc/ScalarConverter.hpp"

/* **************************** [^] INCLUDES [^] **************************** */

/* ************************** [v] PRINT TYPES [v] ************************** */

void ScalarConverter::printTypes(eType type, char c, int i, float f, double d) {
    (void)d;
    printChar(type, c);
    printInt(type, i);
    printFloat(type, f);
    printDouble(type, d);
}

/* ************************** [^] PRINT TYPES [^] ************************** */

/* *************************** [v] CHAR TYPE [v] *************************** */

void ScalarConverter::printChar(eType type, char c) {
    cout << "char: ";
    if (type == SPECIAL || c <= 0 || c > CHAR_MAX) {
        cout << "Impossible to print" << endl;
        return;
    }
    isprint(c) ? cout << "\"" << c << "\"" << endl
               : cout << "Not displayable" << endl;
}

/* *************************** [^] CHAR TYPE [^] *************************** */

/* **************************** [v] INT TYPE [v] **************************** */

void ScalarConverter::printInt(eType type, int i) {
    cout << "int: ";
    if (type != SPECIAL && i >= INT_MIN && i <= INT_MAX)
        cout << i << endl;
    else
        cout << "Impossible to Convert" << endl;
}

/* **************************** [^] INT TYPE [^] **************************** */

/* *************************** [v] FLOAT TYPE [v] *************************** */

void ScalarConverter::printFloat(eType type, float f) {
    (void)type;
    cout << "float: ";
    cout << fixed << setprecision(1) << f << "f" << endl;
}

/* *************************** [^] FLOAT TYPE [^] *************************** */

/* ************************** [v] DOUBLE TYPE [v] ************************** */

void ScalarConverter::printDouble(eType type, double d) {
    (void)type;
    cout << "double: ";
    cout << fixed << setprecision(1) << d << endl;
}

/* ************************** [^] DOUBLE TYPE [^] ************************** */
