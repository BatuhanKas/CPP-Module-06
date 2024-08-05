/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FindType.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:49:50 by bkas              #+#    #+#             */
/*   Updated: 2024/08/05 16:14:55 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include "../inc/ScalarConverter.hpp"

/* **************************** [^] INCLUDES [^] **************************** */

eType ScalarConverter::findType(const string lit) {
    if (isChar(lit))
        return CHAR;
    else if (isInt(lit))
        return INT;
    else if (isFloat(lit))
        return FLOAT;
    else
        return ERROR;
    // return DOUBLE;
    // return ONECHAR;
}

/* *************************** [v] FIND TYPE [v] *************************** */
