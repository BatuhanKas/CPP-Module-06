/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 02:30:59 by bkas              #+#    #+#             */
/*   Updated: 2024/08/13 02:40:13 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include "../inc/Serializer.hpp"

/* **************************** [^] INCLUDES [^] **************************** */

/* ************************* [v] ORTHODOX FORM [v] ************************* */

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &oth) { *this = oth; }

Serializer &Serializer::operator=(const Serializer &oth) {
    (void)oth;
    return *this;
}

Serializer::~Serializer() {}

/* ************************* [^] ORTHODOX FORM [^] ************************* */

/* ******************* [v] SERIALIZE && DESERIALIZE [v] ******************* */

uintptr_t Serializer::serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}

/* ******************* [^] SERIALIZE && DESERIALIZE [^] ******************* */
