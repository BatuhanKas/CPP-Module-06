/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:16:02 by bkas              #+#    #+#             */
/*   Updated: 2024/08/06 12:05:11 by bkas             ###   ########.fr       */
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
    if (type == SCIENCE || i <= 0 || i > CHAR_MAX) {
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

    double d = atof(lit.c_str());
    if (type != SCIENCE && (d >= INT_MIN && d <= INT_MAX))
        cout << i << endl;
    else
        cout << "impossible" << endl;
}

/* **************************** [^] INT TYPE [^] **************************** */

/* *************************** [v] FLOAT TYPE [v] *************************** */

void ScalarConverter::printFloat(eType type, float f, string lit) {
    cout << "float: ";

    double d = atof(lit.c_str());
    if (type != SCIENCE && d >= -DBL_MAX && d <= DBL_MAX)
        if (d >= INT_MIN && d <= INT_MAX) {
            cout << fixed << setprecision(1) << f << "f" << endl;
        } else {
            f = static_cast<float>(d);
            cout << fixed << setprecision(1) << f << "f" << endl;
        }
    else
        cout << "impossible" << endl;
}

/* *************************** [^] FLOAT TYPE [^] *************************** */

/* ************************** [v] DOUBLE TYPE [v] ************************** */

void ScalarConverter::printDouble(eType type, double d, string lit) {
    cout << "double: ";
    double dbl = atof(lit.c_str());
    if (type != SCIENCE && dbl >= -DBL_MAX && dbl <= DBL_MAX)
        if (dbl >= INT_MIN && dbl <= INT_MAX)
            cout << fixed << setprecision(1) << d << endl;
        else {
            d = static_cast<double>(dbl);
            cout << fixed << setprecision(1) << d << endl;
        }
    else
        cout << "impossible" << endl;
}

/* ************************** [^] DOUBLE TYPE [^] ************************** */
