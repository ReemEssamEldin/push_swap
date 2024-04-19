/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reldahli <reldahli@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:52:55 by reldahli          #+#    #+#             */
/*   Updated: 2024/01/30 10:52:57 by reldahli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*------------------------------------------------------------------------ */
/* The main function to get the next line (fish) from the file descriptor. */
/* Alex (get_next_line) gracefully reads lines from the                    */
/* magical aquarium (input file) using the cup (buffer). Alex aims to find */
/* and return each fish (line) one at a time without disturbing            */
/* the rest of the aquarium (file) and avoiding reading the entire file    */
/* at once. The explorer also handles edge cases and errors elegantly.     */
/* *read_from_file:                                                        */
/* Function to read data from the file and append it to partial content.   */
/* *get_next_line:                                                         */
/* The get_next_line function to get the next line from the file descriptor*/
/* *append_buffer:                                                         */
/* Function to append the read buffer data to the partial content (line).  */
/* The explorer (get_next_line) gracefully adds a scoop of water (read     */
/* buffer) to the current cup (line) and returns the updated line for      */
/* further examination.                                                    */
/* ----------------------------------------------------------------------- */

#include "../../inc/get_next_line.h"

char	*append_buffer(char *basin_buffer, char *read_buffer)
{
	char	*temp;

	temp = ft_strjoin(basin_buffer, read_buffer);
	free(basin_buffer);
	return (temp);
}

char	*extract_line(char *basin_buffer)
{
	size_t	length;
	char	*line;
	size_t	i;
	size_t	allocation_size;

	length = 0;
	allocation_size = length + 1;
	while (basin_buffer[length] && basin_buffer[length] != '\n')
		length++;
	allocation_size = length + 1;
	if (basin_buffer[length] == '\n')
		allocation_size += 1;
	line = (char *)ft_calloc(allocation_size, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i < length)
	{
		line[i] = basin_buffer[i];
		i++;
	}
	if (basin_buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*obtain_remaining(char *basin_buffer)
{
	size_t	i;
	size_t	j;
	char	*remaining;

	i = 0;
	j = 0;
	while (basin_buffer[i] && basin_buffer[i] != '\n')
		i++;
	if (!basin_buffer[i] || !basin_buffer[i + 1])
	{
		free(basin_buffer);
		return (NULL);
	}
	remaining = (char *)ft_calloc(ft_strlen(basin_buffer) - i + 1,
			sizeof(char));
	i++;
	while (basin_buffer[i])
		remaining[j++] = basin_buffer[i++];
	remaining[j] = '\0';
	free(basin_buffer);
	return (remaining);
}

char	*read_from_file(char *basin_buffer, int fd)
{
	int		bytes_read;
	char	*cup_buffer;

	cup_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (1)
	{
		bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		cup_buffer[bytes_read] = '\0';
		basin_buffer = append_buffer(basin_buffer, cup_buffer);
		if (ft_strchr(basin_buffer, '\n'))
			break ;
	}
	free(cup_buffer);
	if (bytes_read < 0 || (bytes_read == 0 && (!basin_buffer
				|| !*basin_buffer)))
	{
		free(basin_buffer);
		return (NULL);
	}
	return (basin_buffer);
}

char	*get_next_line(int fd)
{
	static char	*basin_buffer;
	char		*line;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
	{
		if (basin_buffer)
		{
			free(basin_buffer);
			basin_buffer = NULL;
		}
		return (NULL);
	}
	if (!basin_buffer)
		basin_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!ft_strchr(basin_buffer, '\n'))
		basin_buffer = read_from_file(basin_buffer, fd);
	if (!basin_buffer)
		return (NULL);
	line = extract_line(basin_buffer);
	basin_buffer = obtain_remaining(basin_buffer);
	return (line);
}
