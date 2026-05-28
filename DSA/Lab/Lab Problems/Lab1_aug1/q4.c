#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Book {
        char Title[100];
        char Author[20];
        char ISBN[50];
        float Price;
};

int main () {
        int n;
        printf("Enter no.of books:");
        scanf("%d",&n);
        struct Book *e;
        e=(struct Book*)malloc(n*sizeof(struct Book));
	if(e == NULL) {
		printf("Memory allocation failed!\n");
		return 1;
	}
        printf("Input for %d Books:\n",n);
        for(int i=0;i<n;i++) {
                printf("Title:");scanf(" %[^\n]",e[i].Title);
                printf("Author:");scanf(" %[^\n]",e[i].Author);
                printf("ISBN:");scanf(" %[^\n]",e[i].ISBN);
                printf("Price:");scanf("%f",&e[i].Price);
        }
        char AuthorName[20];
	printf("Enter the author name to find his/her books:");
	scanf(" %[^\n]",AuthorName);
        printf("Books names written by author %s:\n",AuthorName);
        for(int i=0;i<n;i++) {
                if(strcasecmp(e[i].Author,AuthorName)==0) 
			printf("Title: %s\n",e[i].Title);
        }
        free(e);
        return 0;
}
