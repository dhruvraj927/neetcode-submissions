// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>>ans;
//         set<int>s;
//         int n=strs.size();
//         for(int i=0;i<n && !s.count(i);i++){
//             vector<string>temp;
//             temp.push_back(strs[i]);
//             s.insert(i);
//             vector<int>c(26,0);
//             for(auto ch:strs[i]){
//                 int ind=ch-'a';
//                 c[ind]++;
//             }
//             vector<int>t(26,0);
//             for(int j=i+1;j<n;j++){
//                  if(s.count(j)) continue;
//                  for(auto ch:strs[j]){
//                     int ind=ch -'a';
//                     t[ind]++;
//                 }
//                 bool all=true;
//                 for(int k=0;k<26;k++){
//                     if(c[k]!=t[k]) {
//                         all=false;
//                         break;}
//                 }
//                 if(all){
//                     temp.push_back(strs[j]);
//                     s.insert(j);
//                 }
//                  for(int k=0;k<26;k++){
//                     t[k]=0;
//                 }

//             }
//             ans.push_back(temp);

//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        set<int> s;
        int n = strs.size();

        for(int i = 0; i < n; i++) {
            if(s.count(i)) continue;

            vector<string> temp;
            temp.push_back(strs[i]);
            s.insert(i);

            vector<int> c(26,0);

            for(char ch : strs[i])
                c[ch-'a']++;

            for(int j = i+1; j < n; j++) {
                if(s.count(j)) continue;

                vector<int> t(26,0);

                for(char ch : strs[j])
                    t[ch-'a']++;

                if(c == t) {
                    temp.push_back(strs[j]);
                    s.insert(j);
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};