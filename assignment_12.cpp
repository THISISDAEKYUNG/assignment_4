#include <iostream>
#include <iterator>
#include <map>
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::pair;

int num_match=0;
int num_mismatch=0;

void print_map(map<int, int> &m){
  cout<<"Match : "<< num_match<< "\nMismatch : "<< num_mismatch<<endl;
  cout<<"\nid pw"<<endl;
  /*Implement this function*/
  for (auto i: m)
    cout << i.first << " " << i.second << endl;
}

int request_insert(map<int, int> &m, int id, int pw){
  /*Implement this function*/
  m.insert(pair<int, int>(id, pw));
  return 0;
}

int request_delete(map<int, int> &m, int id){
  /*Implement this function*/
  m.erase(id);
  return 0;
}

int request_modify(map<int, int> &m, int id, int pw){
  /*Implement this function*/
  m.erase(id);
  m.insert(pair<int, int>(id, pw));
  return 0;
}

int request_check(map<int, int> &m, int id, int pw){
  /*Implement this function.
  You should update the variable num_mismatch and num_match*/
  if (m.find(id) != m.end()) {
      if (m[id] == pw) num_match++;
      else num_mismatch++;
  }
  else num_mismatch++;
  return 0;
}

int main() {
  map <int, int> map_id_pw;
  int num_request, id, pw;
  cin>>num_request;

  for (int i=0; i<num_request; i++){
    char request_type;
    cin>>request_type;

    switch (request_type){
      case 'i':
        cin>>id>>pw;
        request_insert(map_id_pw, id, pw);
        break;
      case 'd':
        cin>>id;
        request_delete(map_id_pw, id);
        break;
      case 'm':
        cin>>id>>pw;
        request_modify(map_id_pw, id, pw);
        break;
      case 'c':
        cin>>id>>pw;
        request_check(map_id_pw, id, pw);
        break;
    }
  }
  print_map(map_id_pw);
}