#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

int main() {
  int n;
  int q;
  std::cin >> n >> q;
  std::string temp;
  std::vector<std::string> hrml;
  std::vector<std::string> quer;
  std::cin.ignore();

  for (auto i = 0; i < n; ++i) {
    getline(std::cin, temp);
    hrml.push_back(temp);
  }
  for (auto i = 0; i < q; ++i) {
    getline(std::cin,temp);
    quer.push_back(temp);
  }

  std::map<std::string, std::string> m;
  std::vector<std::string> tag;

  for (auto i = 0; i < n; ++i) {
    temp = hrml[i];
    temp.erase(remove(begin(temp), end(temp), '\"' ), end(temp));
    temp.erase(remove(begin(temp), end(temp), '>' ), end(temp));

    if (temp.substr(0, 2) == "</") {
      tag.pop_back();
    }
    else {
      std::stringstream ss;
      ss.str("");
      ss << temp;
      std::string t1;
      std::string p1;
      std::string v1;
      char ch;
      ss >> ch >> t1 >> p1 >> ch >> v1;
      std::string temp1 = "";
      if (tag.size() > 0) {
        temp1 = *tag.rbegin();
        temp1 = temp1 + "." + t1;
      }
      else {
        temp1 = t1;
      }
      tag.push_back(temp1);
      m[*tag.rbegin() + "~" + p1] = v1;
      while (ss) {
        ss >> p1 >> ch >> v1;
        m[*tag.rbegin() + "~" + p1] = v1;
      }
    }
  }

  for (auto i = 0; i < q; ++i) {
    if (m.find(quer[i]) == m.end()) {
      std::cout << "Not Found!\n";
    }
    else {
      std::cout << m[quer[i]] << std::endl;
    }
  }
  return 0;
}
