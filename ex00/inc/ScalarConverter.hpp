/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:22:35 by bkas              #+#    #+#             */
/*   Updated: 2024/09/12 18:18:20 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] DEFINES [v] **************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

/* **************************** [^] DEFINES [^] **************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include <limits.h>
#include <stdlib.h>

#include <cfloat>
#include <iomanip>
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::fixed;
using std::setprecision;
using std::string;

/* **************************** [^] INCLUDES [^] **************************** */

/* **************************** [v] DEFINES [v] **************************** */

#define CHARRANGE(c) ((c < 0 || c > CHAR_MAX) ? 1 : 0)
#define INTRANGE(i) ((i >= INT_MIN && i <= INT_MAX) ? 1 : 0)
#define FLTRANGE(f) ((f >= -FLT_MAX && f <= FLT_MAX) ? 1 : 0)
#define DBLRANGE(d) ((d >= -DBL_MAX && d <= DBL_MAX) ? 1 : 0)

/* **************************** [^] DEFINES [^] **************************** */

/* ************************ [v] TYPE ENUMERATION [v] ************************ */

enum eType { CHAR, INT, FLOAT, DOUBLE, PSEUDOLITERALS, ERROR };

/* ************************ [^] TYPE ENUMERATION [^] ************************ */

/* ********************* [v] SCALAR CONVERTER CLASS [v] ********************* */

class ScalarConverter {
   private:
    /* ************* [v] Orthodox Form [v] ************* */
    ScalarConverter();
    ScalarConverter(const ScalarConverter &oth);
    ScalarConverter &operator=(const ScalarConverter &oth);
    ~ScalarConverter();
    /* ************* [^] Orthodox Form [^] ************* */

    /* *************** [v] Find Type Function [v] *************** */
    static eType findType(const string lit);
    /* *************** [^] Find Type Function [^] *************** */

    /* ***************** [v] Finding Types [v] ***************** */
    static bool isChar(const string &lit);
    static bool isInt(const string &lit);
    static bool isFloat(const string &lit);
    static bool isDouble(const string &lit);
    static bool isPseudoLiterals(const string &lit);
    /* ***************** [^] Finding Types [^] ***************** */

    /* ************ [v] Casting to Types [v] ************ */
    static void castChar(eType type, const string lit);
    static void castInt(eType type, const string lit);
    static void castFloat(eType type, const string lit);
    static void castDouble(eType type, const string lit);
    /* ************ [^] Casting to Types [^] ************ */

    /* ********************* [v] Print Types [v] ********************* */
    static void printTypes(eType type, char c, int i, float f, double d,
                           string lit);
    static void printChar(eType type, char c, string lit);
    static void printInt(eType type, int i, string lit);
    static void printFloat(eType type, float f, string lit);
    static void printDouble(eType type, double d, string lit);
    static void printPseudoLiterals(eType type, string lit);
    /* ********************* [^] Print Types [^] ********************* */

   public:
    /* ************* [v] Convert Function [v] ************* */
    static void convert(const string &lit);
    /* ************* [^] Convert Function [^] ************* */
};

/* ********************* [^] SCALAR CONVERTER CLASS [^] ********************* */

#endif
