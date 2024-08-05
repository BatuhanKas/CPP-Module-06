/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:16:02 by bkas              #+#    #+#             */
/*   Updated: 2024/08/05 18:14:26 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include "../inc/ScalarConverter.hpp"

/* **************************** [^] INCLUDES [^] **************************** */

/* ************************** [v] PRINT TYPES [v] ************************** */

void ScalarConverter::printTypes(eType type, char c, int i, float f, double d,
                                 string lit) {
    printChar(type, c, lit);
    printInt(type, i, lit);
    printFloat(type, f, lit);
    printDouble(type, d, lit);
}

/* ************************** [^] PRINT TYPES [^] ************************** */

/* *************************** [v] CHAR TYPE [v] *************************** */

void ScalarConverter::printChar(eType type, char c, string lit) {
    cout << "char: ";

    int i = atoi(lit.c_str());
    if (type == SPECIAL || i <= 0 || i > CHAR_MAX) {
        cout << "impossible" << endl;
        return;
    }
    isprint(c) ? cout << "\"" << c << "\"" << endl
               : cout << "Not displayable" << endl;
}

/* *************************** [^] CHAR TYPE [^] *************************** */

/* **************************** [v] INT TYPE [v] **************************** */

void ScalarConverter::printInt(eType type, int i, string lit) {
    cout << "int: ";

    float f = atof(lit.c_str());
    if (type != SPECIAL && f >= INT_MIN && f <= INT_MAX)
        cout << i << endl;
    else
        cout << "impossible" << endl;
}

/* **************************** [^] INT TYPE [^] **************************** */

/* *************************** [v] FLOAT TYPE [v] *************************** */

void ScalarConverter::printFloat(eType type, float f, string lit) {
    (void)type;
    (void)lit;
    cout << "float: ";

    double d = atoi(lit.c_str());
    if (d >= -FLT_MAX && d <= FLT_MAX && d >= FLT_MIN && d <= -FLT_MIN)
        cout << fixed << setprecision(1) << f << "f" << endl;
    else
        cout << "impossible" << endl;
}

/* *************************** [^] FLOAT TYPE [^] *************************** */

/* ************************** [v] DOUBLE TYPE [v] ************************** */

void ScalarConverter::printDouble(eType type, double d, string lit) {
    (void)type;
    (void)lit;
    cout << "double: ";
    cout << fixed << setprecision(1) << d << endl;
}

/* ************************** [^] DOUBLE TYPE [^] ************************** */
