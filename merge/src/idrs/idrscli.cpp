#include <stdlib.h>
#include <stdio.h>

#include "projektcuda.h"
#include "idrs.h"

int main()
{

   t_mindex N               = 1000000;
   t_mindex sparse_NZ_elements = 10;



   t_SparseMatrix a;
   t_ve bla;

   t_ve*  b;
   t_ve*  xe;

   t_mindex blai;

   printf("\n manual IDRS driver, running Matrix size %u \n", N);

    a.n = N;
    a.m = N;
    a.nzmax = sparse_NZ_elements;


    b = ( t_ve* ) malloc( sizeof( t_ve ) *  N );
    if ( b == NULL) { fprintf(stderr, "sorry, can not allocate memory for you b"); exit( -1 ); }

    a.pRow = ( t_mindex* ) malloc( sizeof( t_mindex ) * ( a.m + 1) );
    if ( a.pRow == NULL) { fprintf(stderr, "sorry, can not allocate memory for you  a.pRow"); exit( -1 ); }

    a.pCol = ( t_mindex* ) malloc( sizeof( t_mindex ) * a.nzmax );
    if ( a.pCol == NULL) { fprintf(stderr, "sorry, can not allocate memory for you a.pCol"); exit( -1 ); }

    a.pNZElement = ( t_ve* ) malloc( sizeof( t_ve ) * a.nzmax );
    if ( a.pNZElement == NULL) { fprintf(stderr, "sorry, can not allocate memory for you  a.pNZElement"); exit( -1 ); }

    for ( t_mindex i = 0; i < a.nzmax; i++ ) {
        a.pNZElement[i] = 14.9;
    }

    for ( t_mindex i = 0; i < a.nzmax; i++ ) {
        a.pCol[i] = i;
    }
    for ( t_mindex i = 0; i < a.m; i++ )  {
       a.pRow[i] = i;
    }

   idrs(
         N,
         a,
         b,
         10,    /* s */
         0.123, /* tol */
         100,   /* maxit */
         xe,



         &bla,
         &bla,
         &blai
     );

}

