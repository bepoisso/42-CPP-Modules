/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:55:48 by bepoisso          #+#    #+#             */
/*   Updated: 2025/06/16 15:25:24 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

    /* Canonical Form */
ScalarConverter::ScalarConverter() {
}

ScalarConverter::~ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter & other) {
    (void)other;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter & other) {
    if (this != &other) {
    }
    return *this;
}

/* Methods */

void ScalarConverter::convert(const std::string & literal) {
    std::string s = literal;
    if (isChar(literal))
        fromChar(literal[0]);
    else if (isInt(literal))
        fromInt(std::atoi(literal.c_str()));
    else if (isPseudoDouble(literal) || isPseudoFloat(literal))
        fromPseudo(literal);
    else if (isFloat(literal))
        fromFloat(std::atof(literal.c_str()));
    else if (isDouble(literal))
        fromDouble(std::atof(literal.c_str()));
    else
        std::cout << "Unknow literal type" << std::endl;
}

bool ScalarConverter::isChar(const std::string & str) {
    if (str.length() != 1)
        return false;
    if (!std::isprint(str[0]) || std::isdigit(str[0]))
        return false;
    return true;
}

bool ScalarConverter::isInt(const std::string & str) {
    size_t start = 0;
    if (str.empty())
        return false;
    if (str[0] == '+' || str[0] == '-')
        start = 1;
    if (start == str.length())
        return false;

    for (size_t i = start; i < str.length(); i++) {
        if (!std::isdigit(str[i]))
            return false;
    }
    long long i = std::atoll(str.c_str());
    if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max()) {
        std::cout << "error: int overflow" << std::endl;
        return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string & str) {
    int len = str.length();
    if (len < 2 || str[len - 1] != 'f')
        return false;

    std::string num = str.substr(0, len - 1);

    bool point = false;
    
    int start = 0;
    if (str[0] == '+' || str[0] == '-')
        start = 1;
    
    for (size_t i = start; i < num.length(); i++) {
        if (num[i] == '.') {
            if (point)
                return false;
            point = true;
        }
        else if (!std::isdigit(num[i]))
            return false;
    }
    return point;
}

bool ScalarConverter::isPseudoFloat(const std::string & str) {
    if (str == "nanf" || str == "+inff" || str == "-inff")
        return true;
    return false;
}

bool ScalarConverter::isDouble(const std::string & str) {
    bool point = false;
    
    if (str.empty())
    return false;
    
    int start = 0;
    if (str[0] == '+' || str[0] == '-')
        start = 1;

    for (size_t i = start; i < str.length(); i++) {
        if (str[i] == '.') {
            if (point)
                return false;
            point = true;
        }
        else if (!std::isdigit(str[i]))
            return false;
    }
    return point;
}

bool ScalarConverter::isPseudoDouble(const std::string & str) {
    if (str == "nan" || str == "+inf" || str == "-inf")
        return true;
    return false;
}


void ScalarConverter::fromChar(char c) {
    std::cout << "----------From char call----------" << std::endl;
    
    // Char
    if (c < std::numeric_limits<char>::min() || c > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (c < 32 || c > 126)
        std::cout << "char: non displayable" << std::endl;
    else 
        std::cout << "char: \'" << c << "\'" << std::endl;
    
    // Int
    if (c < std::numeric_limits<int>::min() || c > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(c) << std::endl;
    
    // Float
    if (c < std::numeric_limits<float>::min() || c > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else 
        std::cout << "float: " << static_cast<float>(c)
        << "." << (static_cast<float>(c) - static_cast<int>(c)) 
        << "f" << std::endl;

    // Double
    if (c < std::numeric_limits<double>::min() || c > std::numeric_limits<double>::max())
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(c)
            << "." << (static_cast<double>(c) - static_cast<int>(c)) << std::endl;
}

void ScalarConverter::fromInt(int i) {
    std::cout << "----------From int call----------" << std::endl;
    
    // Char
    if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (i < 32 || i > 126)
        std::cout << "char: non displayable" << std::endl;
    else 
        std::cout << "char: \'" << static_cast<char>(i) << "\'" << std::endl;
    
    // Int
    if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    
    // Float
    if (i < -std::numeric_limits<float>::max() || i > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else 
        std::cout << "float: " << static_cast<float>(i)
        << "." << (static_cast<float>(i) - static_cast<int>(i)) 
        << "f" << std::endl;

    // Double
    if (i < -std::numeric_limits<double>::max() || i > std::numeric_limits<double>::max())
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(i)
            << "." << (static_cast<double>(i) - static_cast<int>(i)) << std::endl;
}

void ScalarConverter::fromFloat(float i) {
    std::cout << "----------From float call----------" << std::endl;
    
    // Char
    if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (i < 32 || i > 126)
        std::cout << "char: non displayable" << std::endl;
    else 
        std::cout << "char: \'" << static_cast<char>(i) << "\'" << std::endl;
    
    // Int
    if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(i) << std::endl;
      
    // Float
    if (i < -std::numeric_limits<int>::max() || i > std::numeric_limits<int>::max())
        std::cout << "float: impossible" << std::endl;
    else {
        std::cout << "float: " << i;
        if (static_cast<int>(i) - i == 0)
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }

    // Double
    if (i < -std::numeric_limits<double>::max() || i > std::numeric_limits<double>::max())
        std::cout << "double: impossible" << std::endl;
    else {
        std::cout << "double: " << static_cast<double>(i);
        if ((static_cast<int>(i) - static_cast<double>(i)) == 0)
            std::cout << ".0";
        std::cout << std::endl;
    }
}

void ScalarConverter::fromDouble(double i) {
    std::cout << "----------From int double----------" << std::endl;
    
    // Char
    if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (i < 32 || i > 126)
        std::cout << "char: non displayable" << std::endl;
    else 
        std::cout << "char: \'" << static_cast<char>(i) << "\'" << std::endl;
    
    // Int
    if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(i) << std::endl;
    
    // Float
    if (i < -std::numeric_limits<float>::max() || i > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else {
        std::cout << "float: " << static_cast<float>(i);
        if (static_cast<int>(i) - static_cast<float>(i) == 0)
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }

    // Double
    if (i < -std::numeric_limits<double>::max() || i > std::numeric_limits<double>::max())
        std::cout << "double: impossible" << std::endl;
    else {
        std::cout << "double: " << i;
        if ((static_cast<int>(i) - i) == 0)
            std::cout << ".0";
        std::cout << std::endl;
    }
}

void ScalarConverter::fromPseudo(const std::string & literal) {
    if (literal == "nan" || literal == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (literal == "+inf" || literal == "+inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (literal == "-inf" || literal == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}