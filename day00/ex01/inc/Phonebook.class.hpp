/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 13:48:44 by irhett            #+#    #+#             */
/*   Updated: 2017/07/05 16:25:16 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.class.hpp"

class Phonebook {

public:

	int		num_entries;

	Phonebook(void);
	~Phonebook(void);

	void	add(void);

	void	search(void) const;

private:
	Contact _entries[10];

};

#endif
