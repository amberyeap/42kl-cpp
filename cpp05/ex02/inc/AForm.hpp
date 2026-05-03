/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 15:57:25 by ayeap             #+#    #+#             */
/*   Updated: 2026/05/02 15:57:25 by ayeap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool _signedStatus;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		virtual void execute(Bureaucrat const& executor) const = 0;
};

#endif