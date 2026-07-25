class Solution {
public:
    int maxProduct(int n) {
        vector<int> arr;
        while(n>0){
            arr.push_back(n%10);
            n = n/10;
        }
        int maxProd = 0, prod;
        for(int i=0; i<arr.size(); i++){
            for(int j = i+1; j<arr.size(); j++){
                prod = arr[i] * arr[j];
                maxProd = max(prod,maxProd);
            }
        }
        return maxProd;
    }
};