/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <sasano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 23:25:09 by sasano            #+#    #+#             */
/*   Updated: 2025/11/01 22:04:15 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream> // for std::stringstream
#include <string>
#include <climits> // for INT_MIN, INT_MAX


class ScalarConverter
{
private:
    // インスタンス化を防ぐためprivateにする
    ScalarConverter();
    ScalarConverter(const ScalarConverter &copy);
    ScalarConverter &operator=(const ScalarConverter &copy);
    ~ScalarConverter();

public:
    static void convert(const std::string &input);
};