/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <sasano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:36:10 by sasano            #+#    #+#             */
/*   Updated: 2025/11/01 20:10:57 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h> // for uintptr_t

struct Data
{
    int num;
    std::string str;
};

class Serializer
{
private:
    // インスタンス化を防ぐためのコンストラクタは private にする
    Serializer();
    Serializer(const Serializer &copy);
    Serializer &operator=(const Serializer &copy);
    ~Serializer();

public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};