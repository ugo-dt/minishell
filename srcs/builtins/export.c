/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:53:43 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/25 15:05:48 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
void display(char **array, int size){
  for(int i=0; i<size; i++){
    printf("%s ", array[i]);
  }
  printf("\n");
}

int	main(void)
{
	int		i;
	int		j;
	char	**array;
	char	s1[] = "salut";
	char	s2[] = "les";
	char	s3[] = "amis";
	char	*temp;
	int		size = 3;

	array = malloc(sizeof(char *) * (size + 1));
	if (!array)
		return (1);
	array[0] = s1;
	array[1] = s2;
	array[2] = s3;
	array[3] = NULL;
	display(array, size);
	i = 0;
	while (i < size)
	{
    	j = 0;
		while (j < size - 1 - i)
		{
			if(strcmp(array[j], array[j+1]) > 0)
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	display(array, size);
	free(array);
	return (0);
}
*/