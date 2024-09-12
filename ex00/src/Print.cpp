/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:16:02 by bkas              #+#    #+#             */
/*   Updated: 2024/09/12 18:18:34 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include "../inc/ScalarConverter.hpp"

/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] CHAR TYPE [v] *************************** */

void ScalarConverter::printChar(eType type, char c, string lit) {
    cout << "char: ";

    int i = atoi(lit.c_str());
    if (type == PSEUDOLITERALS || CHARRANGE(i)) {
        cout << "impossible" << endl;
        return;
    }
    isprint(c) ? cout << "\'" << c << "\'" << endl
               : cout << "Not displayable" << endl;
}

/* *************************** [^] CHAR TYPE [^] *************************** */

/* **************************** [v] INT TYPE [v] **************************** */

void ScalarConverter::printInt(eType type, int i, string lit) {
    cout << "int: ";

    double d = atof(lit.c_str());
    if (type != PSEUDOLITERALS && INTRANGE(d))
        cout << i << endl;
    else
        cout << "impossible" << endl;
}

/* **************************** [^] INT TYPE [^] **************************** */

/* *************************** [v] FLOAT TYPE [v] *************************** */

void ScalarConverter::printFloat(eType type, float f, string lit) {
    cout << "float: ";

    if (type == PSEUDOLITERALS) {
        printPseudoLiterals(FLOAT, lit);
        return;
    }

    double d = atof(lit.c_str());
    if (type != PSEUDOLITERALS && FLTRANGE(d))
        if (INTRANGE(d)) {
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

    if (type == PSEUDOLITERALS) {
        printPseudoLiterals(DOUBLE, lit);
        return;
    }

    double dbl = atof(lit.c_str());
    if (type != PSEUDOLITERALS && DBLRANGE(dbl))
        if (INTRANGE(dbl))
            cout << fixed << setprecision(1) << d << endl;
        else {
            d = static_cast<double>(dbl);
            cout << fixed << setprecision(1) << d << endl;
        }
    else
        cout << "impossible" << endl;
}

/* ************************** [^] DOUBLE TYPE [^] ************************** */

/* ************************ [v] PSEUDO LITERALS [v] ************************ */

void ScalarConverter::printPseudoLiterals(eType type, string lit) {
    if (!lit.compare("inf") || !lit.compare("inff")) {
        cout << "inf";
        if (type == FLOAT) cout << "f";
        cout << endl;
    } else if (!lit.compare("+inf") || !lit.compare("+inff")) {
        cout << "+inf";
        if (type == FLOAT) cout << "f";
        cout << endl;
    } else if (!lit.compare("-inf") || !lit.compare("-inff")) {
        cout << "-inf";
        if (type == FLOAT) cout << "f";
        cout << endl;
    } else if (!lit.compare("nan") || !lit.compare("nanf")) {
        cout << "nan";
        if (type == FLOAT) cout << "f";
        cout << endl;
    } else if (!lit.compare("+nan") || !lit.compare("+nanf")) {
        cout << "+nan";
        if (type == FLOAT) cout << "f";
        cout << endl;
    } else if (!lit.compare("-nan") || !lit.compare("-nanf")) {
        cout << "-nan";
        if (type == FLOAT) cout << "f";
        cout << endl;
    }
}

/* ************************ [^] PSEUDO LITERALS [^] ************************ */

/* ************************** [v] PRINT TYPES [v] ************************** */

void ScalarConverter::printTypes(eType type, char c, int i, float f, double d,
                                 string lit) {
    printChar(type, c, lit);
    printInt(type, i, lit);
    printFloat(type, f, lit);
    printDouble(type, d, lit);
}

/* ************************** [^] PRINT TYPES [^] ************************** */
