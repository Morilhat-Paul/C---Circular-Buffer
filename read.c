/*
** EPITECH PROJECT, 2024
** circular_buffer
** File description:
** read
*/

#include "circular_buffer.h"

/**
 * @brief Reads data from the circular buffer.
 *
 * @param buffer Pointer to the circular buffer.
 * @param data Pointer to the buffer where the read data will be stored.
 * @param size The size of the data to read.
 * @return The number of bytes successfully read from the circular buffer.
 */
size_t circular_buffer_read(circular_buffer_t *buffer, char *data, size_t size)
{
    size_t bytes_read = 0;

    while ((size > 0) && (buffer->count > 0)) {
        *data++ = *buffer->read++;
        buffer->read = (buffer->read == buffer->data + buffer->size)
            ? buffer->data
            : buffer->read;
        size--;
        bytes_read++;
        buffer->count--;
    }
    return bytes_read;
}
