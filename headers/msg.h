/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:46:43 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/14 17:39:00 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H

int			print_error(const char *str);
void		print_list(t_stack *stack, char pile);
void		print_sinmas(const char *str);
void		print_exit(char *str);
void		double_print(char **str);

#endif
