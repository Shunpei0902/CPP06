/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:45:57 by sasano            #+#    #+#             */
/*   Updated: 2025/08/16 16:49:54 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data *data = new Data();
    data->num = 42;
    data->str = "Hello, World!";

    // シリアライズ
    uintptr_t raw = Serializer::serialize(data);
    std::cout << "Serialized data: " << raw << std::endl;
    std::cout << "Data address: " << data << std::endl;
    std::cout << "Data num: " << data->num << ", str: " << data->str << std::endl;

    // デシリアライズ
    Data *deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized data: num = " << deserializedData->num
              << ", str = " << deserializedData->str << std::endl;
    std::cout << "Deserialized data address: " << deserializedData << std::endl;

    delete data;
    return 0;
}