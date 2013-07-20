#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void Print(int a[],int length){
    for(int i = 0; i < length; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

bool Sorted(int a[], int length){
    bool s = a[1] >= a[0];
    for(int i = 1; i < length; i++){
        s = s && (a[i] >= a[i - 1]);
    }
    return s;
}

void Swap(int *a, int *b){
    /*a += *b;
    *b = *a - *b;
    *a -= *b;*/
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

void RandomSort(int *a, int length, size_t *iter){
    int x, y, z;
    z = rand() % length;
    while(!Sorted(a, length)){
        for(int i = 0; i < z; i++){
            x = rand() % length;
            y = rand() % length;
            if(!(x == y)){
                Swap(&a[x], &a[y]);
            }
        }
    }
}

int main(){
    srand(time(0));
    int l = 13;
    int a[l];// = {0, 0, 0};
    for(int i = 0; i < l; i++){
        a[i] = rand() % 11;
        cout << a[i] << " ";
    }
    cout << endl;
    size_t iter = 0;
    RandomSort(a, l, &iter);
    Print(a, l);

    return 0;
}
