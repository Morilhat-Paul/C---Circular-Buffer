/*
** EPITECH PROJECT, 2024
** circular_buffer
** File description:
** circular_buffer
*/

#ifndef CIRCULAR_BUFFER_H_
    #define CIRCULAR_BUFFER_H_

    #include <stdlib.h>

/* Struct that defines a circular buffer */
typedef struct circular_buffer_s {
    size_t size;               /* Maximum capacity of the buffer */
    char *data;                 /* Array to store the actual data */
    char *write;               /* Pointer to the position to write new data */
    char *read;                /* Pointer to the position to read data */
    size_t count;              /* Current number of elements in the buffer */
} circular_buffer_t;

circular_buffer_t *circular_buffer_create(size_t size);
void circular_buffer_destroy(circular_buffer_t *buffer);
size_t circular_buffer_write(circular_buffer_t *buffer, const char *data,
    size_t size);
size_t circular_buffer_read(circular_buffer_t *buffer, char *data, size_t size);

#endif /* !CIRCULAR_BUFFER_H_ */
