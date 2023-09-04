
int f(vector<int>& a, int n, int pages){
   int students=1;
   int sum=0;
   for(int i=0; i<n; i++){
       if(sum+a[i]>pages){
           students++;
           sum=a[i];
       }
       else{
           sum+=a[i];
       }
   }
   return students;
}

int findPages(vector<int>& a, int n, int stud) {
//    int maxi=*max_element(a.begin(),a.end());
//    int sum=accumulate(a.begin(),a.end(),0);
//    for(int i=maxi; i<=sum; i++){
//        int cntStudents=f(a,n,i);
//        if(cntStudents==m) return i;
//    }
//    return -1;
      if(stud>n) return -1;
      int l=*max_element(a.begin(),a.end());
      int h=accumulate(a.begin(),a.end(),0);
      int m=0;
      while(l<=h){
          m=(l+h)/2;
          int cntStudents=f(a,n,m);
          if(cntStudents>stud) l=m+1;
          else h=m-1;
      }
      return l;

}