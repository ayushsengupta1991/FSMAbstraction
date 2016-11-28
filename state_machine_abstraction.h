#include<iostream>
#include<map>
#include<string>
class StateMachine {
	protected:
		int numStates_;
		int current;
		int start_;
	        int end_;
		map<int, string> stateMap;
		bool **transitionMap;
	public:
		virtual void defineTransitiionFunction(char input) = 0;
		virtual void defineTransitionRules() = 0;
		virtual void stateToString() = 0;
		virtual void stringToState() = 0;
		StateMachine(int numStates, int start, int end) {
			numStates_ = numStates;
			start_ = start;
			current = start;
			end_ = end;
		}
		virtual int getCurrentState() = 0;
		bool Language() {
			if (current == end_)
				return true;
			return false;

		}
};
