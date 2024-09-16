/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 01:36:45 by bkas              #+#    #+#             */
/*   Updated: 2024/09/16 10:11:20 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] DEFINES [v] **************************** */

#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

/* **************************** [^] DEFINES [^] **************************** */

/* *************************** [v] INCLUDES [v] *************************** */

#include <stdlib.h>
#include <sys/time.h>

#include <iostream>

using std::cout;
using std::endl;
using std::exception;
using std::string;

/* *************************** [^] INCLUDES [^] *************************** */

/* **************************** [v] DEFINES [v] **************************** */

#define castToDynamic(p, Type) ((dynamic_cast<Type*>(p)) ? (true) : (false))
#define dynamicRef(p, Type) (dynamic_cast<Type&>(p))

/* **************************** [^] DEFINES [^] **************************** */

/* ************************** [v] BASE CLASS [v] ************************** */

class Base {
   public:
    virtual ~Base();
};

/* ************************** [^] BASE CLASS [^] ************************** */

/* *********************** [v] DERIVED CLASSES [v] *********************** */

class A : public Base {};
class B : public Base {};
class C : public Base {};

/* *********************** [^] DERIVED CLASSES [^] *********************** */

/* ************************** [v] FUNCTIONS [v] ************************** */

Base* generate(void);

void identify(Base* p);
void identify(Base& p);

/* ************************** [^] FUNCTIONS [^] ************************** */

#endif
