#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  string line;
  vector<float> o;
  vector<float> cp;
  int count=0;
  while(getline(cin,line))
  {
    o[count] = stof(line);
    cp[count] = stof(line);
    count++;
  }

  for(int i=0;i<count;i++)
  {
    int shift = 0;
    while(o[i-shift]>o[i+1-shift])
    {
      o[i-shift] = cp[i+1-shift];
      o[i+1-shift] = cp[i-shift];
      cp = o;
      shift++;
      if(shift==count-1)
      {
        exit;
      }
    }
  }
  for(int i = 0;i<count;i++)
  {
    cout << o[i] << endl;
  }
  return 0;
}