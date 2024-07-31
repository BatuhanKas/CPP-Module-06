/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:25:16 by bkas              #+#    #+#             */
/*   Updated: 2024/07/31 18:17:12 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include "../inc/ScalarConverter.hpp"

/* **************************** [^] INCLUDES [^] **************************** */

/* ************************* [v] ORTHODOX FORM [v] ************************* */

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &oth) { *this = oth; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &oth) {
    (void)oth;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

/* ************************* [^] ORTHODOX FORM [^] ************************* */

/* *************************** [v] FIND TYPE [v] *************************** */

bool ScalarConverter::isChar(const string &lit) {
    size_t i = 0;

    if (lit[0] == '+' || lit[0] == '-') {
        if (lit.length() == 1) return false;
        i = 1;
    }
    for (; i < lit.length(); i++) {
        if (!isdigit(lit[i])) return false;
    }
    return true;
}

bool ScalarConverter::isInt(const string &lit) {
    size_t i = 0;

    if (lit[0] == '+' || lit[0] == '-') {
        if (lit.length() == 1) return false;
        i = 1;
    }
    for (; i < lit.length(); i++)
        if (!isdigit(lit[i])) return false;
    return true;
}

/* *************************** [^] FIND TYPE [^] *************************** */

/* *************************** [v] PRINT TYPE [v] *************************** */

void ScalarConverter::printChar(const string lit) {
    cout << "char: ";
    const char *str = lit.c_str();
    int num = atoi(str);
    if (num < 0) {
        cout << "Impossible to print" << endl;
        return;
    }
    char x = static_cast<int>(num);
    if (x >= 32 && x <= 126)
        cout << "\"" << x << "\"" << endl;
    else if ((x >= 0 && x <= 31) || (x == 127))
        cout << "Not printable" << endl;
    else
        cout << "Impossible to print" << endl;
}

void ScalarConverter::printInt(const string lit) {
    cout << "int: ";
    const char *str = lit.c_str();
    int num = atoi(str);
    cout << num << endl;
}

/* *************************** [^] PRINT TYPE [^] *************************** */

/* ************************ [v] CONVERT FUNCTION [v] ************************ */

void ScalarConverter::convert(const string &lit) {
    // bool _char = isChar(lit);
    // bool _int = isInt(lit);

    try {
        if (isChar(lit)) printChar(lit);
        if (isInt(lit)) printInt(lit);
    } catch (exception &e) {
        cerr << e.what() << endl;
    }
}

/* ************************ [^] CONVERT FUNCTION [^] ************************ */
