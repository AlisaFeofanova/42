#include "../includes/pipex.h"
#include "../includes/pipex_bonus.h"
#include <stdio.h>

void print_args_test(char **args)
{
    int i = 0;
    if (!args)
    {
        printf("The array is NULL\n");
        return;
    }
    while (args[i])
    {
        printf("  args[%d]: [%s]\n", i, args[i]);
        i++;
    }
    printf("  args[%d]: NULL\n", i);
}


void print_bonus_args(char **args)
{
    int i;

    i = 0;
    if (!args)
    {
        printf("  Result: NULL (memory allocation error)\n");
        return ;
    }
    while (args[i])
    {
        printf("  [Argument %d]: %s\n", i, args[i]);
        i++;
    }
    printf("  [Argument %d]: NULL\n", i);
}


int main(int argc, char *argv[], char *envp[]) {
    (void)argc; 
    (void)argv; 
    int     i;
    char    *path; // find_path_env, get_cmd_path 
    char    **test_args; // get_cmd_args
    char    **res; // TESTING QUOTATION MARK PARSE (BONUS)
    
    i = 0;
    path = find_path_env(envp);



    printf("\n###############> START TEST FOR find_path_env FUNCTION <###############\n\n");
    printf("Expected result: /usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin\nGet:   ");
    if (!path)
        return (1);
    while (path[i] != '\0') {
        printf("%c", path[i]);
        i++;
    }
    printf("\n\n");



    printf("\n################> START TEST FOR get_cmd_path FUNCTION <###############\n\n");

    path = get_cmd_path("ls", envp);
    printf("Test 'ls':\nExpected result: /bin/ls (or /usr/bin/ls)\nGet:  %s\n\n", path);
    free(path);
    printf("-----------------------------------------------------------\n\n");

    path = get_cmd_path("grep", envp);
    printf("Test 'grep':\nExpected result: /bin/grep (or /usr/bin/grep)\nGet:  %s\n\n", path);
    free(path);
    printf("-----------------------------------------------------------\n\n");

    path = get_cmd_path("abracadabra", envp);
    printf("Test 'abracadabra':\nExpected result: (null)\nGet:  %s\n\n", path);
    free(path);
    printf("-----------------------------------------------------------\n\n");

    path = get_cmd_path("/bin/cat", envp);
    printf("Test '/bin/cat':\nExpected result: /bin/cat\nGet:  %s\n\n", path);
    printf("-----------------------------------------------------------\n\n");
   
    free(path);



    printf("\n################> START TEST FOR get_cmd_args FUNCTION <###############\n\n");

    printf("Test str: \"ls -l -a\"\n");
    test_args = get_cmd_args("ls -l -a");
    print_args_test(test_args);
    free_array(test_args); 
    printf("\n-----------------------------------------------------------\n\n");


    printf("\nTest str: \"grep a1\"\n");
    test_args = get_cmd_args("grep a1");
    print_args_test(test_args);
    free_array(test_args); 
    printf("\n-----------------------------------------------------------\n\n");


    printf("\nTest str: \"wc\"\n");
    test_args = get_cmd_args("wc");
    print_args_test(test_args);
    free_array(test_args);
    printf("\n-----------------------------------------------------------\n\n");




    printf("\n################> TESTING QUOTATION MARK PARSE (BONUS) <###############\n\n");

    printf("Test 1: grep \"hello world\" -i\n");
    printf("Expected result: 3 arguments, the second one should be equal [hello world]\n");
    res = get_cmd_args_bonus("grep \"hello world\" -i");
    print_bonus_args(res);
    free_array(res);
    printf("\n-----------------------------------------------------------\n\n");

    printf("Test 2: awk '{print $1}'\n");
    printf("Expected result: 2 arguments, the second one should be equal [{print $1}]\n");
    res = get_cmd_args_bonus("awk '{print $1}'");
    print_bonus_args(res);
    free_array(res);
    printf("\n-----------------------------------------------------------\n\n");

    printf("Тест 3: gcc main.c -printf \"\"\n");
    printf("Expected result: The last text argument must be an empty string. []\n");
    res = get_cmd_args_bonus("gcc main.c -printf \"\"");
    print_bonus_args(res);
    free_array(res);
    printf("\n-----------------------------------------------------------\n\n");















    printf("\n\n###########################> TESTS END <###############################\n\n");

    return (0);
}
