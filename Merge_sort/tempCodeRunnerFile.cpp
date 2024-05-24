
    for(int i=0; i<bn; i++){
        b[i]=arr[mid+i+1];
    }
    int i=0, j=0, k=l;
    while(i<an && j<bn){
        if(a[i]<b[j])  arr[k++]=a[i++];
        else arr[k++]=b[j++];
    }
    while(i<an){
        arr[k++]=a[i++];
    }