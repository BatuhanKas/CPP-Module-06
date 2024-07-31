/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:22:35 by bkas              #+#    #+#             */
/*   Updated: 2024/07/31 15:20:03 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] DEFINES [v] **************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

/* **************************** [^] DEFINES [^] **************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
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

    /* ********* [v] Find Type [v] ********* */
    static bool isChar(const string &lit);
    static bool isInt(const string &lit);
    /* ********* [^] Find Type [^] ********* */

   public:
    /* **** [v] Convert Function [v] **** */
    static void convert(string lit);
    /* **** [^] Convert Function [^] **** */
};

/* ********************* [^] SCALAR CONVERTER CLASS [^] ********************* */

#endif
