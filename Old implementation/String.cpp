#include <bits/stdc++.h>
using namespace std;

// Sexy code XD ;p
void createLPS(string p, int lps[]) {
	int i=0, j=1;
	lps[0] = 0;
	while(j<p.length()) {
		if(p[i] == p[j])
			lps[j++] = ++i;
		else
			i==0 ? lps[j++] = 0 : i = 0;
	}
}

void KMP(string s, string p) {
	// Create lps
	int lps[p.length()];
	createLPS(p, lps);

	// traversing
	int i=0,j=0;
	while(i<s.length()) {
		
		if(s[i] == p[j]) {
			i++;
			j++;
		}

		if(j == p.length())
		{
			cout << "Found pattern at " << i-j << endl;
			j = lps[j-1];
		}
		else if(i<s.length() and s[i] != p[j]){
			if(j == 0) {
				i++;
				continue;
			}
			j = lps[j-1];
		}
	}
}

int main() {
	string p = "AABA";
	string s = "AABAACAADAABAABA";
	int lps[p.length()];
	KMP(s, p);
	return 0;
}