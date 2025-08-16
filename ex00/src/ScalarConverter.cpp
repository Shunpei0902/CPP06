/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 23:37:51 by sasano            #+#    #+#             */
/*   Updated: 2025/08/16 15:55:26 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    // インスタンス化を防ぐためのコンストラクタは空
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    *this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
    if (this != &copy)
    {
    }; // 自己代入チェックはしてるけど中身が空 *this を返してチェーン代入はできる コピーできないようにしている
    return (*this);
}

ScalarConverter::~ScalarConverter() {}

std::string isPrintableChar(std::string input)
{
    int i = 0;
    try
    {
        i = std::stoi(input);
    }
    catch (const std::out_of_range &)
    { // 入力が int の範囲外の場合
        return "oof";
    }
    catch (const std::exception &e)
    { // 入力が整数でない場合
        std::cerr << "Error: " << e.what() << std::endl;
        return "Nan";
    }

    // 入力が int の範囲内であれば char に変換
    char c = static_cast<char>(i);
    // 印字可能な文字かどうかをチェック
    if (std::isprint(c))
    {
        return "'" + std::string(1, c) + "'";
    }
    else
    {
        return "Non displayable";
    }
}

std::string isInt(std::string input)
{
    try
    {
        // int 変換を試す
        int value = std::stoi(input);
        return std::to_string(value);
    }
    catch (const std::out_of_range &) // 入力が int の範囲外の場合
    {
        return "impossible";
    }
    catch (const std::invalid_argument &) // 入力が整数でない場合
    {
        return "impossible";
    }
}

std::string isFloat(std::string input)
{
    try
    {
        // float 変換を試す
        float value = std::stof(input);
        return std::to_string(value) + "f";
    }
    catch (const std::out_of_range &)
    {
        return "impossible";
    }
    catch (const std::invalid_argument &)
    {
        return "impossible";
    }
}

std::string isDouble(std::string input)
{
    try
    {
        // double 変換を試す
        double value = std::stod(input);
        return std::to_string(value);
    }
    catch (const std::out_of_range &)
    {
        return "impossible";
    }
    catch (const std::invalid_argument &)
    {
        return "impossible";
    }
}

void ScalarConverter::convert(std::string input)
{
    // 入力チェック
    try
    {
        size_t pos;
        std::stod(input, &pos); // double 変換を試みる
    }
    catch (const std::exception &e)
    {
        return (std::cout << "This is not a valid input" << std::endl, void());
    }

    // 特殊ケースの処理
    if (input.compare("nan") == 0 || input.compare("nanf") == 0 || input.compare("inf") == 0 || input.compare("inff") == 0 || input.compare("+inf") == 0 || input.compare("+inff") == 0 || input.compare("-inf") == 0 || input.compare("-inff") == 0)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << input << std::endl;
        std::cout << "double: " << input << std::endl;
        return;
    }

    // 各型への変換結果の出力
    std::cout << "Input: " << input << std::endl;
    std::cout << "char: " << isPrintableChar(input) << std::endl;
    std::cout << "int: " << isInt(input) << std::endl;
    std::cout << "float: " << isFloat(input) << std::endl;
    std::cout << "double: " << isDouble(input) << std::endl;
}