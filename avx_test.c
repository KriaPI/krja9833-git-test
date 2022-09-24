#include <stdio.h>
#include <immintrin.h>

void print_epi32_addition(int* ap, int* bp, int* rp){
    printf("Result of addition: \n{%d %d %d %d %d %d %d %d} + {%d %d %d %d %d %d %d %d} = {%d %d %d %d %d %d %d %d}",
    ap[7], ap[6], ap[5], ap[4], ap[3], ap[2], ap[1], ap[0], 
    bp[7], bp[6], bp[5], bp[4], bp[3], bp[2], bp[1], bp[0],
    rp[7], rp[6], rp[5], rp[4], rp[3], rp[2], rp[1], rp[0] 
    ); 

}

int main(){
    __m256i intsA = _mm256_set_epi32(1,2,3,4,5,6,7,8); 
    __m256i intsB = _mm256_set_epi32(1,2,3,4,5,6,7,8); 
    __m256i intsRes = _mm256_add_epi32(intsA, intsB);

    int* ap = (int*)&intsA;
    int* bp = (int*)&intsB;
    int* rp = (int*)&intsRes;

    print_epi32_addition(ap, bp, rp);
    return 0;
}