class Solution {
    void swap_vectors(vector<int>& nums1, vector<int>& nums2){
        vector<int> temp = nums1;
        nums1 = nums2;
        nums2 = temp;
    }
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()) swap_vectors(nums1, nums2);
        int p1 = 0, p2 = 0;
        while(p1 < nums1.size() and p2 < nums2.size()){ 
            cout << nums1[p1] << " : " << nums2[p2] << endl;
            if(nums1[p1] == nums2[p2]){
                return nums1[p1];
            }else if(nums1[p1] < nums2[p2]){
                p1++;
            }else{
                p2++;
            }
        }
        return -1;
    }
};