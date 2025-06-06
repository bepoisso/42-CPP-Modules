/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:21:55 by bepoisso          #+#    #+#             */
/*   Updated: 2025/05/28 15:44:19 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog & src)  : Animal(src) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
}

Dog & Dog::operator=(const Dog & rhs) {
	if (this != &rhs) {
		_type = rhs._type;
	}
	return *this;
}
