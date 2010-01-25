#include <stdlib.h>
#include <stdio.h>

#include "projektcuda.h"
#include "idrs.h"

int main()
{

   t_mindex N               = 20000;
   t_mindex sparse_NZ_elements = 20000;



   t_SparseMatrix a;
   t_ve bla;

   t_ve*  r;
   t_ve*  b;
   t_ve*  xe;

   t_idrshandle irdshandle;

   t_mindex blai;
   printf( "\n Build configuration host Complier: sizeof(t_ve) = %u \n", sizeof(t_ve));
   printf( "\n Build configuration libidrs: sizeof(t_ve) = %u \n"      , idrs_sizetve());


   printf("\n manual IDRS driver, running Matrix size %u \n", N);

    a.n = N;
    a.m = N;
    a.nzmax = sparse_NZ_elements;


    b = ( t_ve* ) malloc( sizeof( t_ve ) *  N );
    if ( b == NULL) { fprintf(stderr, "sorry, can not allocate memory for you b"); exit( -1 ); }

    r = ( t_ve* ) malloc( sizeof( t_ve ) *  N );
    if ( r == NULL) { fprintf(stderr, "sorry, can not allocate memory for you b"); exit( -1 ); }

   for ( int i = 0; i < N; i++ ) {
      b[i] =  i * 3;
      /* printf( "\n org %u %f", i, b[i] ); */
   }

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
    for ( t_mindex i = 0; i < a.m ; i++ )  {
       a.pRow[i] = i;
    }
    a.pRow[a.m] = a.m;
    idrs_1st(
               a,
               b,
               N,
               r,


               &irdshandle
            );
   if ( N < 101 ) {
   for ( int i = 0; i < N; i++ ) {
       printf( "\n  %u b %f r%f", i, b[i], r[i] );
   }
   }
//   idrs(
//
//         a,
//         b,

//         10,    /* s */
//         0.123, /* tol */
//         100,   /* maxit */
//         xe,
//         N,


//         &bla,
//         &bla,
//         &blai
//     );

}
