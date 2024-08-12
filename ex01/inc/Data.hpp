/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:22:35 by bkas              #+#    #+#             */
/*   Updated: 2024/08/13 02:42:29 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] DEFINES [v] **************************** */

#ifndef DATA_HPP
#define DATA_HPP

/* **************************** [^] DEFINES [^] **************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::exception;
using std::string;

/* **************************** [^] INCLUDES [^] **************************** */

/* ********************* [v] SCALAR CONVERTER CLASS [v] ********************* */

class Data {
   private:
    /* **** [v] uintptr_t value [v] **** */
    uintptr_t _value;
    /* **** [^] uintptr_t value [^] **** */
    Data();

   public:
    /* ************* [v] Orthodox Form [v] ************* */
    Data(uintptr_t value);
    Data(const Data &oth);
    Data &operator=(const Data &oth);
    ~Data();
    /* ************* [^] Orthodox Form [^] ************* */

    /* ************* [v] Convert Function [v] ************* */
    void setValue(const uintptr_t value);
    uintptr_t getValue() const;
    /* ************* [^] Convert Function [^] ************* */
};

/* ********************* [^] SCALAR CONVERTER CLASS [^] ********************* */

#endif
