/*
** EPITECH PROJECT, 2024
** circular_buffer
** File description:
** create
*/

#include <criterion/criterion.h>
#include "../../circular_buffer.h"

Test(create_and_destroy, basic) {
    circular_buffer_t *buffer = circular_buffer_create(4096);

    cr_assert_not_null(buffer);
    cr_assert_str_empty(buffer->data);
    cr_assert_str_empty(buffer->write);
    cr_assert_str_empty(buffer->read);
    cr_assert_eq(buffer->count, 0);
    cr_assert_eq(buffer->size, 4096);

    circular_buffer_destroy(buffer);
}

Test(destroy, buffer_is_null) {
    circular_buffer_t *buffer = NULL;

    circular_buffer_destroy(buffer);
    cr_assert_null(buffer);
}

Test(destroy, data_buffer_is_null) {
    circular_buffer_t *buffer = malloc(sizeof(circular_buffer_t));

    if (buffer)
        buffer->data = NULL;

    circular_buffer_destroy(buffer);
}
