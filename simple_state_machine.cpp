#include<iostream>
#include<string>
using namespace std;
// A simple state machine to recognize strings of type (AB)*(CD)* 
enum ProblemStates {
	null  = 'X',
	alpha = 'A',
	beta  = 'B',
        gamma = 'C',
	delta = 'D',
	error = 'E'
};

/* Transition Function
 * alpha --(A)-- error
 * alpha --(B)-- beta
 * alpha --(else)-- error
 * beta --(A)-- alpha
 * beta --(B/else)-- error
 * beta --(C)-- gamma
 * gamma --(C/A/B/else)-- error
 * gamma --(D)-- delta
 * end state delta
 * delta --(D)-- error
 * delta --(C)-- gamma
 * */

class ProblemFSM {
	ProblemStates curr;
	ProblemStates start;
	ProblemStates end;
	public:
	ProblemFSM(ProblemStates start_, ProblemStates end_)
	{
		start = start_;
		end = end_;
		curr = start_;
	}
	void transitionFunction(char c) {
		switch(curr) {
			case null: if (c == 'A') curr = alpha;
				   else curr = error;
				   break;
			case alpha: if (c == 'B') curr = beta;
				    else curr = error;
				    break;
			case beta: if (c == 'A') curr = alpha;
				   else if (c == 'C') curr = gamma;
				   else curr = error;
				   break;
		        case gamma: if (c == 'D') curr = delta;
				    else curr = error;
				    break;
			case delta: if (c == 'C') curr = gamma;
				    else curr = error;
				    break;
			case error: curr = error; 
				    break;
		}
	}
        ProblemStates getCurrentState() {
		return curr;
	}
        bool returnLanguage() {
		if (curr == end)
			return true;
		return false;
	}	


};

int main()
{
	string str;
	cin>>str;
	ProblemFSM sm(null, delta);
	for(int i=0;i<(int)str.size();++i)
	{
		sm.transitionFunction(str[i]);
		cout<<sm.getCurrentState()<<"\n";
	}
	if (sm.returnLanguage())
		cout<<"YES!\n";
	else cout<<"NO!\n";
	return 0;
}
