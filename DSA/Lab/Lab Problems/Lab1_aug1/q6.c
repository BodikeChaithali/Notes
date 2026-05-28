#include<stdio.h>
#include<stdlib.h>

struct product {
	int ID;
        char Name[20];
        float Price;
	float Qty;
};

int main () {
        int n,f=0;
	float max;
        printf("Enter no.of the products:");
        scanf("%d",&n);
        struct product *s;
        s=(struct product*)malloc(n*sizeof(struct product));
        printf("Input for %d products:\n",n);
        for(int i=0;i<n;i++) {
                printf("ID:");scanf(" %d",&s[i].ID);
                printf("Name:");scanf(" %[^\n]",s[i].Name);
                printf("Price:");scanf("%f",&s[i].Price);
		printf("Quantity:");scanf("%f",&s[i].Qty);
	}
	max=s[0].Price;
	for(int i=1;i<n;i++) {
		if(max<s[i].Price) {
			max=s[i].Price;
			f=i;
		}
        }
        printf("Highest price product details are:\n");
	printf("ID:%d,name:%s,Quantity:%.2f and price:%.2f\n",s[f].ID,s[f].Name,s[f].Qty,max);
        free(s);
        return 0;
}

