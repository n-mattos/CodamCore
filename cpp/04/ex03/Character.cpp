/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:08:28 by nmattos-          #+#    #+#             */
/*   Updated: 2025/09/23 12:11:53 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const& name) : _name(name) {
	for (int i = 0; i < 4; i++) {
        _inventory[i] = nullptr;
    }
}

Character::Character(const Character& other) : _name(other._name) {
	// Init
	for (int i = 0; i < 4; i++) {
        _inventory[i] = nullptr;
    }

	// Copy
	for (int i = 0; i < 4; i++) {
        if (other._inventory[i] != nullptr) {
            _inventory[i] = other._inventory[i]->clone();
        }
    }
}

Character& Character::operator=(const Character& other) {
	if (this == &other) {
		return (*this);
	}

	// Clean
	for (int i = 0; i < 4; i++) {
		delete _inventory[i];
		_inventory[i] = nullptr;
	}

	// Copy
	_name = other._name;
	for (int i = 0; i < 4; i++) {
		if (other._inventory[i] != nullptr) {
			_inventory[i] = other._inventory[i]->clone();
		}
	}

	return (*this);
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
        delete _inventory[i];
    }
}

std::string const& Character::getName() const {
	return (_name);
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == nullptr) {
			_inventory[i] = m;
			return;
		}
	}
}

void	Character::unequip(int idx) {
	if (idx >= 0 && idx < 4) {
		_inventory[idx] = nullptr;
	}
}

void	Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4) {
		if (_inventory[idx] != nullptr) {
			_inventory[idx]->use(target);
		}
	}
}
