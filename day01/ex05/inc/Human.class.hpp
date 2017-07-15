/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 13:48:44 by irhett            #+#    #+#             */
/*   Updated: 2017/07/06 21:44:32 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_CLASS_HPP
# define HUMAN_CLASS_HPP

#include <string>
#include "Brain.class.hpp"

class Human {

public:

	Human(void);
	~Human(void);
	std::string		identify(void) const;
	const Brain		&getBrain(void) const;

private:

	const Brain		_b;

};

#endif
