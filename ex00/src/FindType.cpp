/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FindType.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:49:50 by bkas              #+#    #+#             */
/*   Updated: 2024/09/10 12:50:11 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include "../inc/ScalarConverter.hpp"

/* **************************** [^] INCLUDES [^] **************************** */

/* **************************** [v] IS CHAR [v] **************************** */

bool ScalarConverter::isChar(const string &lit) {
    return (lit.length() == 1 && isprint(lit[0]) && !isdigit(lit[0])) ? true
                                                                      : false;
}

/* **************************** [^] IS CHAR [^] **************************** */

/* ***************************** [v] IS INT [v] ***************************** */

bool ScalarConverter::isInt(const string &lit) {
    size_t i = 0;
    if (lit[0] == '+' || lit[0] == '-') i++;

    for (; i < lit.length(); i++)
        if (!isdigit(lit[i])) return false;
    return true;
}

/* ***************************** [^] IS INT [^] ***************************** */

/* **************************** [v] IS FLOAT [v] **************************** */

bool ScalarConverter::isFloat(const string &lit) {
    size_t i = 0;
    int num_c = 0;

    if (lit[0] == '+' || lit[0] == '-') i++;

    for (; i < lit.length(); i++) {
        if (!isdigit(lit[i]) && lit[i] == '.') {
            i++;
            while (isdigit(lit[i])) {
                i++;
                num_c++;
            }
            if (lit[i] == 'f' && lit[i + 1] == lit[lit.length()] && num_c != 0)
                return true;
        }
    }
    return false;
}

/* **************************** [^] IS FLOAT [^] **************************** */

/* *************************** [v] IS DOUBLE [v] *************************** */

bool ScalarConverter::isDouble(const string &lit) {
    size_t i = 0;
    int num_c = 0;

    if (lit[0] == '+' || lit[0] == '-') i++;

    for (; i < lit.length(); i++) {
        if (!isdigit(lit[i]) && lit[i] == '.') {
            i++;
            while (isdigit(lit[i])) {
                i++;
                num_c++;
            }
            if (lit[i] == lit[lit.length()] && num_c != 0) return true;
        }
    }
    return false;
}

/* *************************** [^] IS DOUBLE [^] *************************** */

/* *********************** [v] IS PSEUDO LITERALS [v] *********************** */

bool ScalarConverter::isPseudoLiterals(const string &lit) {
    string arr[] = {"-inf", "-inff", "+inf", "+inff", "inf",   "inff",
                    "nan",  "+nan",  "-nan", "+nanf", "-nanf", "nanf"};

    size_t arrSize = sizeof(arr) / sizeof(arr[0]);

    for (size_t i = 0; i < arrSize; i++)
        if (!lit.compare(arr[i])) return true;
    return false;
}

/* *********************** [^] IS PSEUDO LITERALS [^] *********************** */

/* *************************** [v] FIND TYPE [v] *************************** */

eType ScalarConverter::findType(const string lit) {
    if (isChar(lit))
        return CHAR;
    else if (isInt(lit))
        return INT;
    else if (isFloat(lit))
        return FLOAT;
    else if (isDouble(lit))
        return DOUBLE;
    else if (isPseudoLiterals(lit))
        return PSEUDOLITERALS;
    else
        return ERROR;
}

/* *************************** [^] FIND TYPE [^] *************************** */
