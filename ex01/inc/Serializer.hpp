/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 01:36:45 by bkas              #+#    #+#             */
/*   Updated: 2024/08/13 02:44:36 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] DEFINES [v] **************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

/* **************************** [^] DEFINES [^] **************************** */

/* *************************** [v] INCLUDES [v] *************************** */

class Data;

#include <stdint.h>

/* *************************** [^] INCLUDES [^] *************************** */

/* *********************** [v] SERIALIZER CLASS [v] *********************** */

class Serializer {
   private:
    /* ************* [v] Orthodox Form [v] ************* */
    Serializer();
    Serializer(const Serializer &oth);
    Serializer &operator=(const Serializer &oth);
    ~Serializer();
    /* ************* [^] Orthodox Form [^] ************* */

   public:
    /* ******* [v] Serialize && Deserialize [v] ******* */
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
    /* ******* [^] Serialize && Deserialize [^] ******* */
};

/* *********************** [^] SERIALIZER CLASS [^] *********************** */

#endif
