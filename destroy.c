/*
** EPITECH PROJECT, 2024
** circular_buffer
** File description:
** destroy
*/

#include "circular_buffer.h"

/**
 * @brief Destroys a circular buffer, freeing the memory.
 *
 * @param buffer Pointer to the circular buffer to destroy.
 */
void circular_buffer_destroy(circular_buffer_t *buffer)
{
    if (buffer) {
        if (buffer->data)
            free(buffer->data);
        free(buffer);
    }
}
