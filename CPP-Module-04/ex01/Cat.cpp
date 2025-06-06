/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:21:44 by bepoisso          #+#    #+#             */
/*   Updated: 2025/05/28 17:47:54 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat(void) : Animal("Cat"){
	std::cout << "Cat default constructor called" << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat & src) : Animal(src) {
	std::cout << "Cat copy constructor called" << std::endl;
	_brain = new Brain(*src._brain);
}

Cat::~Cat(void) {
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat & Cat::operator=(const Cat & rhs) {
	if (this != &rhs) {
		_type = rhs._type;
		delete _brain;
		_brain = new Brain(*rhs._brain);
	}
	return *this;
}

std::string	Cat::getIdeas(int index) {
	return this->_brain->getIdeas(index);
}

void		Cat::setIdeas(std::string newIdea, int index) {
	this->_brain->setIdeas(newIdea, index);
}
