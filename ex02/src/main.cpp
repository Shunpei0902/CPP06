/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:00:31 by sasano            #+#    #+#             */
/*   Updated: 2025/08/16 17:28:28 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Base *generate()
{
    int random = rand() % 3; // 0, 1, 2 のいずれかを生成
    std::cout << "Random number generated: " << random << std::endl;
    switch (random)
    {
    case 0:
        std::cout << "Generating instance of A" << std::endl;
        return new A(); // A クラスのインスタンスを生成
    case 1:
        std::cout << "Generating instance of B" << std::endl;
        return new B(); // B クラスのインスタンスを生成
    case 2:
        std::cout << "Generating instance of C" << std::endl;
        return new C(); // C クラスのインスタンスを生成
    default:
        std::cout << "Unknown type generated" << std::endl;
        return nullptr; // 予期しない場合は nullptr を返す
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p) != nullptr)
        std::cout << "Type: A" << std::endl;
    else if (dynamic_cast<B *>(p) != nullptr)
        std::cout << "Type: B" << std::endl;
    else if (dynamic_cast<C *>(p) != nullptr)
        std::cout << "Type: C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        std::cout << "Type: A" << std::endl;
        (void)a; // a を使用しない場合の警告を防ぐ
    }
    catch (...)
    {
        try
        {
            B &b = dynamic_cast<B &>(p);
            std::cout << "Type: B" << std::endl;
            (void)b; // b を使用しない場合の警告を防ぐ
        }
        catch (...)
        {
            try
            {
                C &c = dynamic_cast<C &>(p);
                std::cout << "Type: C" << std::endl;
                (void)c; // c を使用しない場合の警告を防ぐ
            }
            catch (...)
            {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}

int main()
{
    Base *base = generate();
    identify(base);
    identify(*base);
    delete base; // 動的に生成したオブジェクトを解放
    return 0;
}