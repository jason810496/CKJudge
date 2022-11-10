#include<stdio.h>
#include<string.h>

struct node{
    int id;
    char name[105];
};

struct node arr[35] , temp[35];

int cmp(struct node a,struct node b){
    int n = strlen(a.name);
    int m = strlen(b.name);
    int mn = (n<m ? n:m);
    
    for(int i=0;i<mn;i++){
        if( a.name[i]==b.name[i] ) continue;
        if(a.name[i] < b.name[i] ) return 1;
        return 0;
    }

    return (n<m ? 1:0);
}

void sort(int l,int r){
    int mid = (l+r)/2;
    if( l>=r ) return;
    sort(l,mid);
    sort(mid+1,r);

    int i=l,j=mid+1,k=l;
    
    while(i<=mid && j<=r ){
        if( cmp(arr[i],arr[j]) ){
            temp[k++] = arr[i++]; 
        }
        else temp[k++] = arr[j++];
    }
    while( i<=mid ){
        temp[k++] = arr[i++];
    }
    while( j<=r ){
        temp[k++] = arr[j++];
    }

    for(int i=l;i<=r;i++){
        arr[i] = temp[i];
    }
}

void Convert(struct node *a){
    int len = strlen(a->name);
    for(int i=0;i<len;i++){
        if( 'A'<= a->name[i] && a->name[i]<='Z' ){
            a->name[i] = (char)(a->name[i]-'A'+'a');
        }
    }
}

int same(char *a,char *b){
    int n=strlen(a);
    int m=strlen(b);
    if( n==m ){
        for(int i=0;i<n;i++){
            if( a[i]!=b[i] ) return 0;
        }
        return 1;
    }
    return 0;
}
int main () {
    int n;
    scanf("%d" , &n );

    struct node stu;
    scanf("%d%s" , &stu.id , stu.name);
    Convert(&stu);
    

    for(int i=0;i<n;i++){
        scanf("%d%s" , &arr[i].id , arr[i].name);
        Convert(&arr[i]);
    }
    arr[n] = stu;

    sort(0,n);

    for(int i=0;i<=n;i++){
        if( arr[i].id == stu.id  && same(arr[i].name , stu.name ) ){
            printf("%d\n" , i+1);
            break;
        }
    }
    return 0;
}

