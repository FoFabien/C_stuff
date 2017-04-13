
#include <stdio.h>
main()
{
  unsigned char c;
  while ((c=getchar())!= (unsigned char)EOF)
    {
     switch(c)
      {
      case  156: c='e';printf("o");break; /* oe */ 
      case  233: c='e';break; /* é */
      case  232: c='e';break; /* è */
      case  234: c='e';break; /* ê */
      case  235: c='e';break; /* ë */
      case  226: c='a';break; /* â */
      case  224: c='a';break; /* à */
      case  228: c='a';break; /* ä */
      case  238: c='i';break; /* î */
      case  239: c='i';break; /* ï */
      case  244: c='o';break; /* ô */
      case  251: c='u';break; /* û */
      case  249: c='u';break; /* ù */
      case  231: c='c';break; /* ç */
      case  'É'  c='E';break; 

      }
     putchar(c);
    }
  
}
