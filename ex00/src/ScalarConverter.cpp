/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:25:16 by bkas              #+#    #+#             */
/*   Updated: 2024/07/31 14:18:20 by bkas             ###   ########.fr       */
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
    if (lit.length() == 3) {
        if ((lit[0] == '\'' && lit[2] == '\'') && (lit[1] != 32)) {
            return true;
        }
    }
    return false;
}

bool ScalarConverter::isInt(const string &lit) {
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

/* *************************** [^] FIND TYPE [^] *************************** */

/* ************************ [v] CONVERT FUNCTION [v] ************************ */

void ScalarConverter::convert(string lit) {
    cout << isChar(lit) << endl;
    cout << isInt(lit) << endl;
}

/* ************************ [^] CONVERT FUNCTION [^] ************************ */
