/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <sasano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 23:37:51 by sasano            #+#    #+#             */
/*   Updated: 2025/11/01 22:23:54 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>
#include <climits>
#include <cctype>
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include <limits>

static bool isCharLiteral(const std::string &s)
{
    // return s.size() == 3 && s[0]=='\'' && s[2]=='\'';
    return s.size() == 1 && !isdigit(static_cast<unsigned char>(s[0]));
}

static bool isPseudoFloat(const std::string &s)
{
    return s == "nanf" || s == "+inff" || s == "-inff" || s == "inff";
}

static bool isPseudoDouble(const std::string &s)
{
    return s == "nan" || s == "+inf" || s == "-inf" || s == "inf";
}

static bool isIntLiteral(const std::string &s)
{
    if (s.empty())
        return false;
    char *end = 0;
    errno = 0;
    long v = std::strtol(s.c_str(), &end, 10);
    (void)v;
    return errno == 0 && end && *end == '\0';
}

static bool isFloatLiteral(const std::string &s)
{
    if (isPseudoFloat(s))
        return true;
    if (s.size() < 2 || s[s.size() - 1] != 'f')
        return false;
    std::string core = s.substr(0, s.size() - 1);
    char *end = 0;
    errno = 0;
    std::strtod(core.c_str(), &end);
    return errno == 0 && end && *end == '\0';
}

static bool isDoubleLiteral(const std::string &s)
{
    if (isPseudoDouble(s))
        return true;
    char *end = 0;
    errno = 0;
    std::strtod(s.c_str(), &end);
    return errno == 0 && end && *end == '\0';
}

static void printChar(double d, bool possible)
{
    std::cout << "char: ";
    if (!possible || d != d || d > UCHAR_MAX || d < 0)
    {
        std::cout << "impossible\n";
        return;
    }
    unsigned char c = static_cast<unsigned char>(d);
    if (!std::isprint(c))
    {
        std::cout << "Non displayable\n";
    }
    else
    {
        std::cout << '\'' << static_cast<char>(c) << "'\n";
    }
}

static void printInt(double d, bool possible)
{
    std::cout << "int: ";
    if (!possible || d != d || d > INT_MAX || d < INT_MIN)
    {
        std::cout << "impossible\n";
        return;
    }
    std::cout << static_cast<int>(d) << "\n";
}

static bool isIntegralFinite(double d)
{
    if (d != d)
        return false; // NaN
    if (d == std::numeric_limits<double>::infinity())
        return false;
    if (d == -std::numeric_limits<double>::infinity())
        return false;
    double i = static_cast<double>(static_cast<long>(d));
    return (d - i) == 0.0;
}

static void printFloat(double d)
{
    std::cout << "float: ";
    float f = static_cast<float>(d);
    if (d != d)
    {
        std::cout << "nanf\n";
        return;
    }
    if (d == std::numeric_limits<double>::infinity())
    {
        std::cout << "+inff\n";
        return;
    }
    if (d == -std::numeric_limits<double>::infinity())
    {
        std::cout << "-inff\n";
        return;
    }
    std::cout << f;
    if (isIntegralFinite(d))
        std::cout << ".0";
    std::cout << "f\n";
}

static void printDouble(double d)
{
    std::cout << "double: ";
    if (d != d)
    {
        std::cout << "nan\n";
        return;
    }
    if (d == std::numeric_limits<double>::infinity())
    {
        std::cout << "+inf\n";
        return;
    }
    if (d == -std::numeric_limits<double>::infinity())
    {
        std::cout << "-inf\n";
        return;
    }
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(isIntegralFinite(d) ? 1 : 6);
    std::cout << d << "\n";
    std::cout.unsetf(std::ios::floatfield);
}

void ScalarConverter::convert(const std::string &s)
{
    if (s.empty())
    {
        std::cerr << "Error: empty input" << std::endl;
        return;
    }

    // Detect and normalize to double value for unified printing
    double d = 0.0;
    bool intPossible = true;

    if (isCharLiteral(s))
    {
        char c = s[0];
        d = static_cast<double>(static_cast<unsigned char>(c));
    }
    else if (isPseudoFloat(s))
    {
        if (s == "nanf")
            d = std::numeric_limits<double>::quiet_NaN();
        else if (s == "+inff" || s == "inff")
            d = std::numeric_limits<double>::infinity();
        else if (s == "-inff")
            d = -std::numeric_limits<double>::infinity();
        intPossible = false;
    }
    else if (isPseudoDouble(s))
    {
        if (s == "nan")
            d = std::numeric_limits<double>::quiet_NaN();
        else if (s == "+inf" || s == "inf")
            d = std::numeric_limits<double>::infinity();
        else if (s == "-inf")
            d = -std::numeric_limits<double>::infinity();
        intPossible = false;
    }
    else if (isIntLiteral(s))
    {
        char *end = 0;
        errno = 0;
        long v = std::strtol(s.c_str(), &end, 10);
        (void)end;
        d = static_cast<double>(v);
    }
    else if (isFloatLiteral(s))
    {
        std::string core = s.substr(0, s.size() - 1);
        char *end = 0;
        errno = 0;
        d = std::strtod(core.c_str(), &end);
    }
    else if (isDoubleLiteral(s))
    {
        char *end = 0;
        errno = 0;
        d = std::strtod(s.c_str(), &end);
    }
    else
    {
        std::cerr << "Error: invalid literal" << std::endl;
        return;
    }

    printChar(d, true);
    printInt(d, intPossible);
    printFloat(d);
    printDouble(d);
}