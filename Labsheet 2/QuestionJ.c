// COMPLETE

#include <stdio.h>
#include <stdlib.h>

struct Country{
    char name[20];
    int gold;
    int silver;
    int bronze;
}typedef country;

void getCountryData(country *c){
    scanf("%s %d %d %d", c->name, &c->gold, &c->silver, &c->bronze);
};

void sort(country arr[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(!((arr[i].gold < arr[j].gold) || (arr[i].gold == arr[j].gold && arr[i].silver < arr[j].silver) || 
            (arr[i].gold == arr[j].gold && arr[i].silver == arr[j].silver && arr[i].bronze < arr[j].bronze))){
                country temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    country countryarr[n];
    for(int i = 0; i < n; i++){
        getCountryData(&countryarr[i]);
    }

    sort(countryarr, n);

    for(int i = 0; i < n; i++){
        printf("%s\n", countryarr[i].name);
    }
}