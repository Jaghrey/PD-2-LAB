#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *string1, *string2, *result;
	string1 = (char *)malloc(50 * sizeof(char));
    string2 = (char *)malloc(50 * sizeof(char));
	printf("Ilk karakter dizisini giriniz: ");
    scanf("%s", string1);
    printf("Ikinci karakter dizisini giriniz: ");
    scanf("%s", string2);
	result = (char *)malloc((strlen(string1) + strlen(string2) + 1) * sizeof(char));
	strcpy(result, string1);
    strcat(result, string2);
	printf("Birlestirilmis karakter dizisi: %s\n", result);
    free(string1);
    free(string2);
    free(result);

    return 0;
}

