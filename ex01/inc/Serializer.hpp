/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:36:10 by sasano            #+#    #+#             */
/*   Updated: 2025/08/16 16:47:12 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

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