# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    xcore.s                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrarane <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/01 15:00:49 by nrarane           #+#    #+#              #
#    Updated: 2017/10/01 16:19:37 by nrarane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.name "xcore"
.comment "This is Xcore... you're about to get knocked the fuck out"

	fork	%:problem
	live	%1
	ld		%0, r2
	sti		r1, %:attack, %1

attack:
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	zjmp	%:survivor

survivor:
	fork	%256
	st		r1, 256
	live	%42
	zjmp	%:attack

problem:
	ld		%0, r5
	st		r5, 6

trouble:
	live	%1
	fork	%900
	zjmp	%:trouble
