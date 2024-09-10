/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:25:16 by bkas              #+#    #+#             */
/*   Updated: 2024/09/10 19:12:36 by bkas             ###   ########.fr       */
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
        case PSEUDOLITERALS:
            castDouble(type, lit);
            break;
        default:
            cout << "Not printable or Convertable Value." << endl;
            break;
    }
}

/* *********************** [^] CONVERT FUNCTION [^] ************************ */
