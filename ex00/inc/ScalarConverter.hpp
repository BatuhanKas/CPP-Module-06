/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:22:35 by bkas              #+#    #+#             */
/*   Updated: 2024/08/05 11:28:08 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] DEFINES [v] **************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

/* **************************** [^] DEFINES [^] **************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include <limits.h>

#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::string;

/* **************************** [^] INCLUDES [^] **************************** */

/* ************************ [v] TYPE ENUMERATION [v] ************************ */

enum eType { CHAR, INT, FLOAT, DOUBLE, SPECIAL, ERROR };

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
    /* ****** [^] Casting to Types [^] ****** */

    /* ********* [v] Types [v] ********* */
    static bool isChar(const string &lit);
    static bool isInt(const string &lit);
    /* ********* [^] Types [^] ********* */

    /* ******** [v] Print Types [v] ******** */
    static void printTypes(eType type, char c, int i, float f, double d);
    static void printChar(eType type, char c);
    static void printInt(eType type, int i);
    /* ******** [^] Print Types [^] ******** */

    /* ******* [v] Error Class [v] ******* */
    class PrintError : public exception {
       public:
        virtual const char *what() const throw();
    };
    /* ******* [^] Error Class [^] ******* */

   public:
    /* **** [v] Convert Function [v] **** */
    static void convert(const string &lit);
    /* **** [^] Convert Function [^] **** */
};

/* ********************* [^] SCALAR CONVERTER CLASS [^] ********************* */

#endif
