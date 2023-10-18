#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **get_matrix_with_key_value(char *env_variable)
{
    long int adresses_diff;
    char **key_and_value;
    char *equal_occurrence;

    equal_occurrence = strchr(env_variable, '=');
    adresses_diff = labs(env_variable - equal_occurrence);
    key_and_value = (char **)calloc(sizeof(char *), 3);
    key_and_value[0] = (char *)calloc(sizeof(char), adresses_diff + 1);
    strncpy(key_and_value[0], env_variable, adresses_diff + 1);
    if (equal_occurrence)
        key_and_value[1] = strdup(++equal_occurrence);
    else
        key_and_value[1] = NULL;
    
    return key_and_value;
}

int main()
{
    char *env_variable = "SHELL=/bin/bash";

    char **key_value = get_matrix_with_key_value(env_variable);

    if (key_value)
    {
        printf("Key: %s\n", key_value[0]);
        printf("Value: %s\n", key_value[1]);

        // Don't forget to free the memory when done.
        free(key_value[0]);
        free(key_value[1]);
        free(key_value);
    }

    return 0;
}