#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *protocol;
    char *host;
    char *pathname;
    char *search;
    char *hash;
    int port;
} Location;

Location *parse_url(char *url);

int main()
{
    char url[500] = "";
    fgets(url, 500, stdin); // Get url string

    Location *l = parse_url(url);
    printf("Location {\n  protocol: %s,\n  host: %s,\n", l->protocol, l->host);
    if (l->port)
        printf("  port: %d,\n", l->port);
    else
        printf("  port: (default),\n");
    printf("  pathname: /%s,\n  search: ?%s,\n  hash: #%s,\n}\n", l->pathname, l->search, l->hash);
    return 0;
}


Location *parse_url(char *url)
{
    int n = strlen(url);
    url[n] = '\0';
    n--;
    
    Location *ans = (Location*)malloc(sizeof(Location));
    ans->hash = calloc(1,sizeof(char) );
    ans->host = calloc(1,sizeof(char) );
    ans->pathname = calloc(1,sizeof(char) );
    ans->protocol = calloc(1,sizeof(char) );
    ans->search = calloc(1,sizeof(char) );
    ans->port = 0;

    // hash
    int idx = n-1;
    for(idx=n-1;idx>=0;idx--){
        if( url[idx] == '#' ){
            ans->hash = (char *)calloc( (n-idx)  , sizeof(char) );
            stpncpy(ans->hash , url+idx+1,n-idx-1 );

            n = idx;
            break;
        }
    }

    // search 
    for(idx=n-1;idx>=0;idx--){
        if( url[idx] == '?' ){
            ans->search = (char *)calloc( (n-idx) , sizeof(char) );
            stpncpy(ans->search , url+idx+1,n-idx-1 );
            n = idx;
            break;
        }
    }
    // protocal
    int st = 0;
    for(idx=0;idx<n;idx++){
        if( url[idx] == ':' ){
            ans->protocol = (char*)calloc(idx+1 , sizeof(char) );
            stpncpy(ans->protocol , url,idx );
            st = idx+3;
            break;
        }
    }
    // host & path name
    for(idx=st;idx<n;idx++){
        if( url[idx] == '/' ){
            // path name
            ans->pathname = (char*)calloc( n-idx , sizeof(char));
            stpncpy(ans->pathname , url+idx+1 ,n-idx-1);

            // port
            for(int i=st;i<idx;i++){
                if( url[i] == ':' ){
                    char tmp[idx-i+1];
                    stpncpy( tmp, url+i+1 , idx-i );
                    ans->port = atoi(tmp);
                    idx = i;
                    break;
                }
            }
            // host
            ans->host = (char*)calloc(idx-st+1 , sizeof(char) );
            stpncpy(ans->host , url+st,idx-st);
            

            return ans;
            break;
        }
    }

    // port
    for(int i=st;i<n;i++){
        if( url[i] == ':' ){
            char tmp[idx-i+1];
            stpncpy( tmp, url+i+1 , idx-i );
            ans->port = atoi(tmp);
            n = i;
            break;
        }
    }
    // host
    ans->host = (char*)calloc(n-st+1 , sizeof(char) );
    stpncpy(ans->host , url+st,n-st );
    
    return ans;
}