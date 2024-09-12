/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:29:12 by bkas              #+#    #+#             */
/*   Updated: 2024/09/12 15:53:31 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */

#include "../inc/Data.hpp"
#include "../inc/Serializer.hpp"

/* **************************** [^] INCLUDES [^] **************************** */

/* ****************************** [v] MAIN [v] ****************************** */

int main() {
    try {
        Data *ptr = new Data(10);
        cout << "----------------------------------" << endl;
        cout << "Default adress: " << ptr << endl;
        cout << "----------------------------------" << endl;

        uintptr_t a = Serializer::serialize(ptr);
        cout << "Serialized value: " << a << endl;
        cout << "----------------------------------" << endl;

        ptr = Serializer::deserialize(a);
        cout << "Deserialized adress: " << ptr << endl;
        cout << "----------------------------------" << endl;

        delete ptr;
    } catch (exception &e) {
        std::cerr << "Memory Allocation Failed: " << e.what() << endl;
    }
}

/* ****************************** [^] MAIN [^] ****************************** */
