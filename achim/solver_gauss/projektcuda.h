
#define ab( r, s ) (r -1 ) * ( N + 1 ) + s -1

#define a( r, s ) (r -1 ) * N  + s -1

#define CUDA_UTIL_ERRORCHECK(MSG)        if( e != cudaSuccess ) \
        {\
            fprintf(stderr, "*** Error on CUDA operation '%s': '%s'*** \n\n", MSG, cudaGetErrorString(e));\
            exit(-3);\
        }\


#define GAUSS_NMAX 22

typedef float        t_ve; /* base type of Matrizes: 'float' or 'double' */


