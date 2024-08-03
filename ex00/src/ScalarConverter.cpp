/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:25:16 by bkas              #+#    #+#             */
/*   Updated: 2024/08/03 18:38:46 by bkas             ###   ########.fr       */
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

bool ScalarConverter::isOneChar(const string &lit) {
    return (lit.length() == 1 && isprint(lit[0]) && !isdigit(lit[0])) ? true
                                                                      : false;
}

bool ScalarConverter::isChar(const string &lit) {
    size_t i = 0;

    if (lit[0] == '+' || lit[0] == '-') i++;

    for (; i < lit.length(); i++)
        if (!isdigit(lit[i])) return false;
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

/* *************************** [^] PRINT TYPE [^] *************************** */

/* ************************ [v] CASTING TO TYPES [v] ************************ */

void ScalarConverter::castChar(eType type, const string lit) {
    char c = 0;
    if (type == ONECHAR)
        c = static_cast<char>(lit[0]);
    else if (type == CHAR) {
        int x = atoi(lit.c_str());
        cout << "xvaL: " << x << endl;
        c = static_cast<char>(x);
        cout << "cvaL: " << c << endl;
    }
    int i = static_cast<int>(c);
    cout << "ivaL: " << i << endl;
    printChar(c);
    printInt(i);
}

/* ************************ [^] CASTING TO TYPES [^] ************************ */

/* ************************ [v] CONVERT FUNCTION [v] ************************ */

void ScalarConverter::convert(const string &lit) {
    eType type = ScalarConverter::findType(lit);

    switch (type) {
        case ONECHAR:
            castChar(type, lit);
            break;
        case CHAR:
            castChar(type, lit);
            break;
        // case INT:
        //     castInt(type, lit);
        //     break;
        default:
            break;
    }
}

/* ************************ [^] CONVERT FUNCTION [^] ************************ */

/* *********************** [v] PRINT ERROR CLASS [v] *********************** */

const char *ScalarConverter::PrintError::what() const throw() {
    return "Error: Not printable or Convertable Value.";
}

/* *********************** [^] PRINT ERROR CLASS [^] *********************** */
