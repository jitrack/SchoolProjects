/*
** EPITECH PROJECT, 2020
** skip
** File description:
** skip
*/

#include "my.h"

bool skip_string_flag(char const **str, char const *flag,
                     char const end, bool const choice)
{
    for (; **str && **str != end &&
    flag_cmp(**str, flag) == choice; ++*str);
    return (**str == end);
}

bool skip_to_next_word(char const **str, char const *flag, char const end)
{
    if (**str)
        for (; **str && **str != end &&
        flag_cmp(**str, flag) == false; ++*str);
    if (**str)
        for (; **str && **str != end &&
        flag_cmp(**str, flag) == true; ++*str);
    return (**str == end);

}
