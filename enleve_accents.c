
#include <stdio.h>
main()
{
  unsigned char c;
  while ((c=getchar())!= (unsigned char)EOF)
    {
     switch(c)
      {
      case  156: c='e';printf("o");break; /* oe */ 
      case  233: c='e';break; /* � */
      case  232: c='e';break; /* � */
      case  234: c='e';break; /* � */
      case  235: c='e';break; /* � */
      case  226: c='a';break; /* � */
      case  224: c='a';break; /* � */
      case  228: c='a';break; /* � */
      case  238: c='i';break; /* � */
      case  239: c='i';break; /* � */
      case  244: c='o';break; /* � */
      case  251: c='u';break; /* � */
      case  249: c='u';break; /* � */
      case  231: c='c';break; /* � */
      case  '�'  c='E';break; 

      }
     putchar(c);
    }
  
}
