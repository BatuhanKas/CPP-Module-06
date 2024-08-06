/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:22:35 by bkas              #+#    #+#             */
/*   Updated: 2024/08/06 11:22:12 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] DEFINES [v] **************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

/* **************************** [^] DEFINES [^] **************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include <limits.h>

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

/* ************************ [v] TYPE ENUMERATION [v] ************************ */

enum eType { CHAR, INT, FLOAT, DOUBLE, SCIENCE, ERROR };

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

    // lit means literal

    /* ********* [v] Find Type [v] ********* */
    static eType findType(const string lit);
    /* ********* [^] Find Type [^] ********* */

    /* ****** [v] Casting to Types [v] ****** */
    static void castChar(eType type, const string lit);
    static void castInt(eType type, const string lit);
    static void castFloat(eType type, const string lit);
    static void castDouble(eType type, const string lit);
    /* ****** [^] Casting to Types [^] ****** */

    /* ********* [v] Types [v] ********* */
    static bool isChar(const string &lit);
    static bool isInt(const string &lit);
    static bool isFloat(const string &lit);
    static bool isDouble(const string &lit);
    /* ********* [^] Types [^] ********* */

    /* ******** [v] Print Types [v] ******** */
    static void printTypes(eType type, char c, int i, float f, double d,
                           string lit);
    static void printChar(eType type, char c, string lit);
    static void printInt(eType type, int i, string lit);
    static void printFloat(eType type, float f, string lit);
    static void printDouble(eType type, double d, string lit);
    /* ******** [^] Print Types [^] ******** */

   public:
    /* **** [v] Convert Function [v] **** */
    static void convert(const string &lit);
    /* **** [^] Convert Function [^] **** */
};

/* ********************* [^] SCALAR CONVERTER CLASS [^] ********************* */

#endif
