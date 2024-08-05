/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:25:16 by bkas              #+#    #+#             */
/*   Updated: 2024/08/05 15:38:57 by bkas             ###   ########.fr       */
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
    return (lit.length() == 1 && isprint(lit[0]) && !isdigit(lit[0])) ? true
                                                                      : false;
}

bool ScalarConverter::isInt(const string &lit) {
    size_t i = 0;

    if (lit[0] == '+' || lit[0] == '-') i++;

    for (; i < lit.length(); i++)
        if (!isdigit(lit[i])) return false;

    double d = atoll(lit.c_str());
    return d < INT_MIN || d > INT_MAX ? false : true;
}

/* *************************** [^] FIND TYPE [^] *************************** */

/* ************************ [v] CASTING TO TYPES [v] ************************ */

void ScalarConverter::castChar(eType type, const string lit) {
    char c = static_cast<char>(lit[0]);
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);
    ScalarConverter::printTypes(type, c, i, f, d);
}

void ScalarConverter::castInt(eType type, const string lit) {
    char c = -1;
    int i = atoi(lit.c_str());
    if (i >= 0 && i <= CHAR_MAX) {
        c = static_cast<char>(i);
    }
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);
    ScalarConverter::printTypes(type, c, i, f, d);
}

/* ************************ [^] CASTING TO TYPES [^] ************************ */

/* ************************ [v] CONVERT FUNCTION [v] ************************ */

void ScalarConverter::convert(const string &lit) {
    eType type = ScalarConverter::findType(lit);

    switch (type) {
        case CHAR:
            castChar(type, lit);
            break;
        case INT:
            castInt(type, lit);
            break;
        default:
            cout << "Not printable or Convertable Value." << endl;
            break;
    }
}

/* ************************ [^] CONVERT FUNCTION [^] ************************ */

/* *********************** [v] PRINT ERROR CLASS [v] *********************** */

const char *ScalarConverter::PrintError::what() const throw() {
    return "Error: Not printable or Convertable Value.";
}

/* *********************** [^] PRINT ERROR CLASS [^] *********************** */
