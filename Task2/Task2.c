#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <locale.h>

int main(int argc,char** argv)
{
    setlocale(LC_ALL, "Rus");
    if(argc == 1)
    {
        printf("'Введите -h для вывода меню'\n");
        return 0;
    }
    char* opts = "ho:c";
    char* out_file_name;
    int opt;
    int mod = 1;
    char mod_str[] = "Не активирован";
    while( (opt = getopt(argc, argv, opts)) != -1) {
        switch (opt){
            case 'h':
            {
                printf("Справка по использованию программы:\n");
                printf("' -h '               ---> Вывод меню\n");
   		        printf("' -o out_file_name ' ---> Задание имени выходного файла\n");
   		        printf("' -c '               ---> Включение особого режима работы\n");
                printf("Особый режим работы - %s \n", mod_str);
                return 0; 
            }
            case 'o':
            {
                if(mod == 1)
                {
                    out_file_name = optarg;
                    printf("\nИмя выходного файла: %s\n", out_file_name);
                }
                else printf("\nОпция заблокирована. \n");
                printf("Особый режим работы - %s \n", mod_str);
                sleep(1);
                break;
            }
            case 'c': 
            {
                printf("\nАктивация особого режима ... ");
                mod = 0;
                strcpy( mod_str, "Активирован" );
                printf("\n");
                sleep(1);
                printf("Особый режим работы - %s, опция '-о ' заблокирована\n", mod_str);
                sleep(1);
                break;
            }
        }
    }
    return 0;
}