#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Solution {
public:
    int charIntAdder(){
        char c1;
        char c2;
        int i1;
        int i2;
        cout << "Character input: ca, cb, cc, cd, ..." << endl;
        cout << "Integer input: i0, i21, i104, i5008, ..." << endl;
        cout << "Type 0 to quit\n" << endl;
        while (true){
            cout << "Integer or Char 1: ";
            cin >> c1;
            if(c1 == 'i') cin >> i1;
            else if (c1 == 'c'){
                cin >> c1;
                i1 = (int) c1;
            }
            else break;
            cout << "Integer or Char 2: ";
            cin >> c2;
            if(c2 == 'i') cin >> i2;
            else if (c2 == 'c'){
                cin >> c2;
                i2 = (int) c2;
            }
            else break;
            cout << "sol: " << (i1 + i2) << endl;
        }
    }

    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length()+1;
        int n = s2.length()+1;
        int ansArr[n][m];
        int i;
        int j;
        ansArr[0][0] = 0;
        for(i=1;i<n;i++){
            ansArr[i][0] = (int) s2[i-1] + ansArr[i-1][0];
        }
        for(j=1;j<m;j++){
            ansArr[0][j] = (int) s1[j-1] + ansArr[0][j-1];
        }
        for(i=1;i<n;i++){
            for(j=1;j<m;j++){
                if(s1[j-1] == s2[i-1]) ansArr[i][j] = ansArr[i-1][j-1];
                else{
                    if((ansArr[i-1][j] + (int) s2[i-1]) <= (ansArr[i][j-1] + (int) s1[j-1])) ansArr[i][j] = ansArr[i-1][j] + (int) s2[i-1];
                    else ansArr[i][j] = ansArr[i][j-1] + (int) s1[j-1];
                }
            }
        }
        ofstream myfile;
        myfile.open("output.txt");
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                myfile  << ansArr[i][j] << "\t";
            }
            myfile  << "\n";
        }
        myfile.close();
        return ansArr[n-1][m-1];
    }
};

int main(){
    Solution sol;
    sol.charIntAdder();
    cout << "sol: " << sol.minimumDeleteSum("delete","leet") << endl;
    cout << "sol: " << sol.minimumDeleteSum("caabcccaccccca","cacbaaac") << endl;
    cout << "sol: " << sol.minimumDeleteSum("igijekdtywibepwonjbwykkqmrgmtybwhwjiqudxmnniskqjfbkpcxukrablqmwjndlhblxflgehddrvwfacarwkcpmcfqnajqfxyqwiugztocqzuikamtvmbjrypfqvzqiwooewpzcpwhdejmuahqtukistxgfafrymoaodtluaexucnndlnpeszdfsvfofdylcicrrevjggasrgdhwdgjwcchyanodmzmuqeupnpnsmdkcfszznklqjhjqaboikughrnxxggbfyjriuvdsusvmhiaszicfa","ikhuivqorirphlzqgcruwirpewbjgrjtugwpnkbrdfufjsmgzzjespzdcdjcoioaqybciofdzbdieegetnogoibbwfielwungehetanktjqjrddkrnsxvdmehaeyrpzxrxkhlepdgpwhgpnaatkzbxbnopecfkxoekcdntjyrmmvppcxcgquhomcsltiqzqzmkloomvfayxhawlyqxnsbyskjtzxiyrsaobbnjpgzmetpqvscyycutdkpjpzfokvi") << endl;
    return 0;
}