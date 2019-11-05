#include <bits/stdc++.h>

using namespace std;

class decisionTree {
	
	public:
		decisionTree *group[10];
		string groupName;
		vector<int> element;
		
};

decisionTree *newNode() 
{ 
    decisionTree *temp = new decisionTree(); 
    return temp; 
}
 
void printInfo(decisionTree* root, int x) {
	
	decisionTree* current = root->group[x];
	for(int i = 0;i < current->element.size(); i++){
		cout<<current->element[i]<<" ";
	}
	
}

void sortedprintInfo(decisionTree* root, int x) {
	
	decisionTree* current = root->group[x];
	sort(current->element.begin(), current->element.end());
	for(int i = 0;i < current->element.size(); i++){
		cout<<current->element[i]<<" ";
	}
	
	
}

void createGroup(decisionTree* root,int input[32][32]) {

	for(int i = 0; i < 10; i++){
		root->group[i] = newNode();
	}
	
	int groupNumber;
	
	for(int i = 0; i < 32; i++) {
		for(int j = 0; j < 32; j++) {
			groupNumber = input[i][j]%10;
			root->group[groupNumber]->element.push_back(input[i][j]);
		}
	}
	
}

int main() { 

	int input[32][32];
	
	decisionTree* root = new decisionTree();
	root->groupName = "Decision Tree";
	for(int i = 0; i < 32; i++) {
		for(int j = 0; j < 32; j++) {
			input[i][j] = rand()%1025;
			
		}
	}
	createGroup(root, input);
	
	int gn;
	cout<<"Enter the Group that you want to display:\n";
	cin>>gn;
	printInfo(root,gn);
	cout<<"\nOkay. Now in an organised fashion\n";
	sortedprintInfo(root,gn);
}
