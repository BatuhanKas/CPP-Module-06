/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:22:35 by bkas              #+#    #+#             */
/*   Updated: 2024/07/31 17:32:29 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] DEFINES [v] **************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

/* **************************** [^] DEFINES [^] **************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::string;

/* **************************** [^] INCLUDES [^] **************************** */

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
    static bool isChar(const string &lit);
    static bool isInt(const string &lit);
    /* ********* [^] Find Type [^] ********* */

    /* ******** [v] Print Type [v] ******** */
    static void printChar(const string lit);
    static void printInt(const string lit);
    /* ******** [^] Print Type [^] ******** */

   public:
    /* **** [v] Convert Function [v] **** */
    static void convert(const string &lit);
    /* **** [^] Convert Function [^] **** */
};

/* ********************* [^] SCALAR CONVERTER CLASS [^] ********************* */

#endif
