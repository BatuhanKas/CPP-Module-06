/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 01:37:50 by bkas              #+#    #+#             */
/*   Updated: 2024/08/13 02:23:00 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include "../inc/Data.hpp"

/* **************************** [^] INCLUDES [^] **************************** */

/* ************************* [v] ORTHODOX FORM [v] ************************* */

Data::Data() {}

Data::Data(uintptr_t value) { _value = value; }

Data::Data(const Data &oth) { *this = oth; }

Data &Data::operator=(const Data &oth) {
    (void)oth;
    return *this;
}

Data::~Data() {}

/* ************************* [^] ORTHODOX FORM [^] ************************* */

/* ************************ [v] SET & GET VALUE [v] ************************ */

void Data::setValue(const uintptr_t value) { _value = value; }

uintptr_t Data::getValue() const { return _value; }

/* ************************ [^] SET & GET VALUE [^] ************************ */
