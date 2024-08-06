/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:25:16 by bkas              #+#    #+#             */
/*   Updated: 2024/08/06 11:22:05 by bkas             ###   ########.fr       */
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
    return true;
}

bool ScalarConverter::isFloat(const string &lit) {
    size_t i = 0;

    if (lit[0] == '+' || lit[0] == '-') i++;

    for (; i < lit.length(); i++) {
        if (!isdigit(lit[i]) && lit[i] == '.') {
            i++;
            while (isdigit(lit[i])) i++;
            if (lit[i] == 'f' && lit[i + 1] == lit[lit.length()]) return true;
        }
    }
    return false;
}

bool ScalarConverter::isDouble(const string &lit) {
    size_t i = 0;

    if (lit[0] == '+' || lit[0] == '-') i++;

    for (; i < lit.length(); i++) {
        if (!isdigit(lit[i]) && lit[i] == '.') {
            i++;
            while (isdigit(lit[i])) i++;
            if (lit[i] == lit[lit.length()]) return true;
        }
    }
    return false;
}

/* *************************** [^] FIND TYPE [^] *************************** */

/* *********************** [v] CASTING TO TYPES [v] ************************ */

void ScalarConverter::castChar(eType type, const string lit) {
    char c = static_cast<char>(lit[0]);
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);
    ScalarConverter::printTypes(type, c, i, f, d, lit);
}

void ScalarConverter::castInt(eType type, const string lit) {
    int i = atoi(lit.c_str());
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);
    ScalarConverter::printTypes(type, c, i, f, d, lit);
}

void ScalarConverter::castFloat(eType type, const string lit) {
    float f = atof(lit.c_str());
    char c = static_cast<char>(f);
    int i = static_cast<int>(f);
    double d = static_cast<double>(f);
    ScalarConverter::printTypes(type, c, i, f, d, lit);
}

void ScalarConverter::castDouble(eType type, const string lit) {
    double d = atof(lit.c_str());
    char c = static_cast<char>(d);
    int i = static_cast<int>(d);
    float f = static_cast<float>(d);
    ScalarConverter::printTypes(type, c, i, f, d, lit);
}

/* *********************** [^] CASTING TO TYPES [^] ************************ */

/* *********************** [v] CONVERT FUNCTION [v] ************************ */

void ScalarConverter::convert(const string &lit) {
    eType type = ScalarConverter::findType(lit);

    switch (type) {
        case CHAR:
            castChar(type, lit);
            break;
        case INT:
            castInt(type, lit);
            break;
        case FLOAT:
            castFloat(type, lit);
            break;
        case DOUBLE:
            castDouble(type, lit);
            break;
        default:
            cout << "Not printable or Convertable Value." << endl;
            break;
    }
}

/* *********************** [^] CONVERT FUNCTION [^] ************************ */
