// #include <iostream>
// #include <vector>
// using namespace std;

// string id_list[1000];
// vector< pair<string, string> > report;
// int k;
// int report_count[1000];

// void reporting();

// int main() {
//     reporting();

//     return 0;
// }

// void reporting() {
//     int idCount = 0;

//     while(1) {
//         cin >> id_list[idCount++];
//     }
// }


#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report,  int k) {
    int id_list_size = id_list.size();
    
    vector<int> answer;
    int accused_count_list[1000] = { 0, };    // 고발당한 횟수
    vector<string> accuseList[1000];  // 해당 인덱스가 고발한 리스트
    
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    
    for(int i=0; i<report.size(); i++) {
        string accuser = split(report[i], ' ');
        string accused = report[i].split(' ')[1];
        
        int accuser_index = 
            find(id_list.begin(), id_list.end(), accuser) 
            - id_list.begin();
        
        int accused_index = 
            find(id_list.begin(), id_list.end(), accused) 
            - id_list.begin();
        
        accuseList[accuser_index].push_back(accused);
        accused_count_list[accused_index]++;
    }
    
    for(int i=0; i<accuseList.length; i++) {
        int count = 0;
        
        for(int j=0; j<accuseList[i].size(); j++) {
            int index = accused_count_list.indexOf(accuseList[i][j]);
            if(accused_count_list[index] >= k) count++;
        }
        
        answer.push_back(count);
    }
    
    return answer;
}