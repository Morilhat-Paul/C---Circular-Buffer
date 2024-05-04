/*
** EPITECH PROJECT, 2024
** circular_buffer
** File description:
** create
*/

#include "circular_buffer.h"
#include <string.h>

/**
 * @brief Creates a new circular buffer.
 *
 * @param size The size of the circular buffer.
 * @return A pointer to the newly created circular buffer, or NULL if creation failed.
 */
circular_buffer_t *circular_buffer_create(size_t size)
{
    circular_buffer_t *buffer = malloc(sizeof(circular_buffer_t));

    buffer->size = size;
    buffer->data = calloc(size, sizeof(char));
    buffer->write = &(buffer->data[0]);
    buffer->read = &(buffer->data[0]);
    buffer->count = 0;
    return buffer;
}
