/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: anspirga <anspirga@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/13 14:31:59 by anspirga      #+#    #+#                 */
/*   Updated: 2020/12/13 14:51:15 by anspirga      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int     main(int argc, char *argv[])
{
   my_printf(argv[0]);
   my_printf("\nHello\n");
   my_printf("Test String %s with integer %i and %% test\n", argv[0], argc);

   return 0;
}


int  my_printf(char *pszFormatString, ...)
{
   int CharacterCount = 0;
   int PrintInteger;
   char IntegerString[10];
   char *pPrintString;
   va_list VaList;

   va_start(VaList, pszFormatString);
   
   while(*pszFormatString)
   {
       if(*pszFormatString == '%')
       {
           pszFormatString++;
           switch(*pszFormatString)
           {
              case 's': 
                      pPrintString = va_arg(VaList, char *);
                      fputs(pPrintString, stdout);
                      pszFormatString++;
                      CharacterCount += strlen(pPrintString);
                      break;
              case 'i':  
                      PrintInteger = va_arg(VaList, int);
                      _itoa(PrintInteger, IntegerString, 10);
                      fputs(IntegerString, stdout);
                      pszFormatString++;
                      CharacterCount += strlen(IntegerString);
                      break;
              case '%': 
                      putchar('%');
                      pszFormatString++;
                      CharacterCount++;
                      break;
              case '\0': 
                      break;
              default:
                      putchar('%');
                      putchar(*pszFormatString);
                      pszFormatString++;            
                      CharacterCount +=2;
           }       
       }
       else
       {
           putchar(*pszFormatString);
           pszFormatString++;
           CharacterCount++;
       }
   }

   va_end(VaList);

   return CharacterCount;
}
