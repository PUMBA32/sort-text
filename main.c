#include <stdio.h>

int main(void)
{
    char text[] = "justatext";  //Текст который хотим отсортировать
    char alph[] = "abcdefghijklmnopqrstuvwxyz";

    int pos;
    int n[(sizeof(text) / sizeof(text[0]))-1];

    int text_size = (sizeof(text) / sizeof(text[0])) - 1;
    int n_size = sizeof(n) / sizeof(n[0]);
    int alph_size = (sizeof(alph) / sizeof(alph[0])) - 1;

    printf("\noriginal text: ");
    puts(text);
    

    for (int i = 0; i < text_size; i++) {
        for (int j = 0; j < alph_size; j++) {
            if(text[i] == alph[j]) {
                n[i] = j+1;
                continue;
            }
        }
    }

    for(int i = 0; i < n_size - 1; i++) {
        pos = i;
        for (int j = i+1; j < n_size; j++) {
            if(n[pos] > n[j]) {
                pos = j;
            }
        }
        if(pos != i) {
            int t = n[i];
            n[i] = n[pos];
            n[pos] = t;
        }
    }
    
    
    printf("\nsorted text: ");
    for (int i = 0; i < n_size; i++) {
        printf("%c", alph[n[i]-1]);
    }
    printf("\n\n");

    return 0;
}