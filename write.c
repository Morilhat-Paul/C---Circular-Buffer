/*
** EPITECH PROJECT, 2024
** circular_buffer
** File description:
** write
*/

#include "circular_buffer.h"

/**
 * @brief Writes data into the circular buffer.
 *
 * @param buffer Pointer to the circular buffer.
 * @param data Pointer to the data to write.
 * @param size The size of the data to write.
 * @return The number of bytes successfully written into the circular buffer.
 */
size_t circular_buffer_write(
    circular_buffer_t *buffer,
    const char *data,
    size_t size
)
{
    size_t bytes_written = 0;

    while ((size > 0) && (buffer->count < buffer->size)) {
        *buffer->write++ = *data++;
        buffer->write = (buffer->write == (buffer->data + buffer->size))
            ? buffer->data
            : buffer->write;
        size--;
        bytes_written++;
        buffer->count++;
    }
    return bytes_written;
}
