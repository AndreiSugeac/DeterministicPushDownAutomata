#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#define maxSt 20
#define maxL 256

using namespace std;

ifstream f("input.in");
ofstream g("output.out");

int nrStari, nrLitere, nrStariF, q0, nrTrans;
vector <int> Q;
vector <int> F;
vector <char> E;
stack <char> stiva;

string trans[maxSt][maxL][maxL][maxSt];
void verificare(string cuv) {
	stiva.push('$');
	int stCur = q0;
	for (char lit : cuv) {
		int gasit = 0;
		char top = stiva.top();
		stiva.pop();
		for (int q : Q) {
			if (!trans[stCur][lit][top][q].empty()) {
				string push = trans[stCur][lit][top][q];
				stCur = q;

				if (push == ".") break;

				for (int i = push.size() - 1; i >= 0; --i) {
					stiva.push(push[i]);
				}
				gasit = 1;
			}
		}
		if (gasit == 0) {
			g << "Cuvantul nu este bun!!!" << endl;
			return;
		}
	}

	if (find(F.begin(), F.end(), stCur) != F.end() && stiva.top() == '$')
		g << "Cuvantul este acceptat" << endl;
	else g << "Cuvantul nu este bun" << endl;
	return;
}

void citire() {
	f >> nrStari;
	cout << nrStari;
	for (int i = 1; i <= nrStari; ++i) {
		int stare;
		f >> stare;
		Q.push_back(stare);
	}
	f >> nrLitere;
	for (int i = 1; i <= nrLitere; ++i) {
		char litera;
		f >> litera;
		E.push_back(litera);
	}
	f >> q0;
	f >> nrStariF;
	for (int i = 1; i <= nrStariF; ++i) {
		int fin;
		f >> fin;
		F.push_back(fin);
	}
	f >> nrTrans;
	for (int i = 1; i <= nrTrans; ++i) {
		int stareCur, stareFin;
		char tran, top;
		string push;
		f >> stareCur >> tran >> top >> push >> stareFin;
		trans[stareCur][tran][top][stareFin] = push;
	}
	string cuv;
	f >> cuv;
	verificare(cuv);
}

int main()
{
	citire();
	return 0;
}