class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size() ;
        int sz2 = nums2.size() ;

        int elementsLeftSide = (sz1 + sz2 + 1)/2 ;
        
        int st = max(0, elementsLeftSide - sz2);
        int en = min(elementsLeftSide, sz1);
        
        while(st<=en){
                int mid1 = (st+en)/2 ;
                int mid2 =  elementsLeftSide - mid1 ;
               // cout<<mid1<<", "<<mid2<<endl; 
                int l1 = mid1-1>=0 ? nums1[mid1-1] :  INT_MIN  ;
                int r1 = mid1 < sz1 ? nums1[mid1] : INT_MAX;
                int l2 = mid2-1>=0 ? nums2[mid2-1] : INT_MIN;
                int r2 = mid2 < sz2 ? nums2[mid2] : INT_MAX;

                if(l1<=r2 && l2<=r1){
                    if( (sz1+sz2)%2==0){
                        // cout<<"l1="<<l1<<",r1="<<r1<<",l2="<<l2<<",r2="<<r2<<endl;
                        return (max(l1, l2) + min(r1, r2))/2.0 ; 
                    }else{
                        return max(l1, l2);
                    }
                    
                }
                else if(l1 > r2){
                    en = mid1 - 1 ;
                }
                else{
                    st = mid1 + 1;
                }
                
        }

         return 0.0;
    }
};