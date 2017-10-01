# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    xcore.s                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrarane <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/01 11:58:25 by nrarane           #+#    #+#              #
#    Updated: 2017/10/01 14:50:03 by nrarane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.name "xcore"
.comment "This is Xcore... you're about to get knocked the fuck out"

	fork	%400
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
