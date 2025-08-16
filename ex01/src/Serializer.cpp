/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:43:55 by sasano            #+#    #+#             */
/*   Updated: 2025/08/16 16:44:23 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
    // インスタンス化を防ぐためのコンストラクタは空
}

Serializer::Serializer(const Serializer &copy)
{
    *this = copy;
}

Serializer &Serializer::operator=(const Serializer &copy)
{
    if (this != &copy)
    {
        // 自己代入チェックはしてるけど中身が空
    } // *this を返してチェーン代入はできる
    return (*this);
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data *ptr)
{
    // Data ポインタを uintptr_t に変換して返す
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    // uintptr_t を Data ポインタに変換して返す
    return reinterpret_cast<Data *>(raw);
}
