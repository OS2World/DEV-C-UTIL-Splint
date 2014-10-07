/* Provided by Nelson Beebe */
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

int main(void) 
{
  (void)wprintf(L"English:  Hello, world!\n");
  (void)printf(L"English:  Hello, world!\n"); /* error */
  (void)wprintf("English:  Hello, world!\n"); /* error */
  
  (void)wprintf(L"Russian:  �^�а�^�еги�^��^��^�и�^��^�й�^�е�^��^� �^�ей�^�а�^� на �^�е�^��^��^��^��^� �^�ежд�^�на�^�одн�^��^� �^�он�^�е�^�ен�^�и�^�...\n");
  (void)wprintf(L"Greek:    Σὲ γν�^��^�ίζ�^� �^��^�ὸ �^�ὴν κό�^�η...\n");
  (void)wprintf(L"Georgian: �^�^��^�^��^î�^�^��^�^��^�^� �^�^��^î�^�^��^�^��^�^��^�^� �^�^��^�^��^�^��^�^��^à�^�^��^�^� �^à�^�^��^�^��^�^��^á�^â�^à�^�^��^ê�^�^��^�^� Unicode-�^�^��^á �^�^��^�^��^�^��^�^��^�^� �^á�^�^��^�^��^à�^�^��^�^��^è�^�^��^à�^�^��^á�^�^�\n");
  return (EXIT_SUCCESS);
}

