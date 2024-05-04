/*
** EPITECH PROJECT, 2024
** circular_buffer
** File description:
** write
*/

#include <criterion/criterion.h>
#include <string.h>
#include <stdio.h>
#include "../../circular_buffer.h"

Test(write_and_read, basic) {
    circular_buffer_t *buffer = circular_buffer_create(4096);
    cr_assert_not_null(buffer);
    cr_assert_eq(buffer->size, 4096);

    const char *str = "TEST";
    circular_buffer_write(buffer, str, strlen(str));

    cr_assert_eq(buffer->count, strlen(str));
    cr_assert_str_eq(buffer->data, "TEST");
    cr_assert_str_eq(buffer->read, str);
    cr_assert_eq(buffer->count, strlen(str));

    /* Because write pointer to the last character of the data */
    cr_assert_str_empty(buffer->write);

    char str_read[4] = { 0 };
    circular_buffer_read(buffer, str_read, strlen(str));

    cr_assert_str_eq(str_read, str);
    cr_assert_str_empty(buffer->read);
    cr_assert_eq(buffer->count, 0);

    circular_buffer_destroy(buffer);
}

Test(write_and_read, buffer_size_is_4) {

    circular_buffer_t *buffer = circular_buffer_create(4);
    cr_assert_not_null(buffer);
    cr_assert_eq(buffer->size, 4);

    const char *str1 = "TEST";
    circular_buffer_write(buffer, str1, strlen(str1));

    cr_assert_str_eq(buffer->read, str1);
    cr_assert_str_eq(buffer->data, "TEST");
    cr_assert_eq(buffer->count, strlen(str1));


    char str_read[4] = { 0 };
    circular_buffer_read(buffer, str_read, strlen(str1));

    cr_assert_str_eq(str_read, str1);
    cr_assert_eq(buffer->count, 0);


    const char *str2 = "test";
    circular_buffer_write(buffer, str2, strlen(str2));

    cr_assert_str_eq(buffer->read, str2);
    cr_assert_str_eq(buffer->data, "test");
    cr_assert_eq(buffer->count, 4);


    circular_buffer_read(buffer, str_read, strlen(str2));

    cr_assert_str_eq(str_read, str2);
    cr_assert_eq(buffer->count, 0);

    circular_buffer_destroy(buffer);
}


Test(write_and_read, buffer_size_is_0) {

    circular_buffer_t *buffer = circular_buffer_create(0);
    cr_assert_not_null(buffer);
    cr_assert_eq(buffer->size, 0);

    const char *str1 = "TEST";
    circular_buffer_write(buffer, str1, strlen(str1));

    cr_assert_str_empty(buffer->read);
    cr_assert_str_empty(buffer->data);
    cr_assert_eq(buffer->count, 0);


    char str_read[4] = { 0 };
    circular_buffer_read(buffer, str_read, strlen(str1));

    cr_assert_str_empty(str_read);
    cr_assert_eq(buffer->count, 0);

    circular_buffer_destroy(buffer);
}
