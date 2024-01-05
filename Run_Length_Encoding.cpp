// Link : https://www.geeksforgeeks.org/problems/run-length-encoding
// GoldMan Sachs, Amazon | Day - 5 | Problem - 2
string encode(string src){     
  string ans="";
  char curr = src[0];
  int cnt = 1;
  for(int i = 1; i < src.length(); i++){
        if(src[i] == curr)
            cnt++;
        else{
            ans = ans + curr + to_string(cnt);
            curr = src[i];
            cnt = 1;
        }
  }
  ans = ans + curr + to_string(cnt);
  return ans;
}     
 
